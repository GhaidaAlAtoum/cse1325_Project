#ifndef ROBOT_PART_H
#define ROBOT_PART_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;


// Robot Class and all its Functions

class Robot_Part
{
protected:
  string name;
  int model_number;
  double cost;
  string description;
  string image_filename;
  double weight;
  
public:

  Robot_Part();
  Robot_Part(string, int, string, string, double, double);
  double get_cost();
  double get_shipping_price();
  string get_image_filename();
  string get_part_description();
  string get_part_name();
  int    get_part_number();
  
};

#endif