#ifndef EDIP_GUI_EVENTS_END_HH
#define EDIP_GUI_EVENTS_END_HH

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

void GUI::get_display_area_size(Gtk::Allocation &scr, Controller &controller) {

  auto container_size = controller.get_layout_size() ;

  display_area_width=scr.get_width() ;
  display_area_height=scr.get_height() ;

  if (container_size.first == display_area_width && container_size.second == display_area_height) {
    // If nothing changed we return.
    display_area_size_changed = false ;
    return ;
  }

  display_area_size_changed = true ;

  controller.set_layout_size(scr.get_width(), scr.get_height()) ;

  int width, height ;

  get_size(width, height) ;

  controller.set_window_size(width, height) ;

  have_layout_size = true ;


  if ( widget_current_image_to_display != NULL ) {


    // Updating current image sizes and positions values.
    controller.get_current_image_position() ;

    if ( controller.get_image_size_gt_layout() || controller.get_image_lt_layout() ) {
      set_img(controller.current_image_to_process, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).
      return ;
    }


    // Set image at right position.
    display_area.move(*widget_current_image_to_display, controller.current_image_position.first, controller.current_image_position.second) ;

  }

}


bool GUI::on_display_area_button_press_handler(GdkEventButton *event_button, Controller &controller) {

  if (button_zoom_pointer.get_active() ) { // This is in relationship with the button setting for mouse selection of zoom center.

    if ( controller.mouse_into_image && controller.mouse_curser_changed == 1 && event_button->button == 1 ) {

      // Settings the zoom center coordinates by mutiplying the coordinates from inside the image per factors:
      controller.mouse_zoom_center_x =  static_cast<float>(controller.mouse_inside_image_x) *  controller.factor_width   ;
      controller.mouse_zoom_center_y =  static_cast<float>(controller.mouse_inside_image_y) *  controller.factor_height   ;

      controller.process_after_applying() ;  // We register current frame in vector<cv::Mat> for undo-redo.

      // It convert current_image_to_process as src to RGB(A) in dst current_image_to_display.
      set_img(controller.current_image_to_process, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).
    

      // Reset cursor.
      main_window_gdk_window->set_cursor() ;

      // Reset control variables:
      controller.mouse_curser_changed = -1 ;
  
      controller.draw_offset = 0.0 ;

      if ( button_zoom_pointer.get_active() ) {
        // If button pressed, raise it.
        button_zoom_pointer.set_active(false) ;
      }

    }
    else if (event_button->button != 1) {

      // Reset cursor.
      main_window_gdk_window->set_cursor() ;

      controller.reset_zoom_center(controller.current_image_to_process) ;

      controller.mouse_curser_changed = -1 ;

      if ( button_zoom_pointer.get_active() ) {
        // If button pressed, raise it.
        button_zoom_pointer.set_active(false) ;
      }

    }

  }
  else if ( button_draw_rect.get_active() || button_draw_line.get_active() || button_draw_circle.get_active() || button_draw_ellipse.get_active() || button_draw_polygon.get_active() || button_draw_star.get_active() || button_draw_text.get_active() ) {

    if ( controller.mouse_into_image && controller.mouse_curser_changed == 1 && event_button->button == 1 ) {

      if ( (controller.drawning_status == -1) || (controller.drawning_status == 1) ) {

        // Getting the drawning coordinates onto the real (not resized) image by multiplying per factors:
        controller.mouse_draw_x1 =  static_cast<float>(controller.mouse_inside_image_x) *  controller.factor_width   ;
        controller.mouse_draw_y1 =  static_cast<float>(controller.mouse_inside_image_y) *  controller.factor_height   ;

        controller.drawning_status = 0 ;

        controller.saved_frame = controller.current_image_to_process.clone() ;



        if ( button_draw_line.get_active() ) {
          goto fake_mouse_1_button_press  ;
        }
        if ( button_draw_text.get_active() ) {
          goto fake_mouse_1_button_press ;
        }

        return false ;




      }
      else if (controller.drawning_status == 0) {



        fake_mouse_1_button_press :

        // Getting the drawning coordinates onto the real (not resized) image by multiplying per factors:
        controller.mouse_draw_x2 =  static_cast<float>(controller.mouse_inside_image_x) *  controller.factor_width   ;
        controller.mouse_draw_y2 =  static_cast<float>(controller.mouse_inside_image_y) *  controller.factor_height   ;

        controller.drawning_status = 1 ;

        cv::Scalar color(draw_color.get_blue_u() >> 8, draw_color.get_green_u() >> 8, draw_color.get_red_u() >> 8, draw_color.get_alpha_u() >> 8) ;

        cv::Mat frame = controller.current_image_to_process.clone() ;



        if (button_draw_line.get_active() ) {

           if ( controller.polylines_points_nb == 0) {

             controller.polylines_start_rect = cv::Rect( cv::Point(controller.mouse_draw_x1-7, controller.mouse_draw_y1-7), cv::Size(15, 15) ) ;

           }



           controller.polylines.push_back( cv::Point(controller.mouse_draw_x1, controller.mouse_draw_y1)) ;

           controller.polylines_points_nb++ ;

           if ( controller.polylines_points_nb > 1) {



             if ( controller.polylines_start_rect.contains(cv::Point(controller.mouse_draw_x1,   controller.mouse_draw_y1)) ) {

              draw_polylines(frame , controller.polylines, true, (draw_thickness < 0),  color, (draw_thickness < 0) ? 0 : draw_thickness , draw_line_type) ;
              controller.polylines_points_nb = 0 ;

              controller.polylines.clear() ;
              controller.polylines.shrink_to_fit() ;
            }
            else {
              draw_polylines(frame , controller.polylines, false, false,  color, (draw_thickness < 0) ? 0 : draw_thickness, draw_line_type) ;
            }

           }


        }
        else if (button_draw_rect.get_active()) {


          cv::Rect rect( cv::Point(controller.mouse_draw_x1, controller.mouse_draw_y1), cv::Point(controller.mouse_draw_x2, controller.mouse_draw_y2) ) ;

          draw_rect(frame, rect, color, draw_thickness, draw_line_type) ;

        }
        else if (button_draw_circle.get_active() ) {

          const int radius = static_cast<int>(roundf( sqrtf(powf(static_cast<float>(controller.mouse_draw_x2)-static_cast<float>(controller.mouse_draw_x1), 2) + powf(static_cast<float>(controller.mouse_draw_y2)-static_cast<float>(controller.mouse_draw_y1), 2))) ) ;

          draw_circle(frame, cv::Point(controller.mouse_draw_x1, controller.mouse_draw_y1), radius, color, draw_thickness, draw_line_type) ;

        }
        else if (button_draw_ellipse.get_active() ) {

          const int distance_x = abs(controller.mouse_draw_x1-controller.mouse_draw_x2) ;
          const int distance_y = abs(controller.mouse_draw_y1-controller.mouse_draw_y2) ;

          const cv::RotatedRect rot_rect(cv::Point2f( static_cast<float>(controller.mouse_draw_x1), static_cast<float>(controller.mouse_draw_y1) ), cv::Size(abs( distance_x * 2 ), abs( distance_y * 2 ) ), 0.0  ) ;

          draw_ellipse(frame, rot_rect, color, draw_thickness, draw_line_type) ;

        }
        else if (button_draw_polygon.get_active() && controller.config_draw_success == Gtk::RESPONSE_OK ) {

            const double radius = round( sqrt (pow(static_cast<double>(controller.mouse_draw_x2)-static_cast<double>(controller.mouse_draw_x1), 2) + pow(static_cast<double>(controller.mouse_draw_y2)-static_cast<double>(controller.mouse_draw_y1), 2)) ) ;

            vector<cv::Point> polygon ;

            double offset_correct = 0.0 ;

            if ((controller.polygon_edges > 4) && (controller.polygon_edges % 2 == 1)) {
              offset_correct = 360.0 / controller.polygon_edges / 2.0 / 2.0  ;
            }

            bool fill = false ;

            if ( ! controller.polygon_strikethrough && draw_thickness < 0 ) { fill = true ; }

            generate_polygon(controller.polygon_edges, radius, cv::Point(controller.mouse_draw_x1, controller.mouse_draw_y1),  polygon, controller.polygon_strikethrough, false,  controller.polygon_offset + controller.draw_offset + offset_correct) ;

            draw_polylines(frame, polygon, true, fill, color, ((draw_thickness < 0) ? 0 : draw_thickness) , draw_line_type) ;


         }
         else if (button_draw_text.get_active() && controller.config_draw_success == Gtk::RESPONSE_OK ) {

            int italic_flags = (controller.put_text_is_italic) ? cv::FONT_ITALIC : 0 ;

            draw_text(frame, controller.put_text_string, cv::Point(controller.mouse_draw_x1, controller.mouse_draw_y1), controller.put_text_font_face | italic_flags, controller.put_text_font_scale, color, ((draw_thickness < 0) ? 0 : draw_thickness), draw_line_type) ;

            controller.drawning_status = 1 ;

         }
         else if (button_draw_star.get_active() && controller.config_draw_success == Gtk::RESPONSE_OK ) {

            const double radius = round( sqrt (pow(static_cast<double>(controller.mouse_draw_x2)-static_cast<double>(controller.mouse_draw_x1), 2) + pow(static_cast<double>(controller.mouse_draw_y2)-static_cast<double>(controller.mouse_draw_y1), 2)) ) ;

            vector<cv::Point> star ;

            bool join_stroke = true ;

            bool fill = false ;

            if ( controller.star_correcting && (! controller.star_strokes) && (controller.star_pikes == 5 ||  controller.star_pikes == 6) ) {

              if ( ! controller.star_flower && ! controller.star_strikethrough && draw_thickness < 0 ) { fill = true ; }

              switch (controller.star_pikes) {

                case 5 :

                  generate_pentagram(radius, cv::Point(controller.mouse_draw_x1, controller.mouse_draw_y1), star, controller.star_strikethrough, controller.star_flower, (360.0 / 5.0 / 2.0 / 2.0) + controller.star_offset + controller.draw_offset ) ;
                  break ;

                case 6 :

                  generate_hexagram(radius, cv::Point(controller.mouse_draw_x1, controller.mouse_draw_y1), star, controller.star_strikethrough, controller.star_flower, controller.star_offset + controller.draw_offset ) ;
                  break ;
 
              }
            }
            else if ( ! controller.star_strokes)  {

              if ( ! controller.star_flower && ! controller.star_strikethrough &&  ! controller.star_strokes && draw_thickness < 0 ) { fill = true ; }

              generate_star(controller.star_pikes , radius , cv::Point(controller.mouse_draw_x1, controller.mouse_draw_y1), star, controller.star_strikethrough, controller.star_flower, controller.star_offset + controller.draw_offset  + ((controller.star_pikes == 5) ? (360.0 / 5.0 / 2.0 / 2.0) : 0) ) ;

            }
            else {
        
              generate_polygon(controller.star_pikes, radius, cv::Point(controller.mouse_draw_x1, controller.mouse_draw_y1), star, false, true, controller.star_offset + controller.draw_offset ) ;

              join_stroke = false ;

            }
       
        
            draw_polylines(frame, star, join_stroke, fill, color, ((draw_thickness < 0) ? 0 : draw_thickness), draw_line_type) ;


         }



        // We register current frame in vector<cv::Mat> for undo-redo.
        controller.process_after_applying(frame) ;

        // It convert current_image_to_process as src to RGB(A) in dst current_image_to_display.
        set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

        frame.release() ;

        controller.saved_frame.release() ;

        controller.mouse_curser_changed = -1 ;

        return false ;

      }

    }
    else if (event_button->button == 3) {

      if (main_window_gdk_window->get_cursor() != mouse_cursor_default) {
        // Reset cursor.
        main_window_gdk_window->set_cursor() ;
      }

      controller.mouse_curser_changed = -1 ;

      controller.drawning_status = -1 ;

      if ( ! controller.saved_frame.empty() ) {
        controller.current_image_to_process = controller.saved_frame ;
      }






      // It convert current_image_to_process as src to RGB(A) in dst current_image_to_display.
      set_img(controller.current_image_to_process, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

      if ( button_draw_line.get_active() ) {

        // If button pressed, raise it.
        button_draw_line.set_active(false) ;

        // Reset control variables:
        controller.polylines_points_nb = 0 ;

        controller.polylines_start_rect = cv::Rect( cv::Point(0, 0), cv::Size(0, 0) ) ;

        controller.polylines.clear() ;
        controller.polylines.shrink_to_fit() ;

      }
      if ( button_draw_rect.get_active() ) {

        // If button pressed, raise it.
        button_draw_rect.set_active(false) ;

      }
      if ( button_draw_circle.get_active() ) {

        // If button pressed, raise it.
        button_draw_circle.set_active(false) ;

      }
      if ( button_draw_ellipse.get_active() ) {

        // If button pressed, raise it.
        button_draw_ellipse.set_active(false) ;

      }
      if (button_draw_polygon.get_active() ){

        // If button pressed, raise it.
        button_draw_polygon.set_active(false) ;

        // Reset control variables:
        controller.config_draw_success = Gtk::RESPONSE_CANCEL ;
    
        controller.draw_offset = 0.0 ;

      }
      if (button_draw_star.get_active() ) {

        // If button pressed, raise it.
        button_draw_star.set_active(false) ;

        // Reset control variables:
        controller.config_draw_success = Gtk::RESPONSE_CANCEL ;
 
        controller.draw_offset = 0.0 ;
 
      }
      if ( button_draw_text.get_active() ) {

        // If button pressed, raise it.
        button_draw_text.set_active(false) ;

        // Reset control variables:
        controller.config_draw_success = Gtk::RESPONSE_CANCEL ;
        controller.put_text_string.clear() ;
        controller.put_text_string.shrink_to_fit() ;

      }





    }

  }

  return false ;

}

void GUI::drawning_press_enter_callback(Controller &controller) {

  if ( button_draw_polygon.get_active() || button_draw_star.get_active() ) {

    if ( controller.mouse_curser_changed == 1 ) {

      if ( (controller.drawning_status == -1) || (controller.drawning_status == 1) ) {

        // Getting the drawning coordinates onto the real (not resized) image by multiplying per factors:
        controller.mouse_draw_x1 =  static_cast<float>(controller.mouse_inside_image_x) *  controller.factor_width   ;
        controller.mouse_draw_y1 =  static_cast<float>(controller.mouse_inside_image_y) *  controller.factor_height   ;
   
        if (controller.mouse_draw_x1 < 0 && controller.mouse_draw_y1 < 0) {
     
          return ;
   
        }
   
        controller.drawning_status = 0 ;

        controller.saved_frame = controller.current_image_to_process.clone() ;

        return ;

      }
      else if (controller.drawning_status == 0) {



        fake_mouse_1_button_press :

        // Getting the drawning coordinates onto the real (not resized) image by multiplying per factors:
        controller.mouse_draw_x2 =  static_cast<float>(controller.mouse_inside_image_x) *  controller.factor_width   ;
        controller.mouse_draw_y2 =  static_cast<float>(controller.mouse_inside_image_y) *  controller.factor_height   ;

        controller.drawning_status = 1 ;

        cv::Scalar color(draw_color.get_blue_u() >> 8, draw_color.get_green_u() >> 8, draw_color.get_red_u() >> 8, draw_color.get_alpha_u() >> 8) ;

        cv::Mat frame = controller.current_image_to_process.clone() ;



   
        if (button_draw_polygon.get_active() && controller.config_draw_success == Gtk::RESPONSE_OK ) {

            const double radius = round( sqrt (pow(static_cast<double>(controller.mouse_draw_x2)-static_cast<double>(controller.mouse_draw_x1), 2) + pow(static_cast<double>(controller.mouse_draw_y2)-static_cast<double>(controller.mouse_draw_y1), 2)) ) ;

            vector<cv::Point> polygon ;

            double offset_correct = 0.0 ;

            if ((controller.polygon_edges > 4) && (controller.polygon_edges % 2 == 1)) {
              offset_correct = 360.0 / controller.polygon_edges / 2.0 / 2.0  ;
            }

            bool fill = false ;

            if ( ! controller.polygon_strikethrough && draw_thickness < 0 ) { fill = true ; }

            generate_polygon(controller.polygon_edges, radius, cv::Point(controller.mouse_draw_x1, controller.mouse_draw_y1),  polygon, controller.polygon_strikethrough, false,  controller.polygon_offset + controller.draw_offset + offset_correct) ;

            draw_polylines(frame, polygon, true, fill, color, ((draw_thickness < 0) ? 0 : draw_thickness) , draw_line_type) ;


         }
         else if (button_draw_star.get_active() && controller.config_draw_success == Gtk::RESPONSE_OK ) {

            const double radius = round( sqrt (pow(static_cast<double>(controller.mouse_draw_x2)-static_cast<double>(controller.mouse_draw_x1), 2) + pow(static_cast<double>(controller.mouse_draw_y2)-static_cast<double>(controller.mouse_draw_y1), 2)) ) ;

            vector<cv::Point> star ;

            bool join_stroke = true ;

            bool fill = false ;

            if ( controller.star_correcting && (! controller.star_strokes) && (controller.star_pikes == 5 ||  controller.star_pikes == 6) ) {

              if ( ! controller.star_flower && ! controller.star_strikethrough && draw_thickness < 0 ) { fill = true ; }

              switch (controller.star_pikes) {

                case 5 :

                  generate_pentagram(radius, cv::Point(controller.mouse_draw_x1, controller.mouse_draw_y1), star, controller.star_strikethrough, controller.star_flower, (360.0 / 5.0 / 2.0 / 2.0) + controller.star_offset + controller.draw_offset ) ;
                  break ;

                case 6 :

                  generate_hexagram(radius, cv::Point(controller.mouse_draw_x1, controller.mouse_draw_y1), star, controller.star_strikethrough, controller.star_flower, controller.star_offset + controller.draw_offset ) ;
                  break ;
 
              }
            }
            else if ( ! controller.star_strokes)  {

              if ( ! controller.star_flower && ! controller.star_strikethrough &&  ! controller.star_strokes && draw_thickness < 0 ) { fill = true ; }

              generate_star(controller.star_pikes , radius , cv::Point(controller.mouse_draw_x1, controller.mouse_draw_y1), star, controller.star_strikethrough, controller.star_flower, controller.star_offset + controller.draw_offset  + ((controller.star_pikes == 5) ? (360.0 / 5.0 / 2.0 / 2.0) : 0) ) ;

            }
            else {

              generate_polygon(controller.star_pikes, radius, cv::Point(controller.mouse_draw_x1, controller.mouse_draw_y1), star, false, true, controller.star_offset + controller.draw_offset ) ;

              join_stroke = false ;

            }

            draw_polylines(frame, star, join_stroke, fill, color, ((draw_thickness < 0) ? 0 : draw_thickness), draw_line_type) ;


         }



        // We register current frame in vector<cv::Mat> for undo-redo.
        controller.process_after_applying(frame) ;

        // It convert current_image_to_process as src to RGB(A) in dst current_image_to_display.
        set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

        frame.release() ;

        controller.saved_frame.release() ;
       
        controller.draw_offset = 0.0 ;

        controller.mouse_curser_changed = -1 ;

        return ;

      }

    }


  }

  return ;

}


bool GUI::on_property_notify_event_handler(GdkEventProperty *event, Controller &controller) {

  if ( widget_current_image_to_display != NULL && display_area_size_changed ) {

    // Updating current image sizes and positions values.
    controller.get_current_image_position() ;

    // Size change set.
    display_area_size_changed = false ;

    if ( controller.get_image_size_gt_layout() || controller.get_image_lt_layout() ) { // Image greater than display new surface or littler (when maximize per example).

      // Then we must build a new output image because it must be resize.
      set_img(controller.current_image_to_process, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

      return true ;
    }

    // Set image at right position.
    display_area.move(*widget_current_image_to_display, controller.current_image_position.first, controller.current_image_position.second) ;

    return true ;
  }

  return false ;

}

bool GUI::on_window_state_event_handler(GdkEventWindowState *event, Controller &controller) {


  if ( widget_current_image_to_display != NULL && display_area_size_changed) {

    // Updating current image sizes and positions values.
    controller.get_current_image_position() ;

    // Size change set.
    display_area_size_changed = false ;



    if ( controller.get_image_size_gt_layout() || controller.get_image_lt_layout() ) { // Image greater than display new surface or littler (when maximize per example).

      // Then we must build a new output image because it must be resize.
      set_img(controller.current_image_to_process, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).
      return false ;
    }

    // Set image at right position.
    display_area.move(*widget_current_image_to_display, controller.current_image_position.first, controller.current_image_position.second) ;

    return true ;

  }

  return false ;
}



bool GUI::mouse_motion_event_handler(GdkEventMotion *event, Controller &controller) {

  auto mouse_x = static_cast<long int>( round(event->x) ) ;
  auto mouse_y = static_cast<long int>( round(event->y) ) ;

  if ( button_zoom_pointer.get_active() || button_draw_rect.get_active() || button_draw_line.get_active() || button_draw_circle.get_active() || button_draw_ellipse.get_active() || button_draw_polygon.get_active() || button_draw_star.get_active() || button_draw_text.get_active() ) {

      if ( ( mouse_x >= controller.current_image_position.first  &&
             mouse_x < (controller.current_image_position.first  + controller.display_image_size.first)  ) &&

           ( mouse_y >= controller.current_image_position.second &&
             mouse_y < (controller.current_image_position.second + controller.display_image_size.second) ) &&

             controller.image_file_loaded   ) {

        // This members are not necessary: you can mulitply their values per the factor what's actually their only purpose...
        controller.mouse_inside_image_x = static_cast<int>(mouse_x) - controller.current_image_position.first  ;
        controller.mouse_inside_image_y = static_cast<int>(mouse_y) - controller.current_image_position.second ;


        if (controller.drawning_status == 0) { // In relationship to the draw form (here a rectangle).

          cv::Scalar color(draw_color.get_blue_u() >> 8 , draw_color.get_green_u() >> 8 , draw_color.get_red_u() >> 8 , draw_color.get_alpha_u() >> 8 ) ;

          // Getting the drawning coordinates onto the real (not resized) image by multiplying per factors:
          controller.mouse_draw_x2 =  static_cast<float>(controller.mouse_inside_image_x) *  controller.factor_width   ;
          controller.mouse_draw_y2 =  static_cast<float>(controller.mouse_inside_image_y) *  controller.factor_height   ;

          cv::Mat tmp_frame = controller.saved_frame.clone() ;


      
          if (button_draw_rect.get_active()) {

            cv::Rect rect( cv::Point(controller.mouse_draw_x1, controller.mouse_draw_y1), cv::Point(controller.mouse_draw_x2, controller.mouse_draw_y2) ) ;

            draw_rect(tmp_frame, rect, color, draw_thickness, draw_line_type) ;

          }
          else if ( button_draw_circle.get_active() ) {

            const int radius = static_cast<int>( sqrtf(roundf(powf(static_cast<float>(controller.mouse_draw_x2)-static_cast<float>(controller.mouse_draw_x1), 2) + powf(static_cast<float>(controller.mouse_draw_y2)-static_cast<float>(controller.mouse_draw_y1), 2))) ) ;

            draw_line(tmp_frame, cv::Point(controller.mouse_draw_x1, controller.mouse_draw_y1),   cv::Point(controller.mouse_draw_x2, controller.mouse_draw_y2),   color, ((draw_thickness-1 > 0) ? draw_thickness-1 : 1), draw_line_type) ;

            draw_circle(tmp_frame, cv::Point(controller.mouse_draw_x1, controller.mouse_draw_y1), radius, color, draw_thickness, draw_line_type) ;

          }
          else if ( button_draw_ellipse.get_active()  ) {

            const int distance_x = abs(controller.mouse_draw_x1-controller.mouse_draw_x2) ;
            const int distance_y = abs(controller.mouse_draw_y1-controller.mouse_draw_y2) ;

            const cv::RotatedRect rot_rect(cv::Point2f(static_cast<float>(controller.mouse_draw_x1), static_cast<float>(controller.mouse_draw_y1) ), cv::Size(abs( distance_x * 2 ), abs( distance_y * 2 ) ), 0.0  ) ;

            draw_ellipse(tmp_frame, rot_rect, color, draw_thickness, draw_line_type) ;

          }
          else if ( button_draw_polygon.get_active() && controller.config_draw_success == Gtk::RESPONSE_OK ) {

            const double radius = round(sqrt(pow(static_cast<double>(controller.mouse_draw_x2)-static_cast<double>(controller.mouse_draw_x1), 2) + pow(static_cast<double>(controller.mouse_draw_y2)-static_cast<double>(controller.mouse_draw_y1), 2)) ) ;

            double offset_correct = 0.0 ;

            vector<cv::Point> polygon ;

            bool fill = false ;

            if ((controller.polygon_edges > 4) && (controller.polygon_edges % 2 == 1)) {
              offset_correct = 360.0 / controller.polygon_edges / 2.0 / 2.0  ;
            }

            if ( ! controller.polygon_strikethrough && draw_thickness < 0 ) { fill = true ; }

            generate_polygon(controller.polygon_edges, radius, cv::Point(controller.mouse_draw_x1, controller.mouse_draw_y1),  polygon, controller.polygon_strikethrough, false,  controller.polygon_offset + controller.draw_offset + offset_correct) ;

            draw_polylines(tmp_frame, polygon, true, fill, color, ((draw_thickness < 0) ? 0 : draw_thickness), draw_line_type) ;

          }
          else if (button_draw_star.get_active() && controller.config_draw_success == Gtk::RESPONSE_OK ) {

            const double radius = round(sqrt(pow(static_cast<double>(controller.mouse_draw_x2)-static_cast<double>(controller.mouse_draw_x1), 2) + pow(static_cast<double>(controller.mouse_draw_y2)-static_cast<double>(controller.mouse_draw_y1), 2)) ) ;

            vector<cv::Point> star ;

            bool join_stroke = true ;

            bool fill = false ;

            if ( controller.star_correcting && (! controller.star_strokes) && (controller.star_pikes == 5 ||  controller.star_pikes == 6) ) {

              if ( ! controller.star_flower && ! controller.star_strikethrough && draw_thickness < 0 ) { fill = true ; }

              switch (controller.star_pikes) {

                case 5 :

                  generate_pentagram(radius, cv::Point(controller.mouse_draw_x1, controller.mouse_draw_y1), star, controller.star_strikethrough, controller.star_flower, (360.0 / 5.0 / 2.0 / 2.0) + controller.draw_offset + controller.star_offset) ;
                  break ;

                case 6 :

                  generate_hexagram(radius, cv::Point(controller.mouse_draw_x1, controller.mouse_draw_y1), star, controller.star_strikethrough, controller.star_flower, controller.star_offset + controller.draw_offset ) ;
                  break ;
 
              }
            }
            else if ( ! controller.star_strokes)  {

              if ( ! controller.star_flower && ! controller.star_strikethrough &&  ! controller.star_strokes && draw_thickness < 0 ) { fill = true ; }

              generate_star(controller.star_pikes , radius , cv::Point(controller.mouse_draw_x1, controller.mouse_draw_y1), star, controller.star_strikethrough, controller.star_flower, controller.star_offset + controller.draw_offset + ((controller.star_pikes == 5) ? (360.0 / 5.0 / 2.0 / 2.0) : 0) ) ;

            }
            else {
        
              generate_polygon(controller.star_pikes, radius, cv::Point(controller.mouse_draw_x1, controller.mouse_draw_y1), star, false, true, controller.star_offset + controller.draw_offset ) ;

              join_stroke = false ;

            }

            draw_polylines(tmp_frame, star, join_stroke, fill, color, ((draw_thickness < 0) ? 0 : draw_thickness), draw_line_type) ;
          }

          // It convert current_image_to_process as src to RGB(A) in dst current_image_to_display.
          set_img(tmp_frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

          //tmp_frame.release() ;

          usleep(1000) ;

        }
        else if ( (controller.drawning_status == -1) || (controller.drawning_status == 1) ) {

          if ( button_draw_text.get_active() && controller.config_draw_success == Gtk::RESPONSE_OK && (! controller.put_text_string.empty()) ) {

            cv::Scalar color(draw_color.get_blue_u() >> 8 , draw_color.get_green_u() >> 8 , draw_color.get_red_u() >> 8 , draw_color.get_alpha_u() >> 8 ) ;

            controller.saved_frame = controller.current_image_to_process.clone() ;

            // Getting the drawning coordinates onto the real (not resized) image by multiplying per factors:
            controller.mouse_draw_x2 =  static_cast<float>(controller.mouse_inside_image_x) *  controller.factor_width   ;
            controller.mouse_draw_y2 =  static_cast<float>(controller.mouse_inside_image_y) *  controller.factor_height   ;



            cv::Mat tmp_frame = controller.saved_frame.clone() ;

            int italic_flags = (controller.put_text_is_italic) ? cv::FONT_ITALIC : 0 ;

            draw_text(tmp_frame, controller.put_text_string, cv::Point(controller.mouse_draw_x2, controller.mouse_draw_y2), controller.put_text_font_face | italic_flags, controller.put_text_font_scale, color, ((draw_thickness < 0) ? 0 : draw_thickness), draw_line_type) ;

            // It convert current_image_to_process as src to RGB(A) in dst current_image_to_display.
            set_img(tmp_frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

            usleep(1000) ;

          }



        }


        if (controller.mouse_curser_changed <= 0 ) { // To set in relationship to activate functionnality

          main_window_gdk_window->set_cursor(mouse_cursor_set_center) ;

          controller.mouse_curser_changed = 1 ;

        }

        controller.mouse_into_image = true ;


      }
      else {


        controller.mouse_curser_changed = 0 ;

        main_window_gdk_window->set_cursor(mouse_cursor_set_activate) ;

        controller.mouse_into_image = false ;

      }

  }
  else if (main_window_gdk_window->get_cursor() != mouse_cursor_default) {

    main_window_gdk_window->set_cursor() ;

    controller.mouse_curser_changed = -1 ;

  }

  if ( ( mouse_x >= controller.current_image_position.first  &&
         mouse_x < (controller.current_image_position.first  + controller.display_image_size.first)  ) &&

       ( mouse_y >= controller.current_image_position.second &&
         mouse_y < (controller.current_image_position.second + controller.display_image_size.second) ) )  {

        string label_text(" Coordinates: ") ;

        string str_width(to_string(controller.source_image_size.first)) ;

        string str_height(to_string(controller.source_image_size.second)) ;

        string cur_pos_width  = to_string(static_cast<int>(mouse_x) - controller.current_image_position.first) ;

        string cur_pos_height = to_string(static_cast<int>(mouse_y) - controller.current_image_position.second) ;

        string zero_padding_width(str_width.length()-cur_pos_width.length(),  '0') ;

        string zero_padding_height(str_width.length()-cur_pos_height.length(), '0') ;

        string str_pos_x = zero_padding_width  + cur_pos_width  ;

        string str_pos_y = zero_padding_height + cur_pos_height ;

        label_text += str_pos_x ;

        label_text += "," ;

        label_text += str_pos_y ;

        label_text += "  ;" ;

        set_label_value(get_label(0), label_text ) ;

  }
  else {

    set_label_coords_value_on_null(controller) ;

  }

  return false ; //return false to continue propagate signal.
}


bool GUI::mouse_motion_event_handler_update_offset(Controller &controller) {

  if ( button_zoom_pointer.get_active() || button_draw_rect.get_active() || button_draw_line.get_active() || button_draw_circle.get_active() || button_draw_ellipse.get_active() || button_draw_polygon.get_active() || button_draw_star.get_active() || button_draw_text.get_active() ) {

      if ( controller.image_file_loaded   ) {


        if (controller.drawning_status == 0) {

          cv::Scalar color(draw_color.get_blue_u() >> 8 , draw_color.get_green_u() >> 8 , draw_color.get_red_u() >> 8 , draw_color.get_alpha_u() >> 8 ) ;

          cv::Mat tmp_frame = controller.saved_frame.clone() ;
   
          if ( button_draw_polygon.get_active() && controller.config_draw_success == Gtk::RESPONSE_OK ) {

            const double radius = round(sqrt(pow(static_cast<double>(controller.mouse_draw_x2)-static_cast<double>(controller.mouse_draw_x1), 2) + pow(static_cast<double>(controller.mouse_draw_y2)-static_cast<double>(controller.mouse_draw_y1), 2)) ) ;

            double offset_correct = 0.0 ;

            vector<cv::Point> polygon ;

            bool fill = false ;

            if ((controller.polygon_edges > 4) && (controller.polygon_edges % 2 == 1)) {
              offset_correct = 360.0 / controller.polygon_edges / 2.0 / 2.0  ;
            }

            if ( ! controller.polygon_strikethrough && draw_thickness < 0 ) { fill = true ; }

            generate_polygon(controller.polygon_edges, radius, cv::Point(controller.mouse_draw_x1, controller.mouse_draw_y1),  polygon, controller.polygon_strikethrough, false,  controller.polygon_offset + controller.draw_offset + offset_correct) ;

            draw_polylines(tmp_frame, polygon, true, fill, color, ((draw_thickness < 0) ? 0 : draw_thickness), draw_line_type) ;

          }
          else if (button_draw_star.get_active() && controller.config_draw_success == Gtk::RESPONSE_OK ) {

            const double radius = round(sqrt(pow(static_cast<double>(controller.mouse_draw_x2)-static_cast<double>(controller.mouse_draw_x1), 2) + pow(static_cast<double>(controller.mouse_draw_y2)-static_cast<double>(controller.mouse_draw_y1), 2)) ) ;

            vector<cv::Point> star ;

            bool join_stroke = true ;

            bool fill = false ;

            if ( controller.star_correcting && (! controller.star_strokes) && (controller.star_pikes == 5 ||  controller.star_pikes == 6) ) {

              if ( ! controller.star_flower && ! controller.star_strikethrough && draw_thickness < 0 ) { fill = true ; }

              switch (controller.star_pikes) {

                case 5 :

                  generate_pentagram(radius, cv::Point(controller.mouse_draw_x1, controller.mouse_draw_y1), star, controller.star_strikethrough, controller.star_flower, (360.0 / 5.0 / 2.0 / 2.0) + controller.star_offset + controller.draw_offset ) ;
                  break ;

                case 6 :

                  generate_hexagram(radius, cv::Point(controller.mouse_draw_x1, controller.mouse_draw_y1), star, controller.star_strikethrough, controller.star_flower, controller.star_offset + controller.draw_offset ) ;
                  break ;
 
              }
            }
            else if ( ! controller.star_strokes)  {

              if ( ! controller.star_flower && ! controller.star_strikethrough &&  ! controller.star_strokes && draw_thickness < 0 ) { fill = true ; }

              generate_star(controller.star_pikes , radius , cv::Point(controller.mouse_draw_x1, controller.mouse_draw_y1), star, controller.star_strikethrough, controller.star_flower, controller.draw_offset + controller.star_offset + ((controller.star_pikes == 5) ? (360.0 / 5.0 / 2.0 / 2.0) : 0) ) ;

            }
            else {
        
              generate_polygon(controller.star_pikes, radius, cv::Point(controller.mouse_draw_x1, controller.mouse_draw_y1), star, false, true, controller.star_offset + controller.draw_offset) ;

              join_stroke = false ;

            }

            draw_polylines(tmp_frame, star, join_stroke, fill, color, ((draw_thickness < 0) ? 0 : draw_thickness), draw_line_type) ;
      
          }

          // It convert current_image_to_process as src to RGB(A) in dst current_image_to_display.
          set_img(tmp_frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

          usleep(1000) ;

        }

      }

    }


  return false ; //return false to continue propagate signal.

}

#endif