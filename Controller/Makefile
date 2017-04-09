CXX = g++
CXXOPTS = -std=c++11

Controller.out: Controller.o boss_menu.o customer_menu.o add_component_menu.o new_or_returning_menu.o main_menu.o password_menu.o PM_add_component.o PM_menu.o SA_menu.o add_model.o
	g++ -std=c++11 -o Controller.out Controller.o boss_menu.o customer_menu.o add_component_menu.o new_or_returning_menu.o main_menu.o password_menu.o PM_add_component.o PM_menu.o SA_menu.o add_model.o -lfltk
	
Controller.o: Controller.cpp Controller.h
	g++ -c -std=c++11 Controller.cpp 
	
boss_menu.o: boss_menu.cpp Controller.h
	g++ -c -std=c++11 boss_menu.cpp
	
customer_menu.o: customer_menu.cpp Controller.h
	g++ -c -std=c++11 customer_menu.cpp
	
add_component_menu.o: add_component_menu.cpp Controller.h
	g++ -c -std=c++11 add_component_menu.cpp
	
new_or_returning_menu.o: new_or_returning_menu.cpp Controller.h
	g++ -c -std=c++11 new_or_returning_menu.cpp 
	
main_menu.o: main_menu.cpp Controller.h
	g++ -c -std=c++11 main_menu.cpp
	
password_menu.o: password_menu.cpp Controller.h
	g++ -c -std=c++11 password_menu.cpp
	
PM_add_component.o: PM_add_component.cpp Controller.h
	g++ -c -std=c++11 PM_add_component.cpp 
	
PM_add_menu.o: PM_menu.cpp Controller.h
	g++ -c -std=c++11 PM_menu.cpp
	
SA_menu.o: SA_menu.cpp Controller.h
	g++ -c -std=c++11 SA_menu.cpp
	
add_model.o: add_model.cpp Controller.h
	g++ -c -std=c++11 add_model.cpp


	

clean:
	-rm -f *.o Controller
