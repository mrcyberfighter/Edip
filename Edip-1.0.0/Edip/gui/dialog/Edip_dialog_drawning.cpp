#ifndef EDIP_DRAWNING_DIALOG_HH
#define EDIP_DRAWNING_DIALOG_HH

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


void GUI::config_polygon_draw(Controller &controller) {

  /** Display a dialog for polygon drawning configurating. **/

  Gtk::Dialog dialog("Configure polygon to insert.", true) ;

  // Configure dialog:
  dialog.set_border_width(2)  ;
  dialog.set_resizable(false) ;
  dialog.set_decorated(false) ;
  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "draw-polygon.png") ;
  dialog.set_position(Gtk::WIN_POS_CENTER_ON_PARENT) ;
  dialog.set_type_hint(Gdk::WINDOW_TYPE_HINT_DIALOG) ;
  dialog.set_transient_for(*this) ;

  // Add action buttons
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


  Gtk::Label config_polygon_label_edges("Edges  ") ;

  Gtk::SpinButton config_polygon_spinbutton_edges ;

  config_polygon_spinbutton_edges.set_digits(0)     ;
  config_polygon_spinbutton_edges.set_range(3.0, 720.0) ;
  config_polygon_spinbutton_edges.set_value(controller.polygon_edges)     ;
  config_polygon_spinbutton_edges.set_increments(1.0, 10.0)     ;
  config_polygon_spinbutton_edges.set_update_policy(Gtk::UPDATE_IF_VALID ) ;
  config_polygon_spinbutton_edges.set_wrap(true) ;
  config_polygon_spinbutton_edges.set_numeric(true) ;
  config_polygon_spinbutton_edges.set_snap_to_ticks(true) ;

  config_polygon_spinbutton_edges.set_has_frame(true) ;
  config_polygon_spinbutton_edges.set_max_length(3) ;
  config_polygon_spinbutton_edges.set_width_chars(3) ;
  config_polygon_spinbutton_edges.set_alignment(0.5f) ;

  config_polygon_spinbutton_edges.set_tooltip_text("The number of edges of the regular convex polygon.") ;


  Gtk::Label config_polygon_label_polygon_offset("Offset ") ;

  Gtk::SpinButton config_polygon_spinbutton_offset ;

  config_polygon_spinbutton_offset.set_digits(2)         ;
  config_polygon_spinbutton_offset.set_range(0.0, 720.0) ;
  config_polygon_spinbutton_offset.set_value(controller.polygon_offset)     ;
  config_polygon_spinbutton_offset.set_increments(0.1, 10.0)     ;
  config_polygon_spinbutton_offset.set_update_policy(Gtk::UPDATE_IF_VALID ) ;
  config_polygon_spinbutton_offset.set_wrap(true) ;
  config_polygon_spinbutton_offset.set_numeric(true) ;
  config_polygon_spinbutton_offset.set_snap_to_ticks(true) ;
  config_polygon_spinbutton_offset.set_has_frame(true) ;
  config_polygon_spinbutton_offset.set_max_length(6) ;
  config_polygon_spinbutton_offset.set_width_chars(6) ;
  config_polygon_spinbutton_offset.set_alignment(0.5f) ;

  config_polygon_spinbutton_offset.set_tooltip_text("Rotation angle to add. To get your polygon in the orientation you want.") ;


  Gtk::RadioButton config_polygon_radiobutton_type_normal("Normal polygon") ;

  Gtk::RadioButton config_polygon_radiobutton_type_strikethrough("Strikethrough polygon") ;

  config_polygon_radiobutton_type_strikethrough.join_group(config_polygon_radiobutton_type_normal)  ;


  config_polygon_radiobutton_type_normal.set_mode(false)                                     ;
  config_polygon_radiobutton_type_normal.set_active( ((controller.polygon_strikethrough) ? false : true)  )   ;

  config_polygon_radiobutton_type_strikethrough.set_mode(false)                              ;
  config_polygon_radiobutton_type_strikethrough.set_active(controller.polygon_strikethrough) ;

  Gtk::Box config_polygon_box_config_edges                              ;

  Gtk::Box config_polygon_box_config_offset                             ;

  Gtk::Box config_polygon_box_config_type(Gtk::ORIENTATION_VERTICAL)    ;


  config_polygon_box_config_edges.set_spacing(DRAWNING_DIALOG_BOX_SPACING)      ;
  config_polygon_box_config_edges.set_border_width(DRAWNING_DIALOG_BOX_BORDER)  ;

  config_polygon_box_config_offset.set_spacing(DRAWNING_DIALOG_BOX_SPACING)     ;
  config_polygon_box_config_offset.set_border_width(DRAWNING_DIALOG_BOX_BORDER) ;

  config_polygon_box_config_type.set_spacing(DRAWNING_DIALOG_BOX_SPACING)       ;
  config_polygon_box_config_type.set_border_width(DRAWNING_DIALOG_BOX_BORDER)   ;



  config_polygon_box_config_edges.pack_start(config_polygon_label_edges,                   false, false,  0) ;
  config_polygon_box_config_edges.pack_start(config_polygon_spinbutton_edges,              true,  true,   0) ;

  config_polygon_box_config_offset.pack_start(config_polygon_label_polygon_offset,         false, false,  0) ;
  config_polygon_box_config_offset.pack_start(config_polygon_spinbutton_offset,            true,  true,   0) ;

  config_polygon_box_config_type.pack_start(config_polygon_radiobutton_type_normal,        true,  true,   0) ;
  config_polygon_box_config_type.pack_start(config_polygon_radiobutton_type_strikethrough, true,  true,   0) ;


  Gtk::Box *content_v_box = dialog.get_content_area() ;

  content_v_box->pack_start(config_polygon_box_config_edges,         false, false, 0)   ;
  content_v_box->pack_start(config_polygon_box_config_offset,        false, false, 0)   ;
  content_v_box->pack_start(config_polygon_box_config_type,          false, false, 0)   ;

  // Create accelerator:
  Glib::RefPtr<Gtk::AccelGroup>     accel_group        ;

  Gdk::ModifierType no_modifier =  Gdk::MODIFIER_MASK ;

  no_modifier ^= no_modifier ;

  accel_group = accel_group->create() ;

  button_ok.add_accelerator("clicked", accel_group, GDK_KEY_Return, no_modifier, Gtk::ACCEL_VISIBLE) ;

  dialog.add_accel_group(accel_group) ;


  content_v_box->show_all() ;

  controller.config_draw_success = dialog.run() ;

  // Handle the response:
  switch (controller.config_draw_success) {

    case (Gtk::RESPONSE_OK) :



       controller.polygon_edges         = config_polygon_spinbutton_edges.get_value_as_int()                 ;
       controller.polygon_offset        = config_polygon_spinbutton_offset.get_value()                       ;
       controller.polygon_strikethrough = config_polygon_radiobutton_type_strikethrough.get_active()         ;
       //controller.polygon_stroke_star   = config_polygon_radiobutton_type_stroke_star.get_active()           ;

       break ;

    case (Gtk::RESPONSE_CANCEL) :

      if (main_window_gdk_window->get_cursor() != mouse_cursor_default) {
        // Reset cursor.
        main_window_gdk_window->set_cursor() ;
      }

      controller.mouse_draw_x1 = 0  ;
      controller.mouse_draw_y1 = 0  ;

      controller.mouse_draw_x2 = 0  ;
      controller.mouse_draw_y2 = 0  ;

      controller.mouse_curser_changed = -1 ;

      controller.drawning_status      = -1 ;

      button_draw_polygon.set_active(false) ;

      break ;

  }

  dialog.close() ;

  return ;

}




void GUI::config_star_draw(Controller &controller) {

  /** Display a dialog for star drawning configurating. **/

  Gtk::Dialog dialog("Configure star to insert.", true) ;

  // Configure dialog:
  dialog.set_border_width(2)  ;
  dialog.set_resizable(false) ;
  dialog.set_decorated(false) ;
  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "draw-star.png") ;
  dialog.set_position(Gtk::WIN_POS_CENTER_ON_PARENT) ;
  dialog.set_type_hint(Gdk::WINDOW_TYPE_HINT_DIALOG) ;
  dialog.set_transient_for(*this) ;


  // Add action buttons
  Gtk::ButtonBox *buttonbox = dialog.get_action_area() ;

  buttonbox->set_layout(Gtk::BUTTONBOX_EDGE) ;
  buttonbox->set_homogeneous(true) ;

  Gtk::Button button_ok("OK") ;
  Gtk::Image  image_ok(PATH_TO_BUTTON_ICONS "dialog-ok-apply.png")  ;

  button_ok.set_image(image_ok)         ;
  button_ok.set_always_show_image(true) ;

  Gtk::Button button_cancel("Cancel")  ;
  Gtk::Image  image_cancel(PATH_TO_BUTTON_ICONS "dialog-cancel.png") ;

  button_cancel.set_image(image_cancel)     ;
  button_cancel.set_always_show_image(true) ;

  dialog.add_action_widget(button_cancel, Gtk::RESPONSE_CANCEL) ;
  dialog.add_action_widget(button_ok,     Gtk::RESPONSE_OK)     ;


  Gtk::Label config_star_label_pikes("Pikes   ") ;

  Gtk::SpinButton config_star_spinbutton_pikes ;

  config_star_spinbutton_pikes.set_digits(0)     ;
  config_star_spinbutton_pikes.set_range(5.0, 720.0) ;
  config_star_spinbutton_pikes.set_value(controller.star_pikes)     ;
  config_star_spinbutton_pikes.set_increments(1.0, 10.0)     ;
  config_star_spinbutton_pikes.set_update_policy(Gtk::UPDATE_IF_VALID ) ;
  config_star_spinbutton_pikes.set_wrap(true) ;
  config_star_spinbutton_pikes.set_numeric(true) ;
  config_star_spinbutton_pikes.set_snap_to_ticks(true) ;

  config_star_spinbutton_pikes.set_has_frame(true) ;
  config_star_spinbutton_pikes.set_max_length(3) ;
  config_star_spinbutton_pikes.set_width_chars(3) ;
  config_star_spinbutton_pikes.set_alignment(0.5f) ;

  config_star_spinbutton_pikes.set_tooltip_text("The number of pikes of the star.") ;


  Gtk::Label config_star_label_star_offset("Offset ") ;

  Gtk::SpinButton config_star_spinbutton_offset ;

  config_star_spinbutton_offset.set_digits(2)         ;
  config_star_spinbutton_offset.set_range(0.0, 720.0) ;
  config_star_spinbutton_offset.set_value(controller.star_offset)     ;
  config_star_spinbutton_offset.set_increments(0.1, 10.0)     ;
  config_star_spinbutton_offset.set_update_policy(Gtk::UPDATE_IF_VALID ) ;
  config_star_spinbutton_offset.set_wrap(true) ;
  config_star_spinbutton_offset.set_numeric(true) ;
  config_star_spinbutton_offset.set_snap_to_ticks(true) ;
  config_star_spinbutton_offset.set_has_frame(true) ;
  config_star_spinbutton_offset.set_max_length(6) ;
  config_star_spinbutton_offset.set_width_chars(6) ;
  config_star_spinbutton_offset.set_alignment(0.5f) ;

  config_star_spinbutton_offset.set_tooltip_text("Rotation angle to add. To get your star in the orientation you want.") ;


  Gtk::RadioButton config_star_radiobutton_type_normal("Normal star") ;

  Gtk::RadioButton config_star_radiobutton_type_strikethrough("Strikethrough star") ;

  Gtk::RadioButton config_star_radiobutton_type_flower("Flower like star") ;

  Gtk::RadioButton config_star_radiobutton_type_strokes("Strokes star") ;

  config_star_radiobutton_type_strikethrough.join_group(config_star_radiobutton_type_normal)  ;
  config_star_radiobutton_type_flower.join_group(config_star_radiobutton_type_normal)         ;
  config_star_radiobutton_type_strokes.join_group(config_star_radiobutton_type_normal)        ;

  config_star_radiobutton_type_normal.set_mode(false)                                   ;
  config_star_radiobutton_type_normal.set_active( ( controller.star_strikethrough || controller.star_flower || controller.star_strokes ) ? false : true)     ;

  config_star_radiobutton_type_strikethrough.set_mode(false)                            ;
  config_star_radiobutton_type_strikethrough.set_active(controller.star_strikethrough)  ;

  config_star_radiobutton_type_flower.set_mode(false)                                   ;
  config_star_radiobutton_type_flower.set_active(controller.star_flower)                ;

  config_star_radiobutton_type_strokes.set_mode(false)                                  ;
  config_star_radiobutton_type_strokes.set_active(controller.star_strokes)              ;


  Gtk::CheckButton config_star_checkbutton_correct_star("Correct star (for 5 pikes star)") ;

  config_star_checkbutton_correct_star.set_active(controller.star_correcting) ;
  config_star_checkbutton_correct_star.set_tooltip_text("This only work for 5 pikes star to make a regular pentacle or pentagram") ;


  Gtk::Box config_star_box_config_pikes(Gtk::ORIENTATION_HORIZONTAL)   ;

  Gtk::Box config_star_box_config_offset(Gtk::ORIENTATION_HORIZONTAL)  ;

  Gtk::Box config_star_box_config_type(Gtk::ORIENTATION_VERTICAL)      ;

  Gtk::Box config_star_box_correct_star(Gtk::ORIENTATION_VERTICAL)     ;

  config_star_box_config_pikes.set_spacing(DRAWNING_DIALOG_BOX_SPACING)              ;
  config_star_box_config_pikes.set_border_width(DRAWNING_DIALOG_BOX_BORDER)          ;

  config_star_box_config_offset.set_spacing(DRAWNING_DIALOG_BOX_SPACING)             ;
  config_star_box_config_offset.set_border_width(DRAWNING_DIALOG_BOX_BORDER)         ;

  config_star_box_config_type.set_spacing(DRAWNING_DIALOG_BOX_SPACING)               ;
  config_star_box_config_type.set_border_width(DRAWNING_DIALOG_BOX_BORDER)           ;

  config_star_box_correct_star.set_spacing(DRAWNING_DIALOG_BOX_SPACING)              ;
  config_star_box_correct_star.set_border_width(DRAWNING_DIALOG_BOX_BORDER)          ;




  config_star_box_config_pikes.pack_start(config_star_label_pikes,                   false, false,  0) ;
  config_star_box_config_pikes.pack_start(config_star_spinbutton_pikes,              true,  true,   0) ;

  config_star_box_config_offset.pack_start(config_star_label_star_offset,            false, false,  0) ;
  config_star_box_config_offset.pack_start(config_star_spinbutton_offset,            true,  true,   0) ;

  config_star_box_config_type.pack_start(config_star_radiobutton_type_normal,        true,  true,   0) ;
  config_star_box_config_type.pack_start(config_star_radiobutton_type_strikethrough, true,  true,   0) ;
  config_star_box_config_type.pack_start(config_star_radiobutton_type_flower,        true,  true,   0) ;
  config_star_box_config_type.pack_start(config_star_radiobutton_type_strokes,       true,  true,   0) ;

  config_star_box_correct_star.pack_start(config_star_checkbutton_correct_star,      true,  true,   0) ;


  Gtk::Box *content_v_box = dialog.get_content_area() ;

  content_v_box->pack_start(config_star_box_config_pikes,         false, false, 0)   ;
  content_v_box->pack_start(config_star_box_config_offset,        false, false, 0)   ;
  content_v_box->pack_start(config_star_box_config_type,          false, false, 0)   ;
  content_v_box->pack_start(config_star_box_correct_star,         false, false, 0)   ;

  // Create accelerator:
  Glib::RefPtr<Gtk::AccelGroup>     accel_group        ;

  Gdk::ModifierType no_modifier =  Gdk::MODIFIER_MASK ;

  no_modifier ^= no_modifier ;

  accel_group = accel_group->create() ;

  button_ok.add_accelerator("clicked", accel_group, GDK_KEY_Return, no_modifier, Gtk::ACCEL_VISIBLE) ;

  dialog.add_accel_group(accel_group) ;


  content_v_box->show_all() ;

  controller.config_draw_success = dialog.run() ;

  // Handle the response:
  switch (controller.config_draw_success) {

    case (Gtk::RESPONSE_OK) :


       controller.star_pikes         = config_star_spinbutton_pikes.get_value_as_int()                 ;
       controller.star_offset        = config_star_spinbutton_offset.get_value()                       ;
       controller.star_strikethrough = config_star_radiobutton_type_strikethrough.get_active()         ;
       controller.star_flower        = config_star_radiobutton_type_flower.get_active()                ;
       controller.star_strokes       = config_star_radiobutton_type_strokes.get_active()               ;

       controller.star_correcting    = config_star_checkbutton_correct_star.get_active()               ;

       break ;

    case (Gtk::RESPONSE_CANCEL) :

      if (main_window_gdk_window->get_cursor() != mouse_cursor_default) {
        // Reset cursor.
        main_window_gdk_window->set_cursor() ;
      }

      controller.mouse_draw_x1 = 0  ;
      controller.mouse_draw_y1 = 0  ;

      controller.mouse_draw_x2 = 0  ;
      controller.mouse_draw_y2 = 0  ;

      controller.mouse_curser_changed = -1 ;

      controller.drawning_status = -1 ;

      button_draw_star.set_active(false) ;

      break ;

  }

  dialog.close() ;

  return ;

}

void GUI::config_draw_text(Controller &controller) {

  /** Display a dialog for star drawning configurating. **/

  Gtk::Dialog dialog("Configure insert text.", true) ;

  // Configure the dialog:
  dialog.set_border_width(4)  ;
  dialog.set_resizable(false) ;
  dialog.set_decorated(false) ;
  dialog.set_icon_from_file(PATH_TO_BUTTON_ICONS "insert-text.png") ;
  dialog.set_position(Gtk::WIN_POS_CENTER_ON_PARENT) ;
  dialog.set_type_hint(Gdk::WINDOW_TYPE_HINT_DIALOG) ;
  dialog.set_transient_for(*this) ;

  // Add action buttons
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



  Gtk::Entry config_font_entry_text ;

  config_font_entry_text.set_width_chars(48) ;
  config_font_entry_text.set_max_length(80) ;
  config_font_entry_text.set_alignment(0.5) ;
  config_font_entry_text.set_placeholder_text("Enter your text here...") ;
  config_font_entry_text.set_receives_default(true) ;
  config_font_entry_text.set_tooltip_text("Enter your text here...") ;

  Gtk::ListBox listbox_config_text_font ;

  const vector<string> fonts_description = {
                                             "Small size sans-serif font",
                                             "Small size serif font",

                                             "Normal size sans-serif font",
                                             "Normal size sans-serif font variant",

                                             "Normal size serif font",
                                             "Normal size serif font variant",

                                             "Hand-writing style font ",
                                             "Hand-writing style font variant"

                                            } ;



  const vector<cv::HersheyFonts> font_id = {
                                             cv::FONT_HERSHEY_PLAIN ,
                                             cv::FONT_HERSHEY_COMPLEX_SMALL,

                                             cv::FONT_HERSHEY_SIMPLEX,
                                             cv::FONT_HERSHEY_DUPLEX,

                                             cv::FONT_HERSHEY_COMPLEX,
                                             cv::FONT_HERSHEY_TRIPLEX,

                                             cv::FONT_HERSHEY_SCRIPT_SIMPLEX,
                                             cv::FONT_HERSHEY_SCRIPT_COMPLEX,
                                      
                                            } ;


  Gtk::ComboBoxText config_font_combotext_font(true) ;

  for (int c=0 ; c < static_cast<int>(fonts_description.size()) ; c++) {

    config_font_combotext_font.append(fonts_description.at(c)) ;

  }


  config_font_combotext_font.set_active(controller.put_text_font_face_id)       ;
  config_font_combotext_font.set_border_width(6) ;
  config_font_combotext_font.set_tooltip_text("Choose the font to use to insert your text") ;


  Gtk::CheckButton config_font_checkbutton_is_font_italic(" Set in italic ") ;
  Gtk::Image config_font_image_checkbutton_is_font_italic(PATH_TO_BUTTON_ICONS "format-text-italic.png") ;

  config_font_checkbutton_is_font_italic.set_image(config_font_image_checkbutton_is_font_italic) ;
  config_font_checkbutton_is_font_italic.set_always_show_image(true) ;
  config_font_checkbutton_is_font_italic.set_mode(false) ;



  Gtk::Button config_font_label_font_size("Font scale factor") ;
  Gtk::Image  config_font_image_label_font_size(PATH_TO_BUTTON_ICONS "preferences-desktop-font.png") ;

  config_font_label_font_size.set_relief(Gtk::RELIEF_NONE) ;
  config_font_label_font_size.set_image(config_font_image_label_font_size) ;
  config_font_label_font_size.set_always_show_image(true) ;



  Gtk::SpinButton config_font_spinbutton_size ;

  config_font_spinbutton_size.set_digits(2)     ;
  config_font_spinbutton_size.set_range(0.1, 16.0) ;
  config_font_spinbutton_size.set_value(controller.polygon_edges)     ;
  config_font_spinbutton_size.set_increments(0.1, 10.0)     ;
  config_font_spinbutton_size.set_value(controller.put_text_font_scale)     ;
  config_font_spinbutton_size.set_update_policy(Gtk::UPDATE_IF_VALID ) ;
  config_font_spinbutton_size.set_wrap(true) ;
  config_font_spinbutton_size.set_numeric(true) ;
  config_font_spinbutton_size.set_snap_to_ticks(true) ;
  config_font_spinbutton_size.set_has_frame(true) ;
  config_font_spinbutton_size.set_max_length(6) ;
  config_font_spinbutton_size.set_width_chars(6) ;
  config_font_spinbutton_size.set_alignment(0.5f) ;


  Gtk::Box config_font_hbox_entry(Gtk::ORIENTATION_HORIZONTAL) ;
  config_font_hbox_entry.set_border_width(6) ;

  Gtk::Box config_font_vbox_combotext(Gtk::ORIENTATION_VERTICAL) ;
  config_font_checkbutton_is_font_italic.set_border_width(6) ;
  config_font_checkbutton_is_font_italic.set_active(controller.put_text_is_italic) ;

  Gtk::Box config_font_hbox_font_size(Gtk::ORIENTATION_HORIZONTAL) ;
  config_font_hbox_font_size.set_border_width(6) ;

  Gtk::Box config_font_hbox_checkbutton_is_italic(Gtk::ORIENTATION_HORIZONTAL) ;
  config_font_combotext_font.set_border_width(6) ;

  config_font_hbox_entry.pack_start(config_font_entry_text , true, true, 0) ;

  config_font_vbox_combotext.pack_start(config_font_combotext_font,   false,  false, 0) ;

  config_font_hbox_font_size.pack_start(config_font_label_font_size,  true,  true, 0) ;
  config_font_hbox_font_size.pack_start(config_font_spinbutton_size,  false, false, 0) ;

  config_font_hbox_checkbutton_is_italic.pack_start(config_font_checkbutton_is_font_italic, true, true, 0) ;



  Gtk::Box *content_v_box = dialog.get_content_area() ;

  content_v_box->pack_start(config_font_hbox_entry,                 true,  true,  0) ;
  content_v_box->pack_start(config_font_vbox_combotext,             true,  true, 0) ;
  content_v_box->pack_start(config_font_hbox_font_size,             true,  true, 0) ;
  content_v_box->pack_start(config_font_hbox_checkbutton_is_italic, true,  true, 0) ;


  // Create accelerator:
  Glib::RefPtr<Gtk::AccelGroup>     accel_group        ;

  Gdk::ModifierType no_modifier =  Gdk::MODIFIER_MASK ;

  no_modifier ^= no_modifier ;

  accel_group = accel_group->create() ;

  button_ok.add_accelerator("clicked", accel_group, GDK_KEY_Return, no_modifier, Gtk::ACCEL_VISIBLE) ;

  dialog.add_accel_group(accel_group) ;



  content_v_box->show_all() ;

  back_to_dialog :  // Label in case the user has not enter some text.

  controller.config_draw_success = dialog.run() ;


  // Handle the response:
  switch (controller.config_draw_success) {

    case (Gtk::RESPONSE_OK) :

       controller.put_text_font_scale = config_font_spinbutton_size.get_value() ;

       controller.put_text_font_face = font_id.at(config_font_combotext_font.get_active_row_number()) ;

       controller.put_text_font_face_id = config_font_combotext_font.get_active_row_number() ;

       controller.put_text_is_italic = config_font_checkbutton_is_font_italic.get_active() ;


       if ( (controller.put_text_string  = config_font_entry_text.get_text()).empty() ) {

         message_dialog("Error no data !", "You must enter some text,\nto insert it in image !") ;

         goto back_to_dialog ;

       }



       #ifdef DEBUG
       fprintf(stdout,"\n%s text: %s\n",       __func__, controller.put_text_string.c_str()) ;
       fprintf(stdout,"%s font scale: %lf\n",  __func__, controller.put_text_font_scale) ;
       fprintf(stdout,"%s font face: %s\n",    __func__, fonts_description.at(config_font_combotext_font.get_active_row_number()).c_str() ) ;
       fprintf(stdout,"%s use italic: %d\n\n", __func__, controller.put_text_is_italic)    ;
       #endif


       break ;

    case (Gtk::RESPONSE_CANCEL) :

      if (main_window_gdk_window->get_cursor() != mouse_cursor_default) {
        // Reset cursor.
        main_window_gdk_window->set_cursor() ;
      }

      controller.mouse_draw_x1 = 0  ;
      controller.mouse_draw_y1 = 0  ;

      controller.mouse_draw_x2 = 0  ;
      controller.mouse_draw_y2 = 0  ;

      controller.mouse_curser_changed = 0 ;

      controller.drawning_status = -1 ;

      button_draw_polygon.set_active(false) ;

      if (main_window_gdk_window->get_cursor() != mouse_cursor_default) {
        // Reset cursor.
        main_window_gdk_window->set_cursor() ;
      }

      button_draw_text.set_active(false) ;

      break ;

  }

  dialog.close() ;

  return ;

}

#endif