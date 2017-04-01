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
	
	Controller();
	void show_main_window() {this->show();}
	void hide_main_window() {this->hide();}
	string person_type;
	
	private:
	
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

	// SALES ASSOCIATE (SA) Stuff
	void SA_menu_func();
	Fl_Window* SA_mainmenu_window;
	Fl_Button* SA_CRO_button; // CRO = Create Robot Order
	


};

////////////////////////////////////
// Main Menu Functions, callbacks //
////////////////////////////////////

Controller::Controller():Fl_Window(500,500,"Robots'R'us") {
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
	PM_add_model_button = new Fl_Button(10, 70, 200, 50, "Add Model");
	
	
	PM_mainmenu_window->show();
	end();
	
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




Controller controller;

int main()
	
{

	
	controller.show();
	
	return(Fl::run());
	
}