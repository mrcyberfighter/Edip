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

#include "drawning.hpp"

void draw_line(cv::Mat &result, const cv::Point pt1, const cv::Point pt2, const cv::Scalar color, const int16_t thickness, const int line_type) {

  cv::line(result, pt1, pt2, color, thickness, line_type) ;

  return ;

}

void draw_rect(cv::Mat &result, const cv::Rect rect, const cv::Scalar color, const int16_t thickness, const int line_type) {

  cv::rectangle(result, rect, color, thickness, line_type) ;

  return ;

}

void draw_circle(cv::Mat &result, const cv::Point center, const int radius, const cv::Scalar color, const int16_t thickness, const int line_type) {

  cv::circle(result, center, radius, color, thickness, line_type) ;

  return ;

}

void draw_ellipse(cv::Mat &result, const cv::RotatedRect box, const cv::Scalar color, const int16_t thickness, const int line_type) {

  cv::ellipse(result, box , color, thickness, line_type) ;

  return ;

}

void draw_ellipse2(cv::Mat &result,  cv::Point  center, cv::Size axe, double angle, const cv::Scalar color, const int16_t thickness, const int line_type) {

  cv::ellipse(result, center, axe, angle, 0.0, 360.0 , color, thickness, line_type) ;

  return ;

}

void draw_polylines(cv::Mat &result, vector<cv::Point> points, const bool is_closed, const bool fill, const cv::Scalar color,  const int16_t thickness, const int line_type) {

 if (! fill) {
  cv::polylines(result, points, is_closed, color , thickness, line_type) ;
 }
 else {

   vector<vector<cv::Point>> tmp ;

   tmp.push_back(points) ;

   cv::fillPoly(result, tmp, color , line_type) ;

 }

 return ;

}

void draw_text(cv::Mat &result, const string text, const cv::Point origin, int font_face, double font_scale, const cv::Scalar color, const int16_t thickness, const int line_type) {

  cv::putText(result, text, origin, font_face, font_scale, color, thickness, line_type) ;

  return ;

}

void draw_outlines_contours(const cv::Mat &frame, cv::Mat &result, int8_t compute_threshold, bool invert, cv::Scalar color, int thickness) {

  /** @NOTE: unused in the program Edip. **/

  /**  This function has for goal to detect the external outlines contours edges and to display it.
    *  but it can be extend to detect all edges and to display it.
    *
    *   As problem the black background and the black strokes (maybe Canny() is better for this strokes case).
    *   It shine that the black bits are the problem: don't invert them (by don't use of bitwise_not())
    *   is a convienence solution which works sometimes in relationship to the the background color case.
    *
    *   Else you can invert the edges detection field by don't use of bitwise_not().
    *
    **********************************************************************************************************/


  cv::Mat tmp1 ;
  cv::Mat tmp2 ;

  cv::Mat tmp3 ;

  double threshold_value1  ;
  double threshold_value2  ;
  double threshold_value   ;

  cv::cvtColor(frame, tmp1, cv::COLOR_BGR2GRAY) ;

  switch (compute_threshold) {

    case -1 :
      // Magic threshold value auto-computing with the TRIANGLE algorithm.
      threshold_value = cv::threshold(tmp1, tmp2, 127, 255, cv::THRESH_TRIANGLE) ;
      fprintf(stdout,"%s threshold_value: %lf\n", __func__, threshold_value) ;
      break ;



    case 0 :
      // Magic threshold value auto-computing with the TRIANGLE and OTSU algorithm average.
      threshold_value1 = cv::threshold(tmp1, tmp3, 127, 255, cv::THRESH_TRIANGLE) ;
      threshold_value2 = cv::threshold(tmp1, tmp3, 127, 255, cv::THRESH_OTSU) ;
      threshold_value  = (threshold_value1 + threshold_value2) / 2.0 ;
      fprintf(stdout,"%s threshold_value: %lf + %lf == %lf \n", __func__, threshold_value1, threshold_value2, threshold_value) ;
      cv::threshold(tmp1, tmp2, threshold_value, 255, cv::THRESH_BINARY) ;
      break ;

    case 1 :
      // Magic threshold value auto-computing with the OTSU algorithm.
      threshold_value = cv::threshold(tmp1, tmp2, 127, 255, cv::THRESH_OTSU) ;
      fprintf(stdout,"%s threshold_value: %lf\n", __func__, threshold_value) ;
      break ;

    default :

      /** Better raise an exception. **/
      fprintf(stderr,"Wrong arg func: %s(..., compute_threshold = -1 | 0 | 1) ;\n", __func__) ;
      result = frame ;
      return ;
  }




  if (invert) {

    bitwise_not(tmp2, tmp2) ;  // This will invert the detection field but concrete invert the entire binary image (map).
                               // And combine to the morphologyEx() func include severals edges.
                               // (Inluding the inner edges of the wanted external outlines contours).
  }



  /*
  result = tmp2 ;  // Simply uncomment to sea the binary image.
  return ;
  */



  vector<vector<cv::Point>>  contours  ;
  vector<cv::Vec4i>          hierarchy ;

  cv::findContours(tmp2, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE) ; // cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE ;

  if ( contours.empty() ) {
    fprintf(stderr,"%s() contours detection failed !!!\n", __func__) ;

    result = frame ;

    return ;
  }
  else {
    fprintf(stdout,"%s() %lu contours detected !\n", __func__, contours.size() ) ;
  }

  // Draw contours.
  int idx = 0;
  for( ; idx >= 0; idx = hierarchy[idx][0] ){
    cv::drawContours( result, contours, idx, color, thickness, 8, hierarchy, 0);
  }


}

