#include "pm_gui.h"
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

// MAIN window callbacks and stuff

void pm_gui::show_main() {this->show();}
void pm_gui::hide_main() {this->hide();}

void pm_gui::PM_menu_back_button_cb(Fl_Widget* w, void* v) {
	((pm_gui*)v)->PM_menu_back_button_cb_i();
}
void pm_gui::PM_menu_back_button_cb_i() {
	this->hide();
	cout << "restart whole program's main menu here" << endl;
}

pm_gui::pm_gui():Fl_Window(500,500,"Project Manager")
{
	
	PM_add_component_button = new Fl_Button(10,10,200,50,"Add Component");
	PM_add_component_button->callback(PM_add_component_button_cb, this);
	PM_add_model_button = new Fl_Button(10, 70, 200, 50, "Add Model");
	PM_add_model_button->callback(PM_add_model_button_cb, this);
	
	PM_menu_back_button = new Fl_Button(10,400,100,50,"Back");
	PM_menu_back_button->callback(PM_menu_back_button_cb, this);
	
	end();
}


void pm_gui::PM_add_component_button_cb(Fl_Widget* w, void* v) {
	((pm_gui*)v)->PM_add_component_button_cb_i();
}



// Callback makes menu for adding which type of component
void pm_gui::PM_add_component_button_cb_i() {
	
	this->hide();
	
	PM_ACM = new Fl_Window(500,500,"Add Component");
	
	PM_ACM_addHead = new Fl_Button(10,10,200,50,"Add Head");
	PM_ACM_addHead->callback(PM_ACM_addHead_cb, this);
	
	PM_ACM_addArm = new Fl_Button(10,70,200,50,"Add Arm");
	PM_ACM_addArm->callback(PM_ACM_addArm_cb, this);
	
	PM_ACM_addTorso = new Fl_Button(10,130,200,50,"Add Torso");
	PM_ACM_addTorso->callback(PM_ACM_addTorso_cb, this);
	
	PM_ACM_add_battery = new Fl_Button(10,190,200,50,"Add Battery");
	PM_ACM_add_battery->callback(PM_ACM_addBattery_cb, this);
	
	PM_ACM_add_locomotor = new Fl_Button(10,250,200,50,"Add Locomotor");
	PM_ACM_add_locomotor->callback(PM_ACM_addLoc_cb, this);
	
	PM_ACM_back_button = new Fl_Button(10,400,100,50,"Back");
	PM_ACM_back_button->callback(PM_ACM_back_button_cb, this);
	
	PM_ACM->show();
										
}

// ALL the callbacks for component menu above

void pm_gui::PM_ACM_back_button_cb(Fl_Widget* w, void* v) {
	((pm_gui*)v)->PM_ACM_back_button_cb_i();	
}
void pm_gui::PM_ACM_back_button_cb_i() {
	PM_ACM->hide();
	this->show();
}

void pm_gui::PM_add_model_button_cb(Fl_Widget* w, void* v) {
	((pm_gui*)v)->PM_add_model_button_cb_i();
}
void pm_gui::PM_add_model_button_cb_i() {
	// ADD MODEL WINDOW GOES HERE 
}



// ADD_ALL function, where components are actually created

void pm_gui::ADD_ALL_func(string component_type)
{
	current_component = component_type;
	
	ADD_ALL_window = new Fl_Window(500,500, "Create Component");
	
	// In robot_part class..
	ADD_ALL_name_input = new Fl_Input(110, 25, 250, 30, "&Name");
	ADD_ALL_model_num_input = new Fl_Input(110, 75, 250, 30, "M&odel Number");
	ADD_ALL_cost_input = new Fl_Input(110, 125, 250, 30, "&Cost");
	ADD_ALL_description_input = new Fl_Input(110, 175, 250, 30, "&Description");
	ADD_ALL_image_input = new Fl_Input(110, 225, 250, 30, "&Image");
	ADD_ALL_weight_input = new Fl_Input(110,275,250,30,"Weight: ");
	
	// Additional Inputs based on component type..
	
	if (component_type == "head") {
		ADD_ALL_power_input = new Fl_Input(110,325,250,30,"Power");
	}
	else if (component_type == "arm") {
		ADD_ALL_max_arm_power_input = new Fl_Input(110,325,250,30,"Max Power");
	}
	else if (component_type == "battery") {
		ADD_ALL_power_available_input = new Fl_Input(110,325,250,30,"Power Available");
		ADD_ALL_max_energy_input = new Fl_Input(110,375,250,30,"Max Energy");
	}
	else if (component_type == "locomotor") {
		ADD_ALL_max_loc_power_input = new Fl_Input(110,325,250,30,"Max Power");
		ADD_ALL_max_speed_input = new Fl_Input(110,375,250,30,"Max Speed");
	}
	else if (component_type == "torso") {
		ADD_ALL_max_arms_input = new Fl_Input(110,325,250,30,"Max Arms");
		ADD_ALL_max_battery_compartments_input = new Fl_Input(110,375,250,30,"Battery Compartments");	
	}
			 
	
	ADD_ALL_create_button = new Fl_Button(70,450,100,40,"Create");
	ADD_ALL_create_button->callback(ADD_ALL_create_button_cb, this);
	ADD_ALL_cancel_button = new Fl_Button(190,450,100,40,"Cancel");
	ADD_ALL_cancel_button->callback(ADD_ALL_cancel_button_cb, this);
	
	ADD_ALL_window->show();
}	

// CALLBACKS for the stuff in the ADD_ALL function like back, create

void pm_gui::ADD_ALL_create_button_cb(Fl_Widget* w, void* v) {
	((pm_gui*)v)->ADD_ALL_create_button_cb_i();	
}
void pm_gui::ADD_ALL_create_button_cb_i() {
	ADD_ALL_window->hide();
	PM_ACM->show();
	//////////////////////////////////////
	//MAKE NEW COMPONENT STUFF GOES HERE//
	//////////////////////////////////////
}

void pm_gui::ADD_ALL_cancel_button_cb(Fl_Widget* w, void* v) {
	((pm_gui*)v)->ADD_ALL_cancel_button_cb_i();	
}
void pm_gui::ADD_ALL_cancel_button_cb_i() {
	PM_ACM->show();
	ADD_ALL_window->hide();
}

// CALLBACKs that call the ADD_ALL function to make the component

void pm_gui::PM_ACM_addHead_cb(Fl_Widget* w, void* v) {
	((pm_gui*)v)->PM_ACM_addHead_cb_i();	
}
void pm_gui::PM_ACM_addHead_cb_i() {
	PM_ACM->hide();
	ADD_ALL_func("head");
}

void pm_gui::PM_ACM_addArm_cb(Fl_Widget* w, void* v) {
	((pm_gui*)v)->PM_ACM_addArm_cb_i();	
}
void pm_gui::PM_ACM_addArm_cb_i() {
	PM_ACM->hide();
	ADD_ALL_func("arm");	
}

void pm_gui::PM_ACM_addTorso_cb(Fl_Widget* w, void* v) {
	((pm_gui*)v)->PM_ACM_addTorso_cb_i();		
}
void pm_gui::PM_ACM_addTorso_cb_i() {
	ADD_ALL_func("torso");
	PM_ACM->hide();
}

void pm_gui::PM_ACM_addBattery_cb(Fl_Widget* w, void* v) {
	((pm_gui*)v)->PM_ACM_addBattery_cb_i();	
}
void pm_gui::PM_ACM_addBattery_cb_i() {
	ADD_ALL_func("battery");
	PM_ACM->hide();
}

void pm_gui::PM_ACM_addLoc_cb(Fl_Widget* w, void* v) {
	((pm_gui*)v)->PM_ACM_addLoc_cb_i();	
}
void pm_gui::PM_ACM_addLoc_cb_i() {
	ADD_ALL_func("locomotor");
	PM_ACM->hide();
}

int main() {

	pm_gui* pm = new pm_gui();
	pm->show_main();
	
	return (Fl::run());
	
}
