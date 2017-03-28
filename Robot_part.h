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
  /******** Virtual Functions ********/
  virtual int    Type()=0;
  virtual double get_max_power_Arm() { return 0;}
  virtual int get_max_arms(){return 0; }
  virtual int get_battery_compartments() { return 0;}
  virtual double get_max_power(){return 0; }
  virtual double get_max_speed() { return 0;}
  virtual double Getpower() {return 0; }
  virtual double get_power() {return 0; }
  virtual double get_max_energy() {return 0;}
  
 
};

#endif