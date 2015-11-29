#ifndef EDIP_INFO_DIALOG_HH
#define EDIP_INFO_DIALOG_HH

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



void GUI::show_about(void) {
 
   Gtk::AboutDialog  dialog ;
 
   dialog.set_program_name(PRGNAME_STRING) ;
 
   dialog.set_version(VERSION_STRING) ;
 
   dialog.set_website("http://www.open-source-projects.net/Edip/Edip_presentation.html") ;
 
   dialog.set_website_label("Edip Website") ;
 
   dialog.set_wrap_license(true) ;
 
   dialog.set_copyright(LICENSE_STRING) ;
 
   dialog.set_license(Glib::file_get_contents(PATH_TO_EDIP_LICENSE)) ;
 
   dialog.set_logo_default() ;
 
   vector<Glib::ustring> authors = {AUTHOR_STRING "<mrcyberfighter@gmail.com>"} ;
 
   dialog.set_authors(authors) ;
 
   vector<Glib::ustring> artists = {AUTHOR_STRING "<mrcyberfighter@gmail.com>"} ;
 
   dialog.set_artists(artists) ;
 
   dialog.set_comments("Thanks to my beloved mother, my family and to the doctors.\nStay away from drugs: drugs destroy your brain and your life.") ;
 
   dialog.run() ;
 
   dialog.close() ;

} 

void GUI::launch_readme_html(void) {

  /** Launch the README file to display it to the user through the GUI. **/

  GError *error = NULL ;

  char *readme_realpath = realpath(PATH_TO_README, NULL) ;

  gchar *readme_uri = g_filename_to_uri(readme_realpath, NULL, NULL);

  gtk_show_uri(NULL, readme_uri, GDK_CURRENT_TIME, &error);

  g_free(readme_uri) ;
  free(readme_realpath) ;

  #ifdef DEBUG
  // This call make crash the application, i don't know why. Not really needed, so we process only if DEBUG define.
  if (error != NULL) {

    string msg =  "Cannot display README:\n\n" ;

    msg += error->message ;

    display_message_dialog("Error README displaying !", msg.c_str() ) ;

  }
  #endif

    
  return ;

}

void GUI::launch_documentation_html(void) {

  /** Launch the HTML-Documentation file to display it to the user through the GUI. **/

  GError *error = NULL ;

  char *doc_realpath = realpath(PATH_TO_DOCUMENTATION, NULL) ;

  gchar *doc_uri = g_filename_to_uri(doc_realpath, NULL, NULL);

  gtk_show_uri(NULL, doc_uri, GDK_CURRENT_TIME, &error);

  g_free(doc_uri) ;
  free(doc_realpath) ;

  #ifdef DEBUG
  // This call make crash the application, i don't know why. Not really needed, so we process only if DEBUG define.
  if (error != NULL) {

    string msg =  "Cannot display README:\n\n" ;

    msg += error->message ;

    display_message_dialog("Error README displaying !", msg.c_str() ) ;

  }
  #endif

    
  return ;

}
 
#endif 
 