#ifndef MAIN_GUI_H
#define MAIN_GUI_H
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <iostream>
using namespace std;

class main_menu {
		public:
		Fl_Window* main_window;
		Fl_Button* main_button1;
		Fl_Button* main_button2;
		Fl_Button* main_button3;
		Fl_Button* main_button4;
		
		main_menu();
		void show_window();
		void hide_window();
	
};



#endif



