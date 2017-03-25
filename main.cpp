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
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// First Take information then instance 
class Robot_Modle 
{
	private:  
	     string    modle_name ="No_Name";
	     int       modle_number=0;
	     vector<Torso>     modle_Torso;
	     vector<Head>      modle_Head;
	     vector<Locomotor> modle_Locomotor;
	     vector<Battery> modle_Battry;
	     vector<Arm> modle_Arm;

	public:
	      Robot_Modle();
	      Robot_Modle(string,int);
	      string Get_modle_name ()   { return modle_name; }
	      int    Get_modle_number () { return modle_number ;}
          bool   add_Torso(Torso);
	      bool   add_Head(Head);
	      bool   add_Locomotor(Locomotor);
	      void   add_Battery(Battery);
	      bool   add_Arm(Arm);
	      int    Get_Torso_Bat_Comp();
	      int    Get_Torso_Max_arms();
	      double Get_Locmotor_max_speed();
	      double Get_Locomotor_max_power();
	      int    Get_Head_power();
	      vector<int> Get_Arms_power() ;
	      int    Get_number_of_Arms() { return model_Arm.size();}
	      int    Get_number_of_Batteries(){ return model_Battery.size();}
	      double Get_Model_Cost();
};

Robot_Modle::Robot_Modle() {}
Robot_Modle::Robot_Modle(string in_name , int in_num){
           modle_name = in_name;
	       modle_number = in_num;
}
bool Robot_Modle::add_Torso(Torso in_Torso){
	if(modle_Torso.size()==0) {
	     modle_Torso.push_back(in_Torso);
		return 1;
	 }
	else {
	     return 0;
	}
	
}
bool Robot_Modle::add_Head(Head in_Head){
		if(modle_Head.size()==0) {
	     modle_Head.push_back(in_Head);
		return 1;
	 }
	else {
	     return 0;
	}
	
}
bool Robot_Modle::add_Locomotor(Locomotor in_Locomotor){
		if(modle_Locomotor.size()==0) {
	     modle_Locomotor.push_back(in_Locomotor);
		return 1;
	 }
	else {
	     return 0;
	}
	
}
void Robot_Modle::add_Battery(Battery in_Battery){
	modle_Battry.push_back(in_Battery);
		}
bool Robot_Modle::add_Arm(Arm in_Arm){
	if(modle_Arm.size()<=2) {
	     modle_Arm.push_back(in_Arm);
		return 1;
	 }
	else {
	     return 0;
	}
}
int  Robot_Modle::Get_Torso_Bat_Comp () {
	if(model_Torso.size()!=0) 
		return modle_Torso[0].get_battery_comparments();
    else
        return 0;}
int    Robot_Modle::Get_Torso_Max_arms() { 
	if(model_Torso.size()!=0)
	return  modle_Torso[0].get_max_arms (); 
	else
		return 0;
} 	
double Robot_Modle::Get_Locmotor_max_speed() {
	if(model_Locomotor.size()!=0)
	return  modle_Locomotor[0].get_max_spedd();
	else 
		return 0;
}
double Robot_Modle::Get_Locomotor_max_power() { 
	if(model_Locomotor.size()!=0)
	return  modle_Locomotor[0].get_max_power();
	else
		return 0;
}
int    Robot_Modle::Get_Head_power() {
	if(model_Head.size()!=0)
	return modle_Head[0].Getpower();
	else
		return 0;
}
vector<int> Robot_Modle::Get_Arms_power() {
    vector <int> power ;
	if(model_Arrm.size()!=0){
	 for( auto & num : model_Arm ){
	     num.get_max_power();
		 power.push_back(num);
	 } //end for
	} //end if
	   return power;
}
double Robot_Modle::Get_Model_Cost(){
    double cost=0.0;
	if(model_Arrm.size()!=0){
	 for( auto & num : model_Arm ){
	     cost += num.get_cost();
	 } 
	} 
	if(modle_Battry.size()!=0){
	 for( auto & num : modle_Battry ){
	     cost += num.get_cost();
	 } 
	} 
	cost += modle_Torso.get_cost();
	cost += modle_Head.get_cost();
	cost += modle_Locomotor.get_cost();
	
	return cost;
}

int main(void)
{

  return 0;
}

