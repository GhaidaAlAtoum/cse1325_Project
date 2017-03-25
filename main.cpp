#include <iostream>
#include <stdlib.h>
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
  string get_image_filename();
  double get_shipping_price();
  
};

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

double Robot_Part::get_cost() {return cost;}
double Robot_Part::get_shipping_price() {return (weight * 1.8);}
string Robot_Part::get_image_filename() {return image_filename;}

// Robot Arm Class

class Arm:public Robot_Part
{

private:
  double max_power;
public:
  Arm();
  Arm(string, int, string, string, double, double, double);
  double get_max_power();

};

Arm::Arm()
:Robot_Part() 
{
  max_power = 0;
}

Arm::Arm(string in_name,int in_model_number,string in_description,
	 string in_image_filename, double in_cost,double in_weight, double in_max_power)
  :Robot_Part(in_name,
        in_model_number,in_description,
	in_image_filename, in_cost,
	in_weight)
{
  max_power = in_max_power;
}

double Arm::get_max_power() {return max_power;}

// Torso Class

class Torso:public Robot_Part
{
private:
  int battery_compartments;
  int max_arms;
public:
  int get_battery_compartments();
  int get_max_arms();
  Torso();
  Torso(string, int, string, string, double, double, int, int);
  

};

Torso::Torso():Robot_Part()
{

  battery_compartments = 0;
  max_arms = 0;

}

Torso::Torso(string in_name,
	     int in_model_number, string in_description,
	     string in_image_filename, double in_cost,
	     double in_weight, int in_max_arms,
	     int in_battery_compartments):Robot_Part(in_name,
		       in_model_number, in_description,
		       in_image_filename, in_cost, in_weight)
{
  battery_compartments = in_battery_compartments;
  max_arms = in_max_arms;

}
    
// Locomotor Class

class Locomotor:public Robot_Part
{
private:
  double max_power;
  double max_speed;
public:
  Locomotor();
  Locomotor(string, int, string, string, double,double, double, double);
  double get_max_speed();
  double get_max_power();
  
};

Locomotor::Locomotor()
{

  max_power = 0;
  max_speed = 0;
  
}

Locomotor::Locomotor(string in_name,
		       int in_model_number, string in_description,
		       string in_image_filename, double in_cost,
		     double in_weight, double in_max_speed,
		     double in_max_power):Robot_Part(in_name,
		     in_model_number, in_description,
		     in_image_filename, in_cost, in_weight)
{

  max_speed = in_max_speed;
  max_power = in_max_power;
  
}
				       


  
int main(void)
{

  


  return 0;
}






