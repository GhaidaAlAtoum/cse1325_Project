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
		 static vector <Order&> shop_processed_Orders ; 
         static vector<Order&>shop_unprocessed_Orders ;
         static vector <Sales_Associate> Sales_Associate_of_Shop;
		 shop();
		 	      
  public:
        static shop& Instance_shop();
		static void add_component(Robot_Part&);
        static void add_Model(Robot_model&);
        static void remove_component(int index);
        static void remove_Model(int index);
        static string Print_Catalog_Models();
        static string Print_Catalog_Components();
		static string Print_Unprocessed_Orders() ;
        static string Print_Processed_Orders () ;

		static void save_List_SA();
        static void save_PHB_info();
        static void save_PM_info();
		static void save_Robot_Models();
		static void save_Robot_Components();
        static void Read_Robot_Components();
        static void Read_Robot_Models();
	    static void Read_Robot_Components();
		static void Read_Robot_Models();
		
};

#endif