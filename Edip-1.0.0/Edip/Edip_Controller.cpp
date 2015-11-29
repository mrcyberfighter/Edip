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

#include "Edip_Controller.hpp"

void Controller::process_after_applying(cv::Mat frame) {

  /** To call after aplying an effect.
    *
    * Add frame if given or the @current_image_to_process member to undo-redo vector.
    * After checking if their are some undo done in case it erase the unneded frame from the vector.
    *
    * Optional @arg: frame -> in case the current_image_to_process member is unsuable.
    *
    *************************************************************************************************/
 
  image_to_display_vector_idx++ ;  // We increment: in case of undo-redo vector erasing it's up-to-date.

  check_undo() ; // Check if undo and erase from the undo-redo vector.

  if (! frame.empty() ) {
    // frame argument given we process.
    image_to_display_vector.push_back(frame.clone()) ;  // Add the last image resulting of the operation.
    current_image_to_process = frame.clone() ;
  }
  else {
    image_to_display_vector.push_back(current_image_to_process.clone()) ;  // Add the last image resulting of the operation.
  }


}


void Controller::reset_settings() {

  /** Reset settings after load a new file. **/

  image_to_display_vector_idx = 0 ;

  has_undo = false ;

  is_image_size_gt_layout = false ;

  clear_undo_redo_frame_vector() ;

}

void Controller::reset_zoom_center(const cv::Mat frame) {

  /** Reset zoom center. **/

  mouse_zoom_center_x = static_cast<float>(frame.cols)  / 2.0f ;
  mouse_zoom_center_y = static_cast<float>(frame.rows)  / 2.0f ;

}

void Controller::get_current_image_position() {

  /** Update the image sizes (originally and resized (if needed)) and position related variables. **/

  if ( set_image_gt_layout(current_image_to_process) ) {

    set_sizes_controller_from_images(current_image_to_process) ;

  }
  else {
    
    // Setting sizes members:
    source_image_size.first   = current_image_to_process.cols ;
    source_image_size.second  = current_image_to_process.rows ;

    display_image_size.first  = current_image_to_process.cols ;
    display_image_size.second = current_image_to_process.rows ;

    factor_width  = 1.0f ;
    factor_height = 1.0f ;

  }

  auto container_size = get_layout_size() ;

  int container_center_x = static_cast<int>(roundf(static_cast<float>(container_size.first)  / 2.0f)) ;
  int container_center_y = static_cast<int>(roundf(static_cast<float>(container_size.second) / 2.0f)) ;

  current_image_position.first  = container_center_x-(display_image_size.first  / 2)  ;
  current_image_position.second = container_center_y-(display_image_size.second / 2)  ;

}

const bool Controller::get_image_lt_layout() const {
  /** Is image littler than displaying area ? **/

  auto container_size = get_layout_size() ;

  return (display_image_size.first <= container_size.first-20 && display_image_size.second <= container_size.second ) ;

}

void Controller::check_undo() {

  if (has_undo) {
  
    // An operation has been performed and after undoing operations, so we reset the unod-redo vector.
  
    if ( ! image_to_display_vector.empty() ) {
    
      /** Erase the unneded frames from the undo-redo vector. **/
    
      image_to_display_vector.erase(image_to_display_vector.begin() + image_to_display_vector_idx, image_to_display_vector.end() ) ;

      image_to_display_vector.shrink_to_fit() ;

      has_undo = false ;

    }

  }


}

void Controller::clear_undo_redo_frame_vector() {

  /** Clear undo-redo vector. **/

  if (image_to_display_vector.size() > 0UL) {

    try {

      image_to_display_vector.clear() ;
      image_to_display_vector.shrink_to_fit() ;
    }
    catch (...) {
      ;
    }
    
    image_to_display_vector_idx = 0      ;

    has_undo = false     ;

  }


}

void Controller::set_sizes_controller_from_images(cv::Mat &frame) {

  /** Resize image so that the displaying area can contains it. **/


  Resizer resize_frame ;

  auto container_size = get_layout_size() ;

  auto new_size = resize_frame.resizer(frame, container_size.first-20 , container_size.second-20, true) ;

  if (! resize_frame.assertion() ) {

   // Don't taken in account.

  }

  source_image_size.first   = frame.cols ;
  source_image_size.second  = frame.rows ;

  display_image_size.first  = new_size.first  ;
  display_image_size.second = new_size.second ;

  factor_width  = static_cast<float>(source_image_size.first)  / static_cast<float>(display_image_size.first) ;
  factor_height = static_cast<float>(source_image_size.second) / static_cast<float>(display_image_size.second) ;
}


const bool Controller::set_image_gt_layout(const cv::Mat frame) {

  /** Check if image is greater than displaying area. **/

  pair<int, int> size = get_layout_size() ;

  if (frame.cols > (size.first-20) || frame.rows > (size.second-20) ) {
    is_image_size_gt_layout = true ;
    return true ;
  }
  else {
    is_image_size_gt_layout = false ;
    return false ;
  }

}