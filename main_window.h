
#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm.h>
#include "controller.h"
#include"view.h"
class Main_window : public Gtk::Window
{
    public:
        Main_window();
        virtual ~Main_window();
    protected:
        void on_list_click();        // Create a new game
        void on_add_click();         // Select one stick from pile
	void on_list1_click();        // Create a new game
        void on_add1_click();          
	void on_cin_click();         // Select two sticks from pile
        void on_cout_click();         // Select three sticks from pile
        void on_computer_player_click(); // Enable / disable computer player
        void on_about_click();           // Display About dialog
        void on_quit_click();            // Exit the game
    private:
        void set_sticks();                    // Update display, robot move
                                  // Current game board
	//Controller controller;
	//Library library;
        Gtk::Label *sticks;                   // Display of sticks on game board
        Gtk::Label *msg;                      // Status message display
        Gtk::ToolButton *button1;             // Button to select 1 stick
        Gtk::Image *button1_on_image;         //   Image when active
        Gtk::Image *button1_off_image;        //   Image when inactive
        Gtk::ToolButton *button2;             // Button to select 2 sticks
        Gtk::Image *button2_on_image;
        Gtk::Image *button2_off_image;
        Gtk::ToolButton *button3;             // Button to select 3 sticks
        Gtk::Image *button3_on_image;
        Gtk::Image *button3_off_image;
 Gtk::ToolButton *button4;             // Button to select 1 stick
        Gtk::Image *button4_on_image;    
        Gtk::ToggleToolButton *computer_player;  // Button to enable robot
};
#endif 

