#include "Order.h"

using namespace std;

Order::Order(int Num,string date, Robot_model temp){
	Order_Number=Num;
	Date=date;
	Robot_Model_Order=temp;
}
/******************** Get Order Number ********************/
int Order::Get_Order_Number(){
 return Order_Number;
}
/******************** Get Order Date ********************/
string Order::Get_Order_Date(){
	return Date;
}
/******************** Get Order Status ********************/
int Order::Get_Order_status(){
	return status;
}
/******************** Get Order Model Number+Name ********************/
string Order::Get_Order_Model_Info(){
	string temp=NULL;
	/* Model Number Model Name */
	temp +=Robot_Model_Order.Get_model_number()+"\t"+Robot_Model_Order.Get_model_name();
	return temp;
}
/******************** Set SA ********************/
void Order::Set_SA(SA temp){
	SA_who_Processed=temp;
}
/******************** Set Status ********************/
void Order::Set_Status(int i){
    status = i;
}


