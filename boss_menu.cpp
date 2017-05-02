
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
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Menu_Bar.H>
#include "boss_menu.h"
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Text_Display.H>

using namespace std;

///////////////////////////////////
//////BOSS MENU STUFF///////////////////
///////////////////////////////////////

void boss_menu::B_menu_func() {
	
//hide_main_window();
	B_menu_win = new Fl_Window(500,500,"Bossy Wossy");
	
	fl_register_images();
	jpg = new Fl_JPEG_Image("backgroundwhite500.jpg");
	main_background = new Fl_Box(0,0,500,500);
	main_background->image(*jpg);
	
	BOSS_create_SA = new Fl_Button(150,70,200,50,"Create SA");
	BOSS_create_SA->color(FL_WHITE);
	BOSS_create_SA->labelsize(20);
	BOSS_create_SA->callback(BOSS_create_SA_cb, this);
	
	BOSS_raise_stuff_b = new Fl_Button(150,130,200,50, "Stats and raises");
	BOSS_raise_stuff_b->color(FL_WHITE);
	BOSS_raise_stuff_b->labelsize(20);
	BOSS_raise_stuff_b->callback(stats_callback, this);

	
	BOSS_give_raise_button = new Fl_Button(150, 190, 200, 50, "Give Raise");
	BOSS_give_raise_button->color(FL_WHITE);
	BOSS_give_raise_button->labelsize(20);
	BOSS_give_raise_button->callback(BOSS_give_raise_cb, this);
	
	
	BOSS_menu_back_b = new Fl_Button(150,400,200,50,"Back");
	BOSS_menu_back_b->color(FL_WHITE);
	BOSS_menu_back_b->labelsize(20);
	BOSS_menu_back_b->callback(BOSS_menu_back_b_cb, this);
	B_menu_win->show();

}

void boss_menu::BOSS_give_raise_cb(Fl_Widget* w, void* v) {
((boss_menu*)v)->BOSS_give_raise_cb_i();
}
void boss_menu::BOSS_give_raise_cb_i() {
	B_menu_win->hide();
	give_raise_func();
}

void boss_menu::stats_callback(Fl_Widget* w, void* v) {
	((boss_menu*)v)->stats_callback_i();	
	cout << "this called " << endl;
}
void boss_menu::stats_callback_i() {
	stats_win = new Fl_Window(500,500,"Stats");
	fl_register_images();
	jpg = new Fl_JPEG_Image("backgroundwhite500.jpg");
	main_background = new Fl_Box(0,0,500,500);
	main_background->image(*jpg);
	
	// Can get some statistics like sales numbers, etc, and put them into some vars
	int num_sales;
	int other_thing;
	int other_otherthing;
	// And now display them
	string display1 = "Num of sales: " + num_sales;
	const char* display1C = display1.c_str();
	string display2 = "Other: " + other_thing;
	string display3 = "Other: " + other_otherthing;
	
	d1 = new Fl_Text_Display(20,20,300,50, display1C);
	d1->show();
	
	
	back_from_stats = new Fl_Button(10,440,200,50, "Back");
	back_from_stats->color(FL_WHITE);
	stats_win->show();
	
}


void boss_menu::BOSS_create_SA_cb(Fl_Widget* w, void* v) {
((boss_menu*)v)->BOSS_create_SA_cb_i();
cout << "callback for creating SA" << endl;
}
void boss_menu::BOSS_create_SA_cb_i() {
	B_menu_win->hide();
	BOSS_create_SA_func();
}

void boss_menu::BOSS_menu_back_b_cb(Fl_Widget* w, void* v) {
((boss_menu*)v)->BOSS_menu_back_b_cb_i();

}
void boss_menu::BOSS_menu_back_b_cb_i() {
	
	///////////////////////////////////
	//GHAIDA GHAIDA////////////////////
	/////////////////////////////////
	// Right here goes the code that returns to the Main Menu
	B_menu_win->hide();
	//raise_stuff_func();
}


// CREATE SA WINDOW

void boss_menu::create_SA_b_cb(Fl_Widget* w, void* v) {
((boss_menu*)v)->create_SA_b_cb_i();

}
void boss_menu::create_SA_b_cb_i() {
	B_menu_win->show();
	create_SA_window->hide();
	
	///////////////////////////
	//GHAIDA///////////////////
	///////////////////////////
	// RIght here a SA should be made. You can
	// get the new password and name with what is shown below:
	
	cout << new_SA_name_input->value() << endl;
	cout << new_SA_pass_input->value() << endl;
	
	
}

void boss_menu::create_SA_back_b_cb(Fl_Widget* w, void* v) {
((boss_menu*)v)->create_SA_back_b_cb_i();
cout << "callback for going back" << endl;
}
void boss_menu::create_SA_back_b_cb_i() { 
	create_SA_window->hide();
	B_menu_win->show();
}

void boss_menu::BOSS_create_SA_func() {
	
	create_SA_window = new Fl_Window(500,500,"Create Sales Associate");
	
	fl_register_images();
	jpg = new Fl_JPEG_Image("backgroundwhite500.jpg");
	main_background = new Fl_Box(0,0,500,500);
	main_background->image(*jpg);
	
	new_SA_name_input = new Fl_Input(110,25,250,30,"Name ");
	new_SA_pass_input = new Fl_Input(110,75,250,30,"Password ");
	
	create_SA_b = new Fl_Button(20,450,100,40, "Create ");
	create_SA_b->callback(create_SA_b_cb, this);
	create_SA_b->color(FL_WHITE);
	create_SA_back_b = new Fl_Button(140,450,100,40, "Back ");
	create_SA_back_b->callback(create_SA_back_b_cb, this);
	create_SA_back_b->color(FL_WHITE);
	
	create_SA_window->show();

}
    
// Window for giving raises

void boss_menu::give_raise_func() {

	give_raise_window = new Fl_Window(500,500,"Give Raise");
							
	fl_register_images();
	jpg = new Fl_JPEG_Image("backgroundwhite500.jpg");
	main_background = new Fl_Box(0,0,500,500);
	main_background->image(*jpg);
	
    give_raise_back = new Fl_Button(30,425,200,50,"Back");
	give_raise_back->callback(give_raise_back_cb, this);
	give_raise_back->color(FL_WHITE);
	
	give_raise_enter = new Fl_Button(390,405,70,40,"Enter");
	give_raise_enter->callback(give_raise_enter_cb, this);
	give_raise_enter->color(FL_WHITE);
	
	give_raise_info = new Fl_Button(390,455,70,40,"Info");
	give_raise_info->callback(give_raise_info_cb, this);
	give_raise_info->color(FL_WHITE);
	
	give_raise_index = new Fl_Int_Input(280,430, 70,40,"Index");
	
	
	// Text box at top
	
	/////////////////////////////
	//GHAIDA/?///////////////////
	/////////////////////////////
	/////////////////////////////
	// Right below is where the list of SA's 
	// to give a raise to goes
	
	SA_list = new Fl_Multiline_Output(0,0,500,400);
	string SAs = "SA 1\nSA 2\nSA 3";
	const char* out_SAs = SAs.c_str();
	SA_list->value(out_SAs);
	
	
	give_raise_window->show();					  
	
}

void boss_menu::give_raise_back_cb(Fl_Widget* w, void* v) {
  ((boss_menu*)v)->give_raise_back_callback_i();
}
void boss_menu::give_raise_back_callback_i() {
	give_raise_window->hide();
	B_menu_win->show();
}

void boss_menu::give_raise_enter_cb(Fl_Widget* w, void* v) {
  ((boss_menu*)v)->give_raise_enter_callback_i();
}
void boss_menu::give_raise_enter_callback_i() {
	give_raise_window->hide();					  //	
	B_menu_win->show();                ///////////
	///////////////////////////////////////////o/
  /////GHAIDAN//GHAIDAN//GHAIDAN/////////////////
	///////////////////////////////////////////
	//  //  //  //  //  //  //  //  //  //
	// Right here, you give a raise to a certain SA.
	// You get the index of that SA with: give_raise_index->value();
	cout << give_raise_index->value() << endl;
	
}

void boss_menu::give_raise_info_cb(Fl_Widget* w, void* v) {
  ((boss_menu*)v)->give_raise_info_callback_i();
   
}
void boss_menu::give_raise_info_callback_i() {
		give_raise_info_win = new Fl_Window(400,200,"Order Info");
	
		//////////////////////////
		///GHAIDA/////////////////
		///GHAIDA/////////////////
		//////////////////////////
		// This is where info about an SA is printed
		// So that the boss can decide to give a raise or not.
		
		
		// You can put a string to display the info into a box 
		// using the code below
		string temp_info = "This will have some information about the SA \nBut in the meantime it says you are cool";
		const char* temp_info_2 = temp_info.c_str();
		order_info_box = new Fl_Multiline_Output(0,0,400,200);
		order_info_box->value(temp_info_2);
		give_raise_info_win->show();
}



/*
void boss_menu::show_window() {main_window->show();}
void boss_menu::hide_window() {main_window->hide();}
	
*/
int main(){
	boss_menu Boss;
	Boss.B_menu_func();
	
	
	
		
return Fl::run();	
}







