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

#include "HLSV_Filters.hpp"

void change_lightness(const cv::Mat &frame, cv::Mat &result, float lightness) {

  /** Change the lightness by argument factor @lightness.
    * Luminance factor of light intensity.
    *
    ****************************************************/


  // Convert into the Lab colorspace.
  cv::Mat lab ;
  cv::cvtColor(frame, lab, cv::COLOR_BGR2Lab) ;

  vector<cv::Mat> channels ;

  cv::split(lab, channels) ;

  // Change lightness by multiplying it by factor: 
  channels[0] *= lightness ;

  cv::Mat tmp1 ;

  cv::Mat tmp2 ;

  cv::merge(channels, tmp1) ;

  // Convert back to BGR colorspace.
  cv::cvtColor(tmp1, tmp2, cv::COLOR_Lab2BGR) ;


  // Copying datas with alpha channel don't affect by preceding operation.
  vector<cv::Mat> dst_vector ;
  vector<cv::Mat> cp_vector ;

  cv::split(frame, dst_vector) ;
  cv::split(tmp2, cp_vector) ;

  dst_vector[0] = cp_vector[0] ;
  dst_vector[1] = cp_vector[1] ;
  dst_vector[2] = cp_vector[2] ;

  cv::Mat tmp3 ;

  cv::merge(dst_vector, tmp3) ;

  result = tmp3 ;

  return ;

}

void change_saturation(const cv::Mat &frame, cv::Mat &result, float saturation) {

  /** Change the saturation by argument factor @saturation.
    *
    *   Saturation varies from 0 (black-gray-white) to 255 (pure spectrum color).
    * 
    *   The saturation represent the vivid of the colors:
    *   Low value  : pastel color.
    *   High value : rainbow color.
    *
    *                   max(r,g,b) - min(r,g,b)
    *    Saturation = ----------------------------
    *                         max(r,g,b)
    *
    *****************************************************************************/
                

  cv::Mat hsv ;
  // Convert to HSV colorspace:
  cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV) ;

  vector<cv::Mat> channels ;

  cv::split(hsv, channels) ;

  // Change saturation by multiplying it by factor: 
  channels[1] *= saturation ;

  cv::Mat tmp1 ;
  cv::Mat tmp2 ;

  cv::merge(channels, tmp1) ;

  // Convert back to BGR colorspace:
  cv::cvtColor(tmp1, tmp2, cv::COLOR_HSV2BGR) ;

  // Copying datas with alpha channel don't affect by preceding operation.
  vector<cv::Mat> dst_vector ;
  vector<cv::Mat> cp_vector ;

  cv::split(frame, dst_vector) ;
  cv::split(tmp2, cp_vector) ;

  dst_vector[0] = cp_vector[0] ;
  dst_vector[1] = cp_vector[1] ;
  dst_vector[2] = cp_vector[2] ;

  cv::Mat tmp3 ;

  cv::merge(dst_vector, tmp3) ;

  result = tmp3 ;

  return ;

}

void change_hue(const cv::Mat &frame, cv::Mat &result, float hue) {

  /** Change the hue by argument factor @hue.
    *
    *  Hue varies from 0 to 180, see cvtColor
    *  Hue represent the dominant color on a circle 0-360 degrees.
    *  The value is divided by 2 from cv for uchar representation that's why the range is 0-179.
    *
    *  Hue (dominant color) -> tint of the color.
    *
    ********************************************************************************************/

  cv::Mat hsv ;
  // Convert to HSV colorspace:
  cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV) ;

  vector<cv::Mat> channels ;

  cv::split(hsv, channels) ;

  // Multiply hue by factor:
  channels[0] *= hue ;

  cv::Mat tmp1 ;
  cv::Mat tmp2 ;

  cv::merge(channels, tmp1) ;

  // Convert back to BGR colorspace:
  cv::cvtColor(tmp1, tmp2, cv::COLOR_HSV2BGR) ;


  vector<cv::Mat> dst_vector ;
  vector<cv::Mat> cp_vector ;

  cv::split(frame, dst_vector) ;
  cv::split(tmp2, cp_vector) ;

  dst_vector[0] = cp_vector[0] ;
  dst_vector[1] = cp_vector[1] ;
  dst_vector[2] = cp_vector[2] ;

  cv::Mat tmp3 ;

  cv::merge(dst_vector, tmp3) ;

  result = tmp3 ;

}

void change_brightness(const cv::Mat &frame, cv::Mat &result, float brightness) {

  // Value represent the brightness (luminosity of the colors).

  // val (max value) multiply factor.

  cv::Mat hsv ;

  cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV) ;

  vector<cv::Mat> channels ;

  cv::split(hsv, channels) ;

  //channels[0] // Hue.        (tint)
  //channels[1] // Saturation. (saturation grad).
  //channels[2] // Value (brightness (luminosity) of the color).

  channels[2] *= brightness ;

  cv::Mat tmp1 ;

  cv::Mat tmp2 ;

  cv::merge(channels, tmp1) ;


  cv::cvtColor(tmp1, tmp2, cv::COLOR_HSV2BGR) ;

  // Copying datas with alpha channel don't affect by preceding operation.
  vector<cv::Mat> dst_vector ;
  vector<cv::Mat> cp_vector ;

  cv::split(frame, dst_vector) ;
  cv::split(tmp2, cp_vector) ;

  dst_vector[0] = cp_vector[0] ;
  dst_vector[1] = cp_vector[1] ;
  dst_vector[2] = cp_vector[2] ;

  cv::Mat tmp3 ;

  cv::merge(dst_vector, tmp3) ;

  result = tmp3 ;

  return ;

}

void get_lightness_image(const cv::Mat &frame, cv::Mat &result) {

  /** @NOTE: unused in the program Edip. **/

  /** Get an image representation of the lightness as a grayscale image. **/

  cv::Mat lab ;

  cv::cvtColor(frame, lab, cv::COLOR_BGR2Lab) ;

  vector<cv::Mat> lightness_values  ;
  vector<cv::Mat> output            ;

  cv::split(lab, lightness_values) ;
  cv::split(frame, output) ;

  output[0]=lightness_values[0] ;
  output[1]=lightness_values[0] ;
  output[2]=lightness_values[0] ;


  cv::merge(output, result) ;

}

void get_brightness_image(const cv::Mat &frame, cv::Mat &result) {

  /** @NOTE: unused in the program Edip. **/

  /** Get an image representation of the brighness as a grayscale image. **/

  cv::Mat hsv ;

  cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV) ;

  vector<cv::Mat> brighness_values  ;
  vector<cv::Mat> output            ;

  cv::split(hsv, brighness_values) ;
  cv::split(frame, output) ;

  output[0]=brighness_values[2] ;
  output[1]=brighness_values[2] ;
  output[2]=brighness_values[2] ;


  cv::merge(output, result) ;

}


void get_hue_image(const cv::Mat &frame, cv::Mat &result) {

  /** @NOTE: unused in the program Edip. **/

  /** Get an image representation of the hue as a grayscale image. **/

  cv::Mat hsv ;

  cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV) ;

  vector<cv::Mat> hue_values  ;
  vector<cv::Mat> output      ;

  cv::split(hsv, hue_values) ;
  cv::split(frame, output) ;

  output[0]=hue_values[0] ;
  output[1]=hue_values[0] ;
  output[2]=hue_values[0] ;

  cv::merge(output, result) ;

}

void get_saturation_image(const cv::Mat &frame, cv::Mat &result) {

  /** @NOTE: unused in the program Edip. **/

  /** Get an image representation of the saturation as a grayscale image. **/

  cv::Mat hsv ;

  cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV) ;

  vector<cv::Mat> saturation_values  ;
  vector<cv::Mat> output             ;

  cv::split(hsv, saturation_values) ;
  cv::split(frame, output) ;

  output[0]=saturation_values[1] ;
  output[1]=saturation_values[1] ;
  output[2]=saturation_values[1] ;

  cv::merge(output, result) ;

}




