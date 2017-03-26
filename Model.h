#ifndef model_H
#define model_H
#include "Robot_part.h"
#include "Components.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Robot_model 
{
	private:  
	     string    model_name ="No_Name";
	     string       model_number="0";
	     vector<Torso>     model_Torso;
	     vector<Head>      model_Head;
	     vector<Locomotor> model_Locomotor;
	     vector<Battery> model_Battery;
	     vector<Arm> model_Arm;

	public:
	      Robot_model();
	      Robot_model(string,string);
	      string Get_model_name ()   { return model_name; }
		  string print_model_Components();
	      string    Get_model_number () { return model_number ;}
		  int    Get_number_of_Arms() { return model_Arm.size();}
	      int    Get_number_of_Batteries(){ return model_Battery.size();}
		  int    Get_Torso_Bat_Comp();
	      int    Get_Torso_Max_arms();
		  int    Get_Head_power();
		  double Get_Locomotor_max_speed();
	      double Get_Locomotor_max_power();
		  double Get_Model_Cost();
          bool   add_Torso(Torso);
	      bool   add_Head(Head);
	      bool   add_Locomotor(Locomotor);
		  bool   add_Arm(Arm);
	      void   add_Battery(Battery);
	      vector<int> Get_Arms_power() ;

};
#endif