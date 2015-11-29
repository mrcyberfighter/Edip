#ifndef EDIP_GUI_PROCESS_HH
#define EDIP_GUI_PROCESS_HH

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


/** Actions method providing an image processing action to the GUI. **/

void GUI::process_change_colorspace(Controller &controller, uint8_t selected_scale) {

  if ( ! controller.image_file_loaded   ) { return ; }

  long int value = static_cast<long int>(get_scale(selected_scale).get_value()) ;

  if (value == 0) {
    return ;
  }

  const float div = (selected_scale == 9) ? 2.0f : (selected_scale == 7) ? 1.0 : 16.0f ;

  const float factor = (1.0f / (255.0f / div )) * static_cast<double>(value) ;

  cv::Mat tmp = controller.current_image_to_process.clone() ;

  cv::Mat frame ;

  switch (selected_scale) {

    case 6 :

      // Lightness change ;
      change_lightness(tmp, frame, factor) ;
      break ;

    case 7 :

      // Hue change ;
      change_hue(tmp, frame, factor) ;
      break ;

    case 8 :

      // Saturation change ;
      change_saturation(tmp, frame, factor) ;
      break ;

    case 9 :

      // Brightness change ;
      change_brightness(tmp, frame, factor) ;
      break ;

    #ifdef DEBUG
    default :
      // This cannot append due of the GUI interfacing.
      fprintf(stderr,"Error Change HSBL settings\n") ;
      return ;
    #endif

  }

  // We register current frame in vector<cv::Mat> for undo-redo.
  controller.process_after_applying(frame) ;

  // It convert current_image_to_process as src to RGB(A) in dst current_image_to_display.
  set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).



  // Reset some variables.
  after_applying_reset_settings(controller) ;

}


void GUI::process_change_intensity(Controller &controller, uint8_t selected_scale) {

  if ( ! controller.image_file_loaded   ) { return ; }

  int64_t value = static_cast<int64_t>(get_scale(selected_scale).get_value()) ;

  bool add = true ;

  if (value == 0) { return ; }


  if (value < 0) {

    value  = -value ;
    add    =  false ;

  }

  cv::Mat tmp = controller.current_image_to_process.clone() ;

  cv::Mat frame ;

  switch (selected_scale) {

    case 1 :

      // Red intensity change ;
      change_intensity(tmp, frame, add, static_cast<int>(value), 0, 0 ) ;
      break ;

    case 2 :

      // Green intensity change ;
      change_intensity(tmp, frame, add, 0, static_cast<int>(value), 0 ) ;
      break ;

    case 3 :

      // Blue intensity change ;
      change_intensity(tmp, frame, add, 0, 0, static_cast<int>(value) ) ;
      break ;

    case 4 :

      // Global intensity change
      change_intensity(tmp, frame, add, static_cast<int>(value), static_cast<int>(value), static_cast<int>(value) ) ;
      break ;

    #ifdef DEBUG
    default :
      // This cannot append due of the GUI interfacing.
      fprintf(stderr,"Error intensity changing\n") ;
      return ;
    #endif
 
  }

   // We register current frame in vector<cv::Mat> for undo-redo.
  controller.process_after_applying(frame) ;

  // It convert current_image_to_process as src to RGB(A) in dst current_image_to_display.
  set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

  // Reset some variables.
  after_applying_reset_settings(controller) ;

}

void GUI::mirror(Controller &controller, char sens) {

  if ( ! controller.image_file_loaded   ) { return ; }

  switch (sens) {

    case 'l' :
      mirror_vertical_left(controller.current_image_to_process, controller.current_image_to_process) ;
      break ;

    case 'r' :
      mirror_vertical_right(controller.current_image_to_process, controller.current_image_to_process) ;
      break ;

    case 't' :
      mirror_horizontal_top(controller.current_image_to_process, controller.current_image_to_process) ;
      break ;

    case 'b' :
      mirror_horizontal_bottom(controller.current_image_to_process, controller.current_image_to_process) ;
      break ;

  }

  // We register current frame in vector<cv::Mat> for undo-redo.
  controller.process_after_applying() ;

  // It convert current_image_to_process as src to RGB(A) in dst current_image_to_display.
  set_img(controller.current_image_to_process, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

  // Reset some variables.
  after_applying_reset_settings(controller) ;

}


void GUI::flip(Controller &controller, char sens) {

  if ( ! controller.image_file_loaded   ) { return ; }

  static char flip_x_pos = ' ' ;
  static char flip_y_pos = ' ' ;

  switch (sens) {

    case 'l' :

      if (flip_x_pos != 'l') {
        flipping(controller.current_image_to_process, controller.current_image_to_process, -1) ;
        flip_x_pos = 'l' ;
      }

      break ;

    case 'r' :

      if ( flip_x_pos != ' ' && flip_x_pos != 'r' ) {
        flipping(controller.current_image_to_process, controller.current_image_to_process, -1) ;
        flip_x_pos = 'r' ;
      }

      break ;

    case 'u' :


      if (flip_y_pos != 'u') {
        flipping(controller.current_image_to_process, controller.current_image_to_process, 1) ;
        flip_y_pos = 'u' ;
      }

      break ;

    case 'd' :

      if ( flip_y_pos != ' ' && flip_y_pos != 'd') {
        flipping(controller.current_image_to_process, controller.current_image_to_process, 1) ;
        flip_y_pos='d' ;
      }

      break ;
  }

  // We register current frame in vector<cv::Mat> for undo-redo.
  controller.process_after_applying() ;

  // It convert current_image_to_process as src to RGB(A) in dst current_image_to_display.
  set_img(controller.current_image_to_process, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

  // Reset some variables.
  after_applying_reset_settings(controller) ;

}



void GUI::rotating(Controller &controller, bool sens) {

  if ( ! controller.image_file_loaded   ) { return ; }

  if (! sens)  {
    rotate_90_left(controller.current_image_to_process, controller.current_image_to_process) ;
  }
  else {
    rotate_90_right(controller.current_image_to_process, controller.current_image_to_process) ;
  }

  // We register current frame in vector<cv::Mat> for undo-redo.
  controller.process_after_applying() ;

  controller.get_current_image_position() ;

  // It convert current_image_to_process as src to RGB(A) in dst current_image_to_display.
  set_img(controller.current_image_to_process, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

  set_label_size_value(controller.source_image_size.first, controller.source_image_size.second) ;

  // Reset some variables.
  after_applying_reset_settings(controller) ;

}

void GUI::apply_filter(Controller &controller) {

  if ( ! controller.image_file_loaded   ) { return ; }


  bool is_alpha = controller.current_image_to_process.channels() == 4 ;

  Sharpen sharpen_filter(3, "diamond")      ;

  Sharpen sharpen_filter_more(3, "diamond") ;


  Find_Edges find_edges_filter(3) ;


  Mean mean_filter(3)      ;

  Mean mean_filter_more(5) ;


  cv::Mat kernel = make_kernel("rect", 3)  ;


  cv::Mat tmp = controller.current_image_to_process.clone() ;

  cv::Mat frame ;


  switch (combo_current_filter) {

    case 0 :
    
      // Pencil Sketch filter:
      pencil_sketch_filter(tmp, frame) ;
      break ;

    case 1 :
    
      // Stylisation filter.
      stylisation_filter(tmp, frame) ;
      break ;

    case 2 :
    
      // Detail Enhance filter.
      detail_enhance_filter(tmp, frame) ;
      break ;

    case 3 :
    
      // Edge Preserving filter.
      edge_preserving_filter(tmp, frame) ;
      break ;

    case 4 :

      // Stroke edges filter:
      stroke_edges(tmp, frame) ;
      break ;

    case 5 :

      // Invert Intensity filter:
      invert_intensity(tmp, frame) ;
      break ;

    case 6 :

      // Light Intensity filter:
      effect_light(tmp, frame) ;
      break ;

    case 7 :

      // Recolor-RC (Red-Cyan) filter:
      recolorRC(tmp, frame) ;
      break ;

    case 8 :

      // Recolor-RC (Red-Green-Value) filter:
      recolorRGV(tmp, frame) ;
      break ;

    case 9 :

      // Recolor-RC (Cyan-Magenta-Value) filter:
      recolorCMV(tmp, frame) ;
      break ;

    case 10 :

      // Extrema Maximal Filter:
      extrema(tmp, frame, "max") ;
      break ;

    case 11 :

      // Extrema Minimal Filter:
      extrema(tmp, frame, "min") ;
      break ;



    case 12 :

      // Sharpen filter:
      sharpen_filter.apply(tmp, frame)   ;
      break ;

    case 13 :

      // Sharpen More filter:
      sharpen_filter_more.apply(tmp, frame)   ;
      break ;

    case 14 :

      // Find Edges filter:

      if (is_alpha) {

        cv::Mat frame_rgb ;
        cv::Mat tmp_1     ;

        cvtColor(tmp, frame_rgb, cv::COLOR_BGRA2BGR) ;

        find_edges_filter.apply(frame_rgb, tmp_1)   ;

        vector<cv::Mat> tmp_2 ;
        vector<cv::Mat> tmp_3 ;

        cv::split(tmp,   tmp_2) ;
        cv::split(tmp_1, tmp_3) ;

        // Assign BGR channels.
        tmp_2[0] = tmp_3[0] ;
        tmp_2[1] = tmp_3[1] ;
        tmp_2[2] = tmp_3[2] ;

        // Final channels merging into result with alpha channel unchanged.
        cv::merge(tmp_2, frame) ;

        break ;


      }

      find_edges_filter.apply(tmp, frame)   ;
      break ;

    case 15 :

      // Mean Blur filter:
      mean_filter.apply(tmp, frame)   ;
      break ;

    case 16 :

      // Mean Blur More filter:
      mean_filter_more.apply(tmp, frame)   ;
      break ;


    case 17 :

      // Blur filter:
      blur_filter(tmp, frame) ;
      break ;

    case 18 :

      // Median Blur filter:
      median_blur_filter(tmp, frame) ;
      break ;

    case 19 :

      // Gaussian Blur filter:
      gaussian_blur_filter(tmp, frame) ;
      break ;

    case 20 :

      denoising_filter(tmp, frame) ;
      break ;

    case 21 :

      // Erode filter:
      erode_filter(tmp, frame, kernel, 1)   ;
      break ;

    case 22 :

      // Dilate filter:
      dilate_filter(tmp, frame, kernel, 1)   ;
      break ;

    case 23 :

      // Wave Horizontally filter:
      wave(tmp, frame, -1) ;
      break ;

    case 24 :

      // Wave Vertically filter:
      wave(tmp, frame,  1) ;
      break ;

    case 25 :

      // Wave Twice (Horizontally and Vertically) filter:
      wave(tmp, frame,  0) ;
      break ;

    case 26 :

      // Contours Sobel White filter.
      sobel_drawning(tmp, frame, 3, false, 1) ;
      break ;

    case 27 :

      // Contours Sobel Black filter.
      sobel_drawning(tmp, frame, 3, false, -1) ;
      break ;

    case 28 :

      // Contours Sobel Emboss filter.
      sobel_drawning(tmp, frame, 3, false, 0) ;
      break ;

    case 29 :

      // Emboss Sobel filter:
      sobel_emboss(tmp, frame, 3) ;
      break ;

    case 30 :

      // Emboss Laplacian filter:
      laplacian_emboss(tmp, frame, 3) ;
      break ;


    case 31 :

      // Binary White OTSU filter:
      // Build a binary image (a black and white only image) with white background (@arg value true)
      // based on the OTSU threshold computing algorithm (@arg value -1).
      build_binary_image(tmp, frame, -1, true) ;
      break ;

    case 32 :

      // Binary White TRIANGLE filter:
      // Build a binary image (a black and white only image) with white background (@arg value true)
      // based on the TRIANGLE threshold computing algorithm (@arg value 1).
      build_binary_image(tmp, frame,  1, true) ;
      break ;

    case 33 :

      // Binary White AVERAGE filter:
      // Build a binary image (a black and white only image) with white background (@arg value true)
      // based on the AVERAGE threshold from OTSU and TRIANGLE (@arg value 0).
      build_binary_image(tmp, frame,  0, true) ;
      break ;

    case 34 :

      // Binary Black OTSU filter:
      // Build a binary image (a black and white only image) with black background (@arg value true)
      // based on the OTSU threshold computing algorithm (@arg value -1).
      build_binary_image(tmp, frame, -1, false) ;
      break ;

    case 35 :

      // Binary Black TRIANGLE filter:
      // Build a binary image (a black and white only image) with black background (@arg value true)
      // based on the TRIANGLE threshold computing algorithm (@arg value 1).
      build_binary_image(tmp, frame,  1, false) ;
      break ;

    case 36 :

      // Binary Black AVERAGE filter:
      // Build a binary image (a black and white only image) with black background (@arg value true)
      // based on the AVERAGE threshold from OTSU and TRIANGLE (@arg value 0).
      build_binary_image(tmp, frame,  0, false) ;
      break ;

    case 37 :

      // Binary Contours White filter:
      // Build a binary image (a black and white only image) with contours detction on white background (@arg value false).
      laplacian_zero_crossing(tmp, frame, 19, false)  ;
      break ;

    case 38 :

      // Binary Contours Black filter:
      // Build a binary image (a black and white only image) with contours detction on black background (@arg value true).
      laplacian_zero_crossing(tmp, frame, 19, true)  ;
      break ;







    #ifdef DEBUG
    default :
      // Cannot append due of the GUI interfacing.
      fprintf(stdout,"Error applying filter !!!\n") ;
      return ;
    #endif
  }


  // We register current frame in vector<cv::Mat> for undo-redo.
  controller.process_after_applying(frame) ;

  // It convert current_image_to_process as src to RGB(A) in dst current_image_to_display.
  set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

  // Reset some variables.
  after_applying_reset_settings(controller) ;

}

void GUI::apply_filter_from_menu(Controller &controller, Gtk::ImageMenuItem &imagemenuitem) {

  if ( ! controller.image_file_loaded   ) { return ; }


  bool is_alpha = controller.current_image_to_process.channels() == 4 ;

  Sharpen sharpen_filter(3, "diamond")      ;

  Sharpen sharpen_filter_more(3, "diamond") ;


  Find_Edges find_edges_filter(3) ;


  Mean mean_filter(3)      ;

  Mean mean_filter_more(5) ;


  cv::Mat kernel = make_kernel("rect", 3)  ;


  cv::Mat tmp = controller.current_image_to_process.clone() ;

  cv::Mat frame ;

  switch ( stoi(imagemenuitem.get_name()) ) {

    case 0 :
      
      // Pencil Sketch filter.
      pencil_sketch_filter(tmp, frame) ;
      break ;

    case 1 :
    
      // Stylisation filter.
      stylisation_filter(tmp, frame) ;
      break ;

    case 2 :
    
      // Detail Enhance filter.
      detail_enhance_filter(tmp, frame) ;
      break ;

    case 3 :
     
      // Edge Preserving filter.
      edge_preserving_filter(tmp, frame) ;
      break ;

    case 4 :

      // Stroke edges filter:
      stroke_edges(tmp, frame) ;
      break ;

    case 5 :

      // Invert Intensity filter:
      invert_intensity(tmp, frame) ;
      break ;

    case 6 :

      // Light Intensity filter:
      effect_light(tmp, frame) ;
      break ;

    case 7 :

      // Recolor-RC (Red-Cyan) filter:
      recolorRC(tmp, frame) ;
      break ;

    case 8 :

      // Recolor-RC (Red-Green-Value) filter:
      recolorRGV(tmp, frame) ;
      break ;

    case 9 :

      // Recolor-RC (Cyan-Magenta-Value) filter:
      recolorCMV(tmp, frame) ;
      break ;

    case 10 :

      // Extrema Maximal Filter:
      extrema(tmp, frame, "max") ;
      break ;

    case 11 :

      // Extrema Minimal Filter:
      extrema(tmp, frame, "min") ;
      break ;



    case 12 :

      // Sharpen filter:
      sharpen_filter.apply(tmp, frame)   ;
      break ;

    case 13 :

      // Sharpen More filter:
      sharpen_filter_more.apply(tmp, frame)   ;
      break ;

    case 14 :

      // Find Edges filter:

      if (is_alpha) {

        cv::Mat frame_rgb ;
        cv::Mat tmp_1     ;

        cvtColor(tmp, frame_rgb, cv::COLOR_BGRA2BGR) ;

        find_edges_filter.apply(frame_rgb, tmp_1)   ;

        vector<cv::Mat> tmp_2 ;
        vector<cv::Mat> tmp_3 ;

        cv::split(tmp,   tmp_2) ;
        cv::split(tmp_1, tmp_3) ;

        // Assign BGR channels.
        tmp_2[0] = tmp_3[0] ;
        tmp_2[1] = tmp_3[1] ;
        tmp_2[2] = tmp_3[2] ;

        // Final channels merging into result with alpha channel unchanged.
        cv::merge(tmp_2, frame) ;

        break ;


      }

      find_edges_filter.apply(tmp, frame)   ;
      break ;

    case 15 :

      // Mean Blur filter:
      mean_filter.apply(tmp, frame)   ;
      break ;

    case 16 :

      // Mean Blur More filter:
      mean_filter_more.apply(tmp, frame)   ;
      break ;


    case 17 :

      // Blur filter:
      blur_filter(tmp, frame) ;
      break ;

    case 18 :

      // Median Blur filter:
      median_blur_filter(tmp, frame) ;
      break ;

    case 19 :

      // Gaussian Blur filter:
      gaussian_blur_filter(tmp, frame) ;
      break ;

    case 20 :

      denoising_filter(tmp, frame) ;
      break ;

    case 21 :

      // Erode filter:
      erode_filter(tmp, frame, kernel, 1)   ;
      break ;

    case 22 :

      // Dilate filter:
      dilate_filter(tmp, frame, kernel, 1)   ;
      break ;

    case 23 :

      // Wave Horizontally filter:
      wave(tmp, frame, -1) ;
      break ;

    case 24 :

      // Wave Vertically filter:
      wave(tmp, frame,  1) ;
      break ;

    case 25 :

      // Wave Twice (Horizontally and Vertically) filter:
      wave(tmp, frame,  0) ;
      break ;

    case 26 :

      // Contours Sobel White filter.
      sobel_drawning(tmp, frame, 3, false, 1) ;
      break ;

    case 27 :

      // Contours Sobel Black filter.
      sobel_drawning(tmp, frame, 3, false, -1) ;
      break ;

    case 28 :

      // Contours Sobel Emboss filter.
      sobel_drawning(tmp, frame, 3, false, 0) ;
      break ;

    case 29 :

      // Emboss Sobel filter:
      sobel_emboss(tmp, frame, 3) ;
      break ;

    case 30 :

      // Emboss Laplacian filter:
      laplacian_emboss(tmp, frame, 3) ;
      break ;


    case 31 :

      // Binary White OTSU filter:
      // Build a binary image (a black and white only image) with white background (@arg value true)
      // based on the OTSU threshold computing algorithm (@arg value -1).
      build_binary_image(tmp, frame, -1, true) ;
      break ;

    case 32 :

      // Binary White TRIANGLE filter:
      // Build a binary image (a black and white only image) with white background (@arg value true)
      // based on the TRIANGLE threshold computing algorithm (@arg value 1).
      build_binary_image(tmp, frame,  1, true) ;
      break ;

    case 33 :

      // Binary White AVERAGE filter:
      // Build a binary image (a black and white only image) with white background (@arg value true)
      // based on the AVERAGE threshold from OTSU and TRIANGLE (@arg value 0).
      build_binary_image(tmp, frame,  0, true) ;
      break ;

    case 34 :

      // Binary Black OTSU filter:
      // Build a binary image (a black and white only image) with black background (@arg value true)
      // based on the OTSU threshold computing algorithm (@arg value -1).
      build_binary_image(tmp, frame, -1, false) ;
      break ;

    case 35 :

      // Binary Black TRIANGLE filter:
      // Build a binary image (a black and white only image) with black background (@arg value true)
      // based on the TRIANGLE threshold computing algorithm (@arg value 1).
      build_binary_image(tmp, frame,  1, false) ;
      break ;

    case 36 :

      // Binary Black AVERAGE filter:
      // Build a binary image (a black and white only image) with black background (@arg value true)
      // based on the AVERAGE threshold from OTSU and TRIANGLE (@arg value 0).
      build_binary_image(tmp, frame,  0, false) ;
      break ;

    case 37 :

      // Binary Contours White filter:
      // Build a binary image (a black and white only image) with contours detction on white background (@arg value false).
      laplacian_zero_crossing(tmp, frame, 19, false)  ;
      break ;

    case 38 :

      // Binary Contours Black filter:
      // Build a binary image (a black and white only image) with contours detction on black background (@arg value true).
      laplacian_zero_crossing(tmp, frame, 19, true)  ;
      break ;







    #ifdef DEBUG
    default :
      // Cannot append due of the GUI interfacing.
      fprintf(stdout,"Error applying filter !!!\n") ;
      return ;
    #endif

  }

  // We register current frame in vector<cv::Mat> for undo-redo.
  controller.process_after_applying(frame) ;

  // It convert current_image_to_process as src to RGB(A) in dst current_image_to_display.
  set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

  // Reset some variables.
  after_applying_reset_settings(controller) ;

}



void GUI::apply_grayscale(Controller &controller) {

  if ( ! controller.image_file_loaded   ) { return ; }

  // Transform image into a grayscale image according choosen settings:

  switch (combo_current_grayscaling) {

    case 0 :

      grayscale(controller.current_image_to_process, controller.current_image_to_process, "average") ;
      break ;

    case 1 :

      grayscale(controller.current_image_to_process, controller.current_image_to_process, "max")     ;
      break ;

    case 2 :

      grayscale(controller.current_image_to_process, controller.current_image_to_process, "min")     ;
      break ;

    case 3 :

      grayscale(controller.current_image_to_process, controller.current_image_to_process, "red")     ;
      break ;

    case 4 :

      grayscale(controller.current_image_to_process, controller.current_image_to_process, "green")    ;
      break ;

    case 5 :

      grayscale(controller.current_image_to_process, controller.current_image_to_process, "blue")     ;
      break ;


    #ifdef DEBUG
    default :
      // Cannot append due of the GUI interfacing.
      fprintf(stdout,"Error applying grayscale filter !!!\n") ;
      return ;
   #endif

  }

  // We register current frame in vector<cv::Mat> for undo-redo.
  controller.process_after_applying() ;

  // It convert current_image_to_process as src to RGB(A) in dst current_image_to_display.
  set_img(controller.current_image_to_process, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

  // Reset some variables.
  after_applying_reset_settings(controller) ;

}

void GUI::apply_grayscale_from_menu(Controller &controller, Gtk::ImageMenuItem &imagemenuitem) {

  if ( ! controller.image_file_loaded   ) { return ; }

  // Transform image into a grayscale image according choosen settings:

  switch ( stoi(imagemenuitem.get_name()) ) {

    case 0 :

      grayscale(controller.current_image_to_process, controller.current_image_to_process, "average") ;
      break ;

    case 1 :

      grayscale(controller.current_image_to_process, controller.current_image_to_process, "max")     ;
      break ;

    case 2 :

      grayscale(controller.current_image_to_process, controller.current_image_to_process, "min")     ;
      break ;

    case 3 :

      grayscale(controller.current_image_to_process, controller.current_image_to_process, "red")     ;
      break ;

    case 4 :

      grayscale(controller.current_image_to_process, controller.current_image_to_process, "green")    ;
      break ;

    case 5 :

      grayscale(controller.current_image_to_process, controller.current_image_to_process, "blue")     ;
      break ;

    #ifdef DEBUG
    default :
      // Cannot append due of the GUI interfacing.
      fprintf(stdout,"Error applying grayscale filter !!!\n") ;
      return ;
    #endif
 
  }

  // We register current frame in vector<cv::Mat> for undo-redo.
  controller.process_after_applying() ;

  // It convert current_image_to_process as src to RGB(A) in dst current_image_to_display.
  set_img(controller.current_image_to_process, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

  // Reset some variables.
  after_applying_reset_settings(controller) ;

}

void GUI::apply_colorscale(Controller &controller) {

  if ( ! controller.image_file_loaded   ) { return ; }

  cv::Mat tmp = controller.current_image_to_process.clone() ;

  cv::Mat frame ;


  // Apply a colorscale on the image according choosen settings:

  switch (combo_current_colorscaling) {

    case 0 :

      colorscale(tmp, frame, "red", "average") ;
      break ;

    case 1 :

      colorscale(tmp, frame, "red", "max") ;
      break ;

    case 2 :

      colorscale(tmp, frame, "red", "min") ;
      break ;

    case 3 :

      colorscale(tmp, frame, "red", "red") ;
      break ;

    case 4 :

      colorscale(tmp, frame, "red", "green") ;
      break ;


    case 5 :

      colorscale(tmp, frame, "green", "average") ;
      break ;

    case 6 :

      colorscale(tmp, frame, "green", "max") ;
      break ;

    case 7 :

      colorscale(tmp, frame, "green", "min") ;
      break ;

    case 8 :

      colorscale(tmp, frame, "green", "red") ;
      break ;


    case 9 :

      colorscale(tmp, frame, "green", "blue") ;
      break ;


    case 10 :

      colorscale(tmp, frame, "blue", "average") ;
      break ;

    case 11 :

      colorscale(tmp, frame, "blue", "max") ;
      break ;

    case 12 :

      colorscale(tmp, frame, "blue", "min") ;
      break ;

    case 13 :

      colorscale(tmp, frame, "blue", "red") ;
      break ;

    case 14 :

      colorscale(tmp, frame, "blue", "green") ;
      break ;



    case 15 :

      colorscale(tmp, frame, "yellow", "average") ;
      break ;

    case 16 :

      colorscale(tmp, frame, "yellow", "max") ;
      break ;

    case 17 :

      colorscale(tmp, frame, "yellow", "min") ;
      break ;

    case 18 :

      colorscale(tmp, frame, "yellow", "red") ;
      break ;

    case 19 :

      colorscale(tmp, frame, "yellow", "green") ;
      break ;

    case 20 :

      colorscale(tmp, frame, "yellow", "blue") ;
      break ;


    case 21 :

      colorscale(tmp, frame, "pink", "average") ;
      break ;

    case 22 :

      colorscale(tmp, frame, "pink", "max") ;
      break ;

    case 23 :

      colorscale(tmp, frame, "pink", "min") ;
      break ;

    case 24 :

      colorscale(tmp, frame, "pink", "red") ;
      break ;

    case 25 :

      colorscale(tmp, frame, "pink", "green") ;
      break ;

    case 26 :

      colorscale(tmp, frame, "pink", "blue") ;
      break ;


    case 27 :

      colorscale(tmp, frame, "turquoise", "average") ;
      break ;

    case 28 :

      colorscale(tmp, frame, "turquoise", "max") ;
      break ;

    case 29 :

      colorscale(tmp, frame, "turquoise", "min") ;
      break ;

    case 30 :

      colorscale(tmp, frame, "turquoise", "red") ;
      break ;

    case 31 :

      colorscale(tmp, frame, "turquoise", "green") ;
      break ;

    case 32 :

      colorscale(tmp, frame, "turquoise", "blue") ;
      break ;

    #ifdef DEBUG
    default :
      // Cannot append due of the GUI interfacing.
      fprintf(stdout,"Error applying grayscale filter !!!\n") ;
      return ;
    #endif

  }

  // We register current frame in vector<cv::Mat> for undo-redo.
  controller.process_after_applying(frame) ;

  // It convert current_image_to_process as src to RGB(A) in dst current_image_to_display.
  set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

  // Reset some variables.
  after_applying_reset_settings(controller) ;

}


void GUI::apply_colorscale_from_menu(Controller &controller, Gtk::ImageMenuItem &imagemenuitem) {

  if ( ! controller.image_file_loaded   ) { return ; }

  cv::Mat tmp = controller.current_image_to_process.clone() ;

  cv::Mat frame ;


  // Apply a colorscale on the image according choosen settings:

  switch ( stoi(imagemenuitem.get_name()) ) {

    case 0 :

      colorscale(tmp, frame, "red", "average") ;
      break ;

    case 1 :

      colorscale(tmp, frame, "red", "max") ;
      break ;

    case 2 :

      colorscale(tmp, frame, "red", "min") ;
      break ;

    case 3 :

      colorscale(tmp, frame, "red", "red") ;
      break ;

    case 4 :

      colorscale(tmp, frame, "red", "green") ;
      break ;


    case 5 :

      colorscale(tmp, frame, "green", "average") ;
      break ;

    case 6 :

      colorscale(tmp, frame, "green", "max") ;
      break ;

    case 7 :

      colorscale(tmp, frame, "green", "min") ;
      break ;

    case 8 :

      colorscale(tmp, frame, "green", "red") ;
      break ;


    case 9 :

      colorscale(tmp, frame, "green", "blue") ;
      break ;


    case 10 :

      colorscale(tmp, frame, "blue", "average") ;
      break ;

    case 11 :

      colorscale(tmp, frame, "blue", "max") ;
      break ;

    case 12 :

      colorscale(tmp, frame, "blue", "min") ;
      break ;

    case 13 :

      colorscale(tmp, frame, "blue", "red") ;
      break ;

    case 14 :

      colorscale(tmp, frame, "blue", "green") ;
      break ;



    case 15 :

      colorscale(tmp, frame, "yellow", "average") ;
      break ;

    case 16 :

      colorscale(tmp, frame, "yellow", "max") ;
      break ;

    case 17 :

      colorscale(tmp, frame, "yellow", "min") ;
      break ;

    case 18 :

      colorscale(tmp, frame, "yellow", "red") ;
      break ;

    case 19 :

      colorscale(tmp, frame, "yellow", "green") ;
      break ;

    case 20 :

      colorscale(tmp, frame, "yellow", "blue") ;
      break ;


    case 21 :

      colorscale(tmp, frame, "pink", "average") ;
      break ;

    case 22 :

      colorscale(tmp, frame, "pink", "max") ;
      break ;

    case 23 :

      colorscale(tmp, frame, "pink", "min") ;
      break ;

    case 24 :

      colorscale(tmp, frame, "pink", "red") ;
      break ;

    case 25 :

      colorscale(tmp, frame, "pink", "green") ;
      break ;

    case 26 :

      colorscale(tmp, frame, "pink", "blue") ;
      break ;


    case 27 :

      colorscale(tmp, frame, "turquoise", "average") ;
      break ;

    case 28 :

      colorscale(tmp, frame, "turquoise", "max") ;
      break ;

    case 29 :

      colorscale(tmp, frame, "turquoise", "min") ;
      break ;

    case 30 :

      colorscale(tmp, frame, "turquoise", "red") ;
      break ;

    case 31 :

      colorscale(tmp, frame, "turquoise", "green") ;
      break ;

    case 32 :

      colorscale(tmp, frame, "turquoise", "blue") ;
      break ;


    #ifdef DEBUG
    default :
      // Cannot append due of the GUI interfacing.
      fprintf(stdout,"Error applying colorscale filter !!!\n") ;
      return ;
    #endif

  }

  // We register current frame in vector<cv::Mat> for undo-redo.
  controller.process_after_applying(frame) ;

  // It convert current_image_to_process as src to RGB(A) in dst current_image_to_display.
  set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

  // Reset some variables.
  after_applying_reset_settings(controller) ;

}



/** Zoom specific methods. **/

void GUI::zoom_reset(Controller &controller) {

  if ( ! controller.image_file_loaded   ) { return ; }

  controller.reset_zoom_center(controller.current_image_to_process) ;

}


void GUI::zoom_plus(Controller &controller) {

  if ( ! controller.image_file_loaded   ) { return ; }

  cv::Mat frame ;

  zoom(controller.current_image_to_process, frame, cv::Point2f(controller.mouse_zoom_center_x, controller.mouse_zoom_center_y ), controller.zoom_factor_plus) ;

  // We register current frame in vector<cv::Mat> for undo-redo.
  controller.process_after_applying(frame) ;

  // It convert current_image_to_process as src to RGB(A) in dst current_image_to_display.
  set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

  controller.zoom_idx = controller.image_to_display_vector_idx ;

  controller.zoom_counter++ ;

}

void GUI::zoom_minus(Controller &controller) {

  if ( ! controller.image_file_loaded   ) { return ; }

  if (controller.zoom_counter > 0) {

    controller.zoom_idx--     ;
    controller.zoom_counter-- ;

    cv::Mat frame = controller.image_to_display_vector.at(controller.zoom_idx) ;

    // We register current frame in vector<cv::Mat> for undo-redo.
    controller.process_after_applying(frame) ;

    // It convert current_image_to_process as src to RGB(A) in dst current_image_to_display.
    set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

  }





}


/** Undo-Redo actions. **/

void GUI::undo_callback(Controller &controller) {

  if ( ! controller.image_file_loaded   ) { return ; }

  if (controller.image_to_display_vector_idx > 0) {

    controller.image_to_display_vector_idx-- ;

    controller.current_image_to_process = controller.image_to_display_vector.at(controller.image_to_display_vector_idx) ;

    controller.get_current_image_position() ;

    // It convert current_image_to_process as src to RGB(A) in dst current_image_to_display.
    set_img(controller.current_image_to_process, controller.current_image_to_display, controller) ; // It auto process conversion to RGB(A).

    controller.has_undo = true ;

  }



}

void GUI::redo_callback(Controller &controller) {

  if ( ! controller.image_file_loaded   ) { return ; }

  if (controller.image_to_display_vector_idx < controller.image_to_display_vector.size()-1 ) {

    controller.image_to_display_vector_idx++ ;

    controller.current_image_to_process = controller.image_to_display_vector.at(controller.image_to_display_vector_idx) ;

    controller.get_current_image_position() ;

    // It convert current_image_to_process as src to RGB(A) in dst current_image_to_display.
    set_img(controller.current_image_to_process, controller.current_image_to_display, controller) ; // It auto process conversion to RGB(A).

    if (controller.image_to_display_vector_idx == controller.image_to_display_vector.size()-1 ) {
      controller.has_undo = false ;
    }

  }

}

/** Configurable Filters callbacks. **/

void GUI::morphological_callback(Controller &controller) {

  if ( ! controller.image_file_loaded   ) { return ; }

  string kernel_type ;

  switch (controller.morphological_kernel_type) {

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

  switch (controller.morphological_center_value) {

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

  int operator_type ;

  switch (controller.morphological_operator_type) {

    case 0 :

      operator_type = cv::MORPH_ERODE ;
      break ;

    case 1 :

      operator_type = cv::MORPH_DILATE ;
      break ;

    case 2 :

      operator_type = cv::MORPH_OPEN ;
      break ;

    case 3 :

      operator_type = cv::MORPH_CLOSE ;
      break ;

    case 4 :

      operator_type = cv::MORPH_TOPHAT ;
      break ;

    case 5 :

      operator_type = cv::MORPH_BLACKHAT ;
      break ;

    #ifdef DEBUG
    default :
      // This cannot append due of the GUI interfacing.
      fprintf(stderr,"Cannot identify operator !!!\n") ;
      return ;
    #endif

  }

  cv::Mat kernel = make_kernel(kernel_type, static_cast<int>(controller.morphological_kernel_size), center_value) ;

  cv::Mat tmp = controller.current_image_to_process.clone() ;

  cv::Mat frame ;

  morphological_filter(tmp, frame, operator_type, kernel, static_cast<int>(controller.morphological_iterations) ) ;

  // We register current frame in vector<cv::Mat> for undo-redo.
  controller.process_after_applying(frame) ;

  // It convert current_image_to_process as src to RGB(A) in dst current_image_to_display.
  set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

  // Reset some variables.
  after_applying_reset_settings(controller) ;

}

void GUI::kernel_sharpen_callback(Controller &controller) {

  if ( ! controller.image_file_loaded   ) { return ; }

  string kernel_type ;

  switch (controller.kernel_sharpen_kernel_type) {

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

  cv::Mat tmp = controller.current_image_to_process.clone() ;

  cv::Mat frame ;

  Sharpen kernel(controller.kernel_sharpen_kernel_size, kernel_type, controller.kernel_sharpen_kernel_values_factor, '+', controller.kernel_sharpen_kernel_center_factor) ;

  kernel.apply(tmp, frame) ;

  // We register current frame in vector<cv::Mat> for undo-redo.
  controller.process_after_applying(frame) ;

  // It convert current_image_to_process as src to RGB(A) in dst current_image_to_display.
  set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

  // Reset some variables.
  after_applying_reset_settings(controller) ;

}

void GUI::kernel_find_edges_callback(Controller &controller) {

  if ( ! controller.image_file_loaded   ) { return ; }

  string kernel_type ;

  switch (controller.kernel_find_edges_kernel_type) {

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

  cv::Mat tmp = controller.current_image_to_process.clone() ;

  cv::Mat frame ;

  if (tmp.channels() == 4) {

    cv::Mat frame_rgb ;
    cv::Mat tmp_1     ;

    cvtColor(tmp, frame_rgb, cv::COLOR_BGRA2BGR) ;

    Find_Edges kernel(controller.kernel_find_edges_kernel_size, kernel_type, controller.kernel_find_edges_kernel_values_factor, '0', controller.kernel_find_edges_kernel_center_factor) ;

    kernel.apply(frame_rgb, tmp_1) ;

    vector<cv::Mat> tmp_2 ;
    vector<cv::Mat> tmp_3 ;

    cv::split(tmp,   tmp_2) ;
    cv::split(tmp_1, tmp_3) ;

    // Assign BGR channels.
    tmp_2[0] = tmp_3[0] ;
    tmp_2[1] = tmp_3[1] ;
    tmp_2[2] = tmp_3[2] ;

    // Final channels merging into result with alpha channel unchanged.
    cv::merge(tmp_2, frame) ;

  }
  else {

    Find_Edges kernel(controller.kernel_find_edges_kernel_size, kernel_type, controller.kernel_find_edges_kernel_values_factor, '0', controller.kernel_find_edges_kernel_center_factor) ;

    kernel.apply(tmp, frame) ;

  }
 

  // We register current frame in vector<cv::Mat> for undo-redo.
  controller.process_after_applying(frame) ;

  // It convert current_image_to_process as src to RGB(A) in dst current_image_to_display.
  set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

  // Reset some variables.
  after_applying_reset_settings(controller) ;

}




void GUI::kernel_emboss_callback(Controller &controller) {

  if ( ! controller.image_file_loaded   ) { return ; }

  cv::Mat tmp = controller.current_image_to_process.clone() ;

  cv::Mat frame ;

  Emboss kernel(controller.kernel_emboss_kernel_size, controller.kernel_emboss_kernel_values_factor, '+', controller.kernel_emboss_kernel_center_factor) ;

  kernel.apply(tmp, frame) ;

  // We register current frame in vector<cv::Mat> for undo-redo.
  controller.process_after_applying(frame) ;

  // It convert current_image_to_process as src to RGB(A) in dst current_image_to_display.
  set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

  // Reset some variables.
  after_applying_reset_settings(controller) ;

}

void GUI::kernel_mean_callback(Controller &controller) {

  if ( ! controller.image_file_loaded   ) { return ; }

  string kernel_type ;

  switch (controller.kernel_mean_kernel_type) {

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

  cv::Mat tmp = controller.current_image_to_process.clone() ;

  cv::Mat frame ;

  Mean kernel(controller.kernel_mean_kernel_size, kernel_type) ;

  kernel.kernel_print() ;

  kernel.apply(tmp, frame) ;

  // We register current frame in vector<cv::Mat> for undo-redo.
  controller.process_after_applying(frame) ;

  // It convert current_image_to_process as src to RGB(A) in dst current_image_to_display.
  set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

  // Reset some variables.
  after_applying_reset_settings(controller) ;

}

void GUI::kernel_gaussian_callback(Controller &controller) {

  if ( ! controller.image_file_loaded   ) { return ; }

  string kernel_type ;

  switch (controller.kernel_gaussian_kernel_type) {

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

  cv::Mat tmp = controller.current_image_to_process.clone() ;

  cv::Mat frame ;

  Gaussian kernel(controller.kernel_gaussian_kernel_size, controller.kernel_gaussian_sigma_value, kernel_type) ;

  kernel.apply(tmp, frame) ;

  // We register current frame in vector<cv::Mat> for undo-redo.
  controller.process_after_applying(frame) ;

  // It convert current_image_to_process as src to RGB(A) in dst current_image_to_display.
  set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

  // Reset some variables.
  after_applying_reset_settings(controller) ;

}

void GUI::kernel_kirsch_callback(Controller &controller) {

  if ( ! controller.image_file_loaded   ) { return ; }

  string kernel_direction ;

  switch (controller.kernel_kirsch_kernel_direction) {

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
      fprintf(stderr,"Cannot identify kernel type !!!\n") ;
      return ;
    #endif

  }

  cv::Mat tmp = controller.current_image_to_process.clone() ;

  cv::Mat frame ;

  if (tmp.channels() == 4) {

    cv::Mat frame_rgb ;
    cv::Mat tmp_1     ;

    cvtColor(tmp, frame_rgb, cv::COLOR_BGRA2BGR) ;

    Kirsch kernel(controller.kernel_kirsch_kernel_size, kernel_direction, controller.kernel_kirsch_kernel_values_factor) ;

    kernel.apply(frame_rgb, tmp_1) ;

    vector<cv::Mat> tmp_2 ;
    vector<cv::Mat> tmp_3 ;

    cv::split(tmp,   tmp_2) ;
    cv::split(tmp_1, tmp_3) ;

    // Assign BGR channels.
    tmp_2[0] = tmp_3[0] ;
    tmp_2[1] = tmp_3[1] ;
    tmp_2[2] = tmp_3[2] ;

    // Final channels merging into result with alpha channel unchanged.
    cv::merge(tmp_2, frame) ;

  }
  else {

    Kirsch kernel(controller.kernel_kirsch_kernel_size, kernel_direction, controller.kernel_kirsch_kernel_values_factor) ;

    kernel.apply(tmp, frame) ;

  }

  // We register current frame in vector<cv::Mat> for undo-redo.
  controller.process_after_applying(frame) ;

  // It convert current_image_to_process as src to RGB(A) in dst current_image_to_display.
  set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

  // Reset some variables.
  after_applying_reset_settings(controller) ;

}

void GUI::mult_colors_callback(Controller &controller) {

  if ( ! controller.image_file_loaded   ) { return ; }



  cv::Mat tmp = controller.current_image_to_process.clone() ;

  cv::Mat frame ;

  mult_colors(tmp, frame, static_cast<float>(controller.mult_red), static_cast<float>(controller.mult_green), static_cast<float>(controller.mult_blue), static_cast<float>(controller.mult_alpha) ) ;

  // We register current frame in vector<cv::Mat> for undo-redo.
  controller.process_after_applying(frame) ;

  // It convert current_image_to_process as src to RGB(A) in dst current_image_to_display.
  set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

  // Reset some variables.
  after_applying_reset_settings(controller) ;

}

void GUI::set_image_in_color_tone_callback(Controller &controller, const uint8_t red, const uint8_t green, const uint8_t blue) {

  if ( ! controller.image_file_loaded   ) { return ; }



  cv::Mat tmp = controller.current_image_to_process.clone() ;

  cv::Mat frame ;

  set_image_in_color_tone(tmp, frame, red, green, blue) ;

  // We register current frame in vector<cv::Mat> for undo-redo.
  controller.process_after_applying(frame) ;

  // It convert current_image_to_process as src to RGB(A) in dst current_image_to_display.
  set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

  // Reset some variables.
  after_applying_reset_settings(controller) ;

}

void GUI::mult_global_intensity_callback(Controller &controller, const float factor) {

  if ( ! controller.image_file_loaded   ) { return ; }



  cv::Mat tmp = controller.current_image_to_process.clone() ;

  cv::Mat frame ;

  multiply_global_intensity(tmp, frame, factor) ;

  // We register current frame in vector<cv::Mat> for undo-redo.
  controller.process_after_applying(frame) ;

  // It convert current_image_to_process as src to RGB(A) in dst current_image_to_display.
  set_img(frame, controller.current_image_to_display, controller) ;  // It auto process conversion to RGB(A).

  // Reset some variables.
  after_applying_reset_settings(controller) ;

}

#endif
