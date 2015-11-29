#ifndef LIBEDIP_RESIZER_UTILITY_HH
#define LIBEDIP_RESIZER_UTILITY_HH

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
 
#include <cstdio>

#include <math.h>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std ;

class Resizer {

  public :

    float width  = 0.0f ;  // Output width.
    float height = 0.0f ;  // Output height.

    float factor_width  = 0.0f ; // Factor (image_width  / image_height)

    float factor_height = 0.0f ; // Factor (image_height / image_width)

  public : // Constructor

    Resizer() {} ;

  public :
  
    // Perfom resizing.
    pair<int, int> resizer(const cv::Mat frame, int frame_width, int frame_height, bool use_frame = false) ;
  
    // Make an assertion from the initial size relation factor and the output relation factor.
    bool assertion(int prec=3) const ;
   
    // Getting the initial size width/height factor.
    const float get_factor_width() const { return factor_width  ; } ;
  
    // Getting the initial size width/height factor.
    const float get_factor_height() const { return factor_height ; } ;
  
  
    const float get_ouput_width()  const { return width  ; } ;
  
    const float get_ouput_height() const { return height ; } ;
} ;

#endif
