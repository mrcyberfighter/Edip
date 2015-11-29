#ifndef EDIP_FILES_DIALOG_HH
#define EDIP_FILES_DIALOG_HH

/** **********************************************************************************
 *                                                                                   *
 * @Edip (Easy Digital Image Processing) an easy to use image processing program.    *
 * Copyright (C) 2015 Brüggemann Eddie                                               *
 *                                                                                   *
 * This file is part of @Edip.                                                       *
 * @Edip is free software: you can redistribute it and/or modify                     *
 * it under the terms of the GNU General Public License as published by              *
 * the Free Software Foundation, either version 3 of the License, or                 *
 * (at your option) any later version.                                               *
 *                                                                                   *
 * @Edip is distributed in the hope that it will be useful,                          *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of                    *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                      *
 * GNU General Public License for more details.                                      *
 *                                                                                   *
 * You should have received a copy of the GNU General Public License                 *
 * along with @Edip. If not, see <http://www.gnu.org/licenses/>                      *
 *                                                                                   *
 *************************************************************************************/

void GUI::config_select_file_filters(Gtk::FileChooser &dialog) {

  dialog.set_current_folder(Glib::get_home_dir()) ;

  Glib::RefPtr<Gtk::FileFilter> file_filter_all = Gtk::FileFilter::create() ;


  #ifdef SUPPORT_BMP // Always supported.
  file_filter_all->add_pattern("*.bmp")   ;
  file_filter_all->add_pattern("*.dib")   ;
  file_filter_all->add_mime_type("image/bmp") ;
  #endif

  #ifdef SUPPORT_SUN_RASTER // Always supported.
  file_filter_all->add_pattern("*.ras")   ;
  file_filter_all->add_pattern("*.sr")    ;
  file_filter_all->add_mime_type("image/x-cmu-raster") ;
  #endif

  #ifdef SUPPORT_PORTABLE_IMAGE_FORMAT  // Always supported.

  file_filter_all->add_pattern("*.pbm") ;
  file_filter_all->add_pattern("*.pgm") ;
  file_filter_all->add_pattern("*.ppm") ;
  file_filter_all->add_mime_type("image/x-portable-bitmap")   ;
  file_filter_all->add_mime_type("image/x-portable-graymap")  ;
  file_filter_all->add_mime_type("image/x-portable-pixmap")   ;
  #endif

  #ifdef SUPPORT_PNG                    // Not always supported.
  file_filter_all->add_pattern("*.png")   ;
  file_filter_all->add_mime_type("image/png") ;
  #endif

  #ifdef SUPPORT_JPG                    // Not always supported.
  file_filter_all->add_pattern("*.jpeg") ;
  file_filter_all->add_pattern("*.jpg")  ;
  file_filter_all->add_pattern("*.jpe")  ;
  file_filter_all->add_mime_type("image/jpeg") ;
  #endif

  #ifdef SUPPORT_TIF                    // Not always supported.
  file_filter_all->add_pattern("*.tiff") ;
  file_filter_all->add_pattern("*.tif")  ;
  file_filter_all->add_mime_type("image/tiff") ;
  #endif

  #ifdef SUPPORT_WEBP                    // Not always supported. Dont' be sure about mimetype.
  file_filter_all->add_pattern("*.webp") ;
  file_filter_all->add_mime_type("image/webp") ;
  #endif

  file_filter_all->set_name("All supported graphics formats.") ;

  dialog.add_filter(file_filter_all) ;

}


void GUI::opening_file(Controller &controller) {



  Gtk::FileChooserDialog dialog("Choice a image file to open.", Gtk::FILE_CHOOSER_ACTION_OPEN);

  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "folder-image.png") ;

  dialog.set_transient_for(*this);

  dialog.set_select_multiple(false) ;

  dialog.set_show_hidden(false) ;

  dialog.set_current_folder(Glib::get_home_dir()) ;

  dialog.add_button(Gtk::Stock::CANCEL,    Gtk::RESPONSE_CANCEL) ;
  dialog.add_button(Gtk::Stock::OK,        Gtk::RESPONSE_OK)     ;


  config_select_file_filters(dialog) ;




  dialog.set_create_folders(true) ;

  dialog.set_show_hidden(false) ;

  dialog.set_use_preview_label(true) ;

  //dialog.set_preview_widget(true) ;



  int result = dialog.run();

  //Handle the response:
  switch (result) {

    case Gtk::RESPONSE_OK : {

      //Notice that this is a std::string, not a Glib::ustring.
      const string filepath = dialog.get_filename();
   
      #ifdef DEBUG
      fprintf(stderr,"Load file: %s\n", filepath.c_str() ) ;
      #endif
   
      cv::Mat frame ;

      try {

        frame = cv::imread(filepath, cv::IMREAD_UNCHANGED) ;

      }

      catch (cv::Exception &e) {

        const string title = "Error loading file !"   ;

        string message = "Cannot load image file:\n"  ;

        message +=  Glib::path_get_basename(filepath) ;

        message += "\n\n" ;

        message += e.err ;

        message_dialog(title, message) ;

        #ifdef DEBUG
        fprintf(stderr,"Cannot load file: %s\n",filepath.c_str()) ;
        #endif
    
        return ;

      }


      if ( frame.empty() ) {

        const string title = "Error loading file !"   ;

        string message = "Cannot load image file:\n"  ;

        message +=  Glib::path_get_basename(filepath) ;


        message_dialog(title, message) ;

        #ifdef DEBUG
        fprintf(stderr,"Cannot load file: %s\n",filepath.c_str()) ;
        #endif
    
        return ;

      }

      if (frame.depth() == 3 || frame.depth() == 2) {

        // Input format CV_16S

        cv::Mat tmp(frame.size(), CV_8U) ;

        frame.convertTo(tmp, CV_8U, 1.0/256) ;

        frame = tmp ;

      }
      else if (frame.depth() == 5) {

        // Input format CV_32F

        cv::Mat tmp(frame.size(), CV_8U) ;

        frame.convertTo(tmp, CV_8U) ;

        frame = tmp ;

      }
      else if (frame.depth() != 0) {

        const string title = "Error loading file !"   ;

        string message = "Cannot load image file:\n"  ;

        message +=  Glib::path_get_basename(filepath) ;


        message_dialog(title, message) ;

        #ifdef DEBUG
        fprintf(stderr,"Cannot load file: %s\n",filepath.c_str()) ;
        #endif
    
        return ;
      }

      if (frame.channels() == 1) {
        // Normally GRAY
        cv::cvtColor(frame, frame, cv::COLOR_GRAY2BGR) ;
        //controller.has_image_an_alpha_channel = false ;

      }

      controller.set_filepath(filepath) ;

      #ifdef SET_FILENAME_TITLE
      set_title(Glib::path_get_basename(filepath)) ;
      #endif

      set_label_value(get_label(1), "Filename: " + Glib::path_get_basename(filepath) ) ;

      controller.reset_settings() ;

      controller.image_to_display_vector.push_back(frame.clone()) ;
  
      controller.current_image_to_process = frame ;

      controller.reset_zoom_center(frame) ;

      controller.get_current_image_position() ;

      set_img(frame, controller.current_image_to_display, controller) ;

      set_label_size_value(controller.source_image_size.first, controller.source_image_size.second) ;

      set_label_coords_value_on_null(controller) ;

      controller.image_file_loaded = true ;


      dialog.close() ;

      return ;

    }

    case Gtk::RESPONSE_CANCEL : {

      dialog.close() ;

      return ;

    }

  }

  dialog.close() ;

  return ;
}


void GUI::get_recent_file(Controller &controller) {

  const string filepath(g_filename_from_uri(menu_files_recent_files.get_current_uri().c_str(), NULL, NULL)) ;

  if (! realpath(filepath.c_str(), NULL) ) {

    const string title = "Error loading file !"   ;

    string message = "Cannot load image file:\n"  ;

    message +=  Glib::path_get_basename(filepath) ;

    message += "\n\nFile not exist !" ;

    message_dialog(title, message) ;

    #ifdef DEBUG
    fprintf(stderr,"Cannot load file: %s\n", filepath.c_str()) ;
    #endif
 
    return ;

  }



  cv::Mat frame = cv::imread(filepath, cv::IMREAD_UNCHANGED) ;


  if ( frame.empty() ) {

    const string title = "Error loading file !"   ;

    string message = "Cannot load image file:\n"  ;

    message +=  Glib::path_get_basename(filepath) ;


    message_dialog(title, message) ;

    #ifdef DEBUG
    fprintf(stderr,"Cannot load file: %s\n", filepath.c_str()) ;
    #endif

    return ;

  }

  if (frame.depth() == 3 || frame.depth() == 2) {

    // Input format CV_16S

    cv::Mat tmp(frame.size(), CV_8U) ;

    frame.convertTo(tmp, CV_8U, 1.0/256) ;

    frame = tmp ;

  }
  else if (frame.depth() == 5) {

    // Input format CV_32F

    cv::Mat tmp(frame.size(), CV_8U) ;

    frame.convertTo(tmp, CV_8U) ;

    frame = tmp ;

  }
  else if (frame.depth() != 0) {

    const string title = "Error loading file !"   ;

    string message = "Cannot load image file:\n"  ;

    message +=  Glib::path_get_basename(filepath) ;


    message_dialog(title, message) ;

    #ifdef DEBUG
    fprintf(stderr,"Cannot load file: %s\n",filepath.c_str()) ;
    #endif

    return ;
  }

  controller.set_filepath(filepath) ;

  set_label_value(get_label(1), "Filename: " + Glib::path_get_basename(filepath) ) ;

  controller.reset_settings() ;

  controller.image_to_display_vector.push_back(frame.clone()) ;

  controller.current_image_to_process = frame ;

  controller.reset_zoom_center(frame) ;

  controller.get_current_image_position() ;

  set_img(frame, controller.current_image_to_display, controller) ;

  set_label_size_value(controller.source_image_size.first, controller.source_image_size.second) ;

  set_label_coords_value_on_null(controller) ;

  controller.image_file_loaded = true ;

  #ifdef SET_FILENAME_TITLE
  set_title(Glib::path_get_basename(filepath)) ;
  #endif

  return ;

}


/*
void click_it(bool &tedst, Gtk::Button &but, Gtk::Image &img_off, Gtk::Image &img_on) {

  if ( ! tedst ) {

    but.set_image(img_on) ;

    tedst = true ;

  }
  else {

    but.set_image(img_off) ;

    tedst = false ;

  }

}
*/

void GUI::message_dialog(const string title, const string msg, const bool error) {

  // TODO: Gtk::Window::set_titlebar(Widget&  titlebar)
  // Sets a custom (widget as) titlebar for window.

  Gtk::MessageDialog message_dialog(msg, false, ((error) ? Gtk::MESSAGE_ERROR : Gtk::MESSAGE_INFO) ) ;


  message_dialog.set_title(title) ;

  if (error) {
    message_dialog.set_icon_from_file(PATH_TO_MSG_DIALOG_ICONS "dialog-error.png") ;
  }
  else {
    message_dialog.set_icon_from_file(PATH_TO_MSG_DIALOG_ICONS "dialog-information.png") ;
  }


  message_dialog.show_all() ;

  message_dialog.run() ;

  message_dialog.close() ;

  return ;

}


void change_size(Controller &controller, Gtk::SpinButton &spinbutton_set_width, Gtk::SpinButton &spinbutton_set_height) {

  if ( controller.file_saving.auto_size && controller.file_saving.focus_width ) {

      Resizer resizer ;

      auto new_size = resizer.resizer(controller.file_saving.file_frame, spinbutton_set_width.get_value_as_int() , controller.source_image_size.second, false) ;

      #ifdef DEBUG
      ( resizer.assertion() ) ? : fprintf(stderr,"Error resizing assertion !!!\n") ;
      #endif

      if ( ( new_size.second != controller.file_saving.height )  ) {

        controller.file_saving.resizing = true ;

        spinbutton_set_height.set_value( static_cast<double>(new_size.second) ) ;

        controller.file_saving.width  = new_size.first  ;
        controller.file_saving.height = new_size.second ;

      }

      return ;

    }
    else if ( controller.file_saving.auto_size && (! controller.file_saving.focus_width) ) {


      Resizer resizer ;

      auto new_size = resizer.resizer(controller.file_saving.file_frame, controller.source_image_size.first , spinbutton_set_height.get_value_as_int() ) ;

      #ifdef DEBUG
      ( resizer.assertion() ) ? : fprintf(stderr,"Error resizing assertion !!!\n") ;
      #endif

      if ( (new_size.first != controller.file_saving.width || new_size.second != controller.file_saving.height ) )   {

        controller.file_saving.resizing = true ;

        spinbutton_set_width.set_value( static_cast<double>(new_size.first) ) ;

        controller.file_saving.width  = new_size.first  ;
        controller.file_saving.height = new_size.second ;

      }

      return ;

    }
    else  {

      controller.file_saving.resizing = true ;

      controller.file_saving.width  = spinbutton_set_width.get_value_as_int()  ;
      controller.file_saving.height = spinbutton_set_height.get_value_as_int()  ;

      return ;
   
    }
     
     
}

bool set_width_focus_in_event(GdkEventFocus *event, Controller &controller, Gtk::Button &button, Glib::RefPtr<Gtk::AccelGroup> &accel_group, bool &accel_is_on) {

  if (! accel_is_on) {

    Gdk::ModifierType no_modifier =  Gdk::MODIFIER_MASK ;

    no_modifier ^= no_modifier ;

    accel_is_on = button.remove_accelerator(accel_group, GDK_KEY_Return, no_modifier) ;
  }

  controller.file_saving.focus_width = true ;

  return true ;

}

bool set_height_focus_in_event(GdkEventFocus *event, Controller &controller, Gtk::Button &button, Glib::RefPtr<Gtk::AccelGroup> &accel_group, bool &accel_is_on) {

  if (! accel_is_on) {

    Gdk::ModifierType no_modifier =  Gdk::MODIFIER_MASK ;

    no_modifier ^= no_modifier ;

    accel_is_on = button.remove_accelerator(accel_group, GDK_KEY_Return, no_modifier) ;
  }

  controller.file_saving.focus_width = false ;

  return true ;

}





void GUI::save_as_image_file_settings(Controller &controller) {



  controller.file_saving.apply = false ;

  controller.file_saving.file_frame = controller.current_image_to_process.clone() ;

  controller.file_saving.auto_size = false ;

  controller.file_saving.resizing = false ;

  Gtk::Dialog dialog("Save as image file settings", true) ;

  Gtk::ButtonBox *buttonbox = dialog.get_action_area() ;

  buttonbox->set_layout(Gtk::BUTTONBOX_EDGE) ;
  buttonbox->set_homogeneous(true) ;

  Gtk::Button button_ok("OK") ;
  Gtk::Image  image_ok(PATH_TO_BUTTON_ICONS "dialog-ok-apply.png")  ;

  button_ok.set_image(image_ok) ;
  button_ok.set_always_show_image(true) ;

  Gtk::Button button_cancel("Cancel")  ;
  Gtk::Image  image_cancel(PATH_TO_BUTTON_ICONS "dialog-cancel.png") ;

  button_cancel.set_image(image_cancel) ;
  button_cancel.set_always_show_image(true) ;

  dialog.add_action_widget(button_cancel, Gtk::RESPONSE_CANCEL) ;
  dialog.add_action_widget(button_ok,     Gtk::RESPONSE_OK) ;


  Glib::RefPtr<Gtk::AccelGroup>     accel_group        ;

  Gdk::ModifierType no_modifier =  Gdk::MODIFIER_MASK ;

  no_modifier ^= no_modifier ;

  accel_group = accel_group->create() ;

  button_ok.add_accelerator("clicked", accel_group, GDK_KEY_Return, no_modifier, Gtk::ACCEL_VISIBLE) ;

  dialog.add_accel_group(accel_group) ;


  bool accel_is_on = false ;



  dialog.set_border_width(4)  ;
  dialog.set_resizable(false) ;
  dialog.set_decorated(false) ;
  dialog.set_hide_titlebar_when_maximized( true ) ;

  dialog.set_icon_from_file(PATH_TO_MSG_DIALOG_ICONS "insert-image.png") ;
  dialog.set_position(Gtk::WIN_POS_CENTER_ON_PARENT) ;
  dialog.set_type_hint(Gdk::WINDOW_TYPE_HINT_DIALOG) ;
  dialog.set_transient_for(*this) ;







  Gtk::Button button_filename_title("Name  ") ;

  Gtk::Entry  entry_filename_title ;

  entry_filename_title.set_text(Glib::path_get_basename(controller.file_saving.filepath)) ;

  entry_filename_title.set_width_chars(40) ;
  entry_filename_title.set_alignment(0.5f) ;
  entry_filename_title.set_overwrite_mode(false) ;
  Glib::PropertyProxy< bool > entry_editable = entry_filename_title.property_editable() ;

  entry_editable = false ;

  Gtk::Button button_size_title("Size") ;

  Gtk::Button button_size_width_titel("Width ") ;

  Gtk::SpinButton  spinbutton_set_width  ;

  spinbutton_set_width.set_digits(0)     ;
  spinbutton_set_width.set_range(1.0, DBL_MAX) ;
  spinbutton_set_width.set_value(static_cast<double>(controller.file_saving.width))     ;
  spinbutton_set_width.set_increments(1.0, 10.0)     ;
  spinbutton_set_width.set_numeric(true) ;
  spinbutton_set_width.set_max_length(6) ;
  spinbutton_set_width.set_width_chars(6) ;
  //spinbutton_set_width.set_snap_to_ticks(true) ;

  spinbutton_set_width.set_has_frame(true) ;
  spinbutton_set_width.set_alignment(0.5f) ;


  Gtk::Button button_size_height_titel("Height") ;

  Gtk::SpinButton  spinbutton_set_height ;

  spinbutton_set_height.set_digits(0)     ;
  spinbutton_set_height.set_range(1.0, DBL_MAX) ;
  spinbutton_set_height.set_value(static_cast<double>(controller.file_saving.height))     ;
  spinbutton_set_height.set_increments(1.0, 10.0)     ;
  spinbutton_set_height.set_numeric(true) ;
  spinbutton_set_height.set_max_length(6) ;
  spinbutton_set_height.set_width_chars(6) ;
  //spinbutton_set_height.set_snap_to_ticks(true) ;

  spinbutton_set_height.set_has_frame(true) ;
  spinbutton_set_height.set_alignment(0.5f) ;

  spinbutton_set_width.set_events(Gdk::FOCUS_CHANGE_MASK)   ;
  spinbutton_set_height.set_events(Gdk::FOCUS_CHANGE_MASK)  ;


  spinbutton_set_width.signal_focus_in_event().connect(sigc::bind<Controller &, Gtk::Button &, Glib::RefPtr<Gtk::AccelGroup> &, bool &>(sigc::ptr_fun(set_width_focus_in_event), controller, button_ok, accel_group, accel_is_on)) ;
  spinbutton_set_height.signal_focus_in_event().connect(sigc::bind<Controller &, Gtk::Button &, Glib::RefPtr<Gtk::AccelGroup> &, bool &>(sigc::ptr_fun(set_height_focus_in_event), controller, button_ok, accel_group, accel_is_on)) ;

  spinbutton_set_width.signal_value_changed().connect([&controller, &spinbutton_set_width, &spinbutton_set_height] () {

    change_size(controller, spinbutton_set_width, spinbutton_set_height) ;

    controller.file_saving.focus_width = true ;

  } ) ;

  spinbutton_set_height.signal_value_changed().connect([&controller, &spinbutton_set_width, &spinbutton_set_height] () {

    change_size(controller, spinbutton_set_width, spinbutton_set_height) ;

    controller.file_saving.focus_width = false ;

  } ) ;

  Gtk::Box box_sizes_padding_left  ;
  Gtk::Box box_sizes_padding_right ;


  Gtk::Button button_auto_size_switch("") ;



  Gtk::Image  image_auto_size_switch_off(PATH_TO_AUTOSIZE_ICONS "unlocking.png") ;
  Gtk::Image  image_auto_size_switch_on(PATH_TO_AUTOSIZE_ICONS "locking.png")   ;

  button_auto_size_switch.set_image(image_auto_size_switch_off) ;
  button_auto_size_switch.set_always_show_image(true)           ;


  button_auto_size_switch.signal_clicked().connect([&button_auto_size_switch, &controller, &image_auto_size_switch_off, &image_auto_size_switch_on, &spinbutton_set_width, &spinbutton_set_height] () {

    if ( ! controller.file_saving.auto_size ) {

      button_auto_size_switch.set_image(image_auto_size_switch_on) ;

      controller.file_saving.auto_size = true ;

      change_size(controller, spinbutton_set_width, spinbutton_set_height) ;

    }
    else {

      button_auto_size_switch.set_image(image_auto_size_switch_off) ;

      controller.file_saving.auto_size = false ;

    }

  } ) ;

  Gtk::Box save_as_settings_filename_hbox(Gtk::ORIENTATION_HORIZONTAL, false) ;

  Gtk::Box save_as_settings_labels_size_vbox(Gtk::ORIENTATION_VERTICAL, false) ;

  Gtk::Box save_as_settings_entry_size_vbox(Gtk::ORIENTATION_VERTICAL, false) ;

  Gtk::Box save_as_settings_sizes_hbox(Gtk::ORIENTATION_HORIZONTAL, false) ;

  Gtk::Box button_padding_01 ;

  Gtk::Box button_padding_02 ;

  Gtk::Box save_as_settings_button_size_vbox(Gtk::ORIENTATION_VERTICAL, true) ;


  save_as_settings_sizes_hbox.set_border_width(12) ;

  save_as_settings_sizes_hbox.set_spacing(8) ;

  save_as_settings_filename_hbox.set_spacing(4) ;

  save_as_settings_labels_size_vbox.set_spacing(4) ;

  save_as_settings_entry_size_vbox.set_spacing(4) ;

  save_as_settings_button_size_vbox.set_spacing(4) ;

  save_as_settings_filename_hbox.pack_start(button_filename_title,    false, false, 0) ;
  save_as_settings_filename_hbox.pack_start(entry_filename_title,     false, false, 0) ;


  save_as_settings_labels_size_vbox.pack_start(button_size_width_titel,   false, false, 0) ;
  save_as_settings_labels_size_vbox.pack_start(button_size_height_titel,  false, false, 0) ;


  save_as_settings_entry_size_vbox.pack_start(spinbutton_set_width,             false, false, 0) ;
  save_as_settings_entry_size_vbox.pack_start(spinbutton_set_height,            false, false, 0) ;

  //save_as_settings_button_size_vbox.pack_start(button_padding_01,               true,  true,  0) ;
  save_as_settings_button_size_vbox.pack_start(button_auto_size_switch,         true, true, 0) ;
  //save_as_settings_button_size_vbox.pack_start(button_padding_02,               true,  true,  0) ;

  save_as_settings_sizes_hbox.pack_start(box_sizes_padding_left,                true,  true,  0) ;
  save_as_settings_sizes_hbox.pack_start(save_as_settings_labels_size_vbox,     false, false, 0) ;
  save_as_settings_sizes_hbox.pack_start(save_as_settings_entry_size_vbox,      false, false, 0) ;
  save_as_settings_sizes_hbox.pack_start(save_as_settings_button_size_vbox,     false, false, 0) ;
  save_as_settings_sizes_hbox.pack_start(box_sizes_padding_right,               true,  true,  0) ;


  Gtk::Box *main_content_box = dialog.get_content_area() ;

  main_content_box->pack_start(save_as_settings_filename_hbox, false, false, 0) ;
  main_content_box->pack_start(save_as_settings_sizes_hbox,    false, false, 0) ;

  /** Decalaration of configuration widgets in relationship to file extension **/

  Gtk::Expander expander_save_as_settings_options("Options")  ;
  expander_save_as_settings_options.set_expanded(false)       ;
  expander_save_as_settings_options.set_resize_toplevel(true) ;

  Gtk::Box      save_as_settings_options_vbox(Gtk::ORIENTATION_VERTICAL) ;

  save_as_settings_options_vbox.set_border_width(8) ;
  save_as_settings_options_vbox.set_spacing(4)      ;

  /**               PNG specific configuration widgets                        **/
  Gtk::Frame        frame_png_compression(" PNG Compression ")                   ;
  Gtk::Scale        scale_png_compression(Gtk::ORIENTATION_HORIZONTAL)           ;
  Gtk::Frame        frame_png_strategy(" PNG Strategy ")                         ;
  Gtk::ComboBoxText comboboxtext_png_strategy(true)                              ;
  Gtk::CheckButton  checkbutton_png_bilevel(" PNG Binary level ")                ;
  /** **********************************************************************  **/

  /**              JPEG specific configuration widgets                        **/
  Gtk::Frame       frame_jpeg_quality(" JPEG Quality ")                          ;
  Gtk::Scale       scale_jpeg_quality(Gtk::ORIENTATION_HORIZONTAL)               ;
  Gtk::Frame       frame_jpeg_luma_quality(" JPEG Separate Luma quality ")       ;
  Gtk::Scale       scale_jpeg_luma_quality(Gtk::ORIENTATION_HORIZONTAL)          ;
  Gtk::Frame       frame_jpeg_chroma_quality(" JPEG Separate Chroma quality ")   ;
  Gtk::Scale       scale_jpeg_chroma_quality(Gtk::ORIENTATION_HORIZONTAL)        ;
  Gtk::Frame       frame_jpeg_restart_interval(" JPEG Restart Interval ")        ;
  Gtk::Scale       scale_jpeg_restart_interval(Gtk::ORIENTATION_HORIZONTAL)      ;
  Gtk::CheckButton checkbutton_jpeg_progressiv(" JPEG Progressiv ")              ;
  Gtk::CheckButton checkbutton_jpeg_optimize(" JPEG Optimize ")                  ;
  /** **********************************************************************  **/

  /**              WEBP specific configuration widgets                        **/
  Gtk::Frame       frame_webp_quality(" WEBP Quality ")                          ;
  Gtk::Scale       scale_webp_quality(Gtk::ORIENTATION_HORIZONTAL)               ;
  /** **********************************************************************  **/

  /**              PXM specific configuration widgets                        **/
  Gtk::CheckButton checkbutton_pxm_binary(" PXM Binary ")                    ;
  /** **********************************************************************  **/

  #ifdef SUPPORT_PNG
  if (controller.file_saving.extension == ".png") {

    scale_png_compression.set_digits(0)                                                ;
    scale_png_compression.set_draw_value(true)                                         ;
    scale_png_compression.set_has_origin(true)                                         ;

    scale_png_compression.set_upper_stepper_sensitivity(Gtk::SENSITIVITY_ON)           ;
    scale_png_compression.set_lower_stepper_sensitivity(Gtk::SENSITIVITY_ON)           ;
    //scale_png_compression.set_adjustment(scale_png_compression.get_adjustment() )      ;

    scale_png_compression.set_range(0.0, 9.0)                                          ;
    scale_png_compression.set_value(controller.png_settings.png_compression)           ;
    scale_png_compression.set_increments(1.0, 1.0)                                     ;
    scale_png_compression.add_mark(3.0, Gtk::POS_TOP, "")                              ;

    scale_png_compression.set_margin_top(0)    ;
    scale_png_compression.set_margin_bottom(0) ;
    scale_png_compression.set_margin_right(8)  ;
    scale_png_compression.set_margin_left(8)   ;

    frame_png_compression.set_margin_top(4) ;
    frame_png_compression.set_margin_bottom(4) ;

    frame_png_compression.add(scale_png_compression) ;




    comboboxtext_png_strategy.insert(0, "Default") ;
    comboboxtext_png_strategy.insert(1, "Filtered") ;
    comboboxtext_png_strategy.insert(2, "Huffman only") ;
    comboboxtext_png_strategy.insert(3, "RLE") ;
    comboboxtext_png_strategy.insert(4, "Fixed") ;

    comboboxtext_png_strategy.set_active(controller.png_settings.png_strategy) ;


    comboboxtext_png_strategy.set_margin_top(8)    ;
    comboboxtext_png_strategy.set_margin_bottom(8) ;
    comboboxtext_png_strategy.set_margin_right(8)  ;
    comboboxtext_png_strategy.set_margin_left(8)   ;




    frame_png_strategy.set_margin_top(4) ;
    frame_png_strategy.set_margin_bottom(4) ;

    frame_png_strategy.add(comboboxtext_png_strategy) ;




    checkbutton_png_bilevel.set_mode(false)  ;

    checkbutton_png_bilevel.set_active(controller.png_settings.png_bilevel) ;

    checkbutton_png_bilevel.set_margin_top(8)    ;
    checkbutton_png_bilevel.set_margin_bottom(8) ;

    checkbutton_png_bilevel.set_tooltip_text("Only for binary (black and white) images.") ;





    /** ******* Pack configuration widgets in relationship to file extension. ******* **/

    save_as_settings_options_vbox.pack_start(frame_png_compression,   false, false, 0) ;
    save_as_settings_options_vbox.pack_start(frame_png_strategy,      false, false, 0) ;
    save_as_settings_options_vbox.pack_start(checkbutton_png_bilevel, false, false, 0) ;


    expander_save_as_settings_options.add(save_as_settings_options_vbox) ;

    main_content_box->pack_start(expander_save_as_settings_options, false, false, 0) ;

    /** ***************************************************************************** **/

  }
  #endif

  #ifdef SUPPORT_JPG
  if (controller.file_saving.extension == ".jpeg" || controller.file_saving.extension == ".jpg" || controller.file_saving.extension == ".jpe" ) {





    scale_jpeg_quality.set_digits(0)                                                 ;
    scale_jpeg_quality.set_draw_value(true)                                          ;
    scale_jpeg_quality.set_has_origin(true)                                          ;

    scale_jpeg_quality.set_upper_stepper_sensitivity(Gtk::SENSITIVITY_ON)            ;
    scale_jpeg_quality.set_lower_stepper_sensitivity(Gtk::SENSITIVITY_ON)            ;
    scale_jpeg_quality.set_adjustment(scale_jpeg_quality.get_adjustment() )      ;

    scale_jpeg_quality.set_range(0.0, 100.0)                                         ;
    scale_jpeg_quality.set_value(controller.jpeg_settings.jpeg_quality)              ;
    scale_jpeg_quality.set_increments(1.0, 10.0)                                     ;
    scale_jpeg_quality.add_mark(50.0, Gtk::POS_TOP, "")                              ;

    scale_jpeg_quality.set_margin_top(0)    ;
    scale_jpeg_quality.set_margin_bottom(0) ;
    scale_jpeg_quality.set_margin_right(8)  ;
    scale_jpeg_quality.set_margin_left(8)   ;


    frame_jpeg_quality.add(scale_jpeg_quality) ;



    scale_jpeg_luma_quality.set_digits(0)                                                 ;
    scale_jpeg_luma_quality.set_draw_value(true)                                          ;
    scale_jpeg_luma_quality.set_has_origin(true)                                          ;

    scale_jpeg_luma_quality.set_upper_stepper_sensitivity(Gtk::SENSITIVITY_ON)            ;
    scale_jpeg_luma_quality.set_lower_stepper_sensitivity(Gtk::SENSITIVITY_ON)            ;
    //scale_jpeg_luma_quality.set_adjustment(scale_jpeg_luma_quality.get_adjustment() )      ;

    scale_jpeg_luma_quality.set_range(0.0, 100.0)                                         ;
    scale_jpeg_luma_quality.set_value(controller.jpeg_settings.jpeg_luma_quality)         ;
    scale_jpeg_luma_quality.set_increments(1.0, 10.0)                                     ;
    scale_jpeg_luma_quality.add_mark(50.0, Gtk::POS_TOP, "")                              ;

    scale_jpeg_luma_quality.set_margin_top(0)    ;
    scale_jpeg_luma_quality.set_margin_bottom(0) ;
    scale_jpeg_luma_quality.set_margin_right(8)  ;
    scale_jpeg_luma_quality.set_margin_left(8)   ;


    frame_jpeg_luma_quality.add(scale_jpeg_luma_quality) ;


    scale_jpeg_chroma_quality.set_digits(0)                                                 ;
    scale_jpeg_chroma_quality.set_draw_value(true)                                          ;
    scale_jpeg_chroma_quality.set_has_origin(true)                                          ;

    scale_jpeg_chroma_quality.set_upper_stepper_sensitivity(Gtk::SENSITIVITY_ON)            ;
    scale_jpeg_chroma_quality.set_lower_stepper_sensitivity(Gtk::SENSITIVITY_ON)            ;
    //scale_jpeg_chroma_quality.set_adjustment(scale_jpeg_chroma_quality.get_adjustment() )      ;

    scale_jpeg_chroma_quality.set_range(0.0, 100.0)                                         ;
    scale_jpeg_chroma_quality.set_value(controller.jpeg_settings.jpeg_chroma_quality)       ;
    scale_jpeg_chroma_quality.set_increments(1.0, 10.0)                                     ;
    scale_jpeg_chroma_quality.add_mark(50.0, Gtk::POS_TOP, "")                              ;

    scale_jpeg_chroma_quality.set_margin_top(0)    ;
    scale_jpeg_chroma_quality.set_margin_bottom(0) ;
    scale_jpeg_chroma_quality.set_margin_right(8)  ;
    scale_jpeg_chroma_quality.set_margin_left(8)   ;


    frame_jpeg_chroma_quality.add(scale_jpeg_chroma_quality) ;


    scale_jpeg_restart_interval.set_digits(0)                                                ;
    scale_jpeg_restart_interval.set_draw_value(true)                                         ;
    scale_jpeg_restart_interval.set_has_origin(true)                                         ;

    scale_jpeg_restart_interval.set_upper_stepper_sensitivity(Gtk::SENSITIVITY_ON)           ;
    scale_jpeg_restart_interval.set_lower_stepper_sensitivity(Gtk::SENSITIVITY_ON)           ;
    //scale_jpeg_restart_interval.set_adjustment(scale_jpeg_restart_interval.get_adjustment() )      ;

    scale_jpeg_restart_interval.set_range(0.0, 100.0)                                        ;
    scale_jpeg_restart_interval.set_value(controller.jpeg_settings.jpeg_rst_interval)        ;
    scale_jpeg_restart_interval.set_increments(1.0, 10.0)                                    ;
    scale_jpeg_restart_interval.add_mark(50.0, Gtk::POS_TOP, "")                              ;

    scale_jpeg_restart_interval.set_margin_top(0)    ;
    scale_jpeg_restart_interval.set_margin_bottom(0) ;
    scale_jpeg_restart_interval.set_margin_right(8)  ;
    scale_jpeg_restart_interval.set_margin_left(8)   ;



    checkbutton_jpeg_progressiv.set_mode(false)  ;

    checkbutton_jpeg_progressiv.set_active(controller.jpeg_settings.jpeg_progressiv)   ;

    checkbutton_jpeg_progressiv.set_margin_top(8)    ;
    checkbutton_jpeg_progressiv.set_margin_bottom(8) ;



    checkbutton_jpeg_optimize.set_mode(false)  ;

    checkbutton_jpeg_progressiv.set_active(controller.jpeg_settings.jpeg_optimize)   ;

    checkbutton_jpeg_optimize.set_margin_top(8)    ;
    checkbutton_jpeg_optimize.set_margin_bottom(8) ;


    /** ******* Pack configuration widgets in relationship to file extension. ******* **/

    save_as_settings_options_vbox.pack_start(frame_jpeg_quality,             false, false, 0) ;
    save_as_settings_options_vbox.pack_start(checkbutton_jpeg_optimize,      false, false, 0) ;
    save_as_settings_options_vbox.pack_start(frame_jpeg_luma_quality,        false, false, 0) ;
    save_as_settings_options_vbox.pack_start(frame_jpeg_chroma_quality,      false, false, 0) ;
    save_as_settings_options_vbox.pack_start(checkbutton_jpeg_progressiv,    false, false, 0) ;


    expander_save_as_settings_options.add(save_as_settings_options_vbox) ;

    main_content_box->pack_start(expander_save_as_settings_options, false, false, 0) ;

    /** ***************************************************************************** **/

  }
  #endif

  #ifdef SUPPORT_PORTABLE_IMAGE_FORMAT // Always supported.
  if (controller.file_saving.extension == ".pgm" || controller.file_saving.extension == ".pbm" || controller.file_saving.extension == ".ppm" ) {

    checkbutton_pxm_binary.set_mode(false)  ;

    checkbutton_pxm_binary.set_active(controller.pxm_settings.pxm_binary) ;

    checkbutton_pxm_binary.set_margin_top(8)    ;
    checkbutton_pxm_binary.set_margin_bottom(8) ;


    /** ******* Pack configuration widgets in relationship to file extension. ******* **/

    save_as_settings_options_vbox.pack_start(checkbutton_pxm_binary, false, false, 0) ;

    expander_save_as_settings_options.add(save_as_settings_options_vbox)                  ;

    main_content_box->pack_start(expander_save_as_settings_options,      false, false, 0) ;

    /** ***************************************************************************** **/



  }
  #endif

  #ifdef SUPPORT_WEBP
  if (controller.file_saving.extension == ".webp") {

    scale_webp_quality.set_digits(0)                                                 ;
    scale_webp_quality.set_draw_value(true)                                          ;
    scale_webp_quality.set_has_origin(true)                                          ;

    scale_webp_quality.set_upper_stepper_sensitivity(Gtk::SENSITIVITY_ON)            ;
    scale_webp_quality.set_lower_stepper_sensitivity(Gtk::SENSITIVITY_ON)            ;
    scale_webp_quality.set_adjustment(scale_webp_quality.get_adjustment() )      ;

    scale_webp_quality.set_range(0.0, 100.0)                                         ;
    scale_webp_quality.set_value(controller.webp_settings.webp_quality)              ;
    scale_webp_quality.set_increments(1.0, 10.0)                                     ;
    scale_webp_quality.add_mark(50.0, Gtk::POS_TOP, "")                              ;

    scale_webp_quality.set_margin_top(0)    ;
    scale_webp_quality.set_margin_bottom(0) ;
    scale_webp_quality.set_margin_right(8)  ;
    scale_webp_quality.set_margin_left(8)   ;


    frame_webp_quality.add(scale_webp_quality) ;

    /** ******* Pack configuration widgets in relationship to file extension. ******* **/

    save_as_settings_options_vbox.pack_start(frame_webp_quality,             false, false, 0) ;

    expander_save_as_settings_options.add(save_as_settings_options_vbox) ;

    main_content_box->pack_start(expander_save_as_settings_options, false, false, 0) ;

    /** ***************************************************************************** **/

  }
  #endif




  dialog.show_all() ;


  const string title = "File saving error" ;

  string msg   = "Error saving file: " ;

  msg += Glib::path_get_basename(controller.file_saving.filepath) ;

  error_saving_file :

  int result = dialog.run() ;

  switch (result) {

    case Gtk::RESPONSE_OK : {

      //controller.current_image_to_process = controller.image_to_display_vector.at(controller.image_to_display_vector_idx) ;

      // After Must be resize !!!
      //controller.file_saving.file_frame = controller.current_image_to_process.clone() ;

      if (controller.file_saving.resizing) {

        cv::resize(controller.file_saving.file_frame, controller.file_saving.file_frame, cv::Size(controller.file_saving.width, controller.file_saving.height), 1.0, 1.0, cv::INTER_LINEAR) ;

      }


      #ifdef SUPPORT_PNG
      if (controller.file_saving.extension == ".png") {

        vector<int> png_params ;

        png_params.push_back(cv::IMWRITE_PNG_COMPRESSION) ;
        png_params.push_back( static_cast<int>(scale_png_compression.get_value()) ) ;

        png_params.push_back(cv::IMWRITE_PNG_STRATEGY)    ;
        png_params.push_back( comboboxtext_png_strategy.get_active_row_number() );

        // This must be a binary image if i understand it right.
        png_params.push_back(cv::IMWRITE_PNG_BILEVEL)    ;
        png_params.push_back(((checkbutton_png_bilevel.get_active()) ? 1 : 0) );


        if (checkbutton_png_bilevel.get_active()) {

          cv::cvtColor(controller.file_saving.file_frame, controller.file_saving.file_frame, ((controller.file_saving.file_frame.channels() == 4) ? CV_BGRA2GRAY : CV_BGR2GRAY) ) ;

        }


        if (! imwrite(controller.file_saving.filepath, controller.file_saving.file_frame, png_params) ) {

          unlink(controller.file_saving.filepath.c_str()) ;

          message_dialog(title, msg) ;

          goto error_saving_file ;

        }

        break ;

      }
      #endif

      #ifdef SUPPORT_JPG
      if (controller.file_saving.extension == ".jpeg" || controller.file_saving.extension == ".jpg" || controller.file_saving.extension == ".jpe" ) {

        vector<int> jpeg_params ;

        jpeg_params.push_back(cv::IMWRITE_JPEG_QUALITY) ;
        jpeg_params.push_back( static_cast<int>(scale_jpeg_quality.get_value()) );



        if ( static_cast<int>(checkbutton_jpeg_progressiv.get_active())  ) {
          jpeg_params.push_back(cv::IMWRITE_JPEG_PROGRESSIVE)    ;
          jpeg_params.push_back( static_cast<int>(checkbutton_jpeg_progressiv.get_active()) );
        }


        if ( static_cast<int>(checkbutton_jpeg_optimize.get_active())  ) {
          jpeg_params.push_back(cv::IMWRITE_JPEG_OPTIMIZE)    ;
          jpeg_params.push_back( static_cast<int>(checkbutton_jpeg_optimize.get_active()) );
        }

        if ( static_cast<int>(scale_jpeg_restart_interval.get_value())  ) {
          jpeg_params.push_back(cv::IMWRITE_JPEG_RST_INTERVAL) ;
          jpeg_params.push_back( static_cast<int>(scale_jpeg_restart_interval.get_value()) );
        }

        if ( static_cast<int>(scale_jpeg_luma_quality.get_value()) ) {
          jpeg_params.push_back(cv::IMWRITE_JPEG_LUMA_QUALITY) ;
          jpeg_params.push_back( static_cast<int>(scale_jpeg_luma_quality.get_value()) );
        }


        if ( static_cast<int>(scale_jpeg_chroma_quality.get_value()) ) {
          jpeg_params.push_back(cv::IMWRITE_JPEG_CHROMA_QUALITY) ;
          jpeg_params.push_back( static_cast<int>(scale_jpeg_chroma_quality.get_value()) );
        }





        if (! imwrite(controller.file_saving.filepath, controller.file_saving.file_frame, jpeg_params) ) {

          unlink(controller.file_saving.filepath.c_str()) ;

          message_dialog(title, msg) ;

          goto error_saving_file ;

        }


        break ;

      }

      #endif

      #ifdef SUPPORT_PORTABLE_IMAGE_FORMAT
      if (controller.file_saving.extension == ".pgm" || controller.file_saving.extension == ".pbm" || controller.file_saving.extension == ".ppm" ) {

        vector<int> pxm_params ;

        pxm_params.push_back(cv::IMWRITE_PXM_BINARY)    ;
        pxm_params.push_back( static_cast<int>(checkbutton_pxm_binary.get_active()) );


        if (! imwrite(controller.file_saving.filepath, controller.file_saving.file_frame, pxm_params) ) {

          unlink(controller.file_saving.filepath.c_str()) ;

          message_dialog(title, msg) ;

          goto error_saving_file ;

        }

        break ;

      }
      #endif

      #ifdef SUPPORT_WEBP
      if (controller.file_saving.extension == ".webp") {

        vector<int> webp_params ;

        webp_params.push_back(cv::IMWRITE_JPEG_QUALITY) ;
        webp_params.push_back( static_cast<int>(scale_webp_quality.get_value()) );


        if (!  imwrite(controller.file_saving.filepath, controller.file_saving.file_frame, webp_params) ) {

          unlink(controller.file_saving.filepath.c_str()) ;

          message_dialog(title, msg) ;

          goto error_saving_file ;

        }

        break ;

      }
      #endif


      if (! imwrite(controller.file_saving.filepath, controller.file_saving.file_frame) ) {

        unlink(controller.file_saving.filepath.c_str()) ;

        message_dialog(title, msg) ;

        goto error_saving_file ;

      }


      break ;

    }

 }

 dialog.close() ;

 return ;

}

const string GUI::guess_extension(const string filepath) const {

  auto point_pos = Glib::path_get_basename(filepath).rfind('.') ;

  string ret ;

  if (point_pos == Glib::ustring::npos) { return "" ; }

  string extension = Glib::path_get_basename(filepath).substr(point_pos) ;

  if (! extension.empty() ) {



    for (auto character : extension) {

      ret += tolower(character) ;

    }

  }

  return ret ;

}

void GUI::select_save_as_file(Controller &controller) {

  if ( controller.current_image_to_process.empty() ) {

    message_dialog("File error !", "You must load an file before saving it.") ;

    return ;

  }

  Gtk::FileChooserDialog dialog("Choice a image file to open.", Gtk::FILE_CHOOSER_ACTION_SAVE);

  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "document-save-as.png") ;

  Gtk::ButtonBox *buttonbox = dialog.get_action_area() ;

  //buttonbox->set_layout(Gtk::BUTTONBOX_EDGE) ;
  buttonbox->set_homogeneous(true) ;

  dialog.set_transient_for(*this);

  dialog.set_select_multiple(false) ;

  dialog.set_show_hidden(false) ;

  dialog.set_current_folder(Glib::get_home_dir()) ;

  dialog.set_do_overwrite_confirmation(true) ;

  dialog.add_button(Gtk::Stock::CANCEL,  Gtk::RESPONSE_CANCEL);
  dialog.add_button(Gtk::Stock::SAVE_AS, Gtk::RESPONSE_APPLY);


  #ifdef SUPPORT_PNG // Always supported.
  Glib::RefPtr<Gtk::FileFilter> file_filter_png = Gtk::FileFilter::create() ;

  file_filter_png->add_pattern("*.png") ;

  file_filter_png->add_mime_type("image/png") ;

  // ATTENTION this string gonna be COMPARE !!!
  file_filter_png->set_name("Format: *.png (Portable Network Graphics).") ; // ATTENTION this string gonna be COMPARE !!!

  dialog.add_filter(file_filter_png) ;
  #endif


  #ifdef SUPPORT_BMP // Always supported.
  Glib::RefPtr<Gtk::FileFilter> file_filter_bmp = Gtk::FileFilter::create() ;

  file_filter_bmp->add_pattern("*.bmp") ;
  file_filter_bmp->add_pattern("*.dib") ;

  file_filter_bmp->add_mime_type("image/bmp") ;

  file_filter_bmp->set_name("Format: *.bmp, *.dib (Bitmap Image File).") ; // ATTENTION this string gonna be COMPARE !!!

  dialog.add_filter(file_filter_bmp) ;
  #endif

  #ifdef SUPPORT_JPG
  Glib::RefPtr<Gtk::FileFilter> file_filter_jpeg = Gtk::FileFilter::create() ;

  file_filter_jpeg->add_pattern("*.jpeg") ;
  file_filter_jpeg->add_pattern("*.jpg")  ;
  file_filter_jpeg->add_pattern("*.jpe")  ;

  file_filter_jpeg->add_mime_type("image/jpeg") ;

  // ATTENTION this string gonna be COMPARE !!!
  file_filter_jpeg->set_name("Format: *.jpeg, *.jpg, *.jpe (Join Photgraphic Experts Group).") ; // ATTENTION this string gonna be COMPARE !!!

  dialog.add_filter(file_filter_jpeg) ;
  #endif


  #ifdef SUPPORT_TIF
  Glib::RefPtr<Gtk::FileFilter> file_filter_tiff = Gtk::FileFilter::create() ;

  file_filter_tiff->add_pattern("*.tiff") ;
  file_filter_tiff->add_pattern("*.tif")  ;

  file_filter_tiff->add_mime_type("image/tiff") ;

  // ATTENTION this string gonna be COMPARE !!!
  file_filter_tiff->set_name("Format: *.tiff, *.tif, (Tag(ged) Image File Format).") ; // ATTENTION this string gonna be COMPARE !!!

  dialog.add_filter(file_filter_tiff) ;
  #endif


  #ifdef SUPPORT_SUN_RASTER // Always supported.
  Glib::RefPtr<Gtk::FileFilter> file_filter_ras = Gtk::FileFilter::create() ;

  file_filter_ras->add_pattern("*.ras") ;
  file_filter_ras->add_pattern("*.sr")  ;

  file_filter_ras->add_mime_type("image/x-cmu-raster") ;

  // ATTENTION this string gonna be COMPARE !!!
  file_filter_ras->set_name("Format: *.ras, *.sr, (Sun Rasters).") ;  // ATTENTION this string gonna be COMPARE !!!

  dialog.add_filter(file_filter_ras) ;
  #endif

  #ifdef SUPPORT_PORTABLE_IMAGE_FORMAT // Always supported.
  Glib::RefPtr<Gtk::FileFilter> file_filter_pbm = Gtk::FileFilter::create() ;

  file_filter_pbm->add_pattern("*.pbm") ;
  file_filter_pbm->add_pattern("*.pgm") ;
  file_filter_pbm->add_pattern("*.ppm") ;

  file_filter_pbm->add_mime_type("image/x-portable-bitmap")   ;
  file_filter_pbm->add_mime_type("image/x-portable-graymap")  ;
  file_filter_pbm->add_mime_type("image/x-portable-pixmap")   ;

  // ATTENTION this string gonna be COMPARE !!!
  file_filter_pbm->set_name("Format: *.pbm, *.pgm, *.ppm (Portable Image Format).") ;  // ATTENTION this string gonna be COMPARE !!!

  dialog.add_filter(file_filter_pbm) ;
  #endif


  #ifdef SUPPORT_WEBP
  Glib::RefPtr<Gtk::FileFilter> file_filter_webp = Gtk::FileFilter::create() ;

  file_filter_webp->add_pattern("*.webp") ;

  file_filter_webp->add_mime_type("image/webp") ;

  // ATTENTION this string gonna be COMPARE !!!
  file_filter_webp->set_name("Format: *.webp") ;  // To extend description text.

  dialog.add_filter(file_filter_webp) ;
  #endif


  dialog.set_create_folders(true) ;

  dialog.set_show_hidden(false) ;

  dialog.set_use_preview_label(true) ;

  //dialog.signal_selection_changed().connect(sigc::bind<Gtk::FileChooserDialog &>(sigc::mem_fun(*this, &GUI::check_save_file_changed), dialog)) ;

  int result = dialog.run()  ;

  bool answers_apply = false ;

  //Handle the response:
  switch (result) {

    case Gtk::RESPONSE_APPLY : {

      //Notice that this is a std::string, not a Glib::ustring.
      string filepath = dialog.get_filename() ;

      string extension = guess_extension(filepath) ;

      if ( (  extension == ".png")  ||
           (  extension == ".jpg"   || extension == ".jpe"    || extension ==  ".jpeg" ) ||
           (  extension == ".bmp"   || extension == ".dib"  ) ||
           (  extension == ".tif"   || extension == ".tiff" ) ||
           (  extension == ".ras"   || extension == ".sr"   ) ||
           (  extension == ".pbm"   || extension == ".pgm"    || extension == ".ppm" )   ||
           (  extension == ".webp"  ))

           { controller.file_saving.extension = extension ; }

       else {

         Glib::RefPtr<Gtk::FileFilter> actual_filter = dialog.get_filter() ;

         auto description = actual_filter->get_name() ;

         #ifdef SUPPORT_PNG
         if (description == "Format: *.png (Portable Network Graphics).") {

           if (extension == ".") { filepath += "png" ; }
           else { filepath += ".png" ; }

           controller.file_saving.extension = ".png" ;

         }
         #endif

         #ifdef SUPPORT_BMP // Always supported.
         if (description == "Format: *.bmp, *.dib (Bitmap Image File).") {

           if (extension == ".") { filepath += "bmp" ; }
           else { filepath += ".bmp" ; }

           controller.file_saving.extension = ".bmp" ;

         }
         #endif

         #ifdef SUPPORT_JPG
         if (description == "Format: *.jpeg, *.jpg, *.jpe (Join Photgraphic Experts Group).") {

           if (extension == ".") { filepath += "jpg" ; }
           else { filepath += ".jpg" ; }

           controller.file_saving.extension = ".jpg" ;

         }
         #endif

         #ifdef SUPPORT_TIF
         else if (description == "Format: *.tiff, *.tif, (Tag(ged) Image File Format).") {

           if (extension == ".") { filepath += "tif" ; }
           else { filepath += ".tif" ; }

           controller.file_saving.extension = ".tif" ;

         }
         #endif

         #ifdef SUPPORT_SUN_RASTER // Always supported.
         if (description == "Format: *.ras, *.sr, (Sun Rasters).") {

           if (extension == ".") { filepath += "ras" ; }
           else { filepath += ".ras" ; }

           controller.file_saving.extension = ".ras" ;

         }
         #endif

         #ifdef SUPPORT_PORTABLE_IMAGE_FORMAT // Always supported.
         if (description == "Format: *.pbm, *.pgm, *.ppm (Portable Image Format).") {

           if (extension == ".") { filepath += "ppm" ; }
           else { filepath += ".ppm" ; }

           controller.file_saving.extension = ".ppm" ;

         }
         #endif

         #ifdef SUPPORT_WEBP
         if (description == "Format: *.webp") {

           if (extension == ".") { filepath += "webp" ; }
           else { filepath += ".webp" ; }

           controller.file_saving.extension = ".webp" ;

         }
         #endif

         //controller.file_saving.extension += extension ;


       }



      controller.file_saving.filepath = filepath ;

      controller.file_saving.width    = controller.source_image_size.first  ;
      controller.file_saving.height   = controller.source_image_size.second ;

      #ifdef DEBUG
      fprintf(stderr,"File save as: %s\n", filepath.c_str() ) ;
      #endif
   
      controller.file_saving.apply  = true ;

      break ;

    }

    case Gtk::RESPONSE_CANCEL :

      controller.file_saving.apply  = false ;

      break ;

  }

  dialog.close() ;

  return ;
}

void GUI::saving_file(Controller &controller) {

  select_save_as_file(controller) ;


  if (controller.file_saving.apply) {

    save_as_image_file_settings(controller) ;

  }

  return ;

}

void GUI::display_kernel(cv::Mat kernel, int precison) {

  #define DIALOG_SPACE       4

  Gtk::Dialog dialog("Kernel preview", true) ;

  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "transform-move.png") ;
  dialog.set_type_hint(Gdk::WINDOW_TYPE_HINT_NORMAL) ;
  dialog.set_resizable(false) ;


  dialog.set_border_width(DIALOG_SPACE) ;

  Glib::PropertyProxy<bool> destroy_with_parent_bool = dialog.property_destroy_with_parent() ;

  destroy_with_parent_bool.set_value(true) ;

  int left, top = 0 ;

  Gtk::Frame frame("Kernel") ;

  Gtk::Box hbox(Gtk::ORIENTATION_HORIZONTAL) ;

  Gtk::Label padding_left("") ;
  Gtk::Label padding_right("") ;

  Gtk::Grid grid ;

  grid.set_border_width(12) ;

  for (int c=0 ; c < kernel.rows ; c++) {

    left=0 ;

    for (int cc=0 ; cc < kernel.cols ; cc++) {

      Gtk::Frame *cur_frame = Gtk::manage(new Gtk::Frame())  ;

      Gtk::Label *label = Gtk::manage(new Gtk::Label()) ;

      string value ;

      switch (kernel.depth()) {

        case 0 : {
          value="<b>"+ to_string(kernel.at<uint8_t>(c,cc)) + "</b>" ;
          break ;
        }
        case 1 : {
         value="<b>"+ to_string(kernel.at<int8_t>(c,cc)) + "</b>" ;
         break ;
        }
        case 2 : {
          value="<b>"+ to_string(kernel.at<uint16_t>(c,cc)) + "</b>" ;
          break ;
        }
        case 3 : {
          value="<b>"+ to_string(kernel.at<int16_t>(c,cc)) + "</b>" ;
          break ;
        }
        case 4 : {
          value="<b>"+ to_string(kernel.at<int32_t>(c,cc)) + "</b>" ;
          break ;
        }
        case 5 : {
          char buf[16] ;
          sprintf(buf,"%+.*f", precison, kernel.at<float>(c,cc)) ;
          value =  "<b>" + string(buf) + "</b>" ;
          break ;
        }
        case 6 : {
          char buf[16] ;
          sprintf(buf,"%+.*lf", precison, kernel.at<float>(c,cc)) ;
          value =  "<b>" + string(buf) + "</b>" ;
          break  ;
        }
        #ifdef DEBUG
        default :
          fprintf(stderr,"Kernel matrix type not found\n") ;
          return ;
        #endif
       
      }


      label->set_markup(value) ;

      cur_frame->add(*label) ;

      grid.attach(*cur_frame, left, top, 1, 1) ;

      left++ ;

      Gtk::Label *padding = Gtk::manage(new Gtk::Label(" ") ) ;

      grid.attach(*padding, left, top, 1, 1) ;

      left++ ;

    }

    top++ ;

  }

  Gtk::Box *main_content_box = dialog.get_content_area() ;

  frame.add(grid) ;

  hbox.pack_start(padding_left,  true,  true,  0) ;
  hbox.pack_start(frame,         false, false, 0) ;
  hbox.pack_start(padding_right, true,  true,  0) ;


  main_content_box->pack_start(hbox, false, false, 0) ;

  Gtk::ButtonBox *buttonbox = dialog.get_action_area() ;

  buttonbox->set_layout(Gtk::BUTTONBOX_EDGE) ;
  buttonbox->set_homogeneous(true) ;

  Gtk::Button button_ok("OK") ;

  Gtk::Image  image_ok(PATH_TO_BUTTON_ICONS "dialog-ok-apply.png")  ;

  button_ok.set_image(image_ok) ;
  button_ok.set_always_show_image(true) ;

  dialog.add_action_widget(button_ok,     Gtk::RESPONSE_OK) ;

  main_content_box->show_all() ;

  int ret = dialog.run() ;

  dialog.close() ;

  return ;

}

#endif

