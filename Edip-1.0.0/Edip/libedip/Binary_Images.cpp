#include "Binary_Images.hpp"

void canny(const cv::Mat &frame, cv::Mat &result, double min_threshold, double max_threshold, bool invert) {

    /**  Simply canny algorithm based function to output a
      *  binary image which colors (black and white) could be inverted.
      *
      *  @param min_threshold -> first threshold for the hysteresis procedure.
      *  @param max_threshold -> second threshold for the hysteresis procedure.
      *
      *  @param invert -> invert black and white in output.
      *
      ************************************************************************/


    cv::Mat tmp1 ;

    cv::cvtColor(frame, tmp1, cv::COLOR_BGR2GRAY) ;

    cv::Canny(tmp1, result, min_threshold, max_threshold, 3, true) ;


    if (invert) {

       /** The invert argument invert black and white. **/

       cv::bitwise_not(result, result) ;
    }

    cv::cvtColor(result, result, cv::COLOR_GRAY2BGR) ;

}

void build_binary_image(const cv::Mat &frame, cv::Mat &result, int8_t use_threshold,  bool invert) {

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
    *
    ************************************************************************************************************************************/


  cv::Mat tmp1 ;
  cv::Mat tmp2 ;


  cv::cvtColor(frame, tmp1, cv::COLOR_BGR2GRAY) ;

  int mode ;

  if (invert) { mode = cv::THRESH_BINARY_INV ; }
  else        { mode = cv::THRESH_BINARY     ; }

  double threshold_1 = cv::threshold(tmp1, tmp2, 127, 255, cv::THRESH_TRIANGLE) ;
  double threshold_2 = cv::threshold(tmp1, tmp2, 127, 255, cv::THRESH_OTSU) ;

  double magic_threshold = (threshold_1/2.0 + threshold_2/2.0) ; // / 2.0 ;

  cv::Mat res ;

  switch (use_threshold) {

    case -1 :
      cv::threshold(tmp1, res, threshold_2, 255, mode) ;
      break ;

    case 0 :
      cv::threshold(tmp1, res, magic_threshold, 255, mode) ;
      break ;
    case 1 :
      cv::threshold(tmp1, res, threshold_1, 255, mode) ;
      break ;

    default :
      // Better raise an exception.
      fprintf(stderr,"Wrong arg func: %s(..., use_threshold = -1 | 0 | 1) ;\n", __func__) ;
      result = frame ;
      return ;

  }

  cv::cvtColor(res, res, cv::COLOR_GRAY2BGR ) ;

  vector<cv::Mat> tmp_1 ;
  vector<cv::Mat> tmp_2 ;

  cv::split(frame, tmp_1) ;
  cv::split(res,   tmp_2) ;

  tmp_1[0] = tmp_2[0] ;
  tmp_1[1] = tmp_2[1] ;
  tmp_1[2] = tmp_2[2] ;

  cv::merge(tmp_1, result) ;

}







