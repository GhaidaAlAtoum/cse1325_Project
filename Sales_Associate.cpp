#include "Sales_Associate.h"
#include "Robot_part.h"
#include "Components.h"
#include "Model.h"
#include "Product_Manager.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/****************** Constructors ******************/

SA::SA() { }

SA::SA(string in_name){
  	SA_Name = in_name;
 }
SA::SA(const SA & obj){
 SA_Name = obj.SA_Name;
 SA_pass = obj.SA_Name;
 Orders_processed = obj.Orders_processed;
 Month_Salary = obj.Month_Salary;
}
/****************** Check_Name_Pass ******************/
bool SA::check_SA_Name_Pass(string in_name, string in_pass){
  if(in_name == SA_Name && in_pass == SA_pass)
	     return 0;
  else
	     return 1;
}
/****************** Change Name / Pass ******************/
void SA::change_Name(string in_name){
	SA_Name = in_name;
}
void SA::change_Pass(string in_pass){
	SA_pass= in_pass;
}
/****************** Requist A Raise ******************/
void SA::Request_Raise(){
   string request;
	request +="Number of processed Orders : "+std::to_string(this.number_of_processed_orders)
	request +=" \n "+this.List_Of_Processed_Orders();
   PHB::add_raise_request(request);
}
/****************** Create List of Processed Orders ******************/
string SA::List_Of_Processed_Orders(){
   
}
/****************** Number of processed Orders ******************/
int SA::number_of_processed_orders(){
    return( Orders_processed.size());
}















