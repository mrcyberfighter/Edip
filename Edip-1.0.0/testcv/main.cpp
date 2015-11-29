#include <string>
#include <vector>
#include <cstdlib>

using namespace std ;

#include <gtk/gtk.h>

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

void destroy(GtkWidget *widget,gpointer pointer) ;

static gboolean delete_event(GtkWidget *widget,GdkEvent *event,gpointer pointer) ;

gboolean quit(gpointer user_data) ;

string return_msg ;

int main(int argc, char *argv[]) {

  if (argc < 2 ) {

    fprintf(stdout,"usage: %s image_filepath", argv[0]) ;

    exit(EXIT_FAILURE) ;
  }

  try {
   
    return_msg = "Genius It works !!!" ;
 
    cv::Mat image = cv::imread(argv[1]) ;
   
    cv::Mat frame ;

    // This can fail by some bads images files this why the exception handle.
    cv::resize(image, frame, cv::Size(image.cols, image.rows) ) ;
   
  }
  catch (cv::Exception &e) {
 
    return_msg = "Sorry It doesn't work !\n\n" ;
 
    return_msg += e.err ; 

  }

  
  gtk_init(&argc,&argv) ;

  GtkWidget *window, *label, *image, *vbox ;

  window=gtk_window_new(GTK_WINDOW_TOPLEVEL) ;

  gtk_window_set_icon_from_file(GTK_WINDOW(window), argv[1], NULL) ;
  gtk_window_set_title(GTK_WINDOW(window), "Test program") ;
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER_ALWAYS) ;
  gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
  gtk_widget_set_size_request(window,-1,-1) ;


  label = gtk_label_new(return_msg.c_str()) ;

  image = gtk_image_new_from_file(argv[1]) ;

  vbox  = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0) ;

  gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0) ;
  gtk_box_pack_start(GTK_BOX(vbox), image, TRUE,  TRUE,  0) ;

  gtk_window_set_title(GTK_WINDOW(window),"Test program") ;

  gtk_widget_set_size_request(window,-1,-1) ;

  gtk_container_set_border_width(GTK_CONTAINER(window),16) ;

  gtk_container_add(GTK_CONTAINER(window), vbox) ;

  g_signal_connect(G_OBJECT(window), "destroy",      G_CALLBACK(destroy),    NULL) ;

  g_signal_connect(G_OBJECT(window), "delete-event", G_CALLBACK(delete_event),NULL) ;

  gtk_widget_show_all(window) ;

  int timeout_ms = 5000 ;

  g_timeout_add( timeout_ms, &quit, NULL);

  gtk_main() ;



  exit(EXIT_SUCCESS) ;



}

gboolean quit(gpointer user_data) {

 destroy(NULL, NULL) ;

 return FALSE ;

}

void destroy(GtkWidget *widget,gpointer pointer) {
  fprintf(stdout,"Test program result:\n%s\n", return_msg.c_str()) ;
  gtk_main_quit() ;

  return ;
}

static gboolean delete_event(GtkWidget *widget,GdkEvent *event,gpointer pointer) {
  if (event->type == GDK_DELETE) {
    fprintf(stdout,"%s delete_event catch\n",__func__) ;
    return FALSE ;
  }
  else {
    fprintf(stdout,"%s delete_event not catch\n",__func__) ;
    return TRUE ;
  }
}
