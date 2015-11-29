#ifndef EDIP_CONTROLLER_HH
#define EDIP_CONTROLLER_HH

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

#include <string>
#include <vector>

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include "libedip.hpp"

using namespace std ;

class Controller {

  private :  // Private members.

    pair<int, int> layout_size      ;
    pair<int, int> window_size      ;

    string filepath        ;

    bool is_image_size_gt_layout = false ;

  private :

    void set_sizes_controller_from_images(cv::Mat &frame) ;  // Resize image and set variables.

    void clear_undo_redo_frame_vector() ; // Clear image_to_display_vector.

    void check_undo() ;  // Check if has_undo and process in case of new action after undoing.

  public : // Saving file.

      struct {

        string extension ;
        string filepath  ;

        int width  ;
        int height ;

        bool auto_size = false ;

        bool resizing = false  ;

        bool apply = false ;

        bool focus_width = false ;

        cv::Mat file_frame ;

      } file_saving ;

      struct {


        int jpeg_progressiv     = 0   ;  // 0 or 1.  // Enable JPEG features
        int jpeg_optimize       = 0   ;  // 0 or 1.  // Enable JPEG features
        int jpeg_rst_interval   = 0   ;  // 0-65535. // JPEG restart interval. (0 no restart).

        int jpeg_quality        = 95  ;

        int jpeg_luma_quality   = 0   ; // 0-100 (0 don't use).  // Separate luma quality level.
        int jpeg_chroma_quality = 0   ; // 0-100 (0 don't use).  // Separate chroma quality level.

      } jpeg_settings ;

    struct {

        int png_compression = 3 ;  // 0 to 9. Comptression level.
        int png_strategy    = 0 ;  // IMWRITE_PNG_STRATEGY_DEFAULT
        int png_bilevel     = 0 ;  // 0 or 1. // Binary level PNG

    } png_settings ;

    struct {

      int pxm_binary = 1 ; // 0 or 1 ; //For PPM, PGM, or PBM, it can be a binary format flag.

    } pxm_settings ;

    struct {

      int webp_quality = 100 ; // 0-100. // 100 the lossless compression.

    } webp_settings ;


  public :  // Default and storing settings about configurable filters.

      // Default and storing settings of morphological filter:
      int      morphological_kernel_type   = 0    ;
      double   morphological_kernel_size   = 3.0  ;
      int      morphological_center_value  = 0    ;
      int      morphological_operator_type = 0    ;
      double   morphological_iterations    = 1.0  ;

      // Default and storing settings of sharpen kernel filter:
      int      kernel_sharpen_kernel_type            = 0    ;
      double   kernel_sharpen_kernel_size            = 3.0  ;
      double   kernel_sharpen_kernel_values_factor   = 1.0  ;
      double   kernel_sharpen_kernel_center_factor   = 1.0  ;

      // Default and storing settings of find edges filter:
      int      kernel_find_edges_kernel_type            = 0    ;
      double   kernel_find_edges_kernel_size            = 3.0  ;
      double   kernel_find_edges_kernel_values_factor   = 1.0  ;
      double   kernel_find_edges_kernel_center_factor   = 1.0  ;

      // Default and storing settings of kernel emboss filter:
      double   kernel_emboss_kernel_size            = 3.0  ;
      double   kernel_emboss_kernel_values_factor   = 1.0  ;
      double   kernel_emboss_kernel_center_factor   = 1.0  ;

      // Default and storing settings of mean kernel filter:
      int      kernel_mean_kernel_type            = 0    ;
      double   kernel_mean_kernel_size            = 3.0  ;

      // Default and storing settings of gaussian kernel filter:
      int      kernel_gaussian_kernel_type        = 0    ;
      double   kernel_gaussian_kernel_size        = 3.0  ;
      double   kernel_gaussian_sigma_value        = 1.2  ;

      // Default and storing settings of kirsch kernel filter:
      int      kernel_kirsch_kernel_direction     = 0    ;
      double   kernel_kirsch_kernel_size          = 3.0  ;
      double   kernel_kirsch_kernel_values_factor = 1.0  ;

      // Default and storing settings of multiply colors filter:
      double   mult_red       = 1.0    ;
      double   mult_green     = 1.0    ;
      double   mult_blue      = 1.0    ;
      double   mult_alpha     = 1.0    ;

      // Default and storing settings of multiply global intensity filter:
      double   mult_global_intensity_factor = 1.0    ;

      // Default and storing settings of canny filter:
      double canny_min_threshold = 100.0 ;
      double canny_max_threshold = 200.0 ;
      bool   canny_invert        = false ;

      // Default and storing settings of color contours filter:
      double color_contours_min_threshold = 100.0 ;
      double color_contours_max_threshold = 200.0 ;

      // Default and storing settings of pencil sketch filter:
      double pencil_sketch_sigma_s      = 60.0 ;
      double pencil_sketch_sigma_r      = 0.07 ;
      double pencil_sketch_shade_factor = 0.02 ;

      // Default and storing settings of stylisation filter:
      double stylisation_sigma_s      = 60.0 ;
      double stylisation_sigma_r      = 0.45 ;

      // Default and storing settings of detail enchance filter:
      double detail_enhance_sigma_s      = 60.0 ;
      double detail_enhance_sigma_r      = 0.4  ;

      // Default and storing settings of edge perserving filter:
      double edge_preserving_sigma_s      = 60.0 ;
      double edge_preserving_sigma_r      = 0.4  ;
      int    edge_preserving_filter       = 0    ;

      // Default and storing settings of denoising filter:
      double denoising_luminance      =  7.0 ;
      double denoising_colors         = 10.0 ;

  public :  // Drawning functionality members.

    // Coords into image (not widget relativ).
    int mouse_inside_image_x ;
    int mouse_inside_image_y ;


    // Is mouse into displayed image.
    bool mouse_into_image = false ;

    // The point to zoom on.
    float mouse_zoom_center_x ;
    float mouse_zoom_center_y ;

    // Zoom management members
    uint32_t zoom_idx               ;
    uint32_t zoom_counter   = 0     ;

    // 1.05 is a good factor because:                     (width+height)/2   /  (width+height) * 10) is always equal to 0.05
    // per example for size 600x400 (to obtains 1.05) ->    (600+400)  / 2   / (  (600+400)    * 10)                 == 0.05  + 1.0
    const double zoom_factor_plus  = 1.05 ;


    // Drawning factors: relationship between the displayed and the real size image.
    float factor_width  = 1.0f ;
    float factor_height = 1.0f ;


    int     config_draw_success            ;  // Response of drawning polygon or star configuration dialog.
    int     draw_thickness = 2             ;  // Draw thickness.
    double  draw_offset = 0.0              ;  // Draw polygon and star offset.


    // Polylines settings.
    vector<cv::Point> polylines     ;  // Vector of coordinates.
    int  polylines_points_nb = 0    ;  // Number of points.
    cv::Rect polylines_start_rect   ;  // Rectangle to join first last point detection.

    // Polygon drawning settings.
    int     polygon_edges  = 3             ;
    double  polygon_offset = 0.0           ;
    bool    polygon_strikethrough = false  ;

    // Star drawning settings.
    int     star_pikes                     ;
    double  star_offset                    ;
    bool    star_strikethrough = false     ;
    bool    star_flower = false            ;
    bool    star_strokes = false           ;
    bool    star_correcting = true         ;

    // Draw text settings.
    string  put_text_string                ;
    int     put_text_font_face             ;
    int     put_text_font_face_id = 0      ;
    double  put_text_font_scale   = 2.0    ;
    bool    put_text_is_italic    = false  ;


    // Drawning coordinates on real (size) image.
    float mouse_draw_x1 ;
    float mouse_draw_y1 ;
    float mouse_draw_x2 ;
    float mouse_draw_y2 ;

    // Drawning control variable.
    int8_t drawning_status = -1 ;

    // Cursor displaying control variable.
    int8_t mouse_curser_changed = 0 ;  // -1 == default curser | 0 == set cursor | 1 == mouse cursor set.


  public :  // Main members.

    // Is an image currently loaded.
    bool image_file_loaded = false ;

    // tmp frame for drawning displaying.
    cv::Mat saved_frame                      ;

    // Image to process.
    cv::Mat current_image_to_process         ;

    // Image to display.
    cv::Mat current_image_to_display         ;

    // Undo-Redo vector.
    vector<cv::Mat> image_to_display_vector  ;
    uint32_t image_to_display_vector_idx = 0 ;

    // Undo control variable.
    bool has_undo = false ;

    // Images sizes.
    pair<int, int> display_image_size     ;
    pair<int, int> source_image_size      ;

    // Image position.
    pair<int, int> current_image_position ;


  public :  // Contructor.

    Controller() {} ;

  public : // Setters.

    void set_layout_size(int width, int height) { layout_size.first = width ; layout_size.second = height ; }

    void set_window_size(int width, int height) { window_size.first = width ; window_size.second = height ; }


    void set_filepath(const string path) { filepath = path ; } ;

    const bool set_image_gt_layout(const cv::Mat frame) ;

  public : // Getters.

    const pair<int, int> get_layout_size() const { return layout_size ; } ;

    const pair<int, int> get_window_size() const { return window_size ; } ;

    const bool get_image_size_gt_layout() const { return is_image_size_gt_layout ; }

    const bool get_image_lt_layout() const ;



  public : // Actors.

    void process_after_applying(cv::Mat frame = cv::Mat()) ;

    void reset_settings() ; // Set members at file loading.

    void reset_zoom_center(const cv::Mat frame) ;

    void get_current_image_position() ; // Set the value from the current_image_position member.

} ;


#endif