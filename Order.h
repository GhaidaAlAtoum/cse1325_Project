#ifndef ORDER_H
#define ORDER_H

class Order
{
  private:
  int Order_Number=0;
  int status=0;
  int Quantity=1;
  string Date="00/00/0000";
  SA SA_who_Processed;
  Robot_model Robot_Model_Order ;
  
  public:
	 Order(int,string,Model);
	 /*********** Get Functions ************/
	 int Get_Order_Number();
	 int Get_Order_status();
	 string Get_Order_Date();
	 string Get_Order_Model_Info();
	 
	 /*********** Set Functions ************/
	 void Set_SA(SA);
	 void Set_Status(int);
	 };

#endif