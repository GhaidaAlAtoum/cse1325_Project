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
		  void   Instance_new_component(int choice);
		  void   Instance_new_model();
		  void   push_component(Robot_Part&);
		  void   push_Model(Robot_Model&);
		  void   pull_component(int component_index);
		  void   pull_Model(int Model_index);
};


#endif 