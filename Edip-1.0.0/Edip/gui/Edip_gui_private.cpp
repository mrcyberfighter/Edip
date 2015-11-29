#ifndef EDIP_GUI_PRIVATE_HH
#define EDIP_GUI_PRIVATE_HH

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


/** GUI intern signal connected methods. **/


bool GUI::drawning_add_offset(GdkEventKey *event, Controller &controller) {

  if ( (! button_draw_star.get_active() || ! controller.config_draw_success == Gtk::RESPONSE_OK) && ( ! button_draw_polygon.get_active() || ! controller.config_draw_success == Gtk::RESPONSE_OK ) ) { return false ; }

  if (event->keyval == GDK_KEY_asterisk) {
    controller.draw_offset -= 1.0 ;
    mouse_motion_event_handler_update_offset(controller) ;

    return false ;
  }
  else if (event->keyval == GDK_KEY_dollar) {
    controller.draw_offset += 1.0 ;
    mouse_motion_event_handler_update_offset(controller) ;

    return false ;
  }
  else if (event->keyval == GDK_KEY_equal) {
    drawning_press_enter_callback(controller) ;
    return false ;
  }

  return false ;

}



void GUI::get_draw_color() {

  draw_color = colorbutton_draw.get_rgba() ;

}

void GUI::get_draw_thickness() {

  draw_thickness = spinbutton_draw_thickness.get_value_as_int() ;
}

void GUI::get_draw_line_type() {

  switch (combo_lines_type.get_active_row_number()) {

    case 0 :

      draw_line_type = cv::LINE_4   ;
      break ;

    case 1 :

      draw_line_type = cv::LINE_8 ;
      break ;

    case 2 :

      draw_line_type = cv::LINE_AA  ;
      break ;
  }

}

void GUI::on_changed_filters_comboboxtext(Controller &controller) {

  // Getting combo filters choice.
  combo_current_filter = combo_filters.get_active_row_number() ;

  // So that we automate the tooltip setting from filters combo.
  entry_combo_filters->set_tooltip_text(get_combo_entry_tooltip_text(0)) ;

}

void GUI::on_changed_grayscale_comboboxtext(Controller &controller) {

  // Getting combo graycaling choice.
  combo_current_grayscaling = combo_grayscale.get_active_row_number() ;

  // So that we automate the tooltip setting from grayscaling combo.
  entry_combo_grayscale->set_tooltip_text(get_combo_entry_tooltip_text(1)) ;

}

void GUI::on_changed_colorscale_comboboxtext(Controller &controller) {

  // Getting combo colorscaling choice.
  combo_current_colorscaling = combo_colorscale.get_active_row_number() ;

  // So that we automate the tooltip setting from colorscaling combo.
  entry_combo_colorscale->set_tooltip_text(get_combo_entry_tooltip_text(2)) ;

}



void GUI::click_button_zoom_pointer(Controller &controller) {


  if ( button_zoom_pointer.get_active()  ) {

    if (main_window_gdk_window->get_cursor() != mouse_cursor_default) {
      // Reset cursor.
      main_window_gdk_window->set_cursor() ;

    }

    controller.reset_zoom_center(controller.current_image_to_process) ;


  }

  return ;

}



void GUI::click_button_draw_pointer(Controller &controller, uint8_t button) {

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

  switch (button) {

    case 41 :

      if ( button_draw_line.get_active()) {

        button_draw_rect.set_active(false)    ;
        button_draw_circle.set_active(false)  ;
        button_draw_ellipse.set_active(false) ;
        button_draw_polygon.set_active(false) ;
        button_draw_text.set_active(false)    ;

        controller.polylines_points_nb = 0 ;

        controller.polylines.clear() ;
        controller.polylines.shrink_to_fit() ;

        return ;

      }

      break ;

  case 42 :

    if ( button_draw_rect.get_active()) {

      button_draw_line.set_active(false)    ;
      button_draw_circle.set_active(false)  ;
      button_draw_ellipse.set_active(false) ;
      button_draw_polygon.set_active(false) ;
      button_draw_text.set_active(false)    ;

      return ;

    }

    break ;


  case 43 :

    if ( button_draw_circle.get_active() ) {

      button_draw_line.set_active(false)    ;
      button_draw_rect.set_active(false)    ;
      button_draw_ellipse.set_active(false) ;
      button_draw_polygon.set_active(false) ;
      button_draw_star.set_active(false)    ;
      button_draw_text.set_active(false)    ;

      return ;

    }

    break ;

  case 44 :

    if ( button_draw_ellipse.get_active() ) {

      button_draw_line.set_active(false)    ;
      button_draw_rect.set_active(false)    ;
      button_draw_circle.set_active(false)  ;
      button_draw_polygon.set_active(false) ;
      button_draw_star.set_active(false)    ;
      button_draw_text.set_active(false)    ;

      return ;

    }

    break ;

  case 45 :

    if ( button_draw_polygon.get_active() ) {

      button_draw_line.set_active(false)    ;
      button_draw_rect.set_active(false)    ;
      button_draw_circle.set_active(false)  ;
      button_draw_ellipse.set_active(false) ;
      button_draw_star.set_active(false)    ;
      button_draw_text.set_active(false)    ;

      config_polygon_draw(controller) ;

      return ;

    }

    break ;

  case 46 :

    if ( button_draw_star.get_active() ) {

      button_draw_line.set_active(false)    ;
      button_draw_rect.set_active(false)    ;
      button_draw_circle.set_active(false)  ;
      button_draw_ellipse.set_active(false) ;
      button_draw_polygon.set_active(false) ;
      button_draw_text.set_active(false)    ;

      config_star_draw(controller) ;

      return ;

    }

  case 47 :

    if ( button_draw_text.get_active() ) {

      button_draw_line.set_active(false)    ;
      button_draw_rect.set_active(false)    ;
      button_draw_circle.set_active(false)  ;
      button_draw_ellipse.set_active(false) ;
      button_draw_polygon.set_active(false) ;
      button_draw_star.set_active(false)    ;

      config_draw_text(controller) ;



      return ;

    }

    break ;

  }




}






void GUI::set_img(const cv::Mat &frame, cv::Mat &result, Controller &controller) {

  /** result == controller.current_image_to_display. */

  // Convert controller.current_image_to_process (as src) to RGB(A) controller.current_image_to_display (as dst).
  convert_image_to_gui_output_format(frame, result) ;


  if (widget_current_image_to_display != NULL) {

    delete widget_current_image_to_display ;
  }

  widget_current_image_to_display = Gtk::manage(new Gtk::Image());

  widget_current_image_to_display->clear() ;

  if (result.depth() != CV_8U) { // This desnt' should be !

    result.assignTo(result, CV_8U) ;

  }

  // We resize the original image every time we display it.
  // It's better like this because the image is resized (if needed) only one time per changement
  // Not always resizing the same image.

  //controller.resize_image_to_display(result) ;

  if (controller.get_image_size_gt_layout()) {
    cv::resize(result, result, cv::Size(controller.display_image_size.first, controller.display_image_size.second), 1.0, 1.0, cv::INTER_LINEAR) ;
  }


  IplImage iplimg = _IplImage(result) ;

  widget_current_image_to_display->set(Gdk::Pixbuf::create_from_data( (const guint8 *) iplimg.imageData,
                                       Gdk::COLORSPACE_RGB,
                                       (result.channels() == 4),
                                       iplimg.depth,
                                       iplimg.width,
                                       iplimg.height,
                                       iplimg.widthStep)) ;



  widget_current_image_to_display->show() ;

  display_area.put(*widget_current_image_to_display, controller.current_image_position.first, controller.current_image_position.second) ;

}




inline void GUI::switch_intensity_hsbl(int page_nb) {

  if (page_nb >= 0 && page_nb <= 1) {

    if ( page_nb != notebook_switcher.get_current_page() ) {

      if (page_nb == 0) {


        image_switcher_on.clear() ;
        image_switcher_off.clear() ;

        image_switcher_on.set(PATH_TO_BUTTON_ICONS "dialog-ok-apply.png") ;
        image_switcher_off.set(PATH_TO_BUTTON_ICONS "list-remove.png") ;


      }
      else {


        image_switcher_on.clear() ;
        image_switcher_off.clear() ;

        image_switcher_on.set(PATH_TO_BUTTON_ICONS "list-remove.png") ;
        image_switcher_off.set(PATH_TO_BUTTON_ICONS "dialog-ok-apply.png") ;


      }

      notebook_switcher.set_current_page(page_nb) ;

    }

  }

}

#endif

