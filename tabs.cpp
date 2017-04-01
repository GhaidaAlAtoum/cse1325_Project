#include <string>
#include <iostream>
#include <FL/Fl.H> 
#include <FL/Fl_Window.H>
#include <stdlib.h>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>
using namespace std;

// Compile with: g++ -std=c++11 tabs.cpp -lfltk -o test_window
// Then ./test_window to run

// Callbacks


class Main_Window
{
	
	public:
		Main_Window()
		{
		window = new Fl_Window(500,200, "Tabs Test Window");	

			
		Fl_Tabs *tabs = new Fl_Tabs(10,10,500-20,200-20);
		{
			
			
    		Fl_Group *grp1 = new Fl_Group(10,35,500-20,200-45,"tab1");
    		{
        		customer_button = new Fl_Button(100, 100, 150, 40, "Ghaidan is cool");
    		}
    		grp1->end();
    	
			Fl_Group *grp2 = new Fl_Group(10,35,500-10,200-45,"tab2");
    		{
        		Fl_Button* customer_button2 = new Fl_Button(100, 100, 150, 40, "Junu is cool");
    		}
    	
			grp2->end();
		}
		
		
		tabs->end();
			
		window->end();	
		}
	
	
		void show() {window->show();}
		void hide() {window->hide();}
	

	private:
		Fl_Window* window;
		Fl_Tabs* tabs;
		Fl_Button* customer_button;
};


int main()
{
	
	//fl_register_images(); // I dunno what this is or if its necessary
	
	Main_Window* main_window = new Main_Window();
	main_window->show();

	return(Fl::run());
	
}










