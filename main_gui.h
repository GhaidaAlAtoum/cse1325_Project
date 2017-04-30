#ifndef MAIN_GUI_H
#define MAIN_GUI_H
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <iostream>
#include "Robot_part.h"
#include "Components.h"
#include "Model.h"
#include "shop.h"
#include "Sales_Associate.h"
#include "Product_Manager.h"
#include "Order.h"
#include "customer.h"
#include "PHB.h"

using namespace std;

class main_menu {
		public:
		Fl_Window* main_window;
		Fl_Button* main_button1;
		Fl_Button* main_button2;
		Fl_Button* main_button3;
		Fl_Button* main_button4;
		shop sh;
		
		
		main_menu(shop);
		void show_window();
		void hide_window();
	
};



#endif



