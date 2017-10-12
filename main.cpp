#include"main_window.h"
#include <gtkmm.h>
#include "controller.h"
#include "library.h"


int main(int argc, char *argv[]) {
  //Gtk::Main kit(argc, argv);
Glib::RefPtr<Gtk::Application> app = 
    Gtk::Application::create(argc, argv, "edu.uta.cse1325.nim");

  // Instance a Window
   
//Library library;
  //Controller controller(library);
Main_window win;
win.set_title("Library Management System");
  //controller.cli();
return app->run(win);
}
