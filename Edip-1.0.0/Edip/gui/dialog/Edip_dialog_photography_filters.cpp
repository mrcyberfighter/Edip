#ifndef EDIP_PHOTOGRAPHY_FILTERS_DIALOG_HH
#define EDIP_PHOTOGRAPHY_FILTERS_DIALOG_HH

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

void GUI::pencil_sketch_filter_dialog(Controller &controller) {

  /** Configurable Pencil Sketch filter dialog window displaying. **/

  Gtk::Dialog dialog("Apply Pencil Sketch filter.", false) ;

  // Configure dialog.
  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "camera-photo.png") ;
  dialog.set_type_hint(Gdk::WINDOW_TYPE_HINT_NORMAL) ;
  dialog.set_resizable(false) ;
  dialog.set_border_width(FILTER_DIALOG_SPACE) ;
  dialog.set_modal(false) ;
  dialog.set_size_request(512-128-32-4, -1) ;

  Glib::PropertyProxy<bool> destroy_with_parent_bool = dialog.property_destroy_with_parent() ;
  destroy_with_parent_bool.set_value(true) ;

  // Positioning dialog at the top right corner
  // so that we can sea the entire image by processing.
  auto window_size = controller.get_window_size() ;
  dialog.move(window_size.first, 0) ;





  Gtk::Frame          pencil_sketch_explanation_frame("") ;

  Gtk::Box            pencil_sketch_explanation_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          pencil_sketch_explanation_frame_widget_image(PATH_TO_MENU_ICONS "applications-education-university.png") ;
  Gtk::Label          pencil_sketch_explanation_frame_widget_label(" Explanations ") ;

  Gtk::Label          pencil_sketch_explanation_label("The Pencil Sketch filter produce\n"
                                                      "a non-photorealistic line drawing image.\n") ;

  pencil_sketch_explanation_label.set_tooltip_text("Confer the joined documentation for further\n"
                                                   "informations about Pencil Sketch filter.") ;

  pencil_sketch_explanation_frame_widget_label.set_margin_left(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  pencil_sketch_explanation_frame_widget_label.set_margin_right(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  pencil_sketch_explanation_frame_widget_label.set_margin_top(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  pencil_sketch_explanation_frame_widget_label.set_margin_bottom(FILTER_DIALOG_FRAME_INNER_SPACE) ;

  pencil_sketch_explanation_frame_widget_hbox.pack_start(pencil_sketch_explanation_frame_widget_image, false, false, 0) ;
  pencil_sketch_explanation_frame_widget_hbox.pack_start(pencil_sketch_explanation_frame_widget_label, false, false, 0) ;

  pencil_sketch_explanation_frame.set_label_widget(pencil_sketch_explanation_frame_widget_hbox) ;

  pencil_sketch_explanation_label.set_margin_bottom(6) ;

  pencil_sketch_explanation_frame.add(pencil_sketch_explanation_label) ;



  Gtk::Frame          pencil_sketch_frame("") ;

  Gtk::Box            pencil_sketch_main_vbox(Gtk::ORIENTATION_VERTICAL, 0)  ;

  Gtk::Box            pencil_sketch_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          pencil_sketch_frame_widget_image(PATH_TO_MENU_ICONS "camera-photo.png") ;
  Gtk::Label          pencil_sketch_frame_widget_label(" Pencil Sketch filter ") ;

  pencil_sketch_frame_widget_hbox.pack_start(pencil_sketch_frame_widget_image, false, false, 0) ;
  pencil_sketch_frame_widget_hbox.pack_start(pencil_sketch_frame_widget_label, false, false, 0) ;

  pencil_sketch_frame.set_label_widget(pencil_sketch_frame_widget_hbox) ;

  Gtk::Label          pencil_sketch_sigma_s_label("Sigma S        ") ;

  Gtk::Label          pencil_sketch_sigma_s_padding("") ;

  Gtk::SpinButton     pencil_sketch_sigma_s_spinbutton ;

  Gtk::Box            pencil_sketch_sigma_s_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  pencil_sketch_sigma_s_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  pencil_sketch_sigma_s_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  pencil_sketch_sigma_s_spinbutton.set_digits(1) ;
  pencil_sketch_sigma_s_spinbutton.set_range(0.0, 200.00)      ;
  pencil_sketch_sigma_s_spinbutton.set_value(controller.pencil_sketch_sigma_s)      ;
  pencil_sketch_sigma_s_spinbutton.set_increments(1.0, 0.1)    ;
  pencil_sketch_sigma_s_spinbutton.set_size_request(127, -1)    ;
  pencil_sketch_sigma_s_spinbutton.set_snap_to_ticks(true)    ;
  pencil_sketch_sigma_s_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  pencil_sketch_sigma_s_spinbutton.set_adjustment( Gtk::Adjustment::create(controller.pencil_sketch_sigma_s, 0.0, 200.00, 1.0, 10.0) ) ;


  pencil_sketch_sigma_s_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  pencil_sketch_sigma_s_hbox.pack_start(pencil_sketch_sigma_s_label,      false, false, 0) ;
  pencil_sketch_sigma_s_hbox.pack_start(pencil_sketch_sigma_s_padding,    true,  true,  0) ;
  pencil_sketch_sigma_s_hbox.pack_start(pencil_sketch_sigma_s_spinbutton, false, false,  0) ;

  Gtk::Label          pencil_sketch_sigma_r_label("Sigma R        ") ;

  Gtk::Label          pencil_sketch_sigma_r_padding("") ;

  Gtk::SpinButton     pencil_sketch_sigma_r_spinbutton ;

  Gtk::Box            pencil_sketch_sigma_r_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  pencil_sketch_sigma_r_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  pencil_sketch_sigma_r_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  pencil_sketch_sigma_r_spinbutton.set_digits(2) ;
  pencil_sketch_sigma_r_spinbutton.set_range(0.01, 1.0)      ;
  pencil_sketch_sigma_r_spinbutton.set_value(controller.pencil_sketch_sigma_r)      ;
  pencil_sketch_sigma_r_spinbutton.set_increments(0.01, 0.1)    ;
  pencil_sketch_sigma_r_spinbutton.set_size_request(127, -1)    ;
  pencil_sketch_sigma_r_spinbutton.set_snap_to_ticks(true)    ;
  pencil_sketch_sigma_r_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  pencil_sketch_sigma_r_spinbutton.set_adjustment( Gtk::Adjustment::create(controller.pencil_sketch_sigma_r, 0.01, 1.0, 0.01, 0.1) ) ;


  pencil_sketch_sigma_r_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  pencil_sketch_sigma_r_hbox.pack_start(pencil_sketch_sigma_r_label,      false, false, 0) ;
  pencil_sketch_sigma_r_hbox.pack_start(pencil_sketch_sigma_r_padding,    true,  true,  0) ;
  pencil_sketch_sigma_r_hbox.pack_start(pencil_sketch_sigma_r_spinbutton, false, false,  0) ;


  Gtk::Label          pencil_sketch_shade_factor_label("Shade factor") ;

  Gtk::Label          pencil_sketch_shade_factor_padding("") ;

  Gtk::SpinButton     pencil_sketch_shade_factor_spinbutton ;

  Gtk::Box            pencil_sketch_shade_factor_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  pencil_sketch_shade_factor_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  pencil_sketch_shade_factor_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  pencil_sketch_shade_factor_spinbutton.set_digits(3) ;
  pencil_sketch_shade_factor_spinbutton.set_range(0.001, 0.0989)      ;
  pencil_sketch_shade_factor_spinbutton.set_value(controller.pencil_sketch_shade_factor)      ;
  pencil_sketch_shade_factor_spinbutton.set_increments(0.001, 0.1)    ;
  pencil_sketch_shade_factor_spinbutton.set_size_request(127, -1)    ;
  pencil_sketch_shade_factor_spinbutton.set_snap_to_ticks(true)    ;
  pencil_sketch_shade_factor_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  pencil_sketch_shade_factor_spinbutton.set_adjustment( Gtk::Adjustment::create(controller.pencil_sketch_shade_factor, 0.001, 0.0989, 0.001, 0.1) ) ;


  pencil_sketch_shade_factor_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  pencil_sketch_shade_factor_hbox.pack_start(pencil_sketch_shade_factor_label,      false, false, 0) ;
  pencil_sketch_shade_factor_hbox.pack_start(pencil_sketch_shade_factor_padding,    true,  true,  0) ;
  pencil_sketch_shade_factor_hbox.pack_start(pencil_sketch_shade_factor_spinbutton, false, false,  0) ;


  pencil_sketch_main_vbox.pack_start(pencil_sketch_sigma_s_hbox,      false, false, 0) ;
  pencil_sketch_main_vbox.pack_start(pencil_sketch_sigma_r_hbox,      false, false, 0) ;
  pencil_sketch_main_vbox.pack_start(pencil_sketch_shade_factor_hbox, false, false, 0) ;

  pencil_sketch_frame.add(pencil_sketch_main_vbox) ;



  Gtk::Frame          pencil_sketch_actions_frame("") ;

  Gtk::Box            pencil_sketch_actions_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          pencil_sketch_actions_frame_widget_image(PATH_TO_MENU_ICONS "undo-redo.png") ;
  Gtk::Label          pencil_sketch_actions_frame_widget_label(" Actions ") ;

  pencil_sketch_actions_frame_widget_hbox.pack_start(pencil_sketch_actions_frame_widget_image, false, false, 0) ;
  pencil_sketch_actions_frame_widget_hbox.pack_start(pencil_sketch_actions_frame_widget_label, false, false, 0) ;

  pencil_sketch_actions_frame.set_label_widget(pencil_sketch_actions_frame_widget_hbox) ;

  Gtk::Button         pencil_sketch_actions_undo_button(" Undo ") ;

  Gtk::Image          pencil_sketch_actions_undo_image(PATH_TO_BUTTON_ICONS "go-previous-view.png") ;

  Gtk::Box            pencil_sketch_actions_padding(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Button         pencil_sketch_actions_redo_button(" Redo ") ;

  Gtk::Image          pencil_sketch_actions_redo_image(PATH_TO_BUTTON_ICONS "go-next-view.png") ;




  Gtk::Box            pencil_sketch_actions_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  pencil_sketch_actions_undo_button.set_image(pencil_sketch_actions_undo_image) ;

  pencil_sketch_actions_undo_button.set_always_show_image(true) ;

  pencil_sketch_actions_undo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;
  pencil_sketch_actions_redo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;

  pencil_sketch_actions_redo_button.set_image(pencil_sketch_actions_redo_image) ;

  pencil_sketch_actions_redo_button.set_always_show_image(true) ;

  pencil_sketch_actions_hbox.set_spacing(FILTER_DIALOG_BOX_SPACING) ;
  pencil_sketch_actions_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;


  pencil_sketch_actions_hbox.pack_start(pencil_sketch_actions_undo_button,    false,   false, 0) ;
  pencil_sketch_actions_hbox.pack_start(pencil_sketch_actions_padding,        true,    true,  0) ;
  pencil_sketch_actions_hbox.pack_start(pencil_sketch_actions_redo_button,    false,   false, 0) ;

  pencil_sketch_actions_frame.add(pencil_sketch_actions_hbox) ;

  pencil_sketch_actions_undo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::undo_callback), controller) ) ;
  pencil_sketch_actions_redo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::redo_callback), controller) ) ;


  Gtk::Box *pencil_sketch_main_content_box = dialog.get_content_area() ;

  pencil_sketch_main_content_box->set_spacing(FILTER_DIALOG_BOX_SPACING) ;

  pencil_sketch_main_content_box->pack_start(pencil_sketch_explanation_frame,    false, false, 0) ;
  pencil_sketch_main_content_box->pack_start(pencil_sketch_frame,                false, false, 0) ;
  pencil_sketch_main_content_box->pack_start(pencil_sketch_actions_frame,        false, false, 0) ;

  // Add action buttons.
  Gtk::ButtonBox *buttonbox = dialog.get_action_area() ;

  buttonbox->set_layout(Gtk::BUTTONBOX_EDGE) ;
  buttonbox->set_homogeneous(true) ;

  Gtk::Button button_ok("Apply") ;
  Gtk::Image  image_ok(PATH_TO_BUTTON_ICONS "dialog-ok-apply.png")  ;

  button_ok.set_image(image_ok) ;
  button_ok.set_always_show_image(true) ;

  Gtk::Button button_cancel("Close")  ;
  Gtk::Image  image_cancel(PATH_TO_BUTTON_ICONS "window-close.png") ;

  button_cancel.set_image(image_cancel) ;
  button_cancel.set_always_show_image(true) ;

  dialog.add_action_widget(button_cancel, Gtk::RESPONSE_CLOSE) ;
  dialog.add_action_widget(button_ok,     Gtk::RESPONSE_APPLY) ;

  pencil_sketch_main_content_box->show_all() ;

  renew_dialog :

  int ret = dialog.run() ;

  switch (ret) {

    case Gtk::RESPONSE_APPLY : {
     
    
     
      controller.pencil_sketch_sigma_s      = pencil_sketch_sigma_s_spinbutton.get_value()      ;
      controller.pencil_sketch_sigma_r      = pencil_sketch_sigma_r_spinbutton.get_value()      ;
      controller.pencil_sketch_shade_factor = pencil_sketch_shade_factor_spinbutton.get_value() ;
    
      if ( ! controller.image_file_loaded   ) { return ; }

      cv::Mat tmp = controller.current_image_to_process.clone() ;

      cv::Mat frame ;

      // Sea libedip.
      pencil_sketch_filter(tmp, frame, static_cast<float>(controller.pencil_sketch_sigma_s), static_cast<float>(controller.pencil_sketch_sigma_r), static_cast<float>(controller.pencil_sketch_shade_factor)) ;

      // We register current frame in vector<cv::Mat> for undo-redo.
      controller.process_after_applying(frame) ;

      // It convert frame as src to RGB(A) in dst current_image_to_display.
      set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

      // Reset some variables.
      after_applying_reset_settings(controller) ;

      goto renew_dialog ;

      break ;

    }

    case Gtk::RESPONSE_CLOSE :

      break ;
  }

  dialog.close() ;

  return ;

}

void GUI::stylisation_filter_dialog(Controller &controller) {

  /** Configurable Stylisation filter dialog window displaying. **/

  Gtk::Dialog dialog("Apply Stylisation filter.", false) ;

  // Configure dialog.
  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "camera-photo.png") ;
  dialog.set_type_hint(Gdk::WINDOW_TYPE_HINT_NORMAL) ;
  dialog.set_resizable(false) ;
  dialog.set_border_width(FILTER_DIALOG_SPACE) ;
  dialog.set_modal(false) ;
  dialog.set_size_request(512-128-32-4, -1) ;

  Glib::PropertyProxy<bool> destroy_with_parent_bool = dialog.property_destroy_with_parent() ;
  destroy_with_parent_bool.set_value(true) ;

  // Positioning dialog at the top right corner
  // so that we can sea the entire image by processing.
  auto window_size = controller.get_window_size() ;
  dialog.move(window_size.first, 0) ;





  Gtk::Frame          stylisation_explanation_frame("") ;

  Gtk::Box            stylisation_explanation_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          stylisation_explanation_frame_widget_image(PATH_TO_MENU_ICONS "applications-education-university.png") ;
  Gtk::Label          stylisation_explanation_frame_widget_label(" Explanations ") ;

  Gtk::Label          stylisation_explanation_label("The stylisation filter is an edge-aware filters\n"
                                                    "which effect is not focused on photorealism but\n"
                                                    "abstract regions of low contrast while preserving,\n"
                                                    "or enhancing, high-contrast features.") ;

  stylisation_explanation_label.set_tooltip_text("Confer the joined documentation for further\n"
                                                   "informations about Stylisation filter.") ;

  stylisation_explanation_frame_widget_label.set_margin_left(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  stylisation_explanation_frame_widget_label.set_margin_right(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  stylisation_explanation_frame_widget_label.set_margin_top(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  stylisation_explanation_frame_widget_label.set_margin_bottom(FILTER_DIALOG_FRAME_INNER_SPACE) ;

  stylisation_explanation_frame_widget_hbox.pack_start(stylisation_explanation_frame_widget_image, false, false, 0) ;
  stylisation_explanation_frame_widget_hbox.pack_start(stylisation_explanation_frame_widget_label, false, false, 0) ;

  stylisation_explanation_frame.set_label_widget(stylisation_explanation_frame_widget_hbox) ;

  stylisation_explanation_label.set_margin_bottom(6) ;

  stylisation_explanation_frame.add(stylisation_explanation_label) ;



  Gtk::Frame          stylisation_frame("") ;

  Gtk::Box            stylisation_main_vbox(Gtk::ORIENTATION_VERTICAL, 0)  ;

  Gtk::Box            stylisation_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          stylisation_frame_widget_image(PATH_TO_MENU_ICONS "camera-photo.png") ;
  Gtk::Label          stylisation_frame_widget_label(" Stylisation filter ") ;

  stylisation_frame_widget_hbox.pack_start(stylisation_frame_widget_image, false, false, 0) ;
  stylisation_frame_widget_hbox.pack_start(stylisation_frame_widget_label, false, false, 0) ;

  stylisation_frame.set_label_widget(stylisation_frame_widget_hbox) ;

  Gtk::Label          stylisation_sigma_s_label("Sigma S") ;

  Gtk::Label          stylisation_sigma_s_padding("") ;

  Gtk::SpinButton     stylisation_sigma_s_spinbutton ;

  Gtk::Box            stylisation_sigma_s_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  stylisation_sigma_s_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  stylisation_sigma_s_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  stylisation_sigma_s_spinbutton.set_digits(1) ;
  stylisation_sigma_s_spinbutton.set_range(0.0, 200.00)      ;
  stylisation_sigma_s_spinbutton.set_value(controller.stylisation_sigma_s)      ;
  stylisation_sigma_s_spinbutton.set_increments(1.0, 10.0)    ;
  stylisation_sigma_s_spinbutton.set_size_request(127, -1)    ;
  stylisation_sigma_s_spinbutton.set_snap_to_ticks(true)    ;
  stylisation_sigma_s_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  stylisation_sigma_s_spinbutton.set_adjustment( Gtk::Adjustment::create(controller.stylisation_sigma_s, 0.0, 200.00, 1.0, 10.0) ) ;


  stylisation_sigma_s_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  stylisation_sigma_s_hbox.pack_start(stylisation_sigma_s_label,      false, false, 0) ;
  stylisation_sigma_s_hbox.pack_start(stylisation_sigma_s_padding,    true,  true,  0) ;
  stylisation_sigma_s_hbox.pack_start(stylisation_sigma_s_spinbutton, false, false,  0) ;


  Gtk::Label          stylisation_sigma_r_label("Sigma R") ;

  Gtk::Label          stylisation_sigma_r_padding("") ;

  Gtk::SpinButton     stylisation_sigma_r_spinbutton ;

  Gtk::Box            stylisation_sigma_r_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  stylisation_sigma_r_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  stylisation_sigma_r_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  stylisation_sigma_r_spinbutton.set_digits(2) ;
  stylisation_sigma_r_spinbutton.set_range(0.01, 1.0)      ;
  stylisation_sigma_r_spinbutton.set_value(controller.stylisation_sigma_r)      ;
  stylisation_sigma_r_spinbutton.set_increments(0.01, 0.1)    ;
  stylisation_sigma_r_spinbutton.set_size_request(127, -1)    ;
  stylisation_sigma_r_spinbutton.set_snap_to_ticks(true)    ;
  stylisation_sigma_r_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  stylisation_sigma_r_spinbutton.set_adjustment( Gtk::Adjustment::create(controller.stylisation_sigma_r, 0.01, 1.0, 0.01, 0.1) ) ;


  stylisation_sigma_r_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  stylisation_sigma_r_hbox.pack_start(stylisation_sigma_r_label,      false, false, 0) ;
  stylisation_sigma_r_hbox.pack_start(stylisation_sigma_r_padding,    true,  true,  0) ;
  stylisation_sigma_r_hbox.pack_start(stylisation_sigma_r_spinbutton, false, false,  0) ;





  stylisation_main_vbox.pack_start(stylisation_sigma_s_hbox,      false, false, 0) ;
  stylisation_main_vbox.pack_start(stylisation_sigma_r_hbox,      false, false, 0) ;

  stylisation_frame.add(stylisation_main_vbox) ;


  Gtk::Frame          stylisation_actions_frame("") ;

  Gtk::Box            stylisation_actions_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          stylisation_actions_frame_widget_image(PATH_TO_MENU_ICONS "undo-redo.png") ;
  Gtk::Label          stylisation_actions_frame_widget_label(" Actions ") ;

  stylisation_actions_frame_widget_hbox.pack_start(stylisation_actions_frame_widget_image, false, false, 0) ;
  stylisation_actions_frame_widget_hbox.pack_start(stylisation_actions_frame_widget_label, false, false, 0) ;

  stylisation_actions_frame.set_label_widget(stylisation_actions_frame_widget_hbox) ;

  Gtk::Button         stylisation_actions_undo_button(" Undo ") ;

  Gtk::Image          stylisation_actions_undo_image(PATH_TO_BUTTON_ICONS "go-previous-view.png") ;

  Gtk::Box            stylisation_actions_padding(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Button         stylisation_actions_redo_button(" Redo ") ;

  Gtk::Image          stylisation_actions_redo_image(PATH_TO_BUTTON_ICONS "go-next-view.png") ;




  Gtk::Box            stylisation_actions_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  stylisation_actions_undo_button.set_image(stylisation_actions_undo_image) ;

  stylisation_actions_undo_button.set_always_show_image(true) ;

  stylisation_actions_undo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;
  stylisation_actions_redo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;

  stylisation_actions_redo_button.set_image(stylisation_actions_redo_image) ;

  stylisation_actions_redo_button.set_always_show_image(true) ;

  stylisation_actions_hbox.set_spacing(FILTER_DIALOG_BOX_SPACING) ;
  stylisation_actions_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;


  stylisation_actions_hbox.pack_start(stylisation_actions_undo_button,    false,   false, 0) ;
  stylisation_actions_hbox.pack_start(stylisation_actions_padding,        true,    true,  0) ;
  stylisation_actions_hbox.pack_start(stylisation_actions_redo_button,    false,   false, 0) ;

  stylisation_actions_frame.add(stylisation_actions_hbox) ;

  stylisation_actions_undo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::undo_callback), controller) ) ;
  stylisation_actions_redo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::redo_callback), controller) ) ;


  Gtk::Box *stylisation_main_content_box = dialog.get_content_area() ;

  stylisation_main_content_box->set_spacing(FILTER_DIALOG_BOX_SPACING) ;

  stylisation_main_content_box->pack_start(stylisation_explanation_frame,    false, false, 0) ;
  stylisation_main_content_box->pack_start(stylisation_frame,                false, false, 0) ;
  stylisation_main_content_box->pack_start(stylisation_actions_frame,        false, false, 0) ;

  // Add action buttons.
  Gtk::ButtonBox *buttonbox = dialog.get_action_area() ;

  buttonbox->set_layout(Gtk::BUTTONBOX_EDGE) ;
  buttonbox->set_homogeneous(true) ;

  Gtk::Button button_ok("Apply") ;
  Gtk::Image  image_ok(PATH_TO_BUTTON_ICONS "dialog-ok-apply.png")  ;

  button_ok.set_image(image_ok) ;
  button_ok.set_always_show_image(true) ;

  Gtk::Button button_cancel("Close")  ;
  Gtk::Image  image_cancel(PATH_TO_BUTTON_ICONS "window-close.png") ;

  button_cancel.set_image(image_cancel) ;
  button_cancel.set_always_show_image(true) ;

  dialog.add_action_widget(button_cancel, Gtk::RESPONSE_CLOSE) ;
  dialog.add_action_widget(button_ok,     Gtk::RESPONSE_APPLY) ;

  stylisation_main_content_box->show_all() ;

  renew_dialog :

  int ret = dialog.run() ;

  switch (ret) {

    case Gtk::RESPONSE_APPLY : {

      controller.stylisation_sigma_s      = stylisation_sigma_s_spinbutton.get_value()      ;
      controller.stylisation_sigma_r      = stylisation_sigma_r_spinbutton.get_value()      ;
    
      if ( ! controller.image_file_loaded   ) { return ; }

      cv::Mat tmp = controller.current_image_to_process.clone() ;

      cv::Mat frame ;

      // Sea libedip.
      stylisation_filter(tmp, frame, static_cast<float>(controller.stylisation_sigma_s), static_cast<float>(controller.stylisation_sigma_r)) ;

      // We register current frame in vector<cv::Mat> for undo-redo.
      controller.process_after_applying(frame) ;

      // It convert frame as src to RGB(A) in dst current_image_to_display.
      set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

      // Reset some variables.
      after_applying_reset_settings(controller) ;

      goto renew_dialog ;

      break ;

    }

    case Gtk::RESPONSE_CLOSE :

      break ;
  }

  dialog.close() ;

  return ;

}

void GUI::detail_enhance_filter_dialog(Controller &controller) {

  /** Configurable Detail Enhance filter dialog window displaying. **/

  Gtk::Dialog dialog("Apply Detail Enhance filter.", false) ;


  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "camera-photo.png") ;
  dialog.set_type_hint(Gdk::WINDOW_TYPE_HINT_NORMAL) ;
  dialog.set_resizable(false) ;
  dialog.set_border_width(FILTER_DIALOG_SPACE) ;
  dialog.set_modal(false) ;
  dialog.set_size_request(512-128-32-4, -1) ;

  Glib::PropertyProxy<bool> destroy_with_parent_bool = dialog.property_destroy_with_parent() ;
  destroy_with_parent_bool.set_value(true) ;

  // Positioning dialog at the top right corner
  // so that we can sea the entire image by processing.
  auto window_size = controller.get_window_size() ;
  dialog.move(window_size.first, 0) ;





  Gtk::Frame          detail_enhance_explanation_frame("") ;

  Gtk::Box            detail_enhance_explanation_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          detail_enhance_explanation_frame_widget_image(PATH_TO_MENU_ICONS "applications-education-university.png") ;
  Gtk::Label          detail_enhance_explanation_frame_widget_label(" Explanations ") ;

  Gtk::Label          detail_enhance_explanation_label("The Detail Enhance filter enhances\n"
                                                       "the details of a particular image.") ;
                                                 

  detail_enhance_explanation_label.set_tooltip_text("Confer the joined documentation for further\n"
                                                    "informations about Detail Enhance filter.") ;

  detail_enhance_explanation_frame_widget_label.set_margin_left(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  detail_enhance_explanation_frame_widget_label.set_margin_right(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  detail_enhance_explanation_frame_widget_label.set_margin_top(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  detail_enhance_explanation_frame_widget_label.set_margin_bottom(FILTER_DIALOG_FRAME_INNER_SPACE) ;

  detail_enhance_explanation_frame_widget_hbox.pack_start(detail_enhance_explanation_frame_widget_image, false, false, 0) ;
  detail_enhance_explanation_frame_widget_hbox.pack_start(detail_enhance_explanation_frame_widget_label, false, false, 0) ;

  detail_enhance_explanation_frame.set_label_widget(detail_enhance_explanation_frame_widget_hbox) ;

  detail_enhance_explanation_label.set_margin_bottom(6) ;

  detail_enhance_explanation_frame.add(detail_enhance_explanation_label) ;



  Gtk::Frame          detail_enhance_frame("") ;

  Gtk::Box            detail_enhance_main_vbox(Gtk::ORIENTATION_VERTICAL, 0)  ;

  Gtk::Box            detail_enhance_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          detail_enhance_frame_widget_image(PATH_TO_MENU_ICONS "camera-photo.png") ;
  Gtk::Label          detail_enhance_frame_widget_label(" Detail Enhance filter ") ;

  detail_enhance_frame_widget_hbox.pack_start(detail_enhance_frame_widget_image, false, false, 0) ;
  detail_enhance_frame_widget_hbox.pack_start(detail_enhance_frame_widget_label, false, false, 0) ;

  detail_enhance_frame.set_label_widget(detail_enhance_frame_widget_hbox) ;

  Gtk::Label          detail_enhance_sigma_s_label("Sigma S") ;

  Gtk::Label          detail_enhance_sigma_s_padding("") ;

  Gtk::SpinButton     detail_enhance_sigma_s_spinbutton ;

  Gtk::Box            detail_enhance_sigma_s_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  detail_enhance_sigma_s_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  detail_enhance_sigma_s_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  detail_enhance_sigma_s_spinbutton.set_digits(1) ;
  detail_enhance_sigma_s_spinbutton.set_range(0.0, 200.00)      ;
  detail_enhance_sigma_s_spinbutton.set_value(controller.detail_enhance_sigma_s)      ;
  detail_enhance_sigma_s_spinbutton.set_increments(1.0, 10.0)    ;
  detail_enhance_sigma_s_spinbutton.set_size_request(127, -1)    ;
  detail_enhance_sigma_s_spinbutton.set_snap_to_ticks(true)    ;
  detail_enhance_sigma_s_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  detail_enhance_sigma_s_spinbutton.set_adjustment( Gtk::Adjustment::create(controller.detail_enhance_sigma_s, 0.0, 200.00, 1.0, 10.0) ) ;

  detail_enhance_sigma_s_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  detail_enhance_sigma_s_hbox.pack_start(detail_enhance_sigma_s_label,      false, false, 0) ;
  detail_enhance_sigma_s_hbox.pack_start(detail_enhance_sigma_s_padding,    true,  true,  0) ;
  detail_enhance_sigma_s_hbox.pack_start(detail_enhance_sigma_s_spinbutton, false, false,  0) ;


  Gtk::Label          detail_enhance_sigma_r_label("Sigma R") ;

  Gtk::Label          detail_enhance_sigma_r_padding("") ;

  Gtk::SpinButton     detail_enhance_sigma_r_spinbutton ;

  Gtk::Box            detail_enhance_sigma_r_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  detail_enhance_sigma_r_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  detail_enhance_sigma_r_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  detail_enhance_sigma_r_spinbutton.set_digits(2) ;
  detail_enhance_sigma_r_spinbutton.set_range(0.01, 1.0)      ;
  detail_enhance_sigma_r_spinbutton.set_value(controller.detail_enhance_sigma_r)      ;
  detail_enhance_sigma_r_spinbutton.set_increments(0.01, 0.1)    ;
  detail_enhance_sigma_r_spinbutton.set_size_request(127, -1)    ;
  detail_enhance_sigma_r_spinbutton.set_snap_to_ticks(true)    ;
  detail_enhance_sigma_r_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  detail_enhance_sigma_r_spinbutton.set_adjustment( Gtk::Adjustment::create(controller.detail_enhance_sigma_r, 0.01, 1.0, 0.01, 0.1) ) ;


  detail_enhance_sigma_r_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  detail_enhance_sigma_r_hbox.pack_start(detail_enhance_sigma_r_label,      false, false, 0) ;
  detail_enhance_sigma_r_hbox.pack_start(detail_enhance_sigma_r_padding,    true,  true,  0) ;
  detail_enhance_sigma_r_hbox.pack_start(detail_enhance_sigma_r_spinbutton, false, false,  0) ;





  detail_enhance_main_vbox.pack_start(detail_enhance_sigma_s_hbox,      false, false, 0) ;
  detail_enhance_main_vbox.pack_start(detail_enhance_sigma_r_hbox,      false, false, 0) ;

  detail_enhance_frame.add(detail_enhance_main_vbox) ;


  Gtk::Frame          detail_enhance_actions_frame("") ;

  Gtk::Box            detail_enhance_actions_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          detail_enhance_actions_frame_widget_image(PATH_TO_MENU_ICONS "undo-redo.png") ;
  Gtk::Label          detail_enhance_actions_frame_widget_label(" Actions ") ;

  detail_enhance_actions_frame_widget_hbox.pack_start(detail_enhance_actions_frame_widget_image, false, false, 0) ;
  detail_enhance_actions_frame_widget_hbox.pack_start(detail_enhance_actions_frame_widget_label, false, false, 0) ;

  detail_enhance_actions_frame.set_label_widget(detail_enhance_actions_frame_widget_hbox) ;

  Gtk::Button         detail_enhance_actions_undo_button(" Undo ") ;

  Gtk::Image          detail_enhance_actions_undo_image(PATH_TO_BUTTON_ICONS "go-previous-view.png") ;

  Gtk::Box            detail_enhance_actions_padding(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Button         detail_enhance_actions_redo_button(" Redo ") ;

  Gtk::Image          detail_enhance_actions_redo_image(PATH_TO_BUTTON_ICONS "go-next-view.png") ;




  Gtk::Box            detail_enhance_actions_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  detail_enhance_actions_undo_button.set_image(detail_enhance_actions_undo_image) ;

  detail_enhance_actions_undo_button.set_always_show_image(true) ;

  detail_enhance_actions_undo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;
  detail_enhance_actions_redo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;

  detail_enhance_actions_redo_button.set_image(detail_enhance_actions_redo_image) ;

  detail_enhance_actions_redo_button.set_always_show_image(true) ;

  detail_enhance_actions_hbox.set_spacing(FILTER_DIALOG_BOX_SPACING) ;
  detail_enhance_actions_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;


  detail_enhance_actions_hbox.pack_start(detail_enhance_actions_undo_button,    false,   false, 0) ;
  detail_enhance_actions_hbox.pack_start(detail_enhance_actions_padding,        true,    true,  0) ;
  detail_enhance_actions_hbox.pack_start(detail_enhance_actions_redo_button,    false,   false, 0) ;

  detail_enhance_actions_frame.add(detail_enhance_actions_hbox) ;

  detail_enhance_actions_undo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::undo_callback), controller) ) ;
  detail_enhance_actions_redo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::redo_callback), controller) ) ;


  Gtk::Box *detail_enhance_main_content_box = dialog.get_content_area() ;

  detail_enhance_main_content_box->set_spacing(FILTER_DIALOG_BOX_SPACING) ;

  detail_enhance_main_content_box->pack_start(detail_enhance_explanation_frame,    false, false, 0) ;
  detail_enhance_main_content_box->pack_start(detail_enhance_frame,                false, false, 0) ;
  detail_enhance_main_content_box->pack_start(detail_enhance_actions_frame,        false, false, 0) ;

  // Add action buttons.
  Gtk::ButtonBox *buttonbox = dialog.get_action_area() ;

  buttonbox->set_layout(Gtk::BUTTONBOX_EDGE) ;
  buttonbox->set_homogeneous(true) ;

  Gtk::Button button_ok("Apply") ;
  Gtk::Image  image_ok(PATH_TO_BUTTON_ICONS "dialog-ok-apply.png")  ;

  button_ok.set_image(image_ok) ;
  button_ok.set_always_show_image(true) ;

  Gtk::Button button_cancel("Close")  ;
  Gtk::Image  image_cancel(PATH_TO_BUTTON_ICONS "window-close.png") ;

  button_cancel.set_image(image_cancel) ;
  button_cancel.set_always_show_image(true) ;

  dialog.add_action_widget(button_cancel, Gtk::RESPONSE_CLOSE) ;
  dialog.add_action_widget(button_ok,     Gtk::RESPONSE_APPLY) ;

  detail_enhance_main_content_box->show_all() ;

  renew_dialog :

  int ret = dialog.run() ;

  switch (ret) {

    case Gtk::RESPONSE_APPLY : {

      controller.detail_enhance_sigma_s      = detail_enhance_sigma_s_spinbutton.get_value()      ;
      controller.detail_enhance_sigma_r      = detail_enhance_sigma_r_spinbutton.get_value()      ;
    
      if ( ! controller.image_file_loaded   ) { return ; }

      cv::Mat tmp = controller.current_image_to_process.clone() ;

      cv::Mat frame ;

      // Sea libedip.
      detail_enhance_filter(tmp, frame, static_cast<float>(controller.detail_enhance_sigma_s), static_cast<float>(controller.detail_enhance_sigma_r)) ;

      // We register current frame in vector<cv::Mat> for undo-redo.
      controller.process_after_applying(frame) ;

      // It convert frame as src to RGB(A) in dst current_image_to_display.
      set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

      // Reset some variables.
      after_applying_reset_settings(controller) ;

      goto renew_dialog ;

      break ;

    }

    case Gtk::RESPONSE_CLOSE :

      break ;
  }

  dialog.close() ;

  return ;

}

void GUI::edge_preserving_filter_dialog(Controller &controller) {

  /** Configurable Detail Preserving filter dialog window displaying. **/

  Gtk::Dialog dialog("Apply Edge Preserving filter.", false) ;

  // Configure dialog.
  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "camera-photo.png") ;
  dialog.set_type_hint(Gdk::WINDOW_TYPE_HINT_NORMAL) ;
  dialog.set_resizable(false) ;
  dialog.set_border_width(FILTER_DIALOG_SPACE) ;
  dialog.set_modal(false) ;
  dialog.set_size_request(512-128-32-4, -1) ;

  Glib::PropertyProxy<bool> destroy_with_parent_bool = dialog.property_destroy_with_parent() ;
  destroy_with_parent_bool.set_value(true) ;

  // Positioning dialog at the top right corner
  // so that we can sea the entire image by processing.
  auto window_size = controller.get_window_size() ;
  dialog.move(window_size.first, 0) ;





  Gtk::Frame          edge_preserving_explanation_frame("") ;

  Gtk::Box            edge_preserving_explanation_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          edge_preserving_explanation_frame_widget_image(PATH_TO_MENU_ICONS "applications-education-university.png") ;
  Gtk::Label          edge_preserving_explanation_frame_widget_label(" Explanations ") ;

  Gtk::Label          edge_preserving_explanation_label("The Detail Enhance filter enhances\n"
                                                        "the details of a particular image.") ;
                                               
  edge_preserving_explanation_label.set_tooltip_text("Confer the joined documentation for further\n"
                                                     "informations about Edge Preserving filter.") ;

  edge_preserving_explanation_frame_widget_label.set_margin_left(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  edge_preserving_explanation_frame_widget_label.set_margin_right(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  edge_preserving_explanation_frame_widget_label.set_margin_top(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  edge_preserving_explanation_frame_widget_label.set_margin_bottom(FILTER_DIALOG_FRAME_INNER_SPACE) ;

  edge_preserving_explanation_frame_widget_hbox.pack_start(edge_preserving_explanation_frame_widget_image, false, false, 0) ;
  edge_preserving_explanation_frame_widget_hbox.pack_start(edge_preserving_explanation_frame_widget_label, false, false, 0) ;

  edge_preserving_explanation_frame.set_label_widget(edge_preserving_explanation_frame_widget_hbox) ;

  edge_preserving_explanation_label.set_margin_bottom(6) ;

  edge_preserving_explanation_frame.add(edge_preserving_explanation_label) ;



  Gtk::Frame          edge_preserving_frame("") ;

  Gtk::Box            edge_preserving_main_vbox(Gtk::ORIENTATION_VERTICAL, 0)  ;

  Gtk::Box            edge_preserving_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          edge_preserving_frame_widget_image(PATH_TO_MENU_ICONS "camera-photo.png") ;
  Gtk::Label          edge_preserving_frame_widget_label(" Detail Enhance filter ") ;

  edge_preserving_frame_widget_hbox.pack_start(edge_preserving_frame_widget_image, false, false, 0) ;
  edge_preserving_frame_widget_hbox.pack_start(edge_preserving_frame_widget_label, false, false, 0) ;

  edge_preserving_frame.set_label_widget(edge_preserving_frame_widget_hbox) ;

  Gtk::Label          edge_preserving_filter_label("Filter") ;

  Gtk::Label          edge_preserving_filter_padding("") ;

  Gtk::ComboBoxText   edge_preserving_filter_combo ;

  Gtk::Box            edge_preserving_filter_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  edge_preserving_filter_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  edge_preserving_filter_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  edge_preserving_filter_combo.insert(0, "RECURS FILTER")         ;
  edge_preserving_filter_combo.insert(1, "NORMCONV FILTER") ;

  edge_preserving_filter_combo.set_active(controller.edge_preserving_filter) ;

  edge_preserving_filter_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  edge_preserving_filter_hbox.pack_start(edge_preserving_filter_label,   false, false, 0) ;
  edge_preserving_filter_hbox.pack_start(edge_preserving_filter_padding, true,  true,  0) ;
  edge_preserving_filter_hbox.pack_start(edge_preserving_filter_combo,   false, false, 0) ;


  Gtk::Label          edge_preserving_sigma_s_label("Sigma S") ;

  Gtk::Label          edge_preserving_sigma_s_padding("") ;

  Gtk::SpinButton     edge_preserving_sigma_s_spinbutton ;

  Gtk::Box            edge_preserving_sigma_s_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  edge_preserving_sigma_s_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  edge_preserving_sigma_s_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  edge_preserving_sigma_s_spinbutton.set_digits(1) ;
  edge_preserving_sigma_s_spinbutton.set_range(1.0, 200.00)      ;
  edge_preserving_sigma_s_spinbutton.set_value(controller.edge_preserving_sigma_s)      ;
  edge_preserving_sigma_s_spinbutton.set_increments(1.0, 10.0)    ;
  edge_preserving_sigma_s_spinbutton.set_size_request(127+32, -1)    ;
  edge_preserving_sigma_s_spinbutton.set_snap_to_ticks(true)    ;
  edge_preserving_sigma_s_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  edge_preserving_sigma_s_spinbutton.set_adjustment( Gtk::Adjustment::create(controller.edge_preserving_sigma_s, 1.0, 200.00, 1.0, 10.0) ) ;


  edge_preserving_sigma_s_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  edge_preserving_sigma_s_hbox.pack_start(edge_preserving_sigma_s_label,      false, false, 0) ;
  edge_preserving_sigma_s_hbox.pack_start(edge_preserving_sigma_s_padding,    true,  true,  0) ;
  edge_preserving_sigma_s_hbox.pack_start(edge_preserving_sigma_s_spinbutton, false, false,  0) ;


  Gtk::Label          edge_preserving_sigma_r_label("Sigma R") ;

  Gtk::Label          edge_preserving_sigma_r_padding("") ;

  Gtk::SpinButton     edge_preserving_sigma_r_spinbutton ;

  Gtk::Box            edge_preserving_sigma_r_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  edge_preserving_sigma_r_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  edge_preserving_sigma_r_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  edge_preserving_sigma_r_spinbutton.set_digits(2) ;
  edge_preserving_sigma_r_spinbutton.set_range(0.01, 1.0)      ;
  edge_preserving_sigma_r_spinbutton.set_value(controller.edge_preserving_sigma_r)      ;
  edge_preserving_sigma_r_spinbutton.set_increments(0.01, 0.1)    ;
  edge_preserving_sigma_r_spinbutton.set_size_request(127+32, -1)    ;
  edge_preserving_sigma_r_spinbutton.set_snap_to_ticks(true)    ;
  edge_preserving_sigma_r_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  edge_preserving_sigma_r_spinbutton.set_adjustment( Gtk::Adjustment::create(controller.edge_preserving_sigma_r, 0.01, 1.0, 0.01, 0.1) ) ;


  edge_preserving_sigma_r_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  edge_preserving_sigma_r_hbox.pack_start(edge_preserving_sigma_r_label,      false, false, 0) ;
  edge_preserving_sigma_r_hbox.pack_start(edge_preserving_sigma_r_padding,    true,  true,  0) ;
  edge_preserving_sigma_r_hbox.pack_start(edge_preserving_sigma_r_spinbutton, false, false,  0) ;





  edge_preserving_main_vbox.pack_start(edge_preserving_sigma_s_hbox,      false, false, 0) ;
  edge_preserving_main_vbox.pack_start(edge_preserving_sigma_r_hbox,      false, false, 0) ;
  edge_preserving_main_vbox.pack_start(edge_preserving_filter_hbox,       false, false, 0) ;

  edge_preserving_frame.add(edge_preserving_main_vbox) ;




  Gtk::Frame          edge_preserving_actions_frame("") ;

  Gtk::Box            edge_preserving_actions_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          edge_preserving_actions_frame_widget_image(PATH_TO_MENU_ICONS "undo-redo.png") ;
  Gtk::Label          edge_preserving_actions_frame_widget_label(" Actions ") ;

  edge_preserving_actions_frame_widget_hbox.pack_start(edge_preserving_actions_frame_widget_image, false, false, 0) ;
  edge_preserving_actions_frame_widget_hbox.pack_start(edge_preserving_actions_frame_widget_label, false, false, 0) ;

  edge_preserving_actions_frame.set_label_widget(edge_preserving_actions_frame_widget_hbox) ;

  Gtk::Button         edge_preserving_actions_undo_button(" Undo ") ;

  Gtk::Image          edge_preserving_actions_undo_image(PATH_TO_BUTTON_ICONS "go-previous-view.png") ;

  Gtk::Box            edge_preserving_actions_padding(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Button         edge_preserving_actions_redo_button(" Redo ") ;

  Gtk::Image          edge_preserving_actions_redo_image(PATH_TO_BUTTON_ICONS "go-next-view.png") ;




  Gtk::Box            edge_preserving_actions_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  edge_preserving_actions_undo_button.set_image(edge_preserving_actions_undo_image) ;

  edge_preserving_actions_undo_button.set_always_show_image(true) ;

  edge_preserving_actions_undo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;
  edge_preserving_actions_redo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;

  edge_preserving_actions_redo_button.set_image(edge_preserving_actions_redo_image) ;

  edge_preserving_actions_redo_button.set_always_show_image(true) ;

  edge_preserving_actions_hbox.set_spacing(FILTER_DIALOG_BOX_SPACING) ;
  edge_preserving_actions_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;


  edge_preserving_actions_hbox.pack_start(edge_preserving_actions_undo_button,    false,   false, 0) ;
  edge_preserving_actions_hbox.pack_start(edge_preserving_actions_padding,        true,    true,  0) ;
  edge_preserving_actions_hbox.pack_start(edge_preserving_actions_redo_button,    false,   false, 0) ;

  edge_preserving_actions_frame.add(edge_preserving_actions_hbox) ;

  edge_preserving_actions_undo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::undo_callback), controller) ) ;
  edge_preserving_actions_redo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::redo_callback), controller) ) ;

  Gtk::Box *edge_preserving_main_content_box = dialog.get_content_area() ;

  edge_preserving_main_content_box->set_spacing(FILTER_DIALOG_BOX_SPACING) ;

  edge_preserving_main_content_box->pack_start(edge_preserving_explanation_frame,    false, false, 0) ;
  edge_preserving_main_content_box->pack_start(edge_preserving_frame,                false, false, 0) ;
  edge_preserving_main_content_box->pack_start(edge_preserving_actions_frame,        false, false, 0) ;

  // Add action buttons.
  Gtk::ButtonBox *buttonbox = dialog.get_action_area() ;

  buttonbox->set_layout(Gtk::BUTTONBOX_EDGE) ;
  buttonbox->set_homogeneous(true) ;

  Gtk::Button button_ok("Apply") ;
  Gtk::Image  image_ok(PATH_TO_BUTTON_ICONS "dialog-ok-apply.png")  ;

  button_ok.set_image(image_ok) ;
  button_ok.set_always_show_image(true) ;

  Gtk::Button button_cancel("Close")  ;
  Gtk::Image  image_cancel(PATH_TO_BUTTON_ICONS "window-close.png") ;

  button_cancel.set_image(image_cancel) ;
  button_cancel.set_always_show_image(true) ;

  dialog.add_action_widget(button_cancel, Gtk::RESPONSE_CLOSE) ;
  dialog.add_action_widget(button_ok,     Gtk::RESPONSE_APPLY) ;

  edge_preserving_main_content_box->show_all() ;

  renew_dialog :

  int ret = dialog.run() ;

  switch (ret) {

    case Gtk::RESPONSE_APPLY : {

      controller.edge_preserving_sigma_s      = edge_preserving_sigma_s_spinbutton.get_value()       ;
      controller.edge_preserving_sigma_r      = edge_preserving_sigma_r_spinbutton.get_value()       ;
      controller.edge_preserving_filter       = edge_preserving_filter_combo.get_active_row_number() ;
    
      if ( ! controller.image_file_loaded   ) { return ; }
    
      cv::Mat tmp = controller.current_image_to_process.clone() ;

      cv::Mat frame ;

      // Sea libedip.
      edge_preserving_filter(tmp, frame, static_cast<float>(controller.edge_preserving_sigma_s), static_cast<float>(controller.edge_preserving_sigma_r), controller.edge_preserving_filter + 1 ) ;

      // We register current frame in vector<cv::Mat> for undo-redo.
      controller.process_after_applying(frame) ;

      // It convert frame as src to RGB(A) in dst current_image_to_display.
      set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

      // Reset some variables.
      after_applying_reset_settings(controller) ;

      goto renew_dialog ;

      break ;

    }

    case Gtk::RESPONSE_CLOSE :

      break ;
  }

  dialog.close() ;

  return ;

}

void GUI::denoising_filter_dialog(Controller &controller) {

  /** Configurable Denoising filter dialog window displaying. **/

  Gtk::Dialog dialog("Apply Denoising filter.", false) ;

  // Configure dialog.
  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "camera-photo.png") ;
  dialog.set_type_hint(Gdk::WINDOW_TYPE_HINT_NORMAL) ;
  dialog.set_resizable(false) ;
  dialog.set_border_width(FILTER_DIALOG_SPACE) ;
  dialog.set_modal(false) ;
  dialog.set_size_request(512-128-32-4, -1) ;


  Glib::PropertyProxy<bool> destroy_with_parent_bool = dialog.property_destroy_with_parent() ;
  destroy_with_parent_bool.set_value(true) ;

  // Positioning dialog at the top right corner
  // so that we can sea the entire image by processing.
  auto window_size = controller.get_window_size() ;
  dialog.move(window_size.first, 0) ;





  Gtk::Frame          denoising_explanation_frame("") ;

  Gtk::Box            denoising_explanation_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          denoising_explanation_frame_widget_image(PATH_TO_MENU_ICONS "applications-education-university.png") ;
  Gtk::Label          denoising_explanation_frame_widget_label(" Explanations ") ;

  Gtk::Label          denoising_explanation_label("The denoising filter perform image denoising using\nNon-local Means Denoising\nwith several computational optimizations.\n"
                                                  "Noise expected to be a gaussian white noise.\n"
                                                  "Denoising is done by converting image\nto CIELAB colorspace\nand then separately denoise L and AB\ncomponents with different luminance parameters.") ;
                                                 

  denoising_explanation_label.set_tooltip_text("Confer the joined documentation for further\n"
                                               "informations about Denoising filter.") ;

  denoising_explanation_frame_widget_label.set_margin_left(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  denoising_explanation_frame_widget_label.set_margin_right(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  denoising_explanation_frame_widget_label.set_margin_top(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  denoising_explanation_frame_widget_label.set_margin_bottom(FILTER_DIALOG_FRAME_INNER_SPACE) ;

  denoising_explanation_frame_widget_hbox.pack_start(denoising_explanation_frame_widget_image, false, false, 0) ;
  denoising_explanation_frame_widget_hbox.pack_start(denoising_explanation_frame_widget_label, false, false, 0) ;

  denoising_explanation_frame.set_label_widget(denoising_explanation_frame_widget_hbox) ;

  denoising_explanation_label.set_margin_bottom(6) ;

  denoising_explanation_frame.add(denoising_explanation_label) ;



  Gtk::Frame          denoising_frame("") ;

  Gtk::Box            denoising_main_vbox(Gtk::ORIENTATION_VERTICAL, 0)  ;

  Gtk::Box            denoising_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          denoising_frame_widget_image(PATH_TO_MENU_ICONS "camera-photo.png") ;
  Gtk::Label          denoising_frame_widget_label(" Detail Enhance filter ") ;

  denoising_frame_widget_hbox.pack_start(denoising_frame_widget_image, false, false, 0) ;
  denoising_frame_widget_hbox.pack_start(denoising_frame_widget_label, false, false, 0) ;

  denoising_frame.set_label_widget(denoising_frame_widget_hbox) ;

  Gtk::Label          denoising_luminance_label("Luminance factor") ;

  Gtk::Label          denoising_luminance_padding("") ;

  Gtk::SpinButton     denoising_luminance_spinbutton ;

  Gtk::Box            denoising_luminance_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  denoising_luminance_hbox.set_tooltip_text("Bigger values remove more noise but also remove image details.\nSmaller values preserve details but also preserve noise.") ;

  denoising_luminance_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  denoising_luminance_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  denoising_luminance_spinbutton.set_digits(0) ;
  denoising_luminance_spinbutton.set_range(1.0, 200.00)      ;
  denoising_luminance_spinbutton.set_value(controller.denoising_luminance)      ;
  denoising_luminance_spinbutton.set_increments(1.0, 10.0)    ;
  denoising_luminance_spinbutton.set_size_request(127-32, -1)    ;
  denoising_luminance_spinbutton.set_snap_to_ticks(true)    ;
  denoising_luminance_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  denoising_luminance_spinbutton.set_adjustment( Gtk::Adjustment::create(controller.denoising_luminance, 1.0, 200.00, 1.0, 10.0) ) ;

  denoising_luminance_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  denoising_luminance_hbox.pack_start(denoising_luminance_label,      false, false, 0) ;
  denoising_luminance_hbox.pack_start(denoising_luminance_padding,    true,  true,  0) ;
  denoising_luminance_hbox.pack_start(denoising_luminance_spinbutton, false, false,  0) ;



  Gtk::Label          denoising_colors_label("Colors denoising factor") ;

  Gtk::Label          denoising_colors_padding("") ;

  Gtk::SpinButton     denoising_colors_spinbutton ;

  Gtk::Box            denoising_colors_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  denoising_colors_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  denoising_colors_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  denoising_colors_spinbutton.set_digits(0) ;
  denoising_colors_spinbutton.set_range(1.0, 200.00)      ;
  denoising_colors_spinbutton.set_value(controller.denoising_colors)      ;
  denoising_colors_spinbutton.set_increments(1.0, 10.0)    ;
  denoising_colors_spinbutton.set_size_request(127-32, -1)    ;
  denoising_colors_spinbutton.set_snap_to_ticks(true)    ;
  denoising_colors_spinbutton.set_adjustment( Gtk::Adjustment::create(controller.denoising_colors, 1.0, 200.00, 1.0, 10.0) ) ;


  denoising_colors_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  denoising_colors_hbox.pack_start(denoising_colors_label,      false, false, 0) ;
  denoising_colors_hbox.pack_start(denoising_colors_padding,    true,  true,  0) ;
  denoising_colors_hbox.pack_start(denoising_colors_spinbutton, false, false,  0) ;






  denoising_main_vbox.pack_start(denoising_luminance_hbox,    false, false, 0) ;
  denoising_main_vbox.pack_start(denoising_colors_hbox,       false, false, 0) ;

  denoising_frame.add(denoising_main_vbox) ;


  Gtk::Frame          denoising_actions_frame("") ;

  Gtk::Box            denoising_actions_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          denoising_actions_frame_widget_image(PATH_TO_MENU_ICONS "undo-redo.png") ;
  Gtk::Label          denoising_actions_frame_widget_label(" Actions ") ;

  denoising_actions_frame_widget_hbox.pack_start(denoising_actions_frame_widget_image, false, false, 0) ;
  denoising_actions_frame_widget_hbox.pack_start(denoising_actions_frame_widget_label, false, false, 0) ;

  denoising_actions_frame.set_label_widget(denoising_actions_frame_widget_hbox) ;

  Gtk::Button         denoising_actions_undo_button(" Undo ") ;

  Gtk::Image          denoising_actions_undo_image(PATH_TO_BUTTON_ICONS "go-previous-view.png") ;

  Gtk::Box            denoising_actions_padding(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Button         denoising_actions_redo_button(" Redo ") ;

  Gtk::Image          denoising_actions_redo_image(PATH_TO_BUTTON_ICONS "go-next-view.png") ;




  Gtk::Box            denoising_actions_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  denoising_actions_undo_button.set_image(denoising_actions_undo_image) ;

  denoising_actions_undo_button.set_always_show_image(true) ;

  denoising_actions_undo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;
  denoising_actions_redo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;

  denoising_actions_redo_button.set_image(denoising_actions_redo_image) ;

  denoising_actions_redo_button.set_always_show_image(true) ;

  denoising_actions_hbox.set_spacing(FILTER_DIALOG_BOX_SPACING) ;
  denoising_actions_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;


  denoising_actions_hbox.pack_start(denoising_actions_undo_button,    false,   false, 0) ;
  denoising_actions_hbox.pack_start(denoising_actions_padding,        true,    true,  0) ;
  denoising_actions_hbox.pack_start(denoising_actions_redo_button,    false,   false, 0) ;

  denoising_actions_frame.add(denoising_actions_hbox) ;

  denoising_actions_undo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::undo_callback), controller) ) ;
  denoising_actions_redo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::redo_callback), controller) ) ;

  Gtk::Box *denoising_main_content_box = dialog.get_content_area() ;

  denoising_main_content_box->set_spacing(FILTER_DIALOG_BOX_SPACING) ;

  denoising_main_content_box->pack_start(denoising_explanation_frame,    false, false, 0) ;
  denoising_main_content_box->pack_start(denoising_frame,                false, false, 0) ;



  Gtk::ButtonBox *buttonbox = dialog.get_action_area() ;

  buttonbox->set_layout(Gtk::BUTTONBOX_EDGE) ;
  buttonbox->set_homogeneous(true) ;

  Gtk::Button button_ok("Apply") ;
  Gtk::Image  image_ok(PATH_TO_BUTTON_ICONS "dialog-ok-apply.png")  ;

  button_ok.set_image(image_ok) ;
  button_ok.set_always_show_image(true) ;

  Gtk::Button button_cancel("Close")  ;
  Gtk::Image  image_cancel(PATH_TO_BUTTON_ICONS "window-close.png") ;

  button_cancel.set_image(image_cancel) ;
  button_cancel.set_always_show_image(true) ;

  dialog.add_action_widget(button_cancel, Gtk::RESPONSE_CLOSE) ;
  dialog.add_action_widget(button_ok,     Gtk::RESPONSE_APPLY) ;

  denoising_main_content_box->show_all() ;

  renew_dialog :

  int ret = dialog.run() ;

  switch (ret) {

    case Gtk::RESPONSE_APPLY : {

      controller.denoising_luminance       = denoising_luminance_spinbutton.get_value()    ;
      controller.denoising_colors          = denoising_colors_spinbutton.get_value()       ;
    
      if ( ! controller.image_file_loaded   ) { return ; }
    
      cv::Mat tmp = controller.current_image_to_process.clone() ;

      cv::Mat frame ;

      // Sea libedip.
      denoising_filter(tmp, frame, static_cast<float>(controller.denoising_luminance), static_cast<float>(controller.denoising_colors)) ;

      // We register current frame in vector<cv::Mat> for undo-redo.
      controller.process_after_applying(frame) ;

      // It convert frame as src to RGB(A) in dst current_image_to_display.
      set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

      // Reset some variables.
      after_applying_reset_settings(controller) ;

      goto renew_dialog ;

      break ;

    }

    case Gtk::RESPONSE_CLOSE :

      break ;
  }

  dialog.close() ;

  return ;

}

#endif