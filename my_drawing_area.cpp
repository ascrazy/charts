#ifndef _MYDRAWINGAREA_CPP_
#define _MYDRAWINGAREA_CPP_

#include "my_drawing_area.h"
#include <stdio.h>

MyDrawingArea::MyDrawingArea(Glib::RefPtr<Gtk::Adjustment> _adj_x, Glib::RefPtr<Gtk::Adjustment> _adj_y) :
    f(new Cos(-5, 5, 0.1)),
    adj_x(_adj_x),
    adj_y(_adj_y),
    drawable(new Canvas()),
    pane(new Cartesian())
{
    pane->add_function(f);
    adj_x->signal_value_changed().connect(sigc::mem_fun(*this, &MyDrawingArea::update_view), false);
    adj_y->signal_value_changed().connect(sigc::mem_fun(*this, &MyDrawingArea::update_view), false);
};

bool MyDrawingArea::on_draw(const Cairo::RefPtr<Cairo::Context>& context)
{
    context->scale(get_allocation().get_width(), get_allocation().get_height());
    drawable->set_context(context);
    pane->draw_to(drawable);
    return true;
};

#include <stdio.h>

void MyDrawingArea::update_view()
{
    printf("%f__%f\n", adj_x->get_value(), adj_y->get_value());
    pane->set_x_ratio(adj_x->get_value());
    pane->set_y_ratio(adj_y->get_value());
    Glib::RefPtr<Gdk::Window> win = get_window();
    if (win)
    {
        Gdk::Rectangle r(0, 0, get_allocation().get_width(), get_allocation().get_height());
        win->invalidate_rect(r, false);
    }  
};

#endif // _MYDRAWINGAREA_CPP_