#ifndef PM_GUI_H
#define PM_GUI_H

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

class pm_gui: public Fl_Window
{

	public:
	
	// Main Window
	pm_gui();
	static void PM_add_component_button_cb(Fl_Widget*, void*);
	inline void PM_add_component_button_cb_i();	
	static void PM_add_model_button_cb(Fl_Widget*, void*);
	inline void PM_add_model_button_cb_i();
	static void PM_menu_back_button_cb(Fl_Widget*,void*);
	inline void PM_menu_back_button_cb_i();
	void show_main();
	void hide_main();
	
	// Buttons for choosing which component to add
	
	Fl_Window* PM_ACM;
	Fl_Button* PM_ACM_addHead;
	Fl_Button* PM_ACM_addArm;
	Fl_Button* PM_ACM_addTorso;
	Fl_Button* PM_ACM_add_battery;
	Fl_Button* PM_ACM_add_locomotor;
	Fl_Button* PM_ACM_back_button;
	
	static void PM_ACM_addArm_cb(Fl_Widget*,void*);
	inline void PM_ACM_addArm_cb_i();
	static void PM_ACM_addHead_cb(Fl_Widget*, void*);
	inline void PM_ACM_addHead_cb_i();
	static void PM_ACM_addLoc_cb(Fl_Widget*, void*);
	inline void PM_ACM_addLoc_cb_i();
	static void PM_ACM_addBattery_cb(Fl_Widget*, void*);
	inline void PM_ACM_addBattery_cb_i();
	static void PM_ACM_addTorso_cb(Fl_Widget*, void*);
	inline void PM_ACM_addTorso_cb_i();
	static void PM_ACM_back_button_cb(Fl_Widget*, void*);
	inline void PM_ACM_back_button_cb_i();
	
	// Menu for making component
	
	void ADD_ALL_func(string);
	
	string current_component;
	Fl_Window* ADD_ALL_window;
	
	Fl_Input *ADD_ALL_name_input;
	Fl_Input* ADD_ALL_cost_input;
	Fl_Input* ADD_ALL_description_input;
	Fl_Input* ADD_ALL_image_input;
	Fl_Input* ADD_ALL_weight_input;
	Fl_Input* ADD_ALL_model_num_input;
	
	Fl_Input* ADD_ALL_power_input;
	Fl_Input* ADD_ALL_max_arm_power_input;
	Fl_Input* ADD_ALL_power_available_input;
	Fl_Input* ADD_ALL_max_energy_input;
	Fl_Input* ADD_ALL_max_loc_power_input;
	Fl_Input* ADD_ALL_max_speed_input;
	Fl_Input* ADD_ALL_max_arms_input;
	Fl_Input* ADD_ALL_max_battery_compartments_input;
	
	Fl_Button* ADD_ALL_create_button;
	Fl_Button* ADD_ALL_cancel_button;
	
	static void ADD_ALL_create_button_cb(Fl_Widget*,void*);
	inline void ADD_ALL_create_button_cb_i();
	static void ADD_ALL_cancel_button_cb(Fl_Widget*,void*);
	inline void ADD_ALL_cancel_button_cb_i();
	
	private:	
	
	// Main Window
	Fl_Button* PM_add_component_button;
	Fl_Button* PM_add_model_button;
	Fl_Button* PM_menu_back_button;
	
	
	//  Adding Components Stuff
	
	
};

#endif