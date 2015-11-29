#ifndef EDIP_HELPER_FUNCTIONS_HH
#define EDIP_HELPER_FUNCTIONS_HH

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

#include <vector>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std ;

void convert_image_to_gui_output_format(const cv::Mat frame, cv::Mat &result) ;

void convert_image_to_process_format(const cv::Mat frame, cv::Mat &result) ;

cv::Point get_px_coords(int counter, int edges, double radius, cv::Point center, double offset) ;

inline double get_distance_points(cv::Point point_1, cv::Point point_2) ;

inline cv::Point get_middle_point_from_segment(cv::Point start_point, double length, double angle) ;

inline void generate_strikethrough_polygon(vector<cv::Point> polygon, cv::Point center, vector<cv::Point> &result) ;

inline void generate_polygon_star(vector<cv::Point> polygon, cv::Point center, vector<cv::Point> &result) ;

inline void generate_polygon_flower_star(vector<cv::Point> polygon_1, vector<cv::Point> polygon_2, cv::Point center, vector<cv::Point> &result) ;

inline void generate_strikethrough_star(vector<cv::Point> polygon_1, vector<cv::Point> polygon_2, cv::Point center, vector<cv::Point> &result) ;

void generate_polygon(int edges, double radius, cv::Point center, vector<cv::Point> &result, bool strikethrough, bool stroke_star, double offset) ;

void generate_star(int spikes, double radius, cv::Point center,  vector<cv::Point> &result, bool strikethrough, bool flower, double offset) ;

void generate_pentagram(double radius, cv::Point center, vector<cv::Point> &result, bool strikethrough, bool flower, double offset) ;

void generate_hexagram(double radius, cv::Point center, vector<cv::Point> &result, bool strikethrough, bool flower, double offset) ;

#endif