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
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Menu_Bar.H>



/////////////////////////////////////////
//////BOSS MENU STUFF///////////////////
///////////////////////////////////////

void Controller::B_menu_func() {
	
	hide_main_window();
	B_menu_win = new Fl_Window(500,500,"Bossy Wossy");
	
	BOSS_create_customer = new Fl_Button(20,20,200,50,"Create Customer");
	BOSS_create_customer->callback(BOSS_create_customer_cb, this);
	BOSS_create_SA = new Fl_Button(20,90,200,50,"Create Sales Associate");
	BOSS_create_SA->callback(BOSS_create_SA_cb, this);
	BOSS_raise_stuff_b = new Fl_Button(20,160,200,50, "Stats and raises");
	BOSS_raise_stuff_b->callback(BOSS_raise_stuff_b_cb, this);
	
	BOSS_give_raise_button = new Fl_Button(20, 230, 200, 50, "Give Raise");
	BOSS_give_raise_Button->callback(BOSS_give_raise_cb, this);
	
	
	BOSS_menu_back_b = new Fl_Button(10,400,100,50,"Back");
	BOSS_menu_back_b->callback(BOSS_menu_back_b_cb, this);
	B_menu_win->show();

}



void Controller::BOSS_create_customer_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->BOSS_create_customer_cb_i();	
}
void Controller::BOSS_create_customer_cb_i() {
	B_menu_win->hide();
	BOSS_create_C_func();
}

void Controller::BOSS_create_SA_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->BOSS_create_SA_cb_i();	
}
void Controller::BOSS_create_SA_cb_i() {
	B_menu_win->hide();
	BOSS_create_SA_func();
}

void Controller::BOSS_menu_back_b_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->BOSS_menu_back_b_cb_i();
}
void Controller::BOSS_menu_back_b_cb_i() {
	B_menu_win->hide();
	raise_stuff_func();
}

void Controller::BOSS_raise_stuff_b_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->BOSS_menu_back_b_cb_i();
}
void Controller::BOSS_raise_stuff_b_cb_i() {
	B_menu_win->hide();
	raise_stuff_func();
}

// CREATE SA WINDOW

void Controller::create_SA_b_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->create_SA_b_cb_i();	
}
void Controller::create_SA_b_cb_i() {
	cout << "DO STUFF TO CREATE SA HERE!" << endl;	
	B_menu_win->show();
	create_SA_window->hide();
}

void Controller::create_SA_back_b_cb(Fl_Widget* w, void* v) {
	((Controller*)v)->create_SA_back_b_cb_i();	
}
void Controller::create_SA_back_b_cb_i() { 
	create_SA_window->hide();
	B_menu_win->show();
}

void Controller::BOSS_create_SA_func() {
	
	create_SA_window = new Fl_Window(500,500,"Create Sales Associate");
	
	new_SA_name_input = new Fl_Input(110,25,250,30,"Name ");
	new_SA_pass_input = new Fl_Input(110,75,250,30,"Password ");
	
	create_SA_b = new Fl_Button(20,450,100,40, "Create ");
	create_SA_b->callback(create_SA_b_cb, this);
	create_SA_back_b = new Fl_Button(140,450,100,40, "Back ");
	create_SA_back_b->callback(create_SA_back_b_cb, this);
	create_SA_window->show();

}

// CREATE CUSTOMER STUFF

void Controller::BOSS_create_C_func() {

	BOSS_create_c_win = new Fl_Window(500,500,"Create Customer");
	
	BOSS_CC_name_input = new Fl_Input(110,25,250,30,"Name ");
	BOSS_CC_phone_input = new Fl_Input(110,75,250,30,"Phone ");
	BOSS_CC_email_input = new Fl_Input(110,125,250,30,"Email ");
	BOSS_CC_pass_input = new Fl_Input(110,175,250,30,"Password ");
	
	BOSS_CC_button = new Fl_Button(20,450,100,40,"Create ");
	BOSS_CC_button->callback(BOSS_CC_button_cb, this);
	BOSS_CC_cancel_button = new Fl_Button(140,450,100,40,"Cancel ");
	BOSS_CC_cancel_button->callback(BOSS_CC_cancel_button_cb, this);
	
	BOSS_create_c_win->show();
	
}

void Controller::BOSS_CC_button_cb(Fl_Widget* w,void* v) {
	((Controller*)v)->BOSS_CC_button_cb_i();	
}
void Controller::BOSS_CC_button_cb_i() {
	cout << "CREATE CUSTOMER STUFF GOES HERE!" << endl;
	BOSS_create_c_win->hide();
	B_menu_win->show();
}

void Controller::BOSS_CC_cancel_button_cb(Fl_Widget* w,void* v) {
	((Controller*)v)->BOSS_CC_cancel_button_cb_i();	
}
void Controller::BOSS_CC_cancel_button_cb_i() {
	BOSS_create_c_win->hide();
	B_menu_win->show();
}


// JUNU raises and statistics and stuff

//
// Show how to change submenu names and menu item names
//    Click on Edit -> Change to change the contents of the Edit menu.
//
void Change_CB(Fl_Widget *w, void *) {
    Fl_Menu_Bar *menu = (Fl_Menu_Bar*)w;
    Fl_Menu_Item *p;
    // Change submenu name
    p = (Fl_Menu_Item*)menu->find_item("Print_shop_Status/Process");
    if ( p ) p->label("Still_Processing");
    // Change item name
    p = (Fl_Menu_Item*)menu->find_item("Print_Shop_Status/Still_Processing");
    if ( p ) p->label("Processing_Done");
}
void Default_Password_CB(Fl_Widget *, void *) 
{
    exit(0);
}

void Add_Name_CB(Fl_Widget *, void *) 
{
    exit(0);
}

//void Sales_Associate_Decision_CB(Fl_Widget *, void *) 
//{
//    exit(0);
//}

void Give_Raise_CB(Fl_Widget *, void *) 
{
    exit(0);
}

void No_Raise_CB(Fl_Widget *, void *) 
{
    exit(0);
}



void Controller::raise_stuff_func() {
    Fl_Window *win = new Fl_Window(500,200);
    Fl_Menu_Bar *menu = new Fl_Menu_Bar(0,0,600,25);
    menu->add("Hire_Sales_Associate/Default Password",FL_CTRL+'h' ,Default_Password_CB);
    menu->add("Hire_Sales_Associate/Add_Name", FL_CTRL+'a', Add_Name_CB);

   // menu->add("Check_Raise_Request/Sales_Associate_Decision", FL_CTRL+'c', Sales_Associate_Decision_CB);
    menu->add("Check_Raise_Request/Sales_Associate_Decision/Give_Raise", FL_CTRL+'G', Give_Raise_CB);   
    menu->add("Check_Raise_Request/Sales_Associate_Decision/No__Raise", FL_CTRL+'N', No_Raise_CB);
   

    

  
    menu->add("Print_Shop_Status/Still_Processing");
    menu->add("Print_Shop_Status/Processing_Done");
    win->end();
    win->show();
    
}
    
void Controller::give_raise() {

	give_raise_window = new Fl_Window(500,500,"Give Raise"
	
}














