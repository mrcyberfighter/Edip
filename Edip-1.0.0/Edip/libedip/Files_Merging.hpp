#ifndef LIBEDIP_FILE_MERGING_HH
#define LIBEDIP_FILE_MERGING_HH

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

inline void set_same_channels(cv::Mat &frame1, cv::Mat &frame2) ;

inline int convert_to_U8(cv::Mat &frame) ;

void resize_to_same_size(cv::Mat &frame1, cv::Mat &frame2, cv::Size size = cv::Size(0,0)) ;

const uint8_t blend_images(cv::Mat frame1, cv::Mat frame2, cv::Mat &result, float alpha, cv::Size size = cv::Size(0, 0)) ;

const uint8_t screen_images(cv::Mat frame1, cv::Mat frame2, cv::Mat &result, cv::Size size = cv::Size(0, 0))     ;

const uint8_t darker_images(cv::Mat frame1, cv::Mat frame2, cv::Mat &result, cv::Size size = cv::Size(0, 0))     ;

const uint8_t lighter_images(cv::Mat frame1, cv::Mat frame2, cv::Mat &result, cv::Size size = cv::Size(0, 0))    ;

const uint8_t add_images(cv::Mat frame1, cv::Mat frame2, cv::Mat &result, const double scale, const double offset, cv::Size size = cv::Size(0, 0)) ;

const uint8_t add_modulo_images(cv::Mat frame1, cv::Mat frame2, cv::Mat &result, cv::Size size = cv::Size(0, 0)) ;

const uint8_t sub_images(cv::Mat frame1, cv::Mat frame2, cv::Mat &result, const double scale, const double offset, cv::Size size = cv::Size(0, 0)) ;

const uint8_t sub_modulo_images(cv::Mat frame1, cv::Mat frame2, cv::Mat &result, cv::Size size = cv::Size(0, 0)) ;

#endif