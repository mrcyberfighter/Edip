#ifndef EDIP_OTHER_FILTERS_DIALOG_HH
#define EDIP_OTHER_FILTERS_DIALOG_HH

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


void GUI::morphological_filter_dialog(Controller &controller) {

  /** Morphological configurable filter dialog window displaying. **/

  Gtk::Dialog dialog("Apply morphological filter.", false) ;

  // Configure dialog:
  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "weather-clear-night.png") ;
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





  Gtk::Frame          morphological_explanation_frame("") ;

  Gtk::Box            morphological_explanation_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          morphological_explanation_frame_widget_image(PATH_TO_MENU_ICONS "applications-education-university.png") ;
  Gtk::Label          morphological_explanation_frame_widget_label(" Explanations ") ;

  Gtk::Label          morphological_explanation_label("Mathematical morphological filters transform\n"
                                                      "an image by probing it with a predefined\n"
                                                      "shape element, called kernel.\n"
                                                      "The way this shape intersects the neighborhood\n"
                                                      "of a pixel determine the result of the differents\n"
                                                      "possible morphological operators.") ;

  morphological_explanation_label.set_tooltip_text("Confer the joined documentation for further\n"
                                                   "informations about morphological operators."  ) ;

  morphological_explanation_frame_widget_label.set_margin_left(FILTER_DIALOG_FRAME_INNER_SPACE)   ;
  morphological_explanation_frame_widget_label.set_margin_right(FILTER_DIALOG_FRAME_INNER_SPACE)  ;
  morphological_explanation_frame_widget_label.set_margin_top(FILTER_DIALOG_FRAME_INNER_SPACE)    ;
  morphological_explanation_frame_widget_label.set_margin_bottom(FILTER_DIALOG_FRAME_INNER_SPACE) ;

  morphological_explanation_frame_widget_hbox.pack_start(morphological_explanation_frame_widget_image, false, false, 0) ;
  morphological_explanation_frame_widget_hbox.pack_start(morphological_explanation_frame_widget_label, false, false, 0) ;

  morphological_explanation_frame.set_label_widget(morphological_explanation_frame_widget_hbox) ;

  morphological_explanation_label.set_margin_bottom(6) ;

  morphological_explanation_frame.add(morphological_explanation_label) ;



  Gtk::Frame          morphological_kernel_frame("") ;

  Gtk::Box            morphological_kernel_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          morphological_kernel_frame_widget_image(PATH_TO_MENU_ICONS "transform-move.png") ;
  Gtk::Label          morphological_kernel_frame_widget_label(" Kernel ") ;

  morphological_kernel_frame_widget_hbox.pack_start(morphological_kernel_frame_widget_image, false, false, 0) ;
  morphological_kernel_frame_widget_hbox.pack_start(morphological_kernel_frame_widget_label, false, false, 0) ;

  morphological_kernel_frame.set_label_widget(morphological_kernel_frame_widget_hbox) ;



  Gtk::Box            morphological_kernel_main_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;

  morphological_kernel_main_vbox.set_spacing(FILTER_DIALOG_BOX_SPACING) ;



  Gtk::Label          morphological_kernel_type_label("Kernel type") ;

  Gtk::Label          morphological_padding_01("") ;

  Gtk::ComboBoxText   morphological_kernel_type_combo ;

  Gtk::Box            morphological_kernel_hbox_01(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  morphological_kernel_type_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  morphological_kernel_type_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  morphological_kernel_type_combo.insert(0, "Square") ;
  morphological_kernel_type_combo.insert(1, "Diamond") ;
  morphological_kernel_type_combo.insert(2, "Cross") ;
  morphological_kernel_type_combo.insert(3, "X") ;

  morphological_kernel_type_combo.set_active(controller.morphological_kernel_type) ;

  morphological_kernel_hbox_01.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  morphological_kernel_hbox_01.pack_start(morphological_kernel_type_label, false, false, 0) ;
  morphological_kernel_hbox_01.pack_start(morphological_padding_01,        true,  true,  0) ;
  morphological_kernel_hbox_01.pack_start(morphological_kernel_type_combo, true,  true,  0) ;



  Gtk::Label          morphological_kernel_ksize_label("Kernel size") ;

  Gtk::Label          morphological_padding_02("") ;

  Gtk::SpinButton     morphological_kernel_ksize_spinbutton(Gtk::ORIENTATION_HORIZONTAL) ;

  Gtk::Box            morphological_kernel_hbox_02(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  morphological_kernel_ksize_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  morphological_kernel_ksize_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  morphological_kernel_ksize_spinbutton.set_digits(0) ;
  morphological_kernel_ksize_spinbutton.set_range(3.0, 31.0)      ;
  morphological_kernel_ksize_spinbutton.set_value(controller.morphological_kernel_size)      ;
  morphological_kernel_ksize_spinbutton.set_increments(2.0, 4.0)    ;
  morphological_kernel_ksize_spinbutton.set_size_request(127-64, -1)    ;
  morphological_kernel_ksize_spinbutton.set_snap_to_ticks(true)    ;
  morphological_kernel_ksize_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  morphological_kernel_ksize_spinbutton.set_adjustment( Gtk::Adjustment::create(controller.morphological_kernel_size, 3.0, 31.0, 2.0, 4.0) ) ;


  morphological_kernel_hbox_02.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  morphological_kernel_hbox_02.pack_start(morphological_kernel_ksize_label,      false, false, 0) ;
  morphological_kernel_hbox_02.pack_start(morphological_padding_02,              true,  true,  0) ;
  morphological_kernel_hbox_02.pack_start(morphological_kernel_ksize_spinbutton, false,  false,  0) ;



  Gtk::Box            morphological_kernel_hbox_03(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Label          morphological_kernel_sum_label("Center value            ")   ;

  Gtk::Label          morphological_padding_03("") ;

  Gtk::ComboBoxText   morphological_kernel_sum_combo ;

  morphological_kernel_sum_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  morphological_kernel_sum_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  morphological_kernel_sum_combo.insert(0, "Set to 1")         ;
  morphological_kernel_sum_combo.insert(1, "Set weight to +1") ;
  morphological_kernel_sum_combo.insert(2, "Set weight to  0") ;
  morphological_kernel_sum_combo.insert(3, "Set weight to -1") ;

  morphological_kernel_sum_combo.set_active(controller.morphological_center_value) ;

  morphological_kernel_hbox_03.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  morphological_kernel_hbox_03.pack_start(morphological_kernel_sum_label, false, false, 0) ;
  morphological_kernel_hbox_03.pack_start(morphological_padding_03,       true,  true,  0) ;
  morphological_kernel_hbox_03.pack_start(morphological_kernel_sum_combo, true,  true,  0) ;



  Gtk::Box            morphological_kernel_hbox_04(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Label          morphological_padding_04("") ;

  Gtk::Image          morphological_kernel_display_image(PATH_TO_BUTTON_ICONS "transform-move.png") ;

  Gtk::Button         morphological_kernel_display_button("   Preview kernel    ") ;

  morphological_kernel_display_button.set_image(morphological_kernel_display_image) ;

  morphological_kernel_display_button.set_always_show_image(true) ;


  morphological_kernel_hbox_04.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  morphological_kernel_hbox_04.pack_start(morphological_padding_04,            true,  true,  0) ;
  morphological_kernel_hbox_04.pack_start(morphological_kernel_display_button, false, false, 0) ;


  morphological_kernel_main_vbox.pack_start(morphological_kernel_hbox_01, false, false, 0) ;
  morphological_kernel_main_vbox.pack_start(morphological_kernel_hbox_02, false, false, 0) ;
  morphological_kernel_main_vbox.pack_start(morphological_kernel_hbox_03, false, false, 0) ;
  morphological_kernel_main_vbox.pack_start(morphological_kernel_hbox_04, false, false, 0) ;

  morphological_kernel_frame.add(morphological_kernel_main_vbox) ;





  Gtk::Frame          morphological_operation_frame("") ;

  Gtk::Box            morphological_operation_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          morphological_operation_frame_widget_image(PATH_TO_MENU_ICONS "configure.png") ;
  Gtk::Label          morphological_operation_frame_widget_label(" Morphological Operation ") ;

  morphological_operation_frame_widget_hbox.pack_start(morphological_operation_frame_widget_image, false, false, 0) ;
  morphological_operation_frame_widget_hbox.pack_start(morphological_operation_frame_widget_label, false, false, 0) ;

  morphological_operation_frame.set_label_widget(morphological_operation_frame_widget_hbox) ;

  morphological_operation_frame.set_tooltip_text("+) Erode:     use a little kernel size and or a little iterations value.\n"
                                                 "+) Dilate:     use a little kernel size and or a little iterations value.\n"
                                                 "+) Open:      use a little kernel size and or a little iterations value.\n"
                                                 "+) Close:      use a little kernel size and or a little iterations value.\n"
                                                 "+) Top hat:   use a medium or big kernel size or a great iterations value.\n"
                                                 "+) Black hat: use a medium or big kernel size or a great iterations value.") ;

  Gtk::Box            morphological_operation_main_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;

  Gtk::Box            morphological_operation_hbox_01(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Label          morphological_operation_type_label("Operator type") ;

  Gtk::Label          morphological_padding_05("") ;

  Gtk::ComboBoxText   morphological_operation_type_combo      ;

  morphological_operation_main_vbox.set_spacing(FILTER_DIALOG_BOX_SPACING) ;

  morphological_operation_type_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  morphological_operation_type_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  morphological_operation_type_combo.insert(0, "Erode") ;
  morphological_operation_type_combo.insert(1, "Dilate") ;
  morphological_operation_type_combo.insert(2, "Open") ;
  morphological_operation_type_combo.insert(3, "Close") ;
  morphological_operation_type_combo.insert(4, "Top hat") ;
  morphological_operation_type_combo.insert(5, "Black hat") ;

  morphological_operation_type_combo.set_active(controller.morphological_operator_type) ;

  morphological_operation_hbox_01.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  morphological_operation_hbox_01.pack_start(morphological_operation_type_label, false, false, 0) ;
  morphological_operation_hbox_01.pack_start(morphological_padding_05,           true,  true,  0) ;
  morphological_operation_hbox_01.pack_start(morphological_operation_type_combo, true,  true, 0) ;



  Gtk::Box            morphological_operation_hbox_02(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Label          morphological_operation_iterations_label("Operation iterations") ;

  Gtk::Label          morphological_padding_06("") ;

  Gtk::Scale          morphological_operation_iterations_scale(Gtk::ORIENTATION_HORIZONTAL)      ;

  morphological_operation_iterations_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  morphological_operation_iterations_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  morphological_operation_iterations_scale.set_digits(0) ;
  morphological_operation_iterations_scale.set_draw_value(true) ;
  morphological_operation_iterations_scale.set_has_origin(true) ;
  morphological_operation_iterations_scale.set_upper_stepper_sensitivity(Gtk::SENSITIVITY_ON) ;
  morphological_operation_iterations_scale.set_lower_stepper_sensitivity(Gtk::SENSITIVITY_ON) ;
  morphological_operation_iterations_scale.set_adjustment( morphological_operation_iterations_scale.get_adjustment() )     ;
  morphological_operation_iterations_scale.set_range(1.0, 32.0)      ;
  morphological_operation_iterations_scale.set_value(controller.morphological_iterations)      ;
  morphological_operation_iterations_scale.set_increments(1.0, 10.0)    ;
  morphological_operation_iterations_scale.set_size_request(127, -1)    ;
  morphological_operation_iterations_scale.add_mark(1.0, Gtk::POS_TOP, "")      ;

  morphological_operation_hbox_02.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  morphological_operation_hbox_02.pack_start(morphological_operation_iterations_label, false, false, 0) ;
  morphological_operation_hbox_02.pack_start(morphological_padding_06,                 true,  true,  0) ;
  morphological_operation_hbox_02.pack_start(morphological_operation_iterations_scale, true,  true,  0) ;

  morphological_operation_main_vbox.pack_start(morphological_operation_hbox_01, false, false, 0) ;
  morphological_operation_main_vbox.pack_start(morphological_operation_hbox_02, false, false, 0) ;

  morphological_operation_frame.add(morphological_operation_main_vbox) ;



  Gtk::Frame          morphological_actions_frame("") ;

  Gtk::Box            morphological_actions_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          morphological_actions_frame_widget_image(PATH_TO_MENU_ICONS "undo-redo.png") ;
  Gtk::Label          morphological_actions_frame_widget_label(" Actions ") ;

  morphological_actions_frame_widget_hbox.pack_start(morphological_actions_frame_widget_image, false, false, 0) ;
  morphological_actions_frame_widget_hbox.pack_start(morphological_actions_frame_widget_label, false, false, 0) ;

  morphological_actions_frame.set_label_widget(morphological_actions_frame_widget_hbox) ;


  Gtk::Button         morphological_actions_undo_button(" Undo ") ;

  Gtk::Image          morphological_actions_undo_image(PATH_TO_BUTTON_ICONS "go-previous-view.png") ;

  Gtk::Box            morphological_actions_padding(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Button         morphological_actions_redo_button(" Redo ") ;

  Gtk::Image          morphological_actions_redo_image(PATH_TO_BUTTON_ICONS "go-next-view.png") ;




  Gtk::Box            morphological_actions_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  morphological_actions_undo_button.set_image(morphological_actions_undo_image) ;

  morphological_actions_undo_button.set_always_show_image(true) ;

  morphological_actions_undo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;
  morphological_actions_redo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;

  morphological_actions_redo_button.set_image(morphological_actions_redo_image) ;

  morphological_actions_redo_button.set_always_show_image(true) ;

  morphological_actions_hbox.set_spacing(FILTER_DIALOG_BOX_SPACING) ;
  morphological_actions_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;


  morphological_actions_hbox.pack_start(morphological_actions_undo_button,    false,   false, 0) ;
  morphological_actions_hbox.pack_start(morphological_actions_padding,        true,    true,  0) ;
  morphological_actions_hbox.pack_start(morphological_actions_redo_button,    false,   false, 0) ;

  morphological_actions_frame.add(morphological_actions_hbox) ;

  morphological_actions_undo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::undo_callback), controller) ) ;
  morphological_actions_redo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::redo_callback), controller) ) ;


  Gtk::Box *morphological_main_content_box = dialog.get_content_area() ;

  morphological_main_content_box->set_spacing(FILTER_DIALOG_BOX_SPACING) ;

  morphological_main_content_box->pack_start(morphological_explanation_frame,    false, false, 0) ;
  morphological_main_content_box->pack_start(morphological_kernel_frame,         false, false, 0) ;
  morphological_main_content_box->pack_start(morphological_operation_frame,      false, false, 0) ;
  morphological_main_content_box->pack_start(morphological_actions_frame,        false, false, 0) ;

  // Add action buttons
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

  dialog.add_action_widget(button_cancel, Gtk::RESPONSE_CLOSE)    ;
  dialog.add_action_widget(button_ok,     Gtk::RESPONSE_APPLY)    ;

  // Display kernel button callback.
  morphological_kernel_display_button.signal_clicked().connect([&morphological_kernel_type_combo, &morphological_kernel_ksize_spinbutton, &morphological_kernel_sum_combo, this] () {

    string kernel_type ;

    switch (morphological_kernel_type_combo.get_active_row_number()) {

      case 0 :

        kernel_type = "rect" ;
        break ;

      case 1 :

        kernel_type = "diamond" ;
        break ;

      case 2 :

        kernel_type = "cross" ;
        break ;

      case 3 :

        kernel_type = "X" ;
        break ;


      #ifdef DEBUG
      default :
        // This cannot append due of the GUI interfacing.

        fprintf(stderr,"Cannot identify kernel type !!!\n") ;
        return ;

     #endif
    }

    char center_value ;

    switch ( morphological_kernel_sum_combo.get_active_row_number() ) {

      case 0 :

        center_value = '1' ;
        break ;

     case 1 :

       center_value = '0' ;
       break ;

     case 2 :

       center_value = '+' ;
       break ;

     case 3 :

       center_value = '-' ;
       break ;

      #ifdef DEBUG
      default :
        // This cannot append due of the GUI interfacing.

       fprintf(stderr,"Cannot identify center value !!!\n") ;
       return ;

      #endif
    }

    // Sea the libedip.
    cv::Mat kernel = make_kernel(kernel_type, static_cast<int>(morphological_kernel_ksize_spinbutton.get_value()), center_value) ;

    this->display_kernel(kernel) ;

  } ) ;


  morphological_main_content_box->show_all() ;

  renew_dialog :

  int ret = dialog.run() ;

  switch (ret) {

    case Gtk::RESPONSE_APPLY :

      controller.morphological_kernel_type   = morphological_kernel_type_combo.get_active_row_number()      ;
      controller.morphological_kernel_size   = morphological_kernel_ksize_spinbutton.get_value()            ;
      controller.morphological_center_value  = morphological_kernel_sum_combo.get_active_row_number()       ;
      controller.morphological_operator_type = morphological_operation_type_combo.get_active_row_number()   ;
      controller.morphological_iterations    = morphological_operation_iterations_scale.get_value()         ;

      morphological_callback(controller) ;

      goto renew_dialog ;

      break ;

    case Gtk::RESPONSE_CLOSE :

      dialog.close() ;

      break ;
  }

  dialog.close() ;

  return ;

}





void GUI::canny_filter_dialog(Controller &controller) {

  /** Configurable Canny operator filter dialog window displaying. **/

  Gtk::Dialog dialog("Apply canny filter.", false) ;

  // Configure dialog:
  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "image-missing.png") ;
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





  Gtk::Frame          canny_explanation_frame("") ;

  Gtk::Box            canny_explanation_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          canny_explanation_frame_widget_image(PATH_TO_MENU_ICONS "applications-education-university.png") ;
  Gtk::Label          canny_explanation_frame_widget_label(" Explanations ") ;

  Gtk::Label          canny_explanation_label("This filter finds edges in the input image\n"
                                              "and marks them in the output map edges\n"
                                              "using the Canny algorithm.\n"
                                              "Since the Canny operator produce a binary image\n"
                                              "(a black an white image),\n"
                                              "the canny ouput can be inverted.") ;
                                    

  canny_explanation_label.set_tooltip_text("Confer the joined documentation for further\n"
                                           "informations about the Canny operators.") ;

  canny_explanation_frame_widget_label.set_margin_left(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  canny_explanation_frame_widget_label.set_margin_right(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  canny_explanation_frame_widget_label.set_margin_top(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  canny_explanation_frame_widget_label.set_margin_bottom(FILTER_DIALOG_FRAME_INNER_SPACE) ;

  canny_explanation_frame_widget_hbox.pack_start(canny_explanation_frame_widget_image, false, false, 0) ;
  canny_explanation_frame_widget_hbox.pack_start(canny_explanation_frame_widget_label, false, false, 0) ;

  canny_explanation_frame.set_label_widget(canny_explanation_frame_widget_hbox) ;

  canny_explanation_label.set_margin_bottom(6) ;

  canny_explanation_frame.add(canny_explanation_label) ;



  Gtk::Frame          canny_frame("") ;

  Gtk::Box            canny_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          canny_frame_widget_image(PATH_TO_MENU_ICONS "image-missing.png") ;
  Gtk::Label          canny_frame_widget_label(" Multiply color channels ") ;

  canny_frame_widget_hbox.pack_start(canny_frame_widget_image, false, false, 0) ;
  canny_frame_widget_hbox.pack_start(canny_frame_widget_label, false, false, 0) ;

  canny_frame.set_label_widget(canny_frame_widget_hbox) ;



  Gtk::Box            canny_main_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;

  canny_main_vbox.set_spacing(FILTER_DIALOG_BOX_SPACING) ;



  Gtk::Label          canny_min_threshold_label("Canny minimal threshold") ;

  Gtk::Label          canny_min_threshold_padding("") ;

  Gtk::SpinButton     canny_min_threshold_spinbutton ;

  Gtk::Box            canny_min_threshold_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  canny_min_threshold_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  canny_min_threshold_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  canny_min_threshold_spinbutton.set_digits(0) ;
  canny_min_threshold_spinbutton.set_range(1.0, 500.0)      ;
  canny_min_threshold_spinbutton.set_value(controller.canny_min_threshold)                ;
  canny_min_threshold_spinbutton.set_increments(1.0, 10.0)    ;
  canny_min_threshold_spinbutton.set_size_request(127-64, -1)    ;
  canny_min_threshold_spinbutton.set_snap_to_ticks(true)    ;
  canny_min_threshold_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  canny_min_threshold_spinbutton.set_adjustment( Gtk::Adjustment::create(controller.canny_min_threshold, 1.0, 500.0, 1.0, 10.0) ) ;


  canny_min_threshold_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  canny_min_threshold_hbox.pack_start(canny_min_threshold_label,      false, false, 0) ;
  canny_min_threshold_hbox.pack_start(canny_min_threshold_padding,    true,  true,  0) ;
  canny_min_threshold_hbox.pack_start(canny_min_threshold_spinbutton, true,  true,  0) ;



  Gtk::Label          canny_max_threshold_label("Canny maximal threshold") ;

  Gtk::Label          canny_max_threshold_padding("") ;

  Gtk::SpinButton     canny_max_threshold_spinbutton ;

  Gtk::Box            canny_max_threshold_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  canny_max_threshold_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  canny_max_threshold_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  canny_max_threshold_spinbutton.set_digits(0) ;
  canny_max_threshold_spinbutton.set_range(1.0, 500.0)      ;
  canny_max_threshold_spinbutton.set_value(controller.canny_max_threshold)      ;
  canny_max_threshold_spinbutton.set_increments(1.0, 10.0)    ;
  canny_max_threshold_spinbutton.set_size_request(127-64, -1)    ;
  canny_max_threshold_spinbutton.set_snap_to_ticks(true)    ;
  canny_max_threshold_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  canny_max_threshold_spinbutton.set_adjustment( Gtk::Adjustment::create(controller.canny_max_threshold, 1.0, 500.0, 1.0, 10.0) ) ;


  canny_max_threshold_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  canny_max_threshold_hbox.pack_start(canny_max_threshold_label,      false, false, 0) ;
  canny_max_threshold_hbox.pack_start(canny_max_threshold_padding,    true,  true,  0) ;
  canny_max_threshold_hbox.pack_start(canny_max_threshold_spinbutton, true,  true,  0) ;


  Gtk::Label          canny_invert_label("Invert black and white") ;

  Gtk::Label          canny_invert_padding("") ;

  Gtk::CheckButton    canny_invert_checkbutton ;

  Gtk::Box            canny_invert_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  canny_invert_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  canny_invert_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  canny_invert_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  canny_invert_checkbutton.set_active(controller.canny_invert) ;

  canny_invert_hbox.pack_start(canny_invert_label,       false, false, 0) ;
  canny_invert_hbox.pack_start(canny_invert_padding,     true,  true,  0) ;
  canny_invert_hbox.pack_start(canny_invert_checkbutton, true,  true,  0) ;



  canny_main_vbox.pack_start(canny_min_threshold_hbox, false, false, 0) ;
  canny_main_vbox.pack_start(canny_max_threshold_hbox, false, false, 0) ;
  canny_main_vbox.pack_start(canny_invert_hbox,        false, false, 0) ;

  canny_frame.add(canny_main_vbox) ;

  Gtk::Frame          canny_actions_frame("") ;

  Gtk::Box            canny_actions_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          canny_actions_frame_widget_image(PATH_TO_MENU_ICONS "undo-redo.png") ;
  Gtk::Label          canny_actions_frame_widget_label(" Actions ") ;

  canny_actions_frame_widget_hbox.pack_start(canny_actions_frame_widget_image, false, false, 0) ;
  canny_actions_frame_widget_hbox.pack_start(canny_actions_frame_widget_label, false, false, 0) ;

  canny_actions_frame.set_label_widget(canny_actions_frame_widget_hbox) ;


  Gtk::Button         canny_actions_undo_button(" Undo ") ;

  Gtk::Image          canny_actions_undo_image(PATH_TO_BUTTON_ICONS "go-previous-view.png") ;

  Gtk::Box            canny_actions_padding(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Button         canny_actions_redo_button(" Redo ") ;

  Gtk::Image          canny_actions_redo_image(PATH_TO_BUTTON_ICONS "go-next-view.png") ;




  Gtk::Box            canny_actions_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  canny_actions_undo_button.set_image(canny_actions_undo_image) ;

  canny_actions_undo_button.set_always_show_image(true) ;

  canny_actions_undo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;
  canny_actions_redo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;

  canny_actions_redo_button.set_image(canny_actions_redo_image) ;

  canny_actions_redo_button.set_always_show_image(true) ;

  canny_actions_hbox.set_spacing(FILTER_DIALOG_BOX_SPACING) ;
  canny_actions_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;


  canny_actions_hbox.pack_start(canny_actions_undo_button,    false,   false, 0) ;
  canny_actions_hbox.pack_start(canny_actions_padding,        true,    true,  0) ;
  canny_actions_hbox.pack_start(canny_actions_redo_button,    false,   false, 0) ;

  canny_actions_frame.add(canny_actions_hbox) ;

  canny_actions_undo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::undo_callback), controller) ) ;
  canny_actions_redo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::redo_callback), controller) ) ;



  Gtk::Box *canny_main_content_box = dialog.get_content_area() ;

  canny_main_content_box->set_spacing(FILTER_DIALOG_BOX_SPACING) ;

  canny_main_content_box->pack_start(canny_explanation_frame,    false, false, 0) ;
  canny_main_content_box->pack_start(canny_frame,                false, false, 0) ;
  canny_main_content_box->pack_start(canny_actions_frame,        false, false, 0) ;

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

  // Update showing image by changing the value of the spinbutton.
  canny_min_threshold_spinbutton.signal_value_changed().connect([&canny_min_threshold_spinbutton, &canny_max_threshold_spinbutton, &canny_invert_checkbutton, &controller, this] () {
   
    if ( ! controller.image_file_loaded   ) { return ; }
   
    cv::Mat tmp = controller.current_image_to_process.clone() ;

    cv::Mat frame ;

    canny(tmp, frame, canny_min_threshold_spinbutton.get_value(), canny_max_threshold_spinbutton.get_value(), canny_invert_checkbutton.get_active() ) ;

    // It convert frame as src to RGB(A) in dst current_image_to_display.
    this->set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

  } ) ;

  // Update showing image by changing the value of the spinbutton.
  canny_max_threshold_spinbutton.signal_value_changed().connect([&canny_min_threshold_spinbutton, &canny_max_threshold_spinbutton, &canny_invert_checkbutton, &controller, this] () {
  
    if ( ! controller.image_file_loaded   ) { return ; }
   
    cv::Mat tmp = controller.current_image_to_process.clone() ;

    cv::Mat frame ;

    canny(tmp, frame, canny_min_threshold_spinbutton.get_value(), canny_max_threshold_spinbutton.get_value(), canny_invert_checkbutton.get_active() ) ;

    // It convert frame as src to RGB(A) in dst current_image_to_display.
    this->set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

  } ) ;

  // Update showing image by changing the value of the spinbutton.
  canny_invert_checkbutton.signal_toggled().connect([&canny_min_threshold_spinbutton, &canny_max_threshold_spinbutton, &canny_invert_checkbutton, &controller, this] () {
  
    if ( ! controller.image_file_loaded   ) { return ; }
   
    cv::Mat tmp = controller.current_image_to_process.clone() ;

    cv::Mat frame ;

    canny(tmp, frame, canny_min_threshold_spinbutton.get_value(), canny_max_threshold_spinbutton.get_value(), canny_invert_checkbutton.get_active() ) ;

    // It convert frame as src to RGB(A) in dst current_image_to_display.
    this->set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

  } ) ;

  canny_main_content_box->show_all() ;

  renew_dialog :

  int ret = dialog.run() ;

  switch (ret) {

    case Gtk::RESPONSE_APPLY : {

      // Apply Canny filter to image.

      controller.canny_min_threshold = canny_min_threshold_spinbutton.get_value()  ;
      controller.canny_max_threshold = canny_max_threshold_spinbutton.get_value()  ;
      controller.canny_invert        = canny_invert_checkbutton.get_active()       ;
    
      if ( ! controller.image_file_loaded   ) { return ; }
    
      cv::Mat tmp = controller.current_image_to_process.clone() ;

      cv::Mat frame ;

      // Sea libedip.
      canny(tmp, frame, canny_min_threshold_spinbutton.get_value(), canny_max_threshold_spinbutton.get_value(), canny_invert_checkbutton.get_active() ) ;

      // We register current frame in vector<cv::Mat> for undo-redo.
      controller.process_after_applying(frame) ;

      // It convert frame as src to RGB(A) in dst current_image_to_display.
      set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

      // Reset some variables.
      after_applying_reset_settings(controller) ;

 
      goto renew_dialog ;
 
      break ;

    }

    case Gtk::RESPONSE_CLOSE : {
    
      if ( ! controller.image_file_loaded   ) { return ; }
    
      // Reset image.

      cv::Mat frame = controller.current_image_to_process.clone() ;

      // It convert frame as src to RGB(A) in dst current_image_to_display.
      set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).



      break ;

    }
  }

  dialog.close() ;

  return ;

}

void GUI::color_contours_filter_dialog(Controller &controller) {

  /** Configurable color_contours operator filter dialog window displaying. **/

  Gtk::Dialog dialog("Apply Color Contours filter.", false) ;

  // Configure dialog:
  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "image-x-generic.png") ;
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





  Gtk::Frame          color_contours_explanation_frame("") ;

  Gtk::Box            color_contours_explanation_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          color_contours_explanation_frame_widget_image(PATH_TO_MENU_ICONS "applications-education-university.png") ;
  Gtk::Label          color_contours_explanation_frame_widget_label(" Explanations ") ;

  Gtk::Label          color_contours_explanation_label("This filter detects contours\n"
                                                       "using the canny operator.\n"
                                                       "But instead of producing a black and white image\n"
                                                       "You can set the foreground and background colors.\n") ;
                                    

  color_contours_explanation_label.set_tooltip_text("Confer the joined documentation for further\n"
                                                    "informations about the Color Contours operators.") ;

  color_contours_explanation_frame_widget_label.set_margin_left(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  color_contours_explanation_frame_widget_label.set_margin_right(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  color_contours_explanation_frame_widget_label.set_margin_top(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  color_contours_explanation_frame_widget_label.set_margin_bottom(FILTER_DIALOG_FRAME_INNER_SPACE) ;

  color_contours_explanation_frame_widget_hbox.pack_start(color_contours_explanation_frame_widget_image, false, false, 0) ;
  color_contours_explanation_frame_widget_hbox.pack_start(color_contours_explanation_frame_widget_label, false, false, 0) ;

  color_contours_explanation_frame.set_label_widget(color_contours_explanation_frame_widget_hbox) ;

  color_contours_explanation_label.set_margin_bottom(6) ;

  color_contours_explanation_frame.add(color_contours_explanation_label) ;



  Gtk::Frame          color_contours_frame("") ;

  Gtk::Box            color_contours_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          color_contours_frame_widget_image(PATH_TO_MENU_ICONS "image-x-generic.png") ;
  Gtk::Label          color_contours_frame_widget_label(" Color contours ") ;

  color_contours_frame_widget_hbox.pack_start(color_contours_frame_widget_image, false, false, 0) ;
  color_contours_frame_widget_hbox.pack_start(color_contours_frame_widget_label, false, false, 0) ;

  color_contours_frame.set_label_widget(color_contours_frame_widget_hbox) ;



  Gtk::Box            color_contours_main_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;

  color_contours_main_vbox.set_spacing(FILTER_DIALOG_BOX_SPACING) ;



  Gtk::Label          color_contours_min_threshold_label("Minimal threshold         ") ;

  Gtk::Label          color_contours_min_threshold_padding("") ;

  Gtk::SpinButton     color_contours_min_threshold_spinbutton ;

  Gtk::Box            color_contours_min_threshold_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  color_contours_min_threshold_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  color_contours_min_threshold_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  color_contours_min_threshold_spinbutton.set_digits(0) ;
  color_contours_min_threshold_spinbutton.set_range(1.0, 500.0)      ;
  color_contours_min_threshold_spinbutton.set_value(controller.color_contours_min_threshold)                ;
  color_contours_min_threshold_spinbutton.set_increments(1.0, 10.0)    ;
  color_contours_min_threshold_spinbutton.set_size_request(127-64, -1)    ;
  color_contours_min_threshold_spinbutton.set_snap_to_ticks(true)    ;
  color_contours_min_threshold_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  color_contours_min_threshold_spinbutton.set_adjustment( Gtk::Adjustment::create(controller.color_contours_min_threshold, 1.0, 500.0, 1.0, 10.0) ) ;


  color_contours_min_threshold_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  color_contours_min_threshold_hbox.pack_start(color_contours_min_threshold_label,      false, false, 0) ;
  color_contours_min_threshold_hbox.pack_start(color_contours_min_threshold_padding,    true,  true,  0) ;
  color_contours_min_threshold_hbox.pack_start(color_contours_min_threshold_spinbutton, true,  true,  0) ;



  Gtk::Label          color_contours_max_threshold_label("Maximal threshold         ") ;

  Gtk::Label          color_contours_max_threshold_padding("") ;

  Gtk::SpinButton     color_contours_max_threshold_spinbutton ;

  Gtk::Box            color_contours_max_threshold_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  color_contours_max_threshold_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  color_contours_max_threshold_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  color_contours_max_threshold_spinbutton.set_digits(0) ;
  color_contours_max_threshold_spinbutton.set_range(1.0, 500.0)      ;
  color_contours_max_threshold_spinbutton.set_value(controller.color_contours_max_threshold)      ;
  color_contours_max_threshold_spinbutton.set_increments(1.0, 10.0)    ;
  color_contours_max_threshold_spinbutton.set_size_request(127-64, -1)    ;
  color_contours_max_threshold_spinbutton.set_snap_to_ticks(true)    ;
  color_contours_max_threshold_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  color_contours_max_threshold_spinbutton.set_adjustment( Gtk::Adjustment::create(controller.color_contours_max_threshold, 1.0, 500.0, 1.0, 10.0) ) ;


  color_contours_max_threshold_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  color_contours_max_threshold_hbox.pack_start(color_contours_max_threshold_label,      false, false, 0) ;
  color_contours_max_threshold_hbox.pack_start(color_contours_max_threshold_padding,    true,  true,  0) ;
  color_contours_max_threshold_hbox.pack_start(color_contours_max_threshold_spinbutton, true,  true,  0) ;


  Gtk::Label                  color_contours_bg_color_label("background color") ;

  Gtk::Label                  color_contours_bg_color_padding("") ;

  Gdk::RGBA                   bg_color_start_rgba ;

  bg_color_start_rgba.set_rgba(0.0, 0.0, 0.0) ;

  Gtk::ColorButton            color_contours_bg_color_colorbutton(bg_color_start_rgba) ;

  Gtk::Box                    color_contours_bg_color_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  color_contours_bg_color_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  color_contours_bg_color_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  color_contours_bg_color_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  color_contours_bg_color_colorbutton.set_use_alpha(false) ;

  color_contours_bg_color_colorbutton.set_title("Set background color.") ;

  color_contours_bg_color_hbox.pack_start(color_contours_bg_color_label,       false, false, 0) ;
  color_contours_bg_color_hbox.pack_start(color_contours_bg_color_padding,     true,  true,  0) ;
  color_contours_bg_color_hbox.pack_start(color_contours_bg_color_colorbutton, true,  true,  0) ;


  Gtk::Label                  color_contours_fg_color_label("foreground color") ;

  Gtk::Label                  color_contours_fg_color_padding("") ;

  Gdk::RGBA                   fg_color_start_rgba ;

  fg_color_start_rgba.set_rgba(1.0, 1.0, 1.0) ;

  Gtk::ColorButton            color_contours_fg_color_colorbutton(fg_color_start_rgba) ;

  Gtk::Box                    color_contours_fg_color_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  color_contours_fg_color_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  color_contours_fg_color_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  color_contours_fg_color_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  color_contours_fg_color_colorbutton.set_use_alpha(false) ;

  color_contours_fg_color_colorbutton.set_title("Set foreground color.") ;

  color_contours_fg_color_hbox.pack_start(color_contours_fg_color_label,       false, false, 0) ;
  color_contours_fg_color_hbox.pack_start(color_contours_fg_color_padding,     true,  true,  0) ;
  color_contours_fg_color_hbox.pack_start(color_contours_fg_color_colorbutton, true,  true,  0) ;


  color_contours_main_vbox.pack_start(color_contours_min_threshold_hbox,   false, false, 0) ;
  color_contours_main_vbox.pack_start(color_contours_max_threshold_hbox,   false, false, 0) ;
  color_contours_main_vbox.pack_start(color_contours_bg_color_hbox,        false, false, 0) ;
  color_contours_main_vbox.pack_start(color_contours_fg_color_hbox,        false, false, 0) ;

  color_contours_frame.add(color_contours_main_vbox) ;

  Gtk::Frame          color_contours_actions_frame("") ;

  Gtk::Box            color_contours_actions_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          color_contours_actions_frame_widget_image(PATH_TO_MENU_ICONS "undo-redo.png") ;
  Gtk::Label          color_contours_actions_frame_widget_label(" Actions ") ;

  color_contours_actions_frame_widget_hbox.pack_start(color_contours_actions_frame_widget_image, false, false, 0) ;
  color_contours_actions_frame_widget_hbox.pack_start(color_contours_actions_frame_widget_label, false, false, 0) ;

  color_contours_actions_frame.set_label_widget(color_contours_actions_frame_widget_hbox) ;


  Gtk::Button         color_contours_actions_undo_button(" Undo ") ;

  Gtk::Image          color_contours_actions_undo_image(PATH_TO_BUTTON_ICONS "go-previous-view.png") ;

  Gtk::Box            color_contours_actions_padding(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Button         color_contours_actions_redo_button(" Redo ") ;

  Gtk::Image          color_contours_actions_redo_image(PATH_TO_BUTTON_ICONS "go-next-view.png") ;




  Gtk::Box            color_contours_actions_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  color_contours_actions_undo_button.set_image(color_contours_actions_undo_image) ;

  color_contours_actions_undo_button.set_always_show_image(true) ;

  color_contours_actions_undo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;
  color_contours_actions_redo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;

  color_contours_actions_redo_button.set_image(color_contours_actions_redo_image) ;

  color_contours_actions_redo_button.set_always_show_image(true) ;

  color_contours_actions_hbox.set_spacing(FILTER_DIALOG_BOX_SPACING) ;
  color_contours_actions_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;


  color_contours_actions_hbox.pack_start(color_contours_actions_undo_button,    false,   false, 0) ;
  color_contours_actions_hbox.pack_start(color_contours_actions_padding,        true,    true,  0) ;
  color_contours_actions_hbox.pack_start(color_contours_actions_redo_button,    false,   false, 0) ;

  color_contours_actions_frame.add(color_contours_actions_hbox) ;

  color_contours_actions_undo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::undo_callback), controller) ) ;
  color_contours_actions_redo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::redo_callback), controller) ) ;



  Gtk::Box *color_contours_main_content_box = dialog.get_content_area() ;

  color_contours_main_content_box->set_spacing(FILTER_DIALOG_BOX_SPACING) ;

  color_contours_main_content_box->pack_start(color_contours_explanation_frame,    false, false, 0) ;
  color_contours_main_content_box->pack_start(color_contours_frame,                false, false, 0) ;
  color_contours_main_content_box->pack_start(color_contours_actions_frame,        false, false, 0) ;

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

  // Update showing image by changing the value of the spinbutton.
  color_contours_min_threshold_spinbutton.signal_value_changed().connect([&color_contours_min_threshold_spinbutton, &color_contours_max_threshold_spinbutton, &color_contours_fg_color_colorbutton,  &color_contours_bg_color_colorbutton, &controller, this] () {
   
    if ( ! controller.image_file_loaded   ) { return ; }
   
    cv::Mat tmp = controller.current_image_to_process.clone() ;

    cv::Mat frame ;

    Gdk::RGBA fg_color = color_contours_fg_color_colorbutton.get_rgba() ;

    Gdk::RGBA bg_color = color_contours_bg_color_colorbutton.get_rgba() ;


    color_contours(tmp, frame, color_contours_min_threshold_spinbutton.get_value(), color_contours_max_threshold_spinbutton.get_value(), 3, cv::Scalar((bg_color.get_blue_u() >> 8), (bg_color.get_green_u() >> 8),(bg_color.get_red_u() >> 8)) , cv::Scalar((fg_color.get_blue_u() >> 8), (fg_color.get_green_u() >> 8), (fg_color.get_red_u() >> 8)) ) ;

    // It convert frame as src to RGB(A) in dst current_image_to_display.
    this->set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

  } ) ;

  // Update showing image by changing the value of the spinbutton.
  color_contours_max_threshold_spinbutton.signal_value_changed().connect([&color_contours_min_threshold_spinbutton, &color_contours_max_threshold_spinbutton, &color_contours_fg_color_colorbutton,  &color_contours_bg_color_colorbutton, &controller, this] () {
   
    if ( ! controller.image_file_loaded   ) { return ; }
   
    cv::Mat tmp = controller.current_image_to_process.clone() ;

    cv::Mat frame ;

    Gdk::RGBA fg_color = color_contours_fg_color_colorbutton.get_rgba() ;

    Gdk::RGBA bg_color = color_contours_bg_color_colorbutton.get_rgba() ;


    color_contours(tmp, frame, color_contours_min_threshold_spinbutton.get_value(), color_contours_max_threshold_spinbutton.get_value(), 3, cv::Scalar( (bg_color.get_blue_u() >> 8), (bg_color.get_green_u() >> 8),(bg_color.get_red_u() >> 8)) , cv::Scalar((fg_color.get_blue_u() >> 8), (fg_color.get_green_u() >> 8), (fg_color.get_red_u() >> 8)) ) ;

    // It convert frame as src to RGB(A) in dst current_image_to_display.
    this->set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

  } ) ;

  // Update showing image by changing the value of the colorbutton.
  color_contours_fg_color_colorbutton.signal_color_set().connect([&color_contours_min_threshold_spinbutton, &color_contours_max_threshold_spinbutton, &color_contours_fg_color_colorbutton,  &color_contours_bg_color_colorbutton, &controller, this] () {
  
    if ( ! controller.image_file_loaded   ) { return ; }
  
    cv::Mat tmp = controller.current_image_to_process.clone() ;

    cv::Mat frame ;

    Gdk::RGBA fg_color = color_contours_fg_color_colorbutton.get_rgba() ;

    Gdk::RGBA bg_color = color_contours_bg_color_colorbutton.get_rgba() ;

    color_contours(tmp, frame, color_contours_min_threshold_spinbutton.get_value(), color_contours_max_threshold_spinbutton.get_value(), 3, cv::Scalar( (bg_color.get_blue_u() >> 8), (bg_color.get_green_u() >> 8),(bg_color.get_red_u() >> 8)) , cv::Scalar((fg_color.get_blue_u() >> 8), (fg_color.get_green_u() >> 8), (fg_color.get_red_u() >> 8)) ) ;

    // It convert frame as src to RGB(A) in dst current_image_to_display.
    this->set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

  } ) ;

  // Update showing image by changing the value of the colorbutton.
  color_contours_bg_color_colorbutton.signal_color_set().connect([&color_contours_min_threshold_spinbutton, &color_contours_max_threshold_spinbutton, &color_contours_fg_color_colorbutton,  &color_contours_bg_color_colorbutton, &controller, this] () {
  
    if ( ! controller.image_file_loaded   ) { return ; }
  
    cv::Mat tmp = controller.current_image_to_process.clone() ;

    cv::Mat frame ;

    Gdk::RGBA fg_color = color_contours_fg_color_colorbutton.get_rgba() ;

    Gdk::RGBA bg_color = color_contours_bg_color_colorbutton.get_rgba() ;

    color_contours(tmp, frame, color_contours_min_threshold_spinbutton.get_value(), color_contours_max_threshold_spinbutton.get_value(), 3, cv::Scalar( (bg_color.get_blue_u() >> 8), (bg_color.get_green_u() >> 8),(bg_color.get_red_u() >> 8)) , cv::Scalar((fg_color.get_blue_u() >> 8), (fg_color.get_green_u() >> 8), (fg_color.get_red_u() >> 8)) ) ;

    // It convert frame as src to RGB(A) in dst current_image_to_display.
    this->set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

  } ) ;

  color_contours_main_content_box->show_all() ;

  renew_dialog :

  int ret = dialog.run() ;

  switch (ret) {

    case Gtk::RESPONSE_APPLY : {

      // Apply Color Contours filter to image.

      controller.color_contours_min_threshold = color_contours_min_threshold_spinbutton.get_value()  ;
      controller.color_contours_max_threshold = color_contours_max_threshold_spinbutton.get_value()  ;
  
      if ( ! controller.image_file_loaded   ) { return ; }
    
      Gdk::RGBA fg_color = color_contours_fg_color_colorbutton.get_rgba() ;
  
      Gdk::RGBA bg_color = color_contours_bg_color_colorbutton.get_rgba() ;
  
      cv::Mat tmp = controller.current_image_to_process.clone() ;

      cv::Mat frame ;

      // Sea libedip.
      color_contours(tmp, frame, color_contours_min_threshold_spinbutton.get_value(), color_contours_max_threshold_spinbutton.get_value(), 3, cv::Scalar((bg_color.get_blue_u() >> 8), (bg_color.get_green_u() >> 8),(bg_color.get_red_u() >> 8)) , cv::Scalar((fg_color.get_blue_u() >> 8), (fg_color.get_green_u() >> 8), (fg_color.get_red_u() >> 8)) ) ;

      // We register current frame in vector<cv::Mat> for undo-redo.
      controller.process_after_applying(frame) ;

      // It convert frame as src to RGB(A) in dst current_image_to_display.
      set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

      // Reset some variables.
      after_applying_reset_settings(controller) ;

 
      goto renew_dialog ;
 
      break ;

    }

   case Gtk::RESPONSE_CLOSE : {
    
      if ( ! controller.image_file_loaded   ) { return ; }
    
      // Reset image.
      cv::Mat frame = controller.current_image_to_process.clone() ;

      // It convert frame as src to RGB(A) in dst current_image_to_display.
      set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).



      break ;

    }
  }

  dialog.close() ;

  return ;

}

#endif
