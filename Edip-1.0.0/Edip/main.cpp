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

#include <gtkmm/main.h>

#include <gtkmm/application.h>

#include <giomm.h>


#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>


#include "Edip_gui.hpp"

#include "Edip_Controller.hpp"


/** @Note from the author:
  *
  * This program is my first creation written in C++, complicated programming language
  * through his wide possiblities and classes management add to the C language on which C++ is based on.
  *
  * I try to not writte C-like C++ code so i try to simply not use pointers if i can avoid it.
  *
  * So if you sea some C++ coding chimera thanks to notice me at <mrcyberfighter@gmail.com> and
  * i ask for your indulgence concerning the coding of this program being my first in C++.
  *
  * If you get suggestion, questions or others you can contact me at <mrcyberfighter@gmail.com>.
  *
  *********************************************************************************************************/


/** The program @Edip is based on the MVC (Model-View-Controller) concept and build on the top of a library called @libedip.
  *
  * @libedip: contains all the operations functions applied on the image.
  *
  * @Model: is @libedip and his function set is build on the top of the opencv-3.0.0 library.
  *
  * @View: is build on the GUI Gtk+3.0, his C++ version, gtkmm3 in a class named @GUI.
  *
  * @Controller: make the gap between the Model and the View as a class named @Controller.
  *
  * ******************************************************************************************************************************
  *
  * How we do.
  *
  *   1. We always work on a copy (a frame) from the source image file contains in memory.
  *
  *   2. We always display, after an operation (applyed on the copy), the modified copy (event resized to the display area size).
  *
  *   3. We use temporary frames for displaying when needed (like by drawning, or by the Canny operator) but don't save them.
  *
  ********************************************************************************************************************************/


int main(int argc, char *argv[]) {

  cv::Mat frame ;

  char *filepath=NULL ;

  if (argc > 1) {

    if ((filepath=realpath(argv[1], NULL)) == NULL) {

      fprintf(stderr,"usage %s filepath\nFile not exist !!!\n", argv[0]) ;
      exit(EXIT_FAILURE) ;
    }
    else {

      try {

        frame = cv::imread(filepath, cv::IMREAD_UNCHANGED) ;

      }
      catch (cv::Exception &e) {

        string msg = "Cannot load file: " ;

        msg += filepath ;

        msg += "\n\n" ;

        msg += e.err ;

        fprintf(stdout,"%s\n", msg.c_str()) ;

        exit(EXIT_FAILURE) ;

      }

      if (frame.empty()) {

        fprintf(stderr,"Cannot read image file !!!\n") ;
        exit(EXIT_FAILURE) ;
      }

    }

  }

  Glib::init() ;

  Gtk::Main application(argc, argv);

  Controller controller ;

  controller.set_window_size(0,0) ;

  GUI gui ;  // Instanciate the GUI class.

  // Connecting signals from the GUI:
  gui.display_area.signal_size_allocate().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::get_display_area_size), controller) ) ;

  gui.get_button(0).signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::opening_file), controller) ) ;
  gui.get_button(1).signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::saving_file), controller) ) ;

  gui.get_button(2).signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::undo_callback), controller) ) ;
  gui.get_button(3).signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::redo_callback), controller) ) ;

  gui.get_button(4).signal_clicked().connect(sigc::bind<Controller &, bool>(sigc::mem_fun(gui, &GUI::rotating), controller, true) ) ;
  gui.get_button(5).signal_clicked().connect(sigc::bind<Controller &, bool>(sigc::mem_fun(gui, &GUI::rotating), controller, false) ) ;

  gui.get_button(6).signal_clicked().connect(sigc::bind<Controller &, char>(sigc::mem_fun(gui, &GUI::mirror), controller, 'l' ) ) ;
  gui.get_button(7).signal_clicked().connect(sigc::bind<Controller &, char>(sigc::mem_fun(gui, &GUI::mirror), controller, 'r' ) ) ;
  gui.get_button(8).signal_clicked().connect(sigc::bind<Controller &, char>(sigc::mem_fun(gui, &GUI::mirror), controller, 't' ) ) ;
  gui.get_button(9).signal_clicked().connect(sigc::bind<Controller &, char>(sigc::mem_fun(gui, &GUI::mirror), controller, 'b' ) ) ;

  gui.get_button(10).signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::zoom_reset), controller ) ) ;

  gui.get_button(11).signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::zoom_plus), controller ) ) ;
  gui.get_button(12).signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::zoom_minus), controller ) ) ;
  gui.get_button(13).signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::click_button_zoom_pointer), controller ) ) ;


  gui.get_button(14).signal_clicked().connect(sigc::bind<Controller &, char>(sigc::mem_fun(gui, &GUI::flip), controller, 'l') ) ;
  gui.get_button(15).signal_clicked().connect(sigc::bind<Controller &, char>(sigc::mem_fun(gui, &GUI::flip), controller, 'r') ) ;
  gui.get_button(16).signal_clicked().connect(sigc::bind<Controller &, char>(sigc::mem_fun(gui, &GUI::flip), controller, 'u') ) ;
  gui.get_button(17).signal_clicked().connect(sigc::bind<Controller &, char>(sigc::mem_fun(gui, &GUI::flip), controller, 'd') ) ;


  gui.get_button(21).signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::apply_filter), controller) ) ;
  gui.get_button(22).signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::apply_grayscale), controller) )  ;
  gui.get_button(23).signal_clicked().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::apply_colorscale), controller) ) ;

  gui.get_button(31).signal_clicked().connect(sigc::bind<Controller &, uint8_t>(sigc::mem_fun(gui, &GUI::process_change_intensity), controller, 1) ) ;
  gui.get_button(32).signal_clicked().connect(sigc::bind<Controller &, uint8_t>(sigc::mem_fun(gui, &GUI::process_change_intensity), controller, 2) ) ;
  gui.get_button(33).signal_clicked().connect(sigc::bind<Controller &, uint8_t>(sigc::mem_fun(gui, &GUI::process_change_intensity), controller, 3) ) ;
  gui.get_button(34).signal_clicked().connect(sigc::bind<Controller &, uint8_t>(sigc::mem_fun(gui, &GUI::process_change_intensity), controller, 4) ) ;

  gui.get_button(36).signal_clicked().connect(sigc::bind<Controller &, uint8_t>(sigc::mem_fun(gui, &GUI::process_change_colorspace), controller, 6) ) ;
  gui.get_button(37).signal_clicked().connect(sigc::bind<Controller &, uint8_t>(sigc::mem_fun(gui, &GUI::process_change_colorspace), controller, 7) ) ;
  gui.get_button(38).signal_clicked().connect(sigc::bind<Controller &, uint8_t>(sigc::mem_fun(gui, &GUI::process_change_colorspace), controller, 8) ) ;
  gui.get_button(39).signal_clicked().connect(sigc::bind<Controller &, uint8_t>(sigc::mem_fun(gui, &GUI::process_change_colorspace), controller, 9) ) ;

  gui.get_button(41).signal_clicked().connect(sigc::bind<Controller &, uint8_t>(sigc::mem_fun(gui, &GUI::click_button_draw_pointer), controller, 41 ) ) ;
  gui.get_button(42).signal_clicked().connect(sigc::bind<Controller &, uint8_t>(sigc::mem_fun(gui, &GUI::click_button_draw_pointer), controller, 42 ) ) ;
  gui.get_button(43).signal_clicked().connect(sigc::bind<Controller &, uint8_t>(sigc::mem_fun(gui, &GUI::click_button_draw_pointer), controller, 43 ) ) ;
  gui.get_button(44).signal_clicked().connect(sigc::bind<Controller &, uint8_t>(sigc::mem_fun(gui, &GUI::click_button_draw_pointer), controller, 44 ) ) ;
  gui.get_button(45).signal_clicked().connect(sigc::bind<Controller &, uint8_t>(sigc::mem_fun(gui, &GUI::click_button_draw_pointer), controller, 45 ) ) ;
  gui.get_button(46).signal_clicked().connect(sigc::bind<Controller &, uint8_t>(sigc::mem_fun(gui, &GUI::click_button_draw_pointer), controller, 46 ) ) ;
  gui.get_button(47).signal_clicked().connect(sigc::bind<Controller &, uint8_t>(sigc::mem_fun(gui, &GUI::click_button_draw_pointer), controller, 47 ) ) ;




  gui.get_menuitem(0).signal_activate().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::opening_file),  controller) ) ;
  gui.get_menuitem(1).signal_activate().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::saving_file),     controller) ) ;

  gui.get_recent_file_menuitem().signal_item_activated().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::get_recent_file), controller) ) ;

  gui.get_menuitem(2).signal_activate().connect(sigc::mem_fun(gui, &GUI::files_merging_blend_images) ) ;
  gui.get_menuitem(3).signal_activate().connect(sigc::mem_fun(gui, &GUI::files_merging_screen_images) ) ;
  gui.get_menuitem(4).signal_activate().connect(sigc::mem_fun(gui, &GUI::files_merging_darker_images) ) ;
  gui.get_menuitem(5).signal_activate().connect(sigc::mem_fun(gui, &GUI::files_merging_lighter_images) ) ;
  gui.get_menuitem(6).signal_activate().connect(sigc::mem_fun(gui, &GUI::files_merging_add_images) ) ;
  gui.get_menuitem(7).signal_activate().connect(sigc::mem_fun(gui, &GUI::files_merging_add_modulo_images) ) ;
  gui.get_menuitem(8).signal_activate().connect(sigc::mem_fun(gui, &GUI::files_merging_sub_images) ) ;
  gui.get_menuitem(9).signal_activate().connect(sigc::mem_fun(gui, &GUI::files_merging_sub_modulo_images) ) ;

  gui.get_menuitem(10).signal_activate().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::undo_callback), controller) ) ;
  gui.get_menuitem(11).signal_activate().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::redo_callback), controller) ) ;

  gui.get_menuitem(12).signal_activate().connect(sigc::bind<Controller &, bool>(sigc::mem_fun(gui, &GUI::rotating), controller, true) ) ;
  gui.get_menuitem(13).signal_activate().connect(sigc::bind<Controller &, bool>(sigc::mem_fun(gui, &GUI::rotating), controller, false) ) ;

  gui.get_menuitem(14).signal_activate().connect(sigc::bind<Controller &, char>(sigc::mem_fun(gui, &GUI::mirror), controller, 'l' ) ) ;
  gui.get_menuitem(15).signal_activate().connect(sigc::bind<Controller &, char>(sigc::mem_fun(gui, &GUI::mirror), controller, 'r' ) ) ;
  gui.get_menuitem(16).signal_activate().connect(sigc::bind<Controller &, char>(sigc::mem_fun(gui, &GUI::mirror), controller, 't' ) ) ;
  gui.get_menuitem(17).signal_activate().connect(sigc::bind<Controller &, char>(sigc::mem_fun(gui, &GUI::mirror), controller, 'b' ) ) ;

  gui.get_menuitem(18).signal_activate().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::zoom_plus),                 controller ) ) ;
  gui.get_menuitem(19).signal_activate().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::zoom_minus),                controller ) ) ;

  gui.get_menuitem(20).signal_activate().connect(sigc::bind<Controller &, char>(sigc::mem_fun(gui, &GUI::flip), controller, 'l') ) ;
  gui.get_menuitem(21).signal_activate().connect(sigc::bind<Controller &, char>(sigc::mem_fun(gui, &GUI::flip), controller, 'r') ) ;
  gui.get_menuitem(22).signal_activate().connect(sigc::bind<Controller &, char>(sigc::mem_fun(gui, &GUI::flip), controller, 'u') ) ;
  gui.get_menuitem(23).signal_activate().connect(sigc::bind<Controller &, char>(sigc::mem_fun(gui, &GUI::flip), controller, 'd') ) ;

  gui.get_imagemenuitem(0,  1).signal_activate().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::kernel_sharpen_filter_dialog),     controller ) ) ;
  gui.get_imagemenuitem(1,  1).signal_activate().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::kernel_find_edges_filter_dialog),  controller ) ) ;
  gui.get_imagemenuitem(2,  1).signal_activate().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::kernel_emboss_filter_dialog),      controller ) ) ;
  gui.get_imagemenuitem(3,  1).signal_activate().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::kernel_mean_filter_dialog),        controller ) ) ;
  gui.get_imagemenuitem(4,  1).signal_activate().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::kernel_gaussian_filter_dialog),    controller ) ) ;
  gui.get_imagemenuitem(5,  1).signal_activate().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::kernel_kirsch_filter_dialog),      controller ) ) ;

  gui.get_imagemenuitem(0,  2).signal_activate().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::pencil_sketch_filter_dialog),     controller ) ) ;
  gui.get_imagemenuitem(1,  2).signal_activate().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::stylisation_filter_dialog),       controller ) ) ;
  gui.get_imagemenuitem(2,  2).signal_activate().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::detail_enhance_filter_dialog),    controller ) ) ;
  gui.get_imagemenuitem(3,  2).signal_activate().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::edge_preserving_filter_dialog),   controller ) ) ;
  gui.get_imagemenuitem(4,  2).signal_activate().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::denoising_filter_dialog),         controller ) ) ;

  gui.get_menuitem(30).signal_activate().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::morphological_filter_dialog),      controller ) ) ;

  gui.get_menuitem(31).signal_activate().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::mult_colors_filter_dialog),             controller ) ) ;
  gui.get_menuitem(32).signal_activate().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::set_image_in_color_tone_filter_dialog), controller ) ) ;
  gui.get_menuitem(33).signal_activate().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::mult_global_intesity_filter_dialog),    controller ) ) ;

  gui.get_menuitem(34).signal_activate().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::canny_filter_dialog),             controller ) ) ;
  gui.get_menuitem(35).signal_activate().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::color_contours_filter_dialog),    controller ) ) ;

  gui.get_imagemenuitem(0,  0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(0,  0)) ) ;
  gui.get_imagemenuitem(1,  0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(1,  0)) ) ;
  gui.get_imagemenuitem(2,  0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(2,  0)) ) ;
  gui.get_imagemenuitem(3,  0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(3,  0)) ) ;
  gui.get_imagemenuitem(4,  0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(4,  0)) ) ;
  gui.get_imagemenuitem(5,  0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(5,  0)) ) ;
  gui.get_imagemenuitem(6,  0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(6,  0)) ) ;
  gui.get_imagemenuitem(7,  0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(7,  0)) ) ;
  gui.get_imagemenuitem(8,  0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(8,  0)) ) ;
  gui.get_imagemenuitem(9,  0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(9,  0)) ) ;
  gui.get_imagemenuitem(10, 0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(10, 0)) ) ;
  gui.get_imagemenuitem(11, 0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(11, 0)) ) ;
  gui.get_imagemenuitem(12, 0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(12, 0)) ) ;
  gui.get_imagemenuitem(13, 0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(13, 0)) ) ;
  gui.get_imagemenuitem(14, 0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(14, 0)) ) ;
  gui.get_imagemenuitem(15, 0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(15, 0)) ) ;
  gui.get_imagemenuitem(16, 0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(16, 0)) ) ;
  gui.get_imagemenuitem(17, 0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(17, 0)) ) ;
  gui.get_imagemenuitem(18, 0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(18, 0)) ) ;
  gui.get_imagemenuitem(19, 0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(19, 0)) ) ;
  gui.get_imagemenuitem(20, 0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(20, 0)) ) ;
  gui.get_imagemenuitem(21, 0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(21, 0)) ) ;
  gui.get_imagemenuitem(22, 0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(22, 0)) ) ;
  gui.get_imagemenuitem(23, 0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(23, 0)) ) ;
  gui.get_imagemenuitem(24, 0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(24, 0)) ) ;
  gui.get_imagemenuitem(25, 0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(25, 0)) ) ;
  gui.get_imagemenuitem(26, 0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(26, 0)) ) ;
  gui.get_imagemenuitem(27, 0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(27, 0)) ) ;
  gui.get_imagemenuitem(28, 0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(28, 0)) ) ;
  gui.get_imagemenuitem(29, 0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(29, 0)) ) ;
  gui.get_imagemenuitem(30, 0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(30, 0)) ) ;
  gui.get_imagemenuitem(31, 0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(31, 0)) ) ;
  gui.get_imagemenuitem(32, 0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(32, 0)) ) ;
  gui.get_imagemenuitem(33, 0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(33, 0)) ) ;
  gui.get_imagemenuitem(34, 0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(34, 0)) ) ;
  gui.get_imagemenuitem(35, 0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(35, 0)) ) ;
  gui.get_imagemenuitem(36, 0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(36, 0)) ) ;
  gui.get_imagemenuitem(37, 0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(37, 0)) ) ;
  gui.get_imagemenuitem(38, 0).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_filter_from_menu), controller, gui.get_imagemenuitem(38, 0)) ) ;

  gui.get_imagemenuitem(0, 3).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_grayscale_from_menu), controller, gui.get_imagemenuitem(0, 3)) ) ;
  gui.get_imagemenuitem(1, 3).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_grayscale_from_menu), controller, gui.get_imagemenuitem(1, 3)) ) ;
  gui.get_imagemenuitem(2, 3).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_grayscale_from_menu), controller, gui.get_imagemenuitem(2, 3)) ) ;
  gui.get_imagemenuitem(3, 3).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_grayscale_from_menu), controller, gui.get_imagemenuitem(3, 3)) ) ;
  gui.get_imagemenuitem(4, 3).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_grayscale_from_menu), controller, gui.get_imagemenuitem(4, 3)) ) ;
  gui.get_imagemenuitem(5, 3).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_grayscale_from_menu), controller, gui.get_imagemenuitem(5, 3)) ) ;

  gui.get_imagemenuitem(0,  4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(0,  4)) ) ;
  gui.get_imagemenuitem(1,  4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(1,  4)) ) ;
  gui.get_imagemenuitem(2,  4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(2,  4)) ) ;
  gui.get_imagemenuitem(3,  4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(3,  4)) ) ;
  gui.get_imagemenuitem(4,  4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(4,  4)) ) ;
  gui.get_imagemenuitem(5,  4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(5,  4)) ) ;
  gui.get_imagemenuitem(6,  4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(6,  4)) ) ;
  gui.get_imagemenuitem(7,  4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(7,  4)) ) ;
  gui.get_imagemenuitem(8,  4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(8,  4)) ) ;
  gui.get_imagemenuitem(9,  4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(9,  4)) ) ;
  gui.get_imagemenuitem(10, 4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(10, 4)) ) ;
  gui.get_imagemenuitem(11, 4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(11, 4)) ) ;
  gui.get_imagemenuitem(12, 4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(12, 4)) ) ;
  gui.get_imagemenuitem(13, 4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(13, 4)) ) ;
  gui.get_imagemenuitem(14, 4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(14, 4)) ) ;
  gui.get_imagemenuitem(15, 4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(15, 4)) ) ;
  gui.get_imagemenuitem(16, 4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(16, 4)) ) ;
  gui.get_imagemenuitem(17, 4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(17, 4)) ) ;
  gui.get_imagemenuitem(18, 4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(18, 4)) ) ;
  gui.get_imagemenuitem(19, 4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(19, 4)) ) ;
  gui.get_imagemenuitem(20, 4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(20, 4)) ) ;
  gui.get_imagemenuitem(21, 4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(21, 4)) ) ;
  gui.get_imagemenuitem(22, 4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(22, 4)) ) ;
  gui.get_imagemenuitem(23, 4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(23, 4)) ) ;
  gui.get_imagemenuitem(24, 4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(24, 4)) ) ;
  gui.get_imagemenuitem(25, 4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(25, 4)) ) ;
  gui.get_imagemenuitem(26, 4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(26, 4)) ) ;
  gui.get_imagemenuitem(27, 4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(27, 4)) ) ;
  gui.get_imagemenuitem(28, 4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(28, 4)) ) ;
  gui.get_imagemenuitem(29, 4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(29, 4)) ) ;
  gui.get_imagemenuitem(30, 4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(30, 4)) ) ;
  gui.get_imagemenuitem(31, 4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(31, 4)) ) ;
  gui.get_imagemenuitem(32, 4).signal_activate().connect(sigc::bind<Controller &,Gtk::ImageMenuItem &>(sigc::mem_fun(gui, &GUI::apply_colorscale_from_menu), controller, gui.get_imagemenuitem(32, 4)) ) ;

  gui.get_menuitem(40).signal_activate().connect(sigc::mem_fun(gui, &GUI::launch_readme_html))        ;
  gui.get_menuitem(41).signal_activate().connect(sigc::mem_fun(gui, &GUI::launch_documentation_html)) ;
  gui.get_menuitem(42).signal_activate().connect(sigc::mem_fun(gui, &GUI::show_about))                ;


  gui.get_combo(0).signal_changed().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::on_changed_filters_comboboxtext), controller) ) ;
  gui.get_combo(1).signal_changed().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::on_changed_grayscale_comboboxtext), controller) ) ;
  gui.get_combo(2).signal_changed().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::on_changed_colorscale_comboboxtext), controller) ) ;


  if (gui.display_area.get_has_window()) {
      /** The widget @display_area must have a Gdk::Window and must be realized. Else return a NULL pointer. **/
      gui.display_area_gdk_window = gui.display_area.get_window() ;
  }
  else { free(filepath) ; exit(EXIT_FAILURE) ; }


  if (gui.display_area_gdk_window) {
    /** The widget @display_area must have a Gdk::Window and must be realized. **/

    gui.display_area_gdk_window->set_events(Gdk::BUTTON_PRESS_MASK | Gdk::POINTER_MOTION_MASK )   ; // Activate button press and mouse motion events receiving ; disabled per default.

    // (Now we can) Set a handler for every mouse motion.
    gui.display_area.signal_motion_notify_event().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::mouse_motion_event_handler), controller) ) ;

    // (Now we can Set a handler for button press events.
    gui.display_area.signal_button_press_event().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::on_display_area_button_press_handler), controller) ) ;

  }
  else { free(filepath) ; exit(EXIT_FAILURE) ; }

  if ( gui.get_has_window() ) {
    /** The widget @Window must have a Gdk::Window and must be realized. Else return a NULL pointer. **/

    gui.main_window_gdk_window = gui.get_window() ;

    if (! gui.main_window_gdk_window) {

      fprintf(stderr,"Main window Gdk window invalid !\n") ;
      free(filepath) ;
      exit(EXIT_FAILURE) ;

    }
    else {

      gui.main_window_gdk_window->set_events(Gdk::STRUCTURE_MASK) ;
      gui.main_window_gdk_window->set_events(Gdk::PROPERTY_CHANGE_MASK | Gdk::BUTTON_PRESS_MASK  | Gdk::KEY_PRESS_MASK ) ;

      gui.signal_window_state_event().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::on_window_state_event_handler), controller) ) ;

      gui.signal_property_notify_event().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::on_property_notify_event_handler), controller) ) ;

      gui.signal_key_press_event().connect(sigc::bind<Controller &>(sigc::mem_fun(gui, &GUI::drawning_add_offset), controller)) ;

    }
  }
  else { exit(EXIT_FAILURE) ; }




  while (! gui.have_layout_size  ) { // Loop  until the interface reach his final size.
    application.iteration(false) ;
  }

  // Threath cmdline argument image file frame.
  if (! frame.empty() && argc > 1) {

      if (frame.depth() == 3 || frame.depth() == 2) {
        // Input format CV_16S || CV_16U
        cv::Mat tmp(frame.size(), CV_8U) ;
        frame.convertTo(tmp, CV_8U, 1.0/256) ;
        frame = tmp ;
      }
      else if (frame.depth() == 5) {
        // Input format CV_32F
        cv::Mat tmp(frame.size(), CV_8U) ;
        frame.convertTo(tmp, CV_8U) ;
        frame = tmp ;
      }
      else if (frame.depth() != 0) {
        // depth() different from CV_8U we cannot process.
        fprintf(stderr, "Cannot load file:\n%s\n", filepath) ;
        free(filepath) ;
        exit(EXIT_FAILURE) ;

      }

      if (frame.channels() == 1) {
        // Normally GRAY
        cv::cvtColor(frame, frame, cv::COLOR_GRAY2BGR) ;
      }

      // Reset control variables.
      controller.reset_settings() ;
      // Add first frame to Undo-Redo vector.
      controller.image_to_display_vector.push_back(frame.clone()) ;
      // Set the first frame as image to process.
      controller.current_image_to_process = frame ;
      // Reset zoom center.
      controller.reset_zoom_center(frame) ;
      // Getting image size and postion datas.
      controller.get_current_image_position() ;
      // Displaying the image frame.
      gui.set_img(frame, controller.current_image_to_display, controller) ;
      // Setting boolean value.
      controller.image_file_loaded = true ;

      // Setting infobar datas
      string tmp_filepath(filepath) ;
      gui.set_label_value(gui.get_label(1), "Filename: " + Glib::path_get_basename(tmp_filepath)) ;
      gui.set_label_size_value(controller.source_image_size.first, controller.source_image_size.second) ;
      gui.set_label_coords_value_on_null(controller) ;

      free(filepath) ;

  }



  application.run(gui) ;

  if ( ! controller.image_file_loaded   ) { exit(EXIT_SUCCESS) ; }

  // To get an save forget fallback uncomment:
  // cv::imwrite("/tmp/Edip_output.png", controller.current_image_to_process) ;

  exit(EXIT_SUCCESS) ;

}