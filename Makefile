#declare variable
CXX = g++
CXXOPTS = -std=c++11
FLTKFLAGS =  -I/usr/include/cairo -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng12 -I/usr/include/freetype2 -I/usr/include/cairo -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng12 -g -O2 -fvisibility-inlines-hidden -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_THREAD_SAFE -D_REENTRANT 
LDFLAGS = -Wl,-Bsymbolic-functions /usr/lib/x86_64-linux-gnu/libfltk_images.a /usr/lib/x86_64-linux-gnu/libfltk.a -lXfixes -lXext -lpthread -ldl -lm -lX11
all: sprint
sprint: boss_menu.h
	$(CXX) $(CXXOPTS) $(FLTKFLAGS)$(LDFLAGS)  -o 'boss_menu' 'boss_menu.cpp' -Wl,-Bsymbolic-functions -lfltk_images -lfltk -lX11 
	