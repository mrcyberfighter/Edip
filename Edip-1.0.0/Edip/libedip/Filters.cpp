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

#include "Filters.hpp"

/** morphological functions. **/

void erode_filter(const cv::Mat &frame, cv::Mat &result, cv::Mat kernel, int iterations) {

  /** The function erodes the source image using the specified structuring element that determines
    * the shape of a pixel neighborhood by minimizing.
    *
    * Eroding a binary image will decrease the white regions by eroding it's contours.
    *
    * You can apply this operator on an arbitrary channels value image.
    *
    * The kernel can be from the sort you want (cross, X, diamond, rect...).
    */

  cv::erode(frame, result, kernel, cv::Point(-1, -1), iterations) ;

}


void dilate_filter(const cv::Mat &frame, cv::Mat &result, cv::Mat kernel, int iterations ) {

  /** The function dilate the source image using the specified structuring element that determines
    * the shape of a pixel neighborhood by maximizing.
    *
    * Dilate a binary image will increase the white regions by dilating it's contours.
    *
    * You can apply this operator on an arbitrary channels value image.
    *
    * The kernel can be from the sort you want (cross, X, diamond, rect...).
    *
    **********************************************************************************************/

  cv::dilate(frame, result, kernel, cv::Point(-1, -1), iterations) ;
}

void morphological_filter(const cv::Mat &frame, cv::Mat &result, int op, cv::Mat kernel, int iterations) {

  /** Performs advanced morphological transformations.
    *
    * the @op argument define the type of operation, is represetn by a kernel type and can be :
    * -) MORPH_ERODE
    * -) MORPH_DILATE
    * -) MORPH_OPEN
    * -) MORPH_CLOSE
    * -) MORPH_GRADIENT
    * -) MORPH_TOPHAT
    * -) MORPH_BLACKHAT
    *******************************************************************************************/

  vector<cv::Mat> saved ;
  vector<cv::Mat> tmp_5 ;

  cv::split(frame, saved) ;

  cv::Mat tmp_res ;

  cv::morphologyEx(frame, tmp_res, op, kernel, cv::Point(-1,-1), iterations) ;

  vector<cv::Mat> channels ;

  cv::split(tmp_res, channels) ;

  saved[0] = channels[0] ;
  saved[1] = channels[1] ;
  saved[2] = channels[2] ;

  cv::merge(saved, result) ;

}




/** BLUR: blurring filters. */

void blur_filter(const cv::Mat &frame, cv::Mat &result, cv::Size ksize) {

  /** Blurs an image using the normalized box filter.
    * The function smoothes an image using the kernel.
    *
    **************************************************/

  cv::blur(frame, result, ksize) ;

}

void median_blur_filter(const cv::Mat &frame, cv::Mat &result, int ksize) {

  /** Blurs an image using the median filter.
    * The function smoothes an image using the median filter.
    * ksize must be odd and greater than 1, for example: 3, 5, 7 ...
    *
    *
    * Used to remove noises (salt and pepper) from images.
    * Because it's a median filter...
    *
    *****************************************************************/


  cv::medianBlur(frame, result, ksize) ;

}

void gaussian_blur_filter(const cv::Mat &frame, cv::Mat &result, cv::Size ksize, double sigma_X, double sigma_Y) {

  /** Blur an image using the GaussianBlur() operator.
    *
    * @kisze: Kernel size.
    *
    * @sigma_X:  Gaussian kernel standard deviation in X direction. if 0
    * @sigma_Y:  Gaussian kernel standard deviation in Y direction. if 0 set equal to @sigma_X.
    *
    * if @sigma_X and @sigma_Y == 0 they are computed from @ksize as:
    *
    *           sigma = 0.3*((ksize-1)*0.5 - 1) + 0.8
    *
    *******************************************************************************************/

  cv::GaussianBlur(frame, result, ksize, sigma_X, sigma_Y) ;

}



/** ****************************************************************************************************************************************************************************** **/


void sobel_filter(const cv::Mat &frame, cv::Mat &result, int x_order, int y_order, int ksize, int output_depth, double scale, double delta) {

  /** Calculates the first, second, third, or mixed image derivatives using an extended Sobel operator.
    *
    * @ksize size of the extended Sobel kernel; it must be 1, 3, 5, or 7.
    *
    * In all cases except one, the (ksize X ksize) separable kernel is used to calculate the derivative.
    * When @ksize = 1, the 3x1 or 1x3 Sobel kernel is used (that is, no Gaussian smoothing is done). Only one derivative can be compute.
    *
    * Otherwise @ksize = CV_SCHARR (-1) -> the 3x3 Scharr filter kernel that may give more accurate results than the 3x3 Sobel.
    *
    * @output_depth: CV_8U | CV_16S | CV_32F | CV_64F
    *
    **************************************************************************************************************************************/



  /** 3x3 Sobel kernel:
    *
    *    -1  0  1    |  -1  -2  -1
    *                |
    *    -2  0  2    |   0   0   0
    *                |
    *    -1  0  1    |   1   2   1
    *
    *******************************/

  cv::Sobel(frame, result, output_depth, x_order, y_order, ksize, scale, delta) ; //  , int borderType = BORDER_DEFAULT ) ; // BORDER_DEFAULT = gfedcb|abcdefgh|gfedcba (pixel extrapolation).

}


/** ****************************************************************************************************************************************************************************** **/

void scharr_filter(const cv::Mat &frame, cv::Mat &result, int x_order, int y_order, int ksize, int output_depth, double scale, double delta) {

  /** Calculates the first x- or y- image derivative using Scharr operator.
    *
    * The function computes the first x- or y- spatial image derivative using the Scharr operator.
    *
    **********************************************************************************************/

  /** 3x3 Scharr kernel:
    *
    *    -3  0   3   |   -3  -10  -3
    *                |
    *   -10  0  10   |    0    0   0
    *                |
    *    -3  0   3   |    3  -10   3
    *
    *****************************************************************************************************/

  cv::Scharr(frame, result, output_depth, x_order, y_order, scale, delta) ;

}

/** ****************************************************************************************************************************************************************************** **/


void laplacian_filter(const cv::Mat &frame, cv::Mat &result, int ksize, int output_depth, double scale, double delta) {

  /** Calculates the Laplacian of an image.
    * The function calculates the Laplacian of the source image by adding up the second x and y derivatives calculated using the Sobel operator:
    *
    * @ksize: aperture size.
    *
    * @output_depth: CV_8U | CV_16S | CV_32F | CV_64F
    *
    * @scale: scaling factor.
    *
    * @delta: offset to add.
    *
    ********************************************************************************************************************************************/


  cv::Laplacian(frame, result, output_depth, ksize, scale, delta) ;

}

/** ****************************************************************************************************************************************************************************** **/

void sharpen_rect_3(const cv::Mat &frame, cv::Mat &result, bool one=false) {

  /** Contruct a sharpen rect 3x3 matrix. and apply it on frame. **/

  // Construct kernel (all entries initialized to -1.0)
  cv::Mat kernel(3,3,CV_32F,cv::Scalar(-1.0f)) ;

  kernel.at<float>(1,1) =  8.0f + one  ;

  //filter the image
  cv::filter2D(frame, result, frame.depth(), kernel) ;

}

void sharpen_cross_3(const cv::Mat &frame, cv::Mat &result, bool one=false) {

   /** Contruct a sharpen cross 3x3 matrix. and apply it on frame. **/

  // Construct kernel (all entries initialized to 0.0)
  cv::Mat kernel(3,3,CV_32F,cv::Scalar(0.0f)) ;

  kernel.at<float>(0,0) = -1.0f  ;
  kernel.at<float>(0,2) = -1.0f  ;
  kernel.at<float>(2,0) = -1.0f  ;
  kernel.at<float>(2,2) = -1.0f  ;

  kernel.at<float>(1,1) =  5.0f + one ;

  //filter the image
  cv::filter2D(frame, result, frame.depth(), kernel) ;

}


/** Sobel operator based filters functions. **/

void sobel_drawning(const cv::Mat &frame, cv::Mat &result, int ksize, bool to_gray, int8_t bg_color) {

  /** Contours detection function using the Sobel() operator.
    *
    * @ksize: aperture size.
    *
    * @to_gray = true -> disable colors in result.
    *
    * @bg_color = -1 background black
    * @bg_color =  0 background emboss
    * @bg_color =  1 background white
    *
    **********************************************************/

  cv::Mat x_derivative  ;
  cv::Mat y_derivative  ;

  double xy_min, xy_max ;

  cv::Mat norm,  dir ;

  cv::Mat work_frame ;


  if (to_gray) {
    cv::cvtColor(frame, work_frame, (frame.channels() == 4) ?  cv::COLOR_BGRA2GRAY : cv::COLOR_BGR2GRAY ) ;
  }
  else {
    work_frame = frame ;
  }


  // Compute x-derivative and prepare background in relationship to @bg_color argument.
  cv::Sobel(work_frame, x_derivative, CV_32F, 1, 0, ksize, 1.0, ((bg_color == -1) || (bg_color == 0))  ? 128 : 0 ) ;
  // Compute y-derivative and prepare background in relationship to @bg_color argument.
  cv::Sobel(work_frame, y_derivative, CV_32F, 0, 1, ksize, 1.0, ((bg_color == -1) || (bg_color == 0))  ? 128 : 0 ) ;

  // Calculates the magnitude and angle of 2D vectors (xy-derivative).
  cv::cartToPolar(x_derivative, y_derivative, norm, dir) ;

  // Get minimal and maximal normal vector magnitude.
  cv::minMaxLoc(norm, &xy_min, &xy_max) ;

  cv::Mat tmp_1 ;

  norm.convertTo(tmp_1, CV_8UC3, -255.0/xy_max, 255) ;


  if (bg_color == -1 || bg_color == 0) { // Background black or emboss.

    bitwise_not(tmp_1, tmp_1) ;

    if (bg_color == -1) {
      // Making Background black.
      sharpen_rect_3(tmp_1, tmp_1, false) ;
    }

    if (frame.channels() == 4) {
 
      // Copy data ignoring the alpha channel.
 
      vector<cv::Mat> tmp_2 ;
      vector<cv::Mat> tmp_3 ;

      cv::split(frame, tmp_2) ;
      cv::split(tmp_1, tmp_3) ;

      tmp_2[0] = tmp_3[0] ;
      tmp_2[1] = tmp_3[1] ;
      tmp_2[2] = tmp_3[2] ;

      cv::merge(tmp_2, result) ;

      return ;
    }

    result = tmp_1 ;

    return ;
  }




  if (frame.channels() == 4) {

    // Copy data ignoring the alpha channel.

    vector<cv::Mat> tmp_2 ;
    vector<cv::Mat> tmp_3 ;

    cv::split(frame, tmp_2) ;
    cv::split(tmp_1, tmp_3) ;

    tmp_2[0] = tmp_3[0] ;
    tmp_2[1] = tmp_3[1] ;
    tmp_2[2] = tmp_3[2] ;

    cv::merge(tmp_2, result) ;

  }
  else if (frame.channels() == 3) {
    result = tmp_1 ;
  }

  // Making background white.
  sharpen_rect_3(result, result, true) ;

}


void sobel_emboss(const cv::Mat &frame, cv::Mat &result, int ksize) {

  /** Emboss filter using the Sobel() operator.
    *
    * @ksize: aperture size.
    *
    *******************************************/

  cv::Mat work_frame ;

  cv::Mat tmp_1 ;
  cv::Mat tmp_2 ;
  cv::Mat tmp_3 ;

  bool to_gray = true ;

  if (to_gray) {
    cv::cvtColor(frame, work_frame, (frame.channels() == 4) ? CV_BGRA2GRAY : CV_BGR2GRAY ) ;
  }
  else {
    work_frame = frame ;
  }

  // Compute x-derivative and set the color on 128.
  sobel_filter(work_frame, tmp_1, 1, 0, ksize, CV_8U, 0.2, 128) ;
  // Compute y-derivative and set the color on 128.
  sobel_filter(work_frame, tmp_2, 0, 1, ksize, CV_8U, 0.2, 128) ;

  // Half x-derivative and other half y_derivative.
  tmp_3 = (tmp_1 * 0.5 + tmp_2 * 0.5  )  ;

  sharpen_cross_3(tmp_3, tmp_3, false) ;

  cv::Mat tmp_4 ;

  // Smoothing result.
  cv::bilateralFilter(tmp_3, tmp_4, 3, 150*0.2, 9) ;

  if (to_gray) {
    cv::cvtColor(tmp_4, tmp_4, cv::COLOR_GRAY2BGR) ;
  }

  // Copy data including alpha channel if frame has one.
  vector<cv::Mat> tmp_5 ;
  vector<cv::Mat> tmp_6 ;

  cv::split(frame, tmp_5) ;
  cv::split(tmp_4, tmp_6) ;

  tmp_5[0] = tmp_6[0] ;
  tmp_5[1] = tmp_6[1] ;
  tmp_5[2] = tmp_6[2] ;

  cv::merge(tmp_5, result) ;

}

/** Laplacian operator based filters functions. **/

void laplacian_emboss(const cv::Mat &frame, cv::Mat &result, int ksize) {

  double factor = 2.0 ;

  cv::Mat work_frame ;

  cv::cvtColor(frame, work_frame, (frame.channels() == 4) ? CV_BGRA2GRAY : CV_BGR2GRAY ) ;
 

  // Compute derivatives.
  cv::Mat laplace ;
  cv::Laplacian(work_frame, laplace, CV_32F, ksize);

  // Extract minimal and maximal values from laplacian result.
  double lapmin, lapmax;
  cv::minMaxLoc(laplace, &lapmin, &lapmax) ;

  auto scale = 127.0/ max(-lapmin, lapmax) ;

  scale *= factor ;

  cv::Mat tmp_1 ;

  laplace.convertTo(tmp_1, CV_8U, scale, 128.0/factor) ;

  tmp_1 = tmp_1.mul(factor) ;

  cv::Mat tmp_2 ;

  // Smoothing result.
  cv::bilateralFilter(tmp_1, tmp_2, ksize, 150*factor, 5) ;

  cv::Mat tmp_3 ;
 
  cv::cvtColor(tmp_2, tmp_3,  CV_GRAY2BGR ) ;
 


  // Copy data including alpha channel if frame has one.
  vector<cv::Mat> tmp_4 ;
  vector<cv::Mat> tmp_5 ;

  cv::split(frame, tmp_4) ;
  cv::split(tmp_3, tmp_5) ;

  tmp_4[0] = tmp_5[0] ;
  tmp_4[1] = tmp_5[1] ;
  tmp_4[2] = tmp_5[2] ;

  cv::merge(tmp_4, result) ;


}

void laplacian_zero_crossing(const cv::Mat &frame, cv::Mat &result, int ksize, bool invert) {

  /** Strong contours detection using Laplacian() operator.
    *
    * @kisze: aperture size.
    *
    * @invert: invert black and white.
    *
    ********************************************************/

  cv::Mat work_frame ;

  const bool to_gray = true ; // This setting can be set on false,
                              // so that colors come into play but the output of most images isn't terrible.

  if (to_gray) {
    cv::cvtColor(frame, work_frame, (frame.channels() == 4) ? CV_BGRA2GRAY : CV_BGR2GRAY ) ;
  }
  else {
    work_frame = frame ;
  }


  cv::Mat laplace ;
  // Compute the floating point Laplacian
  cv::Laplacian(work_frame, laplace, CV_32F, ksize);

  // Get a binary image of the zero-crossings
  // laplacian image should be CV_32F

  // threshold at 0
  // negative values in black
  // positive values in white
  cv::Mat sign_image ;
  cv::threshold(laplace, sign_image, 0, 255, cv::THRESH_BINARY);

  // convert the +/- image into CV_8U
  cv::Mat binary;
  sign_image.convertTo(binary,CV_8U);

  // dilate the binary image of +/- regions
  cv::Mat dilated;
  cv::dilate(binary,dilated,cv::Mat());

  // return the zero-crossing contours
  cv::Mat tmp_2 = dilated-binary ;

  cv::Mat tmp_3 = 255-tmp_2 ;

  if (invert) {
    // Invert bits and so the background color.
    bitwise_not(tmp_3, tmp_3) ;

  }


  if (to_gray) {
    // Convert back.
    cv::cvtColor(tmp_3, tmp_3,  CV_GRAY2BGR ) ;
  }

  // Copy data including alpha channel if frame has one.
  vector<cv::Mat> tmp_4 ;
  vector<cv::Mat> tmp_5 ;

  cv::split(frame, tmp_4) ;
  cv::split(tmp_3, tmp_5) ;

  tmp_4[0] = tmp_5[0] ;
  tmp_4[1] = tmp_5[1] ;
  tmp_4[2] = tmp_5[2] ;

  cv::merge(tmp_4, result) ;

}


void stroke_edges(const cv::Mat &frame, cv::Mat &result, int median_blur_ksize, int laplacian_ksize) {

  /** @NOTE: effect implementation from Joseph Howse author from the book: "OpenCV Computer Vision with Python".
    *        Translate from the python into the programming language C++ and BGRA support adding.
    *        by Eddie Bruggemann <mrcyberfighter@gmail.com>.
    *
    *************************************************************************************************************/

  cv::Mat blurred ;
  cv::Mat gray    ;

  cv::Mat laplace ;

  if (median_blur_ksize >= 3) {
    cv::medianBlur(frame, blurred, median_blur_ksize) ;
    cv::cvtColor(blurred, gray,  (frame.channels() == 4) ? CV_BGRA2GRAY : CV_BGR2GRAY )   ;
  }
  else {
    cv::cvtColor(frame, gray,  (frame.channels() == 4) ? CV_BGRA2GRAY : CV_BGR2GRAY )  ;
  }


  cv::Laplacian(gray, laplace, CV_8U, laplacian_ksize) ;

  cv::Mat normalizedInverseAlpha = (1.0 / 255) * (255 - laplace) ;




  vector<cv::Mat> channels ;

  cv::split(frame, channels) ;

  channels[0] = channels[0].mul(normalizedInverseAlpha)  ;
  channels[1] = channels[1].mul(normalizedInverseAlpha)  ;
  channels[2] = channels[2].mul(normalizedInverseAlpha)  ;


  cv::merge(channels, result) ;

}

void wave(const cv::Mat &frame, cv::Mat &result, int8_t sens) {

  /**  Make a wave effect:
    *
    *  horizontally..: @param sens = -1 ;
    *  vertically....: @param sens =  1 ;
    *  twice.........: @param sens =  0 ;
    *
    ************************************/

  /** @NOTE: effect implementation from Robert Langanière author from the book: "OpenCV Computer Vision Application Programming cookbook".
    *
    *        Widened in the differents directions from Eddie Brüggemann <mrcyberfighter@gmail.com>. 
    *
    **************************************************************************************************************************************/


  // the map functions
  cv::Mat srcX(frame.rows, frame.cols, CV_32F); // x-map
  cv::Mat srcY(frame.rows, frame.cols, CV_32F); // y-map

  // creating the mapping
  for (int i=0 ;  i < frame.rows  ; i++) {
    for (int j=0 ; j < frame.cols ; j++) {

      switch (sens) {

        case -1 :
          srcX.at<float>(i,j)= j ;
          srcY.at<float>(i,j)= i+3*sin(j/6.0) ;
          break ;

        case  0 :
          srcY.at<float>(i,j)= i+3*sin(j/6.0) ;
          srcX.at<float>(i,j)= j+3*sin(i/6.0) ;
          break ;

        case  1 :
          srcX.at<float>(i,j)= j+3*sin(i/6.0) ;
          srcY.at<float>(i,j)= i ;
          break ;
      }

    }
  }

  // applying the mapping
  cv::remap(frame,  // source image
            result, // destination image
            srcX,   // x map
            srcY,   // y map
            cv::INTER_LINEAR); // interpolation method
}

void invert_bits(const cv::Mat &frame, cv::Mat &result) {

  /** Invert bits with alpha ignoring support. **/

  cv::Mat rgb ;

  if (frame.channels() == 4) {

    cvtColor(frame, rgb, cv::COLOR_BGRA2BGR) ;

    bitwise_not(rgb, rgb) ;

    vector<cv::Mat> tmp_1 ;
    vector<cv::Mat> tmp_2 ;

    cv::split(frame, tmp_1) ;
    cv::split(rgb, tmp_2) ;

    tmp_1[0] = tmp_2[0] ;
    tmp_1[1] = tmp_2[1] ;
    tmp_1[2] = tmp_2[2] ;

    cv::merge(tmp_1, result) ;

  }
  else {
    bitwise_not(frame, result) ;
  }

}