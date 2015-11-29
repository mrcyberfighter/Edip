#ifndef LIBEDIP_HLSV_FILTERS_HH
#define LIBEDIP_HLSV_FILTERS_HH

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

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

#include <string>
#include <vector>

using namespace std ;


/** Changing lightness, saturation, hue and brightness functions. **/

void change_lightness(const cv::Mat &frame, cv::Mat &result, float lightness=1.0) ;

void change_saturation(const cv::Mat &frame, cv::Mat &result, float saturation=1.0) ;

void change_hue(const cv::Mat &frame, cv::Mat &result, float hue=1.0) ;

void change_brightness(const cv::Mat &frame, cv::Mat &result, float brightness=1.0) ;


/** Getting image in gray representing the source image lightness, brightness, hue or saturation functions. **/

void get_lightness_image(const cv::Mat &frame, cv::Mat &result)   ;

void get_brightness_image(const cv::Mat &frame, cv::Mat &result)  ;

void get_hue_image(const cv::Mat &frame, cv::Mat &result)         ;

void get_saturation_image(const cv::Mat &frame, cv::Mat &result)  ;

#endif