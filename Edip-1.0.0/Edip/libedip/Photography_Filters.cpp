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


#include "Photography_Filters.hpp"


/** Computational Photography */

void denoising_filter(const cv::Mat &frame, cv::Mat &result, const float filter_strengh, const float filter_color_strengh) {

  /** Perform image denoising using Non-local Means Denoising algorith with several computational optimizations.
    *
    * Noise expected to be a gaussian white noise.
    *
    * The function converts image to CIELAB colorspace and then separately denoise L and AB components
    * with given h parameters using fastNlMeansDenoising function.
    *
    *************************************************************************************************************/

  cv::Mat tmp(frame.size(), CV_8UC3)  ;

  if (frame.channels() == 4) {

    vector<cv::Mat> channels ;
    vector<cv::Mat> rgb      ;

    cv::split(frame, channels) ;
    cv::split(tmp,   rgb      ) ;

    rgb[0] = channels[0] ;
    rgb[1] = channels[1] ;
    rgb[2] = channels[2] ;

    cv::merge(rgb, tmp) ;
  }
  else { tmp = frame ; }

  cv::Mat res ;

  cv::fastNlMeansDenoisingColored(tmp, res, filter_strengh, filter_color_strengh) ;

  if (frame.channels() == 4) {

    vector<cv::Mat> rgba ;
    vector<cv::Mat> rgb  ;

    cv::split(frame, rgba) ;
    cv::split(res,   rgb)  ;

    rgba[0] = rgb[0] ;
    rgba[1] = rgb[1] ;
    rgba[2] = rgb[2] ;

    cv:merge(rgba, result) ;

  }
  else { result = res ; }




}

void detail_enhance_filter(const cv::Mat &frame, cv::Mat &result, const float sigma_s, const float sigma_r) {

  /** This filter enhances the details of a particular image.  **/

  if (sigma_s < 0.0f || sigma_s > 200.0f ) {

    fprintf(stdout,"%s() sigma_s [0.0-200.0] argument out of range\n", __func__) ;
    result = frame ;
    return ;
  }
  if (sigma_r < 0.0f || sigma_r > 1.0f ) {

    fprintf(stdout,"%s() sigma_r [0.0-1.0] argument out of range\n", __func__) ;
    result = frame ;
    return ;
  }

  cv::Mat tmp(frame.size(), CV_8UC3)  ;

  if (frame.channels() == 4) {

    vector<cv::Mat> channels ;
    vector<cv::Mat> rgb      ;

    cv::split(frame, channels) ;
    cv::split(tmp,   rgb      ) ;

    rgb[0] = channels[0] ;
    rgb[1] = channels[1] ;
    rgb[2] = channels[2] ;

    cv::merge(rgb, tmp) ;
  }
  else { tmp = frame ; }

  cv::Mat res ;

  cv::detailEnhance(tmp, res, sigma_s, sigma_r) ;

  if (frame.channels() == 4) {

    vector<cv::Mat> rgba ;
    vector<cv::Mat> rgb  ;

    cv::split(frame, rgba) ;
    cv::split(res,   rgb)  ;

    rgba[0] = rgb[0] ;
    rgba[1] = rgb[1] ;
    rgba[2] = rgb[2] ;

    cv:merge(rgba, result) ;

  }
  else { result = res ; }

}


void edge_preserving_filter(const cv::Mat &frame, cv::Mat &result, const float sigma_s, const float sigma_r, int flags) {

  /** Filtering is the fundamental operation in image and video processing. Edge-preserving smoothing filters are used in many different applications **/

  if (sigma_s < 0.0f || sigma_s > 200.0f ) {


    fprintf(stdout,"%s() sigma_s argument out of range\n", __func__) ;

    result = frame ;

    return ;

  }
  if (sigma_r < 0.0f || sigma_r > 1.0f ) {
    fprintf(stdout,"%s() sigma_r argument out of range\n", __func__) ;

    result = frame ;

    return ;
  }


  cv::Mat tmp(frame.size(), CV_8UC3)  ;

  if (frame.channels() == 4) {

    vector<cv::Mat> channels ;
    vector<cv::Mat> rgb      ;

    cv::split(frame, channels) ;
    cv::split(tmp,   rgb      ) ;

    rgb[0] = channels[0] ;
    rgb[1] = channels[1] ;
    rgb[2] = channels[2] ;

    cv::merge(rgb, tmp) ;
  }
  else { tmp = frame ; }

  cv::Mat res ;

  cv::edgePreservingFilter(tmp, res, flags, sigma_s, sigma_r) ;

  if (frame.channels() == 4) {

    vector<cv::Mat> rgba ;
    vector<cv::Mat> rgb  ;

    cv::split(frame, rgba) ;
    cv::split(res,   rgb)  ;

    rgba[0] = rgb[0] ;
    rgba[1] = rgb[1] ;
    rgba[2] = rgb[2] ;

    cv:merge(rgba, result) ;

  }
  else { result = res ; }




}

void pencil_sketch_filter(const cv::Mat &frame, cv::Mat &result, const float sigma_s, const float sigma_r, const float shade_factor) {

  /** Pencil-like non-photorealistic line drawing. **/

  if (sigma_s < 0.0f || sigma_s > 200.0f ) {

    fprintf(stdout,"%s() sigma_s [0.0-200.0] argument out of range\n", __func__) ;
    result = frame ;
    return ;
  }
  if (sigma_r < 0.0f || sigma_r > 1.0f ) {

    fprintf(stdout,"%s() sigma_r [0.0-1.0] argument out of range\n", __func__) ;
    result = frame ;
    return ;
  }
  if (shade_factor < 0.0 || shade_factor > 0.1) {

    fprintf(stdout,"%s() shade_factor [0.0-0.1] argument out of range\n", __func__) ;
    result = frame ;
    return ;
  }


  cv::Mat tmp(frame.size(), CV_8UC3)  ;

  if (frame.channels() == 4) {

    vector<cv::Mat> channels ;
    vector<cv::Mat> rgb      ;

    cv::split(frame, channels) ;
    cv::split(tmp,   rgb      ) ;

    rgb[0] = channels[0] ;
    rgb[1] = channels[1] ;
    rgb[2] = channels[2] ;

    cv::merge(rgb, tmp) ;
  }
  else { tmp = frame ; }

  cv::Mat res ;

  cv::Mat gray ;

  cv::pencilSketch(tmp, gray, res, sigma_s, sigma_r, shade_factor) ;

  if (frame.channels() == 4) {

    vector<cv::Mat> rgba ;
    vector<cv::Mat> rgb  ;

    cv::split(frame, rgba) ;
    cv::split(res,   rgb)  ;

    rgba[0] = rgb[0] ;
    rgba[1] = rgb[1] ;
    rgba[2] = rgb[2] ;

    cv:merge(rgba, result) ;

  }
  else { result = res ; }

}

void stylisation_filter(const cv::Mat &frame, cv::Mat &result, const float sigma_s, const float sigma_r) {

  /** Stylization aims to produce digital imagery with a wide variety of effects not focused on photorealism.
    * Edge-aware filters are ideal for stylization, as they can abstract regions of low contrast while preserving, or enhancing, high-contrast features.
    *
    ****************************************************************************************************************************************************/
  if (sigma_s < 0.0f || sigma_s > 200.0f ) {

    fprintf(stdout,"%s() sigma_s [0.0-200.0] argument out of range\n", __func__) ;
    result = frame ;
    return ;
  }
  if (sigma_r < 0.0f || sigma_r > 1.0f ) {

    fprintf(stdout,"%s() sigma_r [0.0-1.0] argument out of range\n", __func__) ;
    result = frame ;
    return ;
  }


  cv::Mat tmp(frame.size(), CV_8UC3)  ;

  if (frame.channels() == 4) {

    vector<cv::Mat> channels ;
    vector<cv::Mat> rgb      ;

    cv::split(frame, channels) ;
    cv::split(tmp,   rgb      ) ;

    rgb[0] = channels[0] ;
    rgb[1] = channels[1] ;
    rgb[2] = channels[2] ;

    cv::merge(rgb, tmp) ;
  }
  else { tmp = frame ; }

  cv::Mat res ;

  cv::stylization(tmp, res, sigma_s, sigma_r) ;

  if (frame.channels() == 4) {

    vector<cv::Mat> rgba ;
    vector<cv::Mat> rgb  ;

    cv::split(frame, rgba) ;
    cv::split(res,   rgb)  ;

    rgba[0] = rgb[0] ;
    rgba[1] = rgb[1] ;
    rgba[2] = rgb[2] ;

    cv:merge(rgba, result) ;

  }
  else { result = res ; }




}