#include "Product_Manager.h"
#include "shop.h"
#include<iostream>

using namespace std

string Product_Manager::manager_name = "Manager_Default";
string Product_Manager::manager_password = "Manager_Default";

Product_Manager& Product_Manager::get_Instance(){
static Product_Manager instance;
	return instance;	
}

bool Product_Manager::check_name_pass(string in_name, string in_pass){
   if(in_name != manager_name || in_pass !=manager_password)
	   return 0;
	else 
		return 1;	
}

void Product_Manager::change_name(string new_name){
     manager_name = new_name;
}
void Product_Manager::change_pass(string neW_pass){
	manager_password = new_pass;
}
void Product_Manager::Instance_new_Arm(string name, int model_number, string description, string image_filename,
									   double cost, double weight,double max_power)
{   
	Arm Temp(name,model_number,description,image_filename,cost,weight,max_power);
		push_component(temp);
}
void Product_Manager::Instance_new_Torso(string name, int model_number, string description, string image_filename, double cost,
										 double weight, int max_arms, int battery_compartments)
{   
	Tosro temp(name,model_number,description,image_filename,cost,weight,max_arms,battery_compartments);
	push_component(temp);
}
void Product_Manager::Instance_new_Locomotor(string name, int model_number, string description, string image_filename, double cost,
											 double weight, double max_speed, double max_power)
{   
	Locomotor temp(name,model_number,description,image_filename,cost,weight,max_speed,max_power);
	push_component(temp);
}
void Product_Manager::Instance_new_Head(string name, int model_number, string description, string image_filename, 
										double cost, double weight,double max_power)
{   
	Head temp(name,model_number,description,image_filename,cost,weight,max_power);
	push_component(temp);
}
void Product_Manager::Instance_new_Battery(string name, int model_number,string description,string image_filename, 
										   double cost,double weight, double power_available, double max_energy)
{   
	Locomotor temp(name,model_number,description,image_filename,cost,weight,power_available,max_energy);
	push_component(temp);
}
void Product_Manager::Instance_new_model(string m_name,string m_number)
{
	Robot_model temp(m_name,m_number);
    cout<<" Component Catalog \n"<<Shop::Print_Catalog_Components()<<endl;
	
	push_Model(temp);
	
}
void Product_Manager::push_component(Robot_Part& temp)
{
	shop::add_component(temp);
	
}
void Product_Manager::push_Model(Robot_Model& temp)
{
	shop::add_Model(temp);	
}
void   Product_Manager::pull_component(int component_index){
	shop::remove_component(component_index);
}
void   Product_Manager::pull_Model(int Model_index){
	shop::remove_Model(Model_index);
}





int choice;
	string General_Components = R"(
	==================================
	    List Of General Components
	==================================
	1) Arm
	2) Torso
	3) Locomotor
	4) Head
	5) Battery
	6) Exit
	)";
    string Inputs_For_Arm = R"(
	[string] Name:
	[int] Model Number:
	[string] Description:
	[string] Image file name:
	[double] cost:
	[double] weight
	[double] max power:
	)";
    string Inputs_For_Torso = R"(
 	[string] Name:
	[int] Model Number:
	[string] Description:
	[string] Image file name:
	[double] cost:
	[double] weight
	[int] max number of arms:
	[int] number of battery compartments:
	)";
    string Inputs_For_Locomotor = R"(
	[string] Name:
	[int] Model Number:
	[string] Description:
	[string] Image file name:
	[double] cost:
	[double] weight
	[double] max speed:
	[double] max power
	)";
    string Inputs_For_Head= R"(
	[string] Name:
	[int] Model Number:
	[string] Description:
	[string] Image file name:
	[double] cost:
	[double] weight
	[double] max power:
	)";
    string Inputs_For_Battery= R"(
	[string] Name:
	[int] Model Number:
	[string] Description:
	[string] Image file name:
	[double] cost:
	[double] weight
	[double] power available:
	[double] max energy:
	)";
	switch case() {
		     Instance_new_Arm(string, int, string, string, double, double,double);
		     Instance_new_Torso(string, int, string, string, double, double, int, int);
		     Instance_new_Locomotor(string, int, string, string, double,double, double, double);
		     Instance_new_Head(string, int, string, string, double, double,double);
		     Instance_new_Battery(string, int,string,string, double,double, double, double);
	}









