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

#include "Edip_functions.hpp"

void convert_image_to_gui_output_format(const cv::Mat frame, cv::Mat &result) {

  /** Convert input image to displaying format: RGB(A). **/

  if (frame.channels() > 3) {
    // There is an alpha channels.
    cv::cvtColor(frame, result, cv::COLOR_BGRA2RGBA) ;

  }
  else if (frame.channels() == 3) {
    // Normally BGR.
    cv::cvtColor(frame, result, cv::COLOR_BGR2RGB) ;

  }
  else if (frame.channels() == 1) {
    // Normally GRAY
    cv::cvtColor(frame, result, cv::COLOR_GRAY2RGB) ;

  }

}


void convert_image_to_process_format(const cv::Mat &frame, cv::Mat &result) {

  /** Convert from displaying format (RGB(A)) to processing format. **/

  if (frame.channels() > 3) {
    // There is an alpah channels.
    cv::cvtColor(frame, result, cv::COLOR_RGBA2BGRA) ;

  }
  else if (frame.channels() == 3) {
    // Normally BGR.
    cv::cvtColor(frame, result, cv::COLOR_RGB2BGR) ;

  }
  else if (frame.channels() == 1) {
    // Normally GRAY, NOT NEEDED !!!
    cv::cvtColor(frame, result, cv::COLOR_RGB2GRAY) ;

  }

}

cv::Point get_px_coords(int counter, int edges, double radius, cv::Point center, double offset) {

  /** Return the pixel position from the given angle **/

  double degrees  = 360.0/edges * counter + offset ;
  double to_rad   = degrees/180.0 * M_PI ;

  cv::Point ret(round(cos(to_rad) * radius + center.x), round(sin(to_rad) * radius + center.y) ) ;

  return ret ;

}



inline double get_distance_points(cv::Point point_1, cv::Point point_2) {

  /** Return distance between 2 points. **/

  return sqrt( pow(static_cast<double>(point_2.x)-static_cast<double>(point_1.x), 2) + pow(static_cast<double>(point_2.y)-static_cast<double>(point_1.y), 2) ) ;
}

inline cv::Point get_middle_point_from_segment(cv::Point start_point, double length, double angle) {

  /** Return the middle point from an segment. **/

  double degrees = 360.0 + angle ;

  double rad     = degrees / 180.0 * M_PI ;

  return cv::Point(cos(rad) * length + start_point.x, sin(rad) * length + start_point.y) ;
}

inline void generate_strikethrough_polygon(vector<cv::Point> polygon, cv::Point center, vector<cv::Point> &result) {

  /** Generate a strikethrough polygon. **/

  int i = 0 ;

  while ( i < static_cast<int>(polygon.size()) ) {

    if ( i+1 == static_cast<int>(polygon.size()) ) {

      result.push_back(polygon.at(0)) ;
    }
    else {

      result.push_back(polygon.at(i+1)) ;
    }

    result.push_back(center) ;

    result.push_back(polygon.at(i)) ;

    if ( i+1 == static_cast<int>(polygon.size()) ) {

      result.push_back(polygon.at(0)) ;
    }
    else {

      result.push_back(polygon.at(i+1)) ;
    }

    i++ ;
 }

}



inline void generate_polygon_star(vector<cv::Point> polygon, cv::Point center, vector<cv::Point> &result) {

  /** Generate a polygon star. **/

  int i = 0 ;

  while ( i < static_cast<int>(polygon.size()) ) {


    result.push_back(polygon.at(i)) ;
    result.push_back(center)          ;

    i++ ;

  }

}





inline void generate_polygon_flower_star(vector<cv::Point> polygon_1, vector<cv::Point> polygon_2, cv::Point center, vector<cv::Point> &result) {

  /** Generate a polygon flower star.: a star strikethrough looking like a flower. **/

  int i = 0 ;

  while ( i < static_cast<int>(polygon_1.size()) ) {

    result.push_back(center) ;

    result.push_back(polygon_1.at(i)) ;

    result.push_back(polygon_2.at(i)) ;

    if ( i+1 == static_cast<int>(polygon_1.size()) ) {

      result.push_back(polygon_1.at(0)) ;
    }
    else {

      result.push_back(polygon_1.at(i+1)) ;
    }

    i++ ;

  }

}

inline void generate_strikethrough_star(vector<cv::Point> polygon_1, vector<cv::Point> polygon_2, cv::Point center, vector<cv::Point> &result) {

  /** Generate a strikethrough star. **/

  int i = 0 ;

  while ( i < static_cast<int>(polygon_1.size()) ) {

    result.push_back(polygon_1.at(i)) ;

    if ( (i+1) == static_cast<int>(polygon_1.size()) ) {

      result.push_back(polygon_1.at(0)) ;
    }
    else {

      result.push_back(polygon_1.at(i+1)) ;
    }

    result.push_back(center) ;

    result.push_back(polygon_1.at(i)) ;
    result.push_back(polygon_2.at(i)) ;

    if ( i+1 == static_cast<int>(polygon_1.size()) ) {

      result.push_back(polygon_1.at(0)) ;
    }
    else {

      result.push_back(polygon_1.at(i+1)) ;
    }

    i++ ;

  }
}



inline void generate_normal_star(vector<cv::Point> polygon_1, vector<cv::Point> polygon_2, cv::Point center, vector<cv::Point> &result) {

  /** Generate a normal star. **/

  int i = 0 ;

  while ( i < static_cast<int>(polygon_1.size()) ) {

    result.push_back(polygon_1.at(i)) ;
    result.push_back(polygon_2.at(i)) ;

    i++ ;

  }

}


void generate_polygon(int edges, double radius, cv::Point center, vector<cv::Point> &result, bool strikethrough = false, bool stroke_star = false, double offset = 0.0 )  {

  /** Main polygon generation function. **/

  int i=0 ;
  while (i < edges) {

    result.push_back( get_px_coords(i+1, edges, radius, center, offset) ) ;

    i++ ;

  }

  vector<cv::Point> tmp ;

  if (strikethrough) { generate_strikethrough_polygon(result, center, tmp) ; result = tmp ; return ; }

  if (stroke_star)   { generate_polygon_star(result, center, tmp) ; result = tmp ; return ; }


}

void generate_star(int spikes, double radius, cv::Point center,  vector<cv::Point> &result, bool strikethrough = false, bool flower = false, double offset = 0.0) {

  /** Main star generation function. **/

  vector<cv::Point> polygon_1 ;

  generate_polygon(spikes, radius, center, polygon_1, false, false, offset) ;


  double side_length    = get_distance_points(polygon_1.at(0), polygon_1.at(1)) ;

  cv::Point side_middle = get_middle_point_from_segment(polygon_1.at(0), side_length / 2.0, offset + ((360.0/spikes) / 2.0) + (360.0/spikes) + 90.0 ) ;

  double half_length    = get_distance_points(center, side_middle) ;


  vector<cv::Point> polygon_2 ;

  generate_polygon(spikes, half_length * 2.0, center, polygon_2, false, false, ((360.0/spikes)/2.0)+offset ) ;

  if (strikethrough) { generate_strikethrough_star(polygon_1, polygon_2, center, result)  ; return ; }
  else if (flower)   { generate_polygon_flower_star(polygon_1, polygon_2, center, result) ; return ; }
  else               { generate_normal_star(polygon_1, polygon_2, center, result)         ; return ; }


}


void generate_pentagram(double radius, cv::Point center, vector<cv::Point> &result, bool strikethrough = false, bool flower = false, double offset = 0.0) {

  /** Main pentagram generation function. **/

  vector<cv::Point> polygon_1 ;

  generate_polygon(5, radius, center, polygon_1, false, false, offset) ;


  double side_length    = get_distance_points(polygon_1.at(0), polygon_1.at(1)) ;

  cv::Point side_middle = get_middle_point_from_segment(polygon_1.at(0), side_length / 2.0, offset + ((360.0/5.0) / 2.0) + (360.0/5.0) + 90.0 ) ;

  double half_length    = get_distance_points(center, side_middle) ;


  vector<cv::Point> polygon_2 ;

  generate_polygon(5, radius+(half_length*2.0), center, polygon_2, false, false, ((360.0/5.0) / 2.0) + offset ) ;

  if (strikethrough) { generate_strikethrough_star(polygon_1, polygon_2, center, result)  ; return ; }
  else if (flower)   { generate_polygon_flower_star(polygon_1, polygon_2, center, result) ; return ; }
  else               { generate_normal_star(polygon_1, polygon_2, center, result)         ; return ; }


}



void generate_hexagram(double radius, cv::Point center, vector<cv::Point> &result, bool strikethrough = false, bool flower = false, double offset = 0.0) {

  /** Main hexagram generation function. **/

  vector<cv::Point> polygon_1 ;

  generate_polygon(6, radius, center, polygon_1, false, false, offset) ;

  double side_length    = get_distance_points(polygon_1.at(0), polygon_1.at(1)) ;

  cv::Point side_middle = get_middle_point_from_segment(polygon_1.at(0), side_length / 2.0, offset + ((360.0/6.0) / 2.0) + (360.0/6.0)  + 90.0  ) ;

  double half_length    = get_distance_points(center, side_middle) ;


  vector<cv::Point> polygon_2 ;

  generate_polygon(6, half_length*2.0, center, polygon_2, false, false, ((360.0/6.0) / 2.0) + offset ) ;

  if (strikethrough) { generate_strikethrough_star(polygon_1, polygon_2, center, result)  ; return ; }
  else if (flower)   { generate_polygon_flower_star(polygon_1, polygon_2, center, result) ; return ; }
  else               { generate_normal_star(polygon_1, polygon_2, center, result)         ; return ; }

}

