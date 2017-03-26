#include "Robot_part.h"
#include "Components.h"
#include "Model.h"
#include "Product_Manager.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
 
 	Torso T1( "T_1",1,"T_2","T_3",12,13,14,15);
	Robot_Part & check = T1;
	cout<<"Torso Battery Compartments  " <<check.get_battery_compartments()<<endl;
	cout<<"Torso Max arms  " <<check.get_max_arms()<<endl;
	cout<<"Cost Torso  "<< check.get_cost()<<endl;
	cout<<"Shipping price  "<<check.get_shipping_price()<<endl;
	cout<<"Torso Image file name  " <<check.get_image_filename()<<endl;
	cout<<"\n ********************************** \n";
	
    Arm A1("A_1",2,"A_2","A_3",21,22,23);
	cout<<"Arm Max Power  "<<A1.get_max_power()<<endl;
	cout<<"Cost Arm  "<< A1.get_cost()<<endl;
	cout<<"Shipping price  "<<A1.get_shipping_price()<<endl;
	cout<<"Arm Image file name  " <<A1.get_image_filename()<<endl;
    cout<<"\n ********************************** \n";
	
	Locomotor L1("L_1",3,"L_2","L_3",31,32,33,34);
	cout<<"Loco max speed  "<<L1.get_max_speed()<<endl;
	cout<<"Loco max power  "<<L1.get_max_power()<<endl;
	cout<<"Cost Locomotor  "<< L1.get_cost()<<endl;
	cout<<"Shipping price  "<<L1.get_shipping_price()<<endl;
	cout<<"Locomotor Image file name  " <<L1.get_image_filename()<<endl;
	cout<<"\n ********************************** \n";
	
	Head H1("H_1",4,"H_2","H_3",41,42,43);
	cout<<"Head power  "<<H1.Getpower()<<endl;
	cout<<"Cost Head  "<< H1.get_cost()<<endl;
	cout<<"Shipping price  "<<H1.get_shipping_price()<<endl;
	cout<<"Head Image file name  " <<H1.get_image_filename()<<endl;
	cout<<"\n ********************************** \n";
	
	Battery B1("B_1",5,"B_2","B_3",51,52,53,54);
    cout<<"Battery power  "<<B1.get_power()<<endl;
	cout<<"Battery max energy  "<<B1.get_max_energy()<<endl;
	cout<<"Cost Battery  "<< B1.get_cost()<<endl;
	cout<<"Shipping price  "<<B1.get_shipping_price()<<endl;
	cout<<"Battery Image file name  " <<B1.get_image_filename()<<endl;
	cout<<"\n ********************************** \n";
	
	Arm A2("A_2",6,"A_22","A_32",61,62,63);
	cout<<"Arm Max Power  "<<A2.get_max_power()<<endl;
	cout<<"Cost Arm  "<< A2.get_cost()<<endl;
	cout<<"Shipping price  "<<A2.get_shipping_price()<<endl;
	cout<<"Arm Image file name  " <<A2.get_image_filename()<<endl;
    cout<<"\n ********************************** \n";
	
	Battery B2("B_2",7,"B_22","B_32",71,72,73,74);
    cout<<"Battery power  "<<B2.get_power()<<endl;
	cout<<"Battery max energy  "<<B2.get_max_energy()<<endl;
	cout<<"Cost Battery  "<< B2.get_cost()<<endl;
	cout<<"Shipping price  "<<B2.get_shipping_price()<<endl;
	cout<<"Battery Image file name  " <<B2.get_image_filename()<<endl;
	cout<<"\n ********************************** \n";
	
	Robot_model mod1("MOD1.G",100);
	mod1.add_Torso(T1);
	mod1.add_Head(H1);
	mod1.add_Locomotor(L1);
	mod1.add_Battery(B1);
	mod1.add_Arm(A1);
	mod1.add_Battery(B2);
	mod1.add_Arm(A2);
	
	cout<<"Modle Torso Max arms "<<mod1.Get_Torso_Max_arms()<<endl;
	
return 0; }











