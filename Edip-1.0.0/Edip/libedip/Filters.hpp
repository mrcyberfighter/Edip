#ifndef LIBEDIP_MAIN_FILTERS_HH
#define LIBEDIP_MAIN_FILTERS_HH

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


/** morphological functions wrapper functions for cv functions with default values **/

void erode_filter(const cv::Mat &frame, cv::Mat &result, cv::Mat kernel = cv::Mat(), int iterations = 1)  ;

void dilate_filter(const cv::Mat &frame, cv::Mat &result, cv::Mat kernel = cv::Mat(), int iterations = 1) ;

void morphological_filter(const cv::Mat &frame, cv::Mat &result, int op = cv::MORPH_GRADIENT, cv::Mat kernel = cv::Mat(), int iterations = 1) ;


/** blurring filters wrapper functions for cv functions with default values. */

void blur_filter(const cv::Mat &frame, cv::Mat &result, cv::Size ksize = cv::Size(3, 3))   ;

void median_blur_filter(const cv::Mat &frame, cv::Mat &result, int ksize = 5) ;

void gaussian_blur_filter(const cv::Mat &frame, cv::Mat &result, cv::Size ksize = cv::Size(5, 5), double sigma_X = 0, double sigma_Y = 0) ;


/** derivatives and secondary derivatives wrapper functions for cv functions with default values **/

void sobel_filter(const cv::Mat &frame, cv::Mat &result, int x_order=1, int y_order=1, int ksize = 3, int output_depth = CV_8U, double scale =1.0, double delta = 0) ;

void scharr_filter(const cv::Mat &frame, cv::Mat &result, int x_order=1, int y_order=1, int ksize = 3, int output_depth = CV_8U, double scale =1.0, double delta = 0) ;

void laplacian_filter(const cv::Mat &frame, cv::Mat &result, int ksize = 1, int output_depth = CV_8U, double scale = 1.0, double delta = 0) ;


/** Sobel operator based filters functions. **/

void sobel_drawning(const cv::Mat &frame, cv::Mat &result, int ksize=3, bool to_gray=true, int8_t bg_color=-1) ;

void sobel_emboss(const cv::Mat &frame, cv::Mat &result, int ksize=3) ;


/** Laplacian operator based filters functions. **/

void laplacian_emboss(const cv::Mat &frame, cv::Mat &result, int ksize = 3)   ;

void laplacian_zero_crossing(const cv::Mat &frame, cv::Mat &result, int ksize = 7, bool invert=false) ;


/** Other filters. **/

void stroke_edges(const cv::Mat &frame, cv::Mat &result, int median_blur_ksize = 7, int laplacian_ksize = 5) ;

void wave(const cv::Mat &frame, cv::Mat &result, int8_t sens=0) ;

/** Bits inverting (with RGBA support). **/

void invert_bits(const cv::Mat &frame, cv::Mat &result) ;

#endif