#ifndef _MYDRAWINGAREA_CPP_
#define _MYDRAWINGAREA_CPP_

#include "my_drawing_area.h"
#include <stdio.h>

MyDrawingArea::MyDrawingArea(Glib::RefPtr<Gtk::Adjustment> _adj_x) :
    f(new Cos(-5, 5, 0.1)),
    adj_x(_adj_x),
    drawable(new Canvas()),
    pane(new Cartesian())
{
    pane->add_function(f);
    if(adj_x)
    {
        adj_x->signal_value_changed().connect(sigc::mem_fun(*this, &MyDrawingArea::update_view), false);
    }
// Canvas::Canvas(
//         Glib::RefPtr<Gtk::Adjustment> adj_y, 
//         Glib::RefPtr<Gtk::Adjustment> adj_x,
//         Gtk::ColorButton *color_btn) : 
//     adjustment_y(adj_y), 
//     adjustment_x(adj_x),
//     scale_y(1),
//     scale_x(1),
//     color_button(color_btn),
//     color(new Gdk::Color())
//     {
//     color->set_rgb_p(0.999, 0.0, 0.0);
//     signal_draw().connect(sigc::mem_fun(*this, &Canvas::on_draw), false);
//     adjustment_y->set_value(scale_y);
//     adjustment_x->set_value(scale_x);
//     adjustment_y->signal_value_changed().connect(sigc::mem_fun(*this, &Canvas::update_scale_y), false);
//     adjustment_x->signal_value_changed().connect(sigc::mem_fun(*this, &Canvas::update_scale_x), false);
//     color_button->set_color(*color);
//     color_button->signal_color_set().connect(sigc::mem_fun(*this, &Canvas::update_color), false);
};

bool MyDrawingArea::on_draw(const Cairo::RefPtr<Cairo::Context>& context)
{
    context->scale(get_allocation().get_width(), get_allocation().get_height());
    drawable->set_context(context);
    pane->draw_to(drawable);
    return true;
};

void MyDrawingArea::update_view()
{
    if(drawable)
    {
        if(adj_x)
        {
            drawable->set_x_ratio(adj_x->get_value());
        }
    }
    Glib::RefPtr<Gdk::Window> win = get_window();
    if (win)
    {
        Gdk::Rectangle r(0, 0, get_allocation().get_width(), get_allocation().get_height());
        win->invalidate_rect(r, false);
    }  
};

#endif // _MYDRAWINGAREA_CPP_