#include "Product_Manager.h"
#include "shop.h"
#include<iostream>

using namespace std

string Product_Manager::manager_name = "Manager_Default";
string Product_Manager::manager_password = "Manager_Default";

Product_Manager& Product_Manager::get_Instance(){
static get_Instance instance;
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
void Product_Manager::Instance_new_component(int choice)
{   
	 
}
void Product_Manager::Instance_new_model(string m_name,string m_number)
{
	Robot_model temp(m_name,m_number);
	/* from the menu of components PM choses then using the add function in
	   Robot_model we'll add the components */
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
void   Product_Manager::Print_Catalog_Components(){
	shop::Print_Catalog_Models
}
void   Product_Manager::Print_Catalog_model(){
	shop::Print_Catalog_Components
}














