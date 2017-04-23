CXX = g++
CXXOPTS = -std=c++11

Controller.out:  Controller.o boss_menu.o customer_menu.o add_component_menu.o new_or_returning_menu.o main_menu.o password_menu.o PM_add_component.o PM_menu.o SA_menu.o add_model.o catalog.o
	g++ -std=c++11  -I/usr/include/cairo -I/usr/include/glib-2.0-I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng12 -I/usr/include/freetype2 -I/usr/include/cairo -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng12 -g -O2 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE-D_THREAD_SAFE -D_REENTRANT -std=c++11 -o Controller.out Controller.o boss_menu.o customer_menu.o add_component_menu.o new_or_returning_menu.o main_menu.o password_menu.o PM_add_component.o PM_menu.o SA_menu.o add_model.o -lfltk
	
Controller.o: Controller.cpp Controller.h
	g++ -c -std=c++11 $(fltk-config --cxxflags --use-images --compile) Controller.cpp
	
boss_menu.o: boss_menu.cpp Controller.h
	g++ -c -std=c++11 $(fltk-config --cxxflags --use-images --compile ) boss_menu.cpp
	
customer_menu.o: customer_menu.cpp Controller.h
	g++ -c -std=c++11 $(fltk-config --cxxflags --use-images --compile) customer_menu.cpp
	
add_component_menu.o: add_component_menu.cpp Controller.h
	g++ -c -std=c++11 $(fltk-config --cxxflags --use-images --compile) add_component_menu.cpp
	
new_or_returning_menu.o: new_or_returning_menu.cpp Controller.h
	g++ -c -std=c++11 $(fltk-config --cxxflags --use-images --compile) new_or_returning_menu.cpp
	
main_menu.o: main_menu.cpp Controller.h
	g++ -c -std=c++11 $(fltk-config --cxxflags --use-images --compile) main_menu.cpp	
	
password_menu.o: password_menu.cpp Controller.h
	g++ -c -std=c++11 $(fltk-config --cxxflags --use-images --compile) password_menu.cpp
	
PM_add_component.o: PM_add_component.cpp Controller.h
	g++ -c -std=c++11 $(fltk-config --cxxflags --use-images --compile) PM_add_component.cpp
	
PM_add_menu.o: PM_menu.cpp Controller.h
	g++ -c -std=c++11 $(fltk-config --cxxflags --use-images --compile) PM_menu.cpp
	
SA_menu.o: SA_menu.cpp Controller.h
	g++ -c -std=c++11 $(fltk-config --cxxflags --use-images --compile) SA_menu.cpp
	
add_model.o: add_model.cpp Controller.h
	g++ -c -std=c++11 $(fltk-config --cxxflags --use-images --compile) add_model.cpp



#catalog.o: catalog.cpp Controller.h
#	g++ -c -std=c++11 $(fltk-config --cxxflags --use-images --compile) catalog.cpp

	
#fltk-config --compile Controller.cpp

clean:
	-rm -f *.o Controller
	