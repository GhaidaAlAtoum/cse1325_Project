#ifndef SHOP_H
#define SHOP_H
#include "Robot_part.h"
#include "Components.h"
#include "Model.h"
#include "Product_Manager.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class shop
{
  private:
         static vector <Robot_Part&> components;
		 static vector <Robot_model&> Models;
		 static vector <Customers> shop_Customers;
		 static Product_Manager shop_Product_Manager;
		 shop();
		 	      
  public:
        static shop& Instance_shop();
		static void add_component(Robot_Part&);
        static void add_Model(Robot_model&);
        static void remove_component(int index);
        static void remove_Model(int index);
        static void Print_Catalog_Models();
        static void Print_Catalog_Components();
        static void save_Robot_Models();
		static void save_Robot_Components();
		static void Read_Robot_Components()
		static void Read_Robot_Models();
};

#endif