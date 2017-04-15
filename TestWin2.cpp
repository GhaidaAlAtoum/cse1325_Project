#include <stdio.h>
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Choice.H>
#include <iostream>
using namespace std;
void ARM_CB(Fl_Widget * w, void * ){
   Fl_Choice * temp = (Fl_Choice*) w;
	cout<<"Arm Call Back \n"<<temp->value()<<endl;
	
}
void TORSO_CB(Fl_Widget * w, void * ){
   Fl_Choice * temp = (Fl_Choice*) w;
	cout<<"Torso Call Back \n"<<temp->value()<<endl;
	
}
void LOCO_CB(Fl_Widget * w, void * ){
   Fl_Choice * temp = (Fl_Choice*) w;
	cout<<"Locomotor Call Back \n"<<temp->value()<<endl;
	
}
void HEAD_CB(Fl_Widget * w, void * ){

	   Fl_Choice * temp = (Fl_Choice*) w;
	cout<<"Head Call Back \n"<<temp->value()<<endl;
}
void BATTERY_CB(Fl_Widget * w, void * ){

	   Fl_Choice * temp = (Fl_Choice*) w;
	cout<<"Battery Call Back \n"<<temp->value()<<endl;
}
int main() {
  Fl_Double_Window win(100,100,700,500,"Input Choice");
  win.begin(); 
	Fl_Choice * ME= new Fl_Choice(200,50,300,50,"&Shop Components");
	ME->textfont(11);
	ME->textcolor(136);
	ME->add("&Arm",0,ARM_CB);
	ME->add("&Torso",0,TORSO_CB);
	ME->add("&Locomotor",0,LOCO_CB );
	ME->add("&Head",0, HEAD_CB);
	ME->add("&Battery",0,BATTERY_CB );
  win.end();
  win.show();
  return Fl::run();
}

