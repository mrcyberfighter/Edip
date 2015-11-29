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


#include "Resizer.hpp"

pair<int, int> Resizer::resizer(const cv::Mat frame, int frame_width, int frame_height, bool use_frame) {

  /** Resize frame in relationship to the given arguments:
    *   
    * @param frame_width  -> the wanted width  or the frame width size.
    * @param frame_height -> the wanted height or the frame height size.
    *
    * @param use_frame    -> if @true resize image to put into a frame else resize image with given settings.
    *
    *********************************************************************************************************/

  auto image_width  = frame.cols ;
  auto image_height = frame.rows ;

  float frame_image_width  = static_cast<float>(frame_width)  ;
  float frame_image_height = static_cast<float>(frame_height)  ;

  float factor= (static_cast<float>(frame_width) / static_cast<float>(frame_height) ) ;

  if ((image_width >= frame_image_width) && (image_height > frame_image_height)) {
    factor_width  =  static_cast<float>(image_width)  / static_cast<float>(image_height) ;
    factor_height =  static_cast<float>(image_height) / static_cast<float>(image_width) ;
    width  = 0.0f  ;
    height = 0.0f  ;


    if ((factor_width == 1.0) || (factor_height == 1.0)) {

      if (frame_image_height > frame_image_width) {
        width  = frame_image_width ;
        height = frame_image_width ;
      }
      else if (frame_image_height < frame_image_width) {
        width  = frame_image_height ;
        height = frame_image_height ;
      }
      else {
        width  = frame_image_height ;
        height = frame_image_height ;
      }

    }

    if (image_width > image_height) {

      if (factor_width < factor ) { //relation width/height.

        while (height < frame_image_height) {

          if ((height + factor_height) >= frame_image_height) {
            width *= factor_height  ;
            break ;
          }

          width  += factor_width   ;
          height += factor_height  ;
        }
      }
      else if (factor_width > factor) { //relation width/height.

        while (width < frame_image_width) {
          if ((width + factor_width) >= frame_image_width) {
            height *= factor_width ;
            break  ;
          }
          width  += factor_width   ;
          height += factor_height  ;
        }
      }

    }

    if (image_width < image_height) {

      if (factor_width < factor) {  //relation width/height.

        while (height < frame_image_height) {

          if ((height + factor_height) >= frame_image_height) {
            width *= factor_height ;
            break ;
          }
          width = width + factor_width    ;
          height =height+factor_height    ;
        }
      }
      else if (factor_width > factor) { //relation width/height.

        while (width < frame_image_width) {

          if ((width + factor_width) >= frame_image_width) {
            height *= factor_width ;
            break  ;
          }
          width  += factor_width  ;
          height += factor_height ;
        }

      }
    }

    return make_pair(static_cast<int>(roundf(width)), static_cast<int>(roundf(height))) ;
  }

  else if ((image_width > frame_image_width) && (image_height <= frame_image_height)) {

    factor_width  = static_cast<float>(image_width)  / static_cast<float>(image_height) ;
    factor_height = static_cast<float>(image_height) / static_cast<float>(image_width)  ;
    width = 0.0f ;
    height =0.0f ;

    if (image_width == image_height) {
      if (frame_image_height > frame_image_width) {
        width  = frame_image_width ;
        height = frame_image_width ;
      }
      else if (height < frame_image_width) {
        width  = frame_image_height ;
        height = frame_image_height ;
      }
      else {
        width  = frame_image_height ;
        height = frame_image_height ;
      }
    }
    if (factor_width < factor) {  //relation width/height.
  
      while (height < frame_image_height) {
        if ((height + factor_height) >= height) {
          width *= factor_height ;
          break ;
        }

        width  += factor_width  ;
        height += factor_height ;
      }
    }
    else if (factor_width > factor) { //relation width/height.

      while (width < frame_image_width) {

        if ((width + factor_width) >= frame_image_width) {
          height *= factor_width ;
          break  ;
        }
        width  += factor_width   ;
        height += factor_height  ;
      }
    }

    return make_pair(static_cast<int>(roundf(width)), static_cast<int>(roundf(height))) ;
  }

  else if ((image_width <= frame_image_width) && (image_height > frame_image_height)) {
    factor_width  = static_cast<float>(image_width) /  static_cast<float>(image_height) ;
    factor_height = static_cast<float>(image_height) / static_cast<float>(image_width) ;
    width  = 0.0f ;
    height = 0.0f ;


    if (image_width == image_height) {
      if (frame_image_height > frame_image_width) {
        width  = frame_image_width ;
        height = frame_image_width ;
      }
      else if (frame_image_height < frame_image_width) {
        width  = frame_image_height ;
        height = frame_image_height ;
      }
      else {
        width  = frame_image_height ;
        height = frame_image_height ;
      }
    }

    if (image_width > image_height) {

      if (factor_width < factor) {  //relation width/height.

        while (height < frame_image_height) {

          if ((height + factor_height) >= frame_image_height) {
            width *= factor_height ;
            break ;
          }

          width  += factor_width  ;
          height += factor_height ;
        }
      }
      else if (factor_width > factor) { //relation width/height.

        while (width < frame_image_width) {

          if ((width + factor_width) >= width ) {
            height *= factor_width ;
            break  ;
          }
          width  += factor_width   ;
          height += factor_height  ;
        }
      }
    }
    if (image_width < image_height) {

      if (factor_width < factor) { //relation width/height.

        while (height < frame_image_height) {

          if ((height + factor_height) >= frame_image_height) {
            width *= factor_height ;
            break ;
          }
          width  += factor_width  ;
          height += factor_height ;
        }
      }
      else if (factor_width > factor) { //relation width/height.

        while (width < frame_image_width) {
          if ((width + factor_width) >= width) {
            height *= factor_width ;
            break  ;
          }
          width  += factor_width  ;
          height += factor_height ;
       }

      }
    }

    return make_pair(static_cast<int>(roundf(width)), static_cast<int>(roundf(height))) ;
  }

  else if ((image_width <= frame_image_width) && (image_height <= frame_image_height)) {

    factor_width  = (float) image_width/image_height ;
    factor_height = (float) image_height/image_width ;

    width        = (float) image_width ;
    height       = (float) image_height ;
  
    if (! (use_frame) ) {

      if (frame_image_height == frame_image_width) {

        if (width > height) {

          while (width < frame_image_width) {
            width++  ;
            height += factor_height ;
          }
        }
        else if (width < height) {

          while (height < frame_image_height) {
            width += factor_width  ;
            height++ ;
          }
        }
        else {

          while (width < frame_image_width) {
           width++  ;
           height++ ;
          }
        }

      }
      else if (frame_image_height < frame_image_width && (frame_image_width > width) ) {
 
        while (width < frame_image_width) {
          width++ ;
          height += factor_height ;
        }
      }
      else if (frame_image_height < frame_image_width && (frame_image_height > height) ) {

        while (height < frame_image_height) {
 
          height++ ;
          width += factor_width ;
        }
      }
      else if (frame_image_height > frame_image_width && (frame_image_width > width) )  {
 
        while (width < frame_image_width) {
          width++ ;
          height += factor_height ;
        }
      }
      else if (frame_image_height > frame_image_width && (frame_image_height > height) )  {

        while (height < frame_image_height) {
 
          height++ ;
          width += factor_width ;
        }
      }
   
    }


    return make_pair(static_cast<int>(roundf(width)), static_cast<int>(roundf(height))) ;
  }
}

bool Resizer::assertion(int prec) const {

  char buf_1[32]={0} ;
  char buf_2[32]={0} ;

  sprintf(buf_1, "%.*f", prec,  width/height) ;
  sprintf(buf_2, "%.*f", prec,  factor_width) ;

  if  ( strcmp(buf_1, buf_2) != 0 ) {
 
   #ifdef DEBUG
   fprintf(stdout,"Assertion error !!!\nBe aware of false positive !!!\n") ;
   #endif
 
   return false ;
  }
  else {
 
   #ifdef DEBUG
   fprintf(stdout,"Assertion successfull !!!\n") ;
   #endif
 
   return true ;
  }

}