#include "main_window.h"
#include"library.h"
#include"controller.h"
Library library;
Controller controller(library);
Main_window::Main_window() {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(400, 200);

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);

    // ///////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //         N E W   G A M E
    // Append New to the File menu
   // Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New Game", true));
    //menuitem_new->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_new_game_click));
    //filemenu->append(*menuitem_new);

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
    filemenu->append(*menuitem_quit);
//    PUBLICATION
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_pub = Gtk::manage(new Gtk::MenuItem("_Publication", true));
    menubar->append(*menuitem_pub);
    Gtk::Menu *pubmenu = Gtk::manage(new Gtk::Menu());
    menuitem_pub->set_submenu(*pubmenu);
//        List
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_list = Gtk::manage(new Gtk::MenuItem("_List", true));
    menuitem_list->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_list_click));
    pubmenu->append(*menuitem_list);
//        Add
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_add = Gtk::manage(new Gtk::MenuItem("_Add", true));
    menuitem_add->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_add_click));
    pubmenu->append(*menuitem_add);
//        Check In
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_cin = Gtk::manage(new Gtk::MenuItem("_Check In", true));
    menuitem_cin->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_cin_click));
    pubmenu->append(*menuitem_cin);
//        Check Out
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_cout = Gtk::manage(new Gtk::MenuItem("_Check Out", true));
    menuitem_cout->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_cout_click));
    pubmenu->append(*menuitem_cout);

//    PATRON
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_pat = Gtk::manage(new Gtk::MenuItem("_Patron", true));
    menubar->append(*menuitem_pat);
    Gtk::Menu *patmenu = Gtk::manage(new Gtk::Menu());
    menuitem_pat->set_submenu(*patmenu);
//        List
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_list1 = Gtk::manage(new Gtk::MenuItem("_List", true));
    menuitem_list1->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_list1_click));
    patmenu->append(*menuitem_list1);
//        Add
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_add1 = Gtk::manage(new Gtk::MenuItem("_Add", true));
    menuitem_add1->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_add1_click));
    patmenu->append(*menuitem_add1);
    //     H E L P
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    //           A B O U T
    // Append About to the Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("About", true));
    menuitem_about->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_about_click));
    helpmenu->append(*menuitem_about);

     //T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);

    //    Add Pub
    // Add a new game icon
    Gtk::ToolButton *add_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    add_button->set_tooltip_markup("Add a new publication");
    add_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_add_click));
    toolbar->append(*add_button);
	//    List Pub
    // Add a new game icon
 button2_on_image = Gtk::manage(new Gtk::Image("list.png"));
   
    button2 = Gtk::manage(new Gtk::ToolButton(*button2_on_image));
    button2->set_tooltip_markup("List all the publications");
    button2->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_list_click));
    toolbar->append(*button2);
//    Add Pat
    // Add a new game icon
    Gtk::ToolButton *add1_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    add1_button->set_tooltip_markup("Add a new patron");
    add1_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_add1_click));
    toolbar->append(*add1_button);
	//    List Pat
    // Add a new game icon
    button3_on_image = Gtk::manage(new Gtk::Image("list.png"));
   
    button3 = Gtk::manage(new Gtk::ToolButton(*button3_on_image));
    button3->set_tooltip_markup("List all the patrons");
    button3->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_list1_click));
    toolbar->append(*button3);
button1_on_image = Gtk::manage(new Gtk::Image("cout.png"));

    button1 = Gtk::manage(new Gtk::ToolButton(*button1_on_image));
    button1->set_tooltip_markup("Check Out a Publication");
    button1->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_cout_click));
    toolbar->append(*button1);
 button4_on_image = Gtk::manage(new Gtk::Image("cin.png"));

    button4 = Gtk::manage(new Gtk::ToolButton(*button4_on_image));
    button4->set_tooltip_markup("Check In a Publication");
    button4->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_cin_click));
    toolbar->append(*button4);
   //     Q U I T
    // Add a icon for quitting
    Gtk::ToolButton *help_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::HELP));
    help_button->set_tooltip_markup("About");
    help_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_about_click));
    Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
    sep->set_expand(true);  // The expanding sep forces the Quit button to the right
    toolbar->append(*sep);
    toolbar->append(*help_button);
    //     Q U I T
    // Add a icon for quitting
    Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
    quit_button->set_tooltip_markup("Exit game");
    quit_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
    //Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
    //sep->set_expand(true);  // The expanding sep forces the Quit button to the right
    //toolbar->append(*sep);
    toolbar->append(*quit_button);

    // S T I C K S   D I S P L A Y
    // Provide a text entry box to show the remaining sticks
    sticks = Gtk::manage(new Gtk::Label());
    // sticks->set_has_frame(false);
    sticks->set_hexpand(true);
    sticks->set_vexpand(true);
    vbox->add(*sticks);
    
    // S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for game messages
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    vbox->add(*msg);

    // Make the box and everything in it visible
    vbox->show_all();

    // Start a new game
  //  on_new_game_click();

}

Main_window::~Main_window() { }

// /////////////////
// C A L L B A C K S
// /////////////////

void Main_window::on_list_click() {
    controller.execute_cmd(2);
}

void Main_window::on_add_click() {
    controller.execute_cmd(1);
	
}
void Main_window::on_list1_click() {
    controller.execute_cmd(6);
}

void Main_window::on_add1_click() {
    controller.execute_cmd(5);
}

void Main_window::on_cin_click() {
    controller.execute_cmd(4);
}
void Main_window::on_cout_click() {
    controller.execute_cmd(3);
}

void Main_window::on_quit_click() {
    hide();
}

void Main_window::on_about_click() {
  controller.execute_cmd(9);
}

// /////////////////
// U T I L I T I E S
// /////////////////


