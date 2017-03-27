
#include "Robot_part.h"
#include "Components.h"
#include "Model.h"
//#include "Product_Manager.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

///////////////////////// 
 class view 
////////////////////////////

class View {
  public:
    string get_main_menu();
    string get_PM_1_menu();
    string get_PM_2_menu();
    string get_BC_new_menu();
    string get_BC_old_menu();
    string get_SA_1_menu();
    string get_SA_2_menu();
    string get_PB_1_menu();
    string get_PB_1_menu();
    string get_help();
	
	// Customer
	
	string get_new_or_returning_menu(); // Asks if customer if new or returning
  	string get_create_customer_menu(); // For creating a new customer
  	string get_login_menu(); // Logging in if previous customer
  	string get_customer_options_list(); // view robot models, show models, etc
  	string get_robot_models_list();
  	string get_ordering_menu();
  	string get_order_status()
};

string View::get_menu() {
    string menu = R"(
===============================\n"+get_main_menu() + get_help();
}

string View::get_menu() {
    string menu = R"(
==================
    Robot'R'Us
==================

Main Menu
---------
(1) Sign in as a PM
(2) Sign in as a BC
(3) Sign in as an existing SA
(4) Sign in as a PB
(5) Help
(6) Exit

)";
    return menu;
}


string View::get_PM_1_menu() {
  string list = R"(
----------------------------
List of PM
----------------------------
)";
  for (int i=0; i<library.number_of_publications(); ++i) {
    list += std::to_string(i) + ") " + library.publication_to_string(i) + '\n';
  }
  return list;
}

<<<<<<< HEAD
string View::get_patron_list() {
=======

string View::get_Boss() {
>>>>>>> 53f615591126c705a821fbf8d4b9f3537eaeb87c
  string list = R"(
-----------------------
    Boss's Jobs
-----------------------

(1) List of Orders
(2) Check Shop Metrics
(3) Chwck Profit Margin

}





)";
  

string View::get_genre_list() {
  string list = "";
  for (int i = 0; i < Genre::num_genres; ++i)
    list += "  " + std::to_string(i) + ") " + Genre(i).to_string() + '\n';
  return list;
}

string View::get_media_list() {
  string list = "";
  for (int i = 0; i < Media::num_media; ++i)
    list += "  " + std::to_string(i) + ") " + Media(i).to_string() + '\n';
  return list;
}

string View::get_age_list() {
  string list = "";
  for (int i = 0; i < Age::num_ages; ++i)
    list += "  " + std::to_string(i) + ") " + Age(i).to_string() + '\n';
  return list;
}

string View::get_help() {
  return "Try harder.";
}

// Adding Customer functions to class


string View::get_new_or_returning_menu()
{

  cout << "Enter 1 if you are a new user" << endl;
  cout << "Enter 2 if are a returning user" << end;
  
}

string View::get_create_customer_menu()
{

  cout << "Please enter a new username, press enter, and then a password." << endl;

}

string View::get_login_menu()
{

  cout << "Please enter your username, press enter, then enter your password." << endl;

}

string View::get_customer_options_list()
{

  cout << "Enter 1 to view robot models." << endl;
  cout << "Enter 2 to order a robot model." << endl;
  cout << "Enter 3 to check an order status." << endl;

}

string View::get_robot_models_list()
{

 Shop::Print_Catalog_Models();

}

string View::get_ordering_menu()
{

	

}



int main(){
// Creating Main Menu 

/*int choice;
do
{
cout<<"= = = = = = = = = = =\n";
cout<<"      Robot'R'Us       ";
cout<<"= = = = = = = = = = =\n";
cin>> choice;

switch(choice)
{
 case 1:cout<<"Sign in as a PM\n"; break;
 case 2:cout<<"Sign in as a BC\n"; break;
 case 3:cout<<"Sign in as existing SA\n"; break;
 case 4:cout<<"Sign in as a PB\n"; break;
 case 5:cout<<"Help\n"; break;
 case 6:cout<<"EXit\n"; break;
 default:cout<<"Not a valid choice.\n";
}
}while(choice == 6);
return choice;

*/


 
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
	
	Robot_model mod1("MOD1.G","100");
	mod1.add_Torso(T1);
	mod1.add_Head(H1);
	mod1.add_Locomotor(L1);
	mod1.add_Battery(B1);
	mod1.add_Arm(A1);
	mod1.add_Battery(B2);
	mod1.add_Arm(A2);
	
	cout<<"Modle Torso Max arms "<<mod1.Get_Torso_Max_arms()<<endl;
	
return 0; }











