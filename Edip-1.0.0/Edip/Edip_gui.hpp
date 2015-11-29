#ifndef EDIP_GUI_HH
#define EDIP_GUI_HH


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


/** Standart libraries: **/
//#include <iostream>

#include <cstdlib>

//#include <cstdlib>
//#include <string>
#include <cmath>
#include <vector>
#include <string>

/** gtkmm widgets (only the needed widgets). **/
// Window widget:
#include <gtkmm/window.h>

// Container widgets:
#include <gtkmm/box.h>
#include <gtkmm/grid.h>
#include <gtkmm/frame.h>
#include <gtkmm/layout.h>
#include <gtkmm/notebook.h>
#include <gtkmm/buttonbox.h>
#include <gtkmm/expander.h>

// Buttons widgets:
#include <gtkmm/button.h>
#include <gtkmm/togglebutton.h>
#include <gtkmm/checkbutton.h>
#include <gtkmm/radiobutton.h>
#include <gtkmm/colorbutton.h>
#include <gtkmm/filechooserbutton.h>

#include <gtkmm/label.h>

#include <gtkmm/entry.h>

// Images widgets:
#include <gtkmm/image.h>

#include <gtkmm/stock.h>
//#include <gtkmm/separator.h>

#include <gtkmm/listbox.h>

#include <gtkmm/comboboxtext.h>

#include <gtkmm/textview.h>





#include <gtkmm/combobox.h>




// Adjustable widgets:
#include <gtkmm/scale.h>
#include <gtkmm/spinbutton.h>

#include <gtkmm/adjustment.h>

// Menu widgets:
#include <gtkmm/menubar.h>
#include <gtkmm/menu.h>
#include <gtkmm/menuitem.h>
#include <gtkmm/imagemenuitem.h>
#include <gtkmm/separatormenuitem.h>
#include <gtkmm/recentchoosermenu.h>
#include <gtkmm/recentmanager.h>

// Toplevel windows widgets:
#include <gtkmm/filechooserdialog.h>
#include <gtkmm/dialog.h>
#include <gtkmm/filefilter.h>
#include <gtkmm/messagedialog.h>
#include <gtkmm/aboutdialog.h>

// Others widgets:
#include <gtkmm/accelgroup.h>
#include <gtkmm/separator.h>
#include <gtkmm/tooltip.h>

// CSS support.
#include <gtkmm/cssprovider.h>
#include <gtkmm/styleprovider.h>


/** Other libraries **/
#include <gdkmm-3.0/gdkmm.h>
#include <glibmm.h>


/** libopencv: **/
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>




#include "Edip_Controller.hpp" // Edip Controller class declaration.
#include "Edip_define.hpp"     // Edip definitions.

#include "libedip.hpp"         // libedip

using namespace std ;

class GUI : public Gtk::Window {  // Class GUI inherit from the Gtk::Window class.

  /** GUI widgets declaration. **/

  // Main containers
  Gtk::Box       main_box       ;

  Gtk::Box       menu_box       ;
  Gtk::Box       buttonbar      ;
  Gtk::Box       middle_box     ;
  Gtk::Box       bottom_box     ;

  Gtk::Box       middle_box_v   ;

  // Menu
  Gtk::MenuBar     menu_bar                 ;
  Gtk::Menu        menu_files               ;
  Gtk::Menu        menu_edition             ;
  Gtk::Menu        menu_filters             ;
  Gtk::Menu        menu_kernel_filters      ;
  Gtk::Menu        menu_filters_filters     ;
  Gtk::Menu        menu_filters_grayscale   ;
  Gtk::Menu        menu_filters_colorscale  ;
  Gtk::Menu        menu_filters_photo       ;
  Gtk::Menu        menu_infos               ;
 
  // Menubuttons menu items:
  Gtk::MenuItem    menu_files_button             ;
  Gtk::Box         menu_files_button_container   ;
  Gtk::Image       menu_files_button_image       ;
  Gtk::Label       menu_files_button_label       ;

  Gtk::MenuItem    menu_edition_button             ;
  Gtk::Box         menu_edition_button_container   ;
  Gtk::Image       menu_edition_button_image       ;
  Gtk::Label       menu_edition_button_label       ;

  Gtk::MenuItem    menu_filters_button             ;
  Gtk::Box         menu_filters_button_container   ;
  Gtk::Image       menu_filters_button_image       ;
  Gtk::Label       menu_filters_button_label       ;
 
  Gtk::MenuItem    menu_infos_button             ;
  Gtk::Box         menu_infos_button_container   ;
  Gtk::Image       menu_infos_button_image       ;
  Gtk::Label       menu_infos_button_label       ;
 

  // Menuitems:
  Gtk::MenuItem    menu_files_open_file_button       ;
  Gtk::Box         menu_files_open_file_container    ;
  Gtk::Image       menu_files_open_file_image        ;
  Gtk::Label       menu_files_open_file_label        ;
  Gtk::Box         menu_files_open_file_padding      ;
  Gtk::Label       menu_files_open_file_accel_label  ;


  Gtk::MenuItem    menu_files_save_file_button       ;
  Gtk::Box         menu_files_save_file_container    ;
  Gtk::Image       menu_files_save_file_image        ;
  Gtk::Label       menu_files_save_file_label        ;
  Gtk::Box         menu_files_save_file_padding      ;
  Gtk::Label       menu_files_save_file_accel_label  ;


  Gtk::SeparatorMenuItem  menu_files_separator_01    ;

  Gtk::MenuItem    menu_files_recent_file_button       ;
  Gtk::Box         menu_files_recent_file_container    ;
  Gtk::Image       menu_files_recent_file_image        ;
  Gtk::Label       menu_files_recent_file_label        ;
  Gtk::Box         menu_files_recent_file_padding      ;
  Gtk::Label       menu_files_recent_file_accel_label  ;

  Glib::RefPtr<Gtk::RecentManager> recent_file_manager = Gtk::RecentManager::get_default() ;

  Glib::RefPtr<Gtk::RecentFilter> recent_files_filter = Gtk::RecentFilter::create() ;

  Gtk::RecentChooserMenu  menu_files_recent_files    ;

  Gtk::SeparatorMenuItem  menu_files_separator_02    ;

  Gtk::MenuItem    menu_files_blend_images_button       ;
  Gtk::Box         menu_files_blend_images_container    ;
  Gtk::Image       menu_files_blend_images_image        ;
  Gtk::Label       menu_files_blend_images_label        ;
  Gtk::Box         menu_files_blend_images_padding      ;
  Gtk::Label       menu_files_blend_images_accel_label  ;

  Gtk::MenuItem    menu_files_screen_images_button       ;
  Gtk::Box         menu_files_screen_images_container    ;
  Gtk::Image       menu_files_screen_images_image        ;
  Gtk::Label       menu_files_screen_images_label        ;
  Gtk::Box         menu_files_screen_images_padding      ;
  Gtk::Label       menu_files_screen_images_accel_label  ;

  Gtk::MenuItem    menu_files_darker_images_button       ;
  Gtk::Box         menu_files_darker_images_container    ;
  Gtk::Image       menu_files_darker_images_image        ;
  Gtk::Label       menu_files_darker_images_label        ;
  Gtk::Box         menu_files_darker_images_padding      ;
  Gtk::Label       menu_files_darker_images_accel_label  ;

  Gtk::MenuItem    menu_files_lighter_images_button       ;
  Gtk::Box         menu_files_lighter_images_container    ;
  Gtk::Image       menu_files_lighter_images_image        ;
  Gtk::Label       menu_files_lighter_images_label        ;
  Gtk::Box         menu_files_lighter_images_padding      ;
  Gtk::Label       menu_files_lighter_images_accel_label  ;

  Gtk::MenuItem    menu_files_add_images_button       ;
  Gtk::Box         menu_files_add_images_container    ;
  Gtk::Image       menu_files_add_images_image        ;
  Gtk::Label       menu_files_add_images_label        ;
  Gtk::Box         menu_files_add_images_padding      ;
  Gtk::Label       menu_files_add_images_accel_label  ;

  Gtk::MenuItem    menu_files_add_modulo_images_button       ;
  Gtk::Box         menu_files_add_modulo_images_container    ;
  Gtk::Image       menu_files_add_modulo_images_image        ;
  Gtk::Label       menu_files_add_modulo_images_label        ;
  Gtk::Box         menu_files_add_modulo_images_padding      ;
  Gtk::Label       menu_files_add_modulo_images_accel_label  ;

  Gtk::MenuItem    menu_files_sub_images_button       ;
  Gtk::Box         menu_files_sub_images_container    ;
  Gtk::Image       menu_files_sub_images_image        ;
  Gtk::Label       menu_files_sub_images_label        ;
  Gtk::Box         menu_files_sub_images_padding      ;
  Gtk::Label       menu_files_sub_images_accel_label  ;

  Gtk::MenuItem    menu_files_sub_modulo_images_button       ;
  Gtk::Box         menu_files_sub_modulo_images_container    ;
  Gtk::Image       menu_files_sub_modulo_images_image        ;
  Gtk::Label       menu_files_sub_modulo_images_label        ;
  Gtk::Box         menu_files_sub_modulo_images_padding      ;
  Gtk::Label       menu_files_sub_modulo_images_accel_label  ;


  Gtk::MenuItem    menu_edition_undo_button       ;
  Gtk::Box         menu_edition_undo_container    ;
  Gtk::Image       menu_edition_undo_image        ;
  Gtk::Label       menu_edition_undo_label        ;
  Gtk::Box         menu_edition_undo_padding      ;
  Gtk::Label       menu_edition_undo_accel_label  ;

  Gtk::MenuItem    menu_edition_redo_button       ;
  Gtk::Box         menu_edition_redo_container    ;
  Gtk::Image       menu_edition_redo_image        ;
  Gtk::Label       menu_edition_redo_label        ;
  Gtk::Box         menu_edition_redo_padding      ;
  Gtk::Label       menu_edition_redo_accel_label  ;


  Gtk::SeparatorMenuItem menu_edition_separator_01 ;


  Gtk::MenuItem    menu_edition_rotate_left_button       ;
  Gtk::Box         menu_edition_rotate_left_container    ;
  Gtk::Image       menu_edition_rotate_left_image        ;
  Gtk::Label       menu_edition_rotate_left_label        ;
  Gtk::Box         menu_edition_rotate_left_padding      ;
  Gtk::Label       menu_edition_rotate_left_accel_label  ;

  Gtk::MenuItem    menu_edition_rotate_right_button       ;
  Gtk::Box         menu_edition_rotate_right_container    ;
  Gtk::Image       menu_edition_rotate_right_image        ;
  Gtk::Label       menu_edition_rotate_right_label        ;
  Gtk::Box         menu_edition_rotate_right_padding      ;
  Gtk::Label       menu_edition_rotate_right_accel_label  ;


  Gtk::SeparatorMenuItem menu_edition_separator_02 ;


  Gtk::MenuItem    menu_edition_mirror_left_to_right_button       ;
  Gtk::Box         menu_edition_mirror_left_to_right_container    ;
  Gtk::Image       menu_edition_mirror_left_to_right_image        ;
  Gtk::Label       menu_edition_mirror_left_to_right_label        ;
  Gtk::Box         menu_edition_mirror_left_to_right_padding      ;
  Gtk::Label       menu_edition_mirror_left_to_right_accel_label  ;

  Gtk::MenuItem    menu_edition_mirror_right_to_left_button       ;
  Gtk::Box         menu_edition_mirror_right_to_left_container    ;
  Gtk::Image       menu_edition_mirror_right_to_left_image        ;
  Gtk::Label       menu_edition_mirror_right_to_left_label        ;
  Gtk::Box         menu_edition_mirror_right_to_left_padding      ;
  Gtk::Label       menu_edition_mirror_right_to_left_accel_label  ;

  Gtk::MenuItem    menu_edition_mirror_up_to_down_button       ;
  Gtk::Box         menu_edition_mirror_up_to_down_container    ;
  Gtk::Image       menu_edition_mirror_up_to_down_image        ;
  Gtk::Label       menu_edition_mirror_up_to_down_label        ;
  Gtk::Box         menu_edition_mirror_up_to_down_padding      ;
  Gtk::Label       menu_edition_mirror_up_to_down_accel_label  ;

  Gtk::MenuItem    menu_edition_mirror_down_to_up_button       ;
  Gtk::Box         menu_edition_mirror_down_to_up_container    ;
  Gtk::Image       menu_edition_mirror_down_to_up_image        ;
  Gtk::Label       menu_edition_mirror_down_to_up_label        ;
  Gtk::Box         menu_edition_mirror_down_to_up_padding      ;
  Gtk::Label       menu_edition_mirror_down_to_up_accel_label  ;


  Gtk::SeparatorMenuItem menu_edition_separator_03 ;

  Gtk::MenuItem    menu_edition_zoom_plus_button       ;
  Gtk::Box         menu_edition_zoom_plus_container    ;
  Gtk::Image       menu_edition_zoom_plus_image        ;
  Gtk::Label       menu_edition_zoom_plus_label        ;
  Gtk::Box         menu_edition_zoom_plus_padding      ;
  Gtk::Label       menu_edition_zoom_plus_accel_label  ;

  Gtk::MenuItem    menu_edition_zoom_minus_button       ;
  Gtk::Box         menu_edition_zoom_minus_container    ;
  Gtk::Image       menu_edition_zoom_minus_image        ;
  Gtk::Label       menu_edition_zoom_minus_label        ;
  Gtk::Box         menu_edition_zoom_minus_padding      ;
  Gtk::Label       menu_edition_zoom_minus_accel_label  ;

  Gtk::MenuItem    menu_edition_zoom_set_button       ;
  Gtk::Box         menu_edition_zoom_set_container    ;
  Gtk::Image       menu_edition_zoom_set_image        ;
  Gtk::Label       menu_edition_zoom_set_label        ;
  Gtk::Box         menu_edition_zoom_set_padding      ;
  Gtk::Label       menu_edition_zoom_set_accel_label  ;


  Gtk::SeparatorMenuItem menu_edition_separator_04 ;


  Gtk::MenuItem    menu_edition_flip_left_button       ;
  Gtk::Box         menu_edition_flip_left_container    ;
  Gtk::Image       menu_edition_flip_left_image        ;
  Gtk::Label       menu_edition_flip_left_label        ;
  Gtk::Box         menu_edition_flip_left_padding      ;
  Gtk::Label       menu_edition_flip_left_accel_label  ;

  Gtk::MenuItem    menu_edition_flip_right_button       ;
  Gtk::Box         menu_edition_flip_right_container    ;
  Gtk::Image       menu_edition_flip_right_image        ;
  Gtk::Label       menu_edition_flip_right_label        ;
  Gtk::Box         menu_edition_flip_right_padding      ;
  Gtk::Label       menu_edition_flip_right_accel_label  ;

  Gtk::MenuItem    menu_edition_flip_up_button       ;
  Gtk::Box         menu_edition_flip_up_container    ;
  Gtk::Image       menu_edition_flip_up_image        ;
  Gtk::Label       menu_edition_flip_up_label        ;
  Gtk::Box         menu_edition_flip_up_padding      ;
  Gtk::Label       menu_edition_flip_up_accel_label  ;

  Gtk::MenuItem    menu_edition_flip_down_button       ;
  Gtk::Box         menu_edition_flip_down_container    ;
  Gtk::Image       menu_edition_flip_down_image        ;
  Gtk::Label       menu_edition_flip_down_label        ;
  Gtk::Box         menu_edition_flip_down_padding      ;
  Gtk::Label       menu_edition_flip_down_accel_label  ;



  Gtk::MenuItem    menu_filters_filters_button       ;
  Gtk::Box         menu_filters_filters_container    ;
  Gtk::Image       menu_filters_filters_image        ;
  Gtk::Label       menu_filters_filters_label        ;
  Gtk::Box         menu_filters_filters_padding      ;
  Gtk::Label       menu_filters_filters_accel_label  ;

  Gtk::MenuItem    menu_filters_morphological_button       ;
  Gtk::Box         menu_filters_morphological_container    ;
  Gtk::Image       menu_filters_morphological_image        ;
  Gtk::Label       menu_filters_morphological_label        ;
  Gtk::Box         menu_filters_morphological_padding      ;
  Gtk::Label       menu_filters_morphological_accel_label  ;

  Gtk::MenuItem    menu_filters_kernel_filters_button       ;
  Gtk::Box         menu_filters_kernel_filters_container    ;
  Gtk::Image       menu_filters_kernel_filters_image        ;
  Gtk::Label       menu_filters_kernel_filters_label        ;
  Gtk::Box         menu_filters_kernel_filters_padding      ;
  Gtk::Label       menu_filters_kernel_filters_accel_label  ;

  Gtk::ImageMenuItem    menu_filters_kernel_sharpen_button    ;
  Gtk::Image            menu_filters_kernel_sharpen_image     ;


  Gtk::ImageMenuItem    menu_filters_kernel_find_edges_button ;
  Gtk::Image            menu_filters_kernel_find_edges_image  ;


  Gtk::ImageMenuItem    menu_filters_kernel_emboss_button     ;
  Gtk::Image            menu_filters_kernel_emboss_image      ;


  Gtk::ImageMenuItem    menu_filters_kernel_mean_button       ;
  Gtk::Image            menu_filters_kernel_mean_image        ;


  Gtk::ImageMenuItem    menu_filters_kernel_gaussian_button   ;
  Gtk::Image            menu_filters_kernel_gaussian_image    ;


  Gtk::ImageMenuItem    menu_filters_kernel_kirsch_button     ;
  Gtk::Image            menu_filters_kernel_kirsch_image      ;


  Gtk::MenuItem    menu_filters_photo_filters_button       ;
  Gtk::Box         menu_filters_photo_filters_container    ;
  Gtk::Image       menu_filters_photo_filters_image        ;
  Gtk::Label       menu_filters_photo_filters_label        ;
  Gtk::Box         menu_filters_photo_filters_padding      ;
  Gtk::Label       menu_filters_photo_filters_accel_label  ;

  Gtk::ImageMenuItem    menu_filters_photo_pencil_sketch_button     ;
  Gtk::Image            menu_filters_photo_pencil_sketch_image      ;

  Gtk::ImageMenuItem    menu_filters_photo_stylisation_button     ;
  Gtk::Image            menu_filters_photo_stylisation_image      ;

  Gtk::ImageMenuItem    menu_filters_photo_detail_enhance_button     ;
  Gtk::Image            menu_filters_photo_detail_enhance_image      ;

  Gtk::ImageMenuItem    menu_filters_photo_edges_preserving_button     ;
  Gtk::Image            menu_filters_photo_edges_preserving_image      ;

  Gtk::ImageMenuItem    menu_filters_photo_denoising_button     ;
  Gtk::Image            menu_filters_photo_denoising_image      ;

  Gtk::MenuItem    menu_filters_canny_button       ;
  Gtk::Box         menu_filters_canny_container    ;
  Gtk::Image       menu_filters_canny_image        ;
  Gtk::Label       menu_filters_canny_label        ;
  Gtk::Box         menu_filters_canny_padding      ;
  Gtk::Label       menu_filters_canny_accel_label  ;

  Gtk::MenuItem    menu_filters_color_contours_button       ;
  Gtk::Box         menu_filters_color_contours_container    ;
  Gtk::Image       menu_filters_color_contours_image        ;
  Gtk::Label       menu_filters_color_contours_label        ;
  Gtk::Box         menu_filters_color_contours_padding      ;
  Gtk::Label       menu_filters_color_contours_accel_label  ;




  Gtk::SeparatorMenuItem  menu_filters_separator_01    ;

  Gtk::MenuItem    menu_filters_grayscale_button       ;
  Gtk::Box         menu_filters_grayscale_container    ;
  Gtk::Image       menu_filters_grayscale_image        ;
  Gtk::Label       menu_filters_grayscale_label        ;
  Gtk::Box         menu_filters_grayscale_padding      ;
  Gtk::Label       menu_filters_grayscale_accel_label  ;

  Gtk::SeparatorMenuItem  menu_filters_separator_02    ;

  Gtk::MenuItem    menu_filters_colorscale_button       ;
  Gtk::Box         menu_filters_colorscale_container    ;
  Gtk::Image       menu_filters_colorscale_image        ;
  Gtk::Label       menu_filters_colorscale_label        ;
  Gtk::Box         menu_filters_colorscale_padding      ;
  Gtk::Label       menu_filters_colorscale_accel_label  ;


  Gtk::MenuItem    menu_filters_mult_colors_button       ;
  Gtk::Box         menu_filters_mult_colors_container    ;
  Gtk::Image       menu_filters_mult_colors_image        ;
  Gtk::Label       menu_filters_mult_colors_label        ;
  Gtk::Box         menu_filters_mult_colors_padding      ;
  Gtk::Label       menu_filters_mult_colors_accel_label  ;

  Gtk::MenuItem    menu_filters_set_in_color_tone_button       ;
  Gtk::Box         menu_filters_set_in_color_tone_container    ;
  Gtk::Image       menu_filters_set_in_color_tone_image        ;
  Gtk::Label       menu_filters_set_in_color_tone_label        ;
  Gtk::Box         menu_filters_set_in_color_tone_padding      ;
  Gtk::Label       menu_filters_set_in_color_tone_accel_label  ;

  Gtk::MenuItem    menu_filters_mult_intensity_button       ;
  Gtk::Box         menu_filters_mult_intensity_container    ;
  Gtk::Image       menu_filters_mult_intensity_image        ;
  Gtk::Label       menu_filters_mult_intensity_label        ;
  Gtk::Box         menu_filters_mult_intensity_padding      ;
  Gtk::Label       menu_filters_mult_intensity_accel_label  ;


  Gtk::Image            menu_filters_filters_image_00   ;
  Gtk::Image            menu_filters_filters_image_01   ;
  Gtk::Image            menu_filters_filters_image_02   ;
  Gtk::Image            menu_filters_filters_image_03   ;
  Gtk::Image            menu_filters_filters_image_04   ;
  Gtk::Image            menu_filters_filters_image_05   ;
  Gtk::Image            menu_filters_filters_image_06   ;
  Gtk::Image            menu_filters_filters_image_07   ;
  Gtk::Image            menu_filters_filters_image_08   ;
  Gtk::Image            menu_filters_filters_image_09   ;
  Gtk::Image            menu_filters_filters_image_10   ;
  Gtk::Image            menu_filters_filters_image_11   ;
  Gtk::Image            menu_filters_filters_image_12   ;
  Gtk::Image            menu_filters_filters_image_13   ;
  Gtk::Image            menu_filters_filters_image_14   ;
  Gtk::Image            menu_filters_filters_image_15   ;
  Gtk::Image            menu_filters_filters_image_16   ;
  Gtk::Image            menu_filters_filters_image_17   ;
  Gtk::Image            menu_filters_filters_image_18   ;
  Gtk::Image            menu_filters_filters_image_19   ;
  Gtk::Image            menu_filters_filters_image_20   ;
  Gtk::Image            menu_filters_filters_image_21   ;
  Gtk::Image            menu_filters_filters_image_22   ;
  Gtk::Image            menu_filters_filters_image_23   ;
  Gtk::Image            menu_filters_filters_image_24   ;
  Gtk::Image            menu_filters_filters_image_25   ;
  Gtk::Image            menu_filters_filters_image_26   ;
  Gtk::Image            menu_filters_filters_image_27   ;
  Gtk::Image            menu_filters_filters_image_28   ;
  Gtk::Image            menu_filters_filters_image_29   ;
  Gtk::Image            menu_filters_filters_image_30   ;
  Gtk::Image            menu_filters_filters_image_31   ;
  Gtk::Image            menu_filters_filters_image_32   ;
  Gtk::Image            menu_filters_filters_image_33   ;
  Gtk::Image            menu_filters_filters_image_34   ;
  Gtk::Image            menu_filters_filters_image_35   ;
  Gtk::Image            menu_filters_filters_image_36   ;
  Gtk::Image            menu_filters_filters_image_37   ;
  Gtk::Image            menu_filters_filters_image_38   ;



  Gtk::ImageMenuItem    menu_filters_filters_00      ;
  Gtk::ImageMenuItem    menu_filters_filters_01      ;
  Gtk::ImageMenuItem    menu_filters_filters_02      ;
  Gtk::ImageMenuItem    menu_filters_filters_03      ;
  Gtk::ImageMenuItem    menu_filters_filters_04      ;
  Gtk::ImageMenuItem    menu_filters_filters_05      ;
  Gtk::ImageMenuItem    menu_filters_filters_06      ;
  Gtk::ImageMenuItem    menu_filters_filters_07      ;
  Gtk::ImageMenuItem    menu_filters_filters_08      ;
  Gtk::ImageMenuItem    menu_filters_filters_09      ;
  Gtk::ImageMenuItem    menu_filters_filters_10      ;
  Gtk::ImageMenuItem    menu_filters_filters_11      ;
  Gtk::ImageMenuItem    menu_filters_filters_12      ;
  Gtk::ImageMenuItem    menu_filters_filters_13      ;
  Gtk::ImageMenuItem    menu_filters_filters_14      ;
  Gtk::ImageMenuItem    menu_filters_filters_15      ;
  Gtk::ImageMenuItem    menu_filters_filters_16      ;
  Gtk::ImageMenuItem    menu_filters_filters_17      ;
  Gtk::ImageMenuItem    menu_filters_filters_18      ;
  Gtk::ImageMenuItem    menu_filters_filters_19      ;
  Gtk::ImageMenuItem    menu_filters_filters_20      ;
  Gtk::ImageMenuItem    menu_filters_filters_21      ;
  Gtk::ImageMenuItem    menu_filters_filters_22      ;
  Gtk::ImageMenuItem    menu_filters_filters_23      ;
  Gtk::ImageMenuItem    menu_filters_filters_24      ;
  Gtk::ImageMenuItem    menu_filters_filters_25      ;
  Gtk::ImageMenuItem    menu_filters_filters_26      ;
  Gtk::ImageMenuItem    menu_filters_filters_27      ;
  Gtk::ImageMenuItem    menu_filters_filters_28      ;
  Gtk::ImageMenuItem    menu_filters_filters_29      ;
  Gtk::ImageMenuItem    menu_filters_filters_30      ;
  Gtk::ImageMenuItem    menu_filters_filters_31      ;
  Gtk::ImageMenuItem    menu_filters_filters_32      ;
  Gtk::ImageMenuItem    menu_filters_filters_33      ;
  Gtk::ImageMenuItem    menu_filters_filters_34      ;
  Gtk::ImageMenuItem    menu_filters_filters_35      ;
  Gtk::ImageMenuItem    menu_filters_filters_36      ;
  Gtk::ImageMenuItem    menu_filters_filters_37      ;
  Gtk::ImageMenuItem    menu_filters_filters_38      ;

  Gtk::Image            menu_filters_grayscale_image_00   ;
  Gtk::Image            menu_filters_grayscale_image_01   ;
  Gtk::Image            menu_filters_grayscale_image_02   ;
  Gtk::Image            menu_filters_grayscale_image_03   ;
  Gtk::Image            menu_filters_grayscale_image_04   ;
  Gtk::Image            menu_filters_grayscale_image_05   ;



  Gtk::ImageMenuItem    menu_filters_grayscale_00      ;
  Gtk::ImageMenuItem    menu_filters_grayscale_01      ;
  Gtk::ImageMenuItem    menu_filters_grayscale_02      ;
  Gtk::ImageMenuItem    menu_filters_grayscale_03      ;
  Gtk::ImageMenuItem    menu_filters_grayscale_04      ;
  Gtk::ImageMenuItem    menu_filters_grayscale_05      ;



  Gtk::Image            menu_filters_colorscale_image_00   ;
  Gtk::Image            menu_filters_colorscale_image_01   ;
  Gtk::Image            menu_filters_colorscale_image_02   ;
  Gtk::Image            menu_filters_colorscale_image_03   ;
  Gtk::Image            menu_filters_colorscale_image_04   ;
  Gtk::Image            menu_filters_colorscale_image_05   ;
  Gtk::Image            menu_filters_colorscale_image_06   ;
  Gtk::Image            menu_filters_colorscale_image_07   ;
  Gtk::Image            menu_filters_colorscale_image_08   ;
  Gtk::Image            menu_filters_colorscale_image_09   ;
  Gtk::Image            menu_filters_colorscale_image_10   ;
  Gtk::Image            menu_filters_colorscale_image_11   ;
  Gtk::Image            menu_filters_colorscale_image_12   ;
  Gtk::Image            menu_filters_colorscale_image_13   ;
  Gtk::Image            menu_filters_colorscale_image_14   ;
  Gtk::Image            menu_filters_colorscale_image_15   ;
  Gtk::Image            menu_filters_colorscale_image_16   ;
  Gtk::Image            menu_filters_colorscale_image_17   ;
  Gtk::Image            menu_filters_colorscale_image_18   ;
  Gtk::Image            menu_filters_colorscale_image_19   ;
  Gtk::Image            menu_filters_colorscale_image_20   ;
  Gtk::Image            menu_filters_colorscale_image_21   ;
  Gtk::Image            menu_filters_colorscale_image_22   ;
  Gtk::Image            menu_filters_colorscale_image_23   ;
  Gtk::Image            menu_filters_colorscale_image_24   ;
  Gtk::Image            menu_filters_colorscale_image_25   ;
  Gtk::Image            menu_filters_colorscale_image_26   ;
  Gtk::Image            menu_filters_colorscale_image_27   ;
  Gtk::Image            menu_filters_colorscale_image_28   ;
  Gtk::Image            menu_filters_colorscale_image_29   ;
  Gtk::Image            menu_filters_colorscale_image_30   ;
  Gtk::Image            menu_filters_colorscale_image_31   ;
  Gtk::Image            menu_filters_colorscale_image_32   ;



  Gtk::ImageMenuItem    menu_filters_colorscale_00      ;
  Gtk::ImageMenuItem    menu_filters_colorscale_01      ;
  Gtk::ImageMenuItem    menu_filters_colorscale_02      ;
  Gtk::ImageMenuItem    menu_filters_colorscale_03      ;
  Gtk::ImageMenuItem    menu_filters_colorscale_04      ;
  Gtk::ImageMenuItem    menu_filters_colorscale_05      ;
  Gtk::ImageMenuItem    menu_filters_colorscale_06      ;
  Gtk::ImageMenuItem    menu_filters_colorscale_07      ;
  Gtk::ImageMenuItem    menu_filters_colorscale_08      ;
  Gtk::ImageMenuItem    menu_filters_colorscale_09      ;
  Gtk::ImageMenuItem    menu_filters_colorscale_10      ;
  Gtk::ImageMenuItem    menu_filters_colorscale_11      ;
  Gtk::ImageMenuItem    menu_filters_colorscale_12      ;
  Gtk::ImageMenuItem    menu_filters_colorscale_13      ;
  Gtk::ImageMenuItem    menu_filters_colorscale_14      ;
  Gtk::ImageMenuItem    menu_filters_colorscale_15      ;
  Gtk::ImageMenuItem    menu_filters_colorscale_16      ;
  Gtk::ImageMenuItem    menu_filters_colorscale_17      ;
  Gtk::ImageMenuItem    menu_filters_colorscale_18      ;
  Gtk::ImageMenuItem    menu_filters_colorscale_19      ;
  Gtk::ImageMenuItem    menu_filters_colorscale_20      ;
  Gtk::ImageMenuItem    menu_filters_colorscale_21      ;
  Gtk::ImageMenuItem    menu_filters_colorscale_22      ;
  Gtk::ImageMenuItem    menu_filters_colorscale_23      ;
  Gtk::ImageMenuItem    menu_filters_colorscale_24      ;
  Gtk::ImageMenuItem    menu_filters_colorscale_25      ;
  Gtk::ImageMenuItem    menu_filters_colorscale_26      ;
  Gtk::ImageMenuItem    menu_filters_colorscale_27      ;
  Gtk::ImageMenuItem    menu_filters_colorscale_28      ;
  Gtk::ImageMenuItem    menu_filters_colorscale_29      ;
  Gtk::ImageMenuItem    menu_filters_colorscale_30      ;
  Gtk::ImageMenuItem    menu_filters_colorscale_31      ;
  Gtk::ImageMenuItem    menu_filters_colorscale_32      ;
 
  Gtk::MenuItem    menu_infos_readme_button       ;
  Gtk::Box         menu_infos_readme_container    ;
  Gtk::Image       menu_infos_readme_image        ;
  Gtk::Label       menu_infos_readme_label        ;
  Gtk::Box         menu_infos_readme_padding      ;
  Gtk::Label       menu_infos_readme_accel_label  ;
 
  Gtk::MenuItem    menu_infos_documentation_button       ;
  Gtk::Box         menu_infos_documentation_container    ;
  Gtk::Image       menu_infos_documentation_image        ;
  Gtk::Label       menu_infos_documentation_label        ;
  Gtk::Box         menu_infos_documentation_padding      ;
  Gtk::Label       menu_infos_documentation_accel_label  ;
 
  Gtk::MenuItem    menu_infos_about_button       ;
  Gtk::Box         menu_infos_about_container    ;
  Gtk::Image       menu_infos_about_image        ;
  Gtk::Label       menu_infos_about_label        ;
  Gtk::Box         menu_infos_about_padding      ;
  Gtk::Label       menu_infos_about_accel_label  ;

  // Padding in buttonbar.
  Gtk::ButtonBox padding_buttonbox_1   ;


  // Buttonbar component 1: files handling.
  Gtk::ButtonBox buttonbox_files        ;
  Gtk::Button button_open               ;
  Gtk::Button button_save               ;

  Gtk::Image image_open                 ;
  Gtk::Image image_save                 ;


  // Padding in buttonbar.
  Gtk::ButtonBox padding_buttonbox_2    ;


  // Buttonbar component 2: Edition (Undo Redo) handling.
  Gtk::ButtonBox buttonbox_undo_redo    ;
  Gtk::Button button_undo               ;
  Gtk::Button button_redo               ;

  Gtk::Image image_undo                 ;
  Gtk::Image image_redo                 ;


  // Padding in buttonbar.
  Gtk::ButtonBox padding_buttonbox_3    ;


  // Buttonbar component 3: Image rotation handling.
  Gtk::ButtonBox  buttonbox_rot         ;
  Gtk::Button     button_rot_label      ;
  Gtk::Button     button_rot_left       ;
  Gtk::Button     button_rot_right      ;

  Gtk::Image      image_rot_left        ;
  Gtk::Image      image_rot_right       ;

  // Padding in buttonbar.
  Gtk::ButtonBox padding_buttonbox_4    ;


  // Buttonbar component 3: Image rotation handling.
  Gtk::ButtonBox  buttonbox_mirror         ;
  Gtk::Button     button_mirror_label      ;
  Gtk::Button     button_mirror_left       ;
  Gtk::Button     button_mirror_right      ;
  Gtk::Button     button_mirror_top        ;
  Gtk::Button     button_mirror_bottom     ;

  Gtk::Image      image_mirror_left        ;
  Gtk::Image      image_mirror_right       ;
  Gtk::Image      image_mirror_top         ;
  Gtk::Image      image_mirror_bottom     ;




  // Padding in buttonbar.
  Gtk::ButtonBox padding_buttonbox_5    ;


  // Buttonbar component 4: Image zoom handling.
  Gtk::ButtonBox    buttonbox_zoom      ;
  Gtk::Button       button_zoom_label   ;
  Gtk::Button       button_zoom_plus    ;
  Gtk::Button       button_zoom_minus   ;
  Gtk::ToggleButton button_zoom_pointer ;

  Gtk::Image image_zoom_plus            ;
  Gtk::Image image_zoom_minus           ;
  Gtk::Image image_zoom_pointer         ;


  // Padding in buttonbar.
  Gtk::ButtonBox padding_buttonbox_6    ;


  // Buttonbar component 4: Image flipping handling.
  Gtk::ButtonBox buttonbox_flip         ;
  Gtk::Button    button_flip_label      ;
  Gtk::Button    button_flip_left       ;
  Gtk::Button    button_flip_right      ;
  Gtk::Button    button_flip_up         ;
  Gtk::Button    button_flip_down       ;

  Gtk::Image image_flip_left            ;
  Gtk::Image image_flip_right           ;
  Gtk::Image image_flip_up              ;
  Gtk::Image image_flip_down            ;




  // Padding in buttonbar.
  Gtk::ButtonBox padding_buttonbox_7    ;





  // Main sidebar container.
  Gtk::Box   box_sidebar_main      ;
  // Box sidebar 01
  Gtk::Box   box_sidebar_01        ;
  // Convienence sidebar container.
  Gtk::Box   box_execute           ;


  // Sidebar part 1: filters, grayscaling and colorscaling.
  Gtk::Frame frame_sidebar_filters    ;
  Gtk::Frame frame_sidebar_grayscale  ;
  Gtk::Frame frame_sidebar_colorscale ;

  Gtk::Box          box_filters       ;
  Gtk::Box          box_grayscale     ;
  Gtk::Box          box_colorscale    ;


  Gtk::ComboBoxText combo_filters     ;
  Gtk::ComboBoxText combo_grayscale   ;
  Gtk::ComboBoxText combo_colorscale  ;

  Gtk::Entry *entry_combo_filters     ;
  Gtk::Entry *entry_combo_grayscale   ;
  Gtk::Entry *entry_combo_colorscale  ;

  Gtk::Button button_filters          ;
  Gtk::Button button_grayscale        ;
  Gtk::Button button_colorscale       ;

  Gtk::Image button_image_filters     ;
  Gtk::Image button_image_grayscale   ;
  Gtk::Image button_image_colorscale  ;



  // Sidebar part 2: Intensity and HSBL (Hue, Saturation, Brightness, Lightness) scaling,

  // Switching between Intensity and HSBL scaling.
  Gtk::Frame           frame_switcher           ;
  Gtk::Box             buttonbox_switcher       ;

  Gtk::RadioButton     button_intensity         ;
  Gtk::RadioButton     button_hsbl              ;

  Gtk::Image           image_switcher_on        ;
  Gtk::Image           image_switcher_off       ;

  Gtk::Notebook        notebook_switcher        ;



  // Main sidebar part 2 frames
  Gtk::Frame frame_sidebar_intensity  ;
  Gtk::Frame frame_sidebar_hsbl       ;

  // Main sidebar part 2 containers.
  Gtk::Box  box_intensity_rgbm        ;
  Gtk::Box  box_colorspace_hsbl       ;

  Gtk::Box  box_intensity_vertical    ;
  Gtk::Box  box_colorspace_vertical   ;

  // HSBL scaling interface.
  Gtk::Frame frame_lightness          ;
  Gtk::Frame frame_hue                ;
  Gtk::Frame frame_saturation         ;
  Gtk::Frame frame_brightness         ;


  Gtk::Scale scale_lightness          ;
  Gtk::Scale scale_hue                ;
  Gtk::Scale scale_saturation         ;
  Gtk::Scale scale_brightness         ;


  Gtk::ButtonBox buttonbox_hsbl_apply ;
  Gtk::Box box_hsbl_lightness         ;
  Gtk::Box box_hsbl_hue               ;
  Gtk::Box box_hsbl_saturation        ;
  Gtk::Box box_hsbl_brightness        ;


  Gtk::Button button_lightness_apply   ;
  Gtk::Image  image_lightness_apply    ;
  Gtk::Button button_hue_apply         ;
  Gtk::Image  image_hue_apply          ;
  Gtk::Button button_saturation_apply  ;
  Gtk::Image  image_saturation_apply   ;
  Gtk::Button button_brightness_apply  ;
  Gtk::Image  image_brightness_apply   ;

  // Intensity scaling interface
  Gtk::Frame frame_intensity_red      ;
  Gtk::Frame frame_intensity_green    ;
  Gtk::Frame frame_intensity_blue     ;
  Gtk::Frame frame_intensity_main     ;


  Gtk::Scale scale_intensity_red      ;
  Gtk::Scale scale_intensity_green    ;
  Gtk::Scale scale_intensity_blue     ;
  Gtk::Scale scale_intensity_main     ;


  Gtk::ButtonBox buttonbox_intensity_apply  ;
  Gtk::Box box_intensity_red                ;
  Gtk::Box box_intensity_green              ;
  Gtk::Box box_intensity_blue               ;
  Gtk::Box box_intensity_main               ;



  Gtk::Button button_red_apply  ;
  Gtk::Image  image_red_apply   ;
  Gtk::Button button_green_apply  ;
  Gtk::Image  image_green_apply   ;
  Gtk::Button button_blue_apply  ;
  Gtk::Image  image_blue_apply   ;
  Gtk::Button button_main_apply  ;
  Gtk::Image  image_main_apply   ;









  // Image info bar.
  Gtk::Box   box_info_bar_image_bottom   ;

  Gtk::Label label_info_bar_padding_1    ;
  Gtk::Label label_info_bar_mouse_coords ;

  Gtk::Label label_info_bar_padding_2    ;

  Gtk::Label label_info_bar_filename     ;
  Gtk::Label label_info_bar_padding_3    ;

  Gtk::Label label_info_bar_file_size     ;
  Gtk::Label label_info_bar_padding_4    ;

  // Box for image displaying area and infobar.
  Gtk::Box box_image_displaying     ;


  // Bottom (drawning) buttonbox:
  Gtk::Box       buttonbox_bottom      ;

  Gtk::ButtonBox buttonbox_bottom_padding_1 ;
  Gtk::ButtonBox buttonbox_bottom_draw      ;
  Gtk::ButtonBox buttonbox_bottom_padding_2 ;
  Gtk::ButtonBox buttonbox_bottom_config    ;
  Gtk::ButtonBox buttonbox_bottom_padding_3 ;


  // Drawning buttons:
  Gtk::Button         button_label_draw     ;
  Gtk::ToggleButton   button_draw_rect      ;
  Gtk::ToggleButton   button_draw_line      ;
  Gtk::ToggleButton   button_draw_circle    ;
  Gtk::ToggleButton   button_draw_ellipse   ;
  Gtk::ToggleButton   button_draw_polygon   ;
  Gtk::ToggleButton   button_draw_star      ;
  Gtk::ToggleButton   button_draw_text      ;

  Gtk::Image          image_label_draw      ;
  Gtk::Image          image_draw_line       ;
  Gtk::Image          image_draw_rect       ;
  Gtk::Image          image_draw_circle     ;
  Gtk::Image          image_draw_ellipse    ;
  Gtk::Image          image_draw_polygon    ;
  Gtk::Image          image_draw_star       ;
  Gtk::Image          image_draw_text       ;


  // Drawning settings:
  Gtk::Button         label_draw_thickness        ;
  Gtk::SpinButton     spinbutton_draw_thickness   ;
  Gtk::Button         label_draw_color            ;
  Gtk::ColorButton    colorbutton_draw            ;
  Gtk::ComboBoxText   combo_lines_type            ;

  Gtk::Image          image_label_thickness       ;
  Gtk::Image          image_label_draw_color      ;

  // Frames for button boxes.
  Gtk::Frame          frame_buttonbox_top         ;
  Gtk::Frame          frame_buttonbox_bottom      ;

  // Accelerators group.
  Glib::RefPtr<Gtk::AccelGroup>     accel_group        ;

  // Image displaying Gtk::Image widghet pointer:
  Gtk::Image *widget_current_image_to_display = NULL ;

  // Mouse cursers.
  Glib::RefPtr<Gdk::Cursor> mouse_cursor_set_center    ;
  Glib::RefPtr<Gdk::Cursor> mouse_cursor_set_activate  ;
  Glib::RefPtr<Gdk::Cursor> mouse_cursor_default       ;


  private : // Toolptips string constant vectors.

    const vector<string> combo_grayscale_current_tooltip = {  "Average Gray Scaling is based on the computing of the pixels averages values.",

                                                              "Maximal Gray Scaling is based on the computing of the maximal pixels values.\n"
                                                              "The gray values will be set on the maximal values taken from the differents\n"
                                                              "color channels: the red, green or blue value of the source image.\n"
                                                              "The result will be a clear grayscale.",

                                                              "Minimal Gray Scaling is based on the minimal pixels values.\n"
                                                              "The gray values will be set on the minimal value taken from the differents\n"
                                                              "color channels: the red, green or blue value of the source image.\n"
                                                              "The result will be a dark grayscale.",

                                                              "Red Gray Scaling is based on the red pixels values.\n"
                                                              "The gray values will be set on the red color channel values,\n"
                                                              "from the source image.",

                                                              "Green Gray Scaling is based on the green pixels values.\n"
                                                              "The gray values will be set on the green color channel values,\n"
                                                              "from the source image.",

                                                              "Blue Gray Scaling is based on the blue pixels values.\n"
                                                              "The gray values will be set on the blue color channel values,\n"
                                                              "from the source image." } ;



  const vector<string> combo_colorscale_current_tooltip = {   "Red Scaling Average is based on the computing of the pixels averages values.",

                                                              "Red Scaling Maximal is based on the computing of the maximal pixels values.\n"
                                                              "The red values will be set on the maximal values taken from the differents\n"
                                                              "color channels: the red, green or blue value of the source image.",

                                                              "Red Scaling Minimal is based on the minimal pixels values.\n"
                                                              "The red values will be set on the minimal value taken from the differents\n"
                                                              "color channels: the red, green or blue value of the source image.",

                                                              "Red Scaling Green is based on the green pixels values.\n"
                                                              "The red values will be set on the green color channel values, from the source image.\n"
                                                              "And the other color channels will be removed.",

                                                              "Red Scaling Blue is based on the blue pixels values.\n"
                                                              "The red values will be set on the blue color channel values, from the source image.\n"
                                                              "And the other color channels will be removed.",


                                                              "Green Scaling Average is based on the computing of the pixels averages values.",

                                                              "Green Scaling Maximal is based on the computing of the maximal pixels values.\n"
                                                              "The green values will be set on the maximal values taken from the differents\n"
                                                              "color channels: the red, green or blue value of the source image.",

                                                              "Green Scaling Minimal is based on the minimal pixels values.\n"
                                                              "The green values will be set on the minimal value taken from the differents\n"
                                                              "color channels: the red, green or blue value of the source image.",

                                                              "Green Scaling Red is based on the red pixels values.\n"
                                                              "The green values will be set on the red color channel values, from the source image.\n"
                                                              "And the other color channels will be removed.",

                                                              "Green Scaling Blue is based on the blue pixels values.\n"
                                                              "The green values will be set on the blue color channel values, from the source image.\n"
                                                              "And the other color channels will be removed.",


                                                              "Blue Scaling Average is based on the computing of the pixels averages values.",

                                                              "Blue Scaling Maximal is based on the computing of the maximal pixels values.\n"
                                                              "The blue values will be set on the maximal values taken from the differents\n"
                                                              "color channels: the red, green or blue value of the source image.",

                                                              "Blue Scaling Minimal is based on the minimal pixels values.\n"
                                                              "The blue values will be set on the minimal value taken from the differents\n"
                                                              "color channels: the red, green or blue value of the source image.\n",
                                                              "And the other color channels will be removed.",

                                                              "Blue Scaling Red is based on the red pixels values.\n"
                                                              "The blue values will be set on the red color channel values, from the source image.\n"
                                                              "And the other color channels will be removed.",

                                                              "Blue Scaling Green is based on the green pixels values.\n"
                                                              "The blue values will be set on the green color channel values, from the source image.\n"
                                                              "And the other color channels will be removed.",


                                                              "Yellow Scaling Average is based on the computing of the pixels averages values.",

                                                              "Yellow Scaling Maximal is based on the computing of the maximal pixels values.\n"
                                                              "The yellow values will be set on the maximal values taken from the differents\n"
                                                              "color channels: the red, green or blue value of the source image.",

                                                              "Yellow Scaling Minimal is based on the minimal pixels values.\n"
                                                              "The yellow values will be set on the minimal value taken from the differents\n"
                                                              "color channels: the red, green or blue value of the source image.\n",
                                                              "And the other color channels will be removed.",

                                                              "Yellow Scaling Red is based on the red pixels values.\n"
                                                              "The yellow values will be set on the red color channel values, from the source image.\n"
                                                              "And the other color channels will be removed.",

                                                              "Yellow Scaling Green is based on the green pixels values.\n"
                                                              "The yellow values will be set on the green color channel values, from the source image.\n"
                                                              "And the other color channels will be removed.",

                                                              "Yellow Scaling Blue is based on the blue pixels values.\n"
                                                              "The yellow values will be set on the blue color channel values, from the source image.\n"
                                                              "And the other color channels will be removed.",


                                                              "Pink Scaling Average is based on the computing of the pixels averages values.",

                                                              "Pink Scaling Maximal is based on the computing of the maximal pixels values.\n"
                                                              "The pink values will be set on the maximal values taken from the differents\n"
                                                              "color channels: the red, green or blue value of the source image.",

                                                              "Pink Scaling Minimal is based on the minimal pixels values.\n"
                                                              "The pink values will be set on the minimal value taken from the differents\n"
                                                              "color channels: the red, green or blue value of the source image.\n",
                                                              "And the other color channels will be removed.",

                                                              "Pink Scaling Red is based on the red pixels values.\n"
                                                              "The pink values will be set on the red color channel values, from the source image.\n"
                                                              "And the other color channels will be removed.",

                                                              "Pink Scaling Green is based on the green pixels values.\n"
                                                              "The pink values will be set on the green color channel values, from the source image.\n"
                                                              "And the other color channels will be removed.",

                                                              "Pink Scaling Blue is based on the blue pixels values.\n"
                                                              "The pink values will be set on the blue color channel values, from the source image.\n"
                                                              "And the other color channels will be removed.",


                                                              "Turquoise Scaling Average is based on the computing of the pixels averages values.",

                                                              "Turquoise Scaling Maximal is based on the computing of the maximal pixels values.\n"
                                                              "The turquoise values will be set on the maximal values taken from the differents\n"
                                                              "color channels: the red, green or blue value of the source image.",

                                                              "Turquoise Scaling Minimal is based on the minimal pixels values.\n"
                                                              "The turquoise values will be set on the minimal value taken from the differents\n"
                                                              "color channels: the red, green or blue value of the source image.\n",
                                                              "And the other color channels will be removed."

                                                              "Turquoise Scaling Red is based on the red pixels values.\n"
                                                              "The turquoise values will be set on the red color channel values, from the source image.\n"
                                                              "And the other color channels will be removed."

                                                              "Turquoise Scaling Green is based on the green pixels values.\n"
                                                              "The turquoise values will be set on the green color channel values, from the source image.\n"
                                                              "And the other color channels will be removed."

                                                              "Turquoise Scaling Blue is based on the blue pixels values.\n"
                                                              "The turquoise values will be set on the blue color channel values, from the source image.\n"
                                                              "And the other color channels will be removed."


                                                              } ;


    const vector<string> combo_filters_current_tooltip = {
                                                            "The Pencil Sketch filter produce a non-photorealistic line drawing image.",
                                     
                                                            "The stylisation filter is an edge-aware filters\nwhich effect is not focused on photorealism but\n"
                                                            "abstract regions of low contrast while preserving,\nor enhancing, high-contrast features.",
                                     
                                                            "The Detail Enhance filter enhances the details of a particular image.",
                                     
                                                            "The Edge Preserving filter is a smoothing filters used in many different applications.",
                                     
                                     
                                                            "The Stroke Edges filter add black strokes on some edges of the image.",
                                     
                                     
                                                            "The Invert Intensity filter invert the intensity.\n"
                                                            "This mean that the maximal value become the minimal value\nand so soon in the pixel values range.",
                                     
                                                            "The Light Intesity filter invert the intensity from the pixels channels average value.\n"
                                                            "So that it output a grayscale image with light effect.",
                                     
                                     
                                                            "Simulate conversion from RGB (Red, Green, Blue) to RC (red, cyan).\n"
                                                            "Blues and greens are replaced with cyans. The effect is similar\n"
                                                            "to Technicolor Process 2 (used in early color movies) and CGA\n"
                                                            "Palette 3 (used in early color PCs).",

                                                            "Simulate conversion from RGB (Red, Green, Blue) to RGV (red, green, value).\n"
                                                            "Blues are desaturated. The effect is similar to Technicolor\n"
                                                            "Process 1 (used in early color movies).",

                                                            "Simulate conversion from RGB (Red, Green, Blue) to CMV (cyan, magenta, value).\n"
                                                            "Yellows are desaturated. The effect is similar to CGA Palette 1\n"
                                                            "(used in early color PCs).",


                                                            "The Extrema Maximal filter compute the maximal values from\n2 differents channels and set the result on a channel.",

                                                            "The Extrema Minimal filter compute the minimal values from\n2 differents channels and set the result on a channel.",
                                     

                                                            "The Sharpen filter sharpen the image by adding some white pixels at some edges and points of the image.\n"
                                                            "This filter is based on a \'Sharpen\' convolution matrix.",

                                                            "The sharpen More filter sharpen the image by adding some white pixels at some edges and points of the image.\n"
                                                            "It has more impact on the image as the Sharpen filter but does the same stronger.\n"
                                                            "This filter is based on a \'Sharpen\' convolution matrix.",

                                                            "The Find Edges filter will result in black background image with the contours and some pixels,\nof the source image, displayed in color."
                                                            "This filter is based on a \'Find Edges\' convolution matrix.",


                                                            "The Mean Blur filter swindle the image. The result image is blurred.\n"
                                                            "This filter is based on a \'Mean\' convolution matrix.",

                                                            "The Mean Blur More filter swindle the image. The result image is blurred.\n"
                                                            "It has more impact on the image as the Mean Blur filter but does the same stronger.\n"
                                                            "This filter is based on a \'Mean\' convolution matrix.",

                                                            "The Blur filter swindle the image.\n"
                                                            "What can remove some noise of the image or smooth an pixelize image.",

                                                            "The Blur Median filter swindle the image.\n"
                                                            "What can remove some noise of the image or smooth an pixelize image.\n"
                                                            "This filter is well know for salt and pepper noise removing.",

                                                            "The Blur Gaussian filter swindle the image.\n"
                                                            "What can remove some noise of the image or smooth an pixelize image.\n"
                                                            "It use gaussian values for creating the blurring effect applying onto the image.",

                               
                                                            "The denoising filter perform image denoising using Non-local Means Denoising\nwith several computational optimizations.\n"
                                                            "Noise expected to be a gaussian white noise.\n"
                                                            "Denoising is done by converting image to CIELAB colorspace\nand then separately denoise L and AB components with different parameters.",
                               

                                                            "The Erode filter eroding the image content contours.\n"
                                                            "This filter erodes the image by minimizing the pixels neighborhood.",
                  
                                                            "The Dilate filter dilate the image content contours.\n"
                                                            "This filter dilates the image by maximizing the pixels neighborhood.",

                  
                                                            "The Wave Horizontally filter output an horizontally waved image.",

                                                            "The Wave Vertically filter output an horizontally waved image.",

                                                            "The Wave Twice filter output an horizontally and vertically waved image.",

                   
                                                            "The Contours Sobel White filter result in an image\nwith a white background and colored drawning wise foreground.\n"
                                                            "All the contours strokes of the image will be displayed on a white background.",

                                                            "The Contours Sobel Black filter result in an image\nwith a black background and colored drawning wise foreground.\n"
                                                            "All the contours strokes of the image will be displayed on a black background.",

                                                            "The Contours Sobel Emboss filter result in an image\nwith an emboss gray background and colored drawning wise foreground.\n"
                                                            "All the contours strokes of the image will be displayed on a gray background.",
                                     
                                     
                                                            "The Emboss Sobel filter is an emboss filter which result looking like a kopper engraving.\n"
                                                            "Based on the Sobel operator which detect edges horizontally and or vertically.",

                                                            "The Emboss Lalacian filter is an emboss filter which result looking like a kopper engraving.\n"
                                                            "Based on the Laplacian operator which detect edges horizontally and vertically.",
                                      
                                      
                                                            "The Binary White OTSU filter create an black and white image,\nfrom the source image, with white background and black foreground.\n"
                                                            "Based on the OTSU image specific threshold computing algorithm.\n"
                                                            "Simply try every algorithm to find the appositely one for your image,\nto get the best binary image from it.",

                                                            "The Binary White TRIANGLE filter create an black and white image,\nfrom the source image, with white background and black foreground.\n"
                                                            "Based on the TRIANGLE image specific threshold computing algorithm.\n"
                                                            "Simply try every algorithm to find the appositely one for your image,\nto get the best binary image from it.",

                                                            "The Binary White AVERAGE filter create an black and white image,\nfrom the source image, with white background and black foreground.\n"
                                                            "Based on the OTSU and TRIANGLE image specific threshold computing algorithm, average.\n"
                                                            "Simply try every algorithm to find the appositely one for your image,\nto get the best binary image from it.",


                                                            "The Binary Black OTSU filter create an black and white image,\nfrom the source image, with black background and white foreground.\n"
                                                            "Based on the OTSU image specific threshold computing algorithm.\n"
                                                            "Simply try every algorithm to find the appositely one for your image,\nto get the best binary image from it.",

                                                            "The Binary Black TRIANGLE filter create an black and white image,\nfrom the source image, with black background and white foreground.\n"
                                                            "Based on the TRIANGLE image specific threshold computing algorithm.\n"
                                                            "Simply try every algorithm to find the appositely one for your image,\nto get the best binary image from it.",


                                                            "The Binary Black AVERAGE filter create an black and white image,\nfrom the source image, with black background and white foreground.\n"
                                                            "Based on the OTSU and TRIANGLE image specific threshold computing algorithm, average."
                                                            "Simply try every algorithm to find the appositely one for your image,\nto get the best binary image from it.",
                                      
                                      
                                                            "The Binary Contours White filter create an black and white image,\nfrom the source image, with white background and black foreground.\n"
                                                            "With as foreground all the contours strokes of the image.\n"
                                                            "Like an black and white drawning.",

                                                            "The Binary Contours Black filter create an black and white image,\nfrom the source image, with black background and white foreground.\n"
                                                            "With as foreground all the contours strokes of the image.\n"
                                                            "Like an black and white drawning."

                                     

                                                        } ;

  private : // Combo current selection variables.

    uint8_t combo_current_filter       = 0 ;
    uint8_t combo_current_grayscaling  = 0 ;
    uint8_t combo_current_colorscaling = 0 ;

  private :  // Drawning functionalities members.

    Gdk::RGBA draw_color      ;
    int       draw_thickness  ;
    int       draw_line_type  ;

  private : // Switch side-bar.

    void switch_intensity_hsbl(int page_nb) ;

  public : // Files managing public methods.

    void get_recent_file(Controller &controller) ;

    void opening_file(Controller &controller) ;

    void saving_file(Controller &controller) ;

  private : // Files managing private methods.

    void config_select_file_filters(Gtk::FileChooser &dialog) ;

    const string guess_extension(const string filepath) const ;

    void save_as_image_file_settings(Controller &controller) ;

    void select_save_as_file(Controller &controller) ;

  private : // Draw function configuration callbacks.

    void config_polygon_draw(Controller &controller) ;

    void config_draw_text(Controller &controller) ;

    void config_star_draw(Controller &controller) ;

    void get_draw_color()     ;

    void get_draw_thickness() ;

    void get_draw_line_type() ;

  public :  // Menu extra filters methods.

    void kernel_sharpen_filter_dialog(Controller &controller) ;

    void kernel_find_edges_filter_dialog(Controller &controller) ;

    void kernel_emboss_filter_dialog(Controller &controller) ;

    void kernel_mean_filter_dialog(Controller &controller) ;

    void kernel_gaussian_filter_dialog(Controller &controller) ;

    void kernel_kirsch_filter_dialog(Controller &controller) ;

    void pencil_sketch_filter_dialog(Controller &controller) ;

    void stylisation_filter_dialog(Controller &controller) ;

    void detail_enhance_filter_dialog(Controller &controller) ;

    void edge_preserving_filter_dialog(Controller &controller) ;

    void denoising_filter_dialog(Controller &controller) ;

    void morphological_filter_dialog(Controller &controller) ;

    void mult_colors_filter_dialog(Controller &controller) ;

    void mult_global_intesity_filter_dialog(Controller &controller) ;

    void canny_filter_dialog(Controller &controller) ;

    void color_contours_filter_dialog(Controller &controller) ;

    void set_image_in_color_tone_filter_dialog(Controller &controller) ;
 
  public :
   
    void show_about(void) ;
   
    void launch_readme_html(void) ;
   
    void launch_documentation_html(void) ;
   
  private :  // Menu extra filters private callbacks.

    void morphological_callback(Controller &controller) ;

    void kernel_sharpen_callback(Controller &controller) ;

    void kernel_find_edges_callback(Controller &controller) ;

    void kernel_emboss_callback(Controller &controller) ;

    void kernel_mean_callback(Controller &controller) ;

    void kernel_gaussian_callback(Controller &controller) ;

    void kernel_kirsch_callback(Controller &controller) ;

    void mult_colors_callback(Controller &controller) ;

    void set_image_in_color_tone_callback(Controller &controller, uint8_t red, uint8_t green, uint8_t blue) ;

    void mult_global_intensity_callback(Controller &controller, const float factor) ;

    void display_kernel(cv::Mat kernel, int precison=2) ;


  private : // Images files merging utilities.

    void files_merging_set_output_file(string &filepath, Gtk::Entry &entry) ;

    void files_merging_preview_output(cv::Mat frame) ;

  public : // Images files merging dialogs.

    void files_merging_blend_images() ;

    void files_merging_screen_images() ;

    void files_merging_darker_images() ;

    void files_merging_lighter_images() ;

    void files_merging_add_images() ;

    void files_merging_add_modulo_images() ;

    void files_merging_sub_images() ;

    void files_merging_sub_modulo_images() ;

  public : // Message dialog generating method.

    void message_dialog(const string title, const string msg, const bool error = true) ;

  public :  // Add offset callback.

    bool drawning_add_offset(GdkEventKey *event, Controller &controller) ;

  private :  // Drawning private shortcuts methods.

    void drawning_press_enter_callback(Controller &controller) ;

    bool mouse_motion_event_handler_update_offset(Controller &controller) ;

  public : // Public member variable.

    bool display_area_size_changed = false ;

    bool have_window_size = false ;
    bool have_layout_size = false ;

    int display_area_width  = 0 ;
    int display_area_height = 0 ;


    Glib::RefPtr<Gdk::Window> display_area_gdk_window ;

    Glib::RefPtr<Gdk::Window> main_window_gdk_window  ;

    Gtk::Layout display_area         ;


  public : // Constructor.

    GUI() ;

  public : // public method intern.

    const string get_combo_entry_tooltip_text(const uint8_t idx) const { return (idx == 0) ? combo_filters_current_tooltip.at(combo_current_filter) : (idx == 1) ? combo_grayscale_current_tooltip.at(combo_current_grayscaling) : combo_colorscale_current_tooltip.at(combo_current_colorscaling) ; }


  public :  // Signal handlers.

    void get_window_area_size(Gtk::Allocation &scr, Controller &controller) ;

    void get_display_area_size(Gtk::Allocation &scr, Controller &controller) ;

    bool mouse_motion_event_handler(GdkEventMotion *event, Controller &controller) ;

    bool on_display_area_button_press_handler(GdkEventButton *event_button, Controller &controller) ;


    bool on_my_configure_window(GdkEventConfigure *event, Controller &controller) ;
    bool on_window_state_event_handler(GdkEventWindowState *event, Controller &controller) ;
    bool on_property_notify_event_handler(GdkEventProperty *event, Controller &controller) ;


    void on_changed_filters_comboboxtext(Controller &controller) ;
    void on_changed_grayscale_comboboxtext(Controller &controller) ;
    void on_changed_colorscale_comboboxtext(Controller &controller) ;


    void apply_filter(Controller &controller) ;
    void apply_grayscale(Controller &controller) ;
    void apply_colorscale(Controller &controller) ;

    void apply_filter_from_menu(Controller &controller, Gtk::ImageMenuItem &imagemenuitem) ;
    void apply_grayscale_from_menu(Controller &controller, Gtk::ImageMenuItem &imagemenuitem) ;
    void apply_colorscale_from_menu(Controller &controller, Gtk::ImageMenuItem &imagemenuitem) ;


    void undo_callback(Controller &controller) ;
    void redo_callback(Controller &controller) ;


    void rotating(Controller &controller, bool right_to_left) ;

    void mirror(Controller &controller, char sens) ;

    void flip(Controller &controller, char sens) ;





    void zoom_reset(Controller &controller)  ;
    void zoom_plus(Controller &controller)   ;
    void zoom_minus(Controller &controller)  ;



    void process_change_intensity(Controller &controller,  uint8_t selected_scale) ;
    void process_change_colorspace(Controller &controller, uint8_t selected_scale) ;

    void click_button_zoom_pointer(Controller &controller) ;
    void click_button_draw_pointer(Controller &controller, uint8_t button) ;



  public : // GUI Utility method.
   
      void set_img(const cv::Mat &frame, cv::Mat &result, Controller &controller) ;
   
      inline void after_applying_reset_settings(Controller &controller) {

        controller.has_undo   = false ;

        controller.zoom_counter = 0   ;

        if ( button_zoom_pointer.get_active()  ) {
          button_zoom_pointer.set_active(false) ;
        }

        controller.reset_zoom_center(controller.current_image_to_process) ;

      }




  public : //Widget getters inline methods.

    inline Gtk::RecentChooserMenu& get_recent_file_menuitem() { return menu_files_recent_files ; }
 
    // Gtk::ImageMenuItem getter for signal connecting to every item.
    inline Gtk::ImageMenuItem& get_imagemenuitem(const uint8_t imagemenuitem_code, int8_t type) {

      switch (type) {


        case 0 :

          switch (imagemenuitem_code) {

            case 0 : return menu_filters_filters_00 ;

            case 1 : return menu_filters_filters_01 ;

            case 2 : return menu_filters_filters_02 ;

            case 3 : return menu_filters_filters_03 ;

            case 4 : return menu_filters_filters_04 ;

            case 5 : return menu_filters_filters_05 ;

            case 6 : return menu_filters_filters_06 ;

            case 7 : return menu_filters_filters_07 ;

            case 8 : return menu_filters_filters_08 ;

            case 9 : return menu_filters_filters_09 ;

            case 10 : return menu_filters_filters_10 ;

            case 11 : return menu_filters_filters_11 ;

            case 12 : return menu_filters_filters_12 ;

            case 13 : return menu_filters_filters_13 ;

            case 14 : return menu_filters_filters_14 ;

            case 15 : return menu_filters_filters_15 ;

            case 16 : return menu_filters_filters_16 ;

            case 17 : return menu_filters_filters_17 ;

            case 18 : return menu_filters_filters_18 ;

            case 19 : return menu_filters_filters_19 ;

            case 20 : return menu_filters_filters_20 ;

            case 21 : return menu_filters_filters_21 ;

            case 22 : return menu_filters_filters_22 ;

            case 23 : return menu_filters_filters_23 ;

            case 24 : return menu_filters_filters_24 ;

            case 25 : return menu_filters_filters_25 ;

            case 26 : return menu_filters_filters_26 ;

            case 27 : return menu_filters_filters_27 ;

            case 28 : return menu_filters_filters_28 ;

            case 29 : return menu_filters_filters_29 ;

            case 30 : return menu_filters_filters_30 ;

            case 31 : return menu_filters_filters_31 ;

            case 32 : return menu_filters_filters_32 ;

            case 33 : return menu_filters_filters_33 ;

            case 34 : return menu_filters_filters_34 ;

            case 35 : return menu_filters_filters_35 ;

            case 36 : return menu_filters_filters_36 ;

            case 37 : return menu_filters_filters_37 ;

            case 38 : return menu_filters_filters_38 ;

          }

          break ;

      case 1 :

          switch (imagemenuitem_code) {

            case 0 : return menu_filters_kernel_sharpen_button    ;

            case 1 : return menu_filters_kernel_find_edges_button ;

            case 2 : return menu_filters_kernel_emboss_button     ;

            case 3 : return menu_filters_kernel_mean_button       ;

            case 4 : return menu_filters_kernel_gaussian_button   ;

            case 5 : return menu_filters_kernel_kirsch_button     ;

          }

      case 2 :

          switch (imagemenuitem_code) {

            case 0 : return menu_filters_photo_pencil_sketch_button    ;

            case 1 : return menu_filters_photo_stylisation_button      ;

            case 2 : return menu_filters_photo_detail_enhance_button   ;

            case 3 : return menu_filters_photo_edges_preserving_button ;

            case 4 : return menu_filters_photo_denoising_button        ;


          }

      case 3 :

        switch (imagemenuitem_code) {

          case 0 : return menu_filters_grayscale_00 ;

          case 1 : return menu_filters_grayscale_01 ;

          case 2 : return menu_filters_grayscale_02 ;

          case 3 : return menu_filters_grayscale_03 ;

          case 4 : return menu_filters_grayscale_04 ;

          case 5 : return menu_filters_grayscale_05 ;

        }

        break ;


      case 4 :

        switch (imagemenuitem_code) {

          case 0  : return menu_filters_colorscale_00 ;
          case 1  : return menu_filters_colorscale_01 ;
          case 2  : return menu_filters_colorscale_02 ;
          case 3  : return menu_filters_colorscale_03 ;
          case 4  : return menu_filters_colorscale_04 ;
          case 5  : return menu_filters_colorscale_05 ;
          case 6  : return menu_filters_colorscale_06 ;
          case 7  : return menu_filters_colorscale_07 ;
          case 8  : return menu_filters_colorscale_08 ;
          case 9  : return menu_filters_colorscale_09 ;
          case 10 : return menu_filters_colorscale_10 ;
          case 11 : return menu_filters_colorscale_11 ;
          case 12 : return menu_filters_colorscale_12 ;
          case 13 : return menu_filters_colorscale_13 ;
          case 14 : return menu_filters_colorscale_14 ;
          case 15 : return menu_filters_colorscale_15 ;
          case 16 : return menu_filters_colorscale_16 ;
          case 17 : return menu_filters_colorscale_17 ;
          case 18 : return menu_filters_colorscale_18 ;
          case 19 : return menu_filters_colorscale_19 ;
          case 20 : return menu_filters_colorscale_20 ;
          case 21 : return menu_filters_colorscale_21 ;
          case 22 : return menu_filters_colorscale_22 ;
          case 23 : return menu_filters_colorscale_23 ;
          case 24 : return menu_filters_colorscale_24 ;
          case 25 : return menu_filters_colorscale_25 ;
          case 26 : return menu_filters_colorscale_26 ;
          case 27 : return menu_filters_colorscale_27 ;
          case 28 : return menu_filters_colorscale_28 ;
          case 29 : return menu_filters_colorscale_29 ;
          case 30 : return menu_filters_colorscale_30 ;
          case 31 : return menu_filters_colorscale_31 ;
          case 32 : return menu_filters_colorscale_32 ;

    
          }

          break ;

        }

     }
 
    // Gtk::MenuItem getter for signal connecting to every item.
    inline Gtk::MenuItem& get_menuitem(const uint8_t menuitem_code) {

      switch (menuitem_code) {

        case 0  : return menu_files_open_file_button           ;

        case 1  : return menu_files_save_file_button           ;

        case 2  : return menu_files_blend_images_button        ;

        case 3  : return menu_files_screen_images_button       ;

        case 4  : return menu_files_darker_images_button       ;

        case 5  : return menu_files_lighter_images_button      ;

        case 6  : return menu_files_add_images_button          ;

        case 7  : return menu_files_add_modulo_images_button   ;

        case 8  : return menu_files_sub_images_button          ;

        case 9  : return menu_files_sub_modulo_images_button   ;



        case 10 : return menu_edition_undo_button ;

        case 11 : return menu_edition_redo_button ;


        case 12 : return menu_edition_rotate_left_button ;

        case 13 : return menu_edition_rotate_right_button ;


        case 14 : return menu_edition_mirror_left_to_right_button ;

        case 15 : return menu_edition_mirror_right_to_left_button ;

        case 16 : return menu_edition_mirror_up_to_down_button ;

        case 17 : return menu_edition_mirror_down_to_up_button ;


        case 18 : return menu_edition_zoom_plus_button ;

        case 19 : return menu_edition_zoom_minus_button ;



        case 20 : return menu_edition_flip_left_button ;

        case 21 : return menu_edition_flip_right_button ;

        case 22 : return menu_edition_flip_up_button ;

        case 23 : return menu_edition_flip_down_button ;


        case 30 : return menu_filters_morphological_button     ;

        case 31 : return menu_filters_mult_colors_button       ;

        case 32 : return menu_filters_set_in_color_tone_button ;

        case 33 : return menu_filters_mult_intensity_button    ;

        case 34 : return menu_filters_canny_button             ;
  
        case 35 : return menu_filters_color_contours_button    ;
       
       
        case 40 : return menu_infos_readme_button          ;
       
        case 41 : return menu_infos_documentation_button   ;
       
        case 42 : return menu_infos_about_button           ;
       
       
      }
    }
  
    // Gtk::Button getter for signal connecting to every item.
    inline Gtk::Button& get_button(const uint8_t but_code) {

      switch (but_code) {

        // First categorie (0-19) top buttonbox buttons.

        case 0 : return button_open           ;

        case 1 : return button_save           ;

        case 2 : return button_undo           ;

        case 3 : return button_redo           ;

        case 4 : return button_rot_left       ;

        case 5 : return button_rot_right      ;


        case 6 : return button_mirror_left    ;

        case 7 : return button_mirror_right   ;

        case 8 : return button_mirror_top     ;

        case 9 : return button_mirror_bottom  ;


        case 10 : return button_zoom_label   ;

        case 11 : return button_zoom_plus    ;

        case 12 : return button_zoom_minus   ;

        case 13 : return button_zoom_pointer ;


        case 14 : return button_flip_left    ;

        case 15 : return button_flip_right   ;

        case 16 : return button_flip_up      ;

        case 17 : return button_flip_down    ;



        // Second categorie (20-22) apply comboboxtext choice buttons.

        case 21 : return button_filters    ;

        case 22 : return button_grayscale  ;

        case 23 : return button_colorscale ;



        //  Third categorie (31-39) the intensity & HSBL apply buttons.

        case 31 : return button_red_apply       ;

        case 32 : return button_green_apply     ;

        case 33 : return button_blue_apply      ;

        case 34 : return button_main_apply      ;


        case 36 : return button_lightness_apply  ;

        case 37 : return button_hue_apply        ;

        case 38 : return button_saturation_apply ;

        case 39 : return button_brightness_apply ;


        case 41 : return button_draw_line        ;

        case 42 : return button_draw_rect        ;

        case 43 : return button_draw_circle      ;

        case 44 : return button_draw_ellipse     ;

        case 45 : return button_draw_polygon     ;

        case 46 : return button_draw_star        ;

        case 47 : return button_draw_text        ;

      }
    }
 
    // Gtk::ComboBoxText getter for signal connecting to every item.
    inline Gtk::ComboBoxText& get_combo(const uint8_t combo_code) {

      switch (combo_code) {

        case 0 : return combo_filters ;

        case 1 : return combo_grayscale ;

        case 2 : return combo_colorscale ;

      }
    }
 
    // Gtk::Entry getter for setting corresponding tooltip to current selected comboboxtext item.
    inline Gtk::Entry* get_entry_pointer(const uint8_t entry_code) {

      switch (entry_code) {

        case 0 : return entry_combo_filters ;
        case 1 : return entry_combo_grayscale ;
        case 2 : return entry_combo_colorscale ;

      }

    }
 
    // Gtk::Scale getter for signal connecting to every item.
    inline Gtk::Scale& get_scale(const uint8_t scale_code) {

      switch (scale_code) {

        case 1 : return scale_intensity_red   ;
        case 2 : return scale_intensity_green ;
        case 3 : return scale_intensity_blue  ;
        case 4 : return scale_intensity_main  ;

        case 6 : return scale_lightness       ;
        case 7 : return scale_hue             ;
        case 8 : return scale_saturation      ;
        case 9 : return scale_brightness       ;

      }

    }
  
    // Gtk::Label getter for signal connecting to every item.
    inline Gtk::Label& get_label(const uint8_t label_code) {

      switch (label_code) {

        case 0 : return label_info_bar_mouse_coords   ;
        case 1 : return label_info_bar_filename       ;
        case 2 : return label_info_bar_file_size      ;

      }

    }

  public : // Set infobar methods.

    inline void set_label_value(Gtk::Label &label, const string text) { label.set_text(text) ; } ;

    inline void set_label_size_value(const int width, const int height) {

      string text("  Size: ") ;

      text += to_string(width) ;

      text += "x" ;

      text += to_string(height) ;

      text += " " ;

      set_label_value(get_label(2), text) ;

    }

    inline void set_label_coords_value_on_null(Controller &controller) {

      string label_text(" Coordinates: ") ;

      string str_width(to_string(controller.source_image_size.first)) ;

      string str_height(to_string(controller.source_image_size.second)) ;



      string zero_padding(str_width.length(),'0') ;

      label_text +=  zero_padding ;

      label_text += ","   ;

      label_text += zero_padding ;

      label_text += "  ;" ;

      set_label_value(get_label(0), label_text ) ;
    }



} ;

#endif

