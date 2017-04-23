/*#include <iostream>
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


////////////////////////////////////////
//////////  CUSTOMER MENU GUI  //////////
/////////////////////////////////////

// The main Customer menu
void Controller::CU_menu_func() {


        hide_main_window();
        CU_menu_win = new Fl_Window(500,500,"Customer");

        CU_order_button = new Fl_Button(10,10,200,50,"Create Order");
        CU_order_button->callback(CU_order_button_cb, this);

        CU_menu_back_button = new Fl_Button(10,400,100,50,"Back");
        CU_menu_back_button->callback(CU_menu_back_button_cb, this);

        CU_menu_catalog_button = new Fl_Button(10,100,200,50,"View Model Catalog");
        

*/
/*******************************/

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <stdlib.h>
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
    return(Fl::run());
}
    

