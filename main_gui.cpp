#include "Controller.h" 
#include <iostream>
#include <stdlib.h>
#include <string>
#include <FL/Fl.H> 
#include <FL/Fl_Window.H>
#include <stdlib.h>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>

using namespace std;

////////////////////////////////////
// Main Menu Functions, callbacks //
////////////////////////////////////

		
void main_b1_cb(Fl_Widget* w, void* v) {
	cout << "callback called" << endl;
	
}
/*
void Controller::main_b1_cb_i() {
	unpw_menu_func();
	person_type = "PM";
}
*/
void main_b2_cb(Fl_Widget* w, void* v) {
	//((Controller*)v)->main_b2_cb_i();
	cout << "Another called" << endl;
}
/*
void Controller::main_b2_cb_i() {
	unpw_menu_func();
	person_type = "SA";
}
*/

void main_b3_cb(Fl_Widget* w, void* v) {
		//((Controller*)v)->main_b3_cb_i();
	cout << "Another callback" << endl;
}
/*
void Controller::main_b3_cb_i() {
	ask_if_new_func();
	person_type = "CU";
}
*/

void main_b4_cb(Fl_Widget* w, void* v) {
	//((Controller*)v)->main_b4_cb_i();
	cout << "Callback" << endl;
}
/*
void Controller::main_b4_cb_i() {
	unpw_menu_func();	
	person_type = "B";
} */


class main_menu {
	
		public:
	
		main_menu() {
			
		Fl_Window* main_window = new Fl_Window(500,500,"Robots'R'us");
	
		main_button1 = new Fl_Button(20,20,200,50,"Parts Manager");
		main_button1->callback(main_b1_cb, this);
	
		main_button2 = new Fl_Button(20,90,200,50,"Sales Associate");
		main_button2->callback(main_b2_cb, this);
	
		main_button3 = new Fl_Button(20,160,200,50,"Customer");
		main_button3->callback(main_b3_cb, this);
	
		main_button4 = new Fl_Button(20,230,200,50,"Boss");
		main_button4->callback(main_b4_cb, this);
	
		main_window->end();
	
		}
	
		void show() {main_window->show();}
		void hide() {main_window->hide();}
	
		private:
		Fl_Window* main_window;
		Fl_Button* main_button1;
		Fl_Button* main_button2;
		Fl_Button* main_button3;
		Fl_Button* main_button4;
	
};
		


int main() {
	
	main_menu* mm = new main_menu();
	cout << "not shown yet" << endl;
	mm->show();
	cout << "it ran" << endl;
	return(Fl::run());
	
}