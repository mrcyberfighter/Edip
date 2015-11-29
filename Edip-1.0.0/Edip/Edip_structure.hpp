#ifndef EDIP_STRUCTURE_HH
#define EDIP_STRUCTURE_HH

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


#include <gtkmm/box.h>

#include <gtkmm/menuitem.h>

// Images widgets:
#include <gtkmm/image.h>

#include <gtkmm/label.h>

typedef struct {

  Gtk::MenuItem    menu_item              ;
  Gtk::Box         menu_item_container    ;
  Gtk::Image       menu_item_image        ;
  Gtk::Label       menu_item_label        ;
  Gtk::Box         menu_item_padding      ;
  Gtk::Label       menu_item_accel_label  ;

} Menu_Item ;

#endif