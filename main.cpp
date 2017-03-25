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
  Arm(string, int, string, string, double, double,double);
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
  


//Class Robot Head

class Head:public Robot_Part
{

private:
  double power;
public:
  Head();
  Head(string, int, string, string, double, double,double);

  double Getpower();

};

Head::Head()
:Robot_Part() 
{
   power = 0;
}

Head::Head(string in_name,int in_model_number,string in_description,
         string in_image_filename, double in_cost,double in_weight, double in_max_power)
  :Robot_Part(in_name,
        in_model_number,in_description,
        in_image_filename, in_cost,
        in_weight)
{
  power = in_max_power;
}

double Head::Getpower() {return power;}


//Battery class

class Battery:public Robot_Part
{
private:
  double power_available;
  double max_energy;
public:
  Battery();
  Battery(string, int,string,
         string, double,double, double, double);

  double get_power();
  double get_max_energy();
};

Battery::Battery()
:Robot_Part() 
{
  power_available = 0.0;
  max_energy = 0.0;
}
Battery::Battery(string in_name,int in_model_number,string in_description,
         string in_image_filename, double in_cost,double in_weight, double in_power_available, double in_max_energy)
  :Robot_Part(in_name,
        in_model_number,in_description,
        in_image_filename, in_cost,
        in_weight)
{
  power_available = in_power_available;
  max_energy = in_max_energy;
  
}
double Battery::get_power() {return power_available;}
double Battery::get_max_energy() {return max_energy;}



int main(void)
{

  return 0;
}

