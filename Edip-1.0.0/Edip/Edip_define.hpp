#ifndef EDIP_DEFINE_HH
#define EDIP_DEFINE_HH

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

#define SUPPORT_BMP                    // Always supported.
#define SUPPORT_SUN_RASTER             // Always supported.
#define SUPPORT_PORTABLE_IMAGE_FORMAT  // Always supported.

#define SUPPORT_PNG                    // Not always supported.
#define SUPPORT_JPG                    // Not always supported.
#define SUPPORT_TIF                    // Not always supported.
#define SUPPORT_WEBP                   // Not always supported.

#define PRGNAME_STRING  "Edip"
#define VERSION_STRING  "1.0.0"
#define AUTHOR_STRING   "Brüggemann Eddie"
#define LICENSE_STRING  "GPLv3"

#ifndef MAIN_PATH
#define MAIN_PATH                      "./"
#endif

#define PATH_TO_MENU_ICONS             MAIN_PATH   "images/icons/16x16/"


#define PATH_TO_BUTTON_ICONS           MAIN_PATH   "images/icons/22x22/"

#define PATH_TO_MSG_DIALOG_ICONS       MAIN_PATH   "images/icons/48x48/"

#define PATH_TO_AUTOSIZE_ICONS         MAIN_PATH   "images/icons/24x48/"

#define PATH_TO_MOUSE_CURSOR_ICON      MAIN_PATH   "images/mouse_curser/"

#define PATH_TO_EDIP_ICON              MAIN_PATH   "images/icons/Logo/"

#define PATH_TO_EDIP_LICENSE           MAIN_PATH   "License/GPLv3.txt"

#define PATH_TO_README                 MAIN_PATH   "README/README.html" 

#define PATH_TO_DOCUMENTATION          MAIN_PATH   "html-documentation/index.html" 

#define FILTER_DIALOG_SPACE                   4
#define FILTER_DIALOG_FRAME_INNER_SPACE       6
#define FILTER_DIALOG_BOX_SPACING             6
#define FILTER_DIALOG_BOX_BORDER              4
#define FILTER_DIALOG_BUTTON_BORDER           4
#define FILTER_DIALOG_LABEL_MARGIN_LEFT       2
#define FILTER_DIALOG_LABEL_MARGIN_RIGHT      8

#define DIALOG_BORDER_WIDTH     4
#define FRAME_INNER_SPACE       6
#define BOX_SPACING             6
#define BOX_BORDER              4
#define FRAME_BORDER_WIDTH      8

#define DRAWNING_DIALOG_BOX_SPACING   2
#define DRAWNING_DIALOG_BOX_BORDER    4

#endif