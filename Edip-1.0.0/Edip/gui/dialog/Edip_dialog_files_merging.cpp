#ifndef EDIP_DIALOG_FILES_MERGING_HH
#define EDIP_DIALOG_FILES_MERGING_HH

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


void GUI::files_merging_set_output_file(string &filepath, Gtk::Entry &entry) {

  Gtk::FileChooserDialog dialog("Choose file to save as.", Gtk::FILE_CHOOSER_ACTION_SAVE);

  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "folder-image.png") ;

  dialog.set_do_overwrite_confirmation(true) ;

  dialog.set_select_multiple(false) ;

  dialog.set_show_hidden(false) ;

  dialog.set_current_folder(Glib::get_home_dir()) ;

  dialog.add_button(Gtk::Stock::CANCEL,    Gtk::RESPONSE_CANCEL) ;
  dialog.add_button(Gtk::Stock::OK,        Gtk::RESPONSE_OK)     ;

  dialog.set_create_folders(false) ;

  dialog.set_show_hidden(false) ;

  dialog.set_use_preview_label(true) ;

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

  int result = dialog.run();


  switch (result) {

    case Gtk::RESPONSE_OK : {

      filepath = dialog.get_filename() ;

      string extension = guess_extension(filepath) ;

      if ( (  extension == ".png")  ||
         (  extension == ".jpg"   || extension == ".jpe"    || extension ==  ".jpeg" ) ||
         (  extension == ".bmp"   || extension == ".dib"  ) ||
         (  extension == ".tif"   || extension == ".tiff" ) ||
         (  extension == ".ras"   || extension == ".sr"   ) ||
         (  extension == ".pbm"   || extension == ".pgm"    || extension == ".ppm" )   ||
         (  extension == ".webp"  )) {

         ; // Extension OK.
      }
      else {

        Glib::RefPtr<Gtk::FileFilter> actual_filter = dialog.get_filter() ;

        auto description = actual_filter->get_name() ;

        #ifdef SUPPORT_PNG
        if (description == "Format: *.png (Portable Network Graphics).") {

         if (extension == ".") { filepath += "png" ; }
         else { filepath += ".png" ; }



       }
       #endif

       #ifdef SUPPORT_BMP // Always supported.
       if (description == "Format: *.bmp, *.dib (Bitmap Image File).") {

         if (extension == ".") { filepath += "bmp" ; }
         else { filepath += ".bmp" ; }



       }
       #endif

       #ifdef SUPPORT_JPG
       if (description == "Format: *.jpeg, *.jpg, *.jpe (Join Photgraphic Experts Group).") {

         if (extension == ".") { filepath += "jpg" ; }
         else { filepath += ".jpg" ; }

       }
       #endif

       #ifdef SUPPORT_TIF
       else if (description == "Format: *.tiff, *.tif, (Tag(ged) Image File Format).") {

         if (extension == ".") { filepath += "tif" ; }
         else { filepath += ".tif" ; }

       }
       #endif

       #ifdef SUPPORT_SUN_RASTER // Always supported.
       if (description == "Format: *.ras, *.sr, (Sun Rasters).") {

         if (extension == ".") { filepath += "ras" ; }
         else { filepath += ".ras" ; }

       }
       #endif

       #ifdef SUPPORT_PORTABLE_IMAGE_FORMAT // Always supported.
       if (description == "Format: *.pbm, *.pgm, *.ppm (Portable Image Format).") {

         if (extension == ".") { filepath += "ppm" ; }
         else { filepath += ".ppm" ; }

       }
       #endif

       #ifdef SUPPORT_WEBP
       if (description == "Format: *.webp") {

         if (extension == ".") { filepath += "webp" ; }
         else { filepath += ".webp" ; }

       }
       #endif


      }

      entry.set_text(Glib::path_get_basename(filepath)) ;


    }

    break ;

 }

 dialog.close() ;

 return ;

}


void GUI::files_merging_preview_output(cv::Mat frame) {

  Gtk::Dialog dialog("Preview", true) ;

  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "view-presentation.png") ;
  dialog.set_type_hint(Gdk::WINDOW_TYPE_HINT_NORMAL) ;
  dialog.set_resizable(false) ;
  dialog.set_modal(true) ;
  dialog.set_position(Gtk::WIN_POS_CENTER) ;

  Glib::PropertyProxy<bool> destroy_with_parent_bool = dialog.property_destroy_with_parent() ;
  destroy_with_parent_bool.set_value(true) ;





  if (frame.cols > 800 && frame.rows > 600) {

    Resizer resizer ;

    auto new_size = resizer.resizer(frame, 800, 600, true) ;

    cv::Mat tmp ;
    cv::resize(frame, tmp, cv::Size(new_size.first, new_size.second), 1.0, 1.0) ;
    frame = tmp ;
  }

  convert_image_to_gui_output_format(frame, frame) ;

  Gtk::Image image ;

  IplImage iplimg = _IplImage(frame) ;

  image.set(Gdk::Pixbuf::create_from_data((const guint8 *) iplimg.imageData,
                                           Gdk::COLORSPACE_RGB,
                                           (frame.channels() == 4),
                                           iplimg.depth,
                                           iplimg.width,
                                           iplimg.height,
                                           iplimg.widthStep)) ;

  image.show() ;

  Gtk::Box *main_content_box = dialog.get_content_area() ;

  main_content_box->pack_start(image,    false, false, 0) ;

  main_content_box->show_all() ;

  dialog.run() ;

  dialog.close() ;

  return ;

}

void GUI::files_merging_blend_images() {

  /** Interpolate 2 images file with the constant alpha to generate an output image:
    *
    *     Result = Image1 * alpha - (1-alpha) * Image2
    *
    * The images are converted to the same size (to the littler image) was is required for blend operation.
    ******************************************************************************************************/

  string input_filepath_1 ;
  string input_filepath_2 ;

  string output_filepath  ;



  Gtk::Dialog dialog("Files merging blend.", false) ;

  // Configure dialog:
  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "view-presentation.png") ;
  dialog.set_type_hint(Gdk::WINDOW_TYPE_HINT_NORMAL) ;
  dialog.set_resizable(false) ;
  dialog.set_border_width(DIALOG_BORDER_WIDTH) ;
  dialog.set_modal(false) ;
  dialog.set_position(Gtk::WIN_POS_CENTER) ;

  Glib::PropertyProxy<bool> destroy_with_parent_bool = dialog.property_destroy_with_parent() ;
  destroy_with_parent_bool.set_value(false) ;


  Gtk::Frame          files_merging_blend_explanation_frame("") ;

  Gtk::Box            files_merging_blend_explanation_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_blend_explanation_frame_widget_image(PATH_TO_MENU_ICONS "applications-education-university.png") ;
  Gtk::Label          files_merging_blend_explanation_frame_widget_label(" Explanations ") ;

  Gtk::Label          files_merging_blend_explanation_label ;

  files_merging_blend_explanation_label.set_markup("\n\t\t<big>Interpolate 2 images file with the constant alpha to generate an output image:\t\n"
                                                   "\t\t\t\t<big>Result = Image1 * alpha - (1-alpha) * Image2</big>\t\t\t\n"
                                                   "\t<small>The images are converted to the same size (to the littler image) was is required for blend operation.</small>\t</big>\n") ;


  files_merging_blend_explanation_label.set_margin_left(FRAME_INNER_SPACE)   ;
  files_merging_blend_explanation_label.set_margin_right(FRAME_INNER_SPACE)  ;
  files_merging_blend_explanation_label.set_margin_top(FRAME_INNER_SPACE)    ;
  files_merging_blend_explanation_label.set_margin_bottom(FRAME_INNER_SPACE) ;

  files_merging_blend_explanation_frame_widget_hbox.pack_start(files_merging_blend_explanation_frame_widget_image, false, false, 0) ;
  files_merging_blend_explanation_frame_widget_hbox.pack_start(files_merging_blend_explanation_frame_widget_label, false, false, 0) ;

  files_merging_blend_explanation_frame.set_label_widget(files_merging_blend_explanation_frame_widget_hbox) ;

  files_merging_blend_explanation_label.set_margin_bottom(6) ;

  files_merging_blend_explanation_frame.add(files_merging_blend_explanation_label) ;





  Gtk::Frame          files_merging_blend_input_frame("") ;

  Gtk::Box            files_merging_blend_input_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_blend_input_frame_widget_image(PATH_TO_MENU_ICONS "document-save.png") ;
  Gtk::Label          files_merging_blend_input_frame_widget_label(" Input ") ;

  files_merging_blend_input_frame_widget_hbox.pack_start(files_merging_blend_input_frame_widget_image, false, false, 0) ;
  files_merging_blend_input_frame_widget_hbox.pack_start(files_merging_blend_input_frame_widget_label, false, false, 0) ;

  files_merging_blend_input_frame.set_label_widget(files_merging_blend_input_frame_widget_hbox) ;


  Gtk::FileChooserButton files_merging_blend_input_file_1("Choose input file 1 to merge.", Gtk::FILE_CHOOSER_ACTION_OPEN) ;

  Gtk::Label             files_merging_blend_input_alpha_label("Alpha") ;

  Gtk::SpinButton        files_merging_blend_input_alpha_spinbutton(Gtk::ORIENTATION_HORIZONTAL) ;

  Gtk::FileChooserButton files_merging_blend_input_file_2("Choose input file 2 to merge.", Gtk::FILE_CHOOSER_ACTION_OPEN) ;


  Gtk::Box               files_merging_blend_input_hbox(Gtk::ORIENTATION_HORIZONTAL) ;

  files_merging_blend_input_hbox.set_border_width(BOX_BORDER) ;
  files_merging_blend_input_hbox.set_spacing(BOX_SPACING) ;

  files_merging_blend_input_file_1.set_title("Select input file 1") ;
  files_merging_blend_input_file_1.set_width_chars(16) ;

  config_select_file_filters(files_merging_blend_input_file_1) ;

  files_merging_blend_input_file_2.set_title("Select input file 2") ;
  files_merging_blend_input_file_2.set_width_chars(16) ;

  config_select_file_filters(files_merging_blend_input_file_2) ;


  files_merging_blend_input_alpha_spinbutton.set_digits(2) ;
  files_merging_blend_input_alpha_spinbutton.set_range(0.01, 1.0)      ;
  files_merging_blend_input_alpha_spinbutton.set_value(0.5)      ;
  files_merging_blend_input_alpha_spinbutton.set_increments(0.01, 0.1)    ;
  files_merging_blend_input_alpha_spinbutton.set_snap_to_ticks(true)    ;
  files_merging_blend_input_alpha_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  files_merging_blend_input_alpha_spinbutton.set_adjustment( Gtk::Adjustment::create(0.5, 0.01, 1.0, 0.01, 0.1) ) ;

  Gtk::Separator files_merging_blend_input_separator_1(Gtk::ORIENTATION_VERTICAL) ;
  Gtk::Separator files_merging_blend_input_separator_2(Gtk::ORIENTATION_VERTICAL) ;
  Gtk::Separator files_merging_blend_input_separator_3(Gtk::ORIENTATION_VERTICAL) ;
  Gtk::Separator files_merging_blend_input_separator_4(Gtk::ORIENTATION_VERTICAL) ;

  files_merging_blend_input_hbox.pack_start(files_merging_blend_input_separator_1,      false, false, 0) ;
  files_merging_blend_input_hbox.pack_start(files_merging_blend_input_file_1,           true,  true,  0) ;
  files_merging_blend_input_hbox.pack_start(files_merging_blend_input_separator_2,      false, false, 0) ;
  files_merging_blend_input_hbox.pack_start(files_merging_blend_input_alpha_label,      false, false, 0) ;
  files_merging_blend_input_hbox.pack_start(files_merging_blend_input_alpha_spinbutton, false, false, 0) ;
  files_merging_blend_input_hbox.pack_start(files_merging_blend_input_separator_3,      false, false, 0) ;
  files_merging_blend_input_hbox.pack_start(files_merging_blend_input_file_2,           true,  true,  0) ;
  files_merging_blend_input_hbox.pack_start(files_merging_blend_input_separator_4,      false, false, 0) ;

  files_merging_blend_input_frame.add(files_merging_blend_input_hbox) ;


  Gtk::Frame          files_merging_blend_output_frame("") ;

  Gtk::Box            files_merging_blend_output_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_blend_output_frame_widget_image(PATH_TO_MENU_ICONS "document-save.png") ;
  Gtk::Label          files_merging_blend_output_frame_widget_label(" Output ") ;

  files_merging_blend_output_frame_widget_hbox.pack_start(files_merging_blend_output_frame_widget_image, false, false, 0) ;
  files_merging_blend_output_frame_widget_hbox.pack_start(files_merging_blend_output_frame_widget_label, false, false, 0) ;

  files_merging_blend_output_frame.set_label_widget(files_merging_blend_output_frame_widget_hbox) ;


  Gtk::Frame          files_merging_blend_save_as_frame("") ;

  Gtk::Box            files_merging_blend_save_as_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;
  Gtk::Box            files_merging_blend_save_as_hbox2(Gtk::ORIENTATION_VERTICAL,   0) ;

  Gtk::Box            files_merging_blend_save_as_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_blend_save_as_frame_widget_image(PATH_TO_MENU_ICONS "document-save-as.png") ;
  Gtk::Label          files_merging_blend_save_as_frame_widget_label(" Save as ") ;

  files_merging_blend_save_as_frame_widget_hbox.pack_start(files_merging_blend_save_as_frame_widget_image, false, false, 0) ;
  files_merging_blend_save_as_frame_widget_hbox.pack_start(files_merging_blend_save_as_frame_widget_label, false, false, 0) ;

  files_merging_blend_save_as_frame.set_label_widget(files_merging_blend_save_as_frame_widget_hbox) ;



  Gtk::Box            files_merging_blend_save_as_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;


  Gtk::Button         files_merging_blend_save_as_label_button(" Save output file as ") ;

  Gtk::Image          files_merging_blend_save_as_image(PATH_TO_BUTTON_ICONS "document-save-as.png") ;

  files_merging_blend_save_as_label_button.set_image(files_merging_blend_save_as_image) ;
  files_merging_blend_save_as_label_button.set_always_show_image(true) ;

  Gtk::Entry          files_merging_blend_save_as_entry ;

  files_merging_blend_save_as_entry.set_width_chars(40) ;
  files_merging_blend_save_as_entry.set_alignment(Gtk::ALIGN_CENTER) ;

  files_merging_blend_save_as_vbox.set_border_width(BOX_BORDER) ;
  files_merging_blend_save_as_vbox.set_spacing(BOX_SPACING) ;

  files_merging_blend_save_as_vbox.pack_start(files_merging_blend_save_as_label_button, false, false, 0) ;
  files_merging_blend_save_as_vbox.pack_start(files_merging_blend_save_as_entry,        false, false, 0) ;

  files_merging_blend_save_as_hbox2.set_border_width(BOX_BORDER) ;
  files_merging_blend_save_as_hbox2.set_spacing(BOX_SPACING) ;

  files_merging_blend_save_as_hbox2.pack_start(files_merging_blend_save_as_vbox,       false, false, 0) ;



  files_merging_blend_save_as_frame.add(files_merging_blend_save_as_hbox2) ;
  files_merging_blend_save_as_frame.set_border_width(FRAME_BORDER_WIDTH) ;




  Gtk::Frame          files_merging_blend_size_frame("") ;

  Gtk::Box            files_merging_blend_size_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_blend_size_frame_widget_image(PATH_TO_MENU_ICONS "view-fullscreen.png") ;
  Gtk::Label          files_merging_blend_size_frame_widget_label(" Size ") ;

  files_merging_blend_size_frame_widget_hbox.pack_start(files_merging_blend_size_frame_widget_image, false, false, 0) ;
  files_merging_blend_size_frame_widget_hbox.pack_start(files_merging_blend_size_frame_widget_label, false, false, 0) ;

  files_merging_blend_size_frame.set_label_widget(files_merging_blend_size_frame_widget_hbox) ;

  Gtk::Box            files_merging_blend_size_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Box            files_merging_blend_size_width_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;
  Gtk::Box            files_merging_blend_size_height_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;

  Gtk::Button         files_merging_blend_size_width_button(" Width ")   ;
  Gtk::Button         files_merging_blend_size_height_button(" Height ") ;

  Gtk::Image          files_merging_blend_size_width_image(PATH_TO_BUTTON_ICONS "zoom-original.png") ;
  Gtk::Image          files_merging_blend_size_height_image(PATH_TO_BUTTON_ICONS "zoom-original.png") ;

  files_merging_blend_size_width_button.set_image(files_merging_blend_size_width_image)   ;
  files_merging_blend_size_height_button.set_image(files_merging_blend_size_height_image) ;

  files_merging_blend_size_width_button.set_always_show_image(true)   ;
  files_merging_blend_size_height_button.set_always_show_image(true)  ;

  Gtk::SpinButton    files_merging_blend_size_width_spinbutton   ;
  Gtk::SpinButton    files_merging_blend_size_height_spinbutton  ;

  files_merging_blend_size_width_spinbutton.set_digits(0) ;
  files_merging_blend_size_width_spinbutton.set_range(0.0, 65536.0)      ;
  files_merging_blend_size_width_spinbutton.set_value(0.0)      ;
  files_merging_blend_size_width_spinbutton.set_increments(1.0, 1.0)    ;
  files_merging_blend_size_width_spinbutton.set_snap_to_ticks(true)    ;
  files_merging_blend_size_width_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  files_merging_blend_size_width_spinbutton.set_adjustment( Gtk::Adjustment::create(0.0, 0.0, 65536.0, 1.0, 10.0) ) ;

  files_merging_blend_size_height_spinbutton.set_digits(0) ;
  files_merging_blend_size_height_spinbutton.set_range(0.0, 65536.0)      ;
  files_merging_blend_size_height_spinbutton.set_value(0.0)      ;
  files_merging_blend_size_height_spinbutton.set_increments(1.0, 10.0)    ;
  files_merging_blend_size_height_spinbutton.set_snap_to_ticks(true)    ;
  files_merging_blend_size_height_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  files_merging_blend_size_height_spinbutton.set_adjustment( Gtk::Adjustment::create(0.0, 0.0, 65536.0, 1.0, 10.0) ) ;

  files_merging_blend_size_width_vbox.set_border_width(BOX_BORDER) ;
  files_merging_blend_size_height_vbox.set_border_width(BOX_BORDER) ;

  files_merging_blend_size_width_vbox.set_spacing(BOX_SPACING) ;
  files_merging_blend_size_height_vbox.set_spacing(BOX_SPACING) ;

  files_merging_blend_size_width_vbox.pack_start(files_merging_blend_size_width_button,     false, false, 0) ;
  files_merging_blend_size_width_vbox.pack_start(files_merging_blend_size_width_spinbutton, false, false, 0) ;

  files_merging_blend_size_height_vbox.pack_start(files_merging_blend_size_height_button,     false, false, 0) ;
  files_merging_blend_size_height_vbox.pack_start(files_merging_blend_size_height_spinbutton, false, false, 0) ;

  files_merging_blend_size_hbox.set_border_width(BOX_BORDER) ;
  files_merging_blend_size_hbox.set_spacing(BOX_SPACING) ;

  files_merging_blend_size_hbox.pack_start(files_merging_blend_size_width_vbox,  true, true, 0) ;
  files_merging_blend_size_hbox.pack_start(files_merging_blend_size_height_vbox, true, true, 0) ;

  files_merging_blend_size_frame.add(files_merging_blend_size_hbox) ;

  files_merging_blend_size_frame.set_border_width(FRAME_BORDER_WIDTH) ;

  files_merging_blend_save_as_hbox.pack_start(files_merging_blend_save_as_frame, true,  true, 0) ;
  files_merging_blend_save_as_hbox.pack_start(files_merging_blend_size_frame,    true,  true, 0) ;


  files_merging_blend_output_frame.add(files_merging_blend_save_as_hbox) ;






  // Add action buttons
  Gtk::ButtonBox *buttonbox = dialog.get_action_area() ;

  buttonbox->set_layout(Gtk::BUTTONBOX_EDGE) ;
  buttonbox->set_homogeneous(true) ;

  Gtk::Button button_ok(" Save file ") ;
  Gtk::Image  image_ok(PATH_TO_BUTTON_ICONS "dialog-ok-apply.png")  ;

  button_ok.set_image(image_ok) ;
  button_ok.set_always_show_image(true) ;

  Gtk::Button button_preview(" Preview result ") ;
  Gtk::Image  image_preview(PATH_TO_BUTTON_ICONS "view-presentation.png")  ;

  button_preview.set_image(image_preview) ;
  button_preview.set_always_show_image(true) ;

  Gtk::Button button_cancel(" Close window ")  ;
  Gtk::Image  image_cancel(PATH_TO_BUTTON_ICONS "window-close.png") ;

  button_cancel.set_image(image_cancel) ;
  button_cancel.set_always_show_image(true) ;

  dialog.add_action_widget(button_cancel,  Gtk::RESPONSE_CLOSE) ;
  dialog.add_action_widget(button_preview, Gtk::RESPONSE_YES)   ;
  dialog.add_action_widget(button_ok,      Gtk::RESPONSE_APPLY) ;




  Gtk::Box *files_merging_blend_main_content_box = dialog.get_content_area() ;

  files_merging_blend_main_content_box->set_spacing(BOX_SPACING) ;

  files_merging_blend_main_content_box->pack_start(files_merging_blend_explanation_frame,    false, false, 0) ;
  files_merging_blend_main_content_box->pack_start(files_merging_blend_input_frame,          false, false, 0) ;
  files_merging_blend_main_content_box->pack_start(files_merging_blend_output_frame,         false, false, 0) ;


  files_merging_blend_input_file_1.signal_file_set().connect([&files_merging_blend_input_file_1, &input_filepath_1, &input_filepath_2, &files_merging_blend_size_width_spinbutton, &files_merging_blend_size_height_spinbutton]() {

    input_filepath_1 = files_merging_blend_input_file_1.get_filename() ;

    if (! input_filepath_2.empty()) {

      cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
      cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;


      resize_to_same_size(frame1, frame2) ;

      files_merging_blend_size_width_spinbutton.set_value(static_cast<double>(frame1.cols))  ;
      files_merging_blend_size_height_spinbutton.set_value(static_cast<double>(frame1.rows)) ;

   }

  } ) ;

  files_merging_blend_input_file_2.signal_file_set().connect([&files_merging_blend_input_file_2, &input_filepath_1, &input_filepath_2, &files_merging_blend_size_width_spinbutton, &files_merging_blend_size_height_spinbutton]() {

    input_filepath_2 = files_merging_blend_input_file_2.get_filename() ;

    if (! input_filepath_1.empty()) {

      cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
      cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;


     resize_to_same_size(frame1, frame2) ;

     files_merging_blend_size_width_spinbutton.set_value(static_cast<double>(frame1.cols))  ;
     files_merging_blend_size_height_spinbutton.set_value(static_cast<double>(frame1.rows)) ;

   }

  } ) ;


  button_preview.signal_clicked().connect([&dialog, this, &input_filepath_1, &input_filepath_2, &files_merging_blend_size_width_spinbutton, &files_merging_blend_size_height_spinbutton, &files_merging_blend_input_alpha_spinbutton] () {

    if (input_filepath_1.empty() || input_filepath_2.empty()) { return ; }

    if ( ! files_merging_blend_size_width_spinbutton.get_value_as_int() || ! files_merging_blend_size_height_spinbutton.get_value_as_int() ) {

      cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
      cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;

      resize_to_same_size(frame1, frame2, cv::Size(0,0)) ;

      files_merging_blend_size_width_spinbutton.set_value(static_cast<double>(frame1.cols))  ;
      files_merging_blend_size_height_spinbutton.set_value(static_cast<double>(frame1.rows)) ;

    }

    cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
    cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;

    cv::Mat result ;

    const float alpha    = static_cast<float>(files_merging_blend_input_alpha_spinbutton.get_value()) ;

    cv::Size size(files_merging_blend_size_width_spinbutton.get_value_as_int(), files_merging_blend_size_height_spinbutton.get_value_as_int()) ;

    if (blend_images(frame1, frame2, result, alpha, size) != 0) { return ; }


    files_merging_preview_output(result) ;


  } ) ;



  files_merging_blend_save_as_label_button.signal_clicked().connect(sigc::bind<string&, Gtk::Entry&>(sigc::mem_fun(*this, &GUI::files_merging_set_output_file), output_filepath, files_merging_blend_save_as_entry) ) ;

  files_merging_blend_main_content_box->show_all() ;


  reshow_window :

  int ret = dialog.run() ;

  switch (ret) {

    case Gtk::RESPONSE_YES :

      goto reshow_window ;
 
      break ;
 
    case Gtk::RESPONSE_APPLY : {

      if ( input_filepath_1.empty() || input_filepath_2.empty() ) {
 
        const string title = "Input files failed" ;
 
        const string message = "You must set the 2 input files to merge !" ;
 
        message_dialog(title, message) ;
 
        goto reshow_window ;
      }

      if ( output_filepath.empty() ) {
 
        const string title = "Ouput file fail" ;
 
        const string message = "You must set an ouput file to save the merge result !" ;
 
        message_dialog(title, message) ;
 
        goto reshow_window ;
      }

      cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
      cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;

      cv::Mat result ;

      const float alpha    = static_cast<float>(files_merging_blend_input_alpha_spinbutton.get_value()) ;

      cv::Size size(files_merging_blend_size_width_spinbutton.get_value_as_int(), files_merging_blend_size_height_spinbutton.get_value_as_int()) ;

      if (blend_images(frame1, frame2, result, alpha, size) != 0) {
 
        const string title = "Files merging error" ;
 
        const string message = "An error occurs by file merging !" ;
 
        message_dialog(title, message) ;
 
        break ;

      }


      if (! imwrite(output_filepath, result) ) {
   
          unlink(output_filepath.c_str()) ;
   
          const string title = "File saving error" ;

          string msg   = "Error saving file: " ;

          msg += Glib::path_get_basename(output_filepath) ;

          message_dialog(title, msg) ;

          break ;

      }

      const string title = "File merging success" ;

      string msg   = "File\n\n" ;

      msg += Glib::path_get_basename(input_filepath_1) ;

      msg += " and file " ;

      msg += Glib::path_get_basename(input_filepath_2) ;

      msg += "\n\nmerge as file: " ;

      msg += Glib::path_get_basename(output_filepath) ;

      message_dialog(title, msg) ;
   

    }

  }

  dialog.close() ;

  return ;

}

void GUI::files_merging_screen_images() {

  /** Superimpose two inverted images on the top of each other:
    *
    *   Result = MAX - ((MAX-Image1)  * (MAX-Images2) / MAX)
    *
    * The images are converted to the same size (to the littler image) was is required for screen operation.
    *******************************************************************************************************/

  string input_filepath_1 ;
  string input_filepath_2 ;

  string output_filepath  ;



  Gtk::Dialog dialog("Files merging screen.", false) ;

  // Configure dialog:
  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "view-presentation.png") ;
  dialog.set_type_hint(Gdk::WINDOW_TYPE_HINT_NORMAL) ;
  dialog.set_resizable(false) ;
  dialog.set_border_width(DIALOG_BORDER_WIDTH) ;
  dialog.set_modal(false) ;
  dialog.set_position(Gtk::WIN_POS_CENTER) ;

  Glib::PropertyProxy<bool> destroy_with_parent_bool = dialog.property_destroy_with_parent() ;
  destroy_with_parent_bool.set_value(false) ;


  Gtk::Frame          files_merging_screen_explanation_frame("") ;

  Gtk::Box            files_merging_screen_explanation_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_screen_explanation_frame_widget_image(PATH_TO_MENU_ICONS "applications-education-university.png") ;
  Gtk::Label          files_merging_screen_explanation_frame_widget_label(" Explanations ") ;

  Gtk::Label          files_merging_screen_explanation_label ;

  files_merging_screen_explanation_label.set_markup("\n\t\t\t\t<big>Superimpose two inverted images on the top of each other:\n\t<big>"
                                                    "\t\tResult = MAX - ((MAX-Image1)  * (MAX-Images2) / MAX)</big>\t\n<small>"
                                                    "\tThe images are converted to the same size (to the littler image) was is required for screen operation.</small></big>\t\n") ;


  files_merging_screen_explanation_label.set_margin_left(FRAME_INNER_SPACE)   ;
  files_merging_screen_explanation_label.set_margin_right(FRAME_INNER_SPACE)  ;
  files_merging_screen_explanation_label.set_margin_top(FRAME_INNER_SPACE)    ;
  files_merging_screen_explanation_label.set_margin_bottom(FRAME_INNER_SPACE) ;

  files_merging_screen_explanation_frame_widget_hbox.pack_start(files_merging_screen_explanation_frame_widget_image, false, false, 0) ;
  files_merging_screen_explanation_frame_widget_hbox.pack_start(files_merging_screen_explanation_frame_widget_label, false, false, 0) ;

  files_merging_screen_explanation_frame.set_label_widget(files_merging_screen_explanation_frame_widget_hbox) ;

  files_merging_screen_explanation_label.set_margin_bottom(6) ;

  files_merging_screen_explanation_frame.add(files_merging_screen_explanation_label) ;





  Gtk::Frame          files_merging_screen_input_frame("") ;

  Gtk::Box            files_merging_screen_input_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_screen_input_frame_widget_image(PATH_TO_MENU_ICONS "document-save.png") ;
  Gtk::Label          files_merging_screen_input_frame_widget_label(" Input ") ;

  files_merging_screen_input_frame_widget_hbox.pack_start(files_merging_screen_input_frame_widget_image, false, false, 0) ;
  files_merging_screen_input_frame_widget_hbox.pack_start(files_merging_screen_input_frame_widget_label, false, false, 0) ;

  files_merging_screen_input_frame.set_label_widget(files_merging_screen_input_frame_widget_hbox) ;


  Gtk::FileChooserButton files_merging_screen_input_file_1("Choose input file 1 to merge.", Gtk::FILE_CHOOSER_ACTION_OPEN) ;

  Gtk::FileChooserButton files_merging_screen_input_file_2("Choose input file 2 to merge.", Gtk::FILE_CHOOSER_ACTION_OPEN) ;


  Gtk::Box               files_merging_screen_input_hbox(Gtk::ORIENTATION_HORIZONTAL) ;

  files_merging_screen_input_hbox.set_border_width(BOX_BORDER) ;
  files_merging_screen_input_hbox.set_spacing(BOX_SPACING) ;

  files_merging_screen_input_file_1.set_title("Select input file 1") ;
  files_merging_screen_input_file_1.set_width_chars(20) ;

  config_select_file_filters(files_merging_screen_input_file_1) ;

  files_merging_screen_input_file_2.set_title("Select input file 2") ;
  files_merging_screen_input_file_2.set_width_chars(20) ;

  config_select_file_filters(files_merging_screen_input_file_2) ;


  Gtk::Separator files_merging_screen_input_separator_1(Gtk::ORIENTATION_VERTICAL) ;
  Gtk::Separator files_merging_screen_input_separator_2(Gtk::ORIENTATION_VERTICAL) ;
  Gtk::Separator files_merging_screen_input_separator_3(Gtk::ORIENTATION_VERTICAL) ;

  files_merging_screen_input_hbox.pack_start(files_merging_screen_input_separator_1,      false, false, 0) ;
  files_merging_screen_input_hbox.pack_start(files_merging_screen_input_file_1,           true,  true,  0) ;
  files_merging_screen_input_hbox.pack_start(files_merging_screen_input_separator_2,      false, false, 0) ;
  files_merging_screen_input_hbox.pack_start(files_merging_screen_input_file_2,           true,  true,  0) ;
  files_merging_screen_input_hbox.pack_start(files_merging_screen_input_separator_3,      false, false, 0) ;

  files_merging_screen_input_frame.add(files_merging_screen_input_hbox) ;


  Gtk::Frame          files_merging_screen_output_frame("") ;

  Gtk::Box            files_merging_screen_output_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_screen_output_frame_widget_image(PATH_TO_MENU_ICONS "document-save.png") ;
  Gtk::Label          files_merging_screen_output_frame_widget_label(" Output ") ;

  files_merging_screen_output_frame_widget_hbox.pack_start(files_merging_screen_output_frame_widget_image, false, false, 0) ;
  files_merging_screen_output_frame_widget_hbox.pack_start(files_merging_screen_output_frame_widget_label, false, false, 0) ;

  files_merging_screen_output_frame.set_label_widget(files_merging_screen_output_frame_widget_hbox) ;


  Gtk::Frame          files_merging_screen_save_as_frame("") ;

  Gtk::Box            files_merging_screen_save_as_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;
  Gtk::Box            files_merging_screen_save_as_hbox2(Gtk::ORIENTATION_VERTICAL,   0) ;

  Gtk::Box            files_merging_screen_save_as_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_screen_save_as_frame_widget_image(PATH_TO_MENU_ICONS "document-save-as.png") ;
  Gtk::Label          files_merging_screen_save_as_frame_widget_label(" Save as ") ;

  files_merging_screen_save_as_frame_widget_hbox.pack_start(files_merging_screen_save_as_frame_widget_image, false, false, 0) ;
  files_merging_screen_save_as_frame_widget_hbox.pack_start(files_merging_screen_save_as_frame_widget_label, false, false, 0) ;

  files_merging_screen_save_as_frame.set_label_widget(files_merging_screen_save_as_frame_widget_hbox) ;



  Gtk::Box            files_merging_screen_save_as_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;


  Gtk::Button         files_merging_screen_save_as_label_button(" Save output file as ") ;

  Gtk::Image          files_merging_screen_save_as_image(PATH_TO_BUTTON_ICONS "document-save-as.png") ;

  files_merging_screen_save_as_label_button.set_image(files_merging_screen_save_as_image) ;
  files_merging_screen_save_as_label_button.set_always_show_image(true) ;

  Gtk::Entry          files_merging_screen_save_as_entry ;

  files_merging_screen_save_as_entry.set_width_chars(40) ;
  files_merging_screen_save_as_entry.set_alignment(Gtk::ALIGN_CENTER) ;

  files_merging_screen_save_as_vbox.set_border_width(BOX_BORDER) ;
  files_merging_screen_save_as_vbox.set_spacing(BOX_SPACING) ;

  files_merging_screen_save_as_vbox.pack_start(files_merging_screen_save_as_label_button, false, false, 0) ;
  files_merging_screen_save_as_vbox.pack_start(files_merging_screen_save_as_entry,        false, false, 0) ;

  files_merging_screen_save_as_hbox2.set_border_width(BOX_BORDER) ;
  files_merging_screen_save_as_hbox2.set_spacing(BOX_SPACING) ;

  files_merging_screen_save_as_hbox2.pack_start(files_merging_screen_save_as_vbox,       false, false, 0) ;



  files_merging_screen_save_as_frame.add(files_merging_screen_save_as_hbox2) ;
  files_merging_screen_save_as_frame.set_border_width(FRAME_BORDER_WIDTH) ;




  Gtk::Frame          files_merging_screen_size_frame("") ;

  Gtk::Box            files_merging_screen_size_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_screen_size_frame_widget_image(PATH_TO_MENU_ICONS "view-fullscreen.png") ;
  Gtk::Label          files_merging_screen_size_frame_widget_label(" Size ") ;

  files_merging_screen_size_frame_widget_hbox.pack_start(files_merging_screen_size_frame_widget_image, false, false, 0) ;
  files_merging_screen_size_frame_widget_hbox.pack_start(files_merging_screen_size_frame_widget_label, false, false, 0) ;

  files_merging_screen_size_frame.set_label_widget(files_merging_screen_size_frame_widget_hbox) ;

  Gtk::Box            files_merging_screen_size_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Box            files_merging_screen_size_width_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;
  Gtk::Box            files_merging_screen_size_height_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;

  Gtk::Button         files_merging_screen_size_width_button(" Width ")   ;
  Gtk::Button         files_merging_screen_size_height_button(" Height ") ;

  Gtk::Image          files_merging_screen_size_width_image(PATH_TO_BUTTON_ICONS "zoom-original.png") ;
  Gtk::Image          files_merging_screen_size_height_image(PATH_TO_BUTTON_ICONS "zoom-original.png") ;

  files_merging_screen_size_width_button.set_image(files_merging_screen_size_width_image)   ;
  files_merging_screen_size_height_button.set_image(files_merging_screen_size_height_image) ;

  files_merging_screen_size_width_button.set_always_show_image(true)   ;
  files_merging_screen_size_height_button.set_always_show_image(true)  ;

  Gtk::SpinButton    files_merging_screen_size_width_spinbutton   ;
  Gtk::SpinButton    files_merging_screen_size_height_spinbutton  ;

  files_merging_screen_size_width_spinbutton.set_digits(0) ;
  files_merging_screen_size_width_spinbutton.set_range(0.0, 65536.0)      ;
  files_merging_screen_size_width_spinbutton.set_value(0.0)      ;
  files_merging_screen_size_width_spinbutton.set_increments(1.0, 1.0)    ;
  files_merging_screen_size_width_spinbutton.set_snap_to_ticks(true)    ;
  files_merging_screen_size_width_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  files_merging_screen_size_width_spinbutton.set_adjustment( Gtk::Adjustment::create(0.0, 0.0, 65536.0, 1.0, 10.0) ) ;

  files_merging_screen_size_height_spinbutton.set_digits(0) ;
  files_merging_screen_size_height_spinbutton.set_range(0.0, 65536.0)      ;
  files_merging_screen_size_height_spinbutton.set_value(0.0)      ;
  files_merging_screen_size_height_spinbutton.set_increments(1.0, 10.0)    ;
  files_merging_screen_size_height_spinbutton.set_snap_to_ticks(true)    ;
  files_merging_screen_size_height_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  files_merging_screen_size_height_spinbutton.set_adjustment( Gtk::Adjustment::create(0.0, 0.0, 65536.0, 1.0, 10.0) ) ;

  files_merging_screen_size_width_vbox.set_border_width(BOX_BORDER) ;
  files_merging_screen_size_height_vbox.set_border_width(BOX_BORDER) ;

  files_merging_screen_size_width_vbox.set_spacing(BOX_SPACING) ;
  files_merging_screen_size_height_vbox.set_spacing(BOX_SPACING) ;

  files_merging_screen_size_width_vbox.pack_start(files_merging_screen_size_width_button,     false, false, 0) ;
  files_merging_screen_size_width_vbox.pack_start(files_merging_screen_size_width_spinbutton, false, false, 0) ;

  files_merging_screen_size_height_vbox.pack_start(files_merging_screen_size_height_button,     false, false, 0) ;
  files_merging_screen_size_height_vbox.pack_start(files_merging_screen_size_height_spinbutton, false, false, 0) ;

  files_merging_screen_size_hbox.set_border_width(BOX_BORDER) ;
  files_merging_screen_size_hbox.set_spacing(BOX_SPACING) ;

  files_merging_screen_size_hbox.pack_start(files_merging_screen_size_width_vbox,  true, true, 0) ;
  files_merging_screen_size_hbox.pack_start(files_merging_screen_size_height_vbox, true, true, 0) ;

  files_merging_screen_size_frame.add(files_merging_screen_size_hbox) ;

  files_merging_screen_size_frame.set_border_width(FRAME_BORDER_WIDTH) ;

  files_merging_screen_save_as_hbox.pack_start(files_merging_screen_save_as_frame, true,  true, 0) ;
  files_merging_screen_save_as_hbox.pack_start(files_merging_screen_size_frame,    true,  true, 0) ;


  files_merging_screen_output_frame.add(files_merging_screen_save_as_hbox) ;






  // Add action buttons
  Gtk::ButtonBox *buttonbox = dialog.get_action_area() ;

  buttonbox->set_layout(Gtk::BUTTONBOX_EDGE) ;
  buttonbox->set_homogeneous(true) ;

  Gtk::Button button_ok(" Save file ") ;
  Gtk::Image  image_ok(PATH_TO_BUTTON_ICONS "dialog-ok-apply.png")  ;

  button_ok.set_image(image_ok) ;
  button_ok.set_always_show_image(true) ;

  Gtk::Button button_preview(" Preview result ") ;
  Gtk::Image  image_preview(PATH_TO_BUTTON_ICONS "view-presentation.png")  ;

  button_preview.set_image(image_preview) ;
  button_preview.set_always_show_image(true) ;

  Gtk::Button button_cancel(" Close window ")  ;
  Gtk::Image  image_cancel(PATH_TO_BUTTON_ICONS "window-close.png") ;

  button_cancel.set_image(image_cancel) ;
  button_cancel.set_always_show_image(true) ;

  dialog.add_action_widget(button_cancel,  Gtk::RESPONSE_CLOSE) ;
  dialog.add_action_widget(button_preview, Gtk::RESPONSE_YES)   ;
  dialog.add_action_widget(button_ok,      Gtk::RESPONSE_APPLY) ;




  Gtk::Box *files_merging_screen_main_content_box = dialog.get_content_area() ;

  files_merging_screen_main_content_box->set_spacing(BOX_SPACING) ;

  files_merging_screen_main_content_box->pack_start(files_merging_screen_explanation_frame,    false, false, 0) ;
  files_merging_screen_main_content_box->pack_start(files_merging_screen_input_frame,          false, false, 0) ;
  files_merging_screen_main_content_box->pack_start(files_merging_screen_output_frame,         false, false, 0) ;


  files_merging_screen_input_file_1.signal_file_set().connect([&files_merging_screen_input_file_1, &input_filepath_1, &input_filepath_2, &files_merging_screen_size_width_spinbutton, &files_merging_screen_size_height_spinbutton]() {

    input_filepath_1 = files_merging_screen_input_file_1.get_filename() ;

    if (! input_filepath_2.empty()) {

      cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
      cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;


      resize_to_same_size(frame1, frame2) ;

      files_merging_screen_size_width_spinbutton.set_value(static_cast<double>(frame1.cols))  ;
      files_merging_screen_size_height_spinbutton.set_value(static_cast<double>(frame1.rows)) ;

   }

  } ) ;

  files_merging_screen_input_file_2.signal_file_set().connect([&files_merging_screen_input_file_2, &input_filepath_1, &input_filepath_2, &files_merging_screen_size_width_spinbutton, &files_merging_screen_size_height_spinbutton]() {

    input_filepath_2 = files_merging_screen_input_file_2.get_filename() ;

    if (! input_filepath_1.empty()) {

      cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
      cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;


      resize_to_same_size(frame1, frame2) ;

      files_merging_screen_size_width_spinbutton.set_value(static_cast<double>(frame1.cols))  ;
      files_merging_screen_size_height_spinbutton.set_value(static_cast<double>(frame1.rows)) ;

   }

  } ) ;


  button_preview.signal_clicked().connect([&dialog, this, &input_filepath_1, &input_filepath_2, &files_merging_screen_size_width_spinbutton, &files_merging_screen_size_height_spinbutton] () {

    if (input_filepath_1.empty() || input_filepath_2.empty()) { return ; }

    if ( ! files_merging_screen_size_width_spinbutton.get_value_as_int() || ! files_merging_screen_size_height_spinbutton.get_value_as_int() ) {

      cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
      cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;

      resize_to_same_size(frame1, frame2, cv::Size(0,0)) ;

      files_merging_screen_size_width_spinbutton.set_value(static_cast<double>(frame1.cols))  ;
      files_merging_screen_size_height_spinbutton.set_value(static_cast<double>(frame1.rows)) ;

    }

    cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
    cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;

    cv::Mat result ;

    cv::Size size(files_merging_screen_size_width_spinbutton.get_value_as_int(), files_merging_screen_size_height_spinbutton.get_value_as_int()) ;

    if (screen_images(frame1, frame2, result, size) != 0) { return ; }


    files_merging_preview_output(result) ;


  } ) ;



  files_merging_screen_save_as_label_button.signal_clicked().connect(sigc::bind<string&, Gtk::Entry&>(sigc::mem_fun(*this, &GUI::files_merging_set_output_file), output_filepath, files_merging_screen_save_as_entry) ) ;

  files_merging_screen_main_content_box->show_all() ;


  reshow_window :

  int ret = dialog.run() ;

  switch (ret) {

    case Gtk::RESPONSE_YES :

      goto reshow_window ;
 
      break ;
 
    case Gtk::RESPONSE_APPLY : {

      if ( input_filepath_1.empty() || input_filepath_2.empty() ) {
 
        const string title = "Input files failed" ;
 
        const string message = "You must set the 2 input files to merge !" ;
 
        message_dialog(title, message) ;
 
        goto reshow_window ;
      }

      if ( output_filepath.empty() ) {
 
        const string title = "Ouput file fail" ;
 
        const string message = "You must set an ouput file to save the merge result !" ;
 
        message_dialog(title, message) ;
 
        goto reshow_window ;
      }

      cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
      cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;

      cv::Mat result ;

      cv::Size size(files_merging_screen_size_width_spinbutton.get_value_as_int(), files_merging_screen_size_height_spinbutton.get_value_as_int()) ;

      if (screen_images(frame1, frame2, result, size) != 0) {
 
        const string title = "Files merging error" ;
 
        const string message = "An error occurs by file merging !" ;
 
        message_dialog(title, message) ;
 
        break ;

      }


      if (! imwrite(output_filepath, result) ) {
   
          unlink(output_filepath.c_str()) ;
   
          const string title = "File saving error" ;

          string msg   = "Error saving file: " ;

          msg += Glib::path_get_basename(output_filepath) ;

          message_dialog(title, msg) ;

          break ;

      }

      const string title = "File merging success" ;

      string msg   = "File " ;

      msg += Glib::path_get_basename(input_filepath_1) ;

      msg += " and file " ;

      msg += Glib::path_get_basename(input_filepath_2) ;

      msg += "\n\nmerge as file: " ;

      msg += Glib::path_get_basename(output_filepath) ;

      message_dialog(title, msg) ;
   

    }

  }

  dialog.close() ;

  return ;

}

void GUI::files_merging_darker_images() {

  /** Interpolate 2 images file and produce an output image with the darkest pixels values:
    *
    *   Result = min( Image1, Image2 )
    *
    * The images are converted to the same size (to the littler image) was is required for darker operation.
    *******************************************************************************************************/

  string input_filepath_1 ;
  string input_filepath_2 ;

  string output_filepath  ;



  Gtk::Dialog dialog("Files merging darker.", false) ;

  // Configure dialog:
  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "view-presentation.png") ;
  dialog.set_type_hint(Gdk::WINDOW_TYPE_HINT_NORMAL) ;
  dialog.set_resizable(false) ;
  dialog.set_border_width(DIALOG_BORDER_WIDTH) ;
  dialog.set_modal(false) ;
  dialog.set_position(Gtk::WIN_POS_CENTER) ;

  Glib::PropertyProxy<bool> destroy_with_parent_bool = dialog.property_destroy_with_parent() ;
  destroy_with_parent_bool.set_value(false) ;


  Gtk::Frame          files_merging_darker_explanation_frame("") ;

  Gtk::Box            files_merging_darker_explanation_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_darker_explanation_frame_widget_image(PATH_TO_MENU_ICONS "applications-education-university.png") ;
  Gtk::Label          files_merging_darker_explanation_frame_widget_label(" Explanations ") ;

  Gtk::Label          files_merging_darker_explanation_label ;

  files_merging_darker_explanation_label.set_markup("\n\t<big>Interpolate 2 images file and produce an output image with the darkest pixels values:\t\n"
                                                    "\t\t\t\t\t\t\t<big>Result = min( Image1, Image2 ) </big>\t\n<small>"
                                                    "\tThe images are converted to the same size (to the littler image) was is required for darker operation.\t</small></big>\n") ;


  files_merging_darker_explanation_label.set_margin_left(FRAME_INNER_SPACE)   ;
  files_merging_darker_explanation_label.set_margin_right(FRAME_INNER_SPACE)  ;
  files_merging_darker_explanation_label.set_margin_top(FRAME_INNER_SPACE)    ;
  files_merging_darker_explanation_label.set_margin_bottom(FRAME_INNER_SPACE) ;

  files_merging_darker_explanation_frame_widget_hbox.pack_start(files_merging_darker_explanation_frame_widget_image, false, false, 0) ;
  files_merging_darker_explanation_frame_widget_hbox.pack_start(files_merging_darker_explanation_frame_widget_label, false, false, 0) ;

  files_merging_darker_explanation_frame.set_label_widget(files_merging_darker_explanation_frame_widget_hbox) ;

  files_merging_darker_explanation_label.set_margin_bottom(6) ;

  files_merging_darker_explanation_frame.add(files_merging_darker_explanation_label) ;





  Gtk::Frame          files_merging_darker_input_frame("") ;

  Gtk::Box            files_merging_darker_input_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_darker_input_frame_widget_image(PATH_TO_MENU_ICONS "document-save.png") ;
  Gtk::Label          files_merging_darker_input_frame_widget_label(" Input ") ;

  files_merging_darker_input_frame_widget_hbox.pack_start(files_merging_darker_input_frame_widget_image, false, false, 0) ;
  files_merging_darker_input_frame_widget_hbox.pack_start(files_merging_darker_input_frame_widget_label, false, false, 0) ;

  files_merging_darker_input_frame.set_label_widget(files_merging_darker_input_frame_widget_hbox) ;


  Gtk::FileChooserButton files_merging_darker_input_file_1("Choose input file 1 to merge.", Gtk::FILE_CHOOSER_ACTION_OPEN) ;

  Gtk::FileChooserButton files_merging_darker_input_file_2("Choose input file 2 to merge.", Gtk::FILE_CHOOSER_ACTION_OPEN) ;


  Gtk::Box               files_merging_darker_input_hbox(Gtk::ORIENTATION_HORIZONTAL) ;

  files_merging_darker_input_hbox.set_border_width(BOX_BORDER) ;
  files_merging_darker_input_hbox.set_spacing(BOX_SPACING) ;

  files_merging_darker_input_file_1.set_title("Select input file 1") ;
  files_merging_darker_input_file_1.set_width_chars(20) ;

  config_select_file_filters(files_merging_darker_input_file_1) ;

  files_merging_darker_input_file_2.set_title("Select input file 2") ;
  files_merging_darker_input_file_2.set_width_chars(20) ;

  config_select_file_filters(files_merging_darker_input_file_2) ;


  Gtk::Separator files_merging_darker_input_separator_1(Gtk::ORIENTATION_VERTICAL) ;
  Gtk::Separator files_merging_darker_input_separator_2(Gtk::ORIENTATION_VERTICAL) ;
  Gtk::Separator files_merging_darker_input_separator_3(Gtk::ORIENTATION_VERTICAL) ;

  files_merging_darker_input_hbox.pack_start(files_merging_darker_input_separator_1,      false, false, 0) ;
  files_merging_darker_input_hbox.pack_start(files_merging_darker_input_file_1,           true,  true,  0) ;
  files_merging_darker_input_hbox.pack_start(files_merging_darker_input_separator_2,      false, false, 0) ;
  files_merging_darker_input_hbox.pack_start(files_merging_darker_input_file_2,           true,  true,  0) ;
  files_merging_darker_input_hbox.pack_start(files_merging_darker_input_separator_3,      false, false, 0) ;

  files_merging_darker_input_frame.add(files_merging_darker_input_hbox) ;


  Gtk::Frame          files_merging_darker_output_frame("") ;

  Gtk::Box            files_merging_darker_output_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_darker_output_frame_widget_image(PATH_TO_MENU_ICONS "document-save.png") ;
  Gtk::Label          files_merging_darker_output_frame_widget_label(" Output ") ;

  files_merging_darker_output_frame_widget_hbox.pack_start(files_merging_darker_output_frame_widget_image, false, false, 0) ;
  files_merging_darker_output_frame_widget_hbox.pack_start(files_merging_darker_output_frame_widget_label, false, false, 0) ;

  files_merging_darker_output_frame.set_label_widget(files_merging_darker_output_frame_widget_hbox) ;


  Gtk::Frame          files_merging_darker_save_as_frame("") ;

  Gtk::Box            files_merging_darker_save_as_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;
  Gtk::Box            files_merging_darker_save_as_hbox2(Gtk::ORIENTATION_VERTICAL,   0) ;

  Gtk::Box            files_merging_darker_save_as_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_darker_save_as_frame_widget_image(PATH_TO_MENU_ICONS "document-save-as.png") ;
  Gtk::Label          files_merging_darker_save_as_frame_widget_label(" Save as ") ;

  files_merging_darker_save_as_frame_widget_hbox.pack_start(files_merging_darker_save_as_frame_widget_image, false, false, 0) ;
  files_merging_darker_save_as_frame_widget_hbox.pack_start(files_merging_darker_save_as_frame_widget_label, false, false, 0) ;

  files_merging_darker_save_as_frame.set_label_widget(files_merging_darker_save_as_frame_widget_hbox) ;



  Gtk::Box            files_merging_darker_save_as_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;


  Gtk::Button         files_merging_darker_save_as_label_button(" Save output file as ") ;

  Gtk::Image          files_merging_darker_save_as_image(PATH_TO_BUTTON_ICONS "document-save-as.png") ;

  files_merging_darker_save_as_label_button.set_image(files_merging_darker_save_as_image) ;
  files_merging_darker_save_as_label_button.set_always_show_image(true) ;

  Gtk::Entry          files_merging_darker_save_as_entry ;

  files_merging_darker_save_as_entry.set_width_chars(40) ;
  files_merging_darker_save_as_entry.set_alignment(Gtk::ALIGN_CENTER) ;

  files_merging_darker_save_as_vbox.set_border_width(BOX_BORDER) ;
  files_merging_darker_save_as_vbox.set_spacing(BOX_SPACING) ;

  files_merging_darker_save_as_vbox.pack_start(files_merging_darker_save_as_label_button, false, false, 0) ;
  files_merging_darker_save_as_vbox.pack_start(files_merging_darker_save_as_entry,        false, false, 0) ;

  files_merging_darker_save_as_hbox2.set_border_width(BOX_BORDER) ;
  files_merging_darker_save_as_hbox2.set_spacing(BOX_SPACING) ;

  files_merging_darker_save_as_hbox2.pack_start(files_merging_darker_save_as_vbox,       false, false, 0) ;



  files_merging_darker_save_as_frame.add(files_merging_darker_save_as_hbox2) ;
  files_merging_darker_save_as_frame.set_border_width(FRAME_BORDER_WIDTH) ;




  Gtk::Frame          files_merging_darker_size_frame("") ;

  Gtk::Box            files_merging_darker_size_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_darker_size_frame_widget_image(PATH_TO_MENU_ICONS "view-fullscreen.png") ;
  Gtk::Label          files_merging_darker_size_frame_widget_label(" Size ") ;

  files_merging_darker_size_frame_widget_hbox.pack_start(files_merging_darker_size_frame_widget_image, false, false, 0) ;
  files_merging_darker_size_frame_widget_hbox.pack_start(files_merging_darker_size_frame_widget_label, false, false, 0) ;

  files_merging_darker_size_frame.set_label_widget(files_merging_darker_size_frame_widget_hbox) ;

  Gtk::Box            files_merging_darker_size_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Box            files_merging_darker_size_width_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;
  Gtk::Box            files_merging_darker_size_height_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;

  Gtk::Button         files_merging_darker_size_width_button(" Width ")   ;
  Gtk::Button         files_merging_darker_size_height_button(" Height ") ;

  Gtk::Image          files_merging_darker_size_width_image(PATH_TO_BUTTON_ICONS "zoom-original.png") ;
  Gtk::Image          files_merging_darker_size_height_image(PATH_TO_BUTTON_ICONS "zoom-original.png") ;

  files_merging_darker_size_width_button.set_image(files_merging_darker_size_width_image)   ;
  files_merging_darker_size_height_button.set_image(files_merging_darker_size_height_image) ;

  files_merging_darker_size_width_button.set_always_show_image(true)   ;
  files_merging_darker_size_height_button.set_always_show_image(true)  ;

  Gtk::SpinButton    files_merging_darker_size_width_spinbutton   ;
  Gtk::SpinButton    files_merging_darker_size_height_spinbutton  ;

  files_merging_darker_size_width_spinbutton.set_digits(0) ;
  files_merging_darker_size_width_spinbutton.set_range(0.0, 65536.0)      ;
  files_merging_darker_size_width_spinbutton.set_value(0.0)      ;
  files_merging_darker_size_width_spinbutton.set_increments(1.0, 1.0)    ;
  files_merging_darker_size_width_spinbutton.set_snap_to_ticks(true)    ;
  files_merging_darker_size_width_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  files_merging_darker_size_width_spinbutton.set_adjustment( Gtk::Adjustment::create(0.0, 0.0, 65536.0, 1.0, 10.0) ) ;

  files_merging_darker_size_height_spinbutton.set_digits(0) ;
  files_merging_darker_size_height_spinbutton.set_range(0.0, 65536.0)      ;
  files_merging_darker_size_height_spinbutton.set_value(0.0)      ;
  files_merging_darker_size_height_spinbutton.set_increments(1.0, 10.0)    ;
  files_merging_darker_size_height_spinbutton.set_snap_to_ticks(true)    ;
  files_merging_darker_size_height_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  files_merging_darker_size_height_spinbutton.set_adjustment( Gtk::Adjustment::create(0.0, 0.0, 65536.0, 1.0, 10.0) ) ;

  files_merging_darker_size_width_vbox.set_border_width(BOX_BORDER) ;
  files_merging_darker_size_height_vbox.set_border_width(BOX_BORDER) ;

  files_merging_darker_size_width_vbox.set_spacing(BOX_SPACING) ;
  files_merging_darker_size_height_vbox.set_spacing(BOX_SPACING) ;

  files_merging_darker_size_width_vbox.pack_start(files_merging_darker_size_width_button,     false, false, 0) ;
  files_merging_darker_size_width_vbox.pack_start(files_merging_darker_size_width_spinbutton, false, false, 0) ;

  files_merging_darker_size_height_vbox.pack_start(files_merging_darker_size_height_button,     false, false, 0) ;
  files_merging_darker_size_height_vbox.pack_start(files_merging_darker_size_height_spinbutton, false, false, 0) ;

  files_merging_darker_size_hbox.set_border_width(BOX_BORDER) ;
  files_merging_darker_size_hbox.set_spacing(BOX_SPACING) ;

  files_merging_darker_size_hbox.pack_start(files_merging_darker_size_width_vbox,  true, true, 0) ;
  files_merging_darker_size_hbox.pack_start(files_merging_darker_size_height_vbox, true, true, 0) ;

  files_merging_darker_size_frame.add(files_merging_darker_size_hbox) ;

  files_merging_darker_size_frame.set_border_width(FRAME_BORDER_WIDTH) ;

  files_merging_darker_save_as_hbox.pack_start(files_merging_darker_save_as_frame, true,  true, 0) ;
  files_merging_darker_save_as_hbox.pack_start(files_merging_darker_size_frame,    true,  true, 0) ;


  files_merging_darker_output_frame.add(files_merging_darker_save_as_hbox) ;






  // Add action buttons
  Gtk::ButtonBox *buttonbox = dialog.get_action_area() ;

  buttonbox->set_layout(Gtk::BUTTONBOX_EDGE) ;
  buttonbox->set_homogeneous(true) ;

  Gtk::Button button_ok(" Save file ") ;
  Gtk::Image  image_ok(PATH_TO_BUTTON_ICONS "dialog-ok-apply.png")  ;

  button_ok.set_image(image_ok) ;
  button_ok.set_always_show_image(true) ;

  Gtk::Button button_preview(" Preview result ") ;
  Gtk::Image  image_preview(PATH_TO_BUTTON_ICONS "view-presentation.png")  ;

  button_preview.set_image(image_preview) ;
  button_preview.set_always_show_image(true) ;

  Gtk::Button button_cancel(" Close window ")  ;
  Gtk::Image  image_cancel(PATH_TO_BUTTON_ICONS "window-close.png") ;

  button_cancel.set_image(image_cancel) ;
  button_cancel.set_always_show_image(true) ;

  dialog.add_action_widget(button_cancel,  Gtk::RESPONSE_CLOSE) ;
  dialog.add_action_widget(button_preview, Gtk::RESPONSE_YES)   ;
  dialog.add_action_widget(button_ok,      Gtk::RESPONSE_APPLY) ;




  Gtk::Box *files_merging_darker_main_content_box = dialog.get_content_area() ;

  files_merging_darker_main_content_box->set_spacing(BOX_SPACING) ;

  files_merging_darker_main_content_box->pack_start(files_merging_darker_explanation_frame,    false, false, 0) ;
  files_merging_darker_main_content_box->pack_start(files_merging_darker_input_frame,          false, false, 0) ;
  files_merging_darker_main_content_box->pack_start(files_merging_darker_output_frame,         false, false, 0) ;


  files_merging_darker_input_file_1.signal_file_set().connect([&files_merging_darker_input_file_1, &input_filepath_1, &input_filepath_2, &files_merging_darker_size_width_spinbutton, &files_merging_darker_size_height_spinbutton]() {

    input_filepath_1 = files_merging_darker_input_file_1.get_filename() ;

    if (! input_filepath_2.empty()) {

      cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
      cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;


      resize_to_same_size(frame1, frame2) ;

      files_merging_darker_size_width_spinbutton.set_value(static_cast<double>(frame1.cols))  ;
      files_merging_darker_size_height_spinbutton.set_value(static_cast<double>(frame1.rows)) ;

   }

  } ) ;

  files_merging_darker_input_file_2.signal_file_set().connect([&files_merging_darker_input_file_2, &input_filepath_1, &input_filepath_2, &files_merging_darker_size_width_spinbutton, &files_merging_darker_size_height_spinbutton]() {

    input_filepath_2 = files_merging_darker_input_file_2.get_filename() ;

    if (! input_filepath_1.empty()) {

        cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
        cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;


        resize_to_same_size(frame1, frame2) ;

        files_merging_darker_size_width_spinbutton.set_value(static_cast<double>(frame1.cols))  ;
        files_merging_darker_size_height_spinbutton.set_value(static_cast<double>(frame1.rows)) ;

   }

  } ) ;


  button_preview.signal_clicked().connect([&dialog, this, &input_filepath_1, &input_filepath_2, &files_merging_darker_size_width_spinbutton, &files_merging_darker_size_height_spinbutton] () {

    if (input_filepath_1.empty() || input_filepath_2.empty()) { return ; }

    if ( ! files_merging_darker_size_width_spinbutton.get_value_as_int() || ! files_merging_darker_size_height_spinbutton.get_value_as_int() ) {

      cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
      cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;

      resize_to_same_size(frame1, frame2, cv::Size(0,0)) ;

      files_merging_darker_size_width_spinbutton.set_value(static_cast<double>(frame1.cols))  ;
      files_merging_darker_size_height_spinbutton.set_value(static_cast<double>(frame1.rows)) ;

    }

    cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
    cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;

    cv::Mat result ;

    cv::Size size(files_merging_darker_size_width_spinbutton.get_value_as_int(), files_merging_darker_size_height_spinbutton.get_value_as_int()) ;

    if (darker_images(frame1, frame2, result, size) != 0) { return ; }


    files_merging_preview_output(result) ;


  } ) ;



  files_merging_darker_save_as_label_button.signal_clicked().connect(sigc::bind<string&, Gtk::Entry&>(sigc::mem_fun(*this, &GUI::files_merging_set_output_file), output_filepath, files_merging_darker_save_as_entry) ) ;

  files_merging_darker_main_content_box->show_all() ;


  reshow_window :

  int ret = dialog.run() ;

  switch (ret) {

    case Gtk::RESPONSE_YES :

      goto reshow_window ;
 
      break ;
 
    case Gtk::RESPONSE_APPLY : {

      if ( input_filepath_1.empty() || input_filepath_2.empty() ) {
 
        const string title = "Input files failed" ;
 
        const string message = "You must set the 2 input files to merge !" ;
 
        message_dialog(title, message) ;
 
        goto reshow_window ;
      }

      if ( output_filepath.empty() ) {
 
        const string title = "Ouput file fail" ;
 
        const string message = "You must set an ouput file to save the merge result !" ;
 
        message_dialog(title, message) ;
 
        goto reshow_window ;
      }

      cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
      cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;

      cv::Mat result ;

      cv::Size size(files_merging_darker_size_width_spinbutton.get_value_as_int(), files_merging_darker_size_height_spinbutton.get_value_as_int()) ;

      if (darker_images(frame1, frame2, result, size) != 0) {
 
        const string title = "Files merging error" ;
 
        const string message = "An error occurs by file merging !" ;
 
        message_dialog(title, message) ;
 
        break ;

      }


      if (! imwrite(output_filepath, result) ) {
   
          unlink(output_filepath.c_str()) ;
   
          const string title = "File saving error" ;

          string msg   = "Error saving file: " ;

          msg += Glib::path_get_basename(output_filepath) ;

          message_dialog(title, msg) ;

          break ;

      }

      const string title = "File merging success" ;

      string msg   = "File " ;

      msg += Glib::path_get_basename(input_filepath_1) ;

      msg += " and file " ;

      msg += Glib::path_get_basename(input_filepath_2) ;

      msg += "\n\nmerge as file: " ;

      msg += Glib::path_get_basename(output_filepath) ;

      message_dialog(title, msg) ;
   

    }

  }

  dialog.close() ;

  return ;

}

void GUI::files_merging_lighter_images() {

  /** Interpolate 2 images file and produce an output image with the lightest pixels values:
    *
    *   Result = max( Image1, Image2 )
    *
    * The images are converted to the same size (to the littler image) was is required for lighter operation.
    ********************************************************************************************************/

  string input_filepath_1 ;
  string input_filepath_2 ;

  string output_filepath  ;



  Gtk::Dialog dialog("Files merging lighter.", false) ;

  // Configure dialog:
  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "view-presentation.png") ;
  dialog.set_type_hint(Gdk::WINDOW_TYPE_HINT_NORMAL) ;
  dialog.set_resizable(false) ;
  dialog.set_border_width(DIALOG_BORDER_WIDTH) ;
  dialog.set_modal(false) ;
  dialog.set_position(Gtk::WIN_POS_CENTER) ;

  Glib::PropertyProxy<bool> destroy_with_parent_bool = dialog.property_destroy_with_parent() ;
  destroy_with_parent_bool.set_value(false) ;


  Gtk::Frame          files_merging_lighter_explanation_frame("") ;

  Gtk::Box            files_merging_lighter_explanation_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_lighter_explanation_frame_widget_image(PATH_TO_MENU_ICONS "applications-education-university.png") ;
  Gtk::Label          files_merging_lighter_explanation_frame_widget_label(" Explanations ") ;

  Gtk::Label          files_merging_lighter_explanation_label ;

  files_merging_lighter_explanation_label.set_markup("\n\t<big>Interpolate 2 images file and produce an output image with the lightest pixels values:\t\n"
                                                     "\t\t\t\t\t\t\t<big>Result = max( Image1, Image2 )\t</big>\n"
                                                     "<small>\tThe images are converted to the same size (to the littler image) was is required for lighter operation.\t</small></big>\n") ;

  files_merging_lighter_explanation_label.set_margin_left(FRAME_INNER_SPACE)   ;
  files_merging_lighter_explanation_label.set_margin_right(FRAME_INNER_SPACE)  ;
  files_merging_lighter_explanation_label.set_margin_top(FRAME_INNER_SPACE)    ;
  files_merging_lighter_explanation_label.set_margin_bottom(FRAME_INNER_SPACE) ;

  files_merging_lighter_explanation_frame_widget_hbox.pack_start(files_merging_lighter_explanation_frame_widget_image, false, false, 0) ;
  files_merging_lighter_explanation_frame_widget_hbox.pack_start(files_merging_lighter_explanation_frame_widget_label, false, false, 0) ;

  files_merging_lighter_explanation_frame.set_label_widget(files_merging_lighter_explanation_frame_widget_hbox) ;

  files_merging_lighter_explanation_label.set_margin_bottom(6) ;

  files_merging_lighter_explanation_frame.add(files_merging_lighter_explanation_label) ;





  Gtk::Frame          files_merging_lighter_input_frame("") ;

  Gtk::Box            files_merging_lighter_input_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_lighter_input_frame_widget_image(PATH_TO_MENU_ICONS "document-save.png") ;
  Gtk::Label          files_merging_lighter_input_frame_widget_label(" Input ") ;

  files_merging_lighter_input_frame_widget_hbox.pack_start(files_merging_lighter_input_frame_widget_image, false, false, 0) ;
  files_merging_lighter_input_frame_widget_hbox.pack_start(files_merging_lighter_input_frame_widget_label, false, false, 0) ;

  files_merging_lighter_input_frame.set_label_widget(files_merging_lighter_input_frame_widget_hbox) ;


  Gtk::FileChooserButton files_merging_lighter_input_file_1("Choose input file 1 to merge.", Gtk::FILE_CHOOSER_ACTION_OPEN) ;

  Gtk::FileChooserButton files_merging_lighter_input_file_2("Choose input file 2 to merge.", Gtk::FILE_CHOOSER_ACTION_OPEN) ;


  Gtk::Box               files_merging_lighter_input_hbox(Gtk::ORIENTATION_HORIZONTAL) ;

  files_merging_lighter_input_hbox.set_border_width(BOX_BORDER) ;
  files_merging_lighter_input_hbox.set_spacing(BOX_SPACING) ;

  files_merging_lighter_input_file_1.set_title("Select input file 1") ;
  files_merging_lighter_input_file_1.set_width_chars(20) ;

  config_select_file_filters(files_merging_lighter_input_file_1) ;

  files_merging_lighter_input_file_2.set_title("Select input file 2") ;
  files_merging_lighter_input_file_2.set_width_chars(20) ;

  config_select_file_filters(files_merging_lighter_input_file_2) ;


  Gtk::Separator files_merging_lighter_input_separator_1(Gtk::ORIENTATION_VERTICAL) ;
  Gtk::Separator files_merging_lighter_input_separator_2(Gtk::ORIENTATION_VERTICAL) ;
  Gtk::Separator files_merging_lighter_input_separator_3(Gtk::ORIENTATION_VERTICAL) ;

  files_merging_lighter_input_hbox.pack_start(files_merging_lighter_input_separator_1,      false, false, 0) ;
  files_merging_lighter_input_hbox.pack_start(files_merging_lighter_input_file_1,           true,  true,  0) ;
  files_merging_lighter_input_hbox.pack_start(files_merging_lighter_input_separator_2,      false, false, 0) ;
  files_merging_lighter_input_hbox.pack_start(files_merging_lighter_input_file_2,           true,  true,  0) ;
  files_merging_lighter_input_hbox.pack_start(files_merging_lighter_input_separator_3,      false, false, 0) ;

  files_merging_lighter_input_frame.add(files_merging_lighter_input_hbox) ;


  Gtk::Frame          files_merging_lighter_output_frame("") ;

  Gtk::Box            files_merging_lighter_output_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_lighter_output_frame_widget_image(PATH_TO_MENU_ICONS "document-save.png") ;
  Gtk::Label          files_merging_lighter_output_frame_widget_label(" Output ") ;

  files_merging_lighter_output_frame_widget_hbox.pack_start(files_merging_lighter_output_frame_widget_image, false, false, 0) ;
  files_merging_lighter_output_frame_widget_hbox.pack_start(files_merging_lighter_output_frame_widget_label, false, false, 0) ;

  files_merging_lighter_output_frame.set_label_widget(files_merging_lighter_output_frame_widget_hbox) ;


  Gtk::Frame          files_merging_lighter_save_as_frame("") ;

  Gtk::Box            files_merging_lighter_save_as_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;
  Gtk::Box            files_merging_lighter_save_as_hbox2(Gtk::ORIENTATION_VERTICAL,   0) ;

  Gtk::Box            files_merging_lighter_save_as_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_lighter_save_as_frame_widget_image(PATH_TO_MENU_ICONS "document-save-as.png") ;
  Gtk::Label          files_merging_lighter_save_as_frame_widget_label(" Save as ") ;

  files_merging_lighter_save_as_frame_widget_hbox.pack_start(files_merging_lighter_save_as_frame_widget_image, false, false, 0) ;
  files_merging_lighter_save_as_frame_widget_hbox.pack_start(files_merging_lighter_save_as_frame_widget_label, false, false, 0) ;

  files_merging_lighter_save_as_frame.set_label_widget(files_merging_lighter_save_as_frame_widget_hbox) ;



  Gtk::Box            files_merging_lighter_save_as_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;


  Gtk::Button         files_merging_lighter_save_as_label_button(" Save output file as ") ;

  Gtk::Image          files_merging_lighter_save_as_image(PATH_TO_BUTTON_ICONS "document-save-as.png") ;

  files_merging_lighter_save_as_label_button.set_image(files_merging_lighter_save_as_image) ;
  files_merging_lighter_save_as_label_button.set_always_show_image(true) ;

  Gtk::Entry          files_merging_lighter_save_as_entry ;

  files_merging_lighter_save_as_entry.set_width_chars(40) ;
  files_merging_lighter_save_as_entry.set_alignment(Gtk::ALIGN_CENTER) ;

  files_merging_lighter_save_as_vbox.set_border_width(BOX_BORDER) ;
  files_merging_lighter_save_as_vbox.set_spacing(BOX_SPACING) ;

  files_merging_lighter_save_as_vbox.pack_start(files_merging_lighter_save_as_label_button, false, false, 0) ;
  files_merging_lighter_save_as_vbox.pack_start(files_merging_lighter_save_as_entry,        false, false, 0) ;

  files_merging_lighter_save_as_hbox2.set_border_width(BOX_BORDER) ;
  files_merging_lighter_save_as_hbox2.set_spacing(BOX_SPACING) ;

  files_merging_lighter_save_as_hbox2.pack_start(files_merging_lighter_save_as_vbox,       false, false, 0) ;



  files_merging_lighter_save_as_frame.add(files_merging_lighter_save_as_hbox2) ;
  files_merging_lighter_save_as_frame.set_border_width(FRAME_BORDER_WIDTH) ;




  Gtk::Frame          files_merging_lighter_size_frame("") ;

  Gtk::Box            files_merging_lighter_size_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_lighter_size_frame_widget_image(PATH_TO_MENU_ICONS "view-fullscreen.png") ;
  Gtk::Label          files_merging_lighter_size_frame_widget_label(" Size ") ;

  files_merging_lighter_size_frame_widget_hbox.pack_start(files_merging_lighter_size_frame_widget_image, false, false, 0) ;
  files_merging_lighter_size_frame_widget_hbox.pack_start(files_merging_lighter_size_frame_widget_label, false, false, 0) ;

  files_merging_lighter_size_frame.set_label_widget(files_merging_lighter_size_frame_widget_hbox) ;

  Gtk::Box            files_merging_lighter_size_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Box            files_merging_lighter_size_width_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;
  Gtk::Box            files_merging_lighter_size_height_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;

  Gtk::Button         files_merging_lighter_size_width_button(" Width ")   ;
  Gtk::Button         files_merging_lighter_size_height_button(" Height ") ;

  Gtk::Image          files_merging_lighter_size_width_image(PATH_TO_BUTTON_ICONS "zoom-original.png") ;
  Gtk::Image          files_merging_lighter_size_height_image(PATH_TO_BUTTON_ICONS "zoom-original.png") ;

  files_merging_lighter_size_width_button.set_image(files_merging_lighter_size_width_image)   ;
  files_merging_lighter_size_height_button.set_image(files_merging_lighter_size_height_image) ;

  files_merging_lighter_size_width_button.set_always_show_image(true)   ;
  files_merging_lighter_size_height_button.set_always_show_image(true)  ;

  Gtk::SpinButton    files_merging_lighter_size_width_spinbutton   ;
  Gtk::SpinButton    files_merging_lighter_size_height_spinbutton  ;

  files_merging_lighter_size_width_spinbutton.set_digits(0) ;
  files_merging_lighter_size_width_spinbutton.set_range(0.0, 65536.0)      ;
  files_merging_lighter_size_width_spinbutton.set_value(0.0)      ;
  files_merging_lighter_size_width_spinbutton.set_increments(1.0, 1.0)    ;
  files_merging_lighter_size_width_spinbutton.set_snap_to_ticks(true)    ;
  files_merging_lighter_size_width_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  files_merging_lighter_size_width_spinbutton.set_adjustment( Gtk::Adjustment::create(0.0, 0.0, 65536.0, 1.0, 10.0) ) ;

  files_merging_lighter_size_height_spinbutton.set_digits(0) ;
  files_merging_lighter_size_height_spinbutton.set_range(0.0, 65536.0)      ;
  files_merging_lighter_size_height_spinbutton.set_value(0.0)      ;
  files_merging_lighter_size_height_spinbutton.set_increments(1.0, 10.0)    ;
  files_merging_lighter_size_height_spinbutton.set_snap_to_ticks(true)    ;
  files_merging_lighter_size_height_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  files_merging_lighter_size_height_spinbutton.set_adjustment( Gtk::Adjustment::create(0.0, 0.0, 65536.0, 1.0, 10.0) ) ;

  files_merging_lighter_size_width_vbox.set_border_width(BOX_BORDER) ;
  files_merging_lighter_size_height_vbox.set_border_width(BOX_BORDER) ;

  files_merging_lighter_size_width_vbox.set_spacing(BOX_SPACING) ;
  files_merging_lighter_size_height_vbox.set_spacing(BOX_SPACING) ;

  files_merging_lighter_size_width_vbox.pack_start(files_merging_lighter_size_width_button,     false, false, 0) ;
  files_merging_lighter_size_width_vbox.pack_start(files_merging_lighter_size_width_spinbutton, false, false, 0) ;

  files_merging_lighter_size_height_vbox.pack_start(files_merging_lighter_size_height_button,     false, false, 0) ;
  files_merging_lighter_size_height_vbox.pack_start(files_merging_lighter_size_height_spinbutton, false, false, 0) ;

  files_merging_lighter_size_hbox.set_border_width(BOX_BORDER) ;
  files_merging_lighter_size_hbox.set_spacing(BOX_SPACING) ;

  files_merging_lighter_size_hbox.pack_start(files_merging_lighter_size_width_vbox,  true, true, 0) ;
  files_merging_lighter_size_hbox.pack_start(files_merging_lighter_size_height_vbox, true, true, 0) ;

  files_merging_lighter_size_frame.add(files_merging_lighter_size_hbox) ;

  files_merging_lighter_size_frame.set_border_width(FRAME_BORDER_WIDTH) ;

  files_merging_lighter_save_as_hbox.pack_start(files_merging_lighter_save_as_frame, true,  true, 0) ;
  files_merging_lighter_save_as_hbox.pack_start(files_merging_lighter_size_frame,    true,  true, 0) ;


  files_merging_lighter_output_frame.add(files_merging_lighter_save_as_hbox) ;






  // Add action buttons
  Gtk::ButtonBox *buttonbox = dialog.get_action_area() ;

  buttonbox->set_layout(Gtk::BUTTONBOX_EDGE) ;
  buttonbox->set_homogeneous(true) ;

  Gtk::Button button_ok(" Save file ") ;
  Gtk::Image  image_ok(PATH_TO_BUTTON_ICONS "dialog-ok-apply.png")  ;

  button_ok.set_image(image_ok) ;
  button_ok.set_always_show_image(true) ;

  Gtk::Button button_preview(" Preview result ") ;
  Gtk::Image  image_preview(PATH_TO_BUTTON_ICONS "view-presentation.png")  ;

  button_preview.set_image(image_preview) ;
  button_preview.set_always_show_image(true) ;

  Gtk::Button button_cancel(" Close window ")  ;
  Gtk::Image  image_cancel(PATH_TO_BUTTON_ICONS "window-close.png") ;

  button_cancel.set_image(image_cancel) ;
  button_cancel.set_always_show_image(true) ;

  dialog.add_action_widget(button_cancel,  Gtk::RESPONSE_CLOSE) ;
  dialog.add_action_widget(button_preview, Gtk::RESPONSE_YES)   ;
  dialog.add_action_widget(button_ok,      Gtk::RESPONSE_APPLY) ;




  Gtk::Box *files_merging_lighter_main_content_box = dialog.get_content_area() ;

  files_merging_lighter_main_content_box->set_spacing(BOX_SPACING) ;

  files_merging_lighter_main_content_box->pack_start(files_merging_lighter_explanation_frame,    false, false, 0) ;
  files_merging_lighter_main_content_box->pack_start(files_merging_lighter_input_frame,          false, false, 0) ;
  files_merging_lighter_main_content_box->pack_start(files_merging_lighter_output_frame,         false, false, 0) ;


  files_merging_lighter_input_file_1.signal_file_set().connect([&files_merging_lighter_input_file_1, &input_filepath_1, &input_filepath_2, &files_merging_lighter_size_width_spinbutton, &files_merging_lighter_size_height_spinbutton]() {

    input_filepath_1 = files_merging_lighter_input_file_1.get_filename() ;

    if (! input_filepath_2.empty()) {

      cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
      cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;

      resize_to_same_size(frame1, frame2) ;

      files_merging_lighter_size_width_spinbutton.set_value(static_cast<double>(frame1.cols))  ;
      files_merging_lighter_size_height_spinbutton.set_value(static_cast<double>(frame1.rows)) ;

   }

  } ) ;

  files_merging_lighter_input_file_2.signal_file_set().connect([&files_merging_lighter_input_file_2, &input_filepath_1, &input_filepath_2, &files_merging_lighter_size_width_spinbutton, &files_merging_lighter_size_height_spinbutton]() {

    input_filepath_2 = files_merging_lighter_input_file_2.get_filename() ;

    if (! input_filepath_1.empty()) {

      cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
      cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;

      resize_to_same_size(frame1, frame2) ;

      files_merging_lighter_size_width_spinbutton.set_value(static_cast<double>(frame1.cols))  ;
      files_merging_lighter_size_height_spinbutton.set_value(static_cast<double>(frame1.rows)) ;

   }

  } ) ;


  button_preview.signal_clicked().connect([&dialog, this, &input_filepath_1, &input_filepath_2, &files_merging_lighter_size_width_spinbutton, &files_merging_lighter_size_height_spinbutton] () {

    if (input_filepath_1.empty() || input_filepath_2.empty()) { return ; }

    if ( ! files_merging_lighter_size_width_spinbutton.get_value_as_int() || ! files_merging_lighter_size_height_spinbutton.get_value_as_int() ) {

      cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
      cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;

      resize_to_same_size(frame1, frame2, cv::Size(0,0)) ;

      files_merging_lighter_size_width_spinbutton.set_value(static_cast<double>(frame1.cols))  ;
      files_merging_lighter_size_height_spinbutton.set_value(static_cast<double>(frame1.rows)) ;

    }

    cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
    cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;

    cv::Mat result ;

    cv::Size size(files_merging_lighter_size_width_spinbutton.get_value_as_int(), files_merging_lighter_size_height_spinbutton.get_value_as_int()) ;

    if (lighter_images(frame1, frame2, result, size) != 0) { return ; }


    files_merging_preview_output(result) ;


  } ) ;



  files_merging_lighter_save_as_label_button.signal_clicked().connect(sigc::bind<string&, Gtk::Entry&>(sigc::mem_fun(*this, &GUI::files_merging_set_output_file), output_filepath, files_merging_lighter_save_as_entry) ) ;

  files_merging_lighter_main_content_box->show_all() ;


  reshow_window :

  int ret = dialog.run() ;

  switch (ret) {

    case Gtk::RESPONSE_YES :

      goto reshow_window ;
 
      break ;
 
    case Gtk::RESPONSE_APPLY : {

      if ( input_filepath_1.empty() || input_filepath_2.empty() ) {
 
        const string title = "Input files failed" ;
 
        const string message = "You must set the 2 input files to merge !" ;
 
        message_dialog(title, message) ;
 
        goto reshow_window ;
      }

      if ( output_filepath.empty() ) {
 
        const string title = "Ouput file fail" ;
 
        const string message = "You must set an ouput file to save the merge result !" ;
 
        message_dialog(title, message) ;
 
        goto reshow_window ;
      }

      cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
      cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;

      cv::Mat result ;

      cv::Size size(files_merging_lighter_size_width_spinbutton.get_value_as_int(), files_merging_lighter_size_height_spinbutton.get_value_as_int()) ;

      if (lighter_images(frame1, frame2, result, size) != 0) {
 
        const string title = "Files merging error" ;
 
        const string message = "An error occurs by file merging !" ;
 
        message_dialog(title, message) ;
 
        break ;

      }


      if (! imwrite(output_filepath, result) ) {
   
          unlink(output_filepath.c_str()) ;
   
          const string title = "File saving error" ;

          string msg   = "Error saving file: " ;

          msg += Glib::path_get_basename(output_filepath) ;

          message_dialog(title, msg) ;

          break ;

      }

      const string title = "File merging success" ;

      string msg   = "File " ;

      msg += Glib::path_get_basename(input_filepath_1) ;

      msg += " and file " ;

      msg += Glib::path_get_basename(input_filepath_2) ;

      msg += "\n\nmerge as file: " ;

      msg += Glib::path_get_basename(output_filepath) ;

      message_dialog(title, msg) ;
   

    }

  }

  dialog.close() ;

  return ;

}


void GUI::files_merging_add_images() {

  /** Add 2 images, dividing the result by scale and adding offset to generate an output image:
    *
    *   Result = (Image1 + Image2) / scale + offset
    *
    * The images are converted to the same size (to the littler image) was is required for add operation.
    ****************************************************************************************************/

  string input_filepath_1 ;
  string input_filepath_2 ;

  string output_filepath  ;



  Gtk::Dialog dialog("Files merging add.", false) ;

  // Configure dialog:
  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "view-presentation.png") ;
  dialog.set_type_hint(Gdk::WINDOW_TYPE_HINT_NORMAL) ;
  dialog.set_resizable(false) ;
  dialog.set_border_width(DIALOG_BORDER_WIDTH) ;
  dialog.set_modal(false) ;
  dialog.set_position(Gtk::WIN_POS_CENTER) ;

  Glib::PropertyProxy<bool> destroy_with_parent_bool = dialog.property_destroy_with_parent() ;
  destroy_with_parent_bool.set_value(false) ;


  Gtk::Frame          files_merging_add_explanation_frame("") ;

  Gtk::Box            files_merging_add_explanation_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_add_explanation_frame_widget_image(PATH_TO_MENU_ICONS "applications-education-university.png") ;
  Gtk::Label          files_merging_add_explanation_frame_widget_label(" Explanations ") ;

  Gtk::Label          files_merging_add_explanation_label ;

  files_merging_add_explanation_label.set_markup("\n\t<big>Add 2 images, dividing the result by scale and adding offset to generate an output image:\t\n"
                                                   "\t\t\t\t\t\t<big>Result = (Image1 + Image2) / scale + offset</big>\t\n"
                                                   "\t\t<small>The images are converted to the same size (to the littler image) was is required for add operation.\t</small></big>\n") ;


  files_merging_add_explanation_label.set_margin_left(FRAME_INNER_SPACE)   ;
  files_merging_add_explanation_label.set_margin_right(FRAME_INNER_SPACE)  ;
  files_merging_add_explanation_label.set_margin_top(FRAME_INNER_SPACE)    ;
  files_merging_add_explanation_label.set_margin_bottom(FRAME_INNER_SPACE) ;

  files_merging_add_explanation_frame_widget_hbox.pack_start(files_merging_add_explanation_frame_widget_image, false, false, 0) ;
  files_merging_add_explanation_frame_widget_hbox.pack_start(files_merging_add_explanation_frame_widget_label, false, false, 0) ;

  files_merging_add_explanation_frame.set_label_widget(files_merging_add_explanation_frame_widget_hbox) ;

  files_merging_add_explanation_label.set_margin_bottom(6) ;

  files_merging_add_explanation_frame.add(files_merging_add_explanation_label) ;





  Gtk::Frame          files_merging_add_input_frame("") ;

  Gtk::Box            files_merging_add_input_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_add_input_frame_widget_image(PATH_TO_MENU_ICONS "document-save.png") ;
  Gtk::Label          files_merging_add_input_frame_widget_label(" Input ") ;

  files_merging_add_input_frame_widget_hbox.pack_start(files_merging_add_input_frame_widget_image, false, false, 0) ;
  files_merging_add_input_frame_widget_hbox.pack_start(files_merging_add_input_frame_widget_label, false, false, 0) ;

  files_merging_add_input_frame.set_label_widget(files_merging_add_input_frame_widget_hbox) ;


  Gtk::FileChooserButton files_merging_add_input_file_1("Choose input file 1 to merge.", Gtk::FILE_CHOOSER_ACTION_OPEN) ;

  Gtk::Label             files_merging_add_input_scale_label("Scale") ;

  Gtk::SpinButton        files_merging_add_input_scale_spinbutton(Gtk::ORIENTATION_HORIZONTAL) ;

  Gtk::Label             files_merging_add_input_offset_label("Offset") ;

  Gtk::SpinButton        files_merging_add_input_offset_spinbutton(Gtk::ORIENTATION_HORIZONTAL) ;

  Gtk::FileChooserButton files_merging_add_input_file_2("Choose input file 2 to merge.", Gtk::FILE_CHOOSER_ACTION_OPEN) ;


  Gtk::Box               files_merging_add_input_hbox(Gtk::ORIENTATION_HORIZONTAL) ;

  files_merging_add_input_hbox.set_border_width(BOX_BORDER) ;
  files_merging_add_input_hbox.set_spacing(BOX_SPACING) ;

  files_merging_add_input_file_1.set_title("Select input file 1") ;
  files_merging_add_input_file_1.set_width_chars(16) ;

  config_select_file_filters(files_merging_add_input_file_1) ;

  files_merging_add_input_file_2.set_title("Select input file 2") ;
  files_merging_add_input_file_2.set_width_chars(16) ;

  config_select_file_filters(files_merging_add_input_file_2) ;


  files_merging_add_input_scale_spinbutton.set_digits(2) ;
  files_merging_add_input_scale_spinbutton.set_range(0.01, 8.0)      ;
  files_merging_add_input_scale_spinbutton.set_value(1.0)      ;
  files_merging_add_input_scale_spinbutton.set_increments(0.01, 0.1)    ;
  files_merging_add_input_scale_spinbutton.set_snap_to_ticks(true)    ;
  files_merging_add_input_scale_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  files_merging_add_input_scale_spinbutton.set_adjustment( Gtk::Adjustment::create(1.0, 0.01, 8.0, 0.01, 0.1) ) ;


  files_merging_add_input_offset_spinbutton.set_digits(0) ;
  files_merging_add_input_offset_spinbutton.set_range(0.0, 255.0)      ;
  files_merging_add_input_offset_spinbutton.set_value(0.0)      ;
  files_merging_add_input_offset_spinbutton.set_increments(1.0, 10.0)    ;
  files_merging_add_input_offset_spinbutton.set_snap_to_ticks(true)    ;
  files_merging_add_input_offset_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  files_merging_add_input_offset_spinbutton.set_adjustment( Gtk::Adjustment::create(0.0, 0.0, 255.0, 1.0, 10.0) ) ;


  Gtk::Separator files_merging_add_input_separator_1(Gtk::ORIENTATION_VERTICAL) ;
  Gtk::Separator files_merging_add_input_separator_2(Gtk::ORIENTATION_VERTICAL) ;
  Gtk::Separator files_merging_add_input_separator_3(Gtk::ORIENTATION_VERTICAL) ;
  Gtk::Separator files_merging_add_input_separator_4(Gtk::ORIENTATION_VERTICAL) ;

  files_merging_add_input_hbox.pack_start(files_merging_add_input_separator_1,       false, false, 0) ;
  files_merging_add_input_hbox.pack_start(files_merging_add_input_file_1,            true,  true,  0) ;
  files_merging_add_input_hbox.pack_start(files_merging_add_input_separator_2,       false, false, 0) ;
  files_merging_add_input_hbox.pack_start(files_merging_add_input_scale_label,       false, false, 0) ;
  files_merging_add_input_hbox.pack_start(files_merging_add_input_scale_spinbutton,  false, false, 0) ;
  files_merging_add_input_hbox.pack_start(files_merging_add_input_offset_label,      false, false, 0) ;
  files_merging_add_input_hbox.pack_start(files_merging_add_input_offset_spinbutton, false, false, 0) ;
  files_merging_add_input_hbox.pack_start(files_merging_add_input_separator_3,       false, false, 0) ;
  files_merging_add_input_hbox.pack_start(files_merging_add_input_file_2,            true,  true,  0) ;
  files_merging_add_input_hbox.pack_start(files_merging_add_input_separator_4,       false, false, 0) ;

  files_merging_add_input_frame.add(files_merging_add_input_hbox) ;


  Gtk::Frame          files_merging_add_output_frame("") ;

  Gtk::Box            files_merging_add_output_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_add_output_frame_widget_image(PATH_TO_MENU_ICONS "document-save.png") ;
  Gtk::Label          files_merging_add_output_frame_widget_label(" Output ") ;

  files_merging_add_output_frame_widget_hbox.pack_start(files_merging_add_output_frame_widget_image, false, false, 0) ;
  files_merging_add_output_frame_widget_hbox.pack_start(files_merging_add_output_frame_widget_label, false, false, 0) ;

  files_merging_add_output_frame.set_label_widget(files_merging_add_output_frame_widget_hbox) ;


  Gtk::Frame          files_merging_add_save_as_frame("") ;

  Gtk::Box            files_merging_add_save_as_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;
  Gtk::Box            files_merging_add_save_as_hbox2(Gtk::ORIENTATION_VERTICAL,   0) ;

  Gtk::Box            files_merging_add_save_as_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_add_save_as_frame_widget_image(PATH_TO_MENU_ICONS "document-save-as.png") ;
  Gtk::Label          files_merging_add_save_as_frame_widget_label(" Save as ") ;

  files_merging_add_save_as_frame_widget_hbox.pack_start(files_merging_add_save_as_frame_widget_image, false, false, 0) ;
  files_merging_add_save_as_frame_widget_hbox.pack_start(files_merging_add_save_as_frame_widget_label, false, false, 0) ;

  files_merging_add_save_as_frame.set_label_widget(files_merging_add_save_as_frame_widget_hbox) ;



  Gtk::Box            files_merging_add_save_as_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;


  Gtk::Button         files_merging_add_save_as_label_button(" Save output file as ") ;

  Gtk::Image          files_merging_add_save_as_image(PATH_TO_BUTTON_ICONS "document-save-as.png") ;

  files_merging_add_save_as_label_button.set_image(files_merging_add_save_as_image) ;
  files_merging_add_save_as_label_button.set_always_show_image(true) ;

  Gtk::Entry          files_merging_add_save_as_entry ;

  files_merging_add_save_as_entry.set_width_chars(40) ;
  files_merging_add_save_as_entry.set_alignment(Gtk::ALIGN_CENTER) ;

  files_merging_add_save_as_vbox.set_border_width(BOX_BORDER) ;
  files_merging_add_save_as_vbox.set_spacing(BOX_SPACING) ;

  files_merging_add_save_as_vbox.pack_start(files_merging_add_save_as_label_button, false, false, 0) ;
  files_merging_add_save_as_vbox.pack_start(files_merging_add_save_as_entry,        false, false, 0) ;

  files_merging_add_save_as_hbox2.set_border_width(BOX_BORDER) ;
  files_merging_add_save_as_hbox2.set_spacing(BOX_SPACING) ;

  files_merging_add_save_as_hbox2.pack_start(files_merging_add_save_as_vbox,       false, false, 0) ;



  files_merging_add_save_as_frame.add(files_merging_add_save_as_hbox2) ;
  files_merging_add_save_as_frame.set_border_width(FRAME_BORDER_WIDTH) ;




  Gtk::Frame          files_merging_add_size_frame("") ;

  Gtk::Box            files_merging_add_size_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_add_size_frame_widget_image(PATH_TO_MENU_ICONS "view-fullscreen.png") ;
  Gtk::Label          files_merging_add_size_frame_widget_label(" Size ") ;

  files_merging_add_size_frame_widget_hbox.pack_start(files_merging_add_size_frame_widget_image, false, false, 0) ;
  files_merging_add_size_frame_widget_hbox.pack_start(files_merging_add_size_frame_widget_label, false, false, 0) ;

  files_merging_add_size_frame.set_label_widget(files_merging_add_size_frame_widget_hbox) ;

  Gtk::Box            files_merging_add_size_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Box            files_merging_add_size_width_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;
  Gtk::Box            files_merging_add_size_height_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;

  Gtk::Button         files_merging_add_size_width_button(" Width ")   ;
  Gtk::Button         files_merging_add_size_height_button(" Height ") ;

  Gtk::Image          files_merging_add_size_width_image(PATH_TO_BUTTON_ICONS "zoom-original.png") ;
  Gtk::Image          files_merging_add_size_height_image(PATH_TO_BUTTON_ICONS "zoom-original.png") ;

  files_merging_add_size_width_button.set_image(files_merging_add_size_width_image)   ;
  files_merging_add_size_height_button.set_image(files_merging_add_size_height_image) ;

  files_merging_add_size_width_button.set_always_show_image(true)   ;
  files_merging_add_size_height_button.set_always_show_image(true)  ;

  Gtk::SpinButton    files_merging_add_size_width_spinbutton   ;
  Gtk::SpinButton    files_merging_add_size_height_spinbutton  ;

  files_merging_add_size_width_spinbutton.set_digits(0) ;
  files_merging_add_size_width_spinbutton.set_range(0.0, 65536.0)      ;
  files_merging_add_size_width_spinbutton.set_value(0.0)      ;
  files_merging_add_size_width_spinbutton.set_increments(1.0, 1.0)    ;
  files_merging_add_size_width_spinbutton.set_snap_to_ticks(true)    ;
  files_merging_add_size_width_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  files_merging_add_size_width_spinbutton.set_adjustment( Gtk::Adjustment::create(0.0, 0.0, 65536.0, 1.0, 10.0) ) ;

  files_merging_add_size_height_spinbutton.set_digits(0) ;
  files_merging_add_size_height_spinbutton.set_range(0.0, 65536.0)      ;
  files_merging_add_size_height_spinbutton.set_value(0.0)      ;
  files_merging_add_size_height_spinbutton.set_increments(1.0, 10.0)    ;
  files_merging_add_size_height_spinbutton.set_snap_to_ticks(true)    ;
  files_merging_add_size_height_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  files_merging_add_size_height_spinbutton.set_adjustment( Gtk::Adjustment::create(0.0, 0.0, 65536.0, 1.0, 10.0) ) ;

  files_merging_add_size_width_vbox.set_border_width(BOX_BORDER) ;
  files_merging_add_size_height_vbox.set_border_width(BOX_BORDER) ;

  files_merging_add_size_width_vbox.set_spacing(BOX_SPACING) ;
  files_merging_add_size_height_vbox.set_spacing(BOX_SPACING) ;

  files_merging_add_size_width_vbox.pack_start(files_merging_add_size_width_button,     false, false, 0) ;
  files_merging_add_size_width_vbox.pack_start(files_merging_add_size_width_spinbutton, false, false, 0) ;

  files_merging_add_size_height_vbox.pack_start(files_merging_add_size_height_button,     false, false, 0) ;
  files_merging_add_size_height_vbox.pack_start(files_merging_add_size_height_spinbutton, false, false, 0) ;

  files_merging_add_size_hbox.set_border_width(BOX_BORDER) ;
  files_merging_add_size_hbox.set_spacing(BOX_SPACING) ;

  files_merging_add_size_hbox.pack_start(files_merging_add_size_width_vbox,  true, true, 0) ;
  files_merging_add_size_hbox.pack_start(files_merging_add_size_height_vbox, true, true, 0) ;

  files_merging_add_size_frame.add(files_merging_add_size_hbox) ;

  files_merging_add_size_frame.set_border_width(FRAME_BORDER_WIDTH) ;

  files_merging_add_save_as_hbox.pack_start(files_merging_add_save_as_frame, true,  true, 0) ;
  files_merging_add_save_as_hbox.pack_start(files_merging_add_size_frame,    true,  true, 0) ;


  files_merging_add_output_frame.add(files_merging_add_save_as_hbox) ;






  // Add action buttons
  Gtk::ButtonBox *buttonbox = dialog.get_action_area() ;

  buttonbox->set_layout(Gtk::BUTTONBOX_EDGE) ;
  buttonbox->set_homogeneous(true) ;

  Gtk::Button button_ok(" Save file ") ;
  Gtk::Image  image_ok(PATH_TO_BUTTON_ICONS "dialog-ok-apply.png")  ;

  button_ok.set_image(image_ok) ;
  button_ok.set_always_show_image(true) ;

  Gtk::Button button_preview(" Preview result ") ;
  Gtk::Image  image_preview(PATH_TO_BUTTON_ICONS "view-presentation.png")  ;

  button_preview.set_image(image_preview) ;
  button_preview.set_always_show_image(true) ;

  Gtk::Button button_cancel(" Close window ")  ;
  Gtk::Image  image_cancel(PATH_TO_BUTTON_ICONS "window-close.png") ;

  button_cancel.set_image(image_cancel) ;
  button_cancel.set_always_show_image(true) ;

  dialog.add_action_widget(button_cancel,  Gtk::RESPONSE_CLOSE) ;
  dialog.add_action_widget(button_preview, Gtk::RESPONSE_YES)   ;
  dialog.add_action_widget(button_ok,      Gtk::RESPONSE_APPLY) ;




  Gtk::Box *files_merging_add_main_content_box = dialog.get_content_area() ;

  files_merging_add_main_content_box->set_spacing(BOX_SPACING) ;

  files_merging_add_main_content_box->pack_start(files_merging_add_explanation_frame,    false, false, 0) ;
  files_merging_add_main_content_box->pack_start(files_merging_add_input_frame,          false, false, 0) ;
  files_merging_add_main_content_box->pack_start(files_merging_add_output_frame,         false, false, 0) ;


  files_merging_add_input_file_1.signal_file_set().connect([&files_merging_add_input_file_1, &input_filepath_1, &input_filepath_2, &files_merging_add_size_width_spinbutton, &files_merging_add_size_height_spinbutton]() {

    input_filepath_1 = files_merging_add_input_file_1.get_filename() ;

    if (! input_filepath_2.empty()) {

      cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
      cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;


      resize_to_same_size(frame1, frame2) ;

      files_merging_add_size_width_spinbutton.set_value(static_cast<double>(frame1.cols))  ;
      files_merging_add_size_height_spinbutton.set_value(static_cast<double>(frame1.rows)) ;

   }

  } ) ;

  files_merging_add_input_file_2.signal_file_set().connect([&files_merging_add_input_file_2, &input_filepath_1, &input_filepath_2, &files_merging_add_size_width_spinbutton, &files_merging_add_size_height_spinbutton]() {

    input_filepath_2 = files_merging_add_input_file_2.get_filename() ;

    if (! input_filepath_1.empty()) {

      cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
      cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;


      resize_to_same_size(frame1, frame2) ;

      files_merging_add_size_width_spinbutton.set_value(static_cast<double>(frame1.cols))  ;
      files_merging_add_size_height_spinbutton.set_value(static_cast<double>(frame1.rows)) ;

   }

  } ) ;


  button_preview.signal_clicked().connect([&dialog, this, &input_filepath_1, &input_filepath_2, &files_merging_add_size_width_spinbutton, &files_merging_add_size_height_spinbutton, &files_merging_add_input_scale_spinbutton, &files_merging_add_input_offset_spinbutton] () {

    if (input_filepath_1.empty() || input_filepath_2.empty()) { return ; }

    if ( ! files_merging_add_size_width_spinbutton.get_value_as_int() || ! files_merging_add_size_height_spinbutton.get_value_as_int() ) {

      cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
      cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;

      resize_to_same_size(frame1, frame2, cv::Size(0,0)) ;

      files_merging_add_size_width_spinbutton.set_value(static_cast<double>(frame1.cols))  ;
      files_merging_add_size_height_spinbutton.set_value(static_cast<double>(frame1.rows)) ;

    }

    cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
    cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;

    cv::Mat result ;

    const double scale    = files_merging_add_input_scale_spinbutton.get_value()  ;
    const double offset   = files_merging_add_input_offset_spinbutton.get_value() ;

    cv::Size size(files_merging_add_size_width_spinbutton.get_value_as_int(), files_merging_add_size_height_spinbutton.get_value_as_int()) ;

    if (add_images(frame1, frame2, result, scale, offset, size) != 0) { return ; }


    files_merging_preview_output(result) ;


  } ) ;



  files_merging_add_save_as_label_button.signal_clicked().connect(sigc::bind<string&, Gtk::Entry&>(sigc::mem_fun(*this, &GUI::files_merging_set_output_file), output_filepath, files_merging_add_save_as_entry) ) ;

  files_merging_add_main_content_box->show_all() ;


  reshow_window :

  int ret = dialog.run() ;

  switch (ret) {

    case Gtk::RESPONSE_YES :

      goto reshow_window ;
 
      break ;
 
    case Gtk::RESPONSE_APPLY : {

      if ( input_filepath_1.empty() || input_filepath_2.empty() ) {
 
        const string title = "Input files failed" ;
 
        const string message = "You must set the 2 input files to merge !" ;
 
        message_dialog(title, message) ;
 
        goto reshow_window ;
      }

      if ( output_filepath.empty() ) {
 
        const string title = "Ouput file fail" ;
 
        const string message = "You must set an ouput file to save the merge result !" ;
 
        message_dialog(title, message) ;
 
        goto reshow_window ;
      }

      cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
      cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;

      cv::Mat result ;

      const double scale    = files_merging_add_input_scale_spinbutton.get_value()  ;
      const double offset   = files_merging_add_input_offset_spinbutton.get_value() ;
 
      cv::Size size(files_merging_add_size_width_spinbutton.get_value_as_int(), files_merging_add_size_height_spinbutton.get_value_as_int()) ;

      if (add_images(frame1, frame2, result, scale, offset, size) != 0) {
 
        const string title = "Files merging error" ;
 
        const string message = "An error occurs by file merging !" ;
 
        message_dialog(title, message) ;
 
        break ;

      }


      if (! imwrite(output_filepath, result) ) {
   
          unlink(output_filepath.c_str()) ;
   
          const string title = "File saving error" ;

          string msg   = "Error saving file: " ;

          msg += Glib::path_get_basename(output_filepath) ;

          message_dialog(title, msg) ;

          break ;

      }

      const string title = "File merging success" ;

      string msg   = "File\n\n" ;

      msg += Glib::path_get_basename(input_filepath_1) ;

      msg += " and file " ;

      msg += Glib::path_get_basename(input_filepath_2) ;

      msg += "\n\nmerge as file: " ;

      msg += Glib::path_get_basename(output_filepath) ;

      message_dialog(title, msg) ;
   

    }

  }

  dialog.close() ;

  return ;

}

void GUI::files_merging_add_modulo_images() {

  /** Add 2 images, without clipping the result
    *
    *   Result = (Image1 + Image2) % MAX
    *
    * The images are converted to the same size (to the littler image) was is required for add operation.
    ****************************************************************************************************/

  string input_filepath_1 ;
  string input_filepath_2 ;

  string output_filepath  ;



  Gtk::Dialog dialog("Files merging add modulo.", false) ;

  // Configure dialog:
  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "view-presentation.png") ;
  dialog.set_type_hint(Gdk::WINDOW_TYPE_HINT_NORMAL) ;
  dialog.set_resizable(false) ;
  dialog.set_border_width(DIALOG_BORDER_WIDTH) ;
  dialog.set_modal(false) ;
  dialog.set_position(Gtk::WIN_POS_CENTER) ;

  Glib::PropertyProxy<bool> destroy_with_parent_bool = dialog.property_destroy_with_parent() ;
  destroy_with_parent_bool.set_value(false) ;


  Gtk::Frame          files_merging_add_modulo_explanation_frame("") ;

  Gtk::Box            files_merging_add_modulo_explanation_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_add_modulo_explanation_frame_widget_image(PATH_TO_MENU_ICONS "applications-education-university.png") ;
  Gtk::Label          files_merging_add_modulo_explanation_frame_widget_label(" Explanations ") ;

  Gtk::Label          files_merging_add_modulo_explanation_label ;

  files_merging_add_modulo_explanation_label.set_markup("\n\t\t<big>Add 2 images and make the euclidian division of the result per the maximal:\t\n"
                                                     "\t\t\t\t\t\t<big>Result = ( Image1 + Image2 ) % MAX\t</big>\n"
                                                     "<small>\tThe images are converted to the same size (to the littler image) was is required for add modulo operation.\t</small></big>\n") ;

  files_merging_add_modulo_explanation_label.set_margin_left(FRAME_INNER_SPACE)   ;
  files_merging_add_modulo_explanation_label.set_margin_right(FRAME_INNER_SPACE)  ;
  files_merging_add_modulo_explanation_label.set_margin_top(FRAME_INNER_SPACE)    ;
  files_merging_add_modulo_explanation_label.set_margin_bottom(FRAME_INNER_SPACE) ;

  files_merging_add_modulo_explanation_frame_widget_hbox.pack_start(files_merging_add_modulo_explanation_frame_widget_image, false, false, 0) ;
  files_merging_add_modulo_explanation_frame_widget_hbox.pack_start(files_merging_add_modulo_explanation_frame_widget_label, false, false, 0) ;

  files_merging_add_modulo_explanation_frame.set_label_widget(files_merging_add_modulo_explanation_frame_widget_hbox) ;

  files_merging_add_modulo_explanation_label.set_margin_bottom(6) ;

  files_merging_add_modulo_explanation_frame.add(files_merging_add_modulo_explanation_label) ;





  Gtk::Frame          files_merging_add_modulo_input_frame("") ;

  Gtk::Box            files_merging_add_modulo_input_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_add_modulo_input_frame_widget_image(PATH_TO_MENU_ICONS "document-save.png") ;
  Gtk::Label          files_merging_add_modulo_input_frame_widget_label(" Input ") ;

  files_merging_add_modulo_input_frame_widget_hbox.pack_start(files_merging_add_modulo_input_frame_widget_image, false, false, 0) ;
  files_merging_add_modulo_input_frame_widget_hbox.pack_start(files_merging_add_modulo_input_frame_widget_label, false, false, 0) ;

  files_merging_add_modulo_input_frame.set_label_widget(files_merging_add_modulo_input_frame_widget_hbox) ;


  Gtk::FileChooserButton files_merging_add_modulo_input_file_1("Choose input file 1 to merge.", Gtk::FILE_CHOOSER_ACTION_OPEN) ;

  Gtk::FileChooserButton files_merging_add_modulo_input_file_2("Choose input file 2 to merge.", Gtk::FILE_CHOOSER_ACTION_OPEN) ;


  Gtk::Box               files_merging_add_modulo_input_hbox(Gtk::ORIENTATION_HORIZONTAL) ;

  files_merging_add_modulo_input_hbox.set_border_width(BOX_BORDER) ;
  files_merging_add_modulo_input_hbox.set_spacing(BOX_SPACING) ;

  files_merging_add_modulo_input_file_1.set_title("Select input file 1") ;
  files_merging_add_modulo_input_file_1.set_width_chars(20) ;

  config_select_file_filters(files_merging_add_modulo_input_file_1) ;

  files_merging_add_modulo_input_file_2.set_title("Select input file 2") ;
  files_merging_add_modulo_input_file_2.set_width_chars(20) ;

  config_select_file_filters(files_merging_add_modulo_input_file_2) ;


  Gtk::Separator files_merging_add_modulo_input_separator_1(Gtk::ORIENTATION_VERTICAL) ;
  Gtk::Separator files_merging_add_modulo_input_separator_2(Gtk::ORIENTATION_VERTICAL) ;
  Gtk::Separator files_merging_add_modulo_input_separator_3(Gtk::ORIENTATION_VERTICAL) ;

  files_merging_add_modulo_input_hbox.pack_start(files_merging_add_modulo_input_separator_1,      false, false, 0) ;
  files_merging_add_modulo_input_hbox.pack_start(files_merging_add_modulo_input_file_1,           true,  true,  0) ;
  files_merging_add_modulo_input_hbox.pack_start(files_merging_add_modulo_input_separator_2,      false, false, 0) ;
  files_merging_add_modulo_input_hbox.pack_start(files_merging_add_modulo_input_file_2,           true,  true,  0) ;
  files_merging_add_modulo_input_hbox.pack_start(files_merging_add_modulo_input_separator_3,      false, false, 0) ;

  files_merging_add_modulo_input_frame.add(files_merging_add_modulo_input_hbox) ;


  Gtk::Frame          files_merging_add_modulo_output_frame("") ;

  Gtk::Box            files_merging_add_modulo_output_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_add_modulo_output_frame_widget_image(PATH_TO_MENU_ICONS "document-save.png") ;
  Gtk::Label          files_merging_add_modulo_output_frame_widget_label(" Output ") ;

  files_merging_add_modulo_output_frame_widget_hbox.pack_start(files_merging_add_modulo_output_frame_widget_image, false, false, 0) ;
  files_merging_add_modulo_output_frame_widget_hbox.pack_start(files_merging_add_modulo_output_frame_widget_label, false, false, 0) ;

  files_merging_add_modulo_output_frame.set_label_widget(files_merging_add_modulo_output_frame_widget_hbox) ;


  Gtk::Frame          files_merging_add_modulo_save_as_frame("") ;

  Gtk::Box            files_merging_add_modulo_save_as_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;
  Gtk::Box            files_merging_add_modulo_save_as_hbox2(Gtk::ORIENTATION_VERTICAL,   0) ;

  Gtk::Box            files_merging_add_modulo_save_as_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_add_modulo_save_as_frame_widget_image(PATH_TO_MENU_ICONS "document-save-as.png") ;
  Gtk::Label          files_merging_add_modulo_save_as_frame_widget_label(" Save as ") ;

  files_merging_add_modulo_save_as_frame_widget_hbox.pack_start(files_merging_add_modulo_save_as_frame_widget_image, false, false, 0) ;
  files_merging_add_modulo_save_as_frame_widget_hbox.pack_start(files_merging_add_modulo_save_as_frame_widget_label, false, false, 0) ;

  files_merging_add_modulo_save_as_frame.set_label_widget(files_merging_add_modulo_save_as_frame_widget_hbox) ;



  Gtk::Box            files_merging_add_modulo_save_as_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;


  Gtk::Button         files_merging_add_modulo_save_as_label_button(" Save output file as ") ;

  Gtk::Image          files_merging_add_modulo_save_as_image(PATH_TO_BUTTON_ICONS "document-save-as.png") ;

  files_merging_add_modulo_save_as_label_button.set_image(files_merging_add_modulo_save_as_image) ;
  files_merging_add_modulo_save_as_label_button.set_always_show_image(true) ;

  Gtk::Entry          files_merging_add_modulo_save_as_entry ;

  files_merging_add_modulo_save_as_entry.set_width_chars(40) ;
  files_merging_add_modulo_save_as_entry.set_alignment(Gtk::ALIGN_CENTER) ;

  files_merging_add_modulo_save_as_vbox.set_border_width(BOX_BORDER) ;
  files_merging_add_modulo_save_as_vbox.set_spacing(BOX_SPACING) ;

  files_merging_add_modulo_save_as_vbox.pack_start(files_merging_add_modulo_save_as_label_button, false, false, 0) ;
  files_merging_add_modulo_save_as_vbox.pack_start(files_merging_add_modulo_save_as_entry,        false, false, 0) ;

  files_merging_add_modulo_save_as_hbox2.set_border_width(BOX_BORDER) ;
  files_merging_add_modulo_save_as_hbox2.set_spacing(BOX_SPACING) ;

  files_merging_add_modulo_save_as_hbox2.pack_start(files_merging_add_modulo_save_as_vbox,       false, false, 0) ;



  files_merging_add_modulo_save_as_frame.add(files_merging_add_modulo_save_as_hbox2) ;
  files_merging_add_modulo_save_as_frame.set_border_width(FRAME_BORDER_WIDTH) ;




  Gtk::Frame          files_merging_add_modulo_size_frame("") ;

  Gtk::Box            files_merging_add_modulo_size_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_add_modulo_size_frame_widget_image(PATH_TO_MENU_ICONS "view-fullscreen.png") ;
  Gtk::Label          files_merging_add_modulo_size_frame_widget_label(" Size ") ;

  files_merging_add_modulo_size_frame_widget_hbox.pack_start(files_merging_add_modulo_size_frame_widget_image, false, false, 0) ;
  files_merging_add_modulo_size_frame_widget_hbox.pack_start(files_merging_add_modulo_size_frame_widget_label, false, false, 0) ;

  files_merging_add_modulo_size_frame.set_label_widget(files_merging_add_modulo_size_frame_widget_hbox) ;

  Gtk::Box            files_merging_add_modulo_size_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Box            files_merging_add_modulo_size_width_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;
  Gtk::Box            files_merging_add_modulo_size_height_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;

  Gtk::Button         files_merging_add_modulo_size_width_button(" Width ")   ;
  Gtk::Button         files_merging_add_modulo_size_height_button(" Height ") ;

  Gtk::Image          files_merging_add_modulo_size_width_image(PATH_TO_BUTTON_ICONS "zoom-original.png") ;
  Gtk::Image          files_merging_add_modulo_size_height_image(PATH_TO_BUTTON_ICONS "zoom-original.png") ;

  files_merging_add_modulo_size_width_button.set_image(files_merging_add_modulo_size_width_image)   ;
  files_merging_add_modulo_size_height_button.set_image(files_merging_add_modulo_size_height_image) ;

  files_merging_add_modulo_size_width_button.set_always_show_image(true)   ;
  files_merging_add_modulo_size_height_button.set_always_show_image(true)  ;

  Gtk::SpinButton    files_merging_add_modulo_size_width_spinbutton   ;
  Gtk::SpinButton    files_merging_add_modulo_size_height_spinbutton  ;

  files_merging_add_modulo_size_width_spinbutton.set_digits(0) ;
  files_merging_add_modulo_size_width_spinbutton.set_range(0.0, 65536.0)      ;
  files_merging_add_modulo_size_width_spinbutton.set_value(0.0)      ;
  files_merging_add_modulo_size_width_spinbutton.set_increments(1.0, 1.0)    ;
  files_merging_add_modulo_size_width_spinbutton.set_snap_to_ticks(true)    ;
  files_merging_add_modulo_size_width_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  files_merging_add_modulo_size_width_spinbutton.set_adjustment( Gtk::Adjustment::create(0.0, 0.0, 65536.0, 1.0, 10.0) ) ;

  files_merging_add_modulo_size_height_spinbutton.set_digits(0) ;
  files_merging_add_modulo_size_height_spinbutton.set_range(0.0, 65536.0)      ;
  files_merging_add_modulo_size_height_spinbutton.set_value(0.0)      ;
  files_merging_add_modulo_size_height_spinbutton.set_increments(1.0, 10.0)    ;
  files_merging_add_modulo_size_height_spinbutton.set_snap_to_ticks(true)    ;
  files_merging_add_modulo_size_height_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  files_merging_add_modulo_size_height_spinbutton.set_adjustment( Gtk::Adjustment::create(0.0, 0.0, 65536.0, 1.0, 10.0) ) ;

  files_merging_add_modulo_size_width_vbox.set_border_width(BOX_BORDER) ;
  files_merging_add_modulo_size_height_vbox.set_border_width(BOX_BORDER) ;

  files_merging_add_modulo_size_width_vbox.set_spacing(BOX_SPACING) ;
  files_merging_add_modulo_size_height_vbox.set_spacing(BOX_SPACING) ;

  files_merging_add_modulo_size_width_vbox.pack_start(files_merging_add_modulo_size_width_button,     false, false, 0) ;
  files_merging_add_modulo_size_width_vbox.pack_start(files_merging_add_modulo_size_width_spinbutton, false, false, 0) ;

  files_merging_add_modulo_size_height_vbox.pack_start(files_merging_add_modulo_size_height_button,     false, false, 0) ;
  files_merging_add_modulo_size_height_vbox.pack_start(files_merging_add_modulo_size_height_spinbutton, false, false, 0) ;

  files_merging_add_modulo_size_hbox.set_border_width(BOX_BORDER) ;
  files_merging_add_modulo_size_hbox.set_spacing(BOX_SPACING) ;

  files_merging_add_modulo_size_hbox.pack_start(files_merging_add_modulo_size_width_vbox,  true, true, 0) ;
  files_merging_add_modulo_size_hbox.pack_start(files_merging_add_modulo_size_height_vbox, true, true, 0) ;

  files_merging_add_modulo_size_frame.add(files_merging_add_modulo_size_hbox) ;

  files_merging_add_modulo_size_frame.set_border_width(FRAME_BORDER_WIDTH) ;

  files_merging_add_modulo_save_as_hbox.pack_start(files_merging_add_modulo_save_as_frame, true,  true, 0) ;
  files_merging_add_modulo_save_as_hbox.pack_start(files_merging_add_modulo_size_frame,    true,  true, 0) ;


  files_merging_add_modulo_output_frame.add(files_merging_add_modulo_save_as_hbox) ;






  // Add action buttons
  Gtk::ButtonBox *buttonbox = dialog.get_action_area() ;

  buttonbox->set_layout(Gtk::BUTTONBOX_EDGE) ;
  buttonbox->set_homogeneous(true) ;

  Gtk::Button button_ok(" Save file ") ;
  Gtk::Image  image_ok(PATH_TO_BUTTON_ICONS "dialog-ok-apply.png")  ;

  button_ok.set_image(image_ok) ;
  button_ok.set_always_show_image(true) ;

  Gtk::Button button_preview(" Preview result ") ;
  Gtk::Image  image_preview(PATH_TO_BUTTON_ICONS "view-presentation.png")  ;

  button_preview.set_image(image_preview) ;
  button_preview.set_always_show_image(true) ;

  Gtk::Button button_cancel(" Close window ")  ;
  Gtk::Image  image_cancel(PATH_TO_BUTTON_ICONS "window-close.png") ;

  button_cancel.set_image(image_cancel) ;
  button_cancel.set_always_show_image(true) ;

  dialog.add_action_widget(button_cancel,  Gtk::RESPONSE_CLOSE) ;
  dialog.add_action_widget(button_preview, Gtk::RESPONSE_YES)   ;
  dialog.add_action_widget(button_ok,      Gtk::RESPONSE_APPLY) ;




  Gtk::Box *files_merging_add_modulo_main_content_box = dialog.get_content_area() ;

  files_merging_add_modulo_main_content_box->set_spacing(BOX_SPACING) ;

  files_merging_add_modulo_main_content_box->pack_start(files_merging_add_modulo_explanation_frame,    false, false, 0) ;
  files_merging_add_modulo_main_content_box->pack_start(files_merging_add_modulo_input_frame,          false, false, 0) ;
  files_merging_add_modulo_main_content_box->pack_start(files_merging_add_modulo_output_frame,         false, false, 0) ;


  files_merging_add_modulo_input_file_1.signal_file_set().connect([&files_merging_add_modulo_input_file_1, &input_filepath_1, &input_filepath_2, &files_merging_add_modulo_size_width_spinbutton, &files_merging_add_modulo_size_height_spinbutton]() {

    input_filepath_1 = files_merging_add_modulo_input_file_1.get_filename() ;

    if (! input_filepath_2.empty()) {

      cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
      cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;


      resize_to_same_size(frame1, frame2) ;

      files_merging_add_modulo_size_width_spinbutton.set_value(static_cast<double>(frame1.cols))  ;
      files_merging_add_modulo_size_height_spinbutton.set_value(static_cast<double>(frame1.rows)) ;
    
   }

  } ) ;

  files_merging_add_modulo_input_file_2.signal_file_set().connect([&files_merging_add_modulo_input_file_2, &input_filepath_1, &input_filepath_2, &files_merging_add_modulo_size_width_spinbutton, &files_merging_add_modulo_size_height_spinbutton]() {

    input_filepath_2 = files_merging_add_modulo_input_file_2.get_filename() ;

    if (! input_filepath_1.empty()) {

      cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
      cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;
  
      resize_to_same_size(frame1, frame2) ;

      files_merging_add_modulo_size_width_spinbutton.set_value(static_cast<double>(frame1.cols))  ;
      files_merging_add_modulo_size_height_spinbutton.set_value(static_cast<double>(frame1.rows)) ;


   }

  } ) ;


  button_preview.signal_clicked().connect([&dialog, this, &input_filepath_1, &input_filepath_2, &files_merging_add_modulo_size_width_spinbutton, &files_merging_add_modulo_size_height_spinbutton] () {

    if (input_filepath_1.empty() || input_filepath_2.empty()) { return ; }

    if ( ! files_merging_add_modulo_size_width_spinbutton.get_value_as_int() || ! files_merging_add_modulo_size_height_spinbutton.get_value_as_int() ) {

      cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
      cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;

      resize_to_same_size(frame1, frame2, cv::Size(0,0)) ;

      files_merging_add_modulo_size_width_spinbutton.set_value(static_cast<double>(frame1.cols))  ;
      files_merging_add_modulo_size_height_spinbutton.set_value(static_cast<double>(frame1.rows)) ;

    }

    cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
    cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;

    cv::Mat result ;

    cv::Size size(files_merging_add_modulo_size_width_spinbutton.get_value_as_int(), files_merging_add_modulo_size_height_spinbutton.get_value_as_int()) ;

    if (add_modulo_images(frame1, frame2, result, size) != 0) { return ; }


    files_merging_preview_output(result) ;


  } ) ;



  files_merging_add_modulo_save_as_label_button.signal_clicked().connect(sigc::bind<string&, Gtk::Entry&>(sigc::mem_fun(*this, &GUI::files_merging_set_output_file), output_filepath, files_merging_add_modulo_save_as_entry) ) ;

  files_merging_add_modulo_main_content_box->show_all() ;


  reshow_window :

  int ret = dialog.run() ;

  switch (ret) {

    case Gtk::RESPONSE_YES :

      goto reshow_window ;
 
      break ;
 
    case Gtk::RESPONSE_APPLY : {

      if ( input_filepath_1.empty() || input_filepath_2.empty() ) {
 
        const string title = "Input files failed" ;
 
        const string message = "You must set the 2 input files to merge !" ;
 
        message_dialog(title, message) ;
 
        goto reshow_window ;
      }

      if ( output_filepath.empty() ) {
 
        const string title = "Ouput file fail" ;
 
        const string message = "You must set an ouput file to save the merge result !" ;
 
        message_dialog(title, message) ;
 
        goto reshow_window ;
      }

      cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
      cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;

      cv::Mat result ;

      cv::Size size(files_merging_add_modulo_size_width_spinbutton.get_value_as_int(), files_merging_add_modulo_size_height_spinbutton.get_value_as_int()) ;

      if (add_modulo_images(frame1, frame2, result, size) != 0) {
 
        const string title = "Files merging error" ;
 
        const string message = "An error occurs by file merging !" ;
 
        message_dialog(title, message) ;
 
        break ;

      }


      if (! imwrite(output_filepath, result) ) {
   
          unlink(output_filepath.c_str()) ;
   
          const string title = "File saving error" ;

          string msg   = "Error saving file: " ;

          msg += Glib::path_get_basename(output_filepath) ;

          message_dialog(title, msg) ;

          break ;

      }

      const string title = "File merging success" ;

      string msg   = "File " ;

      msg += Glib::path_get_basename(input_filepath_1) ;

      msg += " and file " ;

      msg += Glib::path_get_basename(input_filepath_2) ;

      msg += "\n\nmerge as file: " ;

      msg += Glib::path_get_basename(output_filepath) ;

      message_dialog(title, msg) ;
   

    }

  }

  dialog.close() ;

  return ;

}

void GUI::files_merging_sub_images() {

  /** Substract 2 images, dividing the result by scale and adding offset to generate an output image:
    *
    *   Result = (Image1 - Image2) / scale + offset
    *
    * The images are converted to the same size (to the littler image) was is required for subtract operation.
    *********************************************************************************************************/

  string input_filepath_1 ;
  string input_filepath_2 ;

  string output_filepath  ;



  Gtk::Dialog dialog("Files merging sub.", false) ;

  // Configure dialog:
  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "view-presentation.png") ;
  dialog.set_type_hint(Gdk::WINDOW_TYPE_HINT_NORMAL) ;
  dialog.set_resizable(false) ;
  dialog.set_border_width(DIALOG_BORDER_WIDTH) ;
  dialog.set_modal(false) ;
  dialog.set_position(Gtk::WIN_POS_CENTER) ;

  Glib::PropertyProxy<bool> destroy_with_parent_bool = dialog.property_destroy_with_parent() ;
  destroy_with_parent_bool.set_value(false) ;


  Gtk::Frame          files_merging_sub_explanation_frame("") ;

  Gtk::Box            files_merging_sub_explanation_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_sub_explanation_frame_widget_image(PATH_TO_MENU_ICONS "applications-education-university.png") ;
  Gtk::Label          files_merging_sub_explanation_frame_widget_label(" Explanations ") ;

  Gtk::Label          files_merging_sub_explanation_label ;

  files_merging_sub_explanation_label.set_markup("\n\t<big>Subtract 2 images, dividing the result by scale and adding offset to generate an output image:\t\n"
                                                   "\t\t\t\t\t\t<big>Result = (Image1 - Image2) / scale + offset</big>\t\n"
                                                   "\t\t<small>The images are converted to the same size (to the littler image) was is required for sub operation.\t</small></big>\n") ;


  files_merging_sub_explanation_label.set_margin_left(FRAME_INNER_SPACE)   ;
  files_merging_sub_explanation_label.set_margin_right(FRAME_INNER_SPACE)  ;
  files_merging_sub_explanation_label.set_margin_top(FRAME_INNER_SPACE)    ;
  files_merging_sub_explanation_label.set_margin_bottom(FRAME_INNER_SPACE) ;

  files_merging_sub_explanation_frame_widget_hbox.pack_start(files_merging_sub_explanation_frame_widget_image, false, false, 0) ;
  files_merging_sub_explanation_frame_widget_hbox.pack_start(files_merging_sub_explanation_frame_widget_label, false, false, 0) ;

  files_merging_sub_explanation_frame.set_label_widget(files_merging_sub_explanation_frame_widget_hbox) ;

  files_merging_sub_explanation_label.set_margin_bottom(6) ;

  files_merging_sub_explanation_frame.add(files_merging_sub_explanation_label) ;





  Gtk::Frame          files_merging_sub_input_frame("") ;

  Gtk::Box            files_merging_sub_input_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_sub_input_frame_widget_image(PATH_TO_MENU_ICONS "document-save.png") ;
  Gtk::Label          files_merging_sub_input_frame_widget_label(" Input ") ;

  files_merging_sub_input_frame_widget_hbox.pack_start(files_merging_sub_input_frame_widget_image, false, false, 0) ;
  files_merging_sub_input_frame_widget_hbox.pack_start(files_merging_sub_input_frame_widget_label, false, false, 0) ;

  files_merging_sub_input_frame.set_label_widget(files_merging_sub_input_frame_widget_hbox) ;


  Gtk::FileChooserButton files_merging_sub_input_file_1("Choose input file 1 to merge.", Gtk::FILE_CHOOSER_ACTION_OPEN) ;

  Gtk::Label             files_merging_sub_input_scale_label("Scale") ;

  Gtk::SpinButton        files_merging_sub_input_scale_spinbutton(Gtk::ORIENTATION_HORIZONTAL) ;

  Gtk::Label             files_merging_sub_input_offset_label("Offset") ;

  Gtk::SpinButton        files_merging_sub_input_offset_spinbutton(Gtk::ORIENTATION_HORIZONTAL) ;

  Gtk::FileChooserButton files_merging_sub_input_file_2("Choose input file 2 to merge.", Gtk::FILE_CHOOSER_ACTION_OPEN) ;


  Gtk::Box               files_merging_sub_input_hbox(Gtk::ORIENTATION_HORIZONTAL) ;

  files_merging_sub_input_hbox.set_border_width(BOX_BORDER) ;
  files_merging_sub_input_hbox.set_spacing(BOX_SPACING) ;

  files_merging_sub_input_file_1.set_title("Select input file 1") ;
  files_merging_sub_input_file_1.set_width_chars(16) ;

  config_select_file_filters(files_merging_sub_input_file_1) ;

  files_merging_sub_input_file_2.set_title("Select input file 2") ;
  files_merging_sub_input_file_2.set_width_chars(16) ;

  config_select_file_filters(files_merging_sub_input_file_2) ;


  files_merging_sub_input_scale_spinbutton.set_digits(2) ;
  files_merging_sub_input_scale_spinbutton.set_range(0.01, 8.0)      ;
  files_merging_sub_input_scale_spinbutton.set_value(1.0)      ;
  files_merging_sub_input_scale_spinbutton.set_increments(0.01, 0.1)    ;
  files_merging_sub_input_scale_spinbutton.set_snap_to_ticks(true)    ;
  files_merging_sub_input_scale_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  files_merging_sub_input_scale_spinbutton.set_adjustment( Gtk::Adjustment::create(1.0, 0.01, 8.0, 0.01, 0.1) ) ;


  files_merging_sub_input_offset_spinbutton.set_digits(0) ;
  files_merging_sub_input_offset_spinbutton.set_range(0.0, 255.0)      ;
  files_merging_sub_input_offset_spinbutton.set_value(0.0)      ;
  files_merging_sub_input_offset_spinbutton.set_increments(1.0, 10.0)    ;
  files_merging_sub_input_offset_spinbutton.set_snap_to_ticks(true)    ;
  files_merging_sub_input_offset_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  files_merging_sub_input_offset_spinbutton.set_adjustment( Gtk::Adjustment::create(0.0, 0.0, 255.0, 1.0, 10.0) ) ;


  Gtk::Separator files_merging_sub_input_separator_1(Gtk::ORIENTATION_VERTICAL) ;
  Gtk::Separator files_merging_sub_input_separator_2(Gtk::ORIENTATION_VERTICAL) ;
  Gtk::Separator files_merging_sub_input_separator_3(Gtk::ORIENTATION_VERTICAL) ;
  Gtk::Separator files_merging_sub_input_separator_4(Gtk::ORIENTATION_VERTICAL) ;

  files_merging_sub_input_hbox.pack_start(files_merging_sub_input_separator_1,       false, false, 0) ;
  files_merging_sub_input_hbox.pack_start(files_merging_sub_input_file_1,            true,  true,  0) ;
  files_merging_sub_input_hbox.pack_start(files_merging_sub_input_separator_2,       false, false, 0) ;
  files_merging_sub_input_hbox.pack_start(files_merging_sub_input_scale_label,       false, false, 0) ;
  files_merging_sub_input_hbox.pack_start(files_merging_sub_input_scale_spinbutton,  false, false, 0) ;
  files_merging_sub_input_hbox.pack_start(files_merging_sub_input_offset_label,      false, false, 0) ;
  files_merging_sub_input_hbox.pack_start(files_merging_sub_input_offset_spinbutton, false, false, 0) ;
  files_merging_sub_input_hbox.pack_start(files_merging_sub_input_separator_3,       false, false, 0) ;
  files_merging_sub_input_hbox.pack_start(files_merging_sub_input_file_2,            true,  true,  0) ;
  files_merging_sub_input_hbox.pack_start(files_merging_sub_input_separator_4,       false, false, 0) ;

  files_merging_sub_input_frame.add(files_merging_sub_input_hbox) ;


  Gtk::Frame          files_merging_sub_output_frame("") ;

  Gtk::Box            files_merging_sub_output_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_sub_output_frame_widget_image(PATH_TO_MENU_ICONS "document-save.png") ;
  Gtk::Label          files_merging_sub_output_frame_widget_label(" Output ") ;

  files_merging_sub_output_frame_widget_hbox.pack_start(files_merging_sub_output_frame_widget_image, false, false, 0) ;
  files_merging_sub_output_frame_widget_hbox.pack_start(files_merging_sub_output_frame_widget_label, false, false, 0) ;

  files_merging_sub_output_frame.set_label_widget(files_merging_sub_output_frame_widget_hbox) ;


  Gtk::Frame          files_merging_sub_save_as_frame("") ;

  Gtk::Box            files_merging_sub_save_as_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;
  Gtk::Box            files_merging_sub_save_as_hbox2(Gtk::ORIENTATION_VERTICAL,   0) ;

  Gtk::Box            files_merging_sub_save_as_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_sub_save_as_frame_widget_image(PATH_TO_MENU_ICONS "document-save-as.png") ;
  Gtk::Label          files_merging_sub_save_as_frame_widget_label(" Save as ") ;

  files_merging_sub_save_as_frame_widget_hbox.pack_start(files_merging_sub_save_as_frame_widget_image, false, false, 0) ;
  files_merging_sub_save_as_frame_widget_hbox.pack_start(files_merging_sub_save_as_frame_widget_label, false, false, 0) ;

  files_merging_sub_save_as_frame.set_label_widget(files_merging_sub_save_as_frame_widget_hbox) ;



  Gtk::Box            files_merging_sub_save_as_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;


  Gtk::Button         files_merging_sub_save_as_label_button(" Save output file as ") ;

  Gtk::Image          files_merging_sub_save_as_image(PATH_TO_BUTTON_ICONS "document-save-as.png") ;

  files_merging_sub_save_as_label_button.set_image(files_merging_sub_save_as_image) ;
  files_merging_sub_save_as_label_button.set_always_show_image(true) ;

  Gtk::Entry          files_merging_sub_save_as_entry ;

  files_merging_sub_save_as_entry.set_width_chars(40) ;
  files_merging_sub_save_as_entry.set_alignment(Gtk::ALIGN_CENTER) ;

  files_merging_sub_save_as_vbox.set_border_width(BOX_BORDER) ;
  files_merging_sub_save_as_vbox.set_spacing(BOX_SPACING) ;

  files_merging_sub_save_as_vbox.pack_start(files_merging_sub_save_as_label_button, false, false, 0) ;
  files_merging_sub_save_as_vbox.pack_start(files_merging_sub_save_as_entry,        false, false, 0) ;

  files_merging_sub_save_as_hbox2.set_border_width(BOX_BORDER) ;
  files_merging_sub_save_as_hbox2.set_spacing(BOX_SPACING) ;

  files_merging_sub_save_as_hbox2.pack_start(files_merging_sub_save_as_vbox,       false, false, 0) ;



  files_merging_sub_save_as_frame.add(files_merging_sub_save_as_hbox2) ;
  files_merging_sub_save_as_frame.set_border_width(FRAME_BORDER_WIDTH) ;




  Gtk::Frame          files_merging_sub_size_frame("") ;

  Gtk::Box            files_merging_sub_size_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_sub_size_frame_widget_image(PATH_TO_MENU_ICONS "view-fullscreen.png") ;
  Gtk::Label          files_merging_sub_size_frame_widget_label(" Size ") ;

  files_merging_sub_size_frame_widget_hbox.pack_start(files_merging_sub_size_frame_widget_image, false, false, 0) ;
  files_merging_sub_size_frame_widget_hbox.pack_start(files_merging_sub_size_frame_widget_label, false, false, 0) ;

  files_merging_sub_size_frame.set_label_widget(files_merging_sub_size_frame_widget_hbox) ;

  Gtk::Box            files_merging_sub_size_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Box            files_merging_sub_size_width_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;
  Gtk::Box            files_merging_sub_size_height_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;

  Gtk::Button         files_merging_sub_size_width_button(" Width ")   ;
  Gtk::Button         files_merging_sub_size_height_button(" Height ") ;

  Gtk::Image          files_merging_sub_size_width_image(PATH_TO_BUTTON_ICONS "zoom-original.png") ;
  Gtk::Image          files_merging_sub_size_height_image(PATH_TO_BUTTON_ICONS "zoom-original.png") ;

  files_merging_sub_size_width_button.set_image(files_merging_sub_size_width_image)   ;
  files_merging_sub_size_height_button.set_image(files_merging_sub_size_height_image) ;

  files_merging_sub_size_width_button.set_always_show_image(true)   ;
  files_merging_sub_size_height_button.set_always_show_image(true)  ;

  Gtk::SpinButton    files_merging_sub_size_width_spinbutton   ;
  Gtk::SpinButton    files_merging_sub_size_height_spinbutton  ;

  files_merging_sub_size_width_spinbutton.set_digits(0) ;
  files_merging_sub_size_width_spinbutton.set_range(0.0, 65536.0)      ;
  files_merging_sub_size_width_spinbutton.set_value(0.0)      ;
  files_merging_sub_size_width_spinbutton.set_increments(1.0, 1.0)    ;
  files_merging_sub_size_width_spinbutton.set_snap_to_ticks(true)    ;
  files_merging_sub_size_width_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  files_merging_sub_size_width_spinbutton.set_adjustment( Gtk::Adjustment::create(0.0, 0.0, 65536.0, 1.0, 10.0) ) ;

  files_merging_sub_size_height_spinbutton.set_digits(0) ;
  files_merging_sub_size_height_spinbutton.set_range(0.0, 65536.0)      ;
  files_merging_sub_size_height_spinbutton.set_value(0.0)      ;
  files_merging_sub_size_height_spinbutton.set_increments(1.0, 10.0)    ;
  files_merging_sub_size_height_spinbutton.set_snap_to_ticks(true)    ;
  files_merging_sub_size_height_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  files_merging_sub_size_height_spinbutton.set_adjustment( Gtk::Adjustment::create(0.0, 0.0, 65536.0, 1.0, 10.0) ) ;

  files_merging_sub_size_width_vbox.set_border_width(BOX_BORDER) ;
  files_merging_sub_size_height_vbox.set_border_width(BOX_BORDER) ;

  files_merging_sub_size_width_vbox.set_spacing(BOX_SPACING) ;
  files_merging_sub_size_height_vbox.set_spacing(BOX_SPACING) ;

  files_merging_sub_size_width_vbox.pack_start(files_merging_sub_size_width_button,     false, false, 0) ;
  files_merging_sub_size_width_vbox.pack_start(files_merging_sub_size_width_spinbutton, false, false, 0) ;

  files_merging_sub_size_height_vbox.pack_start(files_merging_sub_size_height_button,     false, false, 0) ;
  files_merging_sub_size_height_vbox.pack_start(files_merging_sub_size_height_spinbutton, false, false, 0) ;

  files_merging_sub_size_hbox.set_border_width(BOX_BORDER) ;
  files_merging_sub_size_hbox.set_spacing(BOX_SPACING) ;

  files_merging_sub_size_hbox.pack_start(files_merging_sub_size_width_vbox,  true, true, 0) ;
  files_merging_sub_size_hbox.pack_start(files_merging_sub_size_height_vbox, true, true, 0) ;

  files_merging_sub_size_frame.add(files_merging_sub_size_hbox) ;

  files_merging_sub_size_frame.set_border_width(FRAME_BORDER_WIDTH) ;

  files_merging_sub_save_as_hbox.pack_start(files_merging_sub_save_as_frame, true,  true, 0) ;
  files_merging_sub_save_as_hbox.pack_start(files_merging_sub_size_frame,    true,  true, 0) ;


  files_merging_sub_output_frame.add(files_merging_sub_save_as_hbox) ;






  // sub action buttons
  Gtk::ButtonBox *buttonbox = dialog.get_action_area() ;

  buttonbox->set_layout(Gtk::BUTTONBOX_EDGE) ;
  buttonbox->set_homogeneous(true) ;

  Gtk::Button button_ok(" Save file ") ;
  Gtk::Image  image_ok(PATH_TO_BUTTON_ICONS "dialog-ok-apply.png")  ;

  button_ok.set_image(image_ok) ;
  button_ok.set_always_show_image(true) ;

  Gtk::Button button_preview(" Preview result ") ;
  Gtk::Image  image_preview(PATH_TO_BUTTON_ICONS "view-presentation.png")  ;

  button_preview.set_image(image_preview) ;
  button_preview.set_always_show_image(true) ;

  Gtk::Button button_cancel(" Close window ")  ;
  Gtk::Image  image_cancel(PATH_TO_BUTTON_ICONS "window-close.png") ;

  button_cancel.set_image(image_cancel) ;
  button_cancel.set_always_show_image(true) ;

  dialog.add_action_widget(button_cancel,  Gtk::RESPONSE_CLOSE) ;
  dialog.add_action_widget(button_preview, Gtk::RESPONSE_YES)   ;
  dialog.add_action_widget(button_ok,      Gtk::RESPONSE_APPLY) ;




  Gtk::Box *files_merging_sub_main_content_box = dialog.get_content_area() ;

  files_merging_sub_main_content_box->set_spacing(BOX_SPACING) ;

  files_merging_sub_main_content_box->pack_start(files_merging_sub_explanation_frame,    false, false, 0) ;
  files_merging_sub_main_content_box->pack_start(files_merging_sub_input_frame,          false, false, 0) ;
  files_merging_sub_main_content_box->pack_start(files_merging_sub_output_frame,         false, false, 0) ;


  files_merging_sub_input_file_1.signal_file_set().connect([&files_merging_sub_input_file_1, &input_filepath_1, &input_filepath_2, &files_merging_sub_size_width_spinbutton, &files_merging_sub_size_height_spinbutton]() {

    input_filepath_1 = files_merging_sub_input_file_1.get_filename() ;

    if (! input_filepath_2.empty()) {

      cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
      cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;

      resize_to_same_size(frame1, frame2) ;

      files_merging_sub_size_width_spinbutton.set_value(static_cast<double>(frame1.cols))  ;
      files_merging_sub_size_height_spinbutton.set_value(static_cast<double>(frame1.rows)) ;

   }

  } ) ;

  files_merging_sub_input_file_2.signal_file_set().connect([&files_merging_sub_input_file_2, &input_filepath_1, &input_filepath_2, &files_merging_sub_size_width_spinbutton, &files_merging_sub_size_height_spinbutton]() {

    input_filepath_2 = files_merging_sub_input_file_2.get_filename() ;

    if (! input_filepath_1.empty()) {

      cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
      cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;


      resize_to_same_size(frame1, frame2) ;

      files_merging_sub_size_width_spinbutton.set_value(static_cast<double>(frame1.cols))  ;
      files_merging_sub_size_height_spinbutton.set_value(static_cast<double>(frame1.rows)) ;

   }

  } ) ;


  button_preview.signal_clicked().connect([&dialog, this, &input_filepath_1, &input_filepath_2, &files_merging_sub_size_width_spinbutton, &files_merging_sub_size_height_spinbutton, &files_merging_sub_input_scale_spinbutton, &files_merging_sub_input_offset_spinbutton] () {

    if (input_filepath_1.empty() || input_filepath_2.empty()) { return ; }

    if ( ! files_merging_sub_size_width_spinbutton.get_value_as_int() || ! files_merging_sub_size_height_spinbutton.get_value_as_int() ) {

      cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
      cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;

      resize_to_same_size(frame1, frame2, cv::Size(0,0)) ;

      files_merging_sub_size_width_spinbutton.set_value(static_cast<double>(frame1.cols))  ;
      files_merging_sub_size_height_spinbutton.set_value(static_cast<double>(frame1.rows)) ;

    }

    cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
    cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;

    cv::Mat result ;

    const double scale    = files_merging_sub_input_scale_spinbutton.get_value()  ;
    const double offset   = files_merging_sub_input_offset_spinbutton.get_value() ;

    cv::Size size(files_merging_sub_size_width_spinbutton.get_value_as_int(), files_merging_sub_size_height_spinbutton.get_value_as_int()) ;

    if (sub_images(frame1, frame2, result, scale, offset, size) != 0) { return ; }


    files_merging_preview_output(result) ;


  } ) ;



  files_merging_sub_save_as_label_button.signal_clicked().connect(sigc::bind<string&, Gtk::Entry&>(sigc::mem_fun(*this, &GUI::files_merging_set_output_file), output_filepath, files_merging_sub_save_as_entry) ) ;

  files_merging_sub_main_content_box->show_all() ;


  reshow_window :

  int ret = dialog.run() ;

  switch (ret) {

    case Gtk::RESPONSE_YES :

      goto reshow_window ;
 
      break ;
 
    case Gtk::RESPONSE_APPLY : {

      if ( input_filepath_1.empty() || input_filepath_2.empty() ) {
 
        const string title = "Input files failed" ;
 
        const string message = "You must set the 2 input files to merge !" ;
 
        message_dialog(title, message) ;
 
        goto reshow_window ;
      }

      if ( output_filepath.empty() ) {
 
        const string title = "Ouput file fail" ;
 
        const string message = "You must set an ouput file to save the merge result !" ;
 
        message_dialog(title, message) ;
 
        goto reshow_window ;
      }

      cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
      cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;

      cv::Mat result ;

      const double scale    = files_merging_sub_input_scale_spinbutton.get_value()  ;
      const double offset   = files_merging_sub_input_offset_spinbutton.get_value() ;
 
      cv::Size size(files_merging_sub_size_width_spinbutton.get_value_as_int(), files_merging_sub_size_height_spinbutton.get_value_as_int()) ;

      if (sub_images(frame1, frame2, result, scale, offset, size) != 0) {
 
        const string title = "Files merging error" ;
 
        const string message = "An error occurs by file merging !" ;
 
        message_dialog(title, message) ;
 
        break ;

      }


      if (! imwrite(output_filepath, result) ) {
   
          unlink(output_filepath.c_str()) ;
   
          const string title = "File saving error" ;

          string msg   = "Error saving file: " ;

          msg += Glib::path_get_basename(output_filepath) ;

          message_dialog(title, msg) ;

          break ;

      }

      const string title = "File merging success" ;

      string msg   = "File\n\n" ;

      msg += Glib::path_get_basename(input_filepath_1) ;

      msg += " and file " ;

      msg += Glib::path_get_basename(input_filepath_2) ;

      msg += "\n\nmerge as file: " ;

      msg += Glib::path_get_basename(output_filepath) ;

      message_dialog(title, msg) ;
   

    }

  }

  dialog.close() ;

  return ;

}

void GUI::files_merging_sub_modulo_images() {

  /** Substract 2 images, without clipping the result
    *
    *   Result = (Image1 - Image2) % MAX
    *
    * The images are converted to the same size (to the littler image) was is required for add operation.
    ****************************************************************************************************/

  string input_filepath_1 ;
  string input_filepath_2 ;

  string output_filepath  ;



  Gtk::Dialog dialog("Files merging sub modulo.", false) ;

  // Configure dialog:
  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "view-presentation.png") ;
  dialog.set_type_hint(Gdk::WINDOW_TYPE_HINT_NORMAL) ;
  dialog.set_resizable(false) ;
  dialog.set_border_width(DIALOG_BORDER_WIDTH) ;
  dialog.set_modal(false) ;
  dialog.set_position(Gtk::WIN_POS_CENTER) ;

  Glib::PropertyProxy<bool> destroy_with_parent_bool = dialog.property_destroy_with_parent() ;
  destroy_with_parent_bool.set_value(false) ;


  Gtk::Frame          files_merging_sub_modulo_explanation_frame("") ;

  Gtk::Box            files_merging_sub_modulo_explanation_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_sub_modulo_explanation_frame_widget_image(PATH_TO_MENU_ICONS "applications-education-university.png") ;
  Gtk::Label          files_merging_sub_modulo_explanation_frame_widget_label(" Explanations ") ;

  Gtk::Label          files_merging_sub_modulo_explanation_label ;

  files_merging_sub_modulo_explanation_label.set_markup("\n\t\t<big>Subtract 2 images and make the euclidian division of the result per the maximal:\t\n"
                                                     "\t\t\t\t\t\t<big>Result = ( Image1 - Image2 ) % MAX\t</big>\n"
                                                     "<small>\tThe images are converted to the same size (to the littler image) was is required for sub modulo operation.\t</small></big>\n") ;


  files_merging_sub_modulo_explanation_label.set_margin_left(FRAME_INNER_SPACE)   ;
  files_merging_sub_modulo_explanation_label.set_margin_right(FRAME_INNER_SPACE)  ;
  files_merging_sub_modulo_explanation_label.set_margin_top(FRAME_INNER_SPACE)    ;
  files_merging_sub_modulo_explanation_label.set_margin_bottom(FRAME_INNER_SPACE) ;

  files_merging_sub_modulo_explanation_frame_widget_hbox.pack_start(files_merging_sub_modulo_explanation_frame_widget_image, false, false, 0) ;
  files_merging_sub_modulo_explanation_frame_widget_hbox.pack_start(files_merging_sub_modulo_explanation_frame_widget_label, false, false, 0) ;

  files_merging_sub_modulo_explanation_frame.set_label_widget(files_merging_sub_modulo_explanation_frame_widget_hbox) ;

  files_merging_sub_modulo_explanation_label.set_margin_bottom(6) ;

  files_merging_sub_modulo_explanation_frame.add(files_merging_sub_modulo_explanation_label) ;





  Gtk::Frame          files_merging_sub_modulo_input_frame("") ;

  Gtk::Box            files_merging_sub_modulo_input_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_sub_modulo_input_frame_widget_image(PATH_TO_MENU_ICONS "document-save.png") ;
  Gtk::Label          files_merging_sub_modulo_input_frame_widget_label(" Input ") ;

  files_merging_sub_modulo_input_frame_widget_hbox.pack_start(files_merging_sub_modulo_input_frame_widget_image, false, false, 0) ;
  files_merging_sub_modulo_input_frame_widget_hbox.pack_start(files_merging_sub_modulo_input_frame_widget_label, false, false, 0) ;

  files_merging_sub_modulo_input_frame.set_label_widget(files_merging_sub_modulo_input_frame_widget_hbox) ;


  Gtk::FileChooserButton files_merging_sub_modulo_input_file_1("Choose input file 1 to merge.", Gtk::FILE_CHOOSER_ACTION_OPEN) ;

  Gtk::FileChooserButton files_merging_sub_modulo_input_file_2("Choose input file 2 to merge.", Gtk::FILE_CHOOSER_ACTION_OPEN) ;


  Gtk::Box               files_merging_sub_modulo_input_hbox(Gtk::ORIENTATION_HORIZONTAL) ;

  files_merging_sub_modulo_input_hbox.set_border_width(BOX_BORDER) ;
  files_merging_sub_modulo_input_hbox.set_spacing(BOX_SPACING) ;

  files_merging_sub_modulo_input_file_1.set_title("Select input file 1") ;
  files_merging_sub_modulo_input_file_1.set_width_chars(20) ;

  config_select_file_filters(files_merging_sub_modulo_input_file_1) ;

  files_merging_sub_modulo_input_file_2.set_title("Select input file 2") ;
  files_merging_sub_modulo_input_file_2.set_width_chars(20) ;

  config_select_file_filters(files_merging_sub_modulo_input_file_2) ;


  Gtk::Separator files_merging_sub_modulo_input_separator_1(Gtk::ORIENTATION_VERTICAL) ;
  Gtk::Separator files_merging_sub_modulo_input_separator_2(Gtk::ORIENTATION_VERTICAL) ;
  Gtk::Separator files_merging_sub_modulo_input_separator_3(Gtk::ORIENTATION_VERTICAL) ;

  files_merging_sub_modulo_input_hbox.pack_start(files_merging_sub_modulo_input_separator_1,      false, false, 0) ;
  files_merging_sub_modulo_input_hbox.pack_start(files_merging_sub_modulo_input_file_1,           true,  true,  0) ;
  files_merging_sub_modulo_input_hbox.pack_start(files_merging_sub_modulo_input_separator_2,      false, false, 0) ;
  files_merging_sub_modulo_input_hbox.pack_start(files_merging_sub_modulo_input_file_2,           true,  true,  0) ;
  files_merging_sub_modulo_input_hbox.pack_start(files_merging_sub_modulo_input_separator_3,      false, false, 0) ;

  files_merging_sub_modulo_input_frame.add(files_merging_sub_modulo_input_hbox) ;


  Gtk::Frame          files_merging_sub_modulo_output_frame("") ;

  Gtk::Box            files_merging_sub_modulo_output_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_sub_modulo_output_frame_widget_image(PATH_TO_MENU_ICONS "document-save.png") ;
  Gtk::Label          files_merging_sub_modulo_output_frame_widget_label(" Output ") ;

  files_merging_sub_modulo_output_frame_widget_hbox.pack_start(files_merging_sub_modulo_output_frame_widget_image, false, false, 0) ;
  files_merging_sub_modulo_output_frame_widget_hbox.pack_start(files_merging_sub_modulo_output_frame_widget_label, false, false, 0) ;

  files_merging_sub_modulo_output_frame.set_label_widget(files_merging_sub_modulo_output_frame_widget_hbox) ;


  Gtk::Frame          files_merging_sub_modulo_save_as_frame("") ;

  Gtk::Box            files_merging_sub_modulo_save_as_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;
  Gtk::Box            files_merging_sub_modulo_save_as_hbox2(Gtk::ORIENTATION_VERTICAL,   0) ;

  Gtk::Box            files_merging_sub_modulo_save_as_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_sub_modulo_save_as_frame_widget_image(PATH_TO_MENU_ICONS "document-save-as.png") ;
  Gtk::Label          files_merging_sub_modulo_save_as_frame_widget_label(" Save as ") ;

  files_merging_sub_modulo_save_as_frame_widget_hbox.pack_start(files_merging_sub_modulo_save_as_frame_widget_image, false, false, 0) ;
  files_merging_sub_modulo_save_as_frame_widget_hbox.pack_start(files_merging_sub_modulo_save_as_frame_widget_label, false, false, 0) ;

  files_merging_sub_modulo_save_as_frame.set_label_widget(files_merging_sub_modulo_save_as_frame_widget_hbox) ;



  Gtk::Box            files_merging_sub_modulo_save_as_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;


  Gtk::Button         files_merging_sub_modulo_save_as_label_button(" Save output file as ") ;

  Gtk::Image          files_merging_sub_modulo_save_as_image(PATH_TO_BUTTON_ICONS "document-save-as.png") ;

  files_merging_sub_modulo_save_as_label_button.set_image(files_merging_sub_modulo_save_as_image) ;
  files_merging_sub_modulo_save_as_label_button.set_always_show_image(true) ;

  Gtk::Entry          files_merging_sub_modulo_save_as_entry ;

  files_merging_sub_modulo_save_as_entry.set_width_chars(40) ;
  files_merging_sub_modulo_save_as_entry.set_alignment(Gtk::ALIGN_CENTER) ;

  files_merging_sub_modulo_save_as_vbox.set_border_width(BOX_BORDER) ;
  files_merging_sub_modulo_save_as_vbox.set_spacing(BOX_SPACING) ;

  files_merging_sub_modulo_save_as_vbox.pack_start(files_merging_sub_modulo_save_as_label_button, false, false, 0) ;
  files_merging_sub_modulo_save_as_vbox.pack_start(files_merging_sub_modulo_save_as_entry,        false, false, 0) ;

  files_merging_sub_modulo_save_as_hbox2.set_border_width(BOX_BORDER) ;
  files_merging_sub_modulo_save_as_hbox2.set_spacing(BOX_SPACING) ;

  files_merging_sub_modulo_save_as_hbox2.pack_start(files_merging_sub_modulo_save_as_vbox,       false, false, 0) ;



  files_merging_sub_modulo_save_as_frame.add(files_merging_sub_modulo_save_as_hbox2) ;
  files_merging_sub_modulo_save_as_frame.set_border_width(FRAME_BORDER_WIDTH) ;




  Gtk::Frame          files_merging_sub_modulo_size_frame("") ;

  Gtk::Box            files_merging_sub_modulo_size_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          files_merging_sub_modulo_size_frame_widget_image(PATH_TO_MENU_ICONS "view-fullscreen.png") ;
  Gtk::Label          files_merging_sub_modulo_size_frame_widget_label(" Size ") ;

  files_merging_sub_modulo_size_frame_widget_hbox.pack_start(files_merging_sub_modulo_size_frame_widget_image, false, false, 0) ;
  files_merging_sub_modulo_size_frame_widget_hbox.pack_start(files_merging_sub_modulo_size_frame_widget_label, false, false, 0) ;

  files_merging_sub_modulo_size_frame.set_label_widget(files_merging_sub_modulo_size_frame_widget_hbox) ;

  Gtk::Box            files_merging_sub_modulo_size_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Box            files_merging_sub_modulo_size_width_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;
  Gtk::Box            files_merging_sub_modulo_size_height_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;

  Gtk::Button         files_merging_sub_modulo_size_width_button(" Width ")   ;
  Gtk::Button         files_merging_sub_modulo_size_height_button(" Height ") ;

  Gtk::Image          files_merging_sub_modulo_size_width_image(PATH_TO_BUTTON_ICONS "zoom-original.png") ;
  Gtk::Image          files_merging_sub_modulo_size_height_image(PATH_TO_BUTTON_ICONS "zoom-original.png") ;

  files_merging_sub_modulo_size_width_button.set_image(files_merging_sub_modulo_size_width_image)   ;
  files_merging_sub_modulo_size_height_button.set_image(files_merging_sub_modulo_size_height_image) ;

  files_merging_sub_modulo_size_width_button.set_always_show_image(true)   ;
  files_merging_sub_modulo_size_height_button.set_always_show_image(true)  ;

  Gtk::SpinButton    files_merging_sub_modulo_size_width_spinbutton   ;
  Gtk::SpinButton    files_merging_sub_modulo_size_height_spinbutton  ;

  files_merging_sub_modulo_size_width_spinbutton.set_digits(0) ;
  files_merging_sub_modulo_size_width_spinbutton.set_range(0.0, 65536.0)      ;
  files_merging_sub_modulo_size_width_spinbutton.set_value(0.0)      ;
  files_merging_sub_modulo_size_width_spinbutton.set_increments(1.0, 1.0)    ;
  files_merging_sub_modulo_size_width_spinbutton.set_snap_to_ticks(true)    ;
  files_merging_sub_modulo_size_width_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  files_merging_sub_modulo_size_width_spinbutton.set_adjustment( Gtk::Adjustment::create(0.0, 0.0, 65536.0, 1.0, 10.0) ) ;

  files_merging_sub_modulo_size_height_spinbutton.set_digits(0) ;
  files_merging_sub_modulo_size_height_spinbutton.set_range(0.0, 65536.0)      ;
  files_merging_sub_modulo_size_height_spinbutton.set_value(0.0)      ;
  files_merging_sub_modulo_size_height_spinbutton.set_increments(1.0, 10.0)    ;
  files_merging_sub_modulo_size_height_spinbutton.set_snap_to_ticks(true)    ;
  files_merging_sub_modulo_size_height_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  files_merging_sub_modulo_size_height_spinbutton.set_adjustment( Gtk::Adjustment::create(0.0, 0.0, 65536.0, 1.0, 10.0) ) ;

  files_merging_sub_modulo_size_width_vbox.set_border_width(BOX_BORDER) ;
  files_merging_sub_modulo_size_height_vbox.set_border_width(BOX_BORDER) ;

  files_merging_sub_modulo_size_width_vbox.set_spacing(BOX_SPACING) ;
  files_merging_sub_modulo_size_height_vbox.set_spacing(BOX_SPACING) ;

  files_merging_sub_modulo_size_width_vbox.pack_start(files_merging_sub_modulo_size_width_button,     false, false, 0) ;
  files_merging_sub_modulo_size_width_vbox.pack_start(files_merging_sub_modulo_size_width_spinbutton, false, false, 0) ;

  files_merging_sub_modulo_size_height_vbox.pack_start(files_merging_sub_modulo_size_height_button,     false, false, 0) ;
  files_merging_sub_modulo_size_height_vbox.pack_start(files_merging_sub_modulo_size_height_spinbutton, false, false, 0) ;

  files_merging_sub_modulo_size_hbox.set_border_width(BOX_BORDER) ;
  files_merging_sub_modulo_size_hbox.set_spacing(BOX_SPACING) ;

  files_merging_sub_modulo_size_hbox.pack_start(files_merging_sub_modulo_size_width_vbox,  true, true, 0) ;
  files_merging_sub_modulo_size_hbox.pack_start(files_merging_sub_modulo_size_height_vbox, true, true, 0) ;

  files_merging_sub_modulo_size_frame.add(files_merging_sub_modulo_size_hbox) ;

  files_merging_sub_modulo_size_frame.set_border_width(FRAME_BORDER_WIDTH) ;

  files_merging_sub_modulo_save_as_hbox.pack_start(files_merging_sub_modulo_save_as_frame, true,  true, 0) ;
  files_merging_sub_modulo_save_as_hbox.pack_start(files_merging_sub_modulo_size_frame,    true,  true, 0) ;


  files_merging_sub_modulo_output_frame.add(files_merging_sub_modulo_save_as_hbox) ;






  // sub action buttons
  Gtk::ButtonBox *buttonbox = dialog.get_action_area() ;

  buttonbox->set_layout(Gtk::BUTTONBOX_EDGE) ;
  buttonbox->set_homogeneous(true) ;

  Gtk::Button button_ok(" Save file ") ;
  Gtk::Image  image_ok(PATH_TO_BUTTON_ICONS "dialog-ok-apply.png")  ;

  button_ok.set_image(image_ok) ;
  button_ok.set_always_show_image(true) ;

  Gtk::Button button_preview(" Preview result ") ;
  Gtk::Image  image_preview(PATH_TO_BUTTON_ICONS "view-presentation.png")  ;

  button_preview.set_image(image_preview) ;
  button_preview.set_always_show_image(true) ;

  Gtk::Button button_cancel(" Close window ")  ;
  Gtk::Image  image_cancel(PATH_TO_BUTTON_ICONS "window-close.png") ;

  button_cancel.set_image(image_cancel) ;
  button_cancel.set_always_show_image(true) ;

  dialog.add_action_widget(button_cancel,  Gtk::RESPONSE_CLOSE) ;
  dialog.add_action_widget(button_preview, Gtk::RESPONSE_YES)   ;
  dialog.add_action_widget(button_ok,      Gtk::RESPONSE_APPLY) ;




  Gtk::Box *files_merging_sub_modulo_main_content_box = dialog.get_content_area() ;

  files_merging_sub_modulo_main_content_box->set_spacing(BOX_SPACING) ;

  files_merging_sub_modulo_main_content_box->pack_start(files_merging_sub_modulo_explanation_frame,    false, false, 0) ;
  files_merging_sub_modulo_main_content_box->pack_start(files_merging_sub_modulo_input_frame,          false, false, 0) ;
  files_merging_sub_modulo_main_content_box->pack_start(files_merging_sub_modulo_output_frame,         false, false, 0) ;


  files_merging_sub_modulo_input_file_1.signal_file_set().connect([&files_merging_sub_modulo_input_file_1, &input_filepath_1, &input_filepath_2, &files_merging_sub_modulo_size_width_spinbutton, &files_merging_sub_modulo_size_height_spinbutton]() {

    input_filepath_1 = files_merging_sub_modulo_input_file_1.get_filename() ;

    if (! input_filepath_2.empty()) {

      cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
      cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;


      resize_to_same_size(frame1, frame2) ;

      files_merging_sub_modulo_size_width_spinbutton.set_value(static_cast<double>(frame1.cols))  ;
      files_merging_sub_modulo_size_height_spinbutton.set_value(static_cast<double>(frame1.rows)) ;

   }

  } ) ;

  files_merging_sub_modulo_input_file_2.signal_file_set().connect([&files_merging_sub_modulo_input_file_2, &input_filepath_1, &input_filepath_2, &files_merging_sub_modulo_size_width_spinbutton, &files_merging_sub_modulo_size_height_spinbutton]() {

    input_filepath_2 = files_merging_sub_modulo_input_file_2.get_filename() ;

    if (! input_filepath_1.empty()) {

      cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
      cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;


      resize_to_same_size(frame1, frame2) ;

      files_merging_sub_modulo_size_width_spinbutton.set_value(static_cast<double>(frame1.cols))  ;
      files_merging_sub_modulo_size_height_spinbutton.set_value(static_cast<double>(frame1.rows)) ;

   }

  } ) ;


  button_preview.signal_clicked().connect([&dialog, this, &input_filepath_1, &input_filepath_2, &files_merging_sub_modulo_size_width_spinbutton, &files_merging_sub_modulo_size_height_spinbutton] () {

    if (input_filepath_1.empty() || input_filepath_2.empty()) { return ; }

    if ( ! files_merging_sub_modulo_size_width_spinbutton.get_value_as_int() || ! files_merging_sub_modulo_size_height_spinbutton.get_value_as_int() ) {

      cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
      cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;

      resize_to_same_size(frame1, frame2, cv::Size(0,0)) ;

      files_merging_sub_modulo_size_width_spinbutton.set_value(static_cast<double>(frame1.cols))  ;
      files_merging_sub_modulo_size_height_spinbutton.set_value(static_cast<double>(frame1.rows)) ;

    }

    cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
    cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;

    cv::Mat result ;

    cv::Size size(files_merging_sub_modulo_size_width_spinbutton.get_value_as_int(), files_merging_sub_modulo_size_height_spinbutton.get_value_as_int()) ;

    if (sub_modulo_images(frame1, frame2, result, size) != 0) { return ; }


    files_merging_preview_output(result) ;


  } ) ;



  files_merging_sub_modulo_save_as_label_button.signal_clicked().connect(sigc::bind<string&, Gtk::Entry&>(sigc::mem_fun(*this, &GUI::files_merging_set_output_file), output_filepath, files_merging_sub_modulo_save_as_entry) ) ;

  files_merging_sub_modulo_main_content_box->show_all() ;


  reshow_window :

  int ret = dialog.run() ;

  switch (ret) {

    case Gtk::RESPONSE_YES :

      goto reshow_window ;
 
      break ;
 
    case Gtk::RESPONSE_APPLY : {

      if ( input_filepath_1.empty() || input_filepath_2.empty() ) {
 
        const string title = "Input files failed" ;
 
        const string message = "You must set the 2 input files to merge !" ;
 
        message_dialog(title, message) ;
 
        goto reshow_window ;
      }

      if ( output_filepath.empty() ) {
 
        const string title = "Ouput file fail" ;
 
        const string message = "You must set an ouput file to save the merge result !" ;
 
        message_dialog(title, message) ;
 
        goto reshow_window ;
      }

      cv::Mat frame1 = imread(input_filepath_1, cv::IMREAD_UNCHANGED) ;
      cv::Mat frame2 = imread(input_filepath_2, cv::IMREAD_UNCHANGED) ;

      cv::Mat result ;

      cv::Size size(files_merging_sub_modulo_size_width_spinbutton.get_value_as_int(), files_merging_sub_modulo_size_height_spinbutton.get_value_as_int()) ;

      if (sub_modulo_images(frame1, frame2, result, size) != 0) {
 
        const string title = "Files merging error" ;
 
        const string message = "An error occurs by file merging !" ;
 
        message_dialog(title, message) ;
 
        break ;

      }


      if (! imwrite(output_filepath, result) ) {
   
          unlink(output_filepath.c_str()) ;
   
          const string title = "File saving error" ;

          string msg   = "Error saving file: " ;

          msg += Glib::path_get_basename(output_filepath) ;

          message_dialog(title, msg) ;

          break ;

      }

      const string title = "File merging success" ;

      string msg   = "File " ;

      msg += Glib::path_get_basename(input_filepath_1) ;

      msg += " and file " ;

      msg += Glib::path_get_basename(input_filepath_2) ;

      msg += "\n\nmerge as file: " ;

      msg += Glib::path_get_basename(output_filepath) ;

      message_dialog(title, msg) ;
   

    }

  }

  dialog.close() ;

  return ;

}

#endif