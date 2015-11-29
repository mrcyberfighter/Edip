/** ***********************************************************************************
  *                                                                                   *      
  * @libedip an underlying library for the image processing program @Edip.            *
  * Copyright (C) 2015 Brüggemann Eddie <mrcyberfighter@gmail.com>                    *
  *                                                                                   *
  * This file is part of @libedip.                                                    *
  * libedip is free software: you can redistribute it and/or modify                   *
  * it under the terms of the GNU General Public License as published by              *
  * the Free Software Foundation, either version 3 of the License, or                 *
  * (at your option) any later version.                                               *
  *                                                                                   *
  * @libedip is distributed in the hope that it will be useful,                       * 
  * but WITHOUT ANY WARRANTY; without even the implied warranty of                    *
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                      *
  * GNU General Public License for more details.                                      *
  *                                                                                   *
  * You should have received a copy of the GNU General Public License                 *
  * along with @libedip. If not, see <http://www.gnu.org/licenses/>                   *
  *                                                                                   *
  *************************************************************************************/
 
/** libedip:
  *
  *  Was developed by Eddie Brüggemann <mrcyberfighter@gmail.com> for his **Easy Digital Imaging Processing** program called @Edip.
  *
  *  This library is based on the @OpenCV library opencv-3.0.0 (the latest release) provided with this file as support (for GTK+3 compatibility reason).
  *
  *  The @OpenCV library provide over 300 algorithms for computer vision purpose.
  *
  *  The @OpenCV libary was introduced in 1999 and adopted as primary development tool for computer vision by
  *  researcher and developers in computer vision.
  *  @OpenCV was originally developed at Intel by a team lead by Gary Bradsky as an initiative to advanced resaerch in vision and
  *  promote the development of rich vision, CPU-intensiv applications.
  *
  *  1. 2006 first major release of @OpenCV.
  *  2. 2009 second major release of @OpenCV.
  *  3. 2012 reshape from @OpenCV to a non-profit foundation <http://opencv.org>
  *
  *  Thank's to all the contributors of the @OpenCV libary for providing us this exceptional tool.
  *
  ******************************************************************************************************************************************************/ 

#include "Color_Filters.hpp"

using namespace std ;

void grayscale(const cv::Mat &frame, cv::Mat &result, const string mode) {

  /** Grayscale the input frame according to the @mode argument representing the base for grayscaling values computing.
    *
    * @mode values: "average", "min", "max", "red", "green", "blue" or "raw".
    *
    ***************************************************************************************************************/

  if ( (! (mode == "average")) && (! (mode == "max")) && (! (mode == "min")) && (! (mode == "blue")) && (! (mode == "green")) && (! (mode == "red")) ) {
    // Better raise an exception.
    fprintf(stdout,"Wrong argument %s(..., mode = \"average\" | \"max\" | \"min\" | \"blue\" | \"green\" | \"red\", ...)\n", __func__) ;
    result = frame ;
    return ;
  }



  vector<cv::Mat> channels    ;
  cv::split(frame, channels)  ;

  cv::Mat r(channels[2])  ;
  cv::Mat g(channels[1])  ;
  cv::Mat b(channels[0])  ;

  cv::Mat res ;

  if (mode == "average") {

    // Average grayscaling mode.

    if (frame.channels() == 4) {
      // Case of BGRA encoding.

      cv::Mat tmp_1 ;

      // Simply Convert the frame to gray and then to BGR pixels encoding.
      cvtColor(frame,  tmp_1, cv::COLOR_BGRA2GRAY ) ;
      cvtColor(tmp_1,  tmp_1, cv::COLOR_GRAY2BGR ) ;

      // Copy the BGR channels converted to gray by leaving the alpha channel unchanged.

      vector<cv::Mat> tmp_2 ;
      vector<cv::Mat> tmp_3 ;

      cv::split(frame, tmp_2) ;
      cv::split(tmp_1, tmp_3) ;

      // Assign BGR channels.
      tmp_2[0] = tmp_3[0] ;
      tmp_2[1] = tmp_3[1] ;
      tmp_2[2] = tmp_3[2] ;

      // Final channels merging into result with alpha channel unchanged.
      cv::merge(tmp_2, result) ;

      return ;
    }

    // Case of BGR encoding.
    // So we simply convert.
    cvtColor(frame, result,  cv::COLOR_BGR2GRAY) ;
    cvtColor(result, result, cv::COLOR_GRAY2BGR) ;

    return ;
  }
  else if (mode == "max") {

    // Maximal grayscaling mode.

    cv::Mat rgb ;

    // Compute maximals from the BGR channels.
    cv::max(r,   g, rgb) ;
    cv::max(rgb, b, rgb) ;


    vector<cv::Mat> tmp ;

    cv::split(frame, tmp) ;

    // Assign BGR channels.
    tmp[0] = rgb ;
    tmp[1] = rgb ;
    tmp[2] = rgb ;

    // Final channels merging into result with alpha channel unchanged.
    cv::merge(tmp, result) ;

    // Final channels merging into result with alpha channel unchanged.
    //result = res ;

    return ;
  }
  else if (mode == "min") {

    // Minimal grayscaling mode.

    cv::Mat rgb ;

    // Compute maximals from the BGR channels.
    cv::min(r,   g, rgb) ;
    cv::min(rgb, b, rgb) ;


    vector<cv::Mat> tmp   ;

    cv::split(frame, tmp) ;

    // Assign BGR channels.
    tmp[0] = rgb ;
    tmp[1] = rgb ;
    tmp[2] = rgb ;

    // Final channels merging into result with alpha channel unchanged.
    cv::merge(tmp, result) ;

    // Final channels merging into result with alpha channel unchanged.
    //result = res ;

    return ;
  }
  else if ( mode == "blue" ) {

    // Blue grayscaling mode.

    vector<cv::Mat> tmp ;

    cv::split(frame, tmp) ;

    // Assign BGR channels to the blue channel.
    tmp[0] = b ;
    tmp[1] = b ;
    tmp[2] = b ;

    // Final channels merging into result with alpha channel unchanged.
    cv::merge(tmp, result) ;

    //result = res ;

    return ;

  }
  else if ( mode == "green" ) {

    // Green grayscaling mode.

    vector<cv::Mat> tmp ;

    cv::split(frame, tmp) ;

    // Assign BGR channels to the green channel.
    tmp[0] = g ;
    tmp[1] = g ;
    tmp[2] = g ;

    // Final channels merging into result with alpha channel unchanged.
    cv::merge(tmp, result) ;

    // Final channels merging into result with alpha channel unchanged.
    //result = res ;

    return ;
  }
  else if ( mode == "red" ) {

    // Red grayscaling mode.

    vector<cv::Mat> tmp ;

    cv::split(frame, tmp) ;

    // Assign BGR channels to the green channel.
    tmp[0] = r ;
    tmp[1] = r ;
    tmp[2] = r ;

    // Final channels merging into result with alpha channel unchanged.
    cv::merge(tmp, result) ;

    // Final channels merging into result with alpha channel unchanged.
    //result = res ;

    return ;

  }





}


void colorscale(const cv::Mat &frame, cv::Mat &result, const string dst_color, const string mode, float factor) {

  /** Colorscale the input frame according to the @mode argument representing the base for colorscaling computing.
    *
    * @mode values: "average", "min", "max", "red", "green" or "blue" .
    *
    * @dst_color values: "red", "green", "blue", "yellow", "pink" or "turquoise".
    *
    ***************************************************************************************************************/


  if ( (! (dst_color == "red")) && (! (dst_color == "green")) && (! (dst_color == "blue")) && (! (dst_color == "yellow")) && (! (dst_color == "pink")) && (! (dst_color == "turquoise") ) ) {
    // Better raise an exception.
    fprintf(stdout,"Wrong argument %s(..., dst_color = \"red\" | \"green\" | \"blue\" | \"yellow\" | \"pink\" | \"turquoise\", ...)\n", __func__) ;

    result = frame ;

    return ;
  }

  if  ((! (mode == "average")) && (! (mode == "max")) && (! (mode == "min")) && (! (mode == "blue")) && (! (mode == "green")) && (! (mode == "red")) ) {
    // Better raise an exception.
    fprintf(stdout,"Wrong argument %s(..., mode = \"average\" | \"max\" | \"min\" | \"blue\" | \"green\" | \"red\", ...)\n", __func__) ;

    result = frame ;

    return ;
  }

  vector<cv::Mat> channels    ;

  cv::split(frame, channels)  ;

  // Construct a matrix for one channel composed from zeros values.
  // For disabling the needed color channels.
  cv::Mat zeros = cv::Mat::zeros(channels[0].rows, channels[0].cols, CV_8U) ;


  // Getting the channels before applying.
  cv::Mat red(channels[0].rows,   channels[0].cols, CV_8U)   ;
  cv::Mat green(channels[0].rows, channels[0].cols, CV_8U)   ;
  cv::Mat blue(channels[0].rows,  channels[0].cols, CV_8U)   ;

  red   = channels[2] ;
  green = channels[1] ;
  blue  = channels[0] ;



  if (factor != 1.0) {
    // Case factor would change something: we multiply the channels with it.
    red.mul(factor) ;
    green.mul(factor) ;
    blue.mul(factor) ;
  }

  if (dst_color == "red" ) {

    // Redscaling.

    if (mode == "average") {
      // Computing and assign the average from the 3 channels.
      red = (red + green + blue) / 3.0 ;
    }
    else if (mode == "min") {
      // Compute minimals from every channel.
      cv::min(red, green, red)    ;
      cv::min(green, blue, green) ;
      cv::min(blue, red, blue)    ;

      // Computing and assign channels minimals average.
      red = (red + green + blue) / 3.0 ;
    }
    else if (mode == "max") {
      // Compute maximals from every channel.
      cv::max(red,   green, red)   ;
      cv::max(green, blue,  green) ;
      cv::max(blue,  red,   blue)  ;
      // Computing and assign channels maximals average.
      red = (red + green + blue) / 3.0 ;
    }
    else if (mode == "red") {
      ; // red = red ; // Equal to raw mode.
    }
    else if (mode == "green") {
      // Assign green to red. So that the red take the values from the green channel.
      red = green ;
    }
    else if (mode == "blue") {
      // Assign blue to red. So that the red take the values from the blue channel.
      red = blue  ;
    }

    // Assign the red channel and disable the others (set on zero).
    channels[2] = red   ;
    channels[1] = zeros ;
    channels[0] = zeros ;
  }

  else if (dst_color == "green" ) {

    // Greenscaling.

    if (mode == "average") {
      // Computing and assign the average from the 3 channels.
      green = (red + green + blue) / 3.0 ;
    }
    else if (mode == "min") {
      // Compute minimals from every channel.
      cv::min(red, green, red) ;
      cv::min(green, blue, green) ;
      cv::min(blue, red, blue) ;
      // Computing and assign channels minimals average.
      green = (red + green + blue) / 3.0 ;
    }
    else if (mode == "max") {
      // Compute maximals from every channel.
      cv::max(red,   green, red)   ;
      cv::max(green, blue,  green) ;
      cv::max(blue,  red,   blue)  ;

      // Computing and assign channels maximals average.
      green = (red + green + blue) / 3.0 ;
    }
    else if (mode == "red") {
      // Assign red to green. So that the green take the values from the red channel.
      green = red ;
    }
    else if (mode == "green") {
      //green = green ; // EQual to raw mode.
    }
    else if (mode == "blue") {
      // Assign green to blue. So that the green take the values from the blue channel.
      green = blue ;
    }

    // Assign the green channel and disable the others (set on zero).
    channels[2] = zeros ;
    channels[1] = green ;
    channels[0] = zeros ;
  }
  else if (dst_color == "blue" ) {

    // Bluescaling.

    if (mode == "average") {
      // Computing and assign the average from the 3 channels.
      blue = (red + green + blue) / 3.0 ;
    }
    else if (mode == "min") {
      // Compute minimals from every channel.
      cv::min(red,   green, red)   ;
      cv::min(green, blue,  green) ;
      cv::min(blue,  red,   blue)  ;
      // Computing and assign channels minimals average.
      blue = (red + green + blue) / 3.0 ;
    }
    else if (mode == "max") {
      // Compute maximals from every channel.
      cv::max(red,   green, red)   ;
      cv::max(green, blue,  green) ;
      cv::max(blue,  red,   blue)  ;
      // Computing and assign channels maximals average.
      blue = (red + green + blue) / 3.0 ;
    }
    else if (mode == "red") {
      // Assign red to blue. So that the blue take the values from the red channel.
      blue = red ;
    }
    else if (mode == "green") {
      // Assign green to blue. So that the blue take the values from the green channel.
      blue = green ;
    }
    else if (mode == "blue") {
      //blue = blue ; // EQual to raw mode.
    }

    // Assign the blue channel and disable the others (set on zero).
    channels[2] = zeros ;
    channels[1] = zeros ;
    channels[0] = blue  ;
  }
  else if (dst_color == "yellow" ) {

    // Yelowscaling.

    if (mode == "average") {
      // Computing and assign the average from the 3 channels.
      red   = (red + green + blue) / 3.0 ;
      green = (red + green + blue) / 3.0 ;
    }
    else if (mode == "min") {
      // Compute minimals from every channel.
      cv::min(red,   green, red)   ;
      cv::min(green, blue,  green) ;
      cv::min(blue,  red,   blue)  ;
      // Computing and assign channels minimals average.
      red   = (red + green + blue) / 3.0 ;
      green = (red + green + blue) / 3.0 ;
    }
    else if (mode == "max") {
      // Compute maximals from every channel.
      cv::max(red, green, red) ;
      cv::max(green, blue, green) ;
      cv::max(blue, red, blue) ;
      // Computing and assign channels maximals average.
      red   = (red + green + blue) / 3.0 ;
      green = (red + green + blue) / 3.0 ;
    }
    else if (mode == "red") {
      // Assign red to green. So that the green take the values from the red channel.
      // So that we make some yellow by letting red unchanged.
      green = red ;
    }
    else if (mode == "green") {
      // Assign green to red. So that the red take the values from the green channel.
      // So that we make some yellow by letting green unchanged.
      red   = green ;
    }
    else if (mode == "blue") {
      // Assign blue to red and blue to green. So that we make some yellow with the blue values.
      red   = blue ;
      green = blue ;
    }

    // Assign the red and green channel and disable the other (set on zero).
    channels[2] = red   ;
    channels[1] = green ;
    channels[0] = zeros ;
  }
  else if (dst_color == "pink" ) {

    // Pinkscaling.

    if (mode == "average") {
      // Computing and assign the average from the 3 channels.
      red   = (red + green + blue) / 3.0 ;
      blue  = (red + green + blue) / 3.0 ;
    }
    else if (mode == "min") {
      // Compute minimals from every channel.
      cv::min(red,   green, red)   ;
      cv::min(green, blue,  green) ;
      cv::min(blue,  red,   blue)  ;

      // Computing and assign channels minimals average.
      red   = (red + green + blue) / 3.0 ;
      blue  = (red + green + blue) / 3.0 ;
    }
    else if (mode == "max") {
      // Compute maximals from every channel.
      cv::max(red,   green, red)   ;
      cv::max(green, blue,  green) ;
      cv::max(blue,  red,   blue)  ;
      // Computing and assign channels maximals average.
      red   = (red + green + blue) / 3.0 ;
      blue  = (red + green + blue) / 3.0 ;
    }
    else if (mode == "red") {
      // Assign red to blue. So that the blue take the values from the red channel.
      // So that we make some pink by letting red unchanged.
      blue = red ;
    }
    else if (mode == "green") {
      // Assign green to red and green to blue. So that we make some pink with the blue values.
      red   = green ;
      blue  = green ;
    }
    else if (mode == "blue") {
      // Assign blue to red. So that the red take the values from the blue channel.
      // So that we make some pink by letting blue unchanged.
      red   = blue ;
    }


    // Assign the red and green channel and disable the other (set on zero).
    channels[2] = red   ;
    channels[1] = zeros ;
    channels[0] = blue  ;
  }
  else if (dst_color == "turquoise" ) {

    // Turquoisescaling.

    if (mode == "average") {
      // Computing and assign the average from the 3 channels.
      green = (red + green + blue) / 3.0 ;
      blue  = (red + green + blue) / 3.0 ;
    }
    else if (mode == "min") {
      // Compute minimals from every channel.
      cv::min(red,   green, red)   ;
      cv::min(green, blue,  green) ;
      cv::min(blue,  red,   blue)  ;

      // Computing and assign channels minimals average.
      green = (red + green + blue) / 3.0 ;
      blue  = (red + green + blue) / 3.0 ;
    }
    else if (mode == "max") {
      // Compute maximals from every channel.
      cv::max(red, green, red) ;
      cv::max(green, blue, green) ;
      cv::max(blue, red, blue) ;
      // Computing and assign channels maximals average.
      green = (red + green + blue) / 3.0 ;
      blue  = (red + green + blue) / 3.0 ;
    }
    else if (mode == "red") {
      // Assign red to green and red to blue. So that we make some turquoise with the blue values.
      green = red ;
      blue  = red ;
    }
    else if (mode == "green") {
      // Assign green to blue. So that the blue take the values from the green channel.
      // So that we make some turquoise by letting red unchanged.
      blue  = green ;
    }
    else if (mode == "blue") {
      // Assign blue to green. So that the green take the values from the blue channel.
      // So that we make some turquoise by letting red unchanged.
      green = blue ;
    }


    // Assign the green and blue channel and disable the other (set on zero).
    channels[2] = zeros ;
    channels[1] = green ;
    channels[0] = blue  ;
  }

  // Final channels merging with letting the alpha channel unchanged.
  cv::merge(channels, result) ;

}

void extrema(const cv::Mat &frame, cv::Mat &result, const string min_or_max) {

  /** Compute the maximal or minimal values from:
    *
    * Blue  and green and set the result as blue value.
    * Green and red   and set the result as green value.
    * Red   and blue  and set the result as red value.
    *
    ****************************************************/
  vector<cv::Mat> channels    ;
  cv::split(frame, channels)  ;

  if (min_or_max == "max" ) {

    cv::Mat max_1 = cv::max(channels[0], channels[1]) ;
    cv::Mat max_2 = cv::max(channels[1], channels[2]) ;
    cv::Mat max_3 = cv::max(channels[2], channels[0]) ;

    channels[0] = max_1  ;
    channels[1] = max_2  ;
    channels[2] = max_3  ;

  }
  else if (min_or_max == "min") {

    cv::Mat min_1 = cv::min(channels[0], channels[1]) ;
    cv::Mat min_2 = cv::min(channels[1], channels[2]) ;
    cv::Mat min_3 = cv::min(channels[2], channels[0]) ;

    channels[0] = min_1  ;
    channels[1] = min_2  ;
    channels[2] = min_3  ;

  }
  else {

    // Better raise an exception.
    fprintf(stdout,"Wrong argument %s(..., min_or_max = \"max\" | \"min\", ...)\n", __func__) ;
    result = frame ;
    return ;

  }

  cv::merge(channels, result) ;

}



void multiply_global_intensity(const cv::Mat &frame, cv::Mat &result, float factor) {

  /** Multiply all channels except alpha (if present) per @factor. **/

  vector<cv::Mat> channels    ;
  cv::split(frame, channels)  ;

  int rows = channels[0].rows ;

  int cols = channels[0].cols ;

  cv::Mat ones  = cv::Mat::ones(channels[0].rows,  channels[0].cols, CV_8U) ;

  cv::Mat red(channels[0].rows,    channels[0].cols,  CV_8U)   ;
  cv::Mat green(channels[0].rows,  channels[0].cols,  CV_8U)   ;
  cv::Mat blue(channels[0].rows,   channels[0].cols,  CV_8U)   ;

  cv::multiply(channels[2], ones, red,   factor, CV_8U) ;
  cv::multiply(channels[1], ones, green, factor, CV_8U) ;
  cv::multiply(channels[0], ones, blue,  factor, CV_8U) ;

  channels[2] = red   ;
  channels[1] = green ;
  channels[0] = blue  ;

  cv::merge(channels, result) ;

}



void set_image_in_color_tone(const cv::Mat &frame, cv::Mat &result, uint8_t red, uint8_t green, uint8_t blue) {

  /** Set the entire image in the wanted color tone by:
    *
    * 1. Computing the frame mean value for every channel.
    * 2. Dividing each given color by the corresponding mean value from each channel.
    * 3. Multiply each channel by the result from step 2.
    *
    *********************************************************************************/

  vector<cv::Mat> channels    ;
  cv::split(frame, channels)  ;

  cv::Mat r(channels[2])  ;
  cv::Mat g(channels[1])  ;
  cv::Mat b(channels[0])  ;

  cv::Scalar blue_scalar  = cv::mean(r) ;
  cv::Scalar green_scalar = cv::mean(g) ;
  cv::Scalar red_scalar   = cv::mean(b) ;

  double blue_divider  = blue_scalar.val[0] ;
  double green_divider = green_scalar.val[0] ;
  double red_divider   = red_scalar.val[0] ;

  double middle_red   =  ((double) red)   / red_divider    ;
  double middle_green =  ((double) green) / green_divider  ;
  double middle_blue  =  ((double) blue)  / blue_divider   ;

  int rows = channels[0].rows ;

  int cols = channels[0].cols ;

  cv::Mat zeros = cv::Mat::zeros(rows, cols, CV_8U) ;

  cv::Mat ones  = cv::Mat::ones(rows,  cols, CV_8U) ;

  cv::Mat reds(channels[2])  ;
  cv::Mat greens(channels[1])  ;
  cv::Mat blues(channels[0])  ;

  cv::multiply(r, ones, reds,   middle_red,   CV_8U) ;
  cv::multiply(g, ones, greens, middle_green, CV_8U) ;
  cv::multiply(b, ones, blues,  middle_blue,  CV_8U) ;


  // Copy data including alpha channel if frame has one.
  vector<cv::Mat> tmp ;

  cv::split(frame, tmp) ;

  tmp[0] = blues ;
  tmp[1] = greens ;
  tmp[2] = reds ;

  cv::merge(tmp, result) ;

}

void change_intensity(const cv::Mat &frame, cv::Mat &result, bool add, int red, int green, int blue, int alpha) {

  if (frame.channels() == 4) {

    if (add) {
      cv::add(frame,      cv::Scalar( blue, green, red, alpha), result, cv::Mat(), frame.depth() ) ;
    }
    else {
      cv::subtract(frame, cv::Scalar( blue, green, red, alpha), result, cv::Mat(), frame.depth()) ;
    }

  }
  else if (frame.channels() == 3) {

    if (add) {
      cv::add(frame,      cv::Scalar( blue, green, red), result, cv::Mat(), frame.depth() ) ;
    }
    else {
      cv::subtract(frame, cv::Scalar( blue, green, red), result, cv::Mat(), frame.depth()) ;
    }

  }
}

void invert_intensity(const cv::Mat &frame, cv::Mat &result) {

  cv::Mat invert_intensity_lookup_table(1, 256, CV_8U) ;

  for (int c=0 ; c < 256 ; c++) {

    invert_intensity_lookup_table.at<uchar>(c)=255-c ;

  }

  /** The LUT function apply on frame the following operation:

      frame[idx] = invert_intensity_lookup_table[ frame[idx] ] + d ;

                         /
                        | 0    if frame depth == CV_U8  ;
                    d= <
                        | 128  if frame depth == CV_S16 ;
                         \
                      
  *****************************************************************/

  if (frame.channels() == 4) {

    // Has an alpha channel.

    cv::Mat tmp_1 ;
    cv::Mat tmp_2 ;

    cvtColor(frame, tmp_1, cv::COLOR_BGRA2BGR) ;

    // Apply invert intensity Look Up Table on BGR.
    cv::LUT(tmp_1, invert_intensity_lookup_table, tmp_2) ;

    vector<cv::Mat> tmp_3 ;
    vector<cv::Mat> tmp_4 ;

    cv::split(frame, tmp_3) ; // Split to keep alpha values.
    cv::split(tmp_2, tmp_4) ; // Split the LUT(...) result.

    // Copy all BGR values into the frame with 4 channels.
    tmp_3[0] = tmp_4[0] ;
    tmp_3[1] = tmp_4[1] ;
    tmp_3[2] = tmp_4[2] ;

    cv::merge(tmp_3, result) ;

  }
  else if (frame.channels() == 3) {
    // Don't need to take in charge alpha channel.
    cv::LUT(frame, invert_intensity_lookup_table, result) ;
  }


}

void effect_light(const cv::Mat &frame, cv::Mat &result) {

  cv::Mat gray ;

  cv::Mat res  ;

  // Process grayscaling.
  grayscale(frame,      gray) ;

  // Then invert intensity.
  invert_intensity(gray, res) ;

  if (frame.channels() == 4) {

    // Has an alpha channel.

    cvtColor(res, res, cv::COLOR_BGRA2BGR) ;

    vector<cv::Mat> tmp_1 ;
    vector<cv::Mat> tmp_2 ;

    cv::split(frame, tmp_1) ;  // Resplit to keep alpha values.
    cv::split(res,   tmp_2) ;

    // Copy all BGR values into the frame with 4 channels.
    tmp_1[0] = tmp_2[0] ;
    tmp_1[1] = tmp_2[1] ;
    tmp_1[2] = tmp_2[2] ;


    cv::merge(tmp_1, result) ;

  }
  else {
    result = res ;
  }



}


void mult_colors(const cv::Mat &frame, cv::Mat &result, float red_mult, float green_mult, float blue_mult, float alpha_mult) {

  /** Multiply every channel per given argument factor. **/

  vector<cv::Mat> tmp_vec ;

  cv::split(frame, tmp_vec) ;

  tmp_vec[0] = tmp_vec[0].mul(blue_mult) ;
  tmp_vec[1] = tmp_vec[1].mul(green_mult) ;
  tmp_vec[2] = tmp_vec[2].mul(red_mult) ;

  if (frame.channels() == 4) {
    tmp_vec[3] = tmp_vec[3].mul(alpha_mult) ;
  }

  cv::merge(tmp_vec, result) ;

}

void bits_not(const cv::Mat &frame, cv::Mat &result) {

  bitwise_not(frame, result) ;

}

void recolorRC(const cv::Mat &frame, cv::Mat &result) {

  /** Simulate conversion from BGR to RC (red, cyan).
    *
    *   Blues and greens are replaced with cyans. The effect is similar
    *   to Technicolor Process 2 (used in early color movies) and CGA
    *   Palette 3 (used in early color PCs).
    *
    *   Pseudocode:
    *   dst.b = dst.g = 0.5 * (src.b + src.g)
    *   dst.r = src.r
    *
    * @NOTE: Effect implementation from Joseph Howse author from the book: "OpenCV Computer Vision with Python".
    *        Translate from the python into the proramming language C++ and BGRA support adding.
    *        by Eddie Bruggemann <mrcyberfighter@gmail.com>.
    *
    ********************************************************************************************************************/


    vector<cv::Mat> channels   ;

    cv::split(frame, channels) ;

    cv::addWeighted(channels[0], 0.5, channels[1], 0.5, 0, channels[0]) ;

    //Copy the blue values into the green channel.
    channels[1] = channels[0] ;
    //channels[0] = channels[0] ;



    cv::merge(channels, result) ;
}



void recolorRGV(const cv::Mat &frame, cv::Mat &result) {

  /** Simulate conversion from BGR to RGV (red, green, value).
    *
    *   Blues are desaturated. The effect is similar to Technicolor
    *   Process 1 (used in early color movies).
    *
    *   Pseudocode:
    *   dst.b = min(src.b, src.g, src.r)
    *   dst.g = src.g
    *   dst.r = src.r
    *
    * On blue toned images, images in color scale blue, it return an black image.
    *
    * @NOTE: effect implementation from Joseph Howse author from the book: "OpenCV Computer Vision with Python".
    *         Translate from the python into the proramming language C++ and BGRA support adding.
    *         by Eddie Bruggemann <mrcyberfighter@gmail.com>.
    *
    ********************************************************************************************************************/

    vector<cv::Mat> channels   ;

    cv::split(frame, channels) ;

    // Compute minimal values from the BGR channels and set the result into the blue channel.
    cv::min(channels[0], channels[1], channels[0]) ;
    cv::min(channels[0], channels[2], channels[0]) ;

    cv::merge(channels, result) ;

}


void recolorCMV(const cv::Mat &frame, cv::Mat &result) {

  /** Simulate conversion from BGR to CMV (cyan, magenta, value).
    *
    *    Yellows are desaturated. The effect is similar to CGA Palette 1
    *    (used in early color PCs).
    *
    *    Pseudocode:
    *    dst.b = max(src.b, src.g, src.r)
    *    dst.g = src.g
    *    dst.r = src.r
    *
    * @NOTE: effect implementation from Joseph Howse author from the book: "OpenCV Computer Vision with Python".
    *        Translate from the python into the proramming language C++ and BGRA support adding.
    *        by Eddie Bruggemann <mrcyberfighter@gmail.com>.
    *
    ********************************************************************************************************************/

    vector<cv::Mat> channels ;

    cv::split(frame, channels) ;

    // Compute the maximal values from BGR channels and set the result into the blue channel.
    cv::max(channels[0], channels[1], channels[0]) ;
    cv::max(channels[0], channels[2], channels[0]) ;

    cv::merge(channels, result) ;
}
