
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

#include "operations.hpp"


void flipping(const cv::Mat &frame, cv::Mat &result, int8_t flip_code) {

  /** @param flip_code = -1 on the X-axe.
      @param flip_code =  1 on the Y-axe.
      @param flip_code =  0 both axes.
  */

  cv::flip(frame, result, (flip_code == -1) ? 1 : (flip_code == 1) ? 0 : -1 ) ;
}

void rotate(const cv::Mat &frame, cv::Mat &result, double angle, double scale, cv::Point2f center, int border_type) {

  /** Rotate the frame from angle degrees with scaling it from scale from the point center. **/

  if (center.x < 0 || center.y < 0) {
    center = cv::Point2f(static_cast<float>(frame.cols) / 2.0f, static_cast<float>(frame.rows) / 2.0f) ;
  }

  cv::Mat rot_matrix = cv::getRotationMatrix2D(center, angle, scale) ;

  cv::warpAffine(frame, result, rot_matrix, cv::Size(frame.cols, frame.rows), cv::INTER_CUBIC, border_type) ;

}

void zoom(const cv::Mat &frame, cv::Mat &result, cv::Point2f center, double factor) {

  /** Zoom onto the frame in direction from the point @center with scaling factor @factor. **/

  cv::Mat rot_matrix = cv::getRotationMatrix2D(center, 0.0, factor) ;

  cv::warpAffine(frame, result, rot_matrix, cv::Size(frame.cols, frame.rows), cv::INTER_CUBIC) ;

}

void rotate_90_right(const cv::Mat &frame, cv::Mat &result) {

  /** Rotate the frame from 90° to the right by copying pixels at the right place. **/

  cv::Mat tmp(frame.cols, frame.rows, (frame.channels() == 4) ? CV_8UC4 : CV_8UC3)  ;


  for (int r= 0 ; r < frame.rows ; r++) {

     for (int c=1 ; c <= frame.cols ; c++) {

       switch (frame.channels()) {

        case 3 :
          tmp.at<cv::Vec3b>(frame.cols-c, r) = frame.at<cv::Vec3b>(r, c-1) ;
          break ;
        case 4 :
          tmp.at<cv::Vec4b>(frame.cols-c, r) = frame.at<cv::Vec4b>(r, c-1) ;
          break ;
        default :
          fprintf(stderr,"%s() must take a frame from 3 | 4 channels.\n", __func__) ;
          return ;
      }

     }
  }

  result = tmp ;

}

void rotate_90_left(const cv::Mat &frame, cv::Mat &result) {

  /** Rotate the frame from 90° to the left by copying pixels at the right place. **/

  cv::Mat tmp(frame.cols, frame.rows, (frame.channels() == 4) ? CV_8UC4 : CV_8UC3)  ;

  for (int r= 1 ; r <= frame.rows ; r++) {

     for (int c=0 ; c < frame.cols ; c++) {

      switch (frame.channels()) {

        case 3 :
          tmp.at<cv::Vec3b>(c, frame.rows-r) = frame.at<cv::Vec3b>(r-1,c) ;
          break ;
        case 4 :
          tmp.at<cv::Vec4b>(c, frame.rows-r) = frame.at<cv::Vec4b>(r-1,c) ;
          break ;
        default :
          fprintf(stderr,"%s() must take a frame from 3 | 4 channels.\n", __func__) ;
          return ;
          
      }
  


     }

  }

  result = tmp ;

}

void mirror_vertical_right(const cv::Mat &frame, cv::Mat &result) {

  /** Copy the right side from the frame over the left side from the frame. **/

  cv::Mat tmp(frame.rows, frame.cols, (frame.channels() == 4) ? CV_8UC4 : CV_8UC3)  ;

  for (int r=0 ; r < frame.rows ; r++) {

     for (int c=0 ; c < frame.cols/2 ; c++) {

      switch (frame.channels()) {

        case 3 :
          tmp.at<cv::Vec3b>(r, c) = frame.at<cv::Vec3b>(r, frame.cols-1-c) ;
          break ;
        case 4 :
          tmp.at<cv::Vec4b>(r, c) = frame.at<cv::Vec4b>(r, frame.cols-1-c) ;
          break ;
        default :
          fprintf(stderr,"%s() must take a frame from 3 | 4 channels.\n", __func__) ;
          return ;
      }
    }
    for (int c=frame.cols/2 ; c < frame.cols ; c++) {
      switch (frame.channels()) {

        case 3 :
          tmp.at<cv::Vec3b>(r, c) = frame.at<cv::Vec3b>(r, c) ;
          break ;
        case 4 :
          tmp.at<cv::Vec4b>(r, c) = frame.at<cv::Vec4b>(r, c) ;
          break ;
        default :
          fprintf(stderr,"%s() must take a frame from 3 | 4 channels.\n", __func__) ;
          return ;
      }
    }



  }

  result = tmp ;

}

void mirror_vertical_left(const cv::Mat &frame, cv::Mat &result) {

  /** Copy the left side from the frame over the right side from the frame. **/

  cv::Mat tmp(frame.rows, frame.cols, (frame.channels() == 4) ? CV_8UC4 : CV_8UC3)  ;

  for (int r=0 ; r < frame.rows ; r++) {

     for (int c=frame.cols/2  ; c < frame.cols ; c++) {

      switch (frame.channels()) {

        case 3 :
          tmp.at<cv::Vec3b>(r, c) = frame.at<cv::Vec3b>(r, frame.cols-1-c) ;
          break ;
        case 4 :
          tmp.at<cv::Vec4b>(r, c) = frame.at<cv::Vec4b>(r, frame.cols-1-c) ;
          break ;
        default :
          fprintf(stderr,"%s() must take a frame from 3 | 4 channels.\n", __func__) ;
          return ;
      }
    }
    for (int c=0 ; c < frame.cols/2 ; c++) {
      switch (frame.channels()) {

        case 3 :
          tmp.at<cv::Vec3b>(r, c) = frame.at<cv::Vec3b>(r, c) ;
          break ;
        case 4 :
          tmp.at<cv::Vec4b>(r, c) = frame.at<cv::Vec4b>(r, c) ;
          break ;
        default :
          fprintf(stderr,"%s() must take a frame from 3 | 4 channels.\n", __func__) ;
          return ;
      }
    }



  }

  result = tmp ;

}

void mirror_horizontal_bottom(const cv::Mat &frame, cv::Mat &result) {

  /** Copy the bottom side from the frame over the upper side from the frame. **/

  cv::Mat tmp(frame.rows, frame.cols, (frame.channels() == 4) ? CV_8UC4 : CV_8UC3)  ;

   for (int c=0 ; c < frame.cols ; c++) {

    for (int r=0 ; r < frame.rows/2 ; r++) {

      switch (frame.channels()) {

        case 3 :
          tmp.at<cv::Vec3b>(r, c) = frame.at<cv::Vec3b>(frame.rows-1-r, c) ;
          break ;
        case 4 :
          tmp.at<cv::Vec4b>(r, c) = frame.at<cv::Vec4b>(frame.rows-1-r, c) ;
          break ;
        default :
          fprintf(stderr,"%s() must take a frame from 3 | 4 channels.\n", __func__) ;
          return ;
      }
    }
    for (int r=frame.rows/2 ; r < frame.rows ; r++) {

      switch (frame.channels()) {

        case 3 :
          tmp.at<cv::Vec3b>(r, c) = frame.at<cv::Vec3b>(r, c) ;
          break ;
        case 4 :
          tmp.at<cv::Vec4b>(r, c) = frame.at<cv::Vec4b>(r, c) ;
          break ;
        default :
          fprintf(stderr,"%s() must take a frame from 3 | 4 channels.\n", __func__) ;
          return ;
      }
    }
  }


  result = tmp ;

}

void mirror_horizontal_top(const cv::Mat &frame, cv::Mat &result) {

  /** Copy the upper side from the frame over the bottom side from the frame. **/

  cv::Mat tmp(frame.rows, frame.cols, (frame.channels() == 4) ? CV_8UC4 : CV_8UC3)  ;

  for (int c=0 ; c < frame.cols ; c++) {

    for (int r=frame.rows/2 ; r < frame.rows ; r++) {

      switch (frame.channels()) {

        case 3 :
          tmp.at<cv::Vec3b>(r, c) = frame.at<cv::Vec3b>(frame.rows-1-r, c) ;
          break ;
        case 4 :
          tmp.at<cv::Vec4b>(r, c) = frame.at<cv::Vec4b>(frame.rows-1-r, c) ;
          break ;
        default :
          fprintf(stderr,"%s() must take a frame from 3 | 4 channels.\n", __func__) ;
          return ;
      }
    }
    for (int r=0 ; r < frame.rows/2 ; r++) {

      switch (frame.channels()) {

        case 3 :
          tmp.at<cv::Vec3b>(r, c) = frame.at<cv::Vec3b>(r, c) ;
          break ;
        case 4 :
          tmp.at<cv::Vec4b>(r, c) = frame.at<cv::Vec4b>(r, c) ;
          break ;
        default :
          fprintf(stderr,"%s() must take a frame from 3 | 4 channels.\n", __func__) ;
          return ;
      }
    }
  }


  result = tmp ;

}

