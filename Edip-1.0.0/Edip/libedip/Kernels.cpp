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

#include "Kernels.hpp"

template <typename T>
void _make_kernel(cv::Mat &kernel, const string kernel_type, const int ksize, const char center_value, const float factor) {

  T counter = 0 ;

  const T val = 1.0f * factor ;

  if (kernel_type == "cross") {

    for (int c=0 ; c < ksize ; c++) {

      if (c != ksize/2) {
        kernel.at<T>(c,ksize/2) = val ;
        kernel.at<T>(ksize/2,c) = val ;
        counter += 2.0f * factor  ;
      }
    }
  }
  else if (kernel_type == "X") {

    int incr=0 ;
    int decr=1 ;
    for (int c=0 ; c < ksize ; c++) {

      if (c != ksize/2) {
       kernel.at<T>(c,incr) = val ;
       kernel.at<T>(c,ksize - decr) = val ;

       incr++ ;
       decr++ ;

       counter += 2.0f * factor  ;
      }
      else {

       incr++ ;
       decr++ ;
      }

    }
  }
  else if (kernel_type == "rect") {

    for (int c=0 ; c < ksize ; c++) {

      for (int cc=0 ; cc < ksize ; cc++) {

        if ( (!(c == ksize/2)) || (!(cc == ksize/2)) ) {

          kernel.at<T>(c,cc) = val ;
          counter += 1.0f * factor ;
     
        }
      }
    }

  }
  else if (kernel_type == "diamond") {

    int incr=ksize/2 ;
    int decr=ksize/2+1 ;
    for (int c=0 ; c < ksize ; c++) {

      if (c != ksize/2) {

        for (int cc=incr ; cc < decr ; cc++) {
          kernel.at<T>(c,cc) = val ;
          counter += 1 * factor ;
        }

        if ( c < ksize/2) {
          incr-- ;
          decr++ ;
        }
        else if ( c > ksize/2) {
          incr++ ;
          decr-- ;
        }

      }
      else {

        for (int cc=0 ; cc < ksize ; cc++) {

          if (cc != ksize/2) {
           kernel.at<T>(c,cc) = val ;
           counter += 1 * factor ;
          }

        }

        incr=1 ;
        decr=ksize-1 ;
      }

   }

  }

  switch (center_value) {

    case '+' :

      counter += 1.0f ;
      break ;

    case '-' :

      counter -= 1.0f ;
      break ;

    case '0' :

      counter ;
      break ;

    case '1' :

      counter = 1 ;
      break ;
  }


  kernel.at<T>(ksize/2,ksize/2) = counter ;

  #ifdef DEBUG
  for (int c=0 ; c < kernel.rows ; c++) {

    cout << "[ " ;

    for (int cc=0 ; cc < kernel.cols ; cc++) {
      cout << to_string(kernel.at<T>(c,cc)) << ((cc >= kernel.cols-1) ? " " : ", ") ;
    }

    cout << " ]\n" ;
  }
  #endif

}

cv::Mat make_kernel(const string kernel_type, const int ksize, const char center_value, const float factor, const int datatypes) {

  /** Function to generate a kernel.
    *
    *  @params:
    *
    *  @kernel_type: "rect" | "diamond" | "cross" | "X"
    *
    *  @ksize: kernel size.
    *
    *  @center_value: value of the center. Determine the weight of the kernel. 
    *
    *  @factor: factor multiplying the kernel values.
    *
    *  @datatypes: CV_8U (uint8_t) | CV_8S (int8_t) | CV_16U (uint16_t) | CV_16S (int16_t) | CV_32S (int32_t) | CV_32F (float) | CV_64F (double).
    *
    **********************************************************************************************************************************************/
   
  if ( (! (kernel_type == "rect")) && (! (kernel_type == "diamond")) && (! (kernel_type == "cross")) && (! (kernel_type == "X")) ) {

    fprintf(stderr,"%s() Wrong kernel_type argument value !!!\nkernel_type = [\"rect\"|\"diamond\"|\"cross\"|\"X\"]", __func__) ;
    return cv::Mat() ;
  }

  if (! (ksize % 2 == 1) ) {

    fprintf(stdout,"%s() Wrong ksize argument value !!!\nksize %% 2 == 1",__func__) ;
    return  cv::Mat() ;
  }

  if ((ksize < 3) || (ksize > 31)) {
    fprintf(stdout,"%s() Wrong ksize argument value !!!\n3 <= ksize <= 31",__func__) ;
    return  cv::Mat() ;
  }

  if ( (! (center_value == '+')) && (! (center_value == '-')) && (! (center_value == '0')) && (! (center_value == '1')) ) {

    fprintf(stdout,"%s() Wrong center_value argument value !!!\ncenter_value = ['+'|'-'|'0'|'1']",__func__) ;
    return  cv::Mat() ;
  }

  cv::Mat kernel(ksize, ksize, datatypes, cv::Scalar(0)) ;

  switch (datatypes) {

    case CV_8U :
      _make_kernel<uint8_t>(kernel, kernel_type, ksize, center_value, factor) ;
      break ;
    case CV_8S :
     _make_kernel<int8_t>(kernel, kernel_type, ksize, center_value, factor) ;
      break ;
    case CV_16U :
      _make_kernel<uint16_t>(kernel, kernel_type, ksize, center_value, factor) ;
      break ;
    case CV_16S :
      _make_kernel<int16_t>(kernel, kernel_type, ksize, center_value, factor) ;
      break ;
    case CV_32S :
      _make_kernel<int32_t>(kernel, kernel_type, ksize, center_value, factor) ;
      break ;
    case CV_32F :
      _make_kernel<float>(kernel, kernel_type, ksize, center_value, factor) ;
      break ;
    case CV_64F :
      _make_kernel<double>(kernel, kernel_type, ksize, center_value, factor) ;
      break ;
 
    default :
      fprintf(stdout,"%s() Wrong datatypes argument value !!!\ndatatypes = [ CV_8U | CV_8S | CV_16U | CV_16S | CV_32S | CV_32F | CV_64F ]",__func__) ;
      return  cv::Mat() ;
  }





  return kernel ;

}

/** ************************************************************************************************************************** **/

Kernels::Kernels(const int ksize, const char main_matrix_sign, const float main_matrix_weight_factor, const float factor) :

  /** Contructor of base class for the different kernels types. **/

  kernel(ksize, ksize, CV_32F, cv::Scalar(0.0f)), main_matrix_factor(main_matrix_weight_factor), kernel_size(ksize), matrix_values_factor(factor)  {

      switch (main_matrix_sign) {

        case '0' :

          // matrix final weight == 0 ;
          matrix_sign =  0 ;
          break ;

        case '-' :

          // matrix final weight == -1 ;
          matrix_sign = -1 ;
          break ;

        case '+' :

          // matrix final weight == +1   ;
          matrix_sign =  1 ;
          break ;

        case 'r' :

          // matrix values unchanged -> (r)aw ;
          matrix_sign = 127 ;
          break ;

      }

}


void Kernels::kernel_print(const uint8_t prec) {

  for (int c=0 ; c < kernel.rows ; c++) {

    fprintf(stdout,"[ ") ;

    for (int cc=0 ; cc < kernel.cols ; cc++) {

      fprintf(stdout,"%+.*f%s",  prec, kernel.at<float>(c,cc),  (cc >= kernel.cols-1) ? " " : ", ") ;
    }

    fprintf(stdout," ]\n") ;
  }

}

inline const float Kernels::get_weight() const {

  float ret = 0.0 ;

  for (int c=0 ; c < kernel.rows ; c++) {

    for (int cc=0 ; cc < kernel.cols ; cc++) {
      ret += kernel.at<float>(c, cc) ;
    }

  }

  return ret ;
}

inline void Kernels::normalize(const float weight) {

  for (int c=0 ; c < kernel.rows ; c++) {

    for (int cc=0 ; cc < kernel.cols ; cc++) {
      kernel.at<float>(c, cc) /= weight ;
    }

  }

}

inline void Kernels::negalize() {

  /** If you negalize like me: setting the entire weight of the image resulting in the value -1.0.
    *  You will obtain an entire balck image: what doesn't make sens.
    *
    *  @ATTENTION: So try to negate the values @but set the entire weight of the matrix of 0 >= .
    *
    **********************************************************************************************/

  for (int c=0 ; c < kernel.rows ; c++) {

    for (int cc=0 ; cc < kernel.cols ; cc++) {
      kernel.at<float>(c, cc) = -kernel.at<float>(c, cc)  ;
    }

  }

}

inline void Kernels::zeroing() {

  const float weight = get_weight() ;

  kernel.at<float>(kernel_size/2, kernel_size/2) = -(weight - kernel.at<float>(kernel_size/2, kernel_size/2)) ;
}

inline void Kernels::compute_matrix_weight() {

  if (matrix_sign != 127) {

    switch (matrix_sign) {

      case -1 :
        normalize(get_weight()) ;
        negalize() ;
        break ;

      case  0 :
        zeroing() ;
        break ;

      case  1 :
        normalize(get_weight()) ;
        break ;
    }

  }

}

inline int8_t Kernels::get_matrix_sign() const {

  if (matrix_sign != 127) {
    return matrix_sign ;
  }

  return 1 ; // Better raise an exception.

}

/** *********************************************************************************************************************************************************************** **/

Sharpen::Sharpen(const int ksize, const string kernel_sort, const float factor, const char main_matrix_sign, const float main_matrix_weight_factor) :

  Kernels(ksize, main_matrix_sign, main_matrix_weight_factor, factor), kernel_type(kernel_sort) {

  const float val = -1.0f * factor ;

  if (kernel_sort == "cross") {

    for (int c=0 ; c < ksize ; c++) {

      if (c != ksize/2) {
        kernel.at<float>(c,ksize/2) = val ;
        kernel.at<float>(ksize/2,c) = val ;
        counter += 2.0f * factor ;
      }
    }
  }
  else if (kernel_sort == "X") {

    int incr=0 ;
    int decr=1 ;
    for (int c=0 ; c < ksize ; c++) {

      if (c != ksize/2) {
       kernel.at<float>(c,incr) = val ;
       kernel.at<float>(c,ksize - decr) = val ;

       incr++ ;
       decr++ ;

       counter += 2.0f * factor ;
      }
      else {

       incr++ ;
       decr++ ;
      }

    }
  }
  else if (kernel_sort == "rect") {

    for (int c=0 ; c < ksize ; c++) {

      for (int cc=0 ; cc < ksize ; cc++) {

        if ( (!(c == ksize/2)) || (!(cc == ksize/2)) ) {

          kernel.at<float>(c,cc) = val ;
          counter += 1.0f * factor ; ;
        }
      }
    }

  }
  else if (kernel_sort == "diamond") {

    int incr=ksize/2 ;
    int decr=ksize/2+1 ;
    for (int c=0 ; c < ksize ; c++) {

      if (c != ksize/2) {

        for (int cc=incr ; cc < decr ; cc++) {
          kernel.at<float>(c,cc) = val ;
          counter += 1.0f * factor ;
        }

        if ( c < ksize/2) {
          incr-- ;
          decr++ ;
        }
        else if ( c > ksize/2) {
          incr++ ;
          decr-- ;
        }

      }
      else {

        for (int cc=0 ; cc < ksize ; cc++) {

          if (cc != ksize/2) {
           kernel.at<float>(c,cc) = val ;
           counter += 1.0f * factor ;
          }

        }

        incr=1 ;
        decr=ksize-1 ;
      }

   }

  }
  else {
    // Better raise an exception.
    fprintf(stderr,"Wrong argument value !!!\n%s(kernel_sort = [ \"cross\" | \"X\" | \"rect\" | \"diamond\" ]\n", __func__) ;
  }

  kernel.at<float>(ksize/2,ksize/2) = (counter + get_matrix_sign() ) * main_matrix_factor ;

}

/** ****************************************************************************************************************************************************************************** **/

Find_Edges::Find_Edges(const int ksize, const string kernel_sort, const float factor, const char main_matrix_sign, const float main_matrix_weight_factor) :

  Kernels(ksize, main_matrix_sign, main_matrix_weight_factor, factor)  {

  const float val = -1.0f * factor ;

  if (kernel_sort == "cross") {

    for (int c=0 ; c < ksize ; c++) {
      if (c != ksize/2) {
        kernel.at<float>(c,ksize/2) = val ;
        kernel.at<float>(ksize/2,c) = val ;
        counter += 2.0f * factor ;
      }
    }

  }
  else if (kernel_sort == "X") {

    int incr=0 ;
    int decr=1 ;
    for (int c=0 ; c < ksize ; c++) {

      if (c != ksize/2) {
        kernel.at<float>(c,incr) = val ;
        kernel.at<float>(c,ksize - decr) = val ;

        incr++ ;
        decr++ ;

        counter += 2.0f * factor ;
      }
      else {
        incr++ ;
        decr++ ;
      }

    }

  }
  else if (kernel_sort == "rect") {

    for (int c=0 ; c < ksize ; c++) {

      for (int cc=0 ; cc < ksize ; cc++) {

        if ( (!(c == ksize/2)) || (!(cc == ksize/2)) ) {

         kernel.at<float>(c,cc) = val ;
         counter += 1.0f * factor ; ;
        }
      }

    }
  }
  else if (kernel_sort == "diamond") {

    int incr=ksize/2 ;
    int decr=ksize/2+1 ;
    for (int c=0 ; c < ksize ; c++) {

      if (c != ksize/2) {

        for (int cc=incr ; cc < decr ; cc++) {
          kernel.at<float>(c,cc) = val ;
          counter += 1.0f * factor ;
        }

        if ( c < ksize/2) {
          incr-- ;
          decr++ ;
        }
        else if ( c > ksize/2) {
          incr++ ;
          decr-- ;
        }
      }
      else {

        for (int cc=0 ; cc < ksize ; cc++) {

          if (cc != ksize/2) {
            kernel.at<float>(c,cc) = val ;
            counter += 1.0f * factor ;
          }

        }

        incr=1 ;
        decr=ksize-1 ;
      }

    }

  }
  else {
    // Better raise an exception.
    fprintf(stderr,"Wrong argument value !!!\n%s(kernel_sort = [ \"cross\" | \"X\" | \"rect\" | \"diamond\" ]\n", __func__) ;
  }


  kernel.at<float>(ksize/2,ksize/2) = (counter + get_matrix_sign() ) * main_matrix_factor ;




}

/** ****************************************************************************************************************************************************************************** **/

Emboss::Emboss(const int ksize, const float factor, const char main_matrix_sign, const float main_matrix_weight_factor) :

  Kernels(ksize, main_matrix_sign, main_matrix_weight_factor, factor)  {

  const float max_val = static_cast<float>(ksize-1) * factor ;

  float ival = max_val ;

  for (int c=0 ; c < ksize ; c++) {

    if (c < ksize/2) {

      for (int cc=0 ; cc < ksize ; cc++) {
        kernel.at<float>(cc,c) = ((ival-cc) > 0 ) ? -(ival-cc) : 0.0f ;
      }
      ival -= 1.0f ;
   }
   else if (c == ksize/2) {

      fprintf(stdout, "ival %f\n", ival) ;

      for (int cc=0 ; cc < ksize ; cc++) {

        if (cc < ksize/2) {
          kernel.at<float>(cc,c) = -(ival-cc)  ;
        }
        else if (cc > ksize/2) {
          kernel.at<float>(cc,c) =  ival-(ksize-1-cc) ;
        }
      }
      ival += 1 ;
    }
    else if (c > ksize/2) {

      for (int cc=0 ; cc < ksize ; cc++) {
        kernel.at<float>(cc,c) = ( ival-(ksize-1-cc) < 0 ) ? 0.0f : ival-(ksize-1-cc) ;  ;
      }
      ival += 1.0f ;
    }

  }


  kernel.at<float>(ksize/2,ksize/2) = get_matrix_sign()  * main_matrix_factor ;


}

/** ****************************************************************************************************************************************************************************** **/

Mean::Mean(const int ksize, const string kernel_sort) :

  Kernels(ksize, '+',  1.0f, 1.0f), kernel_type(kernel_sort) {

  const float val = 1.0f / ((kernel_sort == "rect") ? (ksize*ksize) : (kernel_sort == "diamond") ? (((ksize -1) * 3) + 1) : ((kernel_sort == "cross") || (kernel_sort == "X")) ? ((ksize-1) * 2) + 1 : 0)  ;

  if (kernel_sort == "cross") {

    for (int c=0 ; c < ksize ; c++) {

      if (c != ksize/2) {
        kernel.at<float>(c,ksize/2) = val ;
        kernel.at<float>(ksize/2,c) = val ;
      }
    }
  }
  else if (kernel_sort == "X") {

   int incr=0 ;
   int decr=1 ;
   for (int c=0 ; c < ksize ; c++) {

     if (c != ksize/2) {
       kernel.at<float>(c,incr) = val ;
       kernel.at<float>(c,ksize - decr) = val ;

       incr++ ;
       decr++ ;
     }
     else {

       incr++ ;
       decr++ ;
     }

   }
  }
  else if (kernel_sort == "rect") {

   for (int c=0 ; c < ksize ; c++) {

     for (int cc=0 ; cc < ksize ; cc++) {

       if ( (!(c == ksize/2)) || (!(cc == ksize/2)) ) {
         kernel.at<float>(c,cc) = val ;
       }

     }
   }
  }
  else if (kernel_sort == "diamond") {

    int incr=ksize/2 ;
    int decr=ksize/2+1 ;
    for (int c=0 ; c < ksize ; c++) {

      if (c != ksize/2) {

        for (int cc=incr ; cc < decr ; cc++) {
          kernel.at<float>(c,cc) = val ;
        }

        if ( c < ksize/2) {
          incr-- ;
          decr++ ;
        }
        else if ( c > ksize/2) {
          incr++ ;
          decr-- ;
        }
      }
      else {

        for (int cc=0 ; cc < ksize ; cc++) {

          if (cc != ksize/2) {
            kernel.at<float>(c,cc) = val ;
          }

        }

        incr=1 ;
        decr=ksize-1 ;
      }

    }

  }
  else {

   fprintf(stderr,"Wrong argument value !!!\n%s(kernel_sort = [ \"cross\" | \"X\" | \"rect\" | \"diamond\" ]\n", __func__) ;
  }

  kernel.at<float>(ksize/2,ksize/2) = val ;
}

/** ****************************************************************************************************************************************************************************** **/

Gaussian::Gaussian(const int ksize, const double sigma, const string kernel_sort, const char main_matrix_sign) :

  Kernels(ksize, main_matrix_sign, 1.0f, 1.0f), kernel_type(kernel_sort) {

  /** @NOTES:
    *
    *  The sigma determine the weight of the values from the gaussian matrix.
    *  And so determine the influence of the resulting image (higher sigma value = more influence).
    *  Except by the 'r' (raw) modus which is a little bit special.
    *
    *  Notice result: by mode 'r' it highlight the image or make it very white or luminancing.
    *                 by mode '0' it make a binary image.
    *                 by mode '+' it blur the image.
    *                 by mode '-' it produce a fully black result image.
    *
    *  Particularity: it seems that the "X" matrix x-ing the blurred image pixels (the image seems cover from 'X').
    *                 it seems that the "+" matrix +-ing the blurred image pixels (the image seems cover from '+').
    *
    ***************************************************************************************************************/

  cv::Mat gaussian_vector ;

  gaussian_vector = cv::getGaussianKernel(kernel_size, sigma, CV_32F) ;

  if (kernel_sort == "cross") {

    for (int c=0 ; c < ksize ; c++) {

      if (c != ksize/2) {
        kernel.at<float>(c,ksize/2) =   gaussian_vector.at<float>(c)  ;
        kernel.at<float>(ksize/2,c) =   gaussian_vector.at<float>(c)  ;
      }
    }

    kernel.at<float>(ksize/2, ksize/2) = gaussian_vector.at<float>(ksize/2) ;

  }
  else if (kernel_sort == "X") {

   int incr=0 ;
   int decr=1 ;
   for (int c=0 ; c < ksize ; c++) {

     if (c != ksize/2) {
       kernel.at<float>(c,incr) = gaussian_vector.at<float>(c) ;
       kernel.at<float>(c,ksize - decr) = gaussian_vector.at<float>(c) ;

       incr++ ;
       decr++ ;
     }
     else {

       incr++ ;
       decr++ ;
     }

    }

    kernel.at<float>(ksize/2, ksize/2) = gaussian_vector.at<float>(ksize/2) ;
  }
  else if (kernel_sort == "diamond") {

    int incr=ksize/2 ;
    int decr=ksize/2+1 ;
    int idx=0 ;
    int init_idx=0 ;
    for (int c=0 ; c < ksize ; c++) {

      /** We iterate row per row
        *  with ignoring the position which don't be member from the diamond form of the matrix.
        *  Du of the @incr and @decr variables which permit to do so.
        */

      if (c != ksize/2) {

        /** We ignore the center row and ignore the matrix values don't concern by the diamond form. */

        /** We must right indexing the gaussian vector in relationship of the diamond form. So we use the @idx variable. */


        for (int cc=incr ; cc < decr ; cc++) {

          kernel.at<float>(c,cc) = gaussian_vector.at<float>(idx) ;

          if (cc < ksize/2) {  // littler than the matrix center.
            idx++ ; // Adjust idx indexing the gaussian vector.
          }
          else if (cc > ksize) { // greater than the matrix center.
            idx-- ; // Adjust idx indexing the gaussian vector.
          }
          else { // Equal to the matriox center.
            idx-- ; // Adjust idx indexing the gaussian vector.
          }

        }

        if ( c < ksize/2) {
          incr-- ;
          decr++ ;
        }
        else if ( c > ksize/2) {
          incr++ ;
          decr-- ;
        }
        idx=0 ;


      }
      else {

        // We check the center row.

        for (int cc=0 ; cc < ksize ; cc++) {

          if (cc != ksize/2) {
            kernel.at<float>(c,cc) = gaussian_vector.at<float>(cc) ;
          }

        }

        incr=1 ;
        decr=ksize-1 ;

      }

    }

    kernel.at<float>(ksize/2, ksize/2) = gaussian_vector.at<float>(ksize/2) ;

  }
  else if (kernel_sort == "rect_row_major") {
    // You cann call it: x_ordered. Or simply rows or row_ordered.

    for (int cc=0 ; cc < ksize ; cc++) {
      for (int c=0 ; c < ksize ; c++) {
        kernel.at<float>(c,cc) = gaussian_vector.at<float>(c) ;
      }
    }
  }
  else if (kernel_sort == "rect_col_major") {
    // You cann call it: y_ordered. or simply columns or col_ordered.

    for (int cc=0 ; cc < ksize ; cc++) {
      for (int c=0 ; c < ksize ; c++) {
        kernel.at<float>(c,cc) = gaussian_vector.at<float>(c) ;
      }
    }
  }
  else if (kernel_sort == "rect") {

    /** What a rectangular gaussian matrix ? Good question a row major or a columns major gaussian vector matrix ?
      * ----------------------------------------------------------------------------------------------------------
      * We gonna build a diamond matrix filled with the maximal gaussian vector value.
      * With the border containing the other gaussian values incrementing
      * in relationship from the distance from the center.
      *
      *************************************************************************************************************/

    //We make a first pass to construct the cols gaussian matrix result we doesn't expect.
    for (int cc=0 ; cc < ksize ; cc++) {
      for (int c=0 ; c < ksize ; c++) {
        kernel.at<float>(cc,c) = gaussian_vector.at<float>(c) ;
      }
    }


    // We make a second pass to build the gaussian rectangle diamond matrix. (unfortunaly with holes in the construct).

    // We initialize the variables because the construct must goes ascendant to the maximum.
    int idx=1 ;
    int init_idx=2 ;

    for (int c=0 ; c < ksize ; c++) {

      //  We iterate row per row

      if (c != ksize/2) {

        // We ignore the center because it contains always the same value.

        // We must right indexing the gaussian vector in relationship of the diamond form. So we use the @idx variable.


        for (int cc=1 ; cc <= ksize-2 ; cc++) { // We always iterate into the same action field.

            // Into the action field [1:ksize-2] for every row except the center row.

            if ( cc != ksize/2) {
              // Case different from the cross centered values.
              kernel.at<float>(c,cc) = gaussian_vector.at<float>(idx) ;
            }
            else {
              // Case into the cross centered values: we always set it to the maximum.
              kernel.at<float>(c,cc) = gaussian_vector.at<float>(ksize/2) ;
            }

            // [de|in]crement the gaussian vector value pointer index variable in relationship to the current position in the row.
            if (cc < ksize/2) {
              idx++ ;
            }
            else if (cc > ksize/2) {
              idx-- ;
            }
            else {
              idx-- ;
            }

        }

        // Initialize for next row iteration.
        idx = init_idx ;


        // Update for next row iteration.
        if ( c < ksize/2) {
          init_idx++ ;
        }
        else if ( c > ksize/2) {
          init_idx-- ;
        }

      }


      else {

        // We check the center row.

        for (int cc=0 ; cc < ksize ; cc++) {
          // Always the same value in the center row.
          kernel.at<float>(c,cc) = gaussian_vector.at<float>(ksize/2) ;
        }


        // We reinitialize the variables because after the center the construct must goes descendant from the maximum.
        init_idx = ksize/2-1 ;
        idx=ksize/2 ;

      }


    }

    // We make a last holes correction pass over the matrix.

    for (int cc=0 ; cc < ksize ; cc++) {

      // If we fill with the maximum value from the gaussian vector.
      bool set=false ;

      for (int c=0 ; c < ksize ; c++) {

        if (set) {
          kernel.at<float>(c,cc) = gaussian_vector.at<float>(ksize/2) ;
        }
        if (gaussian_vector.at<float>(ksize/2) == kernel.at<float>(c,cc)) {
          // Detecting maximum value soon set and mark the loop to continue filling.
          set=true ;
        }

        if ( c >= ksize/2) {

          // But the loop cannot fill the entire columns end so we need to stop the filling.

          if (cc < ksize/2) {
            if ( c >= ksize/2+cc) {
              set=false ;
            }
          }
          else if (cc > ksize/2) {
            if (c >= (ksize-1-cc) + ksize/2) {
              set=false ;
            }
          }

        }


      }
    }


  }
  else {
    // Better raise an exception.
    fprintf(stdout,"Wrong argument value !!!\n%s(kernel_sort = [ \"cross\" | \"X\" | \"rect\" | \"diamond\" ]\n", __func__) ;
  }

  compute_matrix_weight() ;



}

/** ****************************************************************************************************************************************************************************** **/

Kirsch::Kirsch(const int ksize, const string direction, const float factor) :

  Kernels(ksize, '0', 0.0f, factor) {

  const float minor = -static_cast<float>(ksize)  ;

  const float major =  static_cast<float>(ksize) * ((ksize*ksize) - ksize - 1) / ksize ;

  const float minor_factor = factor ;

  const float major_factor = factor ;

  fill(minor * minor_factor) ;

  if (direction == "E") {

    for (int c=0 ; c < ksize ; c++) {
      kernel.at<float>(c,ksize-1) = major * major_factor  ;
    }

  }
  else if (direction == "W") {

    for (int c=0 ; c < ksize ; c++) {

      kernel.at<float>(c,0) = major * major_factor ;
    }

  }
  else if (direction == "N") {

    for (int c=0 ; c < ksize ; c++) {
      kernel.at<float>(0, c) = major * major_factor ;
    }

  }
  else if (direction == "S") {

    for (int c=0 ; c < ksize ; c++) {
      kernel.at<float>(ksize-1, c) = major * major_factor ;
    }

  }
  else {
    // better raise an exception.
    fprintf(stderr,"Wrong argument value !!!\n%s(direction = [ \"E\" | \"W\" | \"N\" | \"S\" ]\n", __func__) ;
  }

  kernel.at<float>(ksize/2, ksize/2) = 0.0f ;

}

/** ****************************************************************************************************************************************************************************** **/
