#include <iostream>
#include <FL/Fl_Window.H>
#include <FL/Fl.H> 
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Button.H>
#include <vector>
#include <Fl/Fl_Box.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include "Controller.h"
//Ab
using namespace std;
//okgolsha
void Controller::view_catalog_func() {
	fl_register_images();
	
	vector<string> model_names;
	model_names.push_back("Model 1");
	model_names.push_back("Model 2");
	model_names.push_back("Model 3");
	model_names.push_back("Model 4");
	model_names.push_back("Model 5");
	model_names.push_back("Model 6");
	model_names.push_back("Model 7");
	model_names.push_back("Model 8");
	model_names.push_back("Model 9");
	model_names.push_back("Model 10");
	string image_address = "robot.jpg";
	
	Fl_Window* win = new Fl_Window(500,500,"Catalogue");
	Fl_Scroll* scroll = new Fl_Scroll(0,0,500,500);
	
	int x_pos = 325;
	int y_pos = 40;
	
	for (int i = 0; i < model_names.size(); i++)
	{
		
		Fl_Box* name_box = new Fl_Box(20,y_pos,200,35,model_names[i].c_str());
		
		Fl_Box* box = new Fl_Box(x_pos,y_pos,100,100);
		Fl_JPEG_Image* jpg = new Fl_JPEG_Image("robot.jpg");
		box->image(*jpg);
		y_pos+=130;
		
	}
	
	scroll->show();
	scroll->end();
	
	
	win->end();
	win->show();
	

	
}

