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
  /******** Pure Virtual Functions ********/
  virtual double get_max_power_Arm() { return 0;}
  virtual int get_max_arms(){return 0; }
  virtual int get_battery_compartments() { return 0;}
  virtual double get_max_power(){return 0; }
  virtual double get_max_speed() { return 0;}
  virtual double Getpower() {return 0; }
  virtual double get_power() {return 0; }
  virtual double get_max_energy() {return 0; }
  /* So you would be able to point to whatever component using Robot_part and
     still be able to call each component function using that Robot_part [reference / pointer] */
 /* check the following three videos :
   (1)https://www.youtube.com/watch?v=R_PPA9eejDw&index=55&list=PLAE85DE8440AA6B83
   (2)https://www.youtube.com/watch?v=DudHooleNVg&list=PLAE85DE8440AA6B83&index=56
   (3)https://www.youtube.com/watch?v=ndz3EHpFEZc&list=PLAE85DE8440AA6B83&index=57
   
   AND check in Main how I tested it on T1*/
};

#endif