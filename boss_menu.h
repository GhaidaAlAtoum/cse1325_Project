#ifndef BOSS_MENU_H
#define BOSS_MENU_H
#include <string>
#include <iostream>
#include <stdlib.h>
#include <FL/Fl.H> 
#include <FL/Fl_Window.H>
#include <stdlib.h>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Int_Input.H>
#include <Fl/Fl_Box.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Choice.H>
//#include "Sales Associate.h"
#include <FL/Fl_Text_Display.H>

using namespace std;


class boss_menu {
                public:
	
	// Info window for giving raise
	Fl_Window* give_raise_info_win;
	Fl_Multiline_Output* order_info_box;
	
	// Background stuff
	Fl_JPEG_Image* jpg;
	Fl_Box* main_background;
  
       	// Boss main menu
	void B_menu_func();
	Fl_Window* B_menu_win;
	
	Fl_Button* BOSS_create_customer;
	Fl_Button* BOSS_create_SA;
	Fl_Button* BOSS_menu_back_b;
	Fl_Button* BOSS_raise_stuff_b;
	Fl_Button* BOSS_give_raise_button;
	
	static void BOSS_raise_stuff_b_cb(Fl_Widget*, void*);
	inline void BOSS_raise_stuff_b_cb_i();
	static void BOSS_create_customer_cb(Fl_Widget*, void*);
	inline void BOSS_create_customer_cb_i();
	static void BOSS_create_SA_cb(Fl_Widget*, void*);
	inline void BOSS_create_SA_cb_i();
	static void BOSS_menu_back_b_cb(Fl_Widget*, void*);
	inline void BOSS_menu_back_b_cb_i();
	static void BOSS_give_raise_cb(Fl_Widget*, void*);
	inline void BOSS_give_raise_cb_i();

	
	void BOSS_create_SA_func();
	void BOSS_create_C_func();
	
	// stats and stuff


	static void stats_callback(Fl_Widget* w, void* v);
	inline void stats_callback_i();
	Fl_Window* stats_win;
	Fl_Button* back_from_stats;
	Fl_Text_Display* d1;
	
	
	
	
	
	// BOSS making SA stuff
	
	Fl_Window* create_SA_window;
	Fl_Input* new_SA_name_input;
	Fl_Input* new_SA_pass_input;
	Fl_Button* create_SA_b;
	Fl_Button* create_SA_back_b;
	
	static void create_SA_b_cb(Fl_Widget* w, void* v);
	inline void create_SA_b_cb_i();
	static void create_SA_back_b_cb(Fl_Widget*, void*);
	inline void create_SA_back_b_cb_i();
	
	// BOSS making Customer stuff
	
	Fl_Window* BOSS_create_c_win;
	Fl_Input* BOSS_CC_name_input;
	Fl_Input* BOSS_CC_phone_input;
	Fl_Input* BOSS_CC_email_input;
	Fl_Input* BOSS_CC_pass_input;
	Fl_Button* BOSS_CC_button;
	Fl_Button* BOSS_CC_cancel_button;
	
	static void BOSS_CC_button_cb(Fl_Widget*,void*);
	inline void BOSS_CC_button_cb_i();
	static void BOSS_CC_cancel_button_cb(Fl_Widget*,void*);
	inline void BOSS_CC_cancel_button_cb_i();
	
	
	
	// BOSS gives raise
	
	void give_raise_func();
	
	Fl_Window* give_raise_window;
	Fl_Multiline_Output* SA_list;
	Fl_Button* give_raise_back;
	Fl_Button* give_raise_enter;
	Fl_Button* give_raise_info;
	Fl_Int_Input* give_raise_index;
	
	static void give_raise_back_cb(Fl_Widget*, void*);
	inline void give_raise_back_callback_i();
	static void give_raise_enter_cb(Fl_Widget*, void*);
	inline void give_raise_enter_callback_i();
	static void give_raise_info_cb(Fl_Widget*, void*);
	inline void give_raise_info_callback_i();
};


#endif
