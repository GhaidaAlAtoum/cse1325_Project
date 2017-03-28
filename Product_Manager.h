#ifndef PRODUCT_MANAGER_H
#define PRODUCT_MANAGER_H

#include<iostream>

using namespace std

class Product_Manager 
{
    private :
	      static string manager_name ;
		  static string manager_password ;
		  Product_Manager(){}
 
    public:
	      static Product_Manager& get_Instance();
		  bool   check_name_pass(string,string);
		  void   change_name(string);
		  void   change_pass(string);
		  void   Instance_new_Arm(string, int, string, string, double, double,double);
		  void   Instance_new_Torso(string, int, string, string, double, double, int, int);
		  void   Instance_new_Locomotor(string, int, string, string, double,double, double, double);
		  void   Instance_new_Head(string, int, string, string, double, double,double);
		  void   Instance_new_Battery(string, int,string,string, double,double, double, double);
		  void   Instance_new_model(string,string);
		  void   push_component(Robot_Part&);
		  void   push_Model(Robot_Model&);
		  void   pull_component(int component_index);
		  void   pull_Model(int Model_index);
		  void   Print_Catalog_Components();
		  void   Print_Catalog_model();

};


#endif 