#include"main_window.h"
#include <gtkmm.h>
#include "controller.h"
#include "library.h"


int main(int argc, char *argv[]) {
Glib::RefPtr<Gtk::Application> app = 
    Gtk::Application::create(argc, argv, "edu.uta.cse1325.nim");
Main_window win;
win.set_title("Library Management System");
return app->run(win);
}
