CXX = g++
CXXOPTS = -std=c++11
#all: executable
#rebuild: clean all
debug: CXXFLAGS += -g
debug: executable
Arm: arm_gui.o 
	$(CXX) $(CXXOPTS) -I/usr/include/cairo -I/usr/include/glib-2.0-I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1-I/usr/include/freetype2 -I/usr/include/libpng12 -I/usr/include/freetype2-I/usr/include/cairo -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2-I/usr/include/libpng12 -g -O2 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE-D_THREAD_SAFE -D_REENTRANT -std=c++11 -o 'arm_gui' 'arm_gui.o' -Wl,-Bsymbolic-functions -lfltk -lX11 
arm_gui.o:
	$(CXX) -c $(CXXOPTS) $(fltk-config --cxxflags) arm_gui.cpp
Torso: torso_gui.o 
	$(CXX) $(CXXOPTS) -I/usr/include/cairo -I/usr/include/glib-2.0-I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1-I/usr/include/freetype2 -I/usr/include/libpng12 -I/usr/include/freetype2-I/usr/include/cairo -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2-I/usr/include/libpng12 -g -O2 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE-D_THREAD_SAFE -D_REENTRANT -std=c++11 -o 'torso_gui' 'torso_gui.o' -Wl,-Bsymbolic-functions -lfltk -lX11 
torso_gui.o:
	$(CXX) -c $(CXXOPTS) $(fltk-config --cxxflags) torso_gui.cpp
clean:
	-rm -f *.o arm_gui torso_gui


