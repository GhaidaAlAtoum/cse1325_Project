#include <iostream>
#include <string>



using namespace std;


///////////////////////// 
 
////////////////////////////

class View {
  public:
    string get_main_menu();
	string get_patron_list();	
	string get_Boss();
	string get_PM();
	string get_part_kinds();
	
	
	
	string get_new_or_returning_menu(); // Asks if customer if new or returning

  	string get_customer_options_list(); // view robot models, show models, etc
  	string get_robot_models_list();
  	string get_ordering_menu();
};

string View::get_part_kinds()
{
	
	string menu = R"(
Would you like to create a..
1 - Head
2 - Torso
3 - Arm
4 - Battery
5 - Locometer
	)";
	
	return menu;
	
}


string View::get_main_menu() {
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
(5) Sign in as a Customer (Or create account)
(5) Help
(9) Exit

)";
    return menu;
}

string View::get_patron_list() {}

string View::get_PM()
{
	
	string menu = R"(
	
------------------
PART MANAGER MENU
------------------
1 - Define New Robot Model
2 - Create New Robot Part

)";
	return menu;
}

string View::get_Boss() {

  string list = R"(
-----------------------
    Boss's Jobs
-----------------------

(1) Create a new Sale's Associate

}

)";
}  


string View::get_new_or_returning_menu()
{

  string message = R"(
-----------------------
WELCOME CUSTOMER
-----------------------
1 - Returning Users
2 - Create new account
3 - Exit
  
)";
  
  return message;
  
}

string View::get_customer_options_list()
{

  string message = R"(

----------------------------
CUSTOMER MENU
----------------------------
1 - View Robot Models
2 - Order Robot Model
3 - Check an order status
)";

  return message;

}

string View::get_robot_models_list()
{

 //Shop::Print_Catalog_Models();

}

string View::get_ordering_menu()
{

  string message = R"(
-------------------------------
ORDER A ROBOT MODEL
-------------------------------
- Please enter the number of the model you would like to order
- Enter Q to go back

)";

  return message;

}

	
// Below is the controller class with some stuff like shop, view included. Not used for testing the controller logic.
/*
class Controller
{
	public:
	Controller(Shop& in_shop, View& in_view): shop(in_shop), view(in_view) {}
	void cli();
	void execute_cmd();
	void quit();
	void back();
	private:
	int get_input(string prompt, int max_int);
	Shop shop;
	View view;
};
*/




class Controller
{
	public:

	Controller(View& in_view): view(in_view)
	{
	// Runs the main Command Line Interface for 1st time.	
	main_cli();
	}
	
	// Main Menu
	void main_cli();
	
	void customer_cli();
	
	void PHB_cli();
	
	void PM_cli();

	void execute_cmd();

	// Navigation - Doesn't work (yet)
	//void quit();
	//void back();
	
	
	// Password Stuff
	bool check_password(string username);
	bool check_username(string username);
	bool check_username_and_password();
	
	private:
	
	// Takes the menu view view and prints it, then gets user input (and int.)
	int get_input(string prompt, int max_int);
	View view;
};


//////////////////
// SPRINT 1     //
//////////////////


// Pointy-Haired Boss Functions

void Controller::PHB_cli()
{
	
	int choice = get_input(view.get_Boss(), 3);	
	
}

// Done in a rush and not finished

void Controller::PM_cli()
{
	int choice = get_input(view.get_PM(), 2);
	
	if (choice == 2) 
	{
		int part = get_input(view.get_part_kinds(), 5);
		if (part == 1)
		{
			string name;
			int model_number;
			string description;
			string image_file_name;
			double cost;
			double weight;
			double max_power;
			
			cout << "Enter name: " << endl;
			cin >> name;
			cin.ignore();
			cout << "Enter model number: " << endl;
			cin >> name;
			cin.ignore();
			cout << "Enter description: " << endl;
			cin >> name;
			cout << "Enter image file name: " << endl;
			cin >> name;
			cout << "Enter cost: " << endl;
			cin >> name;
			cout << "Enter weight: " << endl;
			cin >> name;
			cout << "Enter max power: " << endl;
			cin >> name;
		
		}		
	}
	
	else if (choice == 2)
	{
		
	}
	
}


// Main - Menu - All starts from here

void Controller::main_cli()
{

	bool cmd = false;
	while (cmd != true)
	{
		string menu = view.get_main_menu();
		int choice = get_input(menu, 5);		
		if (choice == 5) {customer_cli();}
		else if (choice == 1) {PM_cli();}
	}

}

// Customer cli
						   
void Controller::customer_cli()
{
	int choice = get_input(view.get_new_or_returning_menu(), 4);	
	if (choice == 1)
	{		
		
	}

}

// Function for getting input

int Controller::get_input(string menu, int max_int)
{
	int input;
	while (true)
	{
	
		cout << menu;
		cout << "Enter: ";
		cin >> input;
		cin.ignore();
		
		
		
		if (input > 1 && input <= max_int) 
			return input;
    	//else if (input == 9) {quit();}
		//else if (input == 8) {back();}
		else 
			break;
	
	}

}

						   
// NOT NEEDED FOR SPRINT 1 BUT MAYBE USEFUL LATER
						   
// Password-Checking Functions
/*
bool Controller::check_username_and_password()
{
	string username;
	string password;
	while(true)
	{
		cout << "Please enter your username: ";
		cin >> username;
	
		cout << "Please enter your password: ";
		cin >> password;
	
		if (check_password(password) & (check_username(username)))
			return true;
		else
		{
			cout << "Incorrect username or password. Please try again.";
			continue;
		
		}
	
	}

}

bool Controller::check_password(string password)
{
	
	// GET PW FROM CORRECT CLASS HERE
	// The input person_type will be a string for Customer, PHB, etcetc. From that we know know where to get the pw from.
	// for example if person_type == Customer, the acess Customer class.
	
	
}

bool Controller::check_username(string username)
{
	
	// GET USERNAME FROM CORRECT CLASS HERE
	// The input person_type will be a string for Customer, PHB, etcetc. From that we know know where to get the pw from.
	// for example if person_type == Customer, the acess Customer class.
	
}
	

// Customer functions


// Quit and go back (not sure how to do that yet)

void Controller::quit()
{
	
	
	
}

void Controller::back()
{
	
	
	
}


*/
	
	
int main()
	
{
	
	View view;
	Controller controller(view);

	
	
	return 0;
	
}