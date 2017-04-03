#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <cstdlib>                   //for exit(0)
#include <string.h>
#include <iostream>
using namespace std;

void Add_cb( Fl_Widget* , void* );  //function prototypes
void Back_cb( Fl_Widget* , void* );
void make_window();

int main() {

   make_window();
//   std::cout <<"you added something";

   return Fl::run();
}


void make_window() {
 
   Fl_Window* win= new Fl_Window(500,500, "Arm");
   //Arm_Box = new Fl_Box(20,10,460,50,"Create Arm");

   win->begin();      
      Fl_Button*  Add = new Fl_Button( 10, 450, 70, 30, "&Add"); //child 0   : 1st widget
      //std::cout <<"you added something" << &Add << endl;
      Fl_Button* Back = new Fl_Button(400, 450, 70, 30, "&Back"); //child 1    : 2nd widget
      Fl_Input*  Name = new Fl_Input(110, 100, 250, 30, "&Name"); //child 2 : 3rd widget
      Fl_Input*  Model_Number= new Fl_Input(110, 150, 250, 30, "M&odel Number"); //child 3 : 4th widget
      Fl_Input*  Cost = new Fl_Input(110, 200, 250, 30, "&Cost"); //child 4 : 5th widget
      Fl_Input*  Description = new Fl_Input(110, 250, 250, 30, "&Description"); //child 5 : 3rd widget
      Fl_Input*  Image = new Fl_Input(110, 300, 250, 30, "&Image"); //child 6 : 5th widget
      Fl_Input*  Max_Power = new Fl_Input(110, 350, 250, 30, "&Max Power"); //child 7 : 6th widget
     // Fl_Output* out = new Fl_Output(50, 100, 140, 30, "Out");     //child 3   : 4th widget
   win->end();
   Add->callback(  Add_cb );
   Back->callback( Back_cb );
   win->show();
 }


void Add_cb( Fl_Widget* o , void* ) {
  string Name, Model_Number, Cost_s, Description, Image, Max_Power_s;
  double Cost, Max_Power;

   Fl_Button* b=(Fl_Button*)o;
   Fl_Input* iw = (Fl_Input*) b -> parent() -> child(2); //name
   
   Fl_Input* iw1 = (Fl_Input*) b -> parent() -> child(3); //model_number
   Fl_Input* iw2 = (Fl_Input*) b -> parent() -> child(4); //cost
   Fl_Input* iw3 = (Fl_Input*) b -> parent() -> child(5); //description
   Fl_Input* iw4= (Fl_Input*) b -> parent() -> child(6); //image
   Fl_Input* iw5= (Fl_Input*) b -> parent() -> child(7); //max_power
   Name = iw->value();
   Model_Number = iw1->value();
   Cost_s =(string) iw2->value();
   Cost = std::stod(Cost_s);
   Description = iw3->value();
   Image = iw4->value();
   Max_Power_s =(string) iw5->value();
   Max_Power = std::stod(Max_Power_s);
   //  Arm temp (Name, Model_Number, Description, Image, Cost, Weight, Power);
   std::cout<< Name << ' ' << Model_Number << ' ' << Cost << ' ' << Description << ' ' << Image << ' ' << Max_Power << endl;
   //Fl_Output* ow = (Fl_Output*) b -> parent() -> child(3);
   // ow->value( iw->value() );
}


void Back_cb( Fl_Widget* o, void*) {

   exit(0);
}

