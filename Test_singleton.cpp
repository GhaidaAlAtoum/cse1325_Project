#include <iostream>

using namespace std;

class Test 
{
	public:
	
	static Test& getinstance();
	bool change(string,int,string,int);
	string get_name() { return name; }
	private:
	static string name ;
	static int   pass;
	Test ();
};

string Test::name="Default";
int    Test::pass=123;
bool Test::change(string old_name, int old_pass,string in_name, int in_pass){
	if(old_name != name || old_pass!= pass)
		return 0;
	else {
          name = in_name;
		  pass = in_pass;
	return 1;}
}
Test::Test(){}
Test& Test::getinstance(){
    static Test instance;
	return instance;
}

int main(){
	Test T1 = Test::getinstance();
	cout<<T1.get_name()<<endl;
    T1.change("Default",123,"Ghaida",555);
	cout<<T1.get_name()<<endl;
	
	return 0; }
	
	
	
	
	
	
	
	
	
	