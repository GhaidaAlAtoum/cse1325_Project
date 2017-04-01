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

// This is a test class to make sure that I can access shop and stuff from within the gui stuff.
// Test-Run with: g++ -std=c++11 gui_beginnings.cpp -lfltk -o gui_beginnings.out


class Test
{

	public:
	int num = 7;
	void print_num() {cout << "The number is: " << num << endl;}
	
};

bool authenticate_user(string username, string password, string person_type) {
	// Here goes the stuff for checking the username and password
	cout << person_type << endl;
	return true;
}


	
class Controller: public Fl_Window
{
	
	public:
	
	
	Controller(Test&); 
	void show_main_window() {this->show();}
	void hide_main_window() {this->hide();}
	string person_type;
	
	private:
	
	// Contained classes;
	
	Test test;
	
	
	
	
	
	// MAIN MENU
	Fl_Button* main_button1; // Authenticates PW for Manager, then his menu	
	Fl_Button* main_button2; // sth else
	
	
	// MAIN Menu CALLBACKS
	static void main_b1_cb(Fl_Widget*, void*);
	inline void main_b1_cb_i();
	static void main_b2_cb(Fl_Widget*, void*);
	inline void main_b2_cb_i();
	
	// UNPW MENU // UNPW = UserName PassWord
	
	void unpw_menu_func();
	
	static void unpw_login_cb(Fl_Widget*, void*);
	inline void unpw_login_cb_i();
	static void unpw_cancel_cb(Fl_Widget*, void*);
	inline void unpw_cancel_cb_i();
	
	const char* username;
	const char* password;
	
	Fl_Window* unpw_menu_window;
	Fl_Input* username_input;
	Fl_Input* password_input;
	
	// PM Menu Stuff
	
	void PM_menu_func();
	//void PM_menu_show();
	//void PM_menu_hide();
	Fl_Window* PM_mainmenu_window;
	Fl_Button* PM_add_component_button;
	Fl_Button* PM_add_model_button;
	
	void PM_add_component_menu();
	static void PM_add_component_button_cb(Fl_Widget*, void*);
	inline void PM_add_component_button_cb_i();	
	
	Fl_Window* PM_ACM; // ACM = ADD COMPONENT MENU
	Fl_Button* PM_ACM_addHead;
	Fl_Button* PM_ACM_addArm;
	Fl_Button* PM_ACM_addTorso;
	Fl_Button* PM_ACM_add_battery;
	Fl_Button* PM_ACM_add_locomotor;
	
	// Add head menu
	
	void PM_AHM_func();
	
	Fl_Window* PM_AHM_window;
	Fl_Input* PM_AHM_name_input;
	Fl_Input* PM_AHM_cost_input;
	Fl_Input* PM_AHM_description_input;
	Fl_Input* PM_AHM_image_input;
	Fl_Input* PM_AHM_weight_input;
	Fl_Input* PM_AHM_power_input;
	Fl_Button* PM_AHM_create_button;
	
	static void PM_ACM_addhead_cb(Fl_Widget*, void*);
	inline void PM_ACM_addhead_cb_i();
	static void PM_AHM_create_button_cb(Fl_Widget*,void*);
	inline void PM_AHM_create_button_cb_i();
	
	
	// SA MENU
	void SA_menu_func();
	
	Fl_Window* SA_mainmenu_window;
	Fl_Button* SA_CRO_button; // 
	
};

////////////////////////////////////
// Main Menu Functions, callbacks //
////////////////////////////////////

Controller::Controller(Test &in_test):Fl_Window(500,500,"Robots'R'us") {
	
	test = in_test;
	
	begin();
		main_button1 = new Fl_Button(20,20,200,50,"Parts Manager");
		main_button1->callback(main_b1_cb, this);
	
		main_button2 = new Fl_Button(20,90,200,50,"Sales Associate");
		main_button2->callback(main_b2_cb, this);
	end();
}
		
void Controller::main_b1_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->main_b1_cb_i();
}
void Controller::main_b1_cb_i() {
	unpw_menu_func();
	person_type = "PM";
}

void Controller::main_b2_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->main_b2_cb_i();
}
void Controller::main_b2_cb_i() {
	unpw_menu_func();
	person_type = "SA";
}

/////////////////////////////////////////
// Password menu functions, callbacks //
///////////////////////////////////////

void Controller::unpw_menu_func() {
	
	unpw_menu_window = new Fl_Window(400,250,"Authenticate User");
	
	username_input = new Fl_Input(100,20,100,20,"Username:");
	password_input = new Fl_Input(100,50,100,20,"Password:");
	
	
	Fl_Button* login = new Fl_Button(100,220,40,20,"Log in");
	login->callback(unpw_login_cb, this);
	Fl_Button* cancel = new Fl_Button(160,220,40,20,"Cancel");
	cancel->callback(unpw_cancel_cb, this);
	
	
	end();
	unpw_menu_window->show();
}
	
	
void Controller::unpw_login_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->unpw_login_cb_i();
}
void Controller::unpw_login_cb_i() {
	
	const char* temp_username = username_input->value();
	std::string username(temp_username);
	const char* temp_password = password_input->value();
	std::string password(temp_password);
	
	bool user_accepted = authenticate_user(username, password, person_type);
	if (user_accepted) {
		
		unpw_menu_window->hide();
		if (person_type == "PM")
			PM_menu_func();
		else if (person_type == "SA")
			SA_menu_func();
		
	}
}


void Controller::unpw_cancel_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->unpw_cancel_cb_i();	
}
void Controller::unpw_cancel_cb_i() {
	unpw_menu_window->hide();
}



////////////////////////////
//PM_MENU///////////////////
////////////////////////////

void Controller::PM_menu_func() {
	
	hide_main_window();
	PM_mainmenu_window = new Fl_Window(500,500,"Parts Manager");
	
	PM_add_component_button = new Fl_Button(10,10,200,50,"Add Component");
	PM_add_component_button->callback(PM_add_component_button_cb, this);
	PM_add_model_button = new Fl_Button(10, 70, 200, 50, "Add Model");
	
	PM_mainmenu_window->show();
	end();
	
}

void Controller::PM_add_component_button_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->PM_add_component_button_cb_i();	
}
void Controller::PM_add_component_button_cb_i() {
		PM_add_component_menu();
}


void Controller::PM_add_component_menu() {
	PM_ACM = new Fl_Window(500,500,"Add Component");
	// ACM = ADD COMPONENT MENU
	
	PM_ACM_addHead = new Fl_Button(10,10,200,50,"Add Head");
	PM_ACM_addHead->callback(PM_ACM_addhead_cb, this);
	PM_ACM_addArm = new Fl_Button(10,70,200,50,"Add Arm");
	PM_ACM_addTorso = new Fl_Button(10,130,200,50,"Add Torso");
	PM_ACM_add_battery = new Fl_Button(10,190,200,50,"Add Battery");
	PM_ACM_add_locomotor = new Fl_Button(10,250,200,50,"Add Locomotor");
	
	PM_ACM->show();
										 
	
}

//////////////////////
//ADD HEAD/////
//////////////////

void Controller::PM_ACM_addhead_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->PM_ACM_addhead_cb_i();	
}
void Controller::PM_ACM_addhead_cb_i() {
	PM_AHM_func();		
}

void Controller::PM_AHM_create_button_cb(Fl_Widget* w, void* v) {
		((Controller*)v)->PM_AHM_create_button_cb_i();
}
void Controller::PM_AHM_create_button_cb_i() {
	cout << "Do stuff here to make component class" << endl;		
}




void Controller::PM_AHM_func() {
	// AHM == ADD HEAD MENU
	
	PM_AHM_window = new Fl_Window(500,500,"Add Head");
	
	// name cost description image weight power
	PM_AHM_name_input = new Fl_Input(70,10,200,50,"Name: ");
	PM_AHM_cost_input = new Fl_Input(70,70,200,50,"Cost: ");
	PM_AHM_description_input = new Fl_Input(70,130,200,50,"Description: ");
	PM_AHM_image_input = new Fl_Input(70,190,200,50,"Image: ");
	PM_AHM_weight_input = new Fl_Input(70,250,200,50,"Weight: ");
	PM_AHM_power_input = new Fl_Input(70,310,200,50,"Power: ");
	PM_AHM_create_button = new Fl_Button(70,380,200,50,"Create");
	PM_AHM_create_button->callback(PM_AHM_create_button_cb, this);
	
	
	PM_AHM_window->show();
	
}



/////////////////////////////
////SA MENU//////////////////
/////////////////////////////

void Controller::SA_menu_func() {

	hide_main_window();

	SA_mainmenu_window = new Fl_Window(500,500, "Sales Associate Menu");
	
	SA_CRO_button = new Fl_Button(10,10,200,50, "Create a robot order");
	
	
	SA_mainmenu_window->show();
}



// Create Head



// Create Arm

// Create Torso





int main()
	
{

	
	
	Test test;
	
	Controller controller(test);
	
	controller.show();
	
	cout << "Final Test: " << test.num << endl;
	
	return(Fl::run());
	
}