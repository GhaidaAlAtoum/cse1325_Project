#include "shop.h"
#include "Robot_part.h"
#include "Components.h"
#include "Model.h"
#include "Product_Manager.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

shop::shop() {
}

shop& shop::Instance_shop(){
	static shop instance;
           return instance;
}

void shop::add_component(Robot_Part&){
	
}
void shop::add_Model(Robot_model&){
	
}
void shop::remove_component(int index){
	
}
void shop::remove_Model(int index){
	
}
void shop::Print_Catalog_Models(){
	
}
void shop::Print_Catalog_Components(){
	
}
void shop::save_Robot_Models(){
	ofstream ShopFile ("Robot_Models_Saved.txt");
	
	
	ShopFile.close();
}
void shop::save_Robot_Components(){
	ofstream ShopFile ("Robot_Components_Saved.txt");
	
	
	ShopFile.close();
}
void shop::Read_Robot_Components(){
	
}
void shop::Read_Robot_Models(){
	
}
