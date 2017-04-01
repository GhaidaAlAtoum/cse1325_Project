#include "Robot_part.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
Robot_Part::Robot_Part()
{

  name = "no name"; 
  model_number = 0;
  cost = 0.0;
  description = "no description";
  image_filename = "default.jpg";
  weight = 0.0;

}

Robot_Part::Robot_Part(string in_name,
		       int in_model_number, string in_description,
		       string in_image_filename, double in_cost, double in_weight) 
{

  name = in_name; 
  model_number = in_model_number;
  cost = in_cost;
  description = in_description;
  image_filename = in_image_filename;
  weight = in_weight;

}
int    Robot_Part::get_part_number(){return model_number;}
double Robot_Part::get_cost() {return cost;}
double Robot_Part::get_shipping_price() {return (weight * 1.8);}
double Robot_Part::get_weight(){return weight; }
string Robot_Part::get_image_filename() {return image_filename;}
string Robot_Part::get_part_name() {return name; }
string Robot_Part::get_part_description(){ return description;}







