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


#include "Edip_gui.hpp"

#include "Edip_functions.hpp"

GUI::GUI() :

    main_box(Gtk::ORIENTATION_VERTICAL),

    menu_bar(),


    menu_files(),
    menu_edition(),
    menu_filters(),
    menu_filters_filters(),
    menu_kernel_filters(),
    menu_filters_photo(),
    menu_filters_grayscale(),
    menu_filters_colorscale(),
    menu_infos(),



    accel_group(),

    menu_files_button(),
    menu_files_button_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_files_button_image(PATH_TO_MENU_ICONS "document-open-data.png"),
    menu_files_button_label(" Files "),

    menu_edition_button(),
    menu_edition_button_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_edition_button_image(PATH_TO_MENU_ICONS "folder-image-people.png"),
    menu_edition_button_label(" Edition "),


    menu_filters_button(),
    menu_filters_button_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_filters_button_image(PATH_TO_MENU_ICONS "view-filter.png"),
    menu_filters_button_label(" Filters "),
   
    menu_infos_button(),
    menu_infos_button_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_infos_button_image(PATH_TO_MENU_ICONS "user-info.png"),
    menu_infos_button_label(" Informations "),
   
    menu_files_open_file_button(),
    menu_files_open_file_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_files_open_file_image(PATH_TO_MENU_ICONS "folder-image.png"),
    menu_files_open_file_label(" Open file "),
    menu_files_open_file_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_files_open_file_accel_label("Ctrl + O"),

    menu_files_save_file_button(),
    menu_files_save_file_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_files_save_file_image(PATH_TO_MENU_ICONS "document-save-as.png"),
    menu_files_save_file_label(" Save file "),
    menu_files_save_file_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_files_save_file_accel_label("Ctrl + S"),

    menu_files_separator_01(),


    menu_files_recent_file_button(),
    menu_files_recent_file_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_files_recent_file_image(PATH_TO_MENU_ICONS "document-open-recent.png"),
    menu_files_recent_file_label(" Recent files "),
    menu_files_recent_file_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_files_recent_file_accel_label(""),


    menu_files_separator_02(),

    menu_files_blend_images_button(),
    menu_files_blend_images_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_files_blend_images_image(PATH_TO_MENU_ICONS "view-presentation.png"),
    menu_files_blend_images_label(" Blend images interpolating"),
    menu_files_blend_images_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_files_blend_images_accel_label(""),

    menu_files_screen_images_button(),
    menu_files_screen_images_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_files_screen_images_image(PATH_TO_MENU_ICONS "view-presentation.png"),
    menu_files_screen_images_label(" Screen images interpolating"),
    menu_files_screen_images_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_files_screen_images_accel_label(""),

    menu_files_darker_images_button(),
    menu_files_darker_images_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_files_darker_images_image(PATH_TO_MENU_ICONS "view-presentation.png"),
    menu_files_darker_images_label(" Darker images interpolating"),
    menu_files_darker_images_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_files_darker_images_accel_label(""),

    menu_files_lighter_images_button(),
    menu_files_lighter_images_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_files_lighter_images_image(PATH_TO_MENU_ICONS "view-presentation.png"),
    menu_files_lighter_images_label(" Lighter images interpolating"),
    menu_files_lighter_images_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_files_lighter_images_accel_label(""),

    menu_files_add_images_button(),
    menu_files_add_images_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_files_add_images_image(PATH_TO_MENU_ICONS "view-presentation.png"),
    menu_files_add_images_label(" Add images interpolating"),
    menu_files_add_images_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_files_add_images_accel_label(""),

    menu_files_add_modulo_images_button(),
    menu_files_add_modulo_images_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_files_add_modulo_images_image(PATH_TO_MENU_ICONS "view-presentation.png"),
    menu_files_add_modulo_images_label(" Add modulo images interpolating"),
    menu_files_add_modulo_images_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_files_add_modulo_images_accel_label(""),

    menu_files_sub_images_button(),
    menu_files_sub_images_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_files_sub_images_image(PATH_TO_MENU_ICONS "view-presentation.png"),
    menu_files_sub_images_label(" Subtract images interpolating"),
    menu_files_sub_images_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_files_sub_images_accel_label(""),

    menu_files_sub_modulo_images_button(),
    menu_files_sub_modulo_images_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_files_sub_modulo_images_image(PATH_TO_MENU_ICONS "view-presentation.png"),
    menu_files_sub_modulo_images_label(" Subtract modulo images interpolating"),
    menu_files_sub_modulo_images_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_files_sub_modulo_images_accel_label(""),




    menu_files_recent_files(recent_file_manager),

    menu_edition_undo_button(),
    menu_edition_undo_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_edition_undo_image(PATH_TO_MENU_ICONS "go-previous-view.png"),
    menu_edition_undo_label(" Undo "),
    menu_edition_undo_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_edition_undo_accel_label("Ctrl + Z"),

    menu_edition_redo_button(),
    menu_edition_redo_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_edition_redo_image(PATH_TO_MENU_ICONS "go-next-view.png"),
    menu_edition_redo_label(" Undo "),
    menu_edition_redo_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_edition_redo_accel_label("Ctrl + Maj + Z"),

    menu_edition_separator_01(),

    menu_edition_rotate_left_button(),
    menu_edition_rotate_left_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_edition_rotate_left_image(PATH_TO_MENU_ICONS "object-rotate-left.png"),
    menu_edition_rotate_left_label(" Rotate left "),
    menu_edition_rotate_left_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_edition_rotate_left_accel_label("/"),

    menu_edition_rotate_right_button(),
    menu_edition_rotate_right_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_edition_rotate_right_image(PATH_TO_MENU_ICONS "object-rotate-right.png"),
    menu_edition_rotate_right_label(" Rotate right "),
    menu_edition_rotate_right_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_edition_rotate_right_accel_label("*"),

    menu_edition_separator_02(),

    menu_edition_mirror_left_to_right_button(),
    menu_edition_mirror_left_to_right_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_edition_mirror_left_to_right_image(PATH_TO_MENU_ICONS "distribute-horizontal-left.png"),
    menu_edition_mirror_left_to_right_label(" Mirror left-to-right "),
    menu_edition_mirror_left_to_right_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_edition_mirror_left_to_right_accel_label("Alt + 6"),

    menu_edition_mirror_right_to_left_button(),
    menu_edition_mirror_right_to_left_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_edition_mirror_right_to_left_image(PATH_TO_MENU_ICONS "distribute-horizontal-right.png"),
    menu_edition_mirror_right_to_left_label(" Mirror right-to-left "),
    menu_edition_mirror_right_to_left_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_edition_mirror_right_to_left_accel_label("Alt + 4"),

    menu_edition_mirror_up_to_down_button(),
    menu_edition_mirror_up_to_down_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_edition_mirror_up_to_down_image(PATH_TO_MENU_ICONS "distribute-vertical-top.png"),
    menu_edition_mirror_up_to_down_label(" Mirror top-to-bottom "),
    menu_edition_mirror_up_to_down_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_edition_mirror_up_to_down_accel_label("Alt + 8"),

    menu_edition_mirror_down_to_up_button(),
    menu_edition_mirror_down_to_up_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_edition_mirror_down_to_up_image(PATH_TO_MENU_ICONS "distribute-vertical-bottom.png"),
    menu_edition_mirror_down_to_up_label(" Mirror bottom-to-top "),
    menu_edition_mirror_down_to_up_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_edition_mirror_down_to_up_accel_label("Alt + 2"),

    menu_edition_separator_03(),

    menu_edition_zoom_plus_button(),
    menu_edition_zoom_plus_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_edition_zoom_plus_image(PATH_TO_MENU_ICONS "zoom-in.png"),
    menu_edition_zoom_plus_label(" Zoom in "),
    menu_edition_zoom_plus_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_edition_zoom_plus_accel_label("+"),

    menu_edition_zoom_minus_button(),
    menu_edition_zoom_minus_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_edition_zoom_minus_image(PATH_TO_MENU_ICONS "zoom-out.png"),
    menu_edition_zoom_minus_label(" Zoom out "),
    menu_edition_zoom_minus_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_edition_zoom_minus_accel_label("-"),

    /*
    menu_edition_zoom_set_button(),
    menu_edition_zoom_set_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_edition_zoom_set_image(PATH_TO_MENU_ICONS "edit-select.png"),
    menu_edition_zoom_set_label(" Zoom center setting "),
    menu_edition_zoom_set_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_edition_zoom_set_accel_label(""),
    */

    menu_edition_separator_04(),

    menu_edition_flip_left_button(),
    menu_edition_flip_left_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_edition_flip_left_image(PATH_TO_MENU_ICONS "go-previous.png"),
    menu_edition_flip_left_label(" Flip left "),
    menu_edition_flip_left_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_edition_flip_left_accel_label("4"),

    menu_edition_flip_right_button(),
    menu_edition_flip_right_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_edition_flip_right_image(PATH_TO_MENU_ICONS "go-next.png"),
    menu_edition_flip_right_label(" Flip right "),
    menu_edition_flip_right_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_edition_flip_right_accel_label("6"),

    menu_edition_flip_up_button(),
    menu_edition_flip_up_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_edition_flip_up_image(PATH_TO_MENU_ICONS "go-up.png"),
    menu_edition_flip_up_label(" Flip top "),
    menu_edition_flip_up_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_edition_flip_up_accel_label("8"),

    menu_edition_flip_down_button(),
    menu_edition_flip_down_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_edition_flip_down_image(PATH_TO_MENU_ICONS "go-down.png"),
    menu_edition_flip_down_label(" Flip bottom "),
    menu_edition_flip_down_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_edition_flip_down_accel_label("2"),


    menu_filters_filters_button(),
    menu_filters_filters_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_filters_filters_image(PATH_TO_MENU_ICONS "preferences-activities.png"),
    menu_filters_filters_label(" Apply filter "),
    menu_filters_filters_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_filters_filters_accel_label(""),

    menu_filters_kernel_filters_button(),
    menu_filters_kernel_filters_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_filters_kernel_filters_image(PATH_TO_MENU_ICONS "transform-move.png"),
    menu_filters_kernel_filters_label(" Kernel filters "),
    menu_filters_kernel_filters_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_filters_kernel_filters_accel_label(""),


    menu_filters_kernel_sharpen_button(" Sharpen kernel filter "),
    menu_filters_kernel_sharpen_image(PATH_TO_MENU_ICONS "transform-move.png"),

    menu_filters_kernel_find_edges_button(" Find edges kernel filter "),
    menu_filters_kernel_find_edges_image(PATH_TO_MENU_ICONS "transform-move.png"),

    menu_filters_kernel_emboss_button(" Emboss kernel filter "),
    menu_filters_kernel_emboss_image(PATH_TO_MENU_ICONS "transform-move.png"),

    menu_filters_kernel_mean_button(" Mean kernel filter "),
    menu_filters_kernel_mean_image(PATH_TO_MENU_ICONS "transform-move.png"),

    menu_filters_kernel_gaussian_button(" Gaussian kernel filter "),
    menu_filters_kernel_gaussian_image(PATH_TO_MENU_ICONS "transform-move.png"),

    menu_filters_kernel_kirsch_button(" Kirsch kernel filter "),
    menu_filters_kernel_kirsch_image(PATH_TO_MENU_ICONS "transform-move.png"),


    menu_filters_photo_filters_button(),
    menu_filters_photo_filters_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_filters_photo_filters_image(PATH_TO_MENU_ICONS "camera-photo.png"),
    menu_filters_photo_filters_label(" Photography filters "),
    menu_filters_photo_filters_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_filters_photo_filters_accel_label(""),


    menu_filters_photo_pencil_sketch_button(" Pencil sketch "),
    menu_filters_photo_pencil_sketch_image(PATH_TO_MENU_ICONS "camera-photo.png"),

    menu_filters_photo_stylisation_button(" Stylisation "),
    menu_filters_photo_stylisation_image(PATH_TO_MENU_ICONS "camera-photo.png"),

    menu_filters_photo_detail_enhance_button(" Detail enhance "),
    menu_filters_photo_detail_enhance_image(PATH_TO_MENU_ICONS "camera-photo.png"),

    menu_filters_photo_edges_preserving_button(" Edge preserving "),
    menu_filters_photo_edges_preserving_image(PATH_TO_MENU_ICONS "camera-photo.png"),

    menu_filters_photo_denoising_button(" Denoising "),
    menu_filters_photo_denoising_image(PATH_TO_MENU_ICONS "camera-photo.png"),

    menu_filters_morphological_button(),
    menu_filters_morphological_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_filters_morphological_image(PATH_TO_MENU_ICONS "weather-clear-night.png"),
    menu_filters_morphological_label(" Morphological filter "),
    menu_filters_morphological_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_filters_morphological_accel_label(""),

    menu_filters_canny_button(),
    menu_filters_canny_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_filters_canny_image(PATH_TO_MENU_ICONS "image-missing.png"),
    menu_filters_canny_label(" Canny filter "),
    menu_filters_canny_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_filters_canny_accel_label(""),

    menu_filters_color_contours_button(),
    menu_filters_color_contours_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_filters_color_contours_image(PATH_TO_MENU_ICONS "image-x-generic.png"),
    menu_filters_color_contours_label(" Color contours filter "),
    menu_filters_color_contours_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_filters_color_contours_accel_label(""),

    menu_filters_separator_01(),

    menu_filters_grayscale_button(),
    menu_filters_grayscale_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_filters_grayscale_image(PATH_TO_MENU_ICONS "code-block.png"),
    menu_filters_grayscale_label(" Grayscale "),
    menu_filters_grayscale_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_filters_grayscale_accel_label(""),

    menu_filters_separator_02(),

    menu_filters_colorscale_button(),
    menu_filters_colorscale_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_filters_colorscale_image(PATH_TO_MENU_ICONS "code-class.png"),
    menu_filters_colorscale_label(" Colorscale "),
    menu_filters_colorscale_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_filters_colorscale_accel_label(""),

    menu_filters_mult_colors_button(),
    menu_filters_mult_colors_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_filters_mult_colors_image(PATH_TO_MENU_ICONS "office-chart-pie.png"),
    menu_filters_mult_colors_label(" Multiply colors "),
    menu_filters_mult_colors_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_filters_mult_colors_accel_label(""),

    menu_filters_mult_intensity_button(),
    menu_filters_mult_intensity_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_filters_mult_intensity_image(PATH_TO_MENU_ICONS "quickopen-class.png"),
    menu_filters_mult_intensity_label(" Multiply global intensity "),
    menu_filters_mult_intensity_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_filters_mult_intensity_accel_label(""),

    menu_filters_set_in_color_tone_button(),
    menu_filters_set_in_color_tone_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_filters_set_in_color_tone_image(PATH_TO_MENU_ICONS "view-statistics.png"),
    menu_filters_set_in_color_tone_label(" Set image in color tone "),
    menu_filters_set_in_color_tone_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_filters_set_in_color_tone_accel_label(""),

    menu_infos_readme_button(),
    menu_infos_readme_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_infos_readme_image(PATH_TO_MENU_ICONS "document-readme.png"),
    menu_infos_readme_label(" README "),
    menu_infos_readme_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_infos_readme_accel_label(""),
   
    menu_infos_documentation_button(),
    menu_infos_documentation_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_infos_documentation_image(PATH_TO_MENU_ICONS "system-help.png"),
    menu_infos_documentation_label(" Documentation "),
    menu_infos_documentation_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_infos_documentation_accel_label(""),
   
    menu_infos_about_button(),
    menu_infos_about_container(Gtk::ORIENTATION_HORIZONTAL),
    menu_infos_about_image(PATH_TO_MENU_ICONS "dialog-about.png"),
    menu_infos_about_label(" About "),
    menu_infos_about_padding(Gtk::ORIENTATION_HORIZONTAL),
    menu_infos_about_accel_label(""),


    menu_filters_filters_image_00(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_01(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_02(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_03(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_04(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_05(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_06(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_07(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_08(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_09(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_10(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_11(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_12(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_13(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_14(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_15(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_16(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_17(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_18(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_19(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_20(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_21(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_22(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_23(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_24(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_25(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_26(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_27(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_28(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_29(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_30(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_31(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_32(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_33(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_34(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_35(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_36(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_37(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_filters_image_38(PATH_TO_MENU_ICONS "dialog-ok.png"),



    menu_filters_filters_00(menu_filters_filters_image_00, "Pencil Sketch"),
    menu_filters_filters_01(menu_filters_filters_image_01, "Stylisation"),
    menu_filters_filters_02(menu_filters_filters_image_02, "Detail Enhance"),
    menu_filters_filters_03(menu_filters_filters_image_03, "Edge Preserving"),
    menu_filters_filters_04(menu_filters_filters_image_04, "Stroke Edges"),
    menu_filters_filters_05(menu_filters_filters_image_05, "Invert Intensity"),
    menu_filters_filters_06(menu_filters_filters_image_06, "Light Intesity"),
    menu_filters_filters_07(menu_filters_filters_image_07, "Recolor RC  (Red-Cyan)"),
    menu_filters_filters_08(menu_filters_filters_image_08, "Recolor RGV (Red-Green-Value)"),
    menu_filters_filters_09(menu_filters_filters_image_09, "Recolor CMV (Cyan-Magenta-Value)"),
    menu_filters_filters_10(menu_filters_filters_image_10, "Extrema Maximal"),
    menu_filters_filters_11(menu_filters_filters_image_11, "Extrema Minimal"),
    menu_filters_filters_12(menu_filters_filters_image_12, "Sharpen"),
    menu_filters_filters_13(menu_filters_filters_image_13, "Sharpen More"),
    menu_filters_filters_14(menu_filters_filters_image_14, "Find Edges"),
    menu_filters_filters_15(menu_filters_filters_image_15, "Mean Blur"),
    menu_filters_filters_16(menu_filters_filters_image_16, "Mean Blur More"),
    menu_filters_filters_17(menu_filters_filters_image_17, "Blur"),
    menu_filters_filters_18(menu_filters_filters_image_18, "Blur Median"),
    menu_filters_filters_19(menu_filters_filters_image_19, "Blur Gaussian"),
    menu_filters_filters_20(menu_filters_filters_image_20, "Denoising"),
    menu_filters_filters_21(menu_filters_filters_image_21, "Erode"),
    menu_filters_filters_22(menu_filters_filters_image_22, "Dilate"),
    menu_filters_filters_23(menu_filters_filters_image_23, "Wave Horizontally"),
    menu_filters_filters_24(menu_filters_filters_image_24, "Wave Vertically"),
    menu_filters_filters_25(menu_filters_filters_image_25, "Wave Twice"),
    menu_filters_filters_26(menu_filters_filters_image_26, "Contours Sobel White"),
    menu_filters_filters_27(menu_filters_filters_image_27, "Contours Sobel Black"),
    menu_filters_filters_28(menu_filters_filters_image_28, "Contours Sobel Emboss"),
    menu_filters_filters_29(menu_filters_filters_image_29, "Emboss Sobel"),
    menu_filters_filters_30(menu_filters_filters_image_30, "Emboss Laplacian"),
    menu_filters_filters_31(menu_filters_filters_image_31, "Binary White OTSU"),
    menu_filters_filters_32(menu_filters_filters_image_32, "Binary White TRIANGLE"),
    menu_filters_filters_33(menu_filters_filters_image_33, "Binary White AVERAGE"),
    menu_filters_filters_34(menu_filters_filters_image_34, "Binary Black OTSU"),
    menu_filters_filters_35(menu_filters_filters_image_35, "Binary Black TRIANGLE"),
    menu_filters_filters_36(menu_filters_filters_image_36, "Binary Black AVERAGE"),
    menu_filters_filters_37(menu_filters_filters_image_37, "Binary Contours White"),
    menu_filters_filters_38(menu_filters_filters_image_38, "Binary Contours Black"),
   

    menu_filters_grayscale_image_00(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_grayscale_image_01(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_grayscale_image_02(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_grayscale_image_03(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_grayscale_image_04(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_grayscale_image_05(PATH_TO_MENU_ICONS "dialog-ok.png"),



    menu_filters_grayscale_00(menu_filters_grayscale_image_00, "Gray Scaling Average"),
    menu_filters_grayscale_01(menu_filters_grayscale_image_01, "Gray Scaling Maximal"),
    menu_filters_grayscale_02(menu_filters_grayscale_image_02, "Gray Scaling Minimal"),
    menu_filters_grayscale_03(menu_filters_grayscale_image_03, "Gray Scaling Red"),
    menu_filters_grayscale_04(menu_filters_grayscale_image_04, "Gray Scaling Green"),
    menu_filters_grayscale_05(menu_filters_grayscale_image_05, "Gray Scaling Blue"),



    menu_filters_colorscale_image_00(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_colorscale_image_01(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_colorscale_image_02(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_colorscale_image_03(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_colorscale_image_04(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_colorscale_image_05(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_colorscale_image_06(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_colorscale_image_07(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_colorscale_image_08(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_colorscale_image_09(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_colorscale_image_10(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_colorscale_image_11(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_colorscale_image_12(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_colorscale_image_13(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_colorscale_image_14(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_colorscale_image_15(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_colorscale_image_16(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_colorscale_image_17(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_colorscale_image_18(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_colorscale_image_19(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_colorscale_image_20(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_colorscale_image_21(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_colorscale_image_22(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_colorscale_image_23(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_colorscale_image_24(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_colorscale_image_25(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_colorscale_image_26(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_colorscale_image_27(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_colorscale_image_28(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_colorscale_image_29(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_colorscale_image_30(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_colorscale_image_31(PATH_TO_MENU_ICONS "dialog-ok.png"),
    menu_filters_colorscale_image_32(PATH_TO_MENU_ICONS "dialog-ok.png"),

    menu_filters_colorscale_00(menu_filters_colorscale_image_00, "Red Scaling Average"),
    menu_filters_colorscale_01(menu_filters_colorscale_image_01, "Red Scaling Maximal"),
    menu_filters_colorscale_02(menu_filters_colorscale_image_02, "Red Scaling Minimal"),
    menu_filters_colorscale_03(menu_filters_colorscale_image_03, "Red Scaling Green  "),
    menu_filters_colorscale_04(menu_filters_colorscale_image_04, "Red Scaling Blue   "),
    menu_filters_colorscale_05(menu_filters_colorscale_image_05, "Green Scaling Average"),
    menu_filters_colorscale_06(menu_filters_colorscale_image_06, "Green Scaling Maximal"),
    menu_filters_colorscale_07(menu_filters_colorscale_image_07, "Green Scaling Minimal"),
    menu_filters_colorscale_08(menu_filters_colorscale_image_08, "Green Scaling Red    "),
    menu_filters_colorscale_09(menu_filters_colorscale_image_09, "Green Scaling Blue   "),
    menu_filters_colorscale_10(menu_filters_colorscale_image_10, "Blue Scaling Average"),
    menu_filters_colorscale_11(menu_filters_colorscale_image_11, "Blue Scaling Maximal"),
    menu_filters_colorscale_12(menu_filters_colorscale_image_12, "Blue Scaling Minimal"),
    menu_filters_colorscale_13(menu_filters_colorscale_image_13, "Blue Scaling Red    "),
    menu_filters_colorscale_14(menu_filters_colorscale_image_14, "Blue Scaling Green  "),
    menu_filters_colorscale_15(menu_filters_colorscale_image_15, "Yellow Scaling Average"),
    menu_filters_colorscale_16(menu_filters_colorscale_image_16, "Yellow Scaling Maximal"),
    menu_filters_colorscale_17(menu_filters_colorscale_image_17, "Yellow Scaling Minimal"),
    menu_filters_colorscale_18(menu_filters_colorscale_image_18, "Yellow Scaling Red    "),
    menu_filters_colorscale_19(menu_filters_colorscale_image_19, "Yellow Scaling Green  "),
    menu_filters_colorscale_20(menu_filters_colorscale_image_20, "Yellow Scaling Blue   "),
    menu_filters_colorscale_21(menu_filters_colorscale_image_21, "Pink Scaling Average"),
    menu_filters_colorscale_22(menu_filters_colorscale_image_22, "Pink Scaling Maximal"),
    menu_filters_colorscale_23(menu_filters_colorscale_image_23, "Pink Scaling Minimal"),
    menu_filters_colorscale_24(menu_filters_colorscale_image_24, "Pink Scaling Red    "),
    menu_filters_colorscale_25(menu_filters_colorscale_image_25, "Pink Scaling Green  "),
    menu_filters_colorscale_26(menu_filters_colorscale_image_26, "Pink Scaling Blue   "),
    menu_filters_colorscale_27(menu_filters_colorscale_image_27, "Turquoise Scaling Average"),
    menu_filters_colorscale_28(menu_filters_colorscale_image_28, "Turquoise Scaling Maximal"),
    menu_filters_colorscale_29(menu_filters_colorscale_image_29, "Turquoise Scaling Minimal"),
    menu_filters_colorscale_30(menu_filters_colorscale_image_30, "Turquoise Scaling Red    "),
    menu_filters_colorscale_31(menu_filters_colorscale_image_31, "Turquoise Scaling Green  "),
    menu_filters_colorscale_32(menu_filters_colorscale_image_32, "Turquoise Scaling Blue   "),

   
   


    buttonbar(Gtk::ORIENTATION_HORIZONTAL, 0),

    padding_buttonbox_1(),

    buttonbox_files(),
    button_open("Open"),
    button_save("Save"),

    image_open(PATH_TO_BUTTON_ICONS "folder-image.png"),
    image_save(PATH_TO_BUTTON_ICONS "document-save-as.png"),

    padding_buttonbox_2(),

    buttonbox_undo_redo(),
    button_undo("Undo"),
    button_redo("Redo"),

    image_undo(PATH_TO_BUTTON_ICONS "go-previous-view.png"),
    image_redo(PATH_TO_BUTTON_ICONS "go-next-view.png"),

    padding_buttonbox_3(),

    buttonbox_rot(),
    button_rot_label("Rotate"),
    button_rot_left(""),
    button_rot_right(""),

    image_rot_left(PATH_TO_BUTTON_ICONS "object-rotate-left.png"),
    image_rot_right(PATH_TO_BUTTON_ICONS "object-rotate-right.png"),



    //spinbutton_rot_angle(),

    padding_buttonbox_4(),

    buttonbox_mirror(),
    button_mirror_label("Mirror"),
    button_mirror_left(""),
    button_mirror_right(""),
    button_mirror_top(""),
    button_mirror_bottom(""),

    image_mirror_left(PATH_TO_BUTTON_ICONS "distribute-horizontal-left.png"),
    image_mirror_right(PATH_TO_BUTTON_ICONS "distribute-horizontal-right.png"),
    image_mirror_top(PATH_TO_BUTTON_ICONS "distribute-vertical-top.png"),
    image_mirror_bottom(PATH_TO_BUTTON_ICONS "distribute-vertical-bottom.png"),

    padding_buttonbox_5(),

    buttonbox_zoom(),
    button_zoom_label("Zoom"),
    button_zoom_plus(""),
    button_zoom_minus(""),
    button_zoom_pointer(""),



    image_zoom_plus(PATH_TO_BUTTON_ICONS "zoom-in.png"),
    image_zoom_minus(PATH_TO_BUTTON_ICONS "zoom-out.png"),
    image_zoom_pointer(PATH_TO_BUTTON_ICONS "edit-select.png"),


    padding_buttonbox_6(),

    buttonbox_flip(),

    button_flip_label("Flip"),
    button_flip_left(""),
    button_flip_right(""),
    button_flip_up(""),
    button_flip_down(""),

    image_flip_left(PATH_TO_BUTTON_ICONS "go-previous.png"),
    image_flip_right(PATH_TO_BUTTON_ICONS "go-next.png"),
    image_flip_up(PATH_TO_BUTTON_ICONS "go-up.png"),
    image_flip_down(PATH_TO_BUTTON_ICONS "go-down.png"),




    padding_buttonbox_7(),




    middle_box(Gtk::ORIENTATION_HORIZONTAL),

    box_sidebar_main(Gtk::ORIENTATION_HORIZONTAL),

    box_sidebar_01(Gtk::ORIENTATION_VERTICAL),

    box_execute(Gtk::ORIENTATION_VERTICAL),


    frame_sidebar_filters(   " Filters "),
    frame_sidebar_grayscale( " Grayscale "),
    frame_sidebar_colorscale(" Colorscale "),

    box_filters(Gtk::ORIENTATION_HORIZONTAL),
    box_grayscale(Gtk::ORIENTATION_HORIZONTAL),
    box_colorscale(Gtk::ORIENTATION_HORIZONTAL),

    combo_filters(true),
    combo_grayscale(true),
    combo_colorscale(true),

    button_filters(),
    button_grayscale(),
    button_colorscale(),

    button_image_filters(PATH_TO_BUTTON_ICONS "dialog-ok.png"),
    button_image_grayscale(PATH_TO_BUTTON_ICONS "dialog-ok.png"),
    button_image_colorscale(PATH_TO_BUTTON_ICONS "dialog-ok.png"),

    frame_switcher("Show settings"),
    buttonbox_switcher(),


    button_intensity("Intensity"),
    button_hsbl("Colospace"),

    image_switcher_on(PATH_TO_BUTTON_ICONS "dialog-ok-apply.png"),
    image_switcher_off(PATH_TO_BUTTON_ICONS "list-remove.png"),

    notebook_switcher(),


    frame_sidebar_intensity(" Intensity "),

    frame_sidebar_hsbl(" Colospace "),

    box_intensity_rgbm(Gtk::ORIENTATION_HORIZONTAL),
    box_colorspace_hsbl(Gtk::ORIENTATION_HORIZONTAL),

    box_intensity_vertical(Gtk::ORIENTATION_VERTICAL),
    box_colorspace_vertical(Gtk::ORIENTATION_VERTICAL),







    frame_intensity_red(   "  Red   "  ),
    frame_intensity_green( "Green "  ),
    frame_intensity_blue(  "Blue   "  ),
    frame_intensity_main(  "Global "  ),



    scale_intensity_red(Gtk::ORIENTATION_VERTICAL),
    scale_intensity_green(Gtk::ORIENTATION_VERTICAL),
    scale_intensity_blue(Gtk::ORIENTATION_VERTICAL),
    scale_intensity_main(Gtk::ORIENTATION_VERTICAL),

    buttonbox_intensity_apply(Gtk::ORIENTATION_HORIZONTAL),
    box_intensity_red(Gtk::ORIENTATION_VERTICAL),
    box_intensity_green(Gtk::ORIENTATION_VERTICAL),
    box_intensity_blue(Gtk::ORIENTATION_VERTICAL),
    box_intensity_main(Gtk::ORIENTATION_VERTICAL),

    button_red_apply("Apply"),
    image_red_apply(PATH_TO_BUTTON_ICONS "dialog-ok.png"),
    button_green_apply("Apply"),
    image_green_apply(PATH_TO_BUTTON_ICONS "dialog-ok.png"),
    button_blue_apply("Apply"),
    image_blue_apply(PATH_TO_BUTTON_ICONS "dialog-ok.png"),
    button_main_apply("Apply"),
    image_main_apply(PATH_TO_BUTTON_ICONS "dialog-ok.png"),

    frame_lightness(   " Lightness "   ),
    frame_hue(         "    Hue       "   ),
    frame_saturation(  "Saturation"  ),
    frame_brightness(  "Brightness"  ),

    scale_lightness(Gtk::ORIENTATION_VERTICAL),
    scale_hue(Gtk::ORIENTATION_VERTICAL),
    scale_saturation(Gtk::ORIENTATION_VERTICAL),
    scale_brightness(Gtk::ORIENTATION_VERTICAL),

    buttonbox_hsbl_apply(Gtk::ORIENTATION_HORIZONTAL),
    box_hsbl_lightness(Gtk::ORIENTATION_VERTICAL),
    box_hsbl_hue(Gtk::ORIENTATION_VERTICAL),
    box_hsbl_saturation(Gtk::ORIENTATION_VERTICAL),
    box_hsbl_brightness(Gtk::ORIENTATION_VERTICAL),


    button_lightness_apply("Apply"),
    image_lightness_apply(PATH_TO_BUTTON_ICONS "dialog-ok.png"),
    button_hue_apply("Apply"),
    image_hue_apply(PATH_TO_BUTTON_ICONS "dialog-ok.png"),
    button_saturation_apply("Apply"),
    image_saturation_apply(PATH_TO_BUTTON_ICONS "dialog-ok.png"),
    button_brightness_apply("Apply"),
    image_brightness_apply(PATH_TO_BUTTON_ICONS "dialog-ok.png"),

    display_area(),

    box_image_displaying(Gtk::ORIENTATION_VERTICAL),

    middle_box_v(Gtk::ORIENTATION_VERTICAL),

    box_info_bar_image_bottom(Gtk::ORIENTATION_HORIZONTAL),

    label_info_bar_padding_1(""),
    label_info_bar_mouse_coords(" Coordinates: -1,-1  ;"),
    label_info_bar_padding_2(""),

    label_info_bar_filename(""),
    label_info_bar_padding_3(""),
    label_info_bar_file_size(""),
    label_info_bar_padding_4(""),


    buttonbox_bottom(),

    buttonbox_bottom_padding_1(),
    buttonbox_bottom_draw(),
    buttonbox_bottom_padding_2(),
    buttonbox_bottom_config(),
    buttonbox_bottom_padding_3(),


    button_label_draw("Draw"),
    button_draw_rect(""),
    button_draw_line(""),
    button_draw_circle(""),
    button_draw_ellipse(""),
    button_draw_polygon(""),
    button_draw_star(""),
    button_draw_text(""),


    image_label_draw(PATH_TO_BUTTON_ICONS       "draw-path.png"),
    image_draw_line(PATH_TO_BUTTON_ICONS        "draw-polyline.png"),
    image_draw_rect(PATH_TO_BUTTON_ICONS        "draw-rectangle.png"),
    image_draw_circle(PATH_TO_BUTTON_ICONS      "draw-circle.png"),
    image_draw_ellipse(PATH_TO_BUTTON_ICONS     "draw-ellipse.png"),
    image_draw_polygon(PATH_TO_BUTTON_ICONS     "draw-polygon.png"),
    image_draw_star(PATH_TO_BUTTON_ICONS        "draw-star.png"),
    image_draw_text(PATH_TO_BUTTON_ICONS        "insert-text.png"),

    label_draw_thickness("Thickness"),
    image_label_thickness(PATH_TO_BUTTON_ICONS  "draw-brush.png"),
    spinbutton_draw_thickness(),
    label_draw_color("Color"),
    image_label_draw_color(PATH_TO_BUTTON_ICONS  "preferences-desktop-color.png"),
    colorbutton_draw(),
    combo_lines_type(), // Cannot set an entry **combo_lines_type(true)** because it increase the size of the combobox dramatically
                        // without minimal size respect.

    frame_buttonbox_top()


  {


    set_title(PRGNAME_STRING) ;
    set_resizable(true)       ;



    maximize()               ;
    set_border_width(6)      ;

    set_default_icon_from_file(PATH_TO_EDIP_ICON "Edip_icon.png") ;

    mouse_cursor_set_center = mouse_cursor_set_center->create(Gdk::CROSSHAIR) ;

    mouse_cursor_set_activate = mouse_cursor_set_activate->create( get_display(), Gdk::Pixbuf::create_from_file(PATH_TO_MOUSE_CURSOR_ICON "arrow.png"), 0, 0) ;

    if ( (! mouse_cursor_set_center) || (! mouse_cursor_set_activate) )   {

      fprintf(stdout,"Cannot create mouse cursor !!!\n") ;
    }




    menu_files_button_container.set_homogeneous(false) ;
    menu_files_button_container.pack_start(menu_files_button_image, false, false, 0) ;
    menu_files_button_container.pack_start(menu_files_button_label, false, false, 0) ;
    menu_files_button.add(menu_files_button_container) ;


    menu_edition_button_container.set_homogeneous(false) ;
    menu_edition_button_container.pack_start(menu_edition_button_image, false, false, 0) ;
    menu_edition_button_container.pack_start(menu_edition_button_label, false, false, 0) ;
    menu_edition_button.add(menu_edition_button_container) ;

    menu_filters_button_container.set_homogeneous(false) ;
    menu_filters_button_container.pack_start(menu_filters_button_image, false, false, 0) ;
    menu_filters_button_container.pack_start(menu_filters_button_label, false, false, 0) ;
    menu_filters_button.add(menu_filters_button_container) ;


    menu_infos_button_container.set_homogeneous(false) ;
    menu_infos_button_container.pack_start(menu_infos_button_image, false, false, 0) ;
    menu_infos_button_container.pack_start(menu_infos_button_label, false, false, 0) ;
    menu_infos_button.add(menu_infos_button_container) ;


    menu_files_open_file_container.set_homogeneous(false) ;
    menu_files_open_file_container.pack_start(menu_files_open_file_image,       false, false, 0) ;
    menu_files_open_file_container.pack_start(menu_files_open_file_label,       false, false, 0) ;
    menu_files_open_file_container.pack_start(menu_files_open_file_padding,     true, true,   0) ;
    menu_files_open_file_container.pack_start(menu_files_open_file_accel_label, false, false, 0) ;
    menu_files_open_file_button.add(menu_files_open_file_container) ;


    menu_files_recent_file_container.set_homogeneous(false) ;
    menu_files_recent_file_container.pack_start(menu_files_recent_file_image,       false, false, 0) ;
    menu_files_recent_file_container.pack_start(menu_files_recent_file_label,       false, false, 0) ;
    menu_files_recent_file_container.pack_start(menu_files_recent_file_padding,     true, true,   0) ;
    menu_files_recent_file_container.pack_start(menu_files_recent_file_accel_label, false, false, 0) ;
    menu_files_recent_file_button.add(menu_files_recent_file_container) ;

    menu_files_blend_images_container.set_homogeneous(false) ;
    menu_files_blend_images_container.pack_start(menu_files_blend_images_image,       false, false, 0) ;
    menu_files_blend_images_container.pack_start(menu_files_blend_images_label,       false, false, 0) ;
    menu_files_blend_images_container.pack_start(menu_files_blend_images_padding,     true, true,   0) ;
    menu_files_blend_images_container.pack_start(menu_files_blend_images_accel_label, false, false, 0) ;
    menu_files_blend_images_button.add(menu_files_blend_images_container) ;

    menu_files_screen_images_container.set_homogeneous(false) ;
    menu_files_screen_images_container.pack_start(menu_files_screen_images_image,       false, false, 0) ;
    menu_files_screen_images_container.pack_start(menu_files_screen_images_label,       false, false, 0) ;
    menu_files_screen_images_container.pack_start(menu_files_screen_images_padding,     true, true,   0) ;
    menu_files_screen_images_container.pack_start(menu_files_screen_images_accel_label, false, false, 0) ;
    menu_files_screen_images_button.add(menu_files_screen_images_container) ;


    menu_files_darker_images_container.set_homogeneous(false) ;
    menu_files_darker_images_container.pack_start(menu_files_darker_images_image,       false, false, 0) ;
    menu_files_darker_images_container.pack_start(menu_files_darker_images_label,       false, false, 0) ;
    menu_files_darker_images_container.pack_start(menu_files_darker_images_padding,     true, true,   0) ;
    menu_files_darker_images_container.pack_start(menu_files_darker_images_accel_label, false, false, 0) ;
    menu_files_darker_images_button.add(menu_files_darker_images_container) ;

    menu_files_lighter_images_container.set_homogeneous(false) ;
    menu_files_lighter_images_container.pack_start(menu_files_lighter_images_image,       false, false, 0) ;
    menu_files_lighter_images_container.pack_start(menu_files_lighter_images_label,       false, false, 0) ;
    menu_files_lighter_images_container.pack_start(menu_files_lighter_images_padding,     true, true,   0) ;
    menu_files_lighter_images_container.pack_start(menu_files_lighter_images_accel_label, false, false, 0) ;
    menu_files_lighter_images_button.add(menu_files_lighter_images_container) ;

    menu_files_add_images_container.set_homogeneous(false) ;
    menu_files_add_images_container.pack_start(menu_files_add_images_image,       false, false, 0) ;
    menu_files_add_images_container.pack_start(menu_files_add_images_label,       false, false, 0) ;
    menu_files_add_images_container.pack_start(menu_files_add_images_padding,     true, true,   0) ;
    menu_files_add_images_container.pack_start(menu_files_add_images_accel_label, false, false, 0) ;
    menu_files_add_images_button.add(menu_files_add_images_container) ;

    menu_files_add_modulo_images_container.set_homogeneous(false) ;
    menu_files_add_modulo_images_container.pack_start(menu_files_add_modulo_images_image,       false, false, 0) ;
    menu_files_add_modulo_images_container.pack_start(menu_files_add_modulo_images_label,       false, false, 0) ;
    menu_files_add_modulo_images_container.pack_start(menu_files_add_modulo_images_padding,     true, true,   0) ;
    menu_files_add_modulo_images_container.pack_start(menu_files_add_modulo_images_accel_label, false, false, 0) ;
    menu_files_add_modulo_images_button.add(menu_files_add_modulo_images_container) ;

    menu_files_sub_images_container.set_homogeneous(false) ;
    menu_files_sub_images_container.pack_start(menu_files_sub_images_image,       false, false, 0) ;
    menu_files_sub_images_container.pack_start(menu_files_sub_images_label,       false, false, 0) ;
    menu_files_sub_images_container.pack_start(menu_files_sub_images_padding,     true, true,   0) ;
    menu_files_sub_images_container.pack_start(menu_files_sub_images_accel_label, false, false, 0) ;
    menu_files_sub_images_button.add(menu_files_sub_images_container) ;

    menu_files_sub_modulo_images_container.set_homogeneous(false) ;
    menu_files_sub_modulo_images_container.pack_start(menu_files_sub_modulo_images_image,       false, false, 0) ;
    menu_files_sub_modulo_images_container.pack_start(menu_files_sub_modulo_images_label,       false, false, 0) ;
    menu_files_sub_modulo_images_container.pack_start(menu_files_sub_modulo_images_padding,     true, true,   0) ;
    menu_files_sub_modulo_images_container.pack_start(menu_files_sub_modulo_images_accel_label, false, false, 0) ;
    menu_files_sub_modulo_images_button.add(menu_files_sub_modulo_images_container) ;


    menu_files_save_file_container.set_homogeneous(false) ;
    menu_files_save_file_container.pack_start(menu_files_save_file_image,       false, false, 0) ;
    menu_files_save_file_container.pack_start(menu_files_save_file_label,       false, false, 0) ;
    menu_files_save_file_container.pack_start(menu_files_save_file_padding,     true, true,   0) ;
    menu_files_save_file_container.pack_start(menu_files_save_file_accel_label, false, false, 0) ;
    menu_files_save_file_button.add(menu_files_save_file_container) ;


    menu_edition_undo_container.set_homogeneous(false) ;
    menu_edition_undo_container.pack_start(menu_edition_undo_image,       false, false, 0) ;
    menu_edition_undo_container.pack_start(menu_edition_undo_label,       false, false, 0) ;
    menu_edition_undo_container.pack_start(menu_edition_undo_padding,     true, true,   0) ;
    menu_edition_undo_container.pack_start(menu_edition_undo_accel_label, false, false, 0) ;
    menu_edition_undo_button.add(menu_edition_undo_container) ;


    menu_edition_redo_container.set_homogeneous(false) ;
    menu_edition_redo_container.pack_start(menu_edition_redo_image,       false, false, 0) ;
    menu_edition_redo_container.pack_start(menu_edition_redo_label,       false, false, 0) ;
    menu_edition_redo_container.pack_start(menu_edition_redo_padding,     true, true,   0) ;
    menu_edition_redo_container.pack_start(menu_edition_redo_accel_label, false, false, 0) ;
    menu_edition_redo_button.add(menu_edition_redo_container) ;


    menu_edition_rotate_left_container.set_homogeneous(false) ;
    menu_edition_rotate_left_container.pack_start(menu_edition_rotate_left_image,       false, false, 0) ;
    menu_edition_rotate_left_container.pack_start(menu_edition_rotate_left_label,       false, false, 0) ;
    menu_edition_rotate_left_container.pack_start(menu_edition_rotate_left_padding,     true, true,   0) ;
    menu_edition_rotate_left_container.pack_start(menu_edition_rotate_left_accel_label, false, false, 0) ;
    menu_edition_rotate_left_button.add(menu_edition_rotate_left_container) ;

    menu_edition_rotate_right_container.set_homogeneous(false) ;
    menu_edition_rotate_right_container.pack_start(menu_edition_rotate_right_image,       false, false, 0) ;
    menu_edition_rotate_right_container.pack_start(menu_edition_rotate_right_label,       false, false, 0) ;
    menu_edition_rotate_right_container.pack_start(menu_edition_rotate_right_padding,     true, true,   0) ;
    menu_edition_rotate_right_container.pack_start(menu_edition_rotate_right_accel_label, false, false, 0) ;
    menu_edition_rotate_right_button.add(menu_edition_rotate_right_container) ;


    menu_edition_mirror_left_to_right_container.set_homogeneous(false) ;
    menu_edition_mirror_left_to_right_container.pack_start(menu_edition_mirror_left_to_right_image,       false, false, 0) ;
    menu_edition_mirror_left_to_right_container.pack_start(menu_edition_mirror_left_to_right_label,       false, false, 0) ;
    menu_edition_mirror_left_to_right_container.pack_start(menu_edition_mirror_left_to_right_padding,     true, true,   0) ;
    menu_edition_mirror_left_to_right_container.pack_start(menu_edition_mirror_left_to_right_accel_label, false, false, 0) ;
    menu_edition_mirror_left_to_right_button.add(menu_edition_mirror_left_to_right_container) ;


    menu_edition_mirror_right_to_left_container.set_homogeneous(false) ;
    menu_edition_mirror_right_to_left_container.pack_start(menu_edition_mirror_right_to_left_image,       false, false, 0) ;
    menu_edition_mirror_right_to_left_container.pack_start(menu_edition_mirror_right_to_left_label,       false, false, 0) ;
    menu_edition_mirror_right_to_left_container.pack_start(menu_edition_mirror_right_to_left_padding,     true, true,   0) ;
    menu_edition_mirror_right_to_left_container.pack_start(menu_edition_mirror_right_to_left_accel_label, false, false, 0) ;
    menu_edition_mirror_right_to_left_button.add(menu_edition_mirror_right_to_left_container) ;


    menu_edition_mirror_up_to_down_container.set_homogeneous(false) ;
    menu_edition_mirror_up_to_down_container.pack_start(menu_edition_mirror_up_to_down_image,       false, false, 0) ;
    menu_edition_mirror_up_to_down_container.pack_start(menu_edition_mirror_up_to_down_label,       false, false, 0) ;
    menu_edition_mirror_up_to_down_container.pack_start(menu_edition_mirror_up_to_down_padding,     true, true,   0) ;
    menu_edition_mirror_up_to_down_container.pack_start(menu_edition_mirror_up_to_down_accel_label, false, false, 0) ;
    menu_edition_mirror_up_to_down_button.add(menu_edition_mirror_up_to_down_container) ;


    menu_edition_mirror_down_to_up_container.set_homogeneous(false) ;
    menu_edition_mirror_down_to_up_container.pack_start(menu_edition_mirror_down_to_up_image,       false, false, 0) ;
    menu_edition_mirror_down_to_up_container.pack_start(menu_edition_mirror_down_to_up_label,       false, false, 0) ;
    menu_edition_mirror_down_to_up_container.pack_start(menu_edition_mirror_down_to_up_padding,     true, true,   0) ;
    menu_edition_mirror_down_to_up_container.pack_start(menu_edition_mirror_down_to_up_accel_label, false, false, 0) ;
    menu_edition_mirror_down_to_up_button.add(menu_edition_mirror_down_to_up_container) ;


    menu_edition_zoom_plus_container.set_homogeneous(false) ;
    menu_edition_zoom_plus_container.pack_start(menu_edition_zoom_plus_image,       false, false, 0) ;
    menu_edition_zoom_plus_container.pack_start(menu_edition_zoom_plus_label,       false, false, 0) ;
    menu_edition_zoom_plus_container.pack_start(menu_edition_zoom_plus_padding,     true, true,   0) ;
    menu_edition_zoom_plus_container.pack_start(menu_edition_zoom_plus_accel_label, false, false, 0) ;
    menu_edition_zoom_plus_button.add(menu_edition_zoom_plus_container) ;

    menu_edition_zoom_minus_container.set_homogeneous(false) ;
    menu_edition_zoom_minus_container.pack_start(menu_edition_zoom_minus_image,       false, false, 0) ;
    menu_edition_zoom_minus_container.pack_start(menu_edition_zoom_minus_label,       false, false, 0) ;
    menu_edition_zoom_minus_container.pack_start(menu_edition_zoom_minus_padding,     true, true,   0) ;
    menu_edition_zoom_minus_container.pack_start(menu_edition_zoom_minus_accel_label, false, false, 0) ;
    menu_edition_zoom_minus_button.add(menu_edition_zoom_minus_container) ;


    menu_edition_flip_left_container.set_homogeneous(false) ;
    menu_edition_flip_left_container.pack_start(menu_edition_flip_left_image,       false, false, 0) ;
    menu_edition_flip_left_container.pack_start(menu_edition_flip_left_label,       false, false, 0) ;
    menu_edition_flip_left_container.pack_start(menu_edition_flip_left_padding,     true, true,   0) ;
    menu_edition_flip_left_container.pack_start(menu_edition_flip_left_accel_label, false, false, 0) ;
    menu_edition_flip_left_button.add(menu_edition_flip_left_container) ;

    menu_edition_flip_right_container.set_homogeneous(false) ;
    menu_edition_flip_right_container.pack_start(menu_edition_flip_right_image,       false, false, 0) ;
    menu_edition_flip_right_container.pack_start(menu_edition_flip_right_label,       false, false, 0) ;
    menu_edition_flip_right_container.pack_start(menu_edition_flip_right_padding,     true, true,   0) ;
    menu_edition_flip_right_container.pack_start(menu_edition_flip_right_accel_label, false, false, 0) ;
    menu_edition_flip_right_button.add(menu_edition_flip_right_container) ;

    menu_edition_flip_up_container.set_homogeneous(false) ;
    menu_edition_flip_up_container.pack_start(menu_edition_flip_up_image,       false, false, 0) ;
    menu_edition_flip_up_container.pack_start(menu_edition_flip_up_label,       false, false, 0) ;
    menu_edition_flip_up_container.pack_start(menu_edition_flip_up_padding,     true, true,   0) ;
    menu_edition_flip_up_container.pack_start(menu_edition_flip_up_accel_label, false, false, 0) ;
    menu_edition_flip_up_button.add(menu_edition_flip_up_container) ;

    menu_edition_flip_down_container.set_homogeneous(false) ;
    menu_edition_flip_down_container.pack_start(menu_edition_flip_down_image,       false, false, 0) ;
    menu_edition_flip_down_container.pack_start(menu_edition_flip_down_label,       false, false, 0) ;
    menu_edition_flip_down_container.pack_start(menu_edition_flip_down_padding,     true, true,   0) ;
    menu_edition_flip_down_container.pack_start(menu_edition_flip_down_accel_label, false, false, 0) ;
    menu_edition_flip_down_button.add(menu_edition_flip_down_container) ;


    menu_filters_filters_container.set_homogeneous(false) ;
    menu_filters_filters_container.pack_start(menu_filters_filters_image,       false, false, 0) ;
    menu_filters_filters_container.pack_start(menu_filters_filters_label,       false, false, 0) ;
    menu_filters_filters_container.pack_start(menu_filters_filters_padding,     true, true,   0) ;
    menu_filters_filters_container.pack_start(menu_filters_filters_accel_label, false, false, 0) ;
    menu_filters_filters_button.add(menu_filters_filters_container) ;

    menu_filters_kernel_filters_container.set_homogeneous(false) ;
    menu_filters_kernel_filters_container.pack_start(menu_filters_kernel_filters_image,       false, false, 0) ;
    menu_filters_kernel_filters_container.pack_start(menu_filters_kernel_filters_label,       false, false, 0) ;
    menu_filters_kernel_filters_container.pack_start(menu_filters_kernel_filters_padding,     true, true,   0) ;
    menu_filters_kernel_filters_container.pack_start(menu_filters_kernel_filters_accel_label, false, false, 0) ;
    menu_filters_kernel_filters_button.add(menu_filters_kernel_filters_container) ;




    menu_filters_kernel_sharpen_button.set_image(menu_filters_kernel_sharpen_image) ;
    menu_filters_kernel_sharpen_button.set_always_show_image(true) ;

    menu_filters_kernel_find_edges_button.set_image(menu_filters_kernel_find_edges_image) ;
    menu_filters_kernel_find_edges_button.set_always_show_image(true) ;

    menu_filters_kernel_emboss_button.set_image(menu_filters_kernel_emboss_image) ;
    menu_filters_kernel_emboss_button.set_always_show_image(true) ;

    menu_filters_kernel_mean_button.set_image(menu_filters_kernel_mean_image) ;
    menu_filters_kernel_mean_button.set_always_show_image(true) ;

    menu_filters_kernel_gaussian_button.set_image(menu_filters_kernel_gaussian_image) ;
    menu_filters_kernel_gaussian_button.set_always_show_image(true) ;

    menu_filters_kernel_kirsch_button.set_image(menu_filters_kernel_kirsch_image) ;
    menu_filters_kernel_kirsch_button.set_always_show_image(true) ;

    menu_filters_photo_filters_container.set_homogeneous(false) ;
    menu_filters_photo_filters_container.pack_start(menu_filters_photo_filters_image,       false, false, 0) ;
    menu_filters_photo_filters_container.pack_start(menu_filters_photo_filters_label,       false, false, 0) ;
    menu_filters_photo_filters_container.pack_start(menu_filters_photo_filters_padding,     true, true,   0) ;
    menu_filters_photo_filters_container.pack_start(menu_filters_photo_filters_accel_label, false, false, 0) ;
    menu_filters_photo_filters_button.add(menu_filters_photo_filters_container) ;

    menu_filters_photo_pencil_sketch_button.set_image(menu_filters_photo_pencil_sketch_image) ;
    menu_filters_photo_pencil_sketch_button.set_always_show_image(true) ;

    menu_filters_photo_stylisation_button.set_image(menu_filters_photo_stylisation_image) ;
    menu_filters_photo_stylisation_button.set_always_show_image(true) ;

    menu_filters_photo_detail_enhance_button.set_image(menu_filters_photo_detail_enhance_image) ;
    menu_filters_photo_detail_enhance_button.set_always_show_image(true) ;

    menu_filters_photo_edges_preserving_button.set_image(menu_filters_photo_edges_preserving_image) ;
    menu_filters_photo_edges_preserving_button.set_always_show_image(true) ;

    menu_filters_photo_denoising_button.set_image(menu_filters_photo_denoising_image) ;
    menu_filters_photo_denoising_button.set_always_show_image(true) ;

    menu_filters_morphological_container.set_homogeneous(false) ;
    menu_filters_morphological_container.pack_start(menu_filters_morphological_image,       false, false, 0) ;
    menu_filters_morphological_container.pack_start(menu_filters_morphological_label,       false, false, 0) ;
    menu_filters_morphological_container.pack_start(menu_filters_morphological_padding,     true, true,   0) ;
    menu_filters_morphological_container.pack_start(menu_filters_morphological_accel_label, false, false, 0) ;
    menu_filters_morphological_button.add(menu_filters_morphological_container) ;

    menu_filters_canny_container.set_homogeneous(false) ;
    menu_filters_canny_container.pack_start(menu_filters_canny_image,       false, false, 0) ;
    menu_filters_canny_container.pack_start(menu_filters_canny_label,       false, false, 0) ;
    menu_filters_canny_container.pack_start(menu_filters_canny_padding,     true, true,   0) ;
    menu_filters_canny_container.pack_start(menu_filters_canny_accel_label, false, false, 0) ;
    menu_filters_canny_button.add(menu_filters_canny_container) ;

    menu_filters_color_contours_container.set_homogeneous(false) ;
    menu_filters_color_contours_container.pack_start(menu_filters_color_contours_image,       false, false, 0) ;
    menu_filters_color_contours_container.pack_start(menu_filters_color_contours_label,       false, false, 0) ;
    menu_filters_color_contours_container.pack_start(menu_filters_color_contours_padding,     true, true,   0) ;
    menu_filters_color_contours_container.pack_start(menu_filters_color_contours_accel_label, false, false, 0) ;
    menu_filters_color_contours_button.add(menu_filters_color_contours_container) ;

    menu_filters_grayscale_container.set_homogeneous(false) ;
    menu_filters_grayscale_container.pack_start(menu_filters_grayscale_image,       false, false, 0) ;
    menu_filters_grayscale_container.pack_start(menu_filters_grayscale_label,       false, false, 0) ;
    menu_filters_grayscale_container.pack_start(menu_filters_grayscale_padding,     true, true,   0) ;
    menu_filters_grayscale_container.pack_start(menu_filters_grayscale_accel_label, false, false, 0) ;
    menu_filters_grayscale_button.add(menu_filters_grayscale_container) ;


    menu_filters_colorscale_container.set_homogeneous(false) ;
    menu_filters_colorscale_container.pack_start(menu_filters_colorscale_image,       false, false, 0) ;
    menu_filters_colorscale_container.pack_start(menu_filters_colorscale_label,       false, false, 0) ;
    menu_filters_colorscale_container.pack_start(menu_filters_colorscale_padding,     true, true,   0) ;
    menu_filters_colorscale_container.pack_start(menu_filters_colorscale_accel_label, false, false, 0) ;
    menu_filters_colorscale_button.add(menu_filters_colorscale_container) ;


    menu_filters_mult_colors_container.set_homogeneous(false) ;
    menu_filters_mult_colors_container.pack_start(menu_filters_mult_colors_image,       false, false, 0) ;
    menu_filters_mult_colors_container.pack_start(menu_filters_mult_colors_label,       false, false, 0) ;
    menu_filters_mult_colors_container.pack_start(menu_filters_mult_colors_padding,     true, true,   0) ;
    menu_filters_mult_colors_container.pack_start(menu_filters_mult_colors_accel_label, false, false, 0) ;
    menu_filters_mult_colors_button.add(menu_filters_mult_colors_container) ;

    menu_filters_mult_intensity_container.set_homogeneous(false) ;
    menu_filters_mult_intensity_container.pack_start(menu_filters_mult_intensity_image,       false, false, 0) ;
    menu_filters_mult_intensity_container.pack_start(menu_filters_mult_intensity_label,       false, false, 0) ;
    menu_filters_mult_intensity_container.pack_start(menu_filters_mult_intensity_padding,     true, true,   0) ;
    menu_filters_mult_intensity_container.pack_start(menu_filters_mult_intensity_accel_label, false, false, 0) ;
    menu_filters_mult_intensity_button.add(menu_filters_mult_intensity_container) ;

    menu_filters_set_in_color_tone_container.set_homogeneous(false) ;
    menu_filters_set_in_color_tone_container.pack_start(menu_filters_set_in_color_tone_image,       false, false, 0) ;
    menu_filters_set_in_color_tone_container.pack_start(menu_filters_set_in_color_tone_label,       false, false, 0) ;
    menu_filters_set_in_color_tone_container.pack_start(menu_filters_set_in_color_tone_padding,     true, true,   0) ;
    menu_filters_set_in_color_tone_container.pack_start(menu_filters_set_in_color_tone_accel_label, false, false, 0) ;
    menu_filters_set_in_color_tone_button.add(menu_filters_set_in_color_tone_container) ;


    menu_infos_readme_container.set_homogeneous(false) ;
    menu_infos_readme_container.pack_start(menu_infos_readme_image,       false, false, 0) ;
    menu_infos_readme_container.pack_start(menu_infos_readme_label,       false, false, 0) ;
    menu_infos_readme_container.pack_start(menu_infos_readme_padding,     true, true,   0) ;
    menu_infos_readme_container.pack_start(menu_infos_readme_accel_label, false, false, 0) ;
    menu_infos_readme_button.add(menu_infos_readme_container) ;


    menu_infos_documentation_container.set_homogeneous(false) ;
    menu_infos_documentation_container.pack_start(menu_infos_documentation_image,       false, false, 0) ;
    menu_infos_documentation_container.pack_start(menu_infos_documentation_label,       false, false, 0) ;
    menu_infos_documentation_container.pack_start(menu_infos_documentation_padding,     true, true,   0) ;
    menu_infos_documentation_container.pack_start(menu_infos_documentation_accel_label, false, false, 0) ;
    menu_infos_documentation_button.add(menu_infos_documentation_container) ;


    menu_infos_about_container.set_homogeneous(false) ;
    menu_infos_about_container.pack_start(menu_infos_about_image,       false, false, 0) ;
    menu_infos_about_container.pack_start(menu_infos_about_label,       false, false, 0) ;
    menu_infos_about_container.pack_start(menu_infos_about_padding,     true, true,   0) ;
    menu_infos_about_container.pack_start(menu_infos_about_accel_label, false, false, 0) ;
    menu_infos_about_button.add(menu_infos_about_container) ;







    std::vector<Glib::RefPtr<Gtk::RecentInfo>> recent_files_vector = recent_file_manager->get_items() ;

    vector<string> supported_mimetypes ;


    #ifdef SUPPORT_BMP
    supported_mimetypes.push_back("image/bmp") ;
    #endif

    #ifdef SUPPORT_SUN_RASTER
    supported_mimetypes.push_back("image/x-cmu-raster") ;
    #endif

    #ifdef SUPPORT_PORTABLE_IMAGE_FORMAT
    supported_mimetypes.push_back("image/x-portable-bitmap")  ;
    supported_mimetypes.push_back("image/x-portable-graymap") ;
    supported_mimetypes.push_back("image/x-portable-pixmap")  ;
    #endif

    #ifdef SUPPORT_PNG
    supported_mimetypes.push_back("image/png") ;
    #endif

    #ifdef SUPPORT_JPG
    supported_mimetypes.push_back("image/jpeg") ;
    #endif

    #ifdef SUPPORT_TIF
    supported_mimetypes.push_back("image/tiff") ;
    #endif

    #ifdef SUPPORT_WEBP
    supported_mimetypes.push_back("image/webp") ;
    #endif

                                
    for (auto &val : recent_files_vector) {

      bool is_supported = false ;

      for (auto mval : supported_mimetypes) {

        if (val->get_mime_type() == mval) {
          is_supported = true ;
        }
      }

      if (! is_supported) {
        recent_file_manager->remove_item(val->get_uri()) ;
      }
    }

    menu_files_recent_files.set_show_icons(true) ;


    menu_files_recent_file_button.set_submenu(menu_files_recent_files) ;


    menu_files.append(menu_files_open_file_button) ;
    menu_files.append(menu_files_save_file_button) ;
    menu_files.append(menu_files_separator_01) ;
    menu_files.append(menu_files_recent_file_button) ;
    menu_files.append(menu_files_separator_02) ;
    menu_files.append(menu_files_blend_images_button) ;
    menu_files.append(menu_files_screen_images_button) ;
    menu_files.append(menu_files_darker_images_button) ;
    menu_files.append(menu_files_lighter_images_button) ;
    menu_files.append(menu_files_add_images_button) ;
    menu_files.append(menu_files_add_modulo_images_button) ;
    menu_files.append(menu_files_sub_images_button) ;
    menu_files.append(menu_files_sub_modulo_images_button) ;


    menu_edition.append(menu_edition_undo_button) ;
    menu_edition.append(menu_edition_redo_button) ;

    menu_edition.append(menu_edition_separator_01) ;

    menu_edition.append(menu_edition_rotate_left_button) ;
    menu_edition.append(menu_edition_rotate_right_button) ;

    menu_edition.append(menu_edition_separator_02) ;

    menu_edition.append(menu_edition_mirror_left_to_right_button) ;
    menu_edition.append(menu_edition_mirror_right_to_left_button) ;
    menu_edition.append(menu_edition_mirror_up_to_down_button) ;
    menu_edition.append(menu_edition_mirror_down_to_up_button) ;

    menu_edition.append(menu_edition_separator_03) ;

    menu_edition.append(menu_edition_zoom_plus_button)  ;
    menu_edition.append(menu_edition_zoom_minus_button) ;

    menu_edition.append(menu_edition_separator_04) ;

    menu_edition.append(menu_edition_flip_left_button) ;
    menu_edition.append(menu_edition_flip_right_button) ;
    menu_edition.append(menu_edition_flip_up_button) ;
    menu_edition.append(menu_edition_flip_down_button) ;

    menu_filters_filters_button.set_submenu(menu_filters_filters) ;

    menu_filters_filters_00.set_always_show_image(true) ;
    menu_filters_filters_01.set_always_show_image(true) ;
    menu_filters_filters_02.set_always_show_image(true) ;
    menu_filters_filters_03.set_always_show_image(true) ;
    menu_filters_filters_04.set_always_show_image(true) ;
    menu_filters_filters_05.set_always_show_image(true) ;
    menu_filters_filters_06.set_always_show_image(true) ;
    menu_filters_filters_07.set_always_show_image(true) ;
    menu_filters_filters_08.set_always_show_image(true) ;
    menu_filters_filters_09.set_always_show_image(true) ;
    menu_filters_filters_10.set_always_show_image(true) ;
    menu_filters_filters_11.set_always_show_image(true) ;
    menu_filters_filters_12.set_always_show_image(true) ;
    menu_filters_filters_13.set_always_show_image(true) ;
    menu_filters_filters_14.set_always_show_image(true) ;
    menu_filters_filters_15.set_always_show_image(true) ;
    menu_filters_filters_16.set_always_show_image(true) ;
    menu_filters_filters_17.set_always_show_image(true) ;
    menu_filters_filters_18.set_always_show_image(true) ;
    menu_filters_filters_19.set_always_show_image(true) ;
    menu_filters_filters_20.set_always_show_image(true) ;
    menu_filters_filters_21.set_always_show_image(true) ;
    menu_filters_filters_22.set_always_show_image(true) ;
    menu_filters_filters_23.set_always_show_image(true) ;
    menu_filters_filters_24.set_always_show_image(true) ;
    menu_filters_filters_25.set_always_show_image(true) ;
    menu_filters_filters_26.set_always_show_image(true) ;
    menu_filters_filters_27.set_always_show_image(true) ;
    menu_filters_filters_28.set_always_show_image(true) ;
    menu_filters_filters_29.set_always_show_image(true) ;
    menu_filters_filters_30.set_always_show_image(true) ;
    menu_filters_filters_31.set_always_show_image(true) ;
    menu_filters_filters_32.set_always_show_image(true) ;
    menu_filters_filters_33.set_always_show_image(true) ;
    menu_filters_filters_34.set_always_show_image(true) ;
    menu_filters_filters_35.set_always_show_image(true) ;
    menu_filters_filters_36.set_always_show_image(true) ;
    menu_filters_filters_37.set_always_show_image(true) ;
    menu_filters_filters_38.set_always_show_image(true) ;

    menu_filters_filters_00.set_name( "0") ;
    menu_filters_filters_01.set_name( "1") ;
    menu_filters_filters_02.set_name( "2") ;
    menu_filters_filters_03.set_name( "3") ;
    menu_filters_filters_04.set_name( "4") ;
    menu_filters_filters_05.set_name( "5") ;
    menu_filters_filters_06.set_name( "6") ;
    menu_filters_filters_07.set_name( "7") ;
    menu_filters_filters_08.set_name( "8") ;
    menu_filters_filters_09.set_name( "9") ;
    menu_filters_filters_10.set_name( "10") ;
    menu_filters_filters_11.set_name( "11") ;
    menu_filters_filters_12.set_name( "12") ;
    menu_filters_filters_13.set_name( "13") ;
    menu_filters_filters_14.set_name( "14") ;
    menu_filters_filters_15.set_name( "15") ;
    menu_filters_filters_16.set_name( "16") ;
    menu_filters_filters_17.set_name( "17") ;
    menu_filters_filters_18.set_name( "18") ;
    menu_filters_filters_19.set_name( "19") ;
    menu_filters_filters_20.set_name( "20") ;
    menu_filters_filters_21.set_name( "21") ;
    menu_filters_filters_22.set_name( "22") ;
    menu_filters_filters_23.set_name( "23") ;
    menu_filters_filters_24.set_name( "24") ;
    menu_filters_filters_25.set_name( "25") ;
    menu_filters_filters_26.set_name( "26") ;
    menu_filters_filters_27.set_name( "27") ;
    menu_filters_filters_28.set_name( "28") ;
    menu_filters_filters_29.set_name( "29") ;
    menu_filters_filters_30.set_name( "30") ;
    menu_filters_filters_31.set_name( "31") ;
    menu_filters_filters_32.set_name( "32") ;
    menu_filters_filters_33.set_name( "33") ;
    menu_filters_filters_34.set_name( "34") ;
    menu_filters_filters_35.set_name( "35") ;
    menu_filters_filters_36.set_name( "36") ;
    menu_filters_filters_37.set_name( "37") ;
    menu_filters_filters_38.set_name( "38") ;

    menu_filters_filters.append(menu_filters_filters_00) ;
    menu_filters_filters.append(menu_filters_filters_01) ;
    menu_filters_filters.append(menu_filters_filters_02) ;
    menu_filters_filters.append(menu_filters_filters_03) ;
    menu_filters_filters.append(menu_filters_filters_04) ;
    menu_filters_filters.append(menu_filters_filters_05) ;
    menu_filters_filters.append(menu_filters_filters_06) ;
    menu_filters_filters.append(menu_filters_filters_07) ;
    menu_filters_filters.append(menu_filters_filters_08) ;
    menu_filters_filters.append(menu_filters_filters_09) ;
    menu_filters_filters.append(menu_filters_filters_10) ;
    menu_filters_filters.append(menu_filters_filters_11) ;
    menu_filters_filters.append(menu_filters_filters_12) ;
    menu_filters_filters.append(menu_filters_filters_13) ;
    menu_filters_filters.append(menu_filters_filters_14) ;
    menu_filters_filters.append(menu_filters_filters_15) ;
    menu_filters_filters.append(menu_filters_filters_16) ;
    menu_filters_filters.append(menu_filters_filters_17) ;
    menu_filters_filters.append(menu_filters_filters_18) ;
    menu_filters_filters.append(menu_filters_filters_19) ;
    menu_filters_filters.append(menu_filters_filters_20) ;
    menu_filters_filters.append(menu_filters_filters_21) ;
    menu_filters_filters.append(menu_filters_filters_22) ;
    menu_filters_filters.append(menu_filters_filters_23) ;
    menu_filters_filters.append(menu_filters_filters_24) ;
    menu_filters_filters.append(menu_filters_filters_25) ;
    menu_filters_filters.append(menu_filters_filters_26) ;
    menu_filters_filters.append(menu_filters_filters_27) ;
    menu_filters_filters.append(menu_filters_filters_28) ;
    menu_filters_filters.append(menu_filters_filters_29) ;
    menu_filters_filters.append(menu_filters_filters_30) ;
    menu_filters_filters.append(menu_filters_filters_31) ;
    menu_filters_filters.append(menu_filters_filters_32) ;
    menu_filters_filters.append(menu_filters_filters_33) ;
    menu_filters_filters.append(menu_filters_filters_34) ;
    menu_filters_filters.append(menu_filters_filters_35) ;
    menu_filters_filters.append(menu_filters_filters_36) ;
    menu_filters_filters.append(menu_filters_filters_37) ;
    menu_filters_filters.append(menu_filters_filters_38) ;

    menu_filters_grayscale_button.set_submenu(menu_filters_grayscale) ;

    menu_filters_grayscale_00.set_always_show_image(true) ;
    menu_filters_grayscale_01.set_always_show_image(true) ;
    menu_filters_grayscale_02.set_always_show_image(true) ;
    menu_filters_grayscale_03.set_always_show_image(true) ;
    menu_filters_grayscale_04.set_always_show_image(true) ;
    menu_filters_grayscale_05.set_always_show_image(true) ;

    menu_filters_grayscale_00.set_name( "0") ;
    menu_filters_grayscale_01.set_name( "1") ;
    menu_filters_grayscale_02.set_name( "2") ;
    menu_filters_grayscale_03.set_name( "3") ;
    menu_filters_grayscale_04.set_name( "4") ;
    menu_filters_grayscale_05.set_name( "5") ;

    menu_filters_grayscale.append(menu_filters_grayscale_00) ;
    menu_filters_grayscale.append(menu_filters_grayscale_01) ;
    menu_filters_grayscale.append(menu_filters_grayscale_02) ;
    menu_filters_grayscale.append(menu_filters_grayscale_03) ;
    menu_filters_grayscale.append(menu_filters_grayscale_04) ;
    menu_filters_grayscale.append(menu_filters_grayscale_05) ;


    menu_filters_colorscale_button.set_submenu(menu_filters_colorscale) ;

    menu_filters_colorscale_00.set_always_show_image(true) ;
    menu_filters_colorscale_01.set_always_show_image(true) ;
    menu_filters_colorscale_02.set_always_show_image(true) ;
    menu_filters_colorscale_03.set_always_show_image(true) ;
    menu_filters_colorscale_04.set_always_show_image(true) ;
    menu_filters_colorscale_05.set_always_show_image(true) ;
    menu_filters_colorscale_06.set_always_show_image(true) ;
    menu_filters_colorscale_07.set_always_show_image(true) ;
    menu_filters_colorscale_08.set_always_show_image(true) ;
    menu_filters_colorscale_09.set_always_show_image(true) ;
    menu_filters_colorscale_10.set_always_show_image(true) ;
    menu_filters_colorscale_11.set_always_show_image(true) ;
    menu_filters_colorscale_12.set_always_show_image(true) ;
    menu_filters_colorscale_13.set_always_show_image(true) ;
    menu_filters_colorscale_14.set_always_show_image(true) ;
    menu_filters_colorscale_15.set_always_show_image(true) ;
    menu_filters_colorscale_16.set_always_show_image(true) ;
    menu_filters_colorscale_17.set_always_show_image(true) ;
    menu_filters_colorscale_18.set_always_show_image(true) ;
    menu_filters_colorscale_19.set_always_show_image(true) ;
    menu_filters_colorscale_20.set_always_show_image(true) ;
    menu_filters_colorscale_21.set_always_show_image(true) ;
    menu_filters_colorscale_22.set_always_show_image(true) ;
    menu_filters_colorscale_23.set_always_show_image(true) ;
    menu_filters_colorscale_24.set_always_show_image(true) ;
    menu_filters_colorscale_25.set_always_show_image(true) ;
    menu_filters_colorscale_26.set_always_show_image(true) ;
    menu_filters_colorscale_27.set_always_show_image(true) ;
    menu_filters_colorscale_28.set_always_show_image(true) ;
    menu_filters_colorscale_29.set_always_show_image(true) ;
    menu_filters_colorscale_30.set_always_show_image(true) ;
    menu_filters_colorscale_31.set_always_show_image(true) ;
    menu_filters_colorscale_32.set_always_show_image(true) ;

    menu_filters_colorscale_00.set_name( "0") ;
    menu_filters_colorscale_01.set_name( "1") ;
    menu_filters_colorscale_02.set_name( "2") ;
    menu_filters_colorscale_03.set_name( "3") ;
    menu_filters_colorscale_04.set_name( "4") ;
    menu_filters_colorscale_05.set_name( "5") ;
    menu_filters_colorscale_06.set_name( "6") ;
    menu_filters_colorscale_07.set_name( "7") ;
    menu_filters_colorscale_08.set_name( "8") ;
    menu_filters_colorscale_09.set_name( "9") ;
    menu_filters_colorscale_10.set_name( "10") ;
    menu_filters_colorscale_11.set_name( "11") ;
    menu_filters_colorscale_12.set_name( "12") ;
    menu_filters_colorscale_13.set_name( "13") ;
    menu_filters_colorscale_14.set_name( "14") ;
    menu_filters_colorscale_15.set_name( "15") ;
    menu_filters_colorscale_16.set_name( "16") ;
    menu_filters_colorscale_17.set_name( "17") ;
    menu_filters_colorscale_18.set_name( "18") ;
    menu_filters_colorscale_19.set_name( "19") ;
    menu_filters_colorscale_20.set_name( "20") ;
    menu_filters_colorscale_21.set_name( "21") ;
    menu_filters_colorscale_22.set_name( "22") ;
    menu_filters_colorscale_23.set_name( "23") ;
    menu_filters_colorscale_24.set_name( "24") ;
    menu_filters_colorscale_25.set_name( "25") ;
    menu_filters_colorscale_26.set_name( "26") ;
    menu_filters_colorscale_27.set_name( "27") ;
    menu_filters_colorscale_28.set_name( "28") ;
    menu_filters_colorscale_29.set_name( "29") ;
    menu_filters_colorscale_30.set_name( "30") ;
    menu_filters_colorscale_31.set_name( "31") ;
    menu_filters_colorscale_32.set_name( "32") ;

    menu_filters_colorscale.append(menu_filters_colorscale_00) ;
    menu_filters_colorscale.append(menu_filters_colorscale_01) ;
    menu_filters_colorscale.append(menu_filters_colorscale_02) ;
    menu_filters_colorscale.append(menu_filters_colorscale_03) ;
    menu_filters_colorscale.append(menu_filters_colorscale_04) ;
    menu_filters_colorscale.append(menu_filters_colorscale_05) ;
    menu_filters_colorscale.append(menu_filters_colorscale_06) ;
    menu_filters_colorscale.append(menu_filters_colorscale_07) ;
    menu_filters_colorscale.append(menu_filters_colorscale_08) ;
    menu_filters_colorscale.append(menu_filters_colorscale_09) ;
    menu_filters_colorscale.append(menu_filters_colorscale_10) ;
    menu_filters_colorscale.append(menu_filters_colorscale_11) ;
    menu_filters_colorscale.append(menu_filters_colorscale_12) ;
    menu_filters_colorscale.append(menu_filters_colorscale_13) ;
    menu_filters_colorscale.append(menu_filters_colorscale_14) ;
    menu_filters_colorscale.append(menu_filters_colorscale_15) ;
    menu_filters_colorscale.append(menu_filters_colorscale_16) ;
    menu_filters_colorscale.append(menu_filters_colorscale_17) ;
    menu_filters_colorscale.append(menu_filters_colorscale_18) ;
    menu_filters_colorscale.append(menu_filters_colorscale_19) ;
    menu_filters_colorscale.append(menu_filters_colorscale_20) ;
    menu_filters_colorscale.append(menu_filters_colorscale_21) ;
    menu_filters_colorscale.append(menu_filters_colorscale_22) ;
    menu_filters_colorscale.append(menu_filters_colorscale_23) ;
    menu_filters_colorscale.append(menu_filters_colorscale_24) ;
    menu_filters_colorscale.append(menu_filters_colorscale_25) ;
    menu_filters_colorscale.append(menu_filters_colorscale_26) ;
    menu_filters_colorscale.append(menu_filters_colorscale_27) ;
    menu_filters_colorscale.append(menu_filters_colorscale_28) ;
    menu_filters_colorscale.append(menu_filters_colorscale_29) ;
    menu_filters_colorscale.append(menu_filters_colorscale_30) ;
    menu_filters_colorscale.append(menu_filters_colorscale_31) ;
    menu_filters_colorscale.append(menu_filters_colorscale_32) ;


    menu_kernel_filters.append(menu_filters_kernel_sharpen_button) ;
    menu_kernel_filters.append(menu_filters_kernel_find_edges_button) ;
    menu_kernel_filters.append(menu_filters_kernel_emboss_button) ;
    menu_kernel_filters.append(menu_filters_kernel_mean_button) ;
    menu_kernel_filters.append(menu_filters_kernel_gaussian_button) ;
    menu_kernel_filters.append(menu_filters_kernel_kirsch_button) ;

    menu_filters_kernel_filters_button.set_submenu(menu_kernel_filters) ;


    menu_filters_photo.append(menu_filters_photo_pencil_sketch_button) ;
    menu_filters_photo.append(menu_filters_photo_stylisation_button) ;
    menu_filters_photo.append(menu_filters_photo_detail_enhance_button) ;
    menu_filters_photo.append(menu_filters_photo_edges_preserving_button) ;
    menu_filters_photo.append(menu_filters_photo_denoising_button) ;

    menu_filters_photo_filters_button.set_submenu(menu_filters_photo) ;


    menu_filters.append(menu_filters_filters_button)              ;
    menu_filters.append(menu_filters_kernel_filters_button)       ;
    menu_filters.append(menu_filters_photo_filters_button)        ;
    menu_filters.append(menu_filters_morphological_button)        ;
    menu_filters.append(menu_filters_canny_button)                ;
    menu_filters.append(menu_filters_color_contours_button)       ;
    menu_filters.append(menu_filters_separator_01)                ;
    menu_filters.append(menu_filters_grayscale_button)            ;
    menu_filters.append(menu_filters_separator_02)                ;
    menu_filters.append(menu_filters_colorscale_button)           ;
    menu_filters.append(menu_filters_mult_colors_button)          ;
    menu_filters.append(menu_filters_mult_intensity_button)       ;
    menu_filters.append(menu_filters_set_in_color_tone_button)    ;

    menu_filters_filters_button.set_submenu(menu_filters_filters) ;


    menu_files_button.set_submenu(menu_files)     ;
    menu_edition_button.set_submenu(menu_edition) ;
    menu_filters_button.set_submenu(menu_filters) ;
    menu_infos_button.set_submenu(menu_infos)     ;
   
    menu_infos.append(menu_infos_readme_button)        ;
    menu_infos.append(menu_infos_documentation_button) ;
    menu_infos.append(menu_infos_about_button)         ;
   
    menu_bar.append(menu_files_button)   ;
    menu_bar.append(menu_edition_button) ;
    menu_bar.append(menu_filters_button) ;
    menu_bar.append(menu_infos_button)   ;


    button_open.set_image(image_open) ;
    button_save.set_image(image_save) ;

    button_open.set_always_show_image(true) ;
    button_save.set_always_show_image(true) ;

    button_undo.set_image(image_undo) ;
    button_redo.set_image(image_redo) ;

    button_undo.set_always_show_image(true) ;
    button_redo.set_always_show_image(true) ;

    button_rot_left.set_image(image_rot_left)   ;
    button_rot_right.set_image(image_rot_right) ;

    button_rot_left.set_always_show_image(true)  ;
    button_rot_right.set_always_show_image(true) ;



    button_mirror_left.set_image(image_mirror_left)   ;
    button_mirror_right.set_image(image_mirror_right) ;
    button_mirror_bottom.set_image(image_mirror_bottom) ;
    button_mirror_top.set_image(image_mirror_top)   ;

    button_mirror_left.set_always_show_image(true)  ;
    button_mirror_right.set_always_show_image(true) ;
    button_mirror_bottom.set_always_show_image(true) ;
    button_mirror_top.set_always_show_image(true)  ;

    button_zoom_plus.set_image(image_zoom_plus) ;
    button_zoom_minus.set_image(image_zoom_minus) ;
    button_zoom_pointer.set_image(image_zoom_pointer) ;

    button_zoom_plus.set_always_show_image(true) ;
    button_zoom_minus.set_always_show_image(true) ;
    button_zoom_pointer.set_always_show_image(true) ;


    button_flip_left.set_image(image_flip_left)   ;
    button_flip_right.set_image(image_flip_right) ;
    button_flip_up.set_image(image_flip_up)       ;
    button_flip_down.set_image(image_flip_down)   ;

    button_flip_left.set_always_show_image(true)  ;
    button_flip_right.set_always_show_image(true) ;
    button_flip_up.set_always_show_image(true)    ;
    button_flip_down.set_always_show_image(true)  ;


    buttonbox_files.set_layout(Gtk::BUTTONBOX_CENTER) ;
    buttonbox_undo_redo.set_layout(Gtk::BUTTONBOX_CENTER) ;
    buttonbox_rot.set_layout(Gtk::BUTTONBOX_CENTER) ;
    buttonbox_zoom.set_layout(Gtk::BUTTONBOX_CENTER) ;
    buttonbox_flip.set_layout(Gtk::BUTTONBOX_CENTER) ;



    buttonbox_files.set_spacing(1) ;

    buttonbox_undo_redo.set_spacing(1)  ;

    buttonbox_rot.set_spacing(1)  ;

    buttonbox_mirror.set_spacing(1)  ;

    buttonbox_zoom.set_spacing(1) ;

    buttonbox_flip.set_spacing(1)  ;


    button_open.set_tooltip_text("Open an image file to edit.") ;
    button_save.set_tooltip_text("Save current image as image file.") ;

    button_undo.set_tooltip_text("Undo last action.\nYou can return to your previous image changements.\n\n! Attention: if you perform an action on the image you will be unable to redo.") ;
    button_redo.set_tooltip_text("Redo last undo.\nYou can redo if you have undo.") ;

    button_rot_left.set_tooltip_text("Rotate the image counter-clockwise at 90°.") ;
    button_rot_right.set_tooltip_text("Rotate the image clockwise at 90°.") ;

    button_mirror_left.set_tooltip_text("Mirroring horizontally left.\nMirror the image horizontally so that you duplicate the left half-side from your image\non the right half-side, mirrorwise.") ;
    button_mirror_right.set_tooltip_text("Mirroring horizontally right.\nMirror the image horizontally so that you duplicate the right half-side from your image\non the left half-side, mirrorwise.") ;

    button_mirror_top.set_tooltip_text("Mirroring vertically top.\nMirror the image vertically so that you duplicate the top half from your image\non the bottom half-side, mirrorwise.") ;
    button_mirror_bottom.set_tooltip_text("Mirroring vertically bottom.\nMirror the image vertically so that you duplicate the bottom half side from your image\non the top half-side, mirrorwise.") ;

    button_zoom_label.set_tooltip_text("Reset default middle zoom center point.") ;
    button_zoom_plus.set_tooltip_text("Zoom inside the image\nYou can select where to zoom in which the pointer button.") ;
    button_zoom_minus.set_tooltip_text("Zoom back\nOnly available if you you have zoom in.") ;
    button_zoom_pointer.set_tooltip_text("Select the point of the image on which zoom in.") ;



    button_flip_left.set_tooltip_text("Flip your image horizontally to the left.\nReturn the image.") ;
    button_flip_right.set_tooltip_text("Flip your image horizontally to the right.\nReturn the image.") ;
    button_flip_up.set_tooltip_text("Flip your image vertically to the top.\nReturn the image.") ;
    button_flip_down.set_tooltip_text("Flip your image vertically to the bottom.\nReturn the image.") ;


    buttonbox_files.pack_start(button_open, false, false, 0) ;
    buttonbox_files.pack_start(button_save, false, false, 0) ;





    buttonbox_undo_redo.pack_start(button_undo, false, false, 0) ;
    buttonbox_undo_redo.pack_start(button_redo, false, false, 0) ;

    buttonbox_rot.pack_start(button_rot_label,  false, false, 0) ;
    buttonbox_rot.pack_start(button_rot_left,   false, false, 0) ;
    buttonbox_rot.pack_start(button_rot_right,  false, false, 0) ;


    buttonbox_mirror.pack_start(button_mirror_label,  false, false, 0) ;
    buttonbox_mirror.pack_start(button_mirror_left,   false, false, 0) ;
    buttonbox_mirror.pack_start(button_mirror_right,  false, false, 0) ;
    buttonbox_mirror.pack_start(button_mirror_bottom, false, false, 0) ;
    buttonbox_mirror.pack_start(button_mirror_top,    false, false, 0) ;



    buttonbox_zoom.pack_start(button_zoom_label,           false, false, 0) ;
    buttonbox_zoom.pack_start(button_zoom_plus,            false, false, 0) ;
    buttonbox_zoom.pack_start(button_zoom_minus,           false, false, 0) ;
    buttonbox_zoom.pack_start(button_zoom_pointer,         false, false, 0) ;


    buttonbox_flip.pack_start(button_flip_label,  false, false, 0) ;
    buttonbox_flip.pack_start(button_flip_left,   false, false, 0) ;
    buttonbox_flip.pack_start(button_flip_right,  false, false, 0) ;
    buttonbox_flip.pack_start(button_flip_up,     false, false, 0) ;
    buttonbox_flip.pack_start(button_flip_down,   false, false, 0) ;


    buttonbar.pack_start(padding_buttonbox_1, true,  true,  0) ;
    buttonbar.pack_start(buttonbox_files,     false, false, 0) ;
    buttonbar.pack_start(padding_buttonbox_2, true,  true,  0) ;
    buttonbar.pack_start(buttonbox_undo_redo, false, false, 0) ;
    buttonbar.pack_start(padding_buttonbox_3, true,  true,  0) ;
    buttonbar.pack_start(buttonbox_rot,       false, false, 0) ;
    buttonbar.pack_start(padding_buttonbox_4, true,  true,  0) ;
    buttonbar.pack_start(buttonbox_mirror,    false, false, 0) ;
    buttonbar.pack_start(padding_buttonbox_5, true,  true,  0) ;
    buttonbar.pack_start(buttonbox_zoom,      false, false, 0) ;
    buttonbar.pack_start(padding_buttonbox_6, true,  true,  0) ;
    buttonbar.pack_start(buttonbox_flip,      false, false, 0) ;
    buttonbar.pack_start(padding_buttonbox_7, true,  true,  0) ;



    button_rot_label.set_size_request(-1, 33) ;
    button_mirror_label.set_size_request(-1, 33) ;
    button_zoom_label.set_size_request(-1, 33) ;
    button_flip_label.set_size_request(-1, 33) ;

    buttonbox_undo_redo.set_child_non_homogeneous(button_undo, true)   ;
    buttonbox_undo_redo.set_child_non_homogeneous(button_redo, true)   ;

    buttonbox_rot.set_child_non_homogeneous(button_rot_label, true)    ;
    buttonbox_rot.set_child_non_homogeneous(button_rot_left,  true)    ;
    buttonbox_rot.set_child_non_homogeneous(button_rot_right, true)    ;


    buttonbox_mirror.set_child_non_homogeneous(button_mirror_label, true)    ;
    buttonbox_mirror.set_child_non_homogeneous(button_mirror_left,  true)    ;
    buttonbox_mirror.set_child_non_homogeneous(button_mirror_right, true)    ;
    buttonbox_mirror.set_child_non_homogeneous(button_mirror_bottom,  true)    ;
    buttonbox_mirror.set_child_non_homogeneous(button_mirror_top, true)    ;

    buttonbox_zoom.set_child_non_homogeneous(button_zoom_label,     true)    ;
    buttonbox_zoom.set_child_non_homogeneous(button_zoom_plus,      true)    ;
    buttonbox_zoom.set_child_non_homogeneous(button_zoom_minus,     true)    ;
    buttonbox_zoom.set_child_non_homogeneous(button_zoom_pointer,   true)    ;

    buttonbox_flip.set_child_non_homogeneous(button_flip_label, true)  ;

    buttonbox_flip.set_child_non_homogeneous(button_flip_left,  true)  ;
    buttonbox_flip.set_child_non_homogeneous(button_flip_right, true)  ;
    buttonbox_flip.set_child_non_homogeneous(button_flip_up,    true)  ;
    buttonbox_flip.set_child_non_homogeneous(button_flip_down,  true)  ;


    buttonbar.set_border_width(4) ;

    buttonbar.set_margin_top(2) ;
    buttonbar.set_margin_bottom(2) ;
    buttonbar.set_margin_left(2) ;
    buttonbar.set_margin_right(2) ;


    frame_buttonbox_top.add(buttonbar) ;



    combo_filters.insert(0,  "Pencil Sketch")                    ;
    combo_filters.insert(1,  "Stylisation")                      ;
    combo_filters.insert(2,  "Detail Enhance")                   ;
    combo_filters.insert(3,  "Edge Preserving")                  ;
    combo_filters.insert(4,  "Stroke Edges")                     ;
    combo_filters.insert(5,  "Invert Intensity")                 ;
    combo_filters.insert(6,  "Light Intesity")                   ;
    combo_filters.insert(7,  "Recolor RC  (Red-Cyan)")           ;
    combo_filters.insert(8,  "Recolor RGV (Red-Green-Value)")    ;
    combo_filters.insert(9,  "Recolor CMV (Cyan-Magenta-Value)") ;
    combo_filters.insert(10, "Extrema Maximal")                  ;
    combo_filters.insert(11, "Extrema Minimal")                  ;
    combo_filters.insert(12, "Sharpen")                          ;
    combo_filters.insert(13, "Sharpen More")                     ;
    combo_filters.insert(14, "Find Edges")                       ;
    combo_filters.insert(15, "Mean Blur")                        ;
    combo_filters.insert(16, "Mean Blur More")                   ;
    combo_filters.insert(17, "Blur")                             ;
    combo_filters.insert(18, "Blur Median")                      ;
    combo_filters.insert(19, "Blur Gaussian")                    ;
    combo_filters.insert(20, "Denoising")                        ;
    combo_filters.insert(21, "Erode")                            ;
    combo_filters.insert(22, "Dilate")                           ;
    combo_filters.insert(23, "Wave Horizontally")                ;
    combo_filters.insert(24, "Wave Vertically")                  ;
    combo_filters.insert(25, "Wave Twice")                       ;
    combo_filters.insert(26, "Contours Sobel White")             ;
    combo_filters.insert(27, "Contours Sobel Black")             ;
    combo_filters.insert(28, "Contours Sobel Emboss")            ;
    combo_filters.insert(29, "Emboss Sobel")                     ;
    combo_filters.insert(30, "Emboss Laplacian")                 ;
    combo_filters.insert(31, "Binary White OTSU")                ;
    combo_filters.insert(32, "Binary White TRIANGLE")            ;
    combo_filters.insert(33, "Binary White AVERAGE")             ;
    combo_filters.insert(34, "Binary Black OTSU")                ;
    combo_filters.insert(35, "Binary Black TRIANGLE")            ;
    combo_filters.insert(36, "Binary Black AVERAGE")             ;
    combo_filters.insert(37, "Binary Contours White")            ;
    combo_filters.insert(38, "Binary Contours Black")            ;


    combo_filters.set_active(0) ;


    entry_combo_filters = combo_filters.Gtk::ComboBox::get_entry() ;

    entry_combo_filters->set_tooltip_text(combo_filters_current_tooltip.at(0)) ;

    Glib::PropertyProxy<bool> entry_combo_filters_editable = entry_combo_filters->property_editable() ;

    entry_combo_filters_editable.set_value(false) ;

    button_filters.set_tooltip_text("Apply a filter.\naccording to the choice of the filter.") ;

    combo_grayscale.insert(0, "Gray Scaling Average") ;
    combo_grayscale.insert(1, "Gray Scaling Maximal") ;
    combo_grayscale.insert(2, "Gray Scaling Minimal") ;
    combo_grayscale.insert(3, "Gray Scaling Red    ") ;
    combo_grayscale.insert(4, "Gray Scaling Green  ") ;
    combo_grayscale.insert(5, "Gray Scaling Blue   ") ;

    combo_grayscale.set_active(0)         ;

    entry_combo_grayscale = combo_grayscale.Gtk::ComboBox::get_entry() ;

    entry_combo_grayscale->set_tooltip_text(combo_grayscale_current_tooltip.at(0)) ;

    Glib::PropertyProxy<bool> entry_combo_grayscale_editable = entry_combo_grayscale->property_editable() ;

    entry_combo_grayscale_editable.set_value(false) ;

    button_grayscale.set_tooltip_text("Apply a gray scaling filter: setting the image enterely in gray tone,\naccording to the choosen base for the gray scale computing.") ;

    combo_colorscale.insert(0,  "Red Scaling Average") ;
    combo_colorscale.insert(1,  "Red Scaling Maximal") ;
    combo_colorscale.insert(2,  "Red Scaling Minimal") ;
    combo_colorscale.insert(3,  "Red Scaling Green  ") ;
    combo_colorscale.insert(4,  "Red Scaling Blue   ") ;


    combo_colorscale.insert(5,  "Green Scaling Average") ;
    combo_colorscale.insert(6,  "Green Scaling Maximal") ;
    combo_colorscale.insert(7,  "Green Scaling Minimal") ;
    combo_colorscale.insert(8,  "Green Scaling Red    ") ;
    combo_colorscale.insert(9,  "Green Scaling Blue   ") ;


    combo_colorscale.insert(10, "Blue Scaling Average") ;
    combo_colorscale.insert(11, "Blue Scaling Maximal") ;
    combo_colorscale.insert(12, "Blue Scaling Minimal") ;
    combo_colorscale.insert(13, "Blue Scaling Red    ") ;
    combo_colorscale.insert(14, "Blue Scaling Green  ") ;

    combo_colorscale.insert(15, "Yellow Scaling Average") ;
    combo_colorscale.insert(16, "Yellow Scaling Maximal") ;
    combo_colorscale.insert(17, "Yellow Scaling Minimal") ;
    combo_colorscale.insert(18, "Yellow Scaling Red    ") ;
    combo_colorscale.insert(19, "Yellow Scaling Green  ") ;
    combo_colorscale.insert(20, "Yellow Scaling Blue   ") ;

    combo_colorscale.insert(21, "Pink Scaling Average") ;
    combo_colorscale.insert(22, "Pink Scaling Maximal") ;
    combo_colorscale.insert(23, "Pink Scaling Minimal") ;
    combo_colorscale.insert(24, "Pink Scaling Red    ") ;
    combo_colorscale.insert(25, "Pink Scaling Green  ") ;
    combo_colorscale.insert(26, "Pink Scaling Blue   ") ;

    combo_colorscale.insert(27, "Turquoise Scaling Average") ;
    combo_colorscale.insert(28, "Turquoise Scaling Maximal") ;
    combo_colorscale.insert(29, "Turquoise Scaling Minimal") ;
    combo_colorscale.insert(30, "Turquoise Scaling Red    ") ;
    combo_colorscale.insert(31, "Turquoise Scaling Green  ") ;
    combo_colorscale.insert(32, "Turquoise Scaling Blue   ") ;

    combo_colorscale.set_active(0)         ;


    entry_combo_colorscale = combo_colorscale.Gtk::ComboBox::get_entry() ;

    entry_combo_colorscale->set_tooltip_text(combo_colorscale_current_tooltip.at(0)) ;

    Glib::PropertyProxy<bool> entry_combo_colorscale_editable = entry_combo_colorscale->property_editable() ;

    entry_combo_colorscale_editable.set_value(false) ;

    button_grayscale.set_tooltip_text("Apply a color scaling filter: setting the image enterely in the wanted color tone (red, green, blue, yellow, pink or turquoise),\naccording to the choosen base for the color scale computing.") ;




    frame_lightness.set_tooltip_text("You can change the main lightness of your image, by setting the value you want.\nConfer the joined documentation for further informations about the lightness.") ;
    frame_hue.set_tooltip_text("You can change the main hue of your image, by setting the value you want.\nConfer the joined documentation for further informations about the hue.") ;
    frame_saturation.set_tooltip_text("You can change the main saturation of your image, by setting the value you want.\nConfer the joined documentation for further informations about the saturation.") ;
    frame_brightness.set_tooltip_text("You can change the main brightness of your image, by setting the value you want.\nConfer the joined documentation for further informations about the brightness.") ;

    frame_lightness.set_margin_left(2) ;
    frame_lightness.set_margin_right(2) ;
    frame_hue.set_margin_left(2) ;
    frame_hue.set_margin_right(2) ;
    frame_saturation.set_margin_left(2) ;
    frame_saturation.set_margin_right(2) ;
    frame_brightness.set_margin_left(2) ;
    frame_brightness.set_margin_right(2) ;

    scale_lightness.set_digits(0) ;
    scale_hue.set_digits(0) ;
    scale_saturation.set_digits(0) ;
    scale_brightness.set_digits(0) ;


    scale_lightness.set_draw_value(true) ;
    scale_hue.set_draw_value(true) ;
    scale_saturation.set_draw_value(true) ;
    scale_brightness.set_draw_value(true) ;


    scale_lightness.set_has_origin(true) ;
    scale_hue.set_has_origin(true) ;
    scale_saturation.set_has_origin(true) ;
    scale_brightness.set_has_origin(true) ;


    scale_lightness.set_upper_stepper_sensitivity(Gtk::SENSITIVITY_ON) ;
    scale_hue.set_upper_stepper_sensitivity(Gtk::SENSITIVITY_ON) ;
    scale_saturation.set_upper_stepper_sensitivity(Gtk::SENSITIVITY_ON) ;
    scale_brightness.set_upper_stepper_sensitivity(Gtk::SENSITIVITY_ON) ;


    scale_lightness.set_lower_stepper_sensitivity(Gtk::SENSITIVITY_ON) ;
    scale_hue.set_lower_stepper_sensitivity(Gtk::SENSITIVITY_ON) ;
    scale_saturation.set_lower_stepper_sensitivity(Gtk::SENSITIVITY_ON) ;
    scale_brightness.set_lower_stepper_sensitivity(Gtk::SENSITIVITY_ON) ;


    scale_lightness.set_adjustment( scale_lightness.get_adjustment() )     ;
    scale_hue.set_adjustment( scale_hue.get_adjustment() )     ;
    scale_saturation.set_adjustment( scale_saturation.get_adjustment() )     ;
    scale_brightness.set_adjustment( scale_brightness.get_adjustment() )     ;


    scale_lightness.set_range(-255.0, 255.0)      ;
    scale_hue.set_range(1.0, 160.0)            ;
    scale_saturation.set_range(-255.0, 255.0)     ;
    scale_brightness.set_range(0.0, 255.0)      ;


    scale_lightness.set_value(0.0)      ;
    scale_hue.set_value(80.0)            ;
    scale_saturation.set_value(0.0)     ;
    scale_brightness.set_value(127.5)      ;


    scale_lightness.set_increments(1.0, 10.0)    ;
    scale_hue.set_increments(1.0, 10.0)          ;
    scale_saturation.set_increments(1.0, 10.0)   ;
    scale_brightness.set_increments(1.0, 10.0)    ;


    scale_lightness.add_mark(0.0, Gtk::POS_RIGHT, "")      ;
    scale_hue.add_mark(80.0, Gtk::POS_RIGHT, "")            ;
    scale_saturation.add_mark(0.0, Gtk::POS_RIGHT, "")     ;
    scale_brightness.add_mark(127.5, Gtk::POS_RIGHT, "")      ;


    scale_lightness.set_margin_left(2)         ;
    scale_lightness.set_margin_right(2)        ;

    scale_hue.set_margin_left(2)               ;
    scale_hue.set_margin_right(2)              ;

    scale_saturation.set_margin_left(2)        ;
    scale_saturation.set_margin_right(2)       ;

    scale_brightness.set_margin_left(2)        ;
    scale_brightness.set_margin_right(2)       ;


    scale_lightness.set_margin_top(2)          ;
    scale_lightness.set_margin_bottom(2)       ;

    scale_hue.set_margin_top(2)                ;
    scale_hue.set_margin_bottom(2)             ;

    scale_saturation.set_margin_top(2)         ;
    scale_saturation.set_margin_bottom(2)      ;

    scale_brightness.set_margin_top(2)         ;
    scale_brightness.set_margin_bottom(2)      ;



    scale_lightness.set_inverted(true)      ;
    scale_hue.set_inverted(true)            ;
    scale_saturation.set_inverted(true)     ;
    scale_brightness.set_inverted(true)     ;


    frame_lightness.add(scale_lightness)   ;
    frame_hue.add(scale_hue)               ;
    frame_saturation.add(scale_saturation) ;
    frame_brightness.add(scale_brightness)  ;


    frame_lightness.set_label_align(  0.5,  1.0)  ;
    frame_hue.set_label_align(        0.5,  1.0)  ;
    frame_saturation.set_label_align( 0.5,  1.0)  ;
    frame_brightness.set_label_align( 0.5,  1.0)  ;


    buttonbox_switcher.set_homogeneous(true) ;
    buttonbox_switcher.set_spacing(6) ;



    button_intensity.set_border_width(4) ;
    button_hsbl.set_border_width(4)      ;

    button_intensity.set_mode(false) ;
    button_hsbl.set_mode(false)      ;

    button_hsbl.join_group(button_intensity)  ;

    button_intensity.set_active(true) ;
    button_hsbl.set_active(false)     ;


    button_intensity.set_image(image_switcher_on) ;
    button_intensity.set_always_show_image(true)  ;

    button_hsbl.set_image(image_switcher_off)     ;
    button_hsbl.set_always_show_image(true)       ;


    buttonbox_switcher.pack_start(button_intensity, true, true, 0 ) ;
    buttonbox_switcher.pack_start(button_hsbl,      true, true, 0 ) ;


    frame_switcher.add(buttonbox_switcher) ;


    notebook_switcher.set_show_border(false) ;
    notebook_switcher.set_show_tabs(false)   ;


    frame_intensity_red.set_tooltip_text("Add or substract, the wanted value, from to,\nthe red channel from every pixel of your image.\nSo that you can change, or adjust, the red intensity of your image.") ;
    frame_intensity_green.set_tooltip_text("Add or substract, the wanted value, from to,\nthe green channel from every pixel of your image.\nSo that you can change, or adjust, the green intensity of your image.") ;
    frame_intensity_blue.set_tooltip_text("Add or substract, the wanted value, from to,\nthe blue channel from every pixel of your image.\nSo that you can change, or adjust, the blue intensity of your image.") ;
    frame_intensity_main.set_tooltip_text("Add or substract, the wanted value, from to,\nevery color channel from every pixel of your image.\nSo that you can change, or adjust, the main intensity of your image.") ;

    frame_intensity_red.set_margin_left(2)     ;
    frame_intensity_red.set_margin_right(2)    ;
    frame_intensity_green.set_margin_left(2)   ;
    frame_intensity_green.set_margin_right(2)  ;
    frame_intensity_blue.set_margin_left(2)    ;
    frame_intensity_blue.set_margin_right(2)   ;
    frame_intensity_main.set_margin_left(2)    ;
    frame_intensity_main.set_margin_right(2)   ;


    combo_filters.set_border_width(4)    ;
    combo_grayscale.set_border_width(4)  ;
    combo_colorscale.set_border_width(4) ;



    button_filters.set_border_width(4)    ;
    button_grayscale.set_border_width(4)  ;
    button_colorscale.set_border_width(4) ;

    button_filters.set_image(button_image_filters)       ;
    button_grayscale.set_image(button_image_grayscale)   ;
    button_colorscale.set_image(button_image_colorscale) ;

    scale_intensity_blue.set_digits(0)  ;
    scale_intensity_green.set_digits(0) ;
    scale_intensity_red.set_digits(0)   ;
    scale_intensity_main.set_digits(0)  ;

    scale_intensity_blue.set_draw_value(true)  ;
    scale_intensity_green.set_draw_value(true) ;
    scale_intensity_red.set_draw_value(true)   ;
    scale_intensity_main.set_draw_value(true)  ;

    scale_intensity_blue.set_has_origin(true)  ;
    scale_intensity_green.set_has_origin(true) ;
    scale_intensity_red.set_has_origin(true)   ;
    scale_intensity_main.set_has_origin(true)  ;

    scale_intensity_blue.set_upper_stepper_sensitivity(Gtk::SENSITIVITY_ON)  ;
    scale_intensity_green.set_upper_stepper_sensitivity(Gtk::SENSITIVITY_ON) ;
    scale_intensity_red.set_upper_stepper_sensitivity(Gtk::SENSITIVITY_ON)   ;
    scale_intensity_main.set_upper_stepper_sensitivity(Gtk::SENSITIVITY_ON)  ;


    scale_intensity_blue.set_lower_stepper_sensitivity(Gtk::SENSITIVITY_ON)  ;
    scale_intensity_green.set_lower_stepper_sensitivity(Gtk::SENSITIVITY_ON) ;
    scale_intensity_red.set_lower_stepper_sensitivity(Gtk::SENSITIVITY_ON)   ;
    scale_intensity_main.set_lower_stepper_sensitivity(Gtk::SENSITIVITY_ON)  ;

    scale_intensity_blue.set_adjustment( scale_intensity_blue.get_adjustment())    ;
    scale_intensity_green.set_adjustment( scale_intensity_green.get_adjustment())  ;
    scale_intensity_red.set_adjustment( scale_intensity_red.get_adjustment())      ;
    scale_intensity_main.set_adjustment( scale_intensity_main.get_adjustment())    ;

    scale_intensity_blue.set_range(-255.0,  255.0)    ;
    scale_intensity_green.set_range(-255.0, 255.0)    ;
    scale_intensity_red.set_range(-255.0,   255.0)    ;
    scale_intensity_main.set_range(-255.0,  255.0)    ;

    scale_intensity_blue.set_value(0.0)     ;
    scale_intensity_green.set_value(0.0)    ;
    scale_intensity_red.set_value(0.0)      ;
    scale_intensity_main.set_value(0.0)     ;

    scale_intensity_blue.set_increments(1.0,  10.0)     ;
    scale_intensity_green.set_increments(1.0, 10.0)     ;
    scale_intensity_red.set_increments(1.0,   10.0)     ;
    scale_intensity_main.set_increments(1.0,  10.0)     ;

    scale_intensity_blue.add_mark(0.0,  Gtk::POS_RIGHT,  "")     ;
    scale_intensity_green.add_mark(0.0, Gtk::POS_RIGHT,  "")     ;
    scale_intensity_red.add_mark(0.0,   Gtk::POS_RIGHT,  "")     ;
    scale_intensity_main.add_mark(0.0,  Gtk::POS_RIGHT,  "")     ;

    scale_intensity_blue.set_margin_left(2)        ;
    scale_intensity_blue.set_margin_right(2)       ;

    scale_intensity_green.set_margin_left(2)       ;
    scale_intensity_green.set_margin_right(2)      ;

    scale_intensity_red.set_margin_left(2)         ;
    scale_intensity_red.set_margin_right(2)        ;

    scale_intensity_main.set_margin_left(2)        ;
    scale_intensity_main.set_margin_right(2)       ;

    scale_intensity_blue.set_margin_top(2)         ;
    scale_intensity_blue.set_margin_bottom(2)      ;

    scale_intensity_green.set_margin_top(2)        ;
    scale_intensity_green.set_margin_bottom(2)     ;

    scale_intensity_red.set_margin_top(2)          ;
    scale_intensity_red.set_margin_bottom(2)       ;

    scale_intensity_main.set_margin_top(2)         ;
    scale_intensity_main.set_margin_bottom(2)      ;



    scale_intensity_blue.set_inverted(true)     ;
    scale_intensity_green.set_inverted(true)    ;
    scale_intensity_red.set_inverted(true)      ;
    scale_intensity_main.set_inverted(true)     ;




    box_filters.pack_start(combo_filters,  true,  true,  0) ;
    box_filters.pack_start(button_filters, false, false, 0) ;

    box_grayscale.pack_start(combo_grayscale,  true,  true,  0) ;
    box_grayscale.pack_start(button_grayscale, false, false, 0) ;

    box_colorscale.pack_start(combo_colorscale,  true,  true,  0) ;
    box_colorscale.pack_start(button_colorscale, false, false, 0) ;


    frame_intensity_red.add(scale_intensity_red) ;
    frame_intensity_green.add(scale_intensity_green) ;
    frame_intensity_blue.add(scale_intensity_blue) ;
    frame_intensity_main.add(scale_intensity_main) ;



    frame_intensity_red.set_label_align(   0.5,   1.0)  ;
    frame_intensity_green.set_label_align( 0.5,   1.0)  ;
    frame_intensity_blue.set_label_align(  0.5,   1.0)  ;
    frame_intensity_main.set_label_align(  0.5,   1.0)  ;



    button_red_apply.set_image(image_red_apply) ;
    button_red_apply.set_always_show_image(true) ;
    button_green_apply.set_image(image_green_apply) ;
    button_green_apply.set_always_show_image(true) ;
    button_blue_apply.set_image(image_blue_apply) ;
    button_blue_apply.set_always_show_image(true) ;
    button_main_apply.set_image(image_main_apply) ;
    button_main_apply.set_always_show_image(true) ;

    button_red_apply.set_border_width(2)   ;
    button_green_apply.set_border_width(2) ;
    button_blue_apply.set_border_width(2)  ;
    button_main_apply.set_border_width(2)  ;


    box_intensity_red.pack_start(frame_intensity_red,     true,  true,  0) ;
    box_intensity_red.pack_start(button_red_apply,        false, false, 0) ;

    box_intensity_green.pack_start(frame_intensity_green, true,  true,  0) ;
    box_intensity_green.pack_start(button_green_apply,    false, false, 0) ;

    box_intensity_blue.pack_start(frame_intensity_blue,   true,  true,  0) ;
    box_intensity_blue.pack_start(button_blue_apply,      false, false, 0) ;

    box_intensity_main.pack_start(frame_intensity_main,   true,  true,  0) ;
    box_intensity_main.pack_start(button_main_apply,      false, false, 0) ;

    box_intensity_rgbm.pack_start(box_intensity_red,      true, true,   0) ;
    box_intensity_rgbm.pack_start(box_intensity_green,    true, true,   0) ;
    box_intensity_rgbm.pack_start(box_intensity_blue,     true, true,   0) ;
    box_intensity_rgbm.pack_start(box_intensity_main,     true, true,   0) ;

    box_intensity_rgbm.set_border_width(4) ;

    box_intensity_vertical.pack_start(box_intensity_rgbm,     true,  true, 0) ;




    frame_sidebar_filters.add(box_filters) ;
    frame_sidebar_grayscale.add(box_grayscale) ;
    frame_sidebar_colorscale.add(box_colorscale) ;



    box_execute.pack_start(frame_sidebar_filters,    true,  true, 0) ;
    box_execute.pack_start(frame_sidebar_grayscale,  true,  true, 0) ;
    box_execute.pack_start(frame_sidebar_colorscale, true,  true, 0) ;
    box_execute.pack_start(frame_switcher,           true,  true, 0) ;




    button_lightness_apply.set_image(image_lightness_apply)   ;
    button_lightness_apply.set_always_show_image(true)        ;

    button_hue_apply.set_image(image_hue_apply)               ;
    button_hue_apply.set_always_show_image(true)              ;

    button_saturation_apply.set_image(image_saturation_apply) ;
    button_saturation_apply.set_always_show_image(true)       ;

    button_brightness_apply.set_image(image_brightness_apply) ;
    button_brightness_apply.set_always_show_image(true)       ;

    button_lightness_apply.set_border_width(2)  ;
    button_hue_apply.set_border_width(2)        ;
    button_saturation_apply.set_border_width(2) ;
    button_brightness_apply.set_border_width(2) ;

    box_hsbl_lightness.pack_start(frame_lightness,          true,  true,  0) ;
    box_hsbl_lightness.pack_start(button_lightness_apply,   false, false, 0) ;

    box_hsbl_hue.pack_start(frame_hue,                      true,  true,  0) ;
    box_hsbl_hue.pack_start(button_hue_apply,               false, false, 0) ;

    box_hsbl_saturation.pack_start(frame_saturation,        true,  true,  0) ;
    box_hsbl_saturation.pack_start(button_saturation_apply, false, false, 0) ;

    box_hsbl_brightness.pack_start(frame_brightness,        true,  true,  0) ;
    box_hsbl_brightness.pack_start(button_brightness_apply, false, false, 0) ;


    box_colorspace_hsbl.pack_start(box_hsbl_lightness,     true, true, 0) ;
    box_colorspace_hsbl.pack_start(box_hsbl_hue,           true, true, 0) ;
    box_colorspace_hsbl.pack_start(box_hsbl_saturation,    true, true, 0) ;
    box_colorspace_hsbl.pack_start(box_hsbl_brightness,    true, true, 0) ;

    box_colorspace_hsbl.set_border_width(4) ;

    box_colorspace_vertical.pack_start(box_colorspace_hsbl, true, true, 0) ;







    frame_sidebar_intensity.add(box_intensity_vertical) ;

    frame_sidebar_hsbl.add(box_colorspace_vertical) ;



    frame_sidebar_intensity.show() ;
    frame_sidebar_hsbl.show() ;

    notebook_switcher.append_page(frame_sidebar_intensity) ;
    notebook_switcher.append_page(frame_sidebar_hsbl)      ;

    notebook_switcher.set_current_page(0) ;

    box_sidebar_01.pack_start(box_execute,              false,  false, 0) ;
    box_sidebar_01.pack_start(notebook_switcher,        true,   true,  0) ;

    box_sidebar_main.pack_start(box_sidebar_01,          false, false, 0) ;





    box_info_bar_image_bottom.pack_start(label_info_bar_padding_1,    false,  false, 0) ;
    box_info_bar_image_bottom.pack_start(label_info_bar_mouse_coords, false, false,  0) ;
    box_info_bar_image_bottom.pack_start(label_info_bar_padding_2,    true,  true,   0) ;
    box_info_bar_image_bottom.pack_start(label_info_bar_filename,     false, false,  0) ;
    box_info_bar_image_bottom.pack_start(label_info_bar_padding_3,    true,  true,   0) ;
    box_info_bar_image_bottom.pack_start(label_info_bar_file_size,    false, false,  0) ;
    box_info_bar_image_bottom.pack_start(label_info_bar_padding_4,    false,  false, 0) ;

    box_image_displaying.pack_start(display_area,                     true,  true,  0) ;
    box_image_displaying.pack_start(box_info_bar_image_bottom,        false, false, 0) ;

    label_info_bar_padding_1.set_name("info-bar") ;
    label_info_bar_padding_2.set_name("info-bar") ;
    label_info_bar_padding_3.set_name("info-bar") ;
    label_info_bar_padding_4.set_name("info-bar") ;

    label_info_bar_mouse_coords.set_name("info-bar") ;
    label_info_bar_filename.set_name("info-bar") ;
    label_info_bar_file_size.set_name("info-bar") ;


    button_label_draw.set_image(image_label_draw)       ;
    button_label_draw.set_always_show_image(true)       ;

    button_draw_line.set_image(image_draw_line)         ;
    button_draw_line.set_always_show_image(true)        ;

    button_draw_rect.set_image(image_draw_rect)         ;
    button_draw_rect.set_always_show_image(true)        ;

    button_draw_circle.set_image(image_draw_circle)     ;
    button_draw_circle.set_always_show_image(true)      ;

    button_draw_ellipse.set_image(image_draw_ellipse)   ;
    button_draw_ellipse.set_always_show_image(true)     ;

    button_draw_polygon.set_image(image_draw_polygon)   ;
    button_draw_polygon.set_always_show_image(true)     ;

    button_draw_star.set_image(image_draw_star)         ;
    button_draw_star.set_always_show_image(true)        ;

    button_draw_text.set_image(image_draw_text)         ;
    button_draw_text.set_always_show_image(true)        ;



    button_draw_line.set_tooltip_text("Draw a line or joined multilines, by clicking on the image with the left mouse button.\nPress the right mouse button to stop drawning.\nNote: If you clic on the startpoint of mutilines drawning it will join the lines to a polygon.") ;
    button_draw_rect.set_tooltip_text("Draw an rectangle, by clicking on the image with the left mouse button, to set an anchor corner.\nThen move the mouse to size it at your convenience, and click again to draw the rectangle onto your image.\nPress the right mouse button to stop drawning.") ;
    button_draw_circle.set_tooltip_text("Draw a circle, by clicking on the image with the left mouse button, to set his center.\nThen move the mouse to size it at your convenience, and click again to draw the circle onto your image.\nPress the right mouse button to stop drawning.") ;
    button_draw_ellipse.set_tooltip_text("Draw an ellipse, by clicking on the image with the left mouse button, to set his center.\nThen move the mouse to size it at your convenience, and click again to draw the ellipse onto your image.\nPress the right mouse button to stop drawning.") ;
    button_draw_star.set_tooltip_text("Draw a star: first configure what type of star you want to draw.\nThen click on the image with the left mouse button, to set his center.\nAnd move the mouse to size it at your convenience, and click again to draw the star onto your image.\nPress the right mouse button to stop drawning.\n\nYou can press the keys '$' or '*' to turn the star and hit the '=' key to draw it.") ;
    button_draw_polygon.set_tooltip_text("Draw a convex regular polygon: first configure what type of polygon you want to draw.\nThen click on the image with the left mouse button, to set his center.\nAnd move the mouse to size it at your convenience, and click again to draw the polygon onto your image.\nPress the right mouse button to stop drawning.\n\nYou can press the keys '$' or '*' to turn the polygon and hit the '=' key to draw it.") ;
    button_draw_text.set_tooltip_text("Insert some text on your image: enter your text and configure the font settings.\nThen slide the text to the wanted position, and click with the left mouse button, to set the text position.\nPress the right mouse button to stop editing.") ;

    spinbutton_draw_thickness.set_tooltip_text("Set the thickness of forms to draw.\nThe special value \"-1\" mean filling the form if possible.") ;
    colorbutton_draw.set_tooltip_text("Set the color of the forms to draw.") ;
    combo_lines_type.set_tooltip_text("Set the type of the lines of the forms to draw.") ;

    label_draw_thickness.set_image(image_label_thickness)              ;
    label_draw_thickness.set_always_show_image(true)                   ;
    label_draw_thickness.set_relief(Gtk::RELIEF_NONE)                  ;

    label_draw_color.set_image(image_label_draw_color)                 ;
    label_draw_color.set_always_show_image(true)                       ;
    label_draw_color.set_relief(Gtk::RELIEF_NONE)                      ;

    spinbutton_draw_thickness.set_digits(0)                            ;
    spinbutton_draw_thickness.set_range(-1.0, 32.0)                    ;
    spinbutton_draw_thickness.set_value(2.0)                           ;
    spinbutton_draw_thickness.set_increments(1.0, 10.0)                ;
    spinbutton_draw_thickness.set_update_policy(Gtk::UPDATE_IF_VALID ) ;
    spinbutton_draw_thickness.set_wrap(true)                           ;
    spinbutton_draw_thickness.set_numeric(true)                        ;
    spinbutton_draw_thickness.set_snap_to_ticks(true)                  ;

    spinbutton_draw_thickness.set_has_frame(true)  ;
    spinbutton_draw_thickness.set_max_length(3)    ;
    spinbutton_draw_thickness.set_width_chars(3)   ;
    spinbutton_draw_thickness.set_alignment(0.5f)  ;

    colorbutton_draw.set_title("Choose the color for drawning support.") ; // Title of the dialog to correct.

    combo_lines_type.insert(0, "04-lines") ;
    combo_lines_type.insert(1, "08-lines") ;
    combo_lines_type.insert(2, "aa-lines") ;

    combo_lines_type.set_size_request(32, -1) ;

    combo_lines_type.set_active(1)         ;

    draw_thickness = 2                     ;
    draw_color     = Gdk::RGBA("#FFFFFF")  ;
    draw_line_type = cv::LINE_8            ;

    spinbutton_draw_thickness.set_value(draw_thickness) ;

    colorbutton_draw.set_rgba(draw_color) ;


    buttonbox_bottom_draw.pack_start(button_label_draw,    false, false, 0) ;
    buttonbox_bottom_draw.pack_start(button_draw_line,     false, false, 0) ;
    buttonbox_bottom_draw.pack_start(button_draw_rect,     false, false, 0) ;
    buttonbox_bottom_draw.pack_start(button_draw_circle,   false, false, 0) ;
    buttonbox_bottom_draw.pack_start(button_draw_ellipse,  false, false, 0) ;
    buttonbox_bottom_draw.pack_start(button_draw_polygon,  false, false, 0) ;
    buttonbox_bottom_draw.pack_start(button_draw_star,     false, false, 0) ;
    buttonbox_bottom_draw.pack_start(button_draw_text,     false, false, 0) ;


    buttonbox_bottom_draw.set_child_non_homogeneous(button_label_draw,    true)  ;
    buttonbox_bottom_draw.set_child_non_homogeneous(button_draw_line,     true)  ;
    buttonbox_bottom_draw.set_child_non_homogeneous(button_draw_rect,     true)  ;
    buttonbox_bottom_draw.set_child_non_homogeneous(button_draw_circle,   true)  ;
    buttonbox_bottom_draw.set_child_non_homogeneous(button_draw_ellipse,  true)  ;
    buttonbox_bottom_draw.set_child_non_homogeneous(button_draw_polygon,  true)  ;
    buttonbox_bottom_draw.set_child_non_homogeneous(button_draw_star,     true)  ;
    buttonbox_bottom_draw.set_child_non_homogeneous(button_draw_text,     true)  ;

    buttonbox_bottom_config.pack_start(label_draw_thickness,        false, false, 0) ;
    buttonbox_bottom_config.pack_start(spinbutton_draw_thickness,   false, false, 0) ;
    buttonbox_bottom_config.pack_start(label_draw_color,            false, false, 0) ;
    buttonbox_bottom_config.pack_start(colorbutton_draw,            false, false, 0) ;
    buttonbox_bottom_config.pack_start(combo_lines_type,            false, false, 0) ;

    buttonbox_bottom_config.set_child_non_homogeneous(label_draw_thickness,         true) ;
    buttonbox_bottom_config.set_child_non_homogeneous(spinbutton_draw_thickness,    true) ;
    buttonbox_bottom_config.set_child_non_homogeneous(label_draw_color,             true) ;
    buttonbox_bottom_config.set_child_non_homogeneous(combo_lines_type,             true) ;
    buttonbox_bottom_config.set_child_non_homogeneous(colorbutton_draw,             true) ;


    buttonbox_bottom_draw.set_layout(Gtk::BUTTONBOX_CENTER)      ;
    buttonbox_bottom_draw.set_homogeneous(false)                 ;
    buttonbox_bottom_draw.set_spacing(2)                         ;


    buttonbox_bottom_config.set_layout(Gtk::BUTTONBOX_CENTER)    ;
    buttonbox_bottom_config.set_homogeneous(false)               ;
    buttonbox_bottom_config.set_spacing(2)                       ;



    buttonbox_bottom.pack_start(buttonbox_bottom_padding_1,   true,  true,  0) ;
    buttonbox_bottom.pack_start(buttonbox_bottom_draw,        false, false, 0) ;
    buttonbox_bottom.pack_start(buttonbox_bottom_padding_2,   true,  true,  0) ;
    buttonbox_bottom.pack_start(buttonbox_bottom_config,      false, false, 0) ;
    buttonbox_bottom.pack_start(buttonbox_bottom_padding_3,   true,  true,  0) ;




    buttonbox_bottom.set_border_width(4) ;

    frame_buttonbox_bottom.add(buttonbox_bottom) ;


    frame_buttonbox_bottom.unset_label() ;



    frame_buttonbox_bottom.set_margin_right(5)  ;

    box_image_displaying.set_name("image_display_info_box") ;

    middle_box_v.pack_start(box_image_displaying,   true,  true,  0) ;
    middle_box_v.pack_start(frame_buttonbox_bottom, false, false, 0) ;

    middle_box.pack_start(middle_box_v,     true, true, 0) ;
    middle_box.pack_start(box_sidebar_main, false, false, 0) ;


    main_box.pack_start(menu_bar,            false, false)  ;
    main_box.pack_start(frame_buttonbox_top, false, false)  ;
    main_box.pack_start(middle_box,          true,  true)   ;







    display_area.set_size_request(768+128+20, 512-64-16+20)    ; // 10 border size.

    box_image_displaying.set_margin_bottom(5) ;
    box_image_displaying.set_margin_top(12) ;
    box_image_displaying.set_margin_left(0) ;
    box_image_displaying.set_margin_right(5) ;

    Gdk::ModifierType no_modifier    = Gdk::MODIFIER_MASK ;

    no_modifier ^= no_modifier ;

    Gdk::ModifierType ctrl_modifier  = Gdk::CONTROL_MASK ;

    Gdk::ModifierType shift_modifier = Gdk::SHIFT_MASK  ;

    Gdk::ModifierType shift_ctrl_modifier = Gdk::CONTROL_MASK | Gdk::SHIFT_MASK ;

    Gdk::ModifierType alt_modifier   = Gdk::MOD1_MASK ;

    accel_group = accel_group->create() ;

    // Button accelerators.
    button_open.add_accelerator("clicked",          accel_group, GDK_KEY_o,             ctrl_modifier,          Gtk::ACCEL_VISIBLE) ;
    button_save.add_accelerator("clicked",          accel_group, GDK_KEY_s,             ctrl_modifier,          Gtk::ACCEL_VISIBLE) ;

    button_undo.add_accelerator("clicked",          accel_group, GDK_KEY_z,             ctrl_modifier,          Gtk::ACCEL_VISIBLE) ;
    button_redo.add_accelerator("clicked",          accel_group, GDK_KEY_z,             shift_ctrl_modifier,    Gtk::ACCEL_VISIBLE) ;

    button_zoom_plus.add_accelerator("clicked",     accel_group, GDK_KEY_KP_Add,        no_modifier,            Gtk::ACCEL_VISIBLE) ;
    button_zoom_minus.add_accelerator("clicked",    accel_group, GDK_KEY_KP_Subtract,   no_modifier,            Gtk::ACCEL_VISIBLE) ;

    button_rot_left.add_accelerator("clicked",      accel_group, GDK_KEY_KP_Divide,     no_modifier,            Gtk::ACCEL_VISIBLE) ;
    button_rot_right.add_accelerator("clicked",     accel_group, GDK_KEY_KP_Multiply,   no_modifier,            Gtk::ACCEL_VISIBLE) ;

    button_zoom_plus.add_accelerator("clicked",     accel_group, GDK_KEY_plus,          no_modifier,            Gtk::ACCEL_VISIBLE) ;
    button_zoom_minus.add_accelerator("clicked",    accel_group, GDK_KEY_minus,         no_modifier,            Gtk::ACCEL_VISIBLE) ;

    button_rot_left.add_accelerator("clicked",      accel_group, GDK_KEY_division,      no_modifier,            Gtk::ACCEL_VISIBLE) ;
    button_rot_right.add_accelerator("clicked",     accel_group, GDK_KEY_multiply,      no_modifier,            Gtk::ACCEL_VISIBLE) ;


    button_flip_left.add_accelerator("clicked",     accel_group, GDK_KEY_KP_4,          no_modifier,            Gtk::ACCEL_VISIBLE) ;
    button_flip_right.add_accelerator("clicked",    accel_group, GDK_KEY_KP_6,          no_modifier,            Gtk::ACCEL_VISIBLE) ;

    button_flip_up.add_accelerator("clicked",       accel_group, GDK_KEY_KP_8,          no_modifier,            Gtk::ACCEL_VISIBLE) ;
    button_flip_down.add_accelerator("clicked",     accel_group, GDK_KEY_KP_2,          no_modifier,            Gtk::ACCEL_VISIBLE) ;

    button_flip_left.add_accelerator("clicked",     accel_group, GDK_KEY_KP_4,          no_modifier,            Gtk::ACCEL_VISIBLE) ;
    button_flip_right.add_accelerator("clicked",    accel_group, GDK_KEY_KP_6,          no_modifier,            Gtk::ACCEL_VISIBLE) ;

    button_flip_up.add_accelerator("clicked",       accel_group, GDK_KEY_KP_8,          no_modifier,            Gtk::ACCEL_VISIBLE) ;
    button_flip_down.add_accelerator("clicked",     accel_group, GDK_KEY_KP_2,          no_modifier,            Gtk::ACCEL_VISIBLE) ;

    button_flip_left.add_accelerator("clicked",     accel_group, GDK_KEY_4,             no_modifier,            Gtk::ACCEL_VISIBLE) ;
    button_flip_right.add_accelerator("clicked",    accel_group, GDK_KEY_6,             no_modifier,            Gtk::ACCEL_VISIBLE) ;

    button_flip_up.add_accelerator("clicked",       accel_group, GDK_KEY_8,             no_modifier,            Gtk::ACCEL_VISIBLE) ;
    button_flip_down.add_accelerator("clicked",     accel_group, GDK_KEY_2,             no_modifier,            Gtk::ACCEL_VISIBLE) ;

    button_flip_left.add_accelerator("clicked",     accel_group, GDK_KEY_4,             no_modifier,            Gtk::ACCEL_VISIBLE) ;
    button_flip_right.add_accelerator("clicked",    accel_group, GDK_KEY_6,             no_modifier,            Gtk::ACCEL_VISIBLE) ;

    button_flip_up.add_accelerator("clicked",       accel_group, GDK_KEY_8,             no_modifier,            Gtk::ACCEL_VISIBLE) ;
    button_flip_down.add_accelerator("clicked",     accel_group, GDK_KEY_2,             no_modifier,            Gtk::ACCEL_VISIBLE) ;



    button_mirror_left.add_accelerator("clicked",   accel_group, GDK_KEY_KP_6,          alt_modifier,           Gtk::ACCEL_VISIBLE) ;
    button_mirror_right.add_accelerator("clicked",  accel_group, GDK_KEY_KP_4,          alt_modifier,           Gtk::ACCEL_VISIBLE) ;

    button_mirror_top.add_accelerator("clicked",    accel_group, GDK_KEY_KP_2,          alt_modifier,           Gtk::ACCEL_VISIBLE) ;
    button_mirror_bottom.add_accelerator("clicked", accel_group, GDK_KEY_KP_8,          alt_modifier,           Gtk::ACCEL_VISIBLE) ;

    button_mirror_left.add_accelerator("clicked",   accel_group, GDK_KEY_6,             alt_modifier,           Gtk::ACCEL_VISIBLE) ;
    button_mirror_right.add_accelerator("clicked",  accel_group, GDK_KEY_4,             alt_modifier,           Gtk::ACCEL_VISIBLE) ;

    button_mirror_top.add_accelerator("clicked",    accel_group, GDK_KEY_2,             alt_modifier,           Gtk::ACCEL_VISIBLE) ;
    button_mirror_bottom.add_accelerator("clicked", accel_group, GDK_KEY_8,             alt_modifier,           Gtk::ACCEL_VISIBLE) ;


    add_accel_group(accel_group) ;

    add(main_box) ;


    spinbutton_draw_thickness.signal_value_changed().connect(sigc::mem_fun(*this, &GUI::get_draw_thickness)) ;
    colorbutton_draw.signal_color_set().connect(sigc::mem_fun(*this, &GUI::get_draw_color)) ;
    combo_lines_type.signal_changed().connect(sigc::mem_fun(*this, &GUI::get_draw_line_type)) ;

    button_intensity.signal_clicked().connect([this]() { switch_intensity_hsbl(0) ; }) ;
    button_hsbl.signal_clicked().connect([this]()      { switch_intensity_hsbl(1) ; }) ;



    display_area.set_name("Display") ;




    /** CSS suppport: to set the image displaying area in white background and the infobar in gray. **/

    GtkCssProvider *provider ;
    GdkDisplay *display      ;
    GdkScreen *screen        ;

    provider = gtk_css_provider_new()                    ;
    display  = gdk_display_get_default()                 ;
    screen   = gdk_display_get_default_screen (display)  ;

    gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER (provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    Glib::ustring css_content ;

    css_content +=   Glib::locale_to_utf8("\nGtkLabel#info-bar {\n background-color : #A0A0A0 ; } \nGtkLayout#Display {\n background-color : #FFF ; } \n") ;

    gtk_css_provider_load_from_data(GTK_CSS_PROVIDER (provider), css_content.c_str(), -1, NULL);

    Glib::wrap(provider) ;


    // Check if i must erase it:
    set_events(Gdk::STRUCTURE_MASK) ;


    show_all() ;


 }

#include "./gui/Edip_gui_process.cpp"

#include "./gui/Edip_gui_private.cpp"

#include "./gui/Edip_gui_events_end.cpp"

#include "./gui/Edip_gui_toplevels.cpp"

