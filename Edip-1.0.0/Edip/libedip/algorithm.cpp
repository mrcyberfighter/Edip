#include "algorithm.hpp"

void canny_find_edges(const cv::Mat &frame, cv::Mat &result, double canny_min, double canny_max, int ksize, int8_t bg_color) {

  /**  Simply canny algorithm based configurable Find Edges function.
    *
    *  @param canny_min -> first threshold for the hysteresis procedure.
    *  @param canny_max -> second threshold for the hysteresis procedure.
    *
    *  @param ksize -> aperture size for the Sobel operator.
    *
    *  @param bg_color = -1 ; // background color black.
    *  @param bg_color =  0 ; // background color gray.
    *  @param bg_color =  1 ; // background color white.
    *
    *******************************************************************/

  cv::Mat canny_output ;

  cv::Canny(frame, canny_output, canny_min, canny_max, ksize) ;

  switch (bg_color) {

    case -1 :

      break ;

    case 0  :

      canny_output.convertTo(canny_output, CV_8U, 1.0, 127) ;
      break ;

    case 1  :

      bitwise_not(canny_output, canny_output) ;
      break ;

    default :

      // Raise an exception.
      fprintf(stderr,"Error argument %s(..., bg_color = -1 | 0 | 1)\nDetermine the background color:\nbg_color = -1 -> black ;\nbg_color =  0 -> gray ;\nbg_color =  1 white\n", __func__) ;
      result = frame ;
      return ;
  }

  cvtColor(canny_output, canny_output, cv::COLOR_GRAY2BGR) ;

  canny_output.copyTo(result) ;

}

void color_contours(const cv::Mat &frame, cv::Mat &result, double canny_min, double canny_max, int ksize, cv::Scalar bg_color, cv::Scalar fg_color ) {

  /** Fully configurable draw contours functions. **/

  cv::Mat canny_output ;

  cv::Canny(frame, canny_output, canny_min, canny_max, ksize) ;


  vector<vector<cv::Point>>  contours  ;
  vector<cv::Vec4i>          hierarchy ;

  cv::findContours(canny_output, contours, hierarchy, cv::RETR_LIST, cv::CHAIN_APPROX_SIMPLE) ;

  result = frame ;

  result = bg_color ;

  if (! contours.empty() ) {
    cv::drawContours(result, contours, -1, fg_color, 1, cv::LINE_8) ;
  }
  else {
    result = frame ;
  }


}

void grab_cut_rect(const cv::Mat &frame, cv::Mat &result, cv::Rect rect, bool try_cut_contours ) {

  /** @NOTE: unused in the program Edip.  **/

  /**  Grab and cut function extracting a rectangle from frame.
    *  Optionnaly try to extract the contours.
    *
    *********************************************************/

  cv::Mat grab_cut_res_mask ;

  cv::Mat fg_model ;
  cv::Mat bg_model ;

  /** Must check the utility of the bg_model and fg_model args. **/
  cv::grabCut(frame, grab_cut_res_mask, rect, bg_model, fg_model, 5, cv::GC_INIT_WITH_RECT) ;

  cv::Mat res(frame.size(), CV_8UC3, cv::Scalar(255, 255, 255) ) ;

  if (try_cut_contours) {
    cv::compare(grab_cut_res_mask, cv::GC_PR_FGD, grab_cut_res_mask, cv::CMP_EQ) ;
  }

  result.copyTo(res, grab_cut_res_mask) ;

  result=res ;

}

void grab_cut_mask(const cv::Mat &frame, cv::Mat &result, cv::Rect rect=cv::Rect() ) {

  /** @NOTE: unused in the program Edip.  **/

  /**  Grab and cut function which should extract the outter contours,
    *  using cv::findContours() function and the cv::drawContours() function which output is used to
    *  build the mask of outter contours.
    *
    **************************************************************************************************/

  cv::Mat img_gray ;

  cv::Mat src_gray   ;

  cv::cvtColor(frame,    src_gray, cv::COLOR_BGR2GRAY);
  cv::cvtColor(src_gray, img_gray,  cv::COLOR_GRAY2BGR);

  cv::Mat canny_output;
  int thresh = 255/2 ;

  cv::Canny(src_gray, canny_output, 100, 200, 3 );



  int i, j, compCount = 0 ;

  vector<vector<cv::Point>>  contours  ;
  vector<cv::Vec4i>          hierarchy ;

  cv::findContours(canny_output, contours, hierarchy, cv::RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE);

  if ( contours.empty() ) {
    fprintf(stderr,"contours empty !!!\n") ;
    return ;
  }


  cv::Mat markers(frame.size(), CV_32S);
  markers = cv::Scalar::all(0);

  int idx = 0;
  for( ; idx >= 0; idx = hierarchy[idx][0], compCount++ )
    cv::drawContours(markers, contours, idx, cv::Scalar::all(compCount+1), CV_FILLED, 8, hierarchy, INT_MAX);


  if ( markers.empty() )  {

    fprintf(stderr,"markers empty !!!\n") ;
    return ;
  }


  cv::Mat mask(markers.size(), CV_8UC1) ;

  cv::Mat wshed(markers.size(), CV_8UC3);
  // paint the watershed image

  for( i = 0; i < markers.rows; i++ )
      for( j = 0; j < markers.cols; j++ )
      {
          int index = markers.at<int>(i,j);
          if( index == -1 ) {
              wshed.at<cv::Vec3b>(i,j) = cv::Vec3b(0,0,0) ;
              mask.at<uchar>(i,j) = cv::GC_PR_BGD ;
          }
          else if( index <= 0 || index > compCount ) {
              wshed.at<cv::Vec3b>(i,j) = cv::Vec3b(255, 255, 255);
              mask.at<uchar>(i,j) = cv::GC_PR_BGD ;
          }
          else {
              wshed.at<cv::Vec3b>(i,j) = cv::Vec3b(255, 0, 0) ;

              mask.at<uchar>(i,j) = cv::GC_PR_FGD ;
         }

      }

  wshed = wshed*0.5 + img_gray * 0.5 ;


  cv::Mat grab_cut_res_mask = mask ;

  cv::Mat fg_model ;
  cv::Mat bg_model ;

  cv::grabCut(frame, grab_cut_res_mask, rect, bg_model, fg_model, 5, cv::GC_INIT_WITH_MASK | cv::GC_EVAL) ;

  cv::Mat res(frame.size(), CV_8UC3 ) ;

  cv::compare(grab_cut_res_mask, cv::GC_PR_FGD, grab_cut_res_mask, cv::CMP_EQ) ;

  result.copyTo(res, grab_cut_res_mask) ;

  result=res ;

  return ;
}