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
#include "main_gui.h"
#include "pm_gui.h"
#include "shop.h"

using namespace std;

////////////////////////////////////
// Main Menu Functions, callbacks //
////////////////////////////////////

// We gotta put the right stuff in the callbacks.. otherwise done		

void main_b1_cb(Fl_Widget* w, void* v) {
	pm_gui pm = SH::get_pm_gui();
	pm.show();
}

void main_b2_cb(Fl_Widget* w, void* v) {
	//((Controller*)v)->main_b2_cb_i();
	cout << "Another called" << endl;
}

void main_b3_cb(Fl_Widget* w, void* v) {
		//((Controller*)v)->main_b3_cb_i();
	cout << "Another callback" << endl;
}

void main_b4_cb(Fl_Widget* w, void* v) {
	//((Controller*)v)->main_b4_cb_i();
	cout << "Callback" << endl;
}

main_menu::main_menu(shop SH) sh(SH) {
			
		main_window = new Fl_Window(500,500, "Robots'R'us");
	
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
	
void main_menu::show_window() {main_window->show();}
void main_menu::hide_window() {main_window->hide();}
	

