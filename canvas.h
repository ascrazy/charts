#ifndef _CANVAS_H_
#define _CANVAS_H_

#include <gtkmm.h>
#include <iostream>
#include <stdio.h>

#define F(x) cos(x)+sin(x)

class Canvas : public Gtk::DrawingArea {
public:
    Canvas(Glib::RefPtr<Gtk::Adjustment>, Glib::RefPtr<Gtk::Adjustment>, Gtk::ColorButton*);
    virtual ~Canvas(){};
    float get_scale_y();
    float set_scale_y(float);
    float get_scale_x();
    float set_scale_x(float);
    // Gdk::Color* get_color();
    // Gdk::Color* set_color(Gdk::Color);
protected:
    virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>&);
private:
    void update();
    void update_scale_y();
    void update_scale_x();
    void update_color();
    float x(float);
    float y(float);
    void set_up_axis(Cairo::RefPtr<Cairo::Context>);
    void draw_serif(Cairo::RefPtr<Cairo::Context>);
    float scale_y;
    float scale_x;
    Glib::RefPtr<Gtk::Adjustment> adjustment_y;
    Glib::RefPtr<Gtk::Adjustment> adjustment_x;
    Gtk::ColorButton *color_button;
    Gdk::Color *color;
};

#endif // _CANVAS_H_
