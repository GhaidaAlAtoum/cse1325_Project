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
#include "Controller.h"


using namespace std;

// This is a test class to make sure that I can access shop and stuff from within the gui stuff.
// Test-Run with: g++ -std=c++11 gui_beginnings.cpp -lfltk -o gui_beginnings.out

// MAIN

int main()
	
{
	
	Controller controller;	
	controller.show();
	
	return(Fl::run());
	
}