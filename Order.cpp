#include "Order.h"

using namespace std;

Order::Order(int Num,string date, Robot_model temp){
	Order_Number=Num;
	Date=date;
	Robot_Model_Order=temp;
}

int Order::Get_Order_Number(){
 return Order_Number;
}

string Order::Get_Order_Date(){
	return Date;
}

int Order::Get_Order_status(){
	return status;
}

void Order::Set_SA(SA temp){
	SA_who_Processed=temp;
}

void Order::Set_Status(int i){
    status = i;
}

