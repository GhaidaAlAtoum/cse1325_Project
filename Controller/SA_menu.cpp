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
#include <FL/Fl_Int_Input.H>

using namespace std;

/////////////////////////////
////SA MENU//////////////////
/////////////////////////////

void Controller::SA_menu_func() {

	hide_main_window();

	SA_mainmenu_window = new Fl_Window(500,500, "Sales Associate Menu");
	SA_process_order = new Fl_Button(10,20,200,50, "Process Order");
	SA_process_order->callback(SA_process_order_cb, this);
	
	SA_CRO_button = new Fl_Button(10,80,200,50, "Create a robot order");
	
	SA_mainmenu_window->show();
}

void Controller::SA_process_order_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->SA_process_order_cb_i();	
}
void Controller::SA_process_order_cb_i() {
	SA_process_order_func();
	SA_mainmenu_window->hide();
}

// PROCESS ORDER STUFF

void Controller::SA_process_order_func() {

	SA_process_order_win = new Fl_Window(500,500,"Choose orders");
	
	process_order_back = new Fl_Button(60,450,100,40,"Back");
	process_order_back->callback(process_order_back_cb, this);
	
	order_list = new Fl_Multiline_Output(0,0,500,400);
	get_index = new Fl_Int_Input(330,450, 70,40,"Index");
	
	process_order_enter = new Fl_Button(420,450,70,40,"Enter");
	process_order_enter->callback(process_order_enter_cb, this);
	
	string orders = "Example order 1\nExample order 2\nExample oder 3";
	const char* out_orders = orders.c_str();
	order_list->value(out_orders);
	
	SA_process_order_win->show();
	
}

void Controller::process_order_back_cb(Fl_Widget* w,void* v) {
	((Controller*)v)->process_order_back_cb_i();
}
void Controller::process_order_back_cb_i() {
	SA_process_order_win->hide();
	SA_mainmenu_window->show();
}

void Controller::process_order_enter_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->process_order_enter_cb_i();	
}
void Controller::process_order_enter_cb_i() {
	SA_process_order_win->hide();
	SA_mainmenu_window->hide();
	const char* index = get_index->value();
	cout << index << endl;
	cout << "PROCESSING ORDER DOES STH HERE" << endl;	
}