#ifndef EDIP_COLORS_FILTERS_DIALOG_HH
#define EDIP_COLORS_FILTERS_DIALOG_HH


void GUI::mult_colors_filter_dialog(Controller &controller) {

  /** Configurable multiply colors dialog window displaying. **/

  Gtk::Dialog dialog("Apply mult_colors filter.", false) ;


  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "office-chart-pie.png") ;
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





  Gtk::Frame          mult_colors_explanation_frame("") ;

  Gtk::Box            mult_colors_explanation_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          mult_colors_explanation_frame_widget_image(PATH_TO_MENU_ICONS "applications-education-university.png") ;
  Gtk::Label          mult_colors_explanation_frame_widget_label(" Explanations ") ;

  Gtk::Label          mult_colors_explanation_label("Color multiplying consist of multiplying\n"
                                                    "each color channel.\n"
                                                    "The red, green blue and alpha if supported\n"
                                                    "channel by a define factor.\n") ;
                                               
  mult_colors_explanation_label.set_tooltip_text("Confer the joined documentation for further\n"
                                                 "informations about colors multiplying.") ;

  mult_colors_explanation_frame_widget_label.set_margin_left(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  mult_colors_explanation_frame_widget_label.set_margin_right(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  mult_colors_explanation_frame_widget_label.set_margin_top(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  mult_colors_explanation_frame_widget_label.set_margin_bottom(FILTER_DIALOG_FRAME_INNER_SPACE) ;

  mult_colors_explanation_frame_widget_hbox.pack_start(mult_colors_explanation_frame_widget_image, false, false, 0) ;
  mult_colors_explanation_frame_widget_hbox.pack_start(mult_colors_explanation_frame_widget_label, false, false, 0) ;

  mult_colors_explanation_frame.set_label_widget(mult_colors_explanation_frame_widget_hbox) ;

  mult_colors_explanation_label.set_margin_bottom(6) ;

  mult_colors_explanation_frame.add(mult_colors_explanation_label) ;



  Gtk::Frame          mult_colors_frame("") ;

  Gtk::Box            mult_colors_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          mult_colors_frame_widget_image(PATH_TO_MENU_ICONS "view-statistics.png") ;
  Gtk::Label          mult_colors_frame_widget_label(" Multiply color channels ") ;

  mult_colors_frame_widget_hbox.pack_start(mult_colors_frame_widget_image, false, false, 0) ;
  mult_colors_frame_widget_hbox.pack_start(mult_colors_frame_widget_label, false, false, 0) ;

  mult_colors_frame.set_label_widget(mult_colors_frame_widget_hbox) ;



  Gtk::Box            mult_colors_main_vbox(Gtk::ORIENTATION_VERTICAL, 0) ;

  mult_colors_main_vbox.set_spacing(FILTER_DIALOG_BOX_SPACING) ;



  Gtk::Label          mult_red_label("Multiply red channel    ") ;

  Gtk::Label          mult_red_padding("") ;

  Gtk::SpinButton     mult_red_spinbutton ;

  Gtk::Box            mult_red_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  mult_red_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  mult_red_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  mult_red_spinbutton.set_digits(2) ;
  mult_red_spinbutton.set_range(0.01, 5.00)      ;
  mult_red_spinbutton.set_value(controller.mult_red)      ;
  mult_red_spinbutton.set_increments(0.01, 0.1)    ;
  mult_red_spinbutton.set_size_request(127-64, -1)    ;
  mult_red_spinbutton.set_snap_to_ticks(true)    ;
  mult_red_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  mult_red_spinbutton.set_adjustment( Gtk::Adjustment::create(controller.mult_red, 0.01, 5.00, 0.01, 0.1) ) ;


  mult_red_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  mult_red_hbox.pack_start(mult_red_label,      false, false, 0) ;
  mult_red_hbox.pack_start(mult_red_padding,    true,  true,  0) ;
  mult_red_hbox.pack_start(mult_red_spinbutton, true,  true,  0) ;



  Gtk::Label          mult_green_label("Multiply green channel") ;

  Gtk::Label          mult_green_padding("") ;

  Gtk::SpinButton     mult_green_spinbutton ;

  Gtk::Box            mult_green_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  mult_green_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  mult_green_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  mult_green_spinbutton.set_digits(2) ;
  mult_green_spinbutton.set_range(0.01, 5.00)      ;
  mult_green_spinbutton.set_value(controller.mult_green)      ;
  mult_green_spinbutton.set_increments(0.01, 0.1)    ;
  mult_green_spinbutton.set_size_request(127-64, -1)    ;
  mult_green_spinbutton.set_snap_to_ticks(true)    ;
  mult_green_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  mult_green_spinbutton.set_adjustment( Gtk::Adjustment::create(controller.mult_green, 0.01, 5.00, 0.01, 0.1) ) ;


  mult_green_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  mult_green_hbox.pack_start(mult_green_label,      false, false, 0) ;
  mult_green_hbox.pack_start(mult_green_padding,    true,  true,  0) ;
  mult_green_hbox.pack_start(mult_green_spinbutton, true,  true,  0) ;



  Gtk::Label          mult_blue_label("Multiply blue channel  ") ;

  Gtk::Label          mult_blue_padding("") ;

  Gtk::SpinButton     mult_blue_spinbutton ;

  Gtk::Box            mult_blue_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  mult_blue_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  mult_blue_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  mult_blue_spinbutton.set_digits(2) ;
  mult_blue_spinbutton.set_range(0.01, 5.00)      ;
  mult_blue_spinbutton.set_value(controller.mult_blue)      ;
  mult_blue_spinbutton.set_increments(0.01, 0.1)    ;
  mult_blue_spinbutton.set_size_request(127-64, -1)    ;
  mult_blue_spinbutton.set_snap_to_ticks(true)    ;
  mult_blue_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  mult_blue_spinbutton.set_adjustment( Gtk::Adjustment::create(controller.mult_blue, 0.01, 5.00, 0.01, 0.1) ) ;


  mult_blue_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  mult_blue_hbox.pack_start(mult_blue_label,      false, false, 0) ;
  mult_blue_hbox.pack_start(mult_blue_padding,    true,  true,  0) ;
  mult_blue_hbox.pack_start(mult_blue_spinbutton, true,  true,  0) ;



  Gtk::Label          mult_alpha_label("Multiply alpha channel") ;

  Gtk::Label          mult_alpha_padding("") ;

  Gtk::SpinButton     mult_alpha_spinbutton ;

  Gtk::Box            mult_alpha_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  mult_alpha_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  mult_alpha_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  mult_alpha_spinbutton.set_digits(2) ;
  mult_alpha_spinbutton.set_range(0.01, 5.00)      ;
  mult_alpha_spinbutton.set_value(controller.mult_alpha)      ;
  mult_alpha_spinbutton.set_increments(0.01, 0.1)    ;
  mult_alpha_spinbutton.set_size_request(127-64, -1)    ;
  mult_alpha_spinbutton.set_snap_to_ticks(true)    ;
  mult_alpha_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  mult_alpha_spinbutton.set_adjustment( Gtk::Adjustment::create(controller.mult_alpha, 0.01, 5.00, 0.01, 0.1) ) ;


  mult_alpha_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  mult_alpha_hbox.pack_start(mult_alpha_label,      false, false, 0) ;
  mult_alpha_hbox.pack_start(mult_alpha_padding,    true,  true,  0) ;
  mult_alpha_hbox.pack_start(mult_alpha_spinbutton, true,  true,  0) ;


  mult_colors_main_vbox.pack_start(mult_red_hbox,   false, false, 0) ;
  mult_colors_main_vbox.pack_start(mult_green_hbox, false, false, 0) ;
  mult_colors_main_vbox.pack_start(mult_blue_hbox,  false, false, 0) ;
  mult_colors_main_vbox.pack_start(mult_alpha_hbox, false, false, 0) ;

  mult_colors_frame.add(mult_colors_main_vbox) ;



  Gtk::Button         mult_colors_actions_undo_button(" Undo ") ;

  Gtk::Image          mult_colors_actions_undo_image(PATH_TO_BUTTON_ICONS "go-previous-view.png") ;

  Gtk::Box            mult_colors_actions_padding(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Button         mult_colors_actions_redo_button(" Redo ") ;

  Gtk::Image          mult_colors_actions_redo_image(PATH_TO_BUTTON_ICONS "go-next-view.png") ;


  Gtk::Frame          mult_colors_actions_frame("") ;

  Gtk::Box            mult_colors_actions_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          mult_colors_actions_frame_widget_image(PATH_TO_MENU_ICONS "undo-redo.png") ;
  Gtk::Label          mult_colors_actions_frame_widget_label(" Actions ") ;

  mult_colors_actions_frame_widget_hbox.pack_start(mult_colors_actions_frame_widget_image, false, false, 0) ;
  mult_colors_actions_frame_widget_hbox.pack_start(mult_colors_actions_frame_widget_label, false, false, 0) ;

  mult_colors_actions_frame.set_label_widget(mult_colors_actions_frame_widget_hbox) ;

  Gtk::Box            mult_colors_actions_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  mult_colors_actions_undo_button.set_image(mult_colors_actions_undo_image) ;

  mult_colors_actions_undo_button.set_always_show_image(true) ;

  mult_colors_actions_undo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;
  mult_colors_actions_redo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;

  mult_colors_actions_redo_button.set_image(mult_colors_actions_redo_image) ;

  mult_colors_actions_redo_button.set_always_show_image(true) ;

  mult_colors_actions_hbox.set_spacing(FILTER_DIALOG_BOX_SPACING) ;
  mult_colors_actions_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;


  mult_colors_actions_hbox.pack_start(mult_colors_actions_undo_button,    false,   false, 0) ;
  mult_colors_actions_hbox.pack_start(mult_colors_actions_padding,        true,    true,  0) ;
  mult_colors_actions_hbox.pack_start(mult_colors_actions_redo_button,    false,   false, 0) ;

  mult_colors_actions_frame.add(mult_colors_actions_hbox) ;

  mult_colors_actions_undo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::undo_callback), controller) ) ;
  mult_colors_actions_redo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::redo_callback), controller) ) ;




  Gtk::Box *mult_colors_main_content_box = dialog.get_content_area() ;

  mult_colors_main_content_box->set_spacing(FILTER_DIALOG_BOX_SPACING) ;

  mult_colors_main_content_box->pack_start(mult_colors_explanation_frame,    false, false, 0) ;
  mult_colors_main_content_box->pack_start(mult_colors_frame,                false, false, 0) ;
  mult_colors_main_content_box->pack_start(mult_colors_actions_frame,        false, false, 0) ;



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

  mult_colors_main_content_box->show_all() ;

  renew_dialog :

  int ret = dialog.run() ;

  switch (ret) {

    case Gtk::RESPONSE_APPLY :

      controller.mult_red                    = mult_red_spinbutton.get_value()    ;
      controller.mult_green                  = mult_green_spinbutton.get_value()  ;
      controller.mult_blue                   = mult_blue_spinbutton.get_value()   ;
      controller.mult_alpha                  = mult_alpha_spinbutton.get_value()  ;

      mult_colors_callback(controller) ;

      goto renew_dialog ;

      break ;

    case Gtk::RESPONSE_CLOSE :

      dialog.close() ;

      break ;
  }

  return ;

}
void GUI::set_image_in_color_tone_filter_dialog(Controller &controller) {

  /** Configurable set image in color tone dialog window displaying. **/

  Gtk::Dialog dialog("Set image in color tone.", false) ;

  // Configure dialog.
  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "view-statistics.png") ;
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





  Gtk::Frame          set_in_color_tone_explanation_frame("") ;

  Gtk::Box            set_in_color_tone_explanation_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          set_in_color_tone_explanation_frame_widget_image(PATH_TO_MENU_ICONS "applications-education-university.png") ;
  Gtk::Label          set_in_color_tone_explanation_frame_widget_label(" Explanations ") ;

  Gtk::Label          set_in_color_tone_explanation_label("Choose a color to set the image\n"
                                                          "in this color tone.\n") ;

  set_in_color_tone_explanation_label.set_tooltip_text("Confer the joined documentation for further\n"
                                                       "informations about set image in color tone.") ;

  set_in_color_tone_explanation_frame_widget_label.set_margin_left(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  set_in_color_tone_explanation_frame_widget_label.set_margin_right(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  set_in_color_tone_explanation_frame_widget_label.set_margin_top(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  set_in_color_tone_explanation_frame_widget_label.set_margin_bottom(FILTER_DIALOG_FRAME_INNER_SPACE) ;

  set_in_color_tone_explanation_frame_widget_hbox.pack_start(set_in_color_tone_explanation_frame_widget_image, false, false, 0) ;
  set_in_color_tone_explanation_frame_widget_hbox.pack_start(set_in_color_tone_explanation_frame_widget_label, false, false, 0) ;

  set_in_color_tone_explanation_frame.set_label_widget(set_in_color_tone_explanation_frame_widget_hbox) ;

  set_in_color_tone_explanation_label.set_margin_bottom(6) ;

  set_in_color_tone_explanation_frame.add(set_in_color_tone_explanation_label) ;



  Gtk::Frame          set_in_color_tone_frame("") ;

  Gtk::Box            set_in_color_tone_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          set_in_color_tone_frame_widget_image(PATH_TO_MENU_ICONS "view-statistics.png") ;
  Gtk::Label          set_in_color_tone_frame_widget_label(" Set image in color tone ") ;

  set_in_color_tone_frame_widget_hbox.pack_start(set_in_color_tone_frame_widget_image, false, false, 0) ;
  set_in_color_tone_frame_widget_hbox.pack_start(set_in_color_tone_frame_widget_label, false, false, 0) ;

  set_in_color_tone_frame.set_label_widget(set_in_color_tone_frame_widget_hbox) ;


  Gtk::Label          set_in_color_tone_color_label("Set image in color tone") ;

  Gtk::Label          set_in_color_tone_color_padding("") ;


  Gdk::RGBA           set_in_color_tone_start_rgba ;

  set_in_color_tone_start_rgba.set_rgba(1.0, 1.0, 1.0) ;

  Gtk::ColorButton    set_in_color_tone_color_button(set_in_color_tone_start_rgba) ;

  Gtk::Box            set_in_color_tone_color_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  set_in_color_tone_color_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  set_in_color_tone_color_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  set_in_color_tone_color_button.set_use_alpha(false) ;

  set_in_color_tone_color_button.set_title("Set image in color tone") ;

  set_in_color_tone_color_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  set_in_color_tone_color_hbox.pack_start(set_in_color_tone_color_label,      false, false, 0) ;
  set_in_color_tone_color_hbox.pack_start(set_in_color_tone_color_padding,    true,  true,  0) ;
  set_in_color_tone_color_hbox.pack_start(set_in_color_tone_color_button,     true,  true,  0) ;


  set_in_color_tone_frame.add(set_in_color_tone_color_hbox) ;


  Gtk::Button         set_in_color_tone_actions_undo_button(" Undo ") ;

  Gtk::Image          set_in_color_tone_actions_undo_image(PATH_TO_BUTTON_ICONS "go-previous-view.png") ;

  Gtk::Box            set_in_color_tone_actions_padding(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Button         set_in_color_tone_actions_redo_button(" Redo ") ;

  Gtk::Image          set_in_color_tone_actions_redo_image(PATH_TO_BUTTON_ICONS "go-next-view.png") ;


  Gtk::Frame          set_in_color_tone_actions_frame("") ;

  Gtk::Box            set_in_color_tone_actions_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          set_in_color_tone_actions_frame_widget_image(PATH_TO_MENU_ICONS "undo-redo.png") ;
  Gtk::Label          set_in_color_tone_actions_frame_widget_label(" Actions ") ;

  set_in_color_tone_actions_frame_widget_hbox.pack_start(set_in_color_tone_actions_frame_widget_image, false, false, 0) ;
  set_in_color_tone_actions_frame_widget_hbox.pack_start(set_in_color_tone_actions_frame_widget_label, false, false, 0) ;

  set_in_color_tone_actions_frame.set_label_widget(set_in_color_tone_actions_frame_widget_hbox) ;

  Gtk::Box            set_in_color_tone_actions_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  set_in_color_tone_actions_undo_button.set_image(set_in_color_tone_actions_undo_image) ;

  set_in_color_tone_actions_undo_button.set_always_show_image(true) ;

  set_in_color_tone_actions_undo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;
  set_in_color_tone_actions_redo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;

  set_in_color_tone_actions_redo_button.set_image(set_in_color_tone_actions_redo_image) ;

  set_in_color_tone_actions_redo_button.set_always_show_image(true) ;

  set_in_color_tone_actions_hbox.set_spacing(FILTER_DIALOG_BOX_SPACING) ;
  set_in_color_tone_actions_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;


  set_in_color_tone_actions_hbox.pack_start(set_in_color_tone_actions_undo_button,    false,   false, 0) ;
  set_in_color_tone_actions_hbox.pack_start(set_in_color_tone_actions_padding,        true,    true,  0) ;
  set_in_color_tone_actions_hbox.pack_start(set_in_color_tone_actions_redo_button,    false,   false, 0) ;

  set_in_color_tone_actions_frame.add(set_in_color_tone_actions_hbox) ;

  set_in_color_tone_actions_undo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::undo_callback), controller) ) ;
  set_in_color_tone_actions_redo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::redo_callback), controller) ) ;



  Gtk::Box *set_in_color_tone_main_content_box = dialog.get_content_area() ;

  set_in_color_tone_main_content_box->set_spacing(FILTER_DIALOG_BOX_SPACING) ;

  set_in_color_tone_main_content_box->pack_start(set_in_color_tone_explanation_frame,    false, false, 0) ;
  set_in_color_tone_main_content_box->pack_start(set_in_color_tone_frame,                false, false, 0) ;
  set_in_color_tone_main_content_box->pack_start(set_in_color_tone_actions_frame,        false, false, 0) ;

  // Add action buttons:
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

  set_in_color_tone_main_content_box->show_all() ;

  renew_dialog :

  int ret = dialog.run() ;

  switch (ret) {

    case Gtk::RESPONSE_APPLY : {

      Gdk::RGBA color = set_in_color_tone_color_button.get_rgba() ;

      uint8_t red = static_cast<uint8_t>(color.get_red_u() >> 8)     ;
      uint8_t green = static_cast<uint8_t>(color.get_green_u() >> 8) ;
      uint8_t blue = static_cast<uint8_t>(color.get_blue_u() >> 8)   ;

      set_image_in_color_tone_callback(controller, red, green, blue) ;

      goto renew_dialog ;

      break ;
    }

    case Gtk::RESPONSE_CLOSE :

      break ;
  }

  dialog.close() ;

  return ;

}

void GUI::mult_global_intesity_filter_dialog(Controller &controller) {

  /** Configurable multiply global image intensity dialog window. **/

  Gtk::Dialog dialog("Multiply global intensity.", false) ;

  // Configure dialog.
  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "quickopen-class.png") ;
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





  Gtk::Frame          mult_global_intensity_explanation_frame("") ;

  Gtk::Box            mult_global_intensity_explanation_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0) ;

  Gtk::Image          mult_global_intensity_explanation_frame_widget_image(PATH_TO_MENU_ICONS "applications-education-university.png") ;
  Gtk::Label          mult_global_intensity_explanation_frame_widget_label(" Explanations ") ;

  Gtk::Label          mult_global_intensity_explanation_label("Multiply each color channel\n"
                                                              "red, green and blue per factor.") ;

  mult_global_intensity_explanation_label.set_tooltip_text("Confer the joined documentation for further\n"
                                                           "informations about multiplying the global intensity.") ;

  mult_global_intensity_explanation_frame_widget_label.set_margin_left(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  mult_global_intensity_explanation_frame_widget_label.set_margin_right(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  mult_global_intensity_explanation_frame_widget_label.set_margin_top(FILTER_DIALOG_FRAME_INNER_SPACE) ;
  mult_global_intensity_explanation_frame_widget_label.set_margin_bottom(FILTER_DIALOG_FRAME_INNER_SPACE) ;

  mult_global_intensity_explanation_frame_widget_hbox.pack_start(mult_global_intensity_explanation_frame_widget_image, false, false, 0) ;
  mult_global_intensity_explanation_frame_widget_hbox.pack_start(mult_global_intensity_explanation_frame_widget_label, false, false, 0) ;

  mult_global_intensity_explanation_frame.set_label_widget(mult_global_intensity_explanation_frame_widget_hbox) ;

  mult_global_intensity_explanation_label.set_margin_bottom(6) ;

  mult_global_intensity_explanation_frame.add(mult_global_intensity_explanation_label) ;



  Gtk::Frame          mult_global_intensity_frame("") ;

  Gtk::Box            mult_global_intensity_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          mult_global_intensity_frame_widget_image(PATH_TO_MENU_ICONS "quickopen-class.png") ;
  Gtk::Label          mult_global_intensity_frame_widget_label(" Multiply global intensity ") ;

  mult_global_intensity_frame_widget_hbox.pack_start(mult_global_intensity_frame_widget_image, false, false, 0) ;
  mult_global_intensity_frame_widget_hbox.pack_start(mult_global_intensity_frame_widget_label, false, false, 0) ;

  mult_global_intensity_frame.set_label_widget(mult_global_intensity_frame_widget_hbox) ;

  Gtk::Label          mult_global_intensity_color_label("Factor") ;

  Gtk::Label          mult_global_intensity_color_padding("") ;

  Gtk::SpinButton     mult_global_intensity_color_spinbutton ;

  Gtk::Box            mult_global_intensity_color_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  mult_global_intensity_color_label.set_margin_right(FILTER_DIALOG_LABEL_MARGIN_RIGHT) ;
  mult_global_intensity_color_label.set_margin_left(FILTER_DIALOG_LABEL_MARGIN_LEFT) ;

  mult_global_intensity_color_spinbutton.set_digits(3) ;
  mult_global_intensity_color_spinbutton.set_range(0.01, 5.00)      ;
  mult_global_intensity_color_spinbutton.set_value(controller.mult_global_intensity_factor)      ;
  mult_global_intensity_color_spinbutton.set_increments(0.01, 0.1)    ;
  mult_global_intensity_color_spinbutton.set_size_request(127-64, -1)    ;
  mult_global_intensity_color_spinbutton.set_snap_to_ticks(true)    ;
  mult_global_intensity_color_spinbutton.set_update_policy(Gtk::UPDATE_IF_VALID) ;
  mult_global_intensity_color_spinbutton.set_adjustment( Gtk::Adjustment::create(controller.mult_global_intensity_factor, 0.01, 5.00, 0.01, 0.1) ) ;


  mult_global_intensity_color_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;

  mult_global_intensity_color_hbox.pack_start(mult_global_intensity_color_label,      false, false, 0) ;
  mult_global_intensity_color_hbox.pack_start(mult_global_intensity_color_padding,    true,  true,  0) ;
  mult_global_intensity_color_hbox.pack_start(mult_global_intensity_color_spinbutton, false, false,  0) ;


  mult_global_intensity_frame.add(mult_global_intensity_color_hbox) ;



  Gtk::Frame          mult_global_intensity_actions_frame("") ;

  Gtk::Box            mult_global_intensity_actions_frame_widget_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Image          mult_global_intensity_actions_frame_widget_image(PATH_TO_MENU_ICONS "undo-redo.png") ;
  Gtk::Label          mult_global_intensity_actions_frame_widget_label(" Actions ") ;

  mult_global_intensity_actions_frame_widget_hbox.pack_start(mult_global_intensity_actions_frame_widget_image, false, false, 0) ;
  mult_global_intensity_actions_frame_widget_hbox.pack_start(mult_global_intensity_actions_frame_widget_label, false, false, 0) ;

  mult_global_intensity_actions_frame.set_label_widget(mult_global_intensity_actions_frame_widget_hbox) ;

  Gtk::Button         mult_global_intensity_actions_undo_button(" Undo ") ;

  Gtk::Image          mult_global_intensity_actions_undo_image(PATH_TO_BUTTON_ICONS "go-previous-view.png") ;

  Gtk::Box            mult_global_intensity_actions_padding(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  Gtk::Button         mult_global_intensity_actions_redo_button(" Redo ") ;

  Gtk::Image          mult_global_intensity_actions_redo_image(PATH_TO_BUTTON_ICONS "go-next-view.png") ;




  Gtk::Box            mult_global_intensity_actions_hbox(Gtk::ORIENTATION_HORIZONTAL, 0)  ;

  mult_global_intensity_actions_undo_button.set_image(mult_global_intensity_actions_undo_image) ;

  mult_global_intensity_actions_undo_button.set_always_show_image(true) ;

  mult_global_intensity_actions_undo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;
  mult_global_intensity_actions_redo_button.set_border_width(FILTER_DIALOG_BUTTON_BORDER) ;

  mult_global_intensity_actions_redo_button.set_image(mult_global_intensity_actions_redo_image) ;

  mult_global_intensity_actions_redo_button.set_always_show_image(true) ;

  mult_global_intensity_actions_hbox.set_spacing(FILTER_DIALOG_BOX_SPACING) ;
  mult_global_intensity_actions_hbox.set_border_width(FILTER_DIALOG_BOX_BORDER) ;


  mult_global_intensity_actions_hbox.pack_start(mult_global_intensity_actions_undo_button,    false,   false, 0) ;
  mult_global_intensity_actions_hbox.pack_start(mult_global_intensity_actions_padding,        true,    true,  0) ;
  mult_global_intensity_actions_hbox.pack_start(mult_global_intensity_actions_redo_button,    false,   false, 0) ;

  mult_global_intensity_actions_frame.add(mult_global_intensity_actions_hbox) ;

  mult_global_intensity_actions_undo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::undo_callback), controller) ) ;
  mult_global_intensity_actions_redo_button.signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(*this, &GUI::redo_callback), controller) ) ;


  Gtk::Box *mult_global_intensity_main_content_box = dialog.get_content_area() ;

  mult_global_intensity_main_content_box->set_spacing(FILTER_DIALOG_BOX_SPACING) ;

  mult_global_intensity_main_content_box->pack_start(mult_global_intensity_explanation_frame,    false, false, 0) ;
  mult_global_intensity_main_content_box->pack_start(mult_global_intensity_frame,                false, false, 0) ;
  mult_global_intensity_main_content_box->pack_start(mult_global_intensity_actions_frame,        false, false, 0) ;

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

  mult_global_intensity_main_content_box->show_all() ;

  renew_dialog :

  int ret = dialog.run() ;

  switch (ret) {

    case Gtk::RESPONSE_APPLY :

      controller.mult_global_intensity_factor = mult_global_intensity_color_spinbutton.get_value() ;
 
      // Sea libedip.
      mult_global_intensity_callback(controller, static_cast<float>(controller.mult_global_intensity_factor) ) ;

      goto renew_dialog ;

      break ;

    case Gtk::RESPONSE_CLOSE :

      break ;
  }

  dialog.close() ;

  return ;

}

#endif