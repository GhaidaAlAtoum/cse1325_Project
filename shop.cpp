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
/****************** ADD ********************/
void shop::add_component(Robot_Part& temp){
    	components.push_back(temp);
}
void shop::add_Model(Robot_model&){
    	Models.push_back(temp);
}
/****************** REMOVE ********************/
void shop::remove_component(int index){
	    components.erase(components.begin() + index);
}
void shop::remove_Model(int index){
	Models.erase(Models.begin() + index);
}
/****************** PRINT********************/
void shop::Print_Catalog_Models(){
	
}
void shop::Print_Catalog_Components(){
	
}
/****************** SAVE ********************/
void shop::save_Robot_Models(){
	ofstream ShopFile ("Robot_Models_Saved.txt");
	
	
	ShopFile.close();
}
//power.push_back(num.get_max_power());
void shop::save_Robot_Components(){
	ofstream ShopFile ("Robot_Components_Saved.txt");
	for( auto & num : components ){
	    switch(num.Type()){
			case 1: ShopFile<<num.Type()<<endl;
				    shopFile<<num.get_part_name()<<endl;
				    shopFile<<num.get_part_number()<<endl;
				    shopFile<<num.get_part_description()<<endl;
				    shopFile<<num.get_image_filename()<<endl;
				    shopFile<<num.get_cost()<<endl;
				    shopFile<<num.get_weight()<<endl;
				    shopFile<<num.get_max_power_Arm<<endl;
				break;
			case 2: ShopFile<<num.Type()<<endl;
				    shopFile<<num.get_part_name()<<endl;
				    shopFile<<num.get_part_number()<<endl;
				    shopFile<<num.get_part_description()<<endl;
				    shopFile<<num.get_image_filename()<<endl;
				    shopFile<<num.get_cost()<<endl;
				    shopFile<<num.get_weight()<<endl;
				    shopFile<<num.get_max_arms()<<endl;
				    shopFile<<num.get_battery_compartments()<<endl;
				    break;
			case 3: ShopFile<<num.Type()<<endl;
				    shopFile<<num.get_part_name()<<endl;
				    shopFile<<num.get_part_number()<<endl;
				    shopFile<<num.get_part_description()<<endl;
				    shopFile<<num.get_image_filename()<<endl;
				    shopFile<<num.get_cost()<<endl;
				    shopFile<<num.get_weight()<<endl;
				    shopFile<<num.get_max_speed()<<endl;
				    shopFile<<num.get_max_power()<<endl;
			        break;
			case 4: ShopFile<<num.Type()<<endl;
				    shopFile<<num.get_part_name()<<endl;
				    shopFile<<num.get_part_number()<<endl;
				    shopFile<<num.get_part_description()<<endl;
				    shopFile<<num.get_image_filename()<<endl;
				    shopFile<<num.get_cost()<<endl;
				    shopFile<<num.get_weight()<<endl;
				    shopFile<<num.Getpower()<<endl;
				    break;
			case 5: ShopFile<<num.Type()<<endl;
				    shopFile<<num.get_part_name()<<endl;
				    shopFile<<num.get_part_number()<<endl;
				    shopFile<<num.get_part_description()<<endl;
				    shopFile<<num.get_image_filename()<<endl;
				    shopFile<<num.get_cost()<<endl;
				    shopFile<<num.get_weight()<<endl;
				    shopFile<<nem.get_power()<<endl;
				    shopFile<<num.get_max_energy()<<endl;
				    break;				
		}		
		 
	 } 
	
	ShopFile.close();
}
void shop::save_List_SA(){
	
}
void shop::save_PHB_info(){
	
}
void shop::save_PM_info(){
	
}
/****************** READ ********************/
void shop::Read_Robot_Components(){
	
	string line , name , description, image;
	int n=-1,i=0;
	int type,model_num , Torso_max_arms,Torso_batt_com;
	double cost, weight, arm_power, loco_speed,loco_power,head_power,batt_power,batt_energy;
	ifstream shopFile1("Components.txt");
	if(shopFile1.is_open()){
		while(!shopFile1.eof()){
			getline(shopFile1,line);
			n++;}
		shopFile1.close();
	}
	ifstream file2("Components.txt");
	if(file2.is_open()){
		while((!file2.eof()) && i<n){
			getline(file2,line);
			stringstream(line)>>type;
			switch(type) {
				case 1: 
					    getline(file2,line);
			            name=line;
					    getline(file2,line);
			            stringstream(line)>>model_num;
					    getline(file2,line);
			            description=line;
					    getline(file2,line);
			            image=line;
					    getline(file2,line);
					    stringstream(line)>>cost;
					    getline(file2,line);
					    stringstream(line)>>weight;
						getline(file2,line);
					    stringstream(line)>>arm_power;
					    i+=8;
					Arm 
					    break;
				case 2:  
					    getline(file2,line);
			            name=line;
					    getline(file2,line);
			            stringstream(line)>>model_num;
					    getline(file2,line);
			            description=line;
					    getline(file2,line);
			            image=line;
					    getline(file2,line);
					    stringstream(line)>>cost;
					    getline(file2,line);
					    stringstream(line)>>weight;
					    getline(file2,line);
					    stringstream(line)>>Torso_max_arms;
					    getline(file2,line);
					    stringstream(line)>>Torso_batt_com;	
					    i+=8;
					    break;
				case 3: 
					    getline(file2,line);
			            name=line;
					    getline(file2,line);
			            stringstream(line)>>model_num;
					    getline(file2,line);
			            description=line;
					    getline(file2,line);
			            image=line;
					    getline(file2,line);
					    stringstream(line)>>cost;
					    getline(file2,line);
					    stringstream(line)>>weight;
					    getline(file2,line);
					    stringstream(line)>>loco_speed;
					    getline(file2,line);
					    stringstream(line)>>loco_power;		
					    i+=9;
					    break;
				case 4: 
					    getline(file2,line);
			            name=line;
					    getline(file2,line);
			            stringstream(line)>>model_num;
					    getline(file2,line);
			            description=line;
					    getline(file2,line);
			            image=line;
					    getline(file2,line);
					    stringstream(line)>>cost;	
					    getline(file2,line);    
				    	stringstream(line)>>weight;
					    getline(file2,line);    
				    	stringstream(line)>>head_power;
					    i+=8;
					    break;
				case 5: 
					    getline(file2,line);
			            name=line;
					    getline(file2,line);
			            stringstream(line)>>model_num;
					    getline(file2,line);
			            description=line;
					    getline(file2,line);
			            image=line;
					    getline(file2,line);
					    stringstream(line)>>cost;	
					    getline(file2,line);    
				     	stringstream(line)>>weight;
					    getline(file2,line);    
				     	stringstream(line)>>batt_power;
					    getline(file2,line);    
				     	stringstream(line)>>batt_energy;
					    i+=9;	
					    break;
							}
		
		components.push_back();
		}
		file2.close();
	}
}
void shop::Read_Robot_Models(){
	
}
void shop::Read_SA_List(){
	
	
}
void shop::Read_PHB_info(){
	
}
void shop::Read_PM_info(){
	
}

























