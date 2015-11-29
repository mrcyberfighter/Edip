#ifndef LIBEDIP_ALGORITHM_HH
#define LIBEDIP_ALGORITHM_HH

/** License:
  */

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
//#include <opencv2/features2d.hpp>
//#include <opencv2/objdetect.hpp>



#include <string>
#include <vector>

using namespace std ;



void canny_find_edges(const cv::Mat &frame, cv::Mat &result, double canny_min=100.0, double canny_max=200.0, int ksize=3, int8_t bg_color=1) ;

  /** Simply canny algorithm based Find Edges function.

      @param bg_color = -1 ; // background color black.
      @param bg_color =  0 ; // background color gray.
      @param bg_color =  1 ; // background color white.

  */



void color_contours(const cv::Mat &frame, cv::Mat &result, double canny_min=100.0, double canny_max=200.0, int ksize=3, cv::Scalar bg_color = cv::Scalar(255, 255, 255), cv::Scalar fg_color = cv::Scalar(0, 0, 0) ) ;

  /** Fully configurable draw contours functions.

    @param: canny_min -> canny minimal threshold value.
    @param: canny_max -> canny maximal threshold value.

    @param: ksize -> canny kernel size.

    @param: bg_color -> image background color.

    @param: fg_color -> image foreground color.

  */

void grab_cut_rect(const cv::Mat &frame, cv::Mat &result, cv::Rect rect, bool try_cut_contours = false ) ;

  /** Grab and cut function extracting a rectangle from frame.
    * Optionnaly try to extract the contours.
    **********************************************************/

void grab_cut_mask(const cv::Mat &frame, cv::Mat &result, cv::Rect rect ) ;

  /** Grab and cut function which should extract the outter contours,
    *  using cv::findContours() function and the cv::drawContours() function which output is used to:
    *  build the mask of outter contours.
    *************************************************************************************************/
  

#endif