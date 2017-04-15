#include <stdio.h>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>
#include <FL/Fl.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Menu_Button.H>
#include <FL/fl_draw.H>
#include <iostream>


class Fl_Input_Choice : public Fl_Group {
    // Private class to handle slightly 'special' behavior of menu button
    class InputMenuButton : public Fl_Menu_Button {
	void draw() {
	    draw_box(FL_UP_BOX, color());
	    fl_color(active_r() ? labelcolor() : fl_inactive(labelcolor()));
	    int xc = x()+w()/2, yc=y()+h()/2;
	    fl_polygon(xc-5,yc-3,xc+5,yc-3,xc,yc+3);
	    if (Fl::focus() == this) draw_focus();
	}
    public:
	InputMenuButton(int x,int y,int w,int h,const char*l=0) : 
	    Fl_Menu_Button(x,y,w,h,l) { box(FL_UP_BOX); }
    };

    Fl_Input *_inp;
    InputMenuButton *_menu;

    static void _menu_cb(Fl_Widget*, void *data) { 
        Fl_Input_Choice *o=(Fl_Input_Choice *)data;
	o->_menu_cb2(); 
    }
    void _menu_cb2() {
       std:: cout << _inp->value(_menu->text()) << "\n ";
    }

    // Custom resize behavior -- input stretches, menu button doesn't
    inline int _InpSizeX() { return(x() + Fl::box_dx(box())); }
    inline int _InpSizeY() { return(y() + Fl::box_dy(box())); }
    inline int _InpSizeW() { return(w() - Fl::box_dw(box()) - 20); }
    inline int _InpSizeH() { return(h() - Fl::box_dh(box())); }

    inline int _MenuSizeX() { return(x() + w() - 20 - Fl::box_dx(box())); }
    inline int _MenuSizeY() { return(y() + Fl::box_dy(box()) + (Fl::scheme()?1:0)); }
    inline int _MenuSizeW() { return(20); }
    inline int _MenuSizeH() { return(h() - Fl::box_dh(box()) - (Fl::scheme()?1:0)); }

    void resize(int X, int Y, int W, int H) {
	Fl_Group::resize(X,Y,W,H);
	_inp->resize(_InpSizeX(), _InpSizeY(), _InpSizeW(), _InpSizeH());
	_menu->resize(_MenuSizeX(), _MenuSizeY(), _MenuSizeW(), _MenuSizeH());
    }

public:
    Fl_Input_Choice (int x,int y,int w,int h,const char*l=0) : Fl_Group(x,y,w,h,l) {
	Fl_Group::box(FL_DOWN_BOX);
	align(FL_ALIGN_LEFT);				// default like Fl_Input
        _inp = new Fl_Input(_InpSizeX(), _InpSizeY(),
			    _InpSizeW(), _InpSizeH());
 	if (!Fl::scheme()) { _inp->box(FL_FLAT_BOX); }		// cosmetic
	_menu = new InputMenuButton(_MenuSizeX(), _MenuSizeY(),
				    _MenuSizeW(), _MenuSizeH());
	_menu->callback(_menu_cb, (void*)this);
	_menu->box(FL_FLAT_BOX);				// cosmetic
	end();
    }
    void menuvalue(int val) {
        _menu->value(val);
	_inp->value(_menu->text(val));
    }
    void inputvalue(const char *val) {
	_inp->value(val);
    }
    const char* inputvalue() const {
	return(_inp->value());
    }
    
    const char* value() const {
	return(inputvalue());
    }
    void value(int val) {
	menuvalue(val);
    }
    Fl_Menu_Button& menubutton() { return(*_menu); }
    Fl_Input& input() { return(*_inp); }
};




void buttcb(Fl_Widget*,void*data) 
{
    Fl_Input_Choice *in=(Fl_Input_Choice *)data;
    static int flag = 1;
    flag ^= 1;
    if ( flag ) in->activate();
    else        in->deactivate();
}


/**************************************************/
int main(int argc, char **argv) {
   
    Fl_Window win(400, 200);
    Fl_Input_Choice in(200,40,100,28,"Choose Components");
    in.menubutton().add("Arm");
    in.menubutton().add("Torso");
    in.menubutton().add("Locomotor");
    in.menubutton().add("Head");
    in.menubutton().add("Battery");  

    in.menuvalue(0);
    Fl_Button onoff(40,150,200,28,"Activate/Deactivate");
    onoff.callback(buttcb, (void*)&in);
    win.end();
    win.resizable(win);
    win.show(argc, argv);
    return Fl::run();
}

