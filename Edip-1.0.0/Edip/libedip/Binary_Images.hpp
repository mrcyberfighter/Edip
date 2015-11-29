#ifndef LIBEDIP_BINARY_IMAGE_HH
#define LIBEDIP_BINARY_IMAGE_HH

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

#include <string>
#include <vector>

using namespace std ;

void canny(const cv::Mat &frame, cv::Mat &result, double min_threshold=56.0, double max_threshold=255.0-56.0, bool invert=true) ;

  /** Simply canny algorithm based function to output a
      binary image which colors (bacl and white) could be invert through
  
      @param invert -> invert black and white in output.

  */

void build_binary_image(const cv::Mat &frame, cv::Mat &result, int8_t use_threshold = -1,  bool invert=false) ;

  /** Ouput an binary image based on an automatic threshold computing in relationship to the input image.
    *
    * @param: use_threshold method to compute the threshold.
    *         use_threshold = -1 -> use THRESH_OTSU     algorihtm to autocompute the threshold value.
    *         use_threshold =  1 -> use THRESH_TRIANGLE algorihtm to autocompute the threshold value.
    *         use_threshold =  0 -> aveagre value from the THRESH_OTSU and THRESH_TRIANGLE algorihtm to autocompute the threshold value.
    *
    * @param: invert black and white values inversion.
    *         invert        = true  -> use the THRESH_BINARY_INV which convert to 255 value all values greater than the threshold value.
    *         invert        = false -> use the THRESH_BINARY     which convert to 255 value all values littler than the threshold value.
    */

#endif