#include <iostream>
#include <stdlib.h>
#include <string>
#include <FL/Fl.H> 
#include <FL/Fl_Window.H>
#include <stdlib.h>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>

using namespace std;

// compile with: g++ -std=c++11 robot_gui.cpp -lfltk -o robot_gui

///////////////
//MAIN WINDOW//
///////////////

// CALLBACKS
void main_PM_cb(Fl_Widget* w, void*);


// Main Window Class

class Main_Window
{
	
	public:
	
	
	Main_Window();
	bool authenticate_user(string username, string password);
	
	
	
	private:
	
	Fl_Window* main_window;
	Fl_Button* SA_button;
	Fl_Button* boss_button;
	Fl_Button* PM_button;
	
	int button_width = 200;
	int button_height = 50;
	
	string test_string = "data still available";
	
};


// Main_Window Functions

Main_Window::Main_Window()
{
	
	main_window = new Fl_Window(800, 500, "Robot'R'Us");
	
	SA_button = new Fl_Button(300,50,button_width,button_height,"Sales Associate");
	
	boss_button = new Fl_Button(300,115,button_width,button_height,"Hairy Boss");
	
	PM_button = new Fl_Button(300,180,button_width,button_height,"Parts Manager");
	PM_button->callback(main_PM_cb);
	
	
	main_window->end();
	main_window->show();
	
}

bool Main_Window::authenticate_user(string in_username, string in_password)
{
	
	// This will later have logic to check the username and password given to it.
	// For now, just returns true so we can build beyong it
	
	return true;
	
}

// Main_Window Callbacks

void main_PM_cb(Fl_Widget* w, void* v)
{

	cout << "Callback called" << endl;	
	
}


/////////////////
//PARTS MANAGER//
/////////////////

// Callbacks

// Main Class

class Parts_Manager
{
	
	public:
	Parts_Manager();
	
	private:
	
};




int main()
	
{
	
	Main_Window* main_window = new Main_Window();
	
	
	return(Fl::run());
	
}