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
	     double model_Price=0.0;
	     string    model_name ="No_Name";
	     string       model_number="0";
	     vector<Torso>     model_Torso;
	     vector<Head>      model_Head;
	     vector<Locomotor> model_Locomotor;
	     vector<Battery> model_Battery;
	     vector<Arm> model_Arm;
         
	public:
	/******************* Constructor *********************/
	      Robot_model();
	      Robot_model(string,string);
	/******************* Print Model Components *********************/   
		  string print_model_Components();
   /******************* Get *********************/
          string Get_model_name ();
	      string Get_model_number () ;
		  int    Get_number_of_Arms() ;
	      int    Get_number_of_Batteries();
		  int    Get_Torso_Bat_Comp();
	      int    Get_Torso_Max_arms();
		  int    Get_Head_power();
		  double Get_Locomotor_max_speed();
	      double Get_Locomotor_max_power();
		  double Get_Model_Cost();
		  double Get_Model_Shipping_Cost();
		  vector<int> Get_Arms_power() ;
    /******************* Add *********************/
          bool   add_Torso(Torso);
	      bool   add_Head(Head);
	      bool   add_Locomotor(Locomotor);
		  bool   add_Arm(Arm);
	      void   add_Battery(Battery);
    /***************** Set ********************/
	      void Set_Cost(double);
	      

};
#endif