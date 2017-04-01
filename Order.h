#ifndef ORDER_H
#define ORDER_H

class Order
{
  private:
  int Order_Number=0;
  string Date="00/00/0000";
  SA SA_who_Processed;
  int status=0;
  Robot_model Robot_Model_Order ;
  
  public:
	 Order(int,string,Model);
	 int Get_Order_Number();
	 string Get_Order_Date();
	 int Get_Order_status();
	 void Set_SA(SA);
	 void Set_Status(int);
	 };

#endif