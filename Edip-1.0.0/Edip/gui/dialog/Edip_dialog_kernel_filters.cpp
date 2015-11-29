#ifndef EDIP_KERNEL_FILTERS_DIALOG_HH
#define EDIP_KERNEL_FILTERS_DIALOG_HH

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


void GUI::kernel_sharpen_filter_dialog(Controller &controller) {

  /** Configurable Sharpen kernel filter dialog window displaying. **/

  Gtk::Dialog dialog("Apply kernel Sharpen filter.", false) ;

  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "transform-move.png") ;
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





  Gtk::Frame          kernel_sharpen_explanation_frame("") ;

  Gtk::Box            kernel_sharpen_explanation_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          kernel_sharpen_explanation_frame_widget_image(PATH_TO_MENU_ICONS "applications-education-university.png") ;
  Gtk::Label          kernel_sharpen_explanation_frame_widget_label(" Explanations ") ;

  Gtk::Label          kernel_sharpen_explanation_label("A kernel is a set of weights which determine\n"
                                                       "how each output pixel is calculated\n"
                                                       "from a neighborhood of input pixels.\n"
                                                       "Applying a kernel filter consist of moving\n"
                                                       "the kernel over each pixel of an image\n"
                                                       "and multiplying each corresponding pixel\n"
                                                       "by it's associated weight.\n"
                                                       "According to that the central pixel\n"
                                                       "correspond to a pixel of interest\n"
                                                       "and the others to the neighborhood pixels.") ;

  kernel_sharpen_explanation_label.set_tooltip_text("Confer the joined documentation for further\n"
                                                    "informations about kernels.") ;

  kernel_sharpen_explanation_frame_widget_label.set_margin_left(FILTER_DIALOG_FRAME_INNER_SPACE)   ;
  kernel_sharpen_explanation_frame_widget_label.set_margin_right(FILTER_DIALOG_FRAME_INNER_SPACE)  ;
  kernel_sharpen_explanation_frame_widget_label.set_margin_top(FILTER_DIALOG_FRAME_INNER_SPACE)    ;
  kernel_sharpen_explanation_frame_widget_label.set_margin_bottom(FILTER_DIALOG_FRAME_INNER_SPACE) ;

  kernel_sharpen_explanation_frame_widget_hbox.pack_start(kernel_sharpen_explanation_frame_widget_image, false, false, 0) ;
  kernel_sharpen_explanation_frame_widget_hbox.pack_start(kernel_sharpen_explanation_frame_widget_label, false, false, 0) ;

  kernel_sharpen_explanation_frame.set_label_widget(kernel_sharpen_explanation_frame_widget_hbox) ;

  kernel_sharpen_explanation_label.set_margin_bottom(6) ;

  kernel_sharpen_explanation_frame.add(kernel_sharpen_explanation_label) ;



  Gtk::Frame          kernel_sharpen_kernel_frame("") ;

  Gtk::Box            kernel_sharpen_kernel_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          kernel_sharpen_kernel_frame_widget_image(PATH_TO_MENU_ICONS "transform-move.png") ;
  Gtk::Label          kernel_sharpen_kernel_frame_widget_label(" Sharpen kernel ") ;

  kernel_sharpen_kernel_frame_widget_hbox.pack_start(kernel_sharpen_kernel_frame_widget_image, false, false, 0) ;
  kernel_sharpen_kernel_frame_widget_hbox.pack_start(kernel_sharpen_kernel_frame_widget_label, false, false, 0) ;

  kernel_sharpen_kernel_frame.set_label_widget(kernel_sharpen_kernel_frame_widget_hbox) ;



  Gtk::Box            kernel_sharpen_kernel_main_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;

  kernel_sharpen_kernel_main_vbox.set_spacing(FILTER_DIALOG_BOX_SPACING) ;



  Gtk::Label          kernel_sharpen_kernel_type_label("Kernel type") ;

  Gtk::Label          kernel_sharpen_padding_01("") ;

  Gtk::ComboBoxText   kernel_sharpen_kernel_type_combo ;

  Gtk::Box            kernel_sharpen_kernel_hbox_01(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  kernel_sharpen_kernel_type_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  kernel_sharpen_kernel_type_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  kernel_sharpen_kernel_type_combo.insert(0, "Square") ;
  kernel_sharpen_kernel_type_combo.insert(1, "Diamond") ;
  kernel_sharpen_kernel_type_combo.insert(2, "Cross") ;
  kernel_sharpen_kernel_type_combo.insert(3, "X") ;

  kernel_sharpen_kernel_type_combo.set_active(controller.kernel_sharpen_kernel_type) ;

  kernel_sharpen_kernel_hbox_01.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  kernel_sharpen_kernel_hbox_01.pack_start(kernel_sharpen_kernel_type_label, false, false, 0) ;
  kernel_sharpen_kernel_hbox_01.pack_start(kernel_sharpen_padding_01,        true,  true,  0) ;
  kernel_sharpen_kernel_hbox_01.pack_start(kernel_sharpen_kernel_type_combo, true,  true,  0) ;



  Gtk::Label          kernel_sharpen_kernel_ksize_label("Kernel size") ;

  Gtk::Label          kernel_sharpen_padding_02("") ;

  Gtk::SpinButton     kernel_sharpen_kernel_ksize_spinbutton ;

  Gtk::Box            kernel_sharpen_kernel_hbox_02(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  kernel_sharpen_kernel_ksize_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  kernel_sharpen_kernel_ksize_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  kernel_sharpen_kernel_ksize_spinbutton.set_digits(0) ;
  kernel_sharpen_kernel_ksize_spinbutton.set_range(3.0, 31.0)      ;
  kernel_sharpen_kernel_ksize_spinbutton.set_value(controller.kernel_sharpen_kernel_size)      ;
  kernel_sharpen_kernel_ksize_spinbutton.set_increments(2.0, 4.0)    ;
  kernel_sharpen_kernel_ksize_spinbutton.set_size_request(127-64, -1)    ;
  kernel_sharpen_kernel_ksize_spinbutton.set_snap_to_ticks(true)    ;
  kernel_sharpen_kernel_ksize_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  kernel_sharpen_kernel_ksize_spinbutton.set_adjustment( Gtk::Adjustment::create(controller.kernel_sharpen_kernel_size, 3.0, 31.0, 2.0, 4.0) ) ;


  kernel_sharpen_kernel_hbox_02.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  kernel_sharpen_kernel_hbox_02.pack_start(kernel_sharpen_kernel_ksize_label,      false, false, 0) ;
  kernel_sharpen_kernel_hbox_02.pack_start(kernel_sharpen_padding_02,              true,  true,  0) ;
  kernel_sharpen_kernel_hbox_02.pack_start(kernel_sharpen_kernel_ksize_spinbutton, false, false, 0) ;


  Gtk::Label          kernel_sharpen_kernel_values_factor_label("Values factor") ;

  Gtk::Label          kernel_sharpen_padding_03("") ;

  Gtk::Scale          kernel_sharpen_kernel_values_factor_scale(Gtk::ORIENTATION_HORIZONTAL) ;

  Gtk::Box            kernel_sharpen_kernel_hbox_03(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  kernel_sharpen_kernel_values_factor_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  kernel_sharpen_kernel_values_factor_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  kernel_sharpen_kernel_values_factor_scale.set_digits(2) ;
  kernel_sharpen_kernel_values_factor_scale.set_draw_value(true) ;
  kernel_sharpen_kernel_values_factor_scale.set_has_origin(true) ;
  kernel_sharpen_kernel_values_factor_scale.set_upper_stepper_sensitivity(Gtk::SENSITIVITY_ON) ;
  kernel_sharpen_kernel_values_factor_scale.set_lower_stepper_sensitivity(Gtk::SENSITIVITY_ON) ;
  kernel_sharpen_kernel_values_factor_scale.set_adjustment( kernel_sharpen_kernel_values_factor_scale.get_adjustment() )     ;
  kernel_sharpen_kernel_values_factor_scale.set_range(0.01, 5.00)      ;
  kernel_sharpen_kernel_values_factor_scale.set_value(controller.kernel_sharpen_kernel_values_factor)      ;
  kernel_sharpen_kernel_values_factor_scale.set_increments(0.01, 0.1)    ;
  kernel_sharpen_kernel_values_factor_scale.set_size_request(127-16-8, -1)    ;
  kernel_sharpen_kernel_values_factor_scale.add_mark(1.0, Gtk::POS_TOP, "")      ;

  kernel_sharpen_kernel_hbox_03.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  kernel_sharpen_kernel_hbox_03.pack_start(kernel_sharpen_kernel_values_factor_label, false, false, 0) ;
  kernel_sharpen_kernel_hbox_03.pack_start(kernel_sharpen_padding_03,                 true,  true,  0) ;
  kernel_sharpen_kernel_hbox_03.pack_start(kernel_sharpen_kernel_values_factor_scale, true,  true,  0) ;


  Gtk::Label          kernel_sharpen_kernel_center_factor_label("Center factor") ;

  Gtk::Label          kernel_sharpen_padding_04("") ;

  Gtk::Scale          kernel_sharpen_kernel_center_factor_scale(Gtk::ORIENTATION_HORIZONTAL) ;

  Gtk::Box            kernel_sharpen_kernel_hbox_04(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  kernel_sharpen_kernel_center_factor_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  kernel_sharpen_kernel_center_factor_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  kernel_sharpen_kernel_center_factor_scale.set_digits(2) ;
  kernel_sharpen_kernel_center_factor_scale.set_draw_value(true) ;
  kernel_sharpen_kernel_center_factor_scale.set_has_origin(true) ;
  kernel_sharpen_kernel_center_factor_scale.set_upper_stepper_sensitivity(Gtk::SENSITIVITY_ON) ;
  kernel_sharpen_kernel_center_factor_scale.set_lower_stepper_sensitivity(Gtk::SENSITIVITY_ON) ;
  kernel_sharpen_kernel_center_factor_scale.set_adjustment( kernel_sharpen_kernel_center_factor_scale.get_adjustment() )     ;
  kernel_sharpen_kernel_center_factor_scale.set_range(0.01, 5.00)      ;
  kernel_sharpen_kernel_center_factor_scale.set_value(controller.kernel_sharpen_kernel_center_factor)      ;
  kernel_sharpen_kernel_center_factor_scale.set_increments(0.01, 0.1)    ;
  kernel_sharpen_kernel_center_factor_scale.set_size_request(127-16-8, -1)    ;
  kernel_sharpen_kernel_center_factor_scale.add_mark(1.0, Gtk::POS_TOP, "")      ;

  kernel_sharpen_kernel_hbox_04.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  kernel_sharpen_kernel_hbox_04.pack_start(kernel_sharpen_kernel_center_factor_label, false, false, 0) ;
  kernel_sharpen_kernel_hbox_04.pack_start(kernel_sharpen_padding_04,                 true,  true,  0) ;
  kernel_sharpen_kernel_hbox_04.pack_start(kernel_sharpen_kernel_center_factor_scale, true,  true,  0) ;



  Gtk::Box            kernel_sharpen_kernel_hbox_05(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Label          kernel_sharpen_padding_05("") ;

  Gtk::Image          kernel_sharpen_kernel_display_image(PATH_TO_BUTTON_ICONS "transform-move.png") ;

  Gtk::Button         kernel_sharpen_kernel_display_button("   Preview kernel    ") ;

  kernel_sharpen_kernel_display_button.set_image(kernel_sharpen_kernel_display_image) ;

  kernel_sharpen_kernel_display_button.set_always_show_image(true) ;


  kernel_sharpen_kernel_hbox_05.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  kernel_sharpen_kernel_hbox_05.pack_start(kernel_sharpen_padding_05,            true,  true,  0) ;
  kernel_sharpen_kernel_hbox_05.pack_start(kernel_sharpen_kernel_display_button, false, false, 0) ;


  kernel_sharpen_kernel_main_vbox.pack_start(kernel_sharpen_kernel_hbox_01, false, false, 0) ;
  kernel_sharpen_kernel_main_vbox.pack_start(kernel_sharpen_kernel_hbox_02, false, false, 0) ;
  kernel_sharpen_kernel_main_vbox.pack_start(kernel_sharpen_kernel_hbox_03, false, false, 0) ;
  kernel_sharpen_kernel_main_vbox.pack_start(kernel_sharpen_kernel_hbox_04, false, false, 0) ;
  kernel_sharpen_kernel_main_vbox.pack_start(kernel_sharpen_kernel_hbox_05, false, false, 0) ;

  kernel_sharpen_kernel_frame.add(kernel_sharpen_kernel_main_vbox) ;



  Gtk::Frame          kernel_sharpen_kernel_actions_frame("") ;

  Gtk::Box            kernel_sharpen_kernel_actions_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          kernel_sharpen_kernel_actions_frame_widget_image(PATH_TO_MENU_ICONS "undo-redo.png") ;
  Gtk::Label          kernel_sharpen_kernel_actions_frame_widget_label(" Actions ") ;

  kernel_sharpen_kernel_actions_frame_widget_hbox.pack_start(kernel_sharpen_kernel_actions_frame_widget_image, false, false, 0) ;
  kernel_sharpen_kernel_actions_frame_widget_hbox.pack_start(kernel_sharpen_kernel_actions_frame_widget_label, false, false, 0) ;

  kernel_sharpen_kernel_actions_frame.set_label_widget(kernel_sharpen_kernel_actions_frame_widget_hbox) ;

  Gtk::Button         kernel_sharpen_kernel_actions_undo_button(" Undo ") ;

  Gtk::Image          kernel_sharpen_kernel_actions_undo_image(PATH_TO_BUTTON_ICONS "go-previous-view.png") ;

  Gtk::Box            kernel_sharpen_kernel_actions_padding(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Button         kernel_sharpen_kernel_actions_redo_button(" Redo ") ;

  Gtk::Image          kernel_sharpen_kernel_actions_redo_image(PATH_TO_BUTTON_ICONS "go-next-view.png") ;




  Gtk::Box            kernel_sharpen_kernel_actions_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  kernel_sharpen_kernel_actions_undo_button.set_image(kernel_sharpen_kernel_actions_undo_image) ;

  kernel_sharpen_kernel_actions_undo_button.set_always_show_image(true) ;

  kernel_sharpen_kernel_actions_undo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;
  kernel_sharpen_kernel_actions_redo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;

  kernel_sharpen_kernel_actions_redo_button.set_image(kernel_sharpen_kernel_actions_redo_image) ;

  kernel_sharpen_kernel_actions_redo_button.set_always_show_image(true) ;

  kernel_sharpen_kernel_actions_hbox.set_spacing(FILTER_DIALOG_BOX_SPACING) ;
  kernel_sharpen_kernel_actions_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;


  kernel_sharpen_kernel_actions_hbox.pack_start(kernel_sharpen_kernel_actions_undo_button,    false,   false, 0) ;
  kernel_sharpen_kernel_actions_hbox.pack_start(kernel_sharpen_kernel_actions_padding,        true,    true,  0) ;
  kernel_sharpen_kernel_actions_hbox.pack_start(kernel_sharpen_kernel_actions_redo_button,    false,   false, 0) ;

  kernel_sharpen_kernel_actions_frame.add(kernel_sharpen_kernel_actions_hbox) ;

  kernel_sharpen_kernel_actions_undo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::undo_callback), controller) ) ;
  kernel_sharpen_kernel_actions_redo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::redo_callback), controller) ) ;





  Gtk::Box *kernel_sharpen_main_content_box = dialog.get_content_area() ;

  kernel_sharpen_main_content_box->set_spacing(FILTER_DIALOG_BOX_SPACING) ;

  kernel_sharpen_main_content_box->pack_start(kernel_sharpen_explanation_frame,     false, false, 0) ;
  kernel_sharpen_main_content_box->pack_start(kernel_sharpen_kernel_frame,          false, false, 0) ;
  kernel_sharpen_main_content_box->pack_start(kernel_sharpen_kernel_actions_frame,  false, false, 0) ;



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

  // Display kernel button callback.
  kernel_sharpen_kernel_display_button.signal_clicked().connect([&kernel_sharpen_kernel_type_combo, &kernel_sharpen_kernel_ksize_spinbutton, &kernel_sharpen_kernel_values_factor_scale, &kernel_sharpen_kernel_center_factor_scale, this] () {

    string kernel_type ;

    switch (kernel_sharpen_kernel_type_combo.get_active_row_number()) {

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

    // Sea the libedip.
    Sharpen kernel(static_cast<int>(kernel_sharpen_kernel_ksize_spinbutton.get_value()), kernel_type, static_cast<float>(kernel_sharpen_kernel_values_factor_scale.get_value()), '+', static_cast<float>(kernel_sharpen_kernel_center_factor_scale.get_value())) ;

    #ifdef DEBUG
    kernel.kernel_print() ;
    #endif

    this->display_kernel(kernel.kernel) ;

  } ) ;

  kernel_sharpen_main_content_box->show_all() ;

  renew_dialog :

  int ret = dialog.run() ;

  switch (ret) {

    case Gtk::RESPONSE_APPLY :


      controller.kernel_sharpen_kernel_type          = kernel_sharpen_kernel_type_combo.get_active_row_number()  ;
      controller.kernel_sharpen_kernel_size          = kernel_sharpen_kernel_ksize_spinbutton.get_value()        ;
      controller.kernel_sharpen_kernel_values_factor = kernel_sharpen_kernel_values_factor_scale.get_value()     ;
      controller.kernel_sharpen_kernel_center_factor = kernel_sharpen_kernel_center_factor_scale.get_value()     ;

      kernel_sharpen_callback(controller) ;

      goto renew_dialog ;


      break ;

    case Gtk::RESPONSE_CLOSE :

      dialog.close() ;

      break ;
  }

  dialog.close() ;

  return ;

}

void GUI::kernel_find_edges_filter_dialog(Controller &controller) {

  /** Configurable Find Edges kernel filter dialog window displaying. **/

  Gtk::Dialog dialog("Apply kernel Find Edges filter.", false) ;

  // Configure dialog:
  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "transform-move.png") ;
  dialog.set_type_hint(Gdk::WINDOW_TYPE_HINT_NORMAL) ;
  dialog.set_resizable(false) ;
  dialog.set_border_width(FILTER_DIALOG_SPACE) ;
  dialog.set_modal(false) ;

  Glib::PropertyProxy<bool> destroy_with_parent_bool = dialog.property_destroy_with_parent() ;

  destroy_with_parent_bool.set_value(true) ;

  // Positioning dialog at the top right corner
  // so that we can sea the entire image by processing.
  auto window_size = controller.get_window_size() ;
  dialog.move(window_size.first, 0) ;

  dialog.set_size_request(512-128-32-4, -1) ;



  Gtk::Frame          kernel_find_edges_explanation_frame("") ;

  Gtk::Box            kernel_find_edges_explanation_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          kernel_find_edges_explanation_frame_widget_image(PATH_TO_MENU_ICONS "applications-education-university.png") ;
  Gtk::Label          kernel_find_edges_explanation_frame_widget_label(" Explanations ") ;

  Gtk::Label          kernel_find_edges_explanation_label("A kernel is a set of weights which determine\n"
                                                       "how each output pixel is calculated\n"
                                                       "from a neighborhood of input pixels.\n"
                                                       "Applying a kernel filter consist of moving\n"
                                                       "the kernel over each pixel of an image\n"
                                                       "and multiplying each corresponding pixel\n"
                                                       "by it's associated weight.\n"
                                                       "According to that the central pixel\n"
                                                       "correspond to a pixel of interest\n"
                                                       "and the others to the neighborhood pixels.") ;
                                                

  kernel_find_edges_explanation_label.set_tooltip_text("Confer the joined documentation for further\n"
                                                       "informations about kernels.") ;

  kernel_find_edges_explanation_frame_widget_label.set_margin_left(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  kernel_find_edges_explanation_frame_widget_label.set_margin_right(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  kernel_find_edges_explanation_frame_widget_label.set_margin_top(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  kernel_find_edges_explanation_frame_widget_label.set_margin_bottom(FILTER_DIALOG_FRAME_INNER_SPACE) ;

  kernel_find_edges_explanation_frame_widget_hbox.pack_start(kernel_find_edges_explanation_frame_widget_image, false, false, 0) ;
  kernel_find_edges_explanation_frame_widget_hbox.pack_start(kernel_find_edges_explanation_frame_widget_label, false, false, 0) ;

  kernel_find_edges_explanation_frame.set_label_widget(kernel_find_edges_explanation_frame_widget_hbox) ;

  kernel_find_edges_explanation_label.set_margin_bottom(6) ;

  kernel_find_edges_explanation_frame.add(kernel_find_edges_explanation_label) ;



  Gtk::Frame          kernel_find_edges_kernel_frame("") ;

  Gtk::Box            kernel_find_edges_kernel_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          kernel_find_edges_kernel_frame_widget_image(PATH_TO_MENU_ICONS "transform-move.png") ;
  Gtk::Label          kernel_find_edges_kernel_frame_widget_label(" Find edges kernel ") ;

  kernel_find_edges_kernel_frame_widget_hbox.pack_start(kernel_find_edges_kernel_frame_widget_image, false, false, 0) ;
  kernel_find_edges_kernel_frame_widget_hbox.pack_start(kernel_find_edges_kernel_frame_widget_label, false, false, 0) ;

  kernel_find_edges_kernel_frame.set_label_widget(kernel_find_edges_kernel_frame_widget_hbox) ;



  Gtk::Box            kernel_find_edges_kernel_main_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;

  kernel_find_edges_kernel_main_vbox.set_spacing(FILTER_DIALOG_BOX_SPACING) ;



  Gtk::Label          kernel_find_edges_kernel_type_label("Kernel type") ;

  Gtk::Label          kernel_find_edges_padding_01("") ;

  Gtk::ComboBoxText   kernel_find_edges_kernel_type_combo ;

  Gtk::Box            kernel_find_edges_kernel_hbox_01(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  kernel_find_edges_kernel_type_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  kernel_find_edges_kernel_type_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  kernel_find_edges_kernel_type_combo.insert(0, "Square") ;
  kernel_find_edges_kernel_type_combo.insert(1, "Diamond") ;
  kernel_find_edges_kernel_type_combo.insert(2, "Cross") ;
  kernel_find_edges_kernel_type_combo.insert(3, "X") ;

  kernel_find_edges_kernel_type_combo.set_active(controller.kernel_find_edges_kernel_type) ;

  kernel_find_edges_kernel_hbox_01.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  kernel_find_edges_kernel_hbox_01.pack_start(kernel_find_edges_kernel_type_label, false, false, 0) ;
  kernel_find_edges_kernel_hbox_01.pack_start(kernel_find_edges_padding_01,        true,  true,  0) ;
  kernel_find_edges_kernel_hbox_01.pack_start(kernel_find_edges_kernel_type_combo, true,  true,  0) ;



  Gtk::Label          kernel_find_edges_kernel_ksize_label("Kernel size") ;

  Gtk::Label          kernel_find_edges_padding_02("") ;

  Gtk::SpinButton     kernel_find_edges_kernel_ksize_spinbutton ;

  Gtk::Box            kernel_find_edges_kernel_hbox_02(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  kernel_find_edges_kernel_ksize_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  kernel_find_edges_kernel_ksize_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  kernel_find_edges_kernel_ksize_spinbutton.set_digits(0) ;
  kernel_find_edges_kernel_ksize_spinbutton.set_range(3.0, 31.0)      ;
  kernel_find_edges_kernel_ksize_spinbutton.set_value(controller.kernel_find_edges_kernel_size)      ;
  kernel_find_edges_kernel_ksize_spinbutton.set_increments(2.0, 4.0)    ;
  kernel_find_edges_kernel_ksize_spinbutton.set_size_request(127-64, -1)    ;
  kernel_find_edges_kernel_ksize_spinbutton.set_snap_to_ticks(true)    ;
  kernel_find_edges_kernel_ksize_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  kernel_find_edges_kernel_ksize_spinbutton.set_adjustment( Gtk::Adjustment::create(controller.kernel_find_edges_kernel_size, 3.0, 31.0, 2.0, 4.0) ) ;


  kernel_find_edges_kernel_hbox_02.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  kernel_find_edges_kernel_hbox_02.pack_start(kernel_find_edges_kernel_ksize_label,      false, false, 0) ;
  kernel_find_edges_kernel_hbox_02.pack_start(kernel_find_edges_padding_02,              true,  true,  0) ;
  kernel_find_edges_kernel_hbox_02.pack_start(kernel_find_edges_kernel_ksize_spinbutton, false, false, 0) ;


  Gtk::Label          kernel_find_edges_kernel_values_factor_label("Values factor") ;

  Gtk::Label          kernel_find_edges_padding_03("") ;

  Gtk::Scale          kernel_find_edges_kernel_values_factor_scale(Gtk::ORIENTATION_HORIZONTAL) ;

  Gtk::Box            kernel_find_edges_kernel_hbox_03(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  kernel_find_edges_kernel_values_factor_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  kernel_find_edges_kernel_values_factor_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  kernel_find_edges_kernel_values_factor_scale.set_digits(2) ;
  kernel_find_edges_kernel_values_factor_scale.set_draw_value(true) ;
  kernel_find_edges_kernel_values_factor_scale.set_has_origin(true) ;
  kernel_find_edges_kernel_values_factor_scale.set_upper_stepper_sensitivity(Gtk::SENSITIVITY_ON) ;
  kernel_find_edges_kernel_values_factor_scale.set_lower_stepper_sensitivity(Gtk::SENSITIVITY_ON) ;
  kernel_find_edges_kernel_values_factor_scale.set_adjustment( kernel_find_edges_kernel_values_factor_scale.get_adjustment() )     ;
  kernel_find_edges_kernel_values_factor_scale.set_range(0.01, 5.00)      ;
  kernel_find_edges_kernel_values_factor_scale.set_value(controller.kernel_find_edges_kernel_values_factor)      ;
  kernel_find_edges_kernel_values_factor_scale.set_increments(0.01, 0.1)    ;
  kernel_find_edges_kernel_values_factor_scale.set_size_request(127-16-8, -1)    ;
  kernel_find_edges_kernel_values_factor_scale.add_mark(1.0, Gtk::POS_TOP, "")      ;

  kernel_find_edges_kernel_hbox_03.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  kernel_find_edges_kernel_hbox_03.pack_start(kernel_find_edges_kernel_values_factor_label, false, false, 0) ;
  kernel_find_edges_kernel_hbox_03.pack_start(kernel_find_edges_padding_03,                 true,  true,  0) ;
  kernel_find_edges_kernel_hbox_03.pack_start(kernel_find_edges_kernel_values_factor_scale, true,  true,  0) ;


  Gtk::Label          kernel_find_edges_kernel_center_factor_label("Center factor") ;

  Gtk::Label          kernel_find_edges_padding_04("") ;

  Gtk::Scale          kernel_find_edges_kernel_center_factor_scale(Gtk::ORIENTATION_HORIZONTAL) ;

  Gtk::Box            kernel_find_edges_kernel_hbox_04(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  kernel_find_edges_kernel_center_factor_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  kernel_find_edges_kernel_center_factor_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  kernel_find_edges_kernel_center_factor_scale.set_digits(2) ;
  kernel_find_edges_kernel_center_factor_scale.set_draw_value(true) ;
  kernel_find_edges_kernel_center_factor_scale.set_has_origin(true) ;
  kernel_find_edges_kernel_center_factor_scale.set_upper_stepper_sensitivity(Gtk::SENSITIVITY_ON) ;
  kernel_find_edges_kernel_center_factor_scale.set_lower_stepper_sensitivity(Gtk::SENSITIVITY_ON) ;
  kernel_find_edges_kernel_center_factor_scale.set_adjustment( kernel_find_edges_kernel_center_factor_scale.get_adjustment() )     ;
  kernel_find_edges_kernel_center_factor_scale.set_range(0.01, 5.00)      ;
  kernel_find_edges_kernel_center_factor_scale.set_value(controller.kernel_find_edges_kernel_center_factor)      ;
  kernel_find_edges_kernel_center_factor_scale.set_increments(0.01, 0.1)    ;
  kernel_find_edges_kernel_center_factor_scale.set_size_request(127-16-8, -1)    ;
  kernel_find_edges_kernel_center_factor_scale.add_mark(1.0, Gtk::POS_TOP, "")      ;

  kernel_find_edges_kernel_hbox_04.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  kernel_find_edges_kernel_hbox_04.pack_start(kernel_find_edges_kernel_center_factor_label, false, false, 0) ;
  kernel_find_edges_kernel_hbox_04.pack_start(kernel_find_edges_padding_04,                 true,  true,  0) ;
  kernel_find_edges_kernel_hbox_04.pack_start(kernel_find_edges_kernel_center_factor_scale, true,  true,  0) ;



  Gtk::Box            kernel_find_edges_kernel_hbox_05(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Label          kernel_find_edges_padding_05("") ;

  Gtk::Image          kernel_find_edges_kernel_display_image(PATH_TO_BUTTON_ICONS "transform-move.png") ;

  Gtk::Button         kernel_find_edges_kernel_display_button("   Preview kernel    ") ;

  kernel_find_edges_kernel_display_button.set_image(kernel_find_edges_kernel_display_image) ;

  kernel_find_edges_kernel_display_button.set_always_show_image(true) ;



  kernel_find_edges_kernel_hbox_05.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  kernel_find_edges_kernel_hbox_05.pack_start(kernel_find_edges_padding_05,            true,  true,  0) ;
  kernel_find_edges_kernel_hbox_05.pack_start(kernel_find_edges_kernel_display_button, false, false, 0) ;


  kernel_find_edges_kernel_main_vbox.pack_start(kernel_find_edges_kernel_hbox_01, false, false, 0) ;
  kernel_find_edges_kernel_main_vbox.pack_start(kernel_find_edges_kernel_hbox_02, false, false, 0) ;
  kernel_find_edges_kernel_main_vbox.pack_start(kernel_find_edges_kernel_hbox_03, false, false, 0) ;
  kernel_find_edges_kernel_main_vbox.pack_start(kernel_find_edges_kernel_hbox_04, false, false, 0) ;
  kernel_find_edges_kernel_main_vbox.pack_start(kernel_find_edges_kernel_hbox_05, false, false, 0) ;

  kernel_find_edges_kernel_frame.add(kernel_find_edges_kernel_main_vbox) ;


  Gtk::Frame          kernel_find_edges_kernel_actions_frame("") ;

  Gtk::Box            kernel_find_edges_kernel_actions_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          kernel_find_edges_kernel_actions_frame_widget_image(PATH_TO_MENU_ICONS "undo-redo.png") ;
  Gtk::Label          kernel_find_edges_kernel_actions_frame_widget_label(" Actions ") ;

  kernel_find_edges_kernel_actions_frame_widget_hbox.pack_start(kernel_find_edges_kernel_actions_frame_widget_image, false, false, 0) ;
  kernel_find_edges_kernel_actions_frame_widget_hbox.pack_start(kernel_find_edges_kernel_actions_frame_widget_label, false, false, 0) ;

  kernel_find_edges_kernel_actions_frame.set_label_widget(kernel_find_edges_kernel_actions_frame_widget_hbox) ;

  Gtk::Button         kernel_find_edges_kernel_actions_undo_button(" Undo ") ;

  Gtk::Image          kernel_find_edges_kernel_actions_undo_image(PATH_TO_BUTTON_ICONS "go-previous-view.png") ;

  Gtk::Box            kernel_find_edges_kernel_actions_padding(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Button         kernel_find_edges_kernel_actions_redo_button(" Redo ") ;

  Gtk::Image          kernel_find_edges_kernel_actions_redo_image(PATH_TO_BUTTON_ICONS "go-next-view.png") ;




  Gtk::Box            kernel_find_edges_kernel_actions_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  kernel_find_edges_kernel_actions_undo_button.set_image(kernel_find_edges_kernel_actions_undo_image) ;

  kernel_find_edges_kernel_actions_undo_button.set_always_show_image(true) ;

  kernel_find_edges_kernel_actions_undo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;
  kernel_find_edges_kernel_actions_redo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;

  kernel_find_edges_kernel_actions_redo_button.set_image(kernel_find_edges_kernel_actions_redo_image) ;

  kernel_find_edges_kernel_actions_redo_button.set_always_show_image(true) ;

  kernel_find_edges_kernel_actions_hbox.set_spacing(FILTER_DIALOG_BOX_SPACING) ;
  kernel_find_edges_kernel_actions_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;


  kernel_find_edges_kernel_actions_hbox.pack_start(kernel_find_edges_kernel_actions_undo_button,    false,   false, 0) ;
  kernel_find_edges_kernel_actions_hbox.pack_start(kernel_find_edges_kernel_actions_padding,        true,    true,  0) ;
  kernel_find_edges_kernel_actions_hbox.pack_start(kernel_find_edges_kernel_actions_redo_button,    false,   false, 0) ;

  kernel_find_edges_kernel_actions_frame.add(kernel_find_edges_kernel_actions_hbox) ;

  kernel_find_edges_kernel_actions_undo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::undo_callback), controller) ) ;
  kernel_find_edges_kernel_actions_redo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::redo_callback), controller) ) ;





  Gtk::Box *kernel_find_edges_main_content_box = dialog.get_content_area() ;

  kernel_find_edges_main_content_box->set_spacing(FILTER_DIALOG_BOX_SPACING) ;

  kernel_find_edges_main_content_box->pack_start(kernel_find_edges_explanation_frame,     false, false, 0) ;
  kernel_find_edges_main_content_box->pack_start(kernel_find_edges_kernel_frame,          false, false, 0) ;
  kernel_find_edges_main_content_box->pack_start(kernel_find_edges_kernel_actions_frame,  false, false, 0) ;



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

  // Display kernel button callback.
  kernel_find_edges_kernel_display_button.signal_clicked().connect([&kernel_find_edges_kernel_type_combo, &kernel_find_edges_kernel_ksize_spinbutton, &kernel_find_edges_kernel_values_factor_scale, &kernel_find_edges_kernel_center_factor_scale, this] () {

    string kernel_type ;

    switch (kernel_find_edges_kernel_type_combo.get_active_row_number()) {

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

    // Sea the libedip.
    Find_Edges kernel(static_cast<int>(kernel_find_edges_kernel_ksize_spinbutton.get_value()), kernel_type, static_cast<float>(kernel_find_edges_kernel_values_factor_scale.get_value()), '0', static_cast<float>(kernel_find_edges_kernel_center_factor_scale.get_value())) ;

    #ifdef DEBUG
    kernel.kernel_print() ;
    #endif

    this->display_kernel(kernel.kernel) ;

  } ) ;


  kernel_find_edges_main_content_box->show_all() ;

  renew_dialog :

  int ret = dialog.run() ;

  switch (ret) {

    case Gtk::RESPONSE_APPLY :


      controller.kernel_find_edges_kernel_type          = kernel_find_edges_kernel_type_combo.get_active_row_number()    ;
      controller.kernel_find_edges_kernel_size          = kernel_find_edges_kernel_ksize_spinbutton.get_value()          ;
      controller.kernel_find_edges_kernel_values_factor = kernel_find_edges_kernel_values_factor_scale.get_value()       ;
      controller.kernel_find_edges_kernel_center_factor = kernel_find_edges_kernel_center_factor_scale.get_value()       ;

      kernel_find_edges_callback(controller) ;

      goto renew_dialog ;


      break ;

    case Gtk::RESPONSE_CLOSE :

      dialog.close() ;

      break ;
  }

  dialog.close() ;

  return ;

}

void GUI::kernel_emboss_filter_dialog(Controller &controller) {

  /** Configurable Emboss kernel filter dialog window displaying. **/

  Gtk::Dialog dialog("Apply kernel Emboss filter.", false) ;

  // Configure dialog:
  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "transform-move.png") ;
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





  Gtk::Frame          kernel_emboss_explanation_frame("") ;

  Gtk::Box            kernel_emboss_explanation_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          kernel_emboss_explanation_frame_widget_image(PATH_TO_MENU_ICONS "applications-education-university.png") ;
  Gtk::Label          kernel_emboss_explanation_frame_widget_label(" Explanations ") ;

  Gtk::Label          kernel_emboss_explanation_label("A kernel is a set of weights which determine\n"
                                                       "how each output pixel is calculated\n"
                                                       "from a neighborhood of input pixels.\n"
                                                       "Applying a kernel filter consist of moving\n"
                                                       "the kernel over each pixel of an image\n"
                                                       "and multiplying each corresponding pixel\n"
                                                       "by it's associated weight.\n"
                                                       "According to that the central pixel\n"
                                                       "correspond to a pixel of interest\n"
                                                       "and the others to the neighborhood pixels.") ;

  kernel_emboss_explanation_label.set_tooltip_text("Confer the joined documentation for further\n"
                                                    "informations about kernels.") ;

  kernel_emboss_explanation_frame_widget_label.set_margin_left(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  kernel_emboss_explanation_frame_widget_label.set_margin_right(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  kernel_emboss_explanation_frame_widget_label.set_margin_top(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  kernel_emboss_explanation_frame_widget_label.set_margin_bottom(FILTER_DIALOG_FRAME_INNER_SPACE) ;

  kernel_emboss_explanation_frame_widget_hbox.pack_start(kernel_emboss_explanation_frame_widget_image, false, false, 0) ;
  kernel_emboss_explanation_frame_widget_hbox.pack_start(kernel_emboss_explanation_frame_widget_label, false, false, 0) ;

  kernel_emboss_explanation_frame.set_label_widget(kernel_emboss_explanation_frame_widget_hbox) ;

  kernel_emboss_explanation_label.set_margin_bottom(6) ;

  kernel_emboss_explanation_frame.add(kernel_emboss_explanation_label) ;



  Gtk::Frame          kernel_emboss_kernel_frame("") ;

  Gtk::Box            kernel_emboss_kernel_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          kernel_emboss_kernel_frame_widget_image(PATH_TO_MENU_ICONS "transform-move.png") ;
  Gtk::Label          kernel_emboss_kernel_frame_widget_label(" Emboss kernel ") ;

  kernel_emboss_kernel_frame_widget_hbox.pack_start(kernel_emboss_kernel_frame_widget_image, false, false, 0) ;
  kernel_emboss_kernel_frame_widget_hbox.pack_start(kernel_emboss_kernel_frame_widget_label, false, false, 0) ;

  kernel_emboss_kernel_frame.set_label_widget(kernel_emboss_kernel_frame_widget_hbox) ;



  Gtk::Box            kernel_emboss_kernel_main_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;

  kernel_emboss_kernel_main_vbox.set_spacing(FILTER_DIALOG_BOX_SPACING) ;



  Gtk::Label          kernel_emboss_kernel_ksize_label("Kernel size") ;

  Gtk::Label          kernel_emboss_padding_01("") ;

  Gtk::SpinButton     kernel_emboss_kernel_ksize_spinbutton ;

  Gtk::Box            kernel_emboss_kernel_hbox_01(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  kernel_emboss_kernel_ksize_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  kernel_emboss_kernel_ksize_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  kernel_emboss_kernel_ksize_spinbutton.set_digits(0) ;
  kernel_emboss_kernel_ksize_spinbutton.set_range(3.0, 31.0)      ;
  kernel_emboss_kernel_ksize_spinbutton.set_value(controller.kernel_emboss_kernel_size)      ;
  kernel_emboss_kernel_ksize_spinbutton.set_increments(2.0, 4.0)    ;
  kernel_emboss_kernel_ksize_spinbutton.set_size_request(127-64, -1)    ;
  kernel_emboss_kernel_ksize_spinbutton.set_snap_to_ticks(true)    ;
  kernel_emboss_kernel_ksize_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  kernel_emboss_kernel_ksize_spinbutton.set_adjustment( Gtk::Adjustment::create(controller.kernel_emboss_kernel_size, 3.0, 31.0, 2.0, 4.0) ) ;


  kernel_emboss_kernel_hbox_01.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  kernel_emboss_kernel_hbox_01.pack_start(kernel_emboss_kernel_ksize_label,      false, false, 0) ;
  kernel_emboss_kernel_hbox_01.pack_start(kernel_emboss_padding_01,              true,  true,  0) ;
  kernel_emboss_kernel_hbox_01.pack_start(kernel_emboss_kernel_ksize_spinbutton, false, false, 0) ;


  Gtk::Label          kernel_emboss_kernel_values_factor_label("Values factor") ;

  Gtk::Label          kernel_emboss_padding_02("") ;

  Gtk::Scale          kernel_emboss_kernel_values_factor_scale(Gtk::ORIENTATION_HORIZONTAL) ;

  Gtk::Box            kernel_emboss_kernel_hbox_02(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  kernel_emboss_kernel_values_factor_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  kernel_emboss_kernel_values_factor_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  kernel_emboss_kernel_values_factor_scale.set_digits(2) ;
  kernel_emboss_kernel_values_factor_scale.set_draw_value(true) ;
  kernel_emboss_kernel_values_factor_scale.set_has_origin(true) ;
  kernel_emboss_kernel_values_factor_scale.set_upper_stepper_sensitivity(Gtk::SENSITIVITY_ON) ;
  kernel_emboss_kernel_values_factor_scale.set_lower_stepper_sensitivity(Gtk::SENSITIVITY_ON) ;
  kernel_emboss_kernel_values_factor_scale.set_adjustment( kernel_emboss_kernel_values_factor_scale.get_adjustment() )     ;
  kernel_emboss_kernel_values_factor_scale.set_range(0.01, 5.00)      ;
  kernel_emboss_kernel_values_factor_scale.set_value(controller.kernel_emboss_kernel_values_factor)      ;
  kernel_emboss_kernel_values_factor_scale.set_increments(0.01, 0.1)    ;
  kernel_emboss_kernel_values_factor_scale.set_size_request(127-16-8, -1)    ;
  kernel_emboss_kernel_values_factor_scale.add_mark(1.0, Gtk::POS_TOP, "")      ;

  kernel_emboss_kernel_hbox_02.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  kernel_emboss_kernel_hbox_02.pack_start(kernel_emboss_kernel_values_factor_label, false, false, 0) ;
  kernel_emboss_kernel_hbox_02.pack_start(kernel_emboss_padding_02,                 true,  true,  0) ;
  kernel_emboss_kernel_hbox_02.pack_start(kernel_emboss_kernel_values_factor_scale, true,  true,  0) ;


  Gtk::Label          kernel_emboss_kernel_center_factor_label("Center factor") ;

  Gtk::Label          kernel_emboss_padding_03("") ;

  Gtk::Scale          kernel_emboss_kernel_center_factor_scale(Gtk::ORIENTATION_HORIZONTAL) ;

  Gtk::Box            kernel_emboss_kernel_hbox_03(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  kernel_emboss_kernel_center_factor_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  kernel_emboss_kernel_center_factor_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  kernel_emboss_kernel_center_factor_scale.set_digits(2) ;
  kernel_emboss_kernel_center_factor_scale.set_draw_value(true) ;
  kernel_emboss_kernel_center_factor_scale.set_has_origin(true) ;
  kernel_emboss_kernel_center_factor_scale.set_upper_stepper_sensitivity(Gtk::SENSITIVITY_ON) ;
  kernel_emboss_kernel_center_factor_scale.set_lower_stepper_sensitivity(Gtk::SENSITIVITY_ON) ;
  kernel_emboss_kernel_center_factor_scale.set_adjustment( kernel_emboss_kernel_center_factor_scale.get_adjustment() )     ;
  kernel_emboss_kernel_center_factor_scale.set_range(0.01, 5.00)      ;
  kernel_emboss_kernel_center_factor_scale.set_value(controller.kernel_emboss_kernel_center_factor)      ;
  kernel_emboss_kernel_center_factor_scale.set_increments(0.01, 0.1)    ;
  kernel_emboss_kernel_center_factor_scale.set_size_request(127-16-8, -1)    ;
  kernel_emboss_kernel_center_factor_scale.add_mark(1.0, Gtk::POS_TOP, "")      ;

  kernel_emboss_kernel_hbox_03.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  kernel_emboss_kernel_hbox_03.pack_start(kernel_emboss_kernel_center_factor_label, false, false, 0) ;
  kernel_emboss_kernel_hbox_03.pack_start(kernel_emboss_padding_03,                 true,  true,  0) ;
  kernel_emboss_kernel_hbox_03.pack_start(kernel_emboss_kernel_center_factor_scale, true,  true,  0) ;



  Gtk::Box            kernel_emboss_kernel_hbox_04(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Label          kernel_emboss_padding_04("") ;

  Gtk::Image          kernel_emboss_kernel_display_image(PATH_TO_BUTTON_ICONS "transform-move.png") ;

  Gtk::Button         kernel_emboss_kernel_display_button("   Preview kernel    ") ;

  kernel_emboss_kernel_display_button.set_image(kernel_emboss_kernel_display_image) ;

  kernel_emboss_kernel_display_button.set_always_show_image(true) ;


  kernel_emboss_kernel_hbox_04.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  kernel_emboss_kernel_hbox_04.pack_start(kernel_emboss_padding_04,            true,  true,  0) ;
  kernel_emboss_kernel_hbox_04.pack_start(kernel_emboss_kernel_display_button, false, false, 0) ;


  kernel_emboss_kernel_main_vbox.pack_start(kernel_emboss_kernel_hbox_01, false, false, 0) ;
  kernel_emboss_kernel_main_vbox.pack_start(kernel_emboss_kernel_hbox_02, false, false, 0) ;
  kernel_emboss_kernel_main_vbox.pack_start(kernel_emboss_kernel_hbox_03, false, false, 0) ;
  kernel_emboss_kernel_main_vbox.pack_start(kernel_emboss_kernel_hbox_04, false, false, 0) ;

  kernel_emboss_kernel_frame.add(kernel_emboss_kernel_main_vbox) ;


  Gtk::Button         kernel_emboss_kernel_actions_undo_button(" Undo ") ;

  Gtk::Image          kernel_emboss_kernel_actions_undo_image(PATH_TO_BUTTON_ICONS "go-previous-view.png") ;

  Gtk::Box            kernel_emboss_kernel_actions_padding(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Button         kernel_emboss_kernel_actions_redo_button(" Redo ") ;

  Gtk::Image          kernel_emboss_kernel_actions_redo_image(PATH_TO_BUTTON_ICONS "go-next-view.png") ;


  Gtk::Frame          kernel_emboss_kernel_actions_frame("") ;

  Gtk::Box            kernel_emboss_kernel_actions_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          kernel_emboss_kernel_actions_frame_widget_image(PATH_TO_MENU_ICONS "undo-redo.png") ;
  Gtk::Label          kernel_emboss_kernel_actions_frame_widget_label(" Actions ") ;

  kernel_emboss_kernel_actions_frame_widget_hbox.pack_start(kernel_emboss_kernel_actions_frame_widget_image, false, false, 0) ;
  kernel_emboss_kernel_actions_frame_widget_hbox.pack_start(kernel_emboss_kernel_actions_frame_widget_label, false, false, 0) ;

  kernel_emboss_kernel_actions_frame.set_label_widget(kernel_emboss_kernel_actions_frame_widget_hbox) ;

  Gtk::Box            kernel_emboss_kernel_actions_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  kernel_emboss_kernel_actions_undo_button.set_image(kernel_emboss_kernel_actions_undo_image) ;

  kernel_emboss_kernel_actions_undo_button.set_always_show_image(true) ;

  kernel_emboss_kernel_actions_undo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;
  kernel_emboss_kernel_actions_redo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;

  kernel_emboss_kernel_actions_redo_button.set_image(kernel_emboss_kernel_actions_redo_image) ;

  kernel_emboss_kernel_actions_redo_button.set_always_show_image(true) ;

  kernel_emboss_kernel_actions_hbox.set_spacing(FILTER_DIALOG_BOX_SPACING) ;
  kernel_emboss_kernel_actions_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;


  kernel_emboss_kernel_actions_hbox.pack_start(kernel_emboss_kernel_actions_undo_button,    false,   false, 0) ;
  kernel_emboss_kernel_actions_hbox.pack_start(kernel_emboss_kernel_actions_padding,        true,    true,  0) ;
  kernel_emboss_kernel_actions_hbox.pack_start(kernel_emboss_kernel_actions_redo_button,    false,   false, 0) ;

  kernel_emboss_kernel_actions_frame.add(kernel_emboss_kernel_actions_hbox) ;

  kernel_emboss_kernel_actions_undo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::undo_callback), controller) ) ;
  kernel_emboss_kernel_actions_redo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::redo_callback), controller) ) ;







  Gtk::Box *kernel_emboss_main_content_box = dialog.get_content_area() ;

  kernel_emboss_main_content_box->set_spacing(FILTER_DIALOG_BOX_SPACING) ;

  kernel_emboss_main_content_box->pack_start(kernel_emboss_explanation_frame,     false, false, 0) ;
  kernel_emboss_main_content_box->pack_start(kernel_emboss_kernel_frame,          false, false, 0) ;
  kernel_emboss_main_content_box->pack_start(kernel_emboss_kernel_actions_frame,  false, false, 0) ;



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

  // Display kernel button callback.
  kernel_emboss_kernel_display_button.signal_clicked().connect([&kernel_emboss_kernel_ksize_spinbutton, &kernel_emboss_kernel_values_factor_scale, &kernel_emboss_kernel_center_factor_scale, this] () {

    // Sea libedip.
    Emboss kernel(static_cast<int>(kernel_emboss_kernel_ksize_spinbutton.get_value()), static_cast<float>(kernel_emboss_kernel_values_factor_scale.get_value()), '+', static_cast<float>(kernel_emboss_kernel_center_factor_scale.get_value())) ;

    #ifdef DEBUG
    kernel.kernel_print() ;
    #endif

    this->display_kernel(kernel.kernel) ;

  } ) ;

  kernel_emboss_main_content_box->show_all() ;

  renew_dialog :

  int ret = dialog.run() ;

  switch (ret) {

    case Gtk::RESPONSE_APPLY :

      controller.kernel_emboss_kernel_size          = kernel_emboss_kernel_ksize_spinbutton.get_value()     ;
      controller.kernel_emboss_kernel_values_factor = kernel_emboss_kernel_values_factor_scale.get_value()  ;
      controller.kernel_emboss_kernel_center_factor = kernel_emboss_kernel_center_factor_scale.get_value()  ;

      kernel_emboss_callback(controller) ;

      goto renew_dialog ;


      break ;

    case Gtk::RESPONSE_CLOSE :

      dialog.close() ;

      break ;
  }

  dialog.close() ;

  return ;

}

void GUI::kernel_mean_filter_dialog(Controller &controller) {

  /** Configurable Mean kernel filter dialog window displaying. **/

  Gtk::Dialog dialog("Apply kernel Mean filter.", false) ;

  // Configure dialog.
  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "transform-move.png") ;
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





  Gtk::Frame          kernel_mean_explanation_frame("") ;

  Gtk::Box            kernel_mean_explanation_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          kernel_mean_explanation_frame_widget_image(PATH_TO_MENU_ICONS "applications-education-university.png") ;
  Gtk::Label          kernel_mean_explanation_frame_widget_label(" Explanations ") ;

  Gtk::Label          kernel_mean_explanation_label("A kernel is a set of weights which determine\n"
                                                       "how each output pixel is calculated\n"
                                                       "from a neighborhood of input pixels.\n"
                                                       "Applying a kernel filter consist of moving\n"
                                                       "the kernel over each pixel of an image\n"
                                                       "and multiplying each corresponding pixel\n"
                                                       "by it's associated weight.\n"
                                                       "According to that the central pixel\n"
                                                       "correspond to a pixel of interest\n"
                                                       "and the others to the neighborhood pixels.") ;
                                                

  kernel_mean_explanation_label.set_tooltip_text("Confer the joined documentation for further\n"
                                                 "informations about kernels.") ;

  kernel_mean_explanation_frame_widget_label.set_margin_left(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  kernel_mean_explanation_frame_widget_label.set_margin_right(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  kernel_mean_explanation_frame_widget_label.set_margin_top(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  kernel_mean_explanation_frame_widget_label.set_margin_bottom(FILTER_DIALOG_FRAME_INNER_SPACE) ;

  kernel_mean_explanation_frame_widget_hbox.pack_start(kernel_mean_explanation_frame_widget_image, false, false, 0) ;
  kernel_mean_explanation_frame_widget_hbox.pack_start(kernel_mean_explanation_frame_widget_label, false, false, 0) ;

  kernel_mean_explanation_frame.set_label_widget(kernel_mean_explanation_frame_widget_hbox) ;

  kernel_mean_explanation_label.set_margin_bottom(6) ;

  kernel_mean_explanation_frame.add(kernel_mean_explanation_label) ;



  Gtk::Frame          kernel_mean_kernel_frame("") ;

  Gtk::Box            kernel_mean_kernel_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          kernel_mean_kernel_frame_widget_image(PATH_TO_MENU_ICONS "transform-move.png") ;
  Gtk::Label          kernel_mean_kernel_frame_widget_label(" Mean kernel ") ;

  kernel_mean_kernel_frame_widget_hbox.pack_start(kernel_mean_kernel_frame_widget_image, false, false, 0) ;
  kernel_mean_kernel_frame_widget_hbox.pack_start(kernel_mean_kernel_frame_widget_label, false, false, 0) ;

  kernel_mean_kernel_frame.set_label_widget(kernel_mean_kernel_frame_widget_hbox) ;



  Gtk::Box            kernel_mean_kernel_main_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;

  kernel_mean_kernel_main_vbox.set_spacing(FILTER_DIALOG_BOX_SPACING) ;



  Gtk::Label          kernel_mean_kernel_type_label("Kernel type") ;

  Gtk::Label          kernel_mean_padding_01("") ;

  Gtk::ComboBoxText   kernel_mean_kernel_type_combo ;

  Gtk::Box            kernel_mean_kernel_hbox_01(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  kernel_mean_kernel_type_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  kernel_mean_kernel_type_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  kernel_mean_kernel_type_combo.insert(0, "Square") ;
  kernel_mean_kernel_type_combo.insert(1, "Diamond") ;
  kernel_mean_kernel_type_combo.insert(2, "Cross") ;
  kernel_mean_kernel_type_combo.insert(3, "X") ;

  kernel_mean_kernel_type_combo.set_active(controller.kernel_mean_kernel_type) ;

  kernel_mean_kernel_hbox_01.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  kernel_mean_kernel_hbox_01.pack_start(kernel_mean_kernel_type_label, false, false, 0) ;
  kernel_mean_kernel_hbox_01.pack_start(kernel_mean_padding_01,        true,  true,  0) ;
  kernel_mean_kernel_hbox_01.pack_start(kernel_mean_kernel_type_combo, true,  true,  0) ;



  Gtk::Label          kernel_mean_kernel_ksize_label("Kernel size") ;

  Gtk::Label          kernel_mean_padding_02("") ;

  Gtk::SpinButton     kernel_mean_kernel_ksize_spinbutton ;

  Gtk::Box            kernel_mean_kernel_hbox_02(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  kernel_mean_kernel_ksize_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  kernel_mean_kernel_ksize_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  kernel_mean_kernel_ksize_spinbutton.set_digits(0) ;
  kernel_mean_kernel_ksize_spinbutton.set_range(3.0, 31.0)      ;
  kernel_mean_kernel_ksize_spinbutton.set_value(controller.kernel_mean_kernel_size)      ;
  kernel_mean_kernel_ksize_spinbutton.set_increments(2.0, 4.0)    ;
  kernel_mean_kernel_ksize_spinbutton.set_size_request(127-64, -1)    ;
  kernel_mean_kernel_ksize_spinbutton.set_snap_to_ticks(true)    ;
  kernel_mean_kernel_ksize_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  kernel_mean_kernel_ksize_spinbutton.set_adjustment( Gtk::Adjustment::create(controller.kernel_mean_kernel_size, 3.0, 31.0, 2.0, 4.0) ) ;


  kernel_mean_kernel_hbox_02.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  kernel_mean_kernel_hbox_02.pack_start(kernel_mean_kernel_ksize_label,      false, false, 0) ;
  kernel_mean_kernel_hbox_02.pack_start(kernel_mean_padding_02,              true,  true,  0) ;
  kernel_mean_kernel_hbox_02.pack_start(kernel_mean_kernel_ksize_spinbutton, false, false, 0) ;





  Gtk::Box            kernel_mean_kernel_hbox_03(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Label          kernel_mean_padding_03("") ;

  Gtk::Image          kernel_mean_kernel_display_image(PATH_TO_BUTTON_ICONS "transform-move.png") ;

  Gtk::Button         kernel_mean_kernel_display_button("   Preview kernel    ") ;

  kernel_mean_kernel_display_button.set_image(kernel_mean_kernel_display_image) ;

  kernel_mean_kernel_display_button.set_always_show_image(true) ;



  kernel_mean_kernel_hbox_03.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  kernel_mean_kernel_hbox_03.pack_start(kernel_mean_padding_03,            true,  true,  0) ;
  kernel_mean_kernel_hbox_03.pack_start(kernel_mean_kernel_display_button, false, false, 0) ;


  kernel_mean_kernel_main_vbox.pack_start(kernel_mean_kernel_hbox_01, false, false, 0) ;
  kernel_mean_kernel_main_vbox.pack_start(kernel_mean_kernel_hbox_02, false, false, 0) ;
  kernel_mean_kernel_main_vbox.pack_start(kernel_mean_kernel_hbox_03, false, false, 0) ;

  kernel_mean_kernel_frame.add(kernel_mean_kernel_main_vbox) ;


  Gtk::Frame          kernel_mean_kernel_actions_frame("") ;

  Gtk::Box            kernel_mean_kernel_actions_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          kernel_mean_kernel_actions_frame_widget_image(PATH_TO_MENU_ICONS "undo-redo.png") ;
  Gtk::Label          kernel_mean_kernel_actions_frame_widget_label(" Actions ") ;

  kernel_mean_kernel_actions_frame_widget_hbox.pack_start(kernel_mean_kernel_actions_frame_widget_image, false, false, 0) ;
  kernel_mean_kernel_actions_frame_widget_hbox.pack_start(kernel_mean_kernel_actions_frame_widget_label, false, false, 0) ;

  kernel_mean_kernel_actions_frame.set_label_widget(kernel_mean_kernel_actions_frame_widget_hbox) ;

  Gtk::Button         kernel_mean_kernel_actions_undo_button(" Undo ") ;

  Gtk::Image          kernel_mean_kernel_actions_undo_image(PATH_TO_BUTTON_ICONS "go-previous-view.png") ;

  Gtk::Box            kernel_mean_kernel_actions_padding(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Button         kernel_mean_kernel_actions_redo_button(" Redo ") ;

  Gtk::Image          kernel_mean_kernel_actions_redo_image(PATH_TO_BUTTON_ICONS "go-next-view.png") ;




  Gtk::Box            kernel_mean_kernel_actions_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  kernel_mean_kernel_actions_undo_button.set_image(kernel_mean_kernel_actions_undo_image) ;

  kernel_mean_kernel_actions_undo_button.set_always_show_image(true) ;

  kernel_mean_kernel_actions_undo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;
  kernel_mean_kernel_actions_redo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;

  kernel_mean_kernel_actions_redo_button.set_image(kernel_mean_kernel_actions_redo_image) ;

  kernel_mean_kernel_actions_redo_button.set_always_show_image(true) ;

  kernel_mean_kernel_actions_hbox.set_spacing(FILTER_DIALOG_BOX_SPACING) ;
  kernel_mean_kernel_actions_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;


  kernel_mean_kernel_actions_hbox.pack_start(kernel_mean_kernel_actions_undo_button,    false,   false, 0) ;
  kernel_mean_kernel_actions_hbox.pack_start(kernel_mean_kernel_actions_padding,        true,    true,  0) ;
  kernel_mean_kernel_actions_hbox.pack_start(kernel_mean_kernel_actions_redo_button,    false,   false, 0) ;

  kernel_mean_kernel_actions_frame.add(kernel_mean_kernel_actions_hbox) ;

  kernel_mean_kernel_actions_undo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::undo_callback), controller) ) ;
  kernel_mean_kernel_actions_redo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::redo_callback), controller) ) ;








  Gtk::Box *kernel_mean_main_content_box = dialog.get_content_area() ;

  kernel_mean_main_content_box->set_spacing(FILTER_DIALOG_BOX_SPACING) ;

  kernel_mean_main_content_box->pack_start(kernel_mean_explanation_frame,     false, false, 0) ;
  kernel_mean_main_content_box->pack_start(kernel_mean_kernel_frame,          false, false, 0) ;
  kernel_mean_main_content_box->pack_start(kernel_mean_kernel_actions_frame,  false, false, 0) ;



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

  // Display kernel button callback.
  kernel_mean_kernel_display_button.signal_clicked().connect([&kernel_mean_kernel_type_combo, &kernel_mean_kernel_ksize_spinbutton, this] () {

    string kernel_type ;

    switch (kernel_mean_kernel_type_combo.get_active_row_number()) {

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

    // Sea libedip.
    Mean kernel(static_cast<int>(kernel_mean_kernel_ksize_spinbutton.get_value()), kernel_type ) ;

    #ifdef DEBUG
    kernel.kernel_print() ;
    #endif

    this->display_kernel(kernel.kernel, 3) ;

  } ) ;


  kernel_mean_main_content_box->show_all() ;

  renew_dialog :

  int ret = dialog.run() ;

  switch (ret) {

    case Gtk::RESPONSE_APPLY :


      controller.kernel_mean_kernel_type   = kernel_mean_kernel_type_combo.get_active_row_number()     ;
      controller.kernel_mean_kernel_size   = kernel_mean_kernel_ksize_spinbutton.get_value()           ;

      kernel_mean_callback(controller) ;

      goto renew_dialog ;


      break ;

    case Gtk::RESPONSE_CLOSE :

      dialog.close() ;

      break ;
  }

  dialog.close() ;

  return ;

}

void GUI::kernel_gaussian_filter_dialog(Controller &controller) {

  /** Configurable Gaussian kernel filter dialog window displaying. **/

  Gtk::Dialog dialog("Apply kernel Gaussian filter.", false) ;


  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "transform-move.png") ;
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





  Gtk::Frame          kernel_gaussian_explanation_frame("") ;

  Gtk::Box            kernel_gaussian_explanation_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          kernel_gaussian_explanation_frame_widget_image(PATH_TO_MENU_ICONS "applications-education-university.png") ;
  Gtk::Label          kernel_gaussian_explanation_frame_widget_label(" Explanations ") ;

  Gtk::Label          kernel_gaussian_explanation_label("A kernel is a set of weights which determine\n"
                                                       "how each output pixel is calculated\n"
                                                       "from a neighborhood of input pixels.\n"
                                                       "Applying a kernel filter consist of moving\n"
                                                       "the kernel over each pixel of an image\n"
                                                       "and multiplying each corresponding pixel\n"
                                                       "by it's associated weight.\n"
                                                       "According to that the central pixel\n"
                                                       "correspond to a pixel of interest\n"
                                                       "and the others to the neighborhood pixels.") ;

  kernel_gaussian_explanation_label.set_tooltip_text("Confer the joined documentation for further\n"
                                                     "informations about kernels.") ;

  kernel_gaussian_explanation_frame_widget_label.set_margin_left(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  kernel_gaussian_explanation_frame_widget_label.set_margin_right(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  kernel_gaussian_explanation_frame_widget_label.set_margin_top(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  kernel_gaussian_explanation_frame_widget_label.set_margin_bottom(FILTER_DIALOG_FRAME_INNER_SPACE) ;

  kernel_gaussian_explanation_frame_widget_hbox.pack_start(kernel_gaussian_explanation_frame_widget_image, false, false, 0) ;
  kernel_gaussian_explanation_frame_widget_hbox.pack_start(kernel_gaussian_explanation_frame_widget_label, false, false, 0) ;

  kernel_gaussian_explanation_frame.set_label_widget(kernel_gaussian_explanation_frame_widget_hbox) ;

  kernel_gaussian_explanation_label.set_margin_bottom(6) ;

  kernel_gaussian_explanation_frame.add(kernel_gaussian_explanation_label) ;



  Gtk::Frame          kernel_gaussian_kernel_frame("") ;

  Gtk::Box            kernel_gaussian_kernel_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          kernel_gaussian_kernel_frame_widget_image(PATH_TO_MENU_ICONS "transform-move.png") ;
  Gtk::Label          kernel_gaussian_kernel_frame_widget_label(" Gaussian kernel ") ;

  kernel_gaussian_kernel_frame_widget_hbox.pack_start(kernel_gaussian_kernel_frame_widget_image, false, false, 0) ;
  kernel_gaussian_kernel_frame_widget_hbox.pack_start(kernel_gaussian_kernel_frame_widget_label, false, false, 0) ;

  kernel_gaussian_kernel_frame.set_label_widget(kernel_gaussian_kernel_frame_widget_hbox) ;



  Gtk::Box            kernel_gaussian_kernel_main_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;

  kernel_gaussian_kernel_main_vbox.set_spacing(FILTER_DIALOG_BOX_SPACING) ;



  Gtk::Label          kernel_gaussian_kernel_type_label("Kernel type") ;

  Gtk::Label          kernel_gaussian_padding_01("") ;

  Gtk::ComboBoxText   kernel_gaussian_kernel_type_combo ;

  Gtk::Box            kernel_gaussian_kernel_hbox_01(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  kernel_gaussian_kernel_type_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  kernel_gaussian_kernel_type_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  kernel_gaussian_kernel_type_combo.insert(0, "Square") ;
  kernel_gaussian_kernel_type_combo.insert(1, "Diamond") ;
  kernel_gaussian_kernel_type_combo.insert(2, "Cross") ;
  kernel_gaussian_kernel_type_combo.insert(3, "X") ;

  kernel_gaussian_kernel_type_combo.set_active(controller.kernel_gaussian_kernel_type) ;

  kernel_gaussian_kernel_hbox_01.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  kernel_gaussian_kernel_hbox_01.pack_start(kernel_gaussian_kernel_type_label, false, false, 0) ;
  kernel_gaussian_kernel_hbox_01.pack_start(kernel_gaussian_padding_01,        true,  true,  0) ;
  kernel_gaussian_kernel_hbox_01.pack_start(kernel_gaussian_kernel_type_combo, true,  true,  0) ;



  Gtk::Label          kernel_gaussian_kernel_ksize_label("Kernel size") ;

  Gtk::Label          kernel_gaussian_padding_02("") ;

  Gtk::SpinButton     kernel_gaussian_kernel_ksize_spinbutton ;

  Gtk::Box            kernel_gaussian_kernel_hbox_02(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  kernel_gaussian_kernel_ksize_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  kernel_gaussian_kernel_ksize_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  kernel_gaussian_kernel_ksize_spinbutton.set_digits(0) ;
  kernel_gaussian_kernel_ksize_spinbutton.set_range(3.0, 31.0)      ;
  kernel_gaussian_kernel_ksize_spinbutton.set_value(controller.kernel_gaussian_kernel_size)      ;
  kernel_gaussian_kernel_ksize_spinbutton.set_increments(2.0, 4.0)    ;
  kernel_gaussian_kernel_ksize_spinbutton.set_size_request(127-64, -1)    ;
  kernel_gaussian_kernel_ksize_spinbutton.set_snap_to_ticks(true)    ;
  kernel_gaussian_kernel_ksize_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  kernel_gaussian_kernel_ksize_spinbutton.set_adjustment( Gtk::Adjustment::create(controller.kernel_gaussian_kernel_size, 3.0, 31.0, 2.0, 4.0) ) ;


  kernel_gaussian_kernel_hbox_02.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  kernel_gaussian_kernel_hbox_02.pack_start(kernel_gaussian_kernel_ksize_label,      false, false, 0) ;
  kernel_gaussian_kernel_hbox_02.pack_start(kernel_gaussian_padding_02,              true,  true,  0) ;
  kernel_gaussian_kernel_hbox_02.pack_start(kernel_gaussian_kernel_ksize_spinbutton, false, false, 0) ;


  Gtk::Label          kernel_gaussian_sigma_value_factor_label("Sigma value") ;

  Gtk::Label          kernel_gaussian_padding_03("") ;

  Gtk::Scale          kernel_gaussian_sigma_value_factor_scale(Gtk::ORIENTATION_HORIZONTAL) ;

  Gtk::Box            kernel_gaussian_kernel_hbox_03(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  kernel_gaussian_sigma_value_factor_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  kernel_gaussian_sigma_value_factor_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  kernel_gaussian_sigma_value_factor_scale.set_digits(2) ;
  kernel_gaussian_sigma_value_factor_scale.set_draw_value(true) ;
  kernel_gaussian_sigma_value_factor_scale.set_has_origin(true) ;
  kernel_gaussian_sigma_value_factor_scale.set_upper_stepper_sensitivity(Gtk::SENSITIVITY_ON) ;
  kernel_gaussian_sigma_value_factor_scale.set_lower_stepper_sensitivity(Gtk::SENSITIVITY_ON) ;
  kernel_gaussian_sigma_value_factor_scale.set_adjustment( kernel_gaussian_sigma_value_factor_scale.get_adjustment() )     ;
  kernel_gaussian_sigma_value_factor_scale.set_range(0.01, 5.00)      ;
  kernel_gaussian_sigma_value_factor_scale.set_value(controller.kernel_gaussian_sigma_value)      ;
  kernel_gaussian_sigma_value_factor_scale.set_increments(0.01, 0.1)    ;
  kernel_gaussian_sigma_value_factor_scale.set_size_request(127-16-8, -1)    ;
  kernel_gaussian_sigma_value_factor_scale.add_mark(1.0, Gtk::POS_TOP, "")      ;

  kernel_gaussian_kernel_hbox_03.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  kernel_gaussian_kernel_hbox_03.pack_start(kernel_gaussian_sigma_value_factor_label,   false, false, 0) ;
  kernel_gaussian_kernel_hbox_03.pack_start(kernel_gaussian_padding_03,                 true,  true,  0) ;
  kernel_gaussian_kernel_hbox_03.pack_start(kernel_gaussian_sigma_value_factor_scale,   true,  true,  0) ;






  Gtk::Box            kernel_gaussian_kernel_hbox_04(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Label          kernel_gaussian_padding_04("") ;

  Gtk::Image          kernel_gaussian_kernel_display_image(PATH_TO_BUTTON_ICONS "transform-move.png") ;

  Gtk::Button         kernel_gaussian_kernel_display_button("   Preview kernel    ") ;

  kernel_gaussian_kernel_display_button.set_image(kernel_gaussian_kernel_display_image) ;

  kernel_gaussian_kernel_display_button.set_always_show_image(true) ;


  kernel_gaussian_kernel_hbox_04.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  kernel_gaussian_kernel_hbox_04.pack_start(kernel_gaussian_padding_04,            true,  true,  0) ;
  kernel_gaussian_kernel_hbox_04.pack_start(kernel_gaussian_kernel_display_button, false, false, 0) ;


  kernel_gaussian_kernel_main_vbox.pack_start(kernel_gaussian_kernel_hbox_01, false, false, 0) ;
  kernel_gaussian_kernel_main_vbox.pack_start(kernel_gaussian_kernel_hbox_02, false, false, 0) ;
  kernel_gaussian_kernel_main_vbox.pack_start(kernel_gaussian_kernel_hbox_03, false, false, 0) ;
  kernel_gaussian_kernel_main_vbox.pack_start(kernel_gaussian_kernel_hbox_04, false, false, 0) ;

  kernel_gaussian_kernel_frame.add(kernel_gaussian_kernel_main_vbox) ;



  Gtk::Frame          kernel_gaussian_kernel_actions_frame("") ;

  Gtk::Box            kernel_gaussian_kernel_actions_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          kernel_gaussian_kernel_actions_frame_widget_image(PATH_TO_MENU_ICONS "undo-redo.png") ;
  Gtk::Label          kernel_gaussian_kernel_actions_frame_widget_label(" Actions ") ;

  kernel_gaussian_kernel_actions_frame_widget_hbox.pack_start(kernel_gaussian_kernel_actions_frame_widget_image, false, false, 0) ;
  kernel_gaussian_kernel_actions_frame_widget_hbox.pack_start(kernel_gaussian_kernel_actions_frame_widget_label, false, false, 0) ;

  kernel_gaussian_kernel_actions_frame.set_label_widget(kernel_gaussian_kernel_actions_frame_widget_hbox) ;

  Gtk::Button         kernel_gaussian_kernel_actions_undo_button(" Undo ") ;

  Gtk::Image          kernel_gaussian_kernel_actions_undo_image(PATH_TO_BUTTON_ICONS "go-previous-view.png") ;

  Gtk::Box            kernel_gaussian_kernel_actions_padding(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Button         kernel_gaussian_kernel_actions_redo_button(" Redo ") ;

  Gtk::Image          kernel_gaussian_kernel_actions_redo_image(PATH_TO_BUTTON_ICONS "go-next-view.png") ;




  Gtk::Box            kernel_gaussian_kernel_actions_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  kernel_gaussian_kernel_actions_undo_button.set_image(kernel_gaussian_kernel_actions_undo_image) ;

  kernel_gaussian_kernel_actions_undo_button.set_always_show_image(true) ;

  kernel_gaussian_kernel_actions_undo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;
  kernel_gaussian_kernel_actions_redo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;

  kernel_gaussian_kernel_actions_redo_button.set_image(kernel_gaussian_kernel_actions_redo_image) ;

  kernel_gaussian_kernel_actions_redo_button.set_always_show_image(true) ;

  kernel_gaussian_kernel_actions_hbox.set_spacing(FILTER_DIALOG_BOX_SPACING) ;
  kernel_gaussian_kernel_actions_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;


  kernel_gaussian_kernel_actions_hbox.pack_start(kernel_gaussian_kernel_actions_undo_button,    false,   false, 0) ;
  kernel_gaussian_kernel_actions_hbox.pack_start(kernel_gaussian_kernel_actions_padding,        true,    true,  0) ;
  kernel_gaussian_kernel_actions_hbox.pack_start(kernel_gaussian_kernel_actions_redo_button,    false,   false, 0) ;

  kernel_gaussian_kernel_actions_frame.add(kernel_gaussian_kernel_actions_hbox) ;

  kernel_gaussian_kernel_actions_undo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::undo_callback), controller) ) ;
  kernel_gaussian_kernel_actions_redo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::redo_callback), controller) ) ;





  Gtk::Box *kernel_gaussian_main_content_box = dialog.get_content_area() ;

  kernel_gaussian_main_content_box->set_spacing(FILTER_DIALOG_BOX_SPACING) ;

  kernel_gaussian_main_content_box->pack_start(kernel_gaussian_explanation_frame,     false, false, 0) ;
  kernel_gaussian_main_content_box->pack_start(kernel_gaussian_kernel_frame,          false, false, 0) ;
  kernel_gaussian_main_content_box->pack_start(kernel_gaussian_kernel_actions_frame,  false, false, 0) ;



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

  // Display kernel button callback.
  kernel_gaussian_kernel_display_button.signal_clicked().connect([&kernel_gaussian_kernel_type_combo, &kernel_gaussian_kernel_ksize_spinbutton, &kernel_gaussian_sigma_value_factor_scale, this] () {

    string kernel_type ;

    switch (kernel_gaussian_kernel_type_combo.get_active_row_number()) {

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

    // Sea libedip.
    Gaussian kernel(static_cast<int>(kernel_gaussian_kernel_ksize_spinbutton.get_value()), kernel_gaussian_sigma_value_factor_scale.get_value(), kernel_type) ;

    #ifdef DEBUG
    kernel.kernel_print() ;
    #endif

    this->display_kernel(kernel.kernel, 3) ;

  } ) ;


  kernel_gaussian_main_content_box->show_all() ;

  renew_dialog :

  int ret = dialog.run() ;

  switch (ret) {

    case Gtk::RESPONSE_APPLY :

      controller.kernel_gaussian_kernel_type   = kernel_gaussian_kernel_type_combo.get_active_row_number()     ;
      controller.kernel_gaussian_kernel_size   = kernel_gaussian_kernel_ksize_spinbutton.get_value()           ;
      controller.kernel_gaussian_sigma_value   = kernel_gaussian_sigma_value_factor_scale.get_value()          ;

      kernel_gaussian_callback(controller) ;

      goto renew_dialog ;


      break ;

    case Gtk::RESPONSE_CLOSE :

      dialog.close() ;

      break ;
  }

  dialog.close() ;

  return ;

}

void GUI::kernel_kirsch_filter_dialog(Controller &controller) {

  /** Configurable Kirsch kernel filter dialog window displaying. **/

  Gtk::Dialog dialog("Apply kernel Kirsch filter.", false) ;

  // Configure dialog:
  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "transform-move.png") ;
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





  Gtk::Frame          kernel_kirsch_explanation_frame("") ;

  Gtk::Box            kernel_kirsch_explanation_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          kernel_kirsch_explanation_frame_widget_image(PATH_TO_MENU_ICONS "applications-education-university.png") ;
  Gtk::Label          kernel_kirsch_explanation_frame_widget_label(" Explanations ") ;

  Gtk::Label          kernel_kirsch_explanation_label("A kernel is a set of weights which determine\n"
                                                       "how each output pixel is calculated\n"
                                                       "from a neighborhood of input pixels.\n"
                                                       "Applying a kernel filter consist of moving\n"
                                                       "the kernel over each pixel of an image\n"
                                                       "and multiplying each corresponding pixel\n"
                                                       "by it's associated weight.\n"
                                                       "According to that the central pixel\n"
                                                       "correspond to a pixel of interest\n"
                                                       "and the others to the neighborhood pixels.") ;

  kernel_kirsch_explanation_label.set_tooltip_text("Confer the joined documentation for further\n"
                                                    "informations about kernels.") ;

  kernel_kirsch_explanation_frame_widget_label.set_margin_left(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  kernel_kirsch_explanation_frame_widget_label.set_margin_right(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  kernel_kirsch_explanation_frame_widget_label.set_margin_top(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  kernel_kirsch_explanation_frame_widget_label.set_margin_bottom(FILTER_DIALOG_FRAME_INNER_SPACE) ;

  kernel_kirsch_explanation_frame_widget_hbox.pack_start(kernel_kirsch_explanation_frame_widget_image, false, false, 0) ;
  kernel_kirsch_explanation_frame_widget_hbox.pack_start(kernel_kirsch_explanation_frame_widget_label, false, false, 0) ;

  kernel_kirsch_explanation_frame.set_label_widget(kernel_kirsch_explanation_frame_widget_hbox) ;

  kernel_kirsch_explanation_label.set_margin_bottom(6) ;

  kernel_kirsch_explanation_frame.add(kernel_kirsch_explanation_label) ;



  Gtk::Frame          kernel_kirsch_kernel_frame("") ;

  Gtk::Box            kernel_kirsch_kernel_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          kernel_kirsch_kernel_frame_widget_image(PATH_TO_MENU_ICONS "transform-move.png") ;
  Gtk::Label          kernel_kirsch_kernel_frame_widget_label(" Kirsch kernel ") ;

  kernel_kirsch_kernel_frame_widget_hbox.pack_start(kernel_kirsch_kernel_frame_widget_image, false, false, 0) ;
  kernel_kirsch_kernel_frame_widget_hbox.pack_start(kernel_kirsch_kernel_frame_widget_label, false, false, 0) ;

  kernel_kirsch_kernel_frame.set_label_widget(kernel_kirsch_kernel_frame_widget_hbox) ;



  Gtk::Box            kernel_kirsch_kernel_main_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;

  kernel_kirsch_kernel_main_vbox.set_spacing(FILTER_DIALOG_BOX_SPACING) ;



  Gtk::Label          kernel_kirsch_kernel_direction_label("Direction") ;

  Gtk::Label          kernel_kirsch_padding_01("") ;

  Gtk::ComboBoxText   kernel_kirsch_kernel_direction_combo ;

  Gtk::Box            kernel_kirsch_kernel_hbox_01(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  kernel_kirsch_kernel_direction_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  kernel_kirsch_kernel_direction_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  kernel_kirsch_kernel_direction_combo.insert(0, "East") ;
  kernel_kirsch_kernel_direction_combo.insert(1, "West") ;
  kernel_kirsch_kernel_direction_combo.insert(2, "North") ;
  kernel_kirsch_kernel_direction_combo.insert(3, "South") ;

  kernel_kirsch_kernel_direction_combo.set_active(controller.kernel_kirsch_kernel_direction) ;

  kernel_kirsch_kernel_hbox_01.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  kernel_kirsch_kernel_hbox_01.pack_start(kernel_kirsch_kernel_direction_label, false, false, 0) ;
  kernel_kirsch_kernel_hbox_01.pack_start(kernel_kirsch_padding_01,        true,  true,  0) ;
  kernel_kirsch_kernel_hbox_01.pack_start(kernel_kirsch_kernel_direction_combo, true,  true,  0) ;



  Gtk::Label          kernel_kirsch_kernel_ksize_label("Kernel size") ;

  Gtk::Label          kernel_kirsch_padding_02("") ;

  Gtk::SpinButton     kernel_kirsch_kernel_ksize_spinbutton ;

  Gtk::Box            kernel_kirsch_kernel_hbox_02(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  kernel_kirsch_kernel_ksize_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  kernel_kirsch_kernel_ksize_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  kernel_kirsch_kernel_ksize_spinbutton.set_digits(0) ;
  kernel_kirsch_kernel_ksize_spinbutton.set_range(3.0, 31.0)      ;
  kernel_kirsch_kernel_ksize_spinbutton.set_value(controller.kernel_kirsch_kernel_size)      ;
  kernel_kirsch_kernel_ksize_spinbutton.set_increments(2.0, 4.0)    ;
  kernel_kirsch_kernel_ksize_spinbutton.set_size_request(127-64, -1)    ;
  kernel_kirsch_kernel_ksize_spinbutton.set_snap_to_ticks(true)    ;
  kernel_kirsch_kernel_ksize_spinbutton.set_adjustment( Gtk::Adjustment::create(controller.kernel_kirsch_kernel_size, 3.0, 31.0, 2.0, 4.0) ) ;

  kernel_kirsch_kernel_hbox_02.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  kernel_kirsch_kernel_hbox_02.pack_start(kernel_kirsch_kernel_ksize_label,      false, false, 0) ;
  kernel_kirsch_kernel_hbox_02.pack_start(kernel_kirsch_padding_02,              true,  true,  0) ;
  kernel_kirsch_kernel_hbox_02.pack_start(kernel_kirsch_kernel_ksize_spinbutton, false, false, 0) ;


  Gtk::Label          kernel_kirsch_kernel_values_factor_label("Values factor") ;

  Gtk::Label          kernel_kirsch_padding_03("") ;

  Gtk::Scale          kernel_kirsch_kernel_values_factor_scale(Gtk::ORIENTATION_HORIZONTAL) ;

  Gtk::Box            kernel_kirsch_kernel_hbox_03(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  kernel_kirsch_kernel_values_factor_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  kernel_kirsch_kernel_values_factor_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  kernel_kirsch_kernel_values_factor_scale.set_digits(2) ;
  kernel_kirsch_kernel_values_factor_scale.set_draw_value(true) ;
  kernel_kirsch_kernel_values_factor_scale.set_has_origin(true) ;
  kernel_kirsch_kernel_values_factor_scale.set_upper_stepper_sensitivity(Gtk::SENSITIVITY_ON) ;
  kernel_kirsch_kernel_values_factor_scale.set_lower_stepper_sensitivity(Gtk::SENSITIVITY_ON) ;
  kernel_kirsch_kernel_values_factor_scale.set_adjustment( kernel_kirsch_kernel_values_factor_scale.get_adjustment() )     ;
  kernel_kirsch_kernel_values_factor_scale.set_range(0.01, 5.00)      ;
  kernel_kirsch_kernel_values_factor_scale.set_value(controller.kernel_kirsch_kernel_values_factor)      ;
  kernel_kirsch_kernel_values_factor_scale.set_increments(0.01, 0.1)    ;
  kernel_kirsch_kernel_values_factor_scale.set_size_request(127-16-8, -1)    ;
  kernel_kirsch_kernel_values_factor_scale.add_mark(1.0, Gtk::POS_TOP, "")      ;

  kernel_kirsch_kernel_hbox_03.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  kernel_kirsch_kernel_hbox_03.pack_start(kernel_kirsch_kernel_values_factor_label, false, false, 0) ;
  kernel_kirsch_kernel_hbox_03.pack_start(kernel_kirsch_padding_03,                 true,  true,  0) ;
  kernel_kirsch_kernel_hbox_03.pack_start(kernel_kirsch_kernel_values_factor_scale, true,  true,  0) ;



  Gtk::Box            kernel_kirsch_kernel_hbox_04(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Label          kernel_kirsch_padding_04("") ;

  Gtk::Image          kernel_kirsch_kernel_display_image(PATH_TO_BUTTON_ICONS "transform-move.png") ;

  Gtk::Button         kernel_kirsch_kernel_display_button("   Preview kernel    ") ;

  kernel_kirsch_kernel_display_button.set_image(kernel_kirsch_kernel_display_image) ;

  kernel_kirsch_kernel_display_button.set_always_show_image(true) ;


  kernel_kirsch_kernel_hbox_04.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  kernel_kirsch_kernel_hbox_04.pack_start(kernel_kirsch_padding_04,            true,  true,  0) ;
  kernel_kirsch_kernel_hbox_04.pack_start(kernel_kirsch_kernel_display_button, false, false, 0) ;


  kernel_kirsch_kernel_main_vbox.pack_start(kernel_kirsch_kernel_hbox_01, false, false, 0) ;
  kernel_kirsch_kernel_main_vbox.pack_start(kernel_kirsch_kernel_hbox_02, false, false, 0) ;
  kernel_kirsch_kernel_main_vbox.pack_start(kernel_kirsch_kernel_hbox_03, false, false, 0) ;
  kernel_kirsch_kernel_main_vbox.pack_start(kernel_kirsch_kernel_hbox_04, false, false, 0) ;

  kernel_kirsch_kernel_frame.add(kernel_kirsch_kernel_main_vbox) ;



  Gtk::Frame          kernel_kirsch_kernel_actions_frame("") ;

  Gtk::Box            kernel_kirsch_kernel_actions_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          kernel_kirsch_kernel_actions_frame_widget_image(PATH_TO_MENU_ICONS "undo-redo.png") ;
  Gtk::Label          kernel_kirsch_kernel_actions_frame_widget_label(" Actions ") ;

  kernel_kirsch_kernel_actions_frame_widget_hbox.pack_start(kernel_kirsch_kernel_actions_frame_widget_image, false, false, 0) ;
  kernel_kirsch_kernel_actions_frame_widget_hbox.pack_start(kernel_kirsch_kernel_actions_frame_widget_label, false, false, 0) ;

  kernel_kirsch_kernel_actions_frame.set_label_widget(kernel_kirsch_kernel_actions_frame_widget_hbox) ;

  Gtk::Button         kernel_kirsch_kernel_actions_undo_button(" Undo ") ;

  Gtk::Image          kernel_kirsch_kernel_actions_undo_image(PATH_TO_BUTTON_ICONS "go-previous-view.png") ;

  Gtk::Box            kernel_kirsch_kernel_actions_padding(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Button         kernel_kirsch_kernel_actions_redo_button(" Redo ") ;

  Gtk::Image          kernel_kirsch_kernel_actions_redo_image(PATH_TO_BUTTON_ICONS "go-next-view.png") ;




  Gtk::Box            kernel_kirsch_kernel_actions_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  kernel_kirsch_kernel_actions_undo_button.set_image(kernel_kirsch_kernel_actions_undo_image) ;

  kernel_kirsch_kernel_actions_undo_button.set_always_show_image(true) ;

  kernel_kirsch_kernel_actions_undo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;
  kernel_kirsch_kernel_actions_redo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;

  kernel_kirsch_kernel_actions_redo_button.set_image(kernel_kirsch_kernel_actions_redo_image) ;

  kernel_kirsch_kernel_actions_redo_button.set_always_show_image(true) ;

  kernel_kirsch_kernel_actions_hbox.set_spacing(FILTER_DIALOG_BOX_SPACING) ;
  kernel_kirsch_kernel_actions_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;


  kernel_kirsch_kernel_actions_hbox.pack_start(kernel_kirsch_kernel_actions_undo_button,    false,   false, 0) ;
  kernel_kirsch_kernel_actions_hbox.pack_start(kernel_kirsch_kernel_actions_padding,        true,    true,  0) ;
  kernel_kirsch_kernel_actions_hbox.pack_start(kernel_kirsch_kernel_actions_redo_button,    false,   false, 0) ;

  kernel_kirsch_kernel_actions_frame.add(kernel_kirsch_kernel_actions_hbox) ;

  kernel_kirsch_kernel_actions_undo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::undo_callback), controller) ) ;
  kernel_kirsch_kernel_actions_redo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::redo_callback), controller) ) ;






  Gtk::Box *kernel_kirsch_main_content_box = dialog.get_content_area() ;

  kernel_kirsch_main_content_box->set_spacing(FILTER_DIALOG_BOX_SPACING) ;

  kernel_kirsch_main_content_box->pack_start(kernel_kirsch_explanation_frame,     false, false, 0) ;
  kernel_kirsch_main_content_box->pack_start(kernel_kirsch_kernel_frame,          false, false, 0) ;
  kernel_kirsch_main_content_box->pack_start(kernel_kirsch_kernel_actions_frame,  false, false, 0) ;



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

  // Display kernel button callback.
  kernel_kirsch_kernel_display_button.signal_clicked().connect([&kernel_kirsch_kernel_direction_combo, &kernel_kirsch_kernel_ksize_spinbutton, &kernel_kirsch_kernel_values_factor_scale, this] () {

    string kernel_direction ;

    switch (kernel_kirsch_kernel_direction_combo.get_active_row_number()) {

      case 0 :

        kernel_direction = "E" ;
        break ;

      case 1 :

        kernel_direction = "W" ;
        break ;

      case 2 :

        kernel_direction = "N" ;
        break ;

      case 3 :

        kernel_direction = "S" ;
        break ;


      #ifdef DEBUG
      default :
        // This cannot append due of the GUI interfacing.

        fprintf(stderr,"Cannot identify kernel direction !!!\n") ;
        return ;

     #endif
    }

    // Sea libedip.
    Kirsch kernel(static_cast<int>(kernel_kirsch_kernel_ksize_spinbutton.get_value()), kernel_direction, static_cast<float>(kernel_kirsch_kernel_values_factor_scale.get_value()) ) ;

    #ifdef DEBUG
    kernel.kernel_print() ;
    #endif

    this->display_kernel(kernel.kernel) ;

  } ) ;


  kernel_kirsch_main_content_box->show_all() ;

  renew_dialog :

  int ret = dialog.run() ;

  switch (ret) {

    case Gtk::RESPONSE_APPLY :


      controller.kernel_kirsch_kernel_direction     = kernel_kirsch_kernel_direction_combo.get_active_row_number()           ;

      controller.kernel_kirsch_kernel_size          = kernel_kirsch_kernel_ksize_spinbutton.get_value()           ;

      controller.kernel_kirsch_kernel_values_factor = kernel_kirsch_kernel_values_factor_scale.get_value()       ;

      kernel_kirsch_callback(controller) ;

      goto renew_dialog ;


      break ;

    case Gtk::RESPONSE_CLOSE :

      dialog.close() ;

      break ;
  }

  dialog.close() ;

  return ;

}


#endif