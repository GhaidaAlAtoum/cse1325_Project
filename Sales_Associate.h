#ifndef SALES_H
#define SALES_H

#include "Robot_part.h"
#include "Components.h"
#include "Model.h"
#include "Product_Manager.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SA 
{
    private:
	    string SA_Name="Default";
		string SA_pass="123456";
		vector<Orders> Orders_processed;
		double Month_Salary = 1000;
	public:
	    SA();
		SA(string);
		bool check_SA_Name_Pass(string,string);
		void change_Name(string);
		void change_Pass(string);
		void Request_Raise();
		void check_for_unprocesses_Orders();
		void Process_an_order();
		string List_Of_Processed_Orders();
		int number_of_processed_orders();
        int check_Salary();




};


#endif 