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
		 shop();
		 	      
  public:
        static shop& Instance_shop();
		static add_component(Robot_Part&);
        static add_Model(Robot_model&);
        static remove_component(int index);
        static remove_Model(int index);
        static Print_Catalog_Models();
        static Print_Catalog_Components();
      

};

#endif