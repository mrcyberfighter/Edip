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

#include "Files_Merging.hpp"

inline void set_same_channels(cv::Mat &frame1, cv::Mat &frame2) {

  /** We suppose the images are encoded either in GRAY | BGR or BGRA. **/

  if ( frame1.channels() == frame2.channels() ) {

    return  ;

  }

  if (frame1.channels() == 1) {

    cv::cvtColor(frame2, frame2, (frame2.channels() == 3) ? cv::COLOR_BGR2GRAY : cv::COLOR_BGRA2GRAY) ;

    return  ;

  }
  if (frame2.channels() == 1) {

    cv::cvtColor(frame1, frame1, (frame1.channels() == 3) ? cv::COLOR_BGR2GRAY : cv::COLOR_BGRA2GRAY) ;

    return  ;

  }

  if (frame1.channels() == 3) {

    cv::cvtColor(frame1, frame1, cv::COLOR_BGR2BGRA) ;

    return  ;

  }

  if (frame2.channels() == 3) {

    cv::cvtColor(frame2, frame2, cv::COLOR_BGR2BGRA) ;

    return ;

  }

  #ifdef DEBUG
  fprintf(stderr,"Cannot convert frames into the same colorspace\n") ;
  #endif
 
  return ;

}



inline int convert_to_U8(cv::Mat &frame) {

  /** Convert input image into uint8_t encoding. **/

  if (frame.depth() == 3 || frame.depth() == 2 ) {

    // Input format CV_16S or CV_16U

    cv::Mat tmp(frame.size(), CV_8U) ;

    frame.convertTo(tmp, CV_8U, 1.0/256) ;

    frame = tmp ;

    return 0 ;

  }
  else if (frame.depth() == 5) {

    // Input format CV_32F

    cv::Mat tmp(frame.size(), CV_8U) ;

    frame.convertTo(tmp, CV_8U) ;

    frame = tmp ;

    return 0 ;

  }

  if (frame.depth() != 0) {
   
    #ifdef DEBUG
    fprintf(stderr,"Cannot convert input frame to uint8_t\n") ;
    #endif
  
    return 1 ;

  }

  return 0 ;

}



void resize_to_same_size(cv::Mat &frame1, cv::Mat &frame2, cv::Size size)  {

  if (size.width <= 0 || size.height <= 0) {

    const int size_factor_frame_1  = frame1.rows * frame1.cols ;

    const int size_factor_frame_2  = frame2.rows * frame2.cols ;

    if (size_factor_frame_1 > size_factor_frame_2) {

      // The 2 image must be from the same size.
      cv::resize(frame1, frame1, cv::Size(frame2.cols, frame2.rows), 1.0, 1.0, CV_INTER_AREA) ;

      return  ;

    }
    else if (size_factor_frame_1 < size_factor_frame_2) {

      // The 2 image must be from the same size.
      cv::resize(frame2, frame2, cv::Size(frame1.cols, frame1.rows), 1.0, 1.0, CV_INTER_AREA) ;

      return  ;

    }

  }
  else {

    cv::resize(frame1, frame1, size, 1.0, 1.0, CV_INTER_CUBIC) ;

    cv::resize(frame2, frame2, size, 1.0, 1.0, CV_INTER_CUBIC) ;

    return ;

  }

}




const uint8_t blend_images(cv::Mat frame1, cv::Mat frame2, cv::Mat &result, float alpha, cv::Size size) {

  /** Interpolate 2 images file with the constant alpha to generate an output image:
    *
    *     Result = Image1 * alpha - (1-alpha) * Image2
    *
    * The image are converted to the same size (to the littler image) was is required for blend operation.
    ******************************************************************************************************/

  if ((alpha > 1.0) || (alpha <= 0.0)) {

    fprintf(stderr,"%s() Wrong alpha value\nalpha [0.0-1.0]\n",__func__) ;
    return 1 ;
  }

  if (convert_to_U8(frame1) != 0) {

    return 1 ;
  }

  if (convert_to_U8(frame2) != 0) {

    return 1 ;
  }

  set_same_channels(frame1, frame2) ;

  resize_to_same_size(frame1, frame2, size) ;


  cv::addWeighted(frame1 * alpha, 1.0, (1.0-alpha) * frame2, 1.0, 0.0, result) ;

  return 0 ;

}

const uint8_t screen_images(cv::Mat frame1, cv::Mat frame2, cv::Mat &result, cv::Size size) {

  /** Superimpose two inverted images on the top of each other:
    *
    *   Result = MAX - ((MAX-Image1)  * (MAX-Images2) / MAX)
    *
    * The image are converted to the same size (to the littler image) was is required for screen operation.
    *******************************************************************************************************/

  if (convert_to_U8(frame1) != 0) {

    return 1 ;
  }

  if (convert_to_U8(frame2) != 0) {

    return 1 ;
  }

  set_same_channels(frame1, frame2) ;

  resize_to_same_size(frame1, frame2, size) ;


  cv::Mat max ;

  cv::max(frame1, frame2, max) ;

  cv::Mat tmp ;

  cv::multiply((max-frame1), (max-frame2), tmp) ;

  cv::divide(tmp, max, tmp) ;

  cv::subtract(max, tmp, result) ;

  return 0 ;

}

const uint8_t darker_images(cv::Mat frame1, cv::Mat frame2, cv::Mat &result, cv::Size size) {

  /** Interpolate 2 images file and produce an output image with the darkest pixels values:
    *
    *   Result = min( Image1, Image2 )
    *
    * The image are converted to the same size (to the littler image) was is required for darker operation.
    *******************************************************************************************************/


  if (convert_to_U8(frame1) != 0) {

    return 1 ;
  }

  if (convert_to_U8(frame2) != 0) {

    return 1 ;
  }

  set_same_channels(frame1, frame2) ;

  resize_to_same_size(frame1, frame2, size) ;

  cv::min(frame1, frame2, result) ;

  return 0 ;

}

const uint8_t lighter_images(cv::Mat frame1, cv::Mat frame2, cv::Mat &result, cv::Size size) {

  /** Interpolate 2 images file and produce an output image with the lightest pixels values:
    *
    *   Result = max( Image1, Image2 )
    *
    * The image are converted to the same size (to the littler image) was is required for lighter operation.
    ********************************************************************************************************/

  if (convert_to_U8(frame1) != 0) {

    return 1 ;
  }

  if (convert_to_U8(frame2) != 0) {

    return 1 ;
  }

  set_same_channels(frame1, frame2) ;

  resize_to_same_size(frame1, frame2, size) ;

  cv::max(frame1, frame2, result) ;

  return 0 ;

}

const uint8_t add_images(cv::Mat frame1, cv::Mat frame2, cv::Mat &result, const double scale, const double offset, cv::Size size) {

  /** Add 2 images, dividing the result by scale and adding offset to generate an output image:
    *
    *   Result = (Image1 + Image2) / scale + offset
    *
    * The image are converted to the same size (to the littler image) was is required for add operation.
    ****************************************************************************************************/

  if (scale > 8.0 || scale <= 0) {
    fprintf(stderr,"%s() Wrong scale argument value\nscale -> [0-8]\n", __func__) ;
    return 1 ;
  }

  if (offset < 0.0 || offset > 255.0) {
    fprintf(stderr,"%s() Wrong offset argument value\noffset -> [0-255]\n", __func__) ;
    return 1 ;
  }


  if (convert_to_U8(frame1) != 0) { return 1 ; }

  if (convert_to_U8(frame2) != 0) { return 1 ; }

  set_same_channels(frame1, frame2) ;

  resize_to_same_size(frame1, frame2, size) ;


  cv::Mat add ;

  cv::add(frame1, frame2, add) ;

  cv::Mat tmp ;

  cv::divide(add, scale, tmp) ;

  cv::add(tmp, offset, result) ;

  return 0 ;

}

const uint8_t add_modulo_images(cv::Mat frame1, cv::Mat frame2, cv::Mat &result, cv::Size size) {

  /** Add 2 images, without clipping the result
    *
    *   Result = (Image1 + Image2) % MAX
    *
    * The image are converted to the same size (to the littler image) was is required for add operation.
    ****************************************************************************************************/

  if (convert_to_U8(frame1) != 0) { return 1 ; }

  if (convert_to_U8(frame2) != 0) { return 1 ; }

  set_same_channels(frame1, frame2) ;

  resize_to_same_size(frame1, frame2, size) ;


  cv::Mat max ;

  cv::max(frame1, frame2, max) ;

  cv::Mat add ;

  cv::add(frame1, frame2, add) ;

  cv::Mat tmp = add ;

  for (int c=0 ; c < tmp.rows ; c++) {

    for (int cc=0 ; cc < tmp.cols ; cc++ ) {

      switch (tmp.channels()) {

        case 1 :
 
          if (max.at<uint8_t>(c,cc) != 0) {
            tmp.at<uint8_t>(c,cc) = tmp.at<uint8_t>(c,cc) % max.at<uint8_t>(c,cc) ;
          }
          break ;
 
        case 3 :
 
          if (max.at<cv::Vec3b>(c,cc)[0] != 0) {
            tmp.at<cv::Vec3b>(c,cc)[0]  = tmp.at<cv::Vec3b>(c,cc)[0] % max.at<cv::Vec3b>(c,cc)[0] ;
          }
          if (max.at<cv::Vec3b>(c,cc)[1] != 0) {
            tmp.at<cv::Vec3b>(c,cc)[1]  = tmp.at<cv::Vec3b>(c,cc)[1] % max.at<cv::Vec3b>(c,cc)[1] ;
          }
          if (max.at<cv::Vec3b>(c,cc)[2] != 0) {
           tmp.at<cv::Vec3b>(c,cc)[2]  = tmp.at<cv::Vec3b>(c,cc)[2] % max.at<cv::Vec3b>(c,cc)[2] ;
          }
          break ;

        case 4 :
  
          if (max.at<cv::Vec3b>(c,cc)[0] != 0) {
            tmp.at<cv::Vec3b>(c,cc)[0]  = tmp.at<cv::Vec3b>(c,cc)[0] % max.at<cv::Vec3b>(c,cc)[0] ;
          }
          if (max.at<cv::Vec3b>(c,cc)[1] != 0) {
            tmp.at<cv::Vec3b>(c,cc)[1]  = tmp.at<cv::Vec3b>(c,cc)[1] % max.at<cv::Vec3b>(c,cc)[1] ;
          }
          if (max.at<cv::Vec3b>(c,cc)[2] != 0) {
           tmp.at<cv::Vec3b>(c,cc)[2]  = tmp.at<cv::Vec3b>(c,cc)[2] % max.at<cv::Vec3b>(c,cc)[2] ;
          }
          if (max.at<cv::Vec3b>(c,cc)[3] != 0) {
           tmp.at<cv::Vec3b>(c,cc)[3]  = tmp.at<cv::Vec3b>(c,cc)[3] % max.at<cv::Vec3b>(c,cc)[3] ;
          }
          break ;
 
 
      }

    }

  }

  result = tmp ;

  return 0 ;

}

const uint8_t sub_images(cv::Mat frame1, cv::Mat frame2, cv::Mat &result, const double scale, const double offset, cv::Size size) {

  /** Substract 2 images, dividing the result by scale and adding offset to generate an output image:
    *
    *   Result = (Image1 - Image2) / scale + offset
    *
    * The image are converted to the same size (to the littler image) was is required for subtract operation.
    *********************************************************************************************************/

  if (scale > 8.0 || scale <= 0.0) {
    fprintf(stderr,"%s() Wrong scale argument value\nscale -> [0.0-8.0]\n", __func__) ;
    return 1 ;
  }

  if (offset < 0.0 || offset > 255.0) {
    fprintf(stderr,"%s() Wrong offset argument value\noffset -> [0.0-255.0]\n", __func__) ;
    return 1 ;
  }


  if (convert_to_U8(frame1) != 0) { return 1 ; }

  if (convert_to_U8(frame2) != 0) { return 1 ; }

  set_same_channels(frame1, frame2) ;

  resize_to_same_size(frame1, frame2, size) ;


  cv::Mat sub ;

  cv::subtract(frame1, frame2, sub) ;

  cv::Mat tmp ;

  cv::divide(sub, scale, tmp) ;

  cv::add(tmp, offset, result) ;

  return 0 ;

}

const uint8_t sub_modulo_images(cv::Mat frame1, cv::Mat frame2, cv::Mat &result, cv::Size size) {

  /** Substract 2 images, without clipping the result
    *
    *   Result = (Image1 - Image2) % MAX
    *
    * The image are converted to the same size (to the littler image) was is required for add operation.
    ****************************************************************************************************/

  if (convert_to_U8(frame1) != 0) { return 1 ; }

  if (convert_to_U8(frame2) != 0) { return 1 ; }

  set_same_channels(frame1, frame2) ;

  resize_to_same_size(frame1, frame2, size) ;


  cv::Mat max ;

  cv::max(frame1, frame2, max) ;

  cv::Mat sub ;

  cv::subtract(frame1, frame2, sub) ;

  cv::Mat tmp = sub ;

  for (int c=0 ; c < tmp.rows ; c++) {

    for (int cc=0 ; cc < tmp.cols ; cc++ ) {

      switch (tmp.channels()) {

        case 1 :
 
          if (max.at<uint8_t>(c,cc) != 0) {
            tmp.at<uint8_t>(c,cc) = tmp.at<uint8_t>(c,cc) % max.at<uint8_t>(c,cc) ;
          }
          break ;
 
        case 3 :
 
          if (max.at<cv::Vec3b>(c,cc)[0] != 0) {
            tmp.at<cv::Vec3b>(c,cc)[0]  = tmp.at<cv::Vec3b>(c,cc)[0] % max.at<cv::Vec3b>(c,cc)[0] ;
          }
          if (max.at<cv::Vec3b>(c,cc)[1] != 0) {
            tmp.at<cv::Vec3b>(c,cc)[1]  = tmp.at<cv::Vec3b>(c,cc)[1] % max.at<cv::Vec3b>(c,cc)[1] ;
          }
          if (max.at<cv::Vec3b>(c,cc)[2] != 0) {
           tmp.at<cv::Vec3b>(c,cc)[2]  = tmp.at<cv::Vec3b>(c,cc)[2] % max.at<cv::Vec3b>(c,cc)[2] ;
          }
          break ;
 
        case 4 :
  
          if (max.at<cv::Vec3b>(c,cc)[0] != 0) {
            tmp.at<cv::Vec3b>(c,cc)[0]  = tmp.at<cv::Vec3b>(c,cc)[0] % max.at<cv::Vec3b>(c,cc)[0] ;
          }
          if (max.at<cv::Vec3b>(c,cc)[1] != 0) {
            tmp.at<cv::Vec3b>(c,cc)[1]  = tmp.at<cv::Vec3b>(c,cc)[1] % max.at<cv::Vec3b>(c,cc)[1] ;
          }
          if (max.at<cv::Vec3b>(c,cc)[2] != 0) {
           tmp.at<cv::Vec3b>(c,cc)[2]  = tmp.at<cv::Vec3b>(c,cc)[2] % max.at<cv::Vec3b>(c,cc)[2] ;
          }
          if (max.at<cv::Vec3b>(c,cc)[3] != 0) {
           tmp.at<cv::Vec3b>(c,cc)[3]  = tmp.at<cv::Vec3b>(c,cc)[3] % max.at<cv::Vec3b>(c,cc)[3] ;
          }
          break ;
   

      }

    }

  }

  result = tmp ;

  return 0 ;

}

