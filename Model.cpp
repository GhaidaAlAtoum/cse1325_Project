#include "Robot_part.h"
#include "Components.h"
#include "Model.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
/******************* Constructor *********************/
Robot_model::Robot_model() {}
Robot_model::Robot_model(string in_name , string in_num){
           model_name = in_name;
	       model_number = in_num;
}
Robot_model::Robot_model(const Robot_model & obj){
  
}
/******************* Add Arm *********************/
bool Robot_model::add_Arm(Arm in_Arm){
	if(model_Arm.size()<=2) {
	     model_Arm.push_back(in_Arm);
		return 1;
	 }
	else {
	     return 0;
	}
}
/******************* Add Torso *********************/
bool Robot_model::add_Torso(Torso in_Torso){
	if(model_Torso.size()==0) {
	     model_Torso.push_back(in_Torso);
		return 1;
	 }
	else {
	     return 0;
	}
	
}
/******************* Add Locomotor *********************/
bool Robot_model::add_Locomotor(Locomotor in_Locomotor){
		if(model_Locomotor.size()==0) {
	     model_Locomotor.push_back(in_Locomotor);
		return 1;
	 }
	else {
	     return 0;
	}
	
}
/******************* Add Head *********************/
bool Robot_model::add_Head(Head in_Head){
		if(model_Head.size()==0) {
	     model_Head.push_back(in_Head);
		return 1;
	 }
	else {
	     return 0;
	}
	
}
/******************* Add Battery *********************/
void Robot_model::add_Battery(Battery in_Battery){
	model_Battery.push_back(in_Battery);
		}
/******************* Get Arm(s) Info  *********************/
vector<int> Robot_model::Get_Arms_power() {
    vector <int> power ;
	if(model_Arm.size()!=0){
	 for( auto & num : model_Arm ){
	     
		 power.push_back(num.get_max_power());
	 } //end for
	} //end if
	   return power;
}
/******************* Get Torso Info  *********************/
int  Robot_model::Get_Torso_Bat_Comp () {
	if(model_Torso.size()!=0) 
		return model_Torso[0].get_battery_compartments();
    else
        return 0;}
int    Robot_model::Get_Torso_Max_arms() { 
	if(model_Torso.size()!=0)
	return  model_Torso[0].get_max_arms (); 
	else
		return 0;
} 	
/******************* Get Locomotor Info  *********************/
double Robot_model::Get_Locomotor_max_speed() {
	if(model_Locomotor.size()!=0)
	return  model_Locomotor[0].get_max_speed();
	else 
		return 0;
}
double Robot_model::Get_Locomotor_max_power() { 
	if(model_Locomotor.size()!=0)
	return  model_Locomotor[0].get_max_power();
	else
		return 0;
}
/******************* Get Head Info  *********************/
int    Robot_model::Get_Head_power() {
	if(model_Head.size()!=0)
	return model_Head[0].Getpower();
	else
		return 0;
}

/******************* Get Model Cost  *********************/
double Robot_model::Get_Model_Cost(){
    double cost=0.0;
	if(model_Arm.size()!=0){
	 for( auto & num : model_Arm ){
	     cost += num.get_cost();
	 } 
	} 
	if(model_Battery.size()!=0){
	 for( auto & num : model_Battery ){
	     cost += num.get_cost();
	 } 
	} 
	cost += model_Torso[0].get_cost();
	cost += model_Head[0].get_cost();
	cost += model_Locomotor[0].get_cost();
	
	return cost;
}
/******************* Get Model name   *********************/
/******************* Get Model number *********************/
/******************* Print Model *********************/
string Robot_model::print_model_Components(){
	

}



