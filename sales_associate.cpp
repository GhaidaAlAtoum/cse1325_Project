#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <cstdlib>                   //for exit(0)
#include <string.h>
#include <iostream>
using namespace std;

void Request_Raise_cb( Fl_Widget* , void* );  //function prototypes
void Back_cb( Fl_Widget* , void* );
void Process_Order_cb( Fl_Widget* , void* );


void make_window();

int main() {

   make_window();

   return Fl::run();
}


void make_window() {
 
   Fl_Window* win= new Fl_Window(300,250, "Sales Associate");

   win->begin();      
      Fl_Button*  Request_Raise = new Fl_Button( 10, 125, 120, 30, "&Request_Raise"); //child 0   : 1st widget
      Fl_Button* Back = new Fl_Button(10, 200, 70, 30, "&Back"); //child 1    : 2nd widget

      Fl_Button* Process_Order = new Fl_Button(10, 50, 120, 30, "&Process_Order"); //child 2    : 3nd widget
      
     /*
      Fl_Input*  Model_Number= new Fl_Input(160, 100, 250, 30, "M&odel Number"); //child 3 : 4th widget
      Fl_Input*  Description = new Fl_Input(160, 150, 250, 30, "&Description"); //child 5 : 3rd widget
      Fl_Input*  Image = new Fl_Input(160, 200, 250, 30, "&Image"); //child 6 : 5th widget
      Fl_Input*  Cost = new Fl_Input(160, 250, 250, 30, "&Cost"); //child 4 : 5th widget
      Fl_Input*  Weight = new Fl_Input(160, 300, 250, 30, "&Weight"); //child 8 : 7th widget
      Fl_Input*  Max_Arm = new Fl_Input(160, 350, 250, 30, "Ma&x_Arm"); //child 8 : 7th widget
      Fl_Input*  Battery_Component = new Fl_Input(160, 400, 250, 30, "&Battery_Component"); //child 8 : 7th widget
    */
   win->end();
   Request_Raise->callback(  Request_Raise_cb );
   Back->callback( Back_cb );
   Process_Order->callback( Process_Order_cb );

   win->show();
 }


void Request_Raise_cb( Fl_Widget* o , void* ) {
  string Process_Order;

   Fl_Button* b=(Fl_Button*)o;

   Fl_Input* iw = (Fl_Input*) b -> parent() -> child(2); //name
   Fl_Input* iw1 = (Fl_Input*) b -> parent() -> child(3); //model_number


   Process_Order = iw->value();       

  /* Arm temp (Name, Model_Number, Description, Image, Cost, Weight, Power);
   Arm :: Arm (string Name, string Model_Number, string Description, string Image, double Cost, double Weight, double Power){
   
   }*/

   std::cout<< Process_Order <<endl;
 

}

void Process_Order_cb( Fl_Widget* o , void* ) {
 /* string Process_Order;*/

   Fl_Button* b=(Fl_Button*)o;

   Fl_Input* iw = (Fl_Input*) b -> parent() -> child(2); //name
   Fl_Input* iw1 = (Fl_Input*) b -> parent() -> child(3); //model_number


  // Process_Order = iw->value();       

  /* Arm temp (Name, Model_Number, Description, Image, Cost, Weight, Power);
   Arm :: Arm (string Name, string Model_Number, string Description, string Image, double Cost, double Weight, double Power){
   
   }*/

//   std::cout<< Process_Order <<endl;
 

}




void Back_cb( Fl_Widget* o, void*) {

   exit(0);
}




