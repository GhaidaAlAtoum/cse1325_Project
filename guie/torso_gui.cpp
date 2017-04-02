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

   return Fl::run();
}


void make_window() {
 
   Fl_Window* win= new Fl_Window(500,500, "Torso");

   win->begin();      
      Fl_Button*  Add = new Fl_Button( 10, 450, 70, 30, "&Add"); //child 0   : 1st widget
      Fl_Button* Back = new Fl_Button(400, 450, 70, 30, "&Back"); //child 1    : 2nd widget

      Fl_Input*  Name = new Fl_Input(160, 50, 250, 30, "&Name"); //child 2 : 3rd widget
      Fl_Input*  Model_Number= new Fl_Input(160, 100, 250, 30, "M&odel Number"); //child 3 : 4th widget
      Fl_Input*  Description = new Fl_Input(160, 150, 250, 30, "&Description"); //child 5 : 3rd widget
      Fl_Input*  Image = new Fl_Input(160, 200, 250, 30, "&Image"); //child 6 : 5th widget
      Fl_Input*  Cost = new Fl_Input(160, 250, 250, 30, "&Cost"); //child 4 : 5th widget
      Fl_Input*  Weight = new Fl_Input(160, 300, 250, 30, "&Weight"); //child 8 : 7th widget
      Fl_Input*  Max_Arm = new Fl_Input(160, 350, 250, 30, "Ma&x_Arm"); //child 8 : 7th widget
      Fl_Input*  Battery_Component = new Fl_Input(160, 400, 250, 30, "&Battery_Component"); //child 8 : 7th widget

   win->end();
   Add->callback(  Add_cb );
   Back->callback( Back_cb );
   win->show();
 }


void Add_cb( Fl_Widget* o , void* ) {
  string Name, Model_Number, Description, Image, Cost_s, Weight_s, Max_Arms_s, Battery_Components_s;
  double Cost, Weight;
  int Max_Arms, Battery_Components;

   Fl_Button* b=(Fl_Button*)o;

   Fl_Input* iw = (Fl_Input*) b -> parent() -> child(2); //name
   Fl_Input* iw1 = (Fl_Input*) b -> parent() -> child(3); //model_number
   Fl_Input* iw2 = (Fl_Input*) b -> parent() -> child(4); //cost
   Fl_Input* iw3 = (Fl_Input*) b -> parent() -> child(5); //description
   Fl_Input* iw4= (Fl_Input*) b -> parent() -> child(6); //image
   Fl_Input* iw5= (Fl_Input*) b -> parent() -> child(7); //max_power
   Fl_Input* iw6= (Fl_Input*) b -> parent() -> child(8); //weight
   Fl_Input* iw7= (Fl_Input*) b -> parent() -> child(9); //max_power
   Fl_Input* iw8= (Fl_Input*) b -> parent() -> child(10);


   Name = iw->value();
   Model_Number = iw1->value();
   Description = iw2->value();
   Image = iw3->value();

   Cost_s =(string) iw4->value();
   Cost = std::stod(Cost_s);

   Weight_s =(string) iw5->value();
   Weight = std::stod(Weight_s);

   Max_Arms_s =(string) iw6->value();
   Max_Arms = std::stoi(Max_Arms_s);

   Battery_Components_s =(string) iw7->value();
   Battery_Components = std::stoi(Battery_Components_s);
       

  /* Arm temp (Name, Model_Number, Description, Image, Cost, Weight, Power);
   Arm :: Arm (string Name, string Model_Number, string Description, string Image, double Cost, double Weight, double Power){
   
   }*/
   std::cout<< Name << ' ' << Model_Number << ' ' << Description << ' ' << Image << ' ' << Cost << ' ' << Weight << ' ' << Max_Arms << ' ' << Battery_Components <<endl;
 

}


void Back_cb( Fl_Widget* o, void*) {

   exit(0);
}


