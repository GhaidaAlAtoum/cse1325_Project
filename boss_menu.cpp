
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

using namespace std;

///////////////////////////////////
//////BOSS MENU STUFF///////////////////
///////////////////////////////////////

void boss_menu::B_menu_func() {
	
//hide_main_window();
	B_menu_win = new Fl_Window(500,500,"Bossy Wossy");
	
	BOSS_create_customer = new Fl_Button(20,20,200,50,"Create Customer");
	BOSS_create_customer->callback(BOSS_create_customer_cb, this);
	BOSS_create_SA = new Fl_Button(20,90,200,50,"Create Sales Associate");
	BOSS_create_SA->callback(BOSS_create_SA_cb, this);
	BOSS_raise_stuff_b = new Fl_Button(20,160,200,50, "Stats and raises");
	BOSS_raise_stuff_b->callback(BOSS_raise_stuff_b_cb, this);

	
	BOSS_give_raise_button = new Fl_Button(20, 230, 200, 50, "Give Raise");
	BOSS_give_raise_button->callback(BOSS_give_raise_cb, this);
	
	
	BOSS_menu_back_b = new Fl_Button(10,400,100,50,"Back");
	BOSS_menu_back_b->callback(BOSS_menu_back_b_cb, this);
	B_menu_win->show();

}

void boss_menu::BOSS_give_raise_cb(Fl_Widget* w, void* v) {
//((boss_menu*)v)->BOSS_give_raise_cb_i();
cout<< "Give raise callback" << endl;
}
void boss_menu::BOSS_give_raise_cb_i() {
	B_menu_win->hide();
	give_raise_func();
}

void boss_menu::BOSS_create_customer_cb(Fl_Widget* w, void* v) {
//((Controller*)v)->BOSS_create_customer_cb_i();
cout << "callback for boss create customer" << endl;
}
void boss_menu::BOSS_create_customer_cb_i() {
	B_menu_win->hide();
	BOSS_create_C_func();
}

void boss_menu::BOSS_create_SA_cb(Fl_Widget* w, void* v) {
//((Controller*)v)->BOSS_create_SA_cb_i();
cout << "callback for creating SA" << endl;
}
void boss_menu::BOSS_create_SA_cb_i() {
	B_menu_win->hide();
	BOSS_create_SA_func();
}

void boss_menu::BOSS_menu_back_b_cb(Fl_Widget* w, void* v) {
//((Controller*)v)->BOSS_menu_back_b_cb_i();
cout << "callback for back" << endl;
}
void boss_menu::BOSS_menu_back_b_cb_i() {
	B_menu_win->hide();
	raise_stuff_func();
}

void boss_menu::BOSS_raise_stuff_b_cb(Fl_Widget* w, void* v) {
//((Controller*)v)->BOSS_menu_back_b_cb_i();
cout << "callback for raise" << endl;
}
void boss_menu::BOSS_raise_stuff_b_cb_i() {
	B_menu_win->hide();
	raise_stuff_func();
}

// CREATE SA WINDOW

void boss_menu::create_SA_b_cb(Fl_Widget* w, void* v) {
//((Controller*)v)->create_SA_b_cb_i();
cout << "callback fo createSA" << endl;
}
void boss_menu::create_SA_b_cb_i() {
	cout << "DO STUFF TO CREATE SA HERE!" << endl;	
	B_menu_win->show();
	create_SA_window->hide();
}

void boss_menu::create_SA_back_b_cb(Fl_Widget* w, void* v) {
//((Controller*)v)->create_SA_back_b_cb_i();
cout << "callback for going back" << endl;
}
void boss_menu::create_SA_back_b_cb_i() { 
	create_SA_window->hide();
	B_menu_win->show();
}

void boss_menu::BOSS_create_SA_func() {
	
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

void boss_menu::BOSS_create_C_func() {

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

void boss_menu::BOSS_CC_button_cb(Fl_Widget* w,void* v) {
  //((Controller*)v)->BOSS_CC_button_cb_i();
    cout << "callback button boss" << endl; 
}
void boss_menu::BOSS_CC_button_cb_i() {
	cout << "CREATE CUSTOMER STUFF GOES HERE!" << endl;
	BOSS_create_c_win->hide();
	B_menu_win->show();
}

void boss_menu::BOSS_CC_cancel_button_cb(Fl_Widget* w,void* v) {
  //((Controller*)v)->BOSS_CC_cancel_button_cb_i();
  cout << "callback for calcel" << endl;
}
void boss_menu::BOSS_CC_cancel_button_cb_i() {
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



void boss_menu::raise_stuff_func() {
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
    
// Window for giving raises

void boss_menu::give_raise_func() {

	give_raise_window = new Fl_Window(500,500,"Give Raise");
								
    give_raise_back = new Fl_Button(60,450,100,40,"Back");
	give_raise_back->callback(give_raise_back_cb, this);
	
	give_raise_enter = new Fl_Button(420,450,70,40,"Enter");
	give_raise_enter->callback(give_raise_enter_cb, this);
	
	give_raise_info = new Fl_Button(420,400,70,40,"Info");
	give_raise_info->callback(give_raise_info_cb, this);
	
	give_raise_index = new Fl_Int_Input(330,450, 70,40,"Index");
	
	// Text box at top
	
	SA_list = new Fl_Multiline_Output(0,0,500,400);
	string SAs = "SA 1\nSA 2\nSA 3";
	const char* out_SAs = SAs.c_str();
	SA_list->value(out_SAs);
	
	
	give_raise_window->show();					  
	
}

void boss_menu::give_raise_back_cb(Fl_Widget* w, void* v) {
  //((Controller*)v)->give_raise_back_callback_i();
   cout << "callback for raise" << endl;
}
void boss_menu::give_raise_back_callback_i() {
	give_raise_window->hide();
	B_menu_win->show();
}

void boss_menu::give_raise_enter_cb(Fl_Widget* w, void* v) {
  //((Controller*)v)->give_raise_enter_callback_i();
   cout << "callback for raise2" << endl;
}
void boss_menu::give_raise_enter_callback_i() {
	give_raise_window->hide();
	B_menu_win->show();
	cout << "DO STUFF FOR APPROVING OR REJECTING RAISE HERE" << endl;
}

void boss_menu::give_raise_info_cb(Fl_Widget* w, void* v) {
  //((Controller*)v)->give_raise_info_callback_i();
   cout << "callback for raise info" << endl;
}
void boss_menu::give_raise_info_callback_i() {
	give_raise_window->hide();
	B_menu_win->show();
	cout << "Tis isn't right" << endl;
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







