#ifndef LIBEDIP_CONVOLUTION_KERNEL_APPLY_HH
#define LIBEDIP_CONVOLUTION_KERNEL_APPLY_HH

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

//#include <opencv2/opencv.hpp>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>
#include <string>

using namespace std ;

template <typename T>
void _make_kernel(cv::Mat &kernel, const string kernel_type, const int ksize, const char center_value, const float factor) ;

cv::Mat make_kernel(const string kernel_type="rect", const int ksize=3, const char center_value = '1', const float factor = 1.0f, const int datatypes = CV_8U) ;

class Kernels {

  public :

    float counter = 0 ;

    float main_matrix_factor = 1.0f ; // Final factor for the matrix center weight in most case is better to let it be 1.0f because all matrix take a second factor parameter which influente of all the matrix
                                      // not only the matrix center like this parameter.
                              
    int8_t matrix_sign = 0 ;          // Will determinate the final sign of the matrix, the matrix value summe sign.
                                      // I think that zero as sign make sense here because the weight can be equal to zero.
                                      // Which is an important value (sign) for the result of the matrix applying of an image: It can change the result radically.

    int kernel_size ;

    float matrix_values_factor ;

    cv::Mat kernel ;


    Kernels(const int ksize, const char main_matrix_sign, const float main_matrix_weight_factor, const float factor) ;


    void apply(const cv::Mat &frame, cv::Mat &result, bool invert=false) { cv::filter2D(frame, result, frame.depth(), kernel) ; if (invert) { bitwise_not(result, result) ; }  } ;

    void kernel_print(const uint8_t prec=3) ;

    void fill(const float val) { for (int c=0 ; c < kernel_size ; c++) { for (int cc=0 ; cc < kernel_size ; cc++) { kernel.at<float>(c,cc) = val ; } } } ;

    inline const float get_weight() const ;

    inline void normalize(const float weight) ;

    inline void negalize() ;

    inline void zeroing() ;

    inline void compute_matrix_weight() ;

    inline int8_t get_matrix_sign() const ;
} ;

class Sharpen : public Kernels {

  /** The Sharpen matrix is composed from the following default values:
    *
    *     -1 -1 -1
    *     -1  9 -1
    *     -1 -1 -1
    *
    *  Sharpen matrix type.
    *
    *******************************************************************/

  /** Note: the Sharpen and the Find_Edges matrix are the same: same values except
    *       the center which determine the total weight of the matrix, which differ.
    *
    *       The default argument value is different in the 2 matrix: that's all.
    ********************************************************************************/       


  private :

    const string kernel_type ;

  public :

    Sharpen(const int ksize, const string kernel_sort="rect", const float factor = 1.0f, const char main_matrix_sign='+', const float main_matrix_weight_factor = 1.0f) ;

} ;


class Find_Edges : public Kernels {

  /** The Sharpen matrix is composed from the following default values:
    *
    *     -1 -1 -1
    *     -1  8 -1
    *     -1 -1 -1
    *
    *  Find Edges matrix type.
    *
    *******************************************************************/

  /** Note: the Sharpen and the Find_Edges matrix are the same: same values except
    *       the center which determine the total weight of the matrix, which differ.
    *
    *       The default argument value is different in the 2 matrix: that's all.
    ********************************************************************************/    

  public :

    Find_Edges(const int ksize, const string kernel_sort="rect", const float factor = 1.0f, const char main_matrix_sign='0', const float main_matrix_weight_factor = 1.0f) ;

} ;


class Emboss : public Kernels {

  /** For Emboss Kernels:

    If the matrix values sum equal 1.

      can be an making looking older filter.

      ! IDEA: Must detected faces...

    Else if the matrix values sum equal 0.

      very dark emboss result.

    Note: this doesn't really make sens because the matrix aplying doesn't result in an emboss filter.

  */

  public :

    Emboss(const int ksize, const float factor = 1.0f, const char main_matrix_sign='+', const float main_matrix_weight_factor = 1.0f) ;

} ;


class Mean : public Kernels {

  /** The Mean matrix is composed from the following default values:
    *
    *     1.0/9 1.0/9 1.0/9
    *     1.0/9 1.0/9 1.0/9
    *     1.0/9 1.0/9 1.0/9
    *
    *  Mean matrix type: all value are equal.
    *
    *  This is a blurring effect matrix.
    *
    ***************************************************************/

  private :

    const string kernel_type ;

  public :

    Mean(const int ksize, const string kernel_sort="rect") ;

} ;


class Gaussian : public Kernels {

  /** The Gaussian matrix is composed from an gaussian vector values:
    *
    * @NOTE: Maybe i invented this matrix type like i implement it.
    *
    ***************************************************************/

  private :

    const string kernel_type ;

  public :

    Gaussian(const int ksize, const double sigma=1.2, const string kernel_sort="rect", const char main_matrix_sign='r') ;

} ;


class Kirsch : public Kernels {

  /** The Kirsch matrix is composed from the following (example) values:
    *
    * East: -3 -3  5    West: 5 -3 -3    North:  5  5  5    Sud:  -3 -3 -3
    *       -3  0  5          5  0 -3           -3  0 -3          -3  0 -3
    *       -3 -3  5          5 -3 -3           -3 -3 -3           5  5  5
    *
    *  Find Edges matrix type.
    *
    *******************************************************************/

  /** The Kirsch matrix major purpose is form detection preparation.
    *
    * Named as compass operator.
    *
    * Which mesure the gradient in a given direction (N, S, E, W).
    *
    * @USAGE: use the 4 directions and add the results each divided by 4.
    *
    ********************************************************************/

  public :

    Kirsch(const int ksize, const string direction, const float factor=1.0f) ;

} ;

#endif









