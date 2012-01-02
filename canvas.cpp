
#ifndef _CANVAS_CPP_
#define _CANVAS_CPP_

#include "canvas.h"

Canvas::Canvas(Cairo::RefPtr<Cairo::Context> _context) :
    context(_context) 
{
     context->translate(0.5, 0.5);
     context->rotate_degrees(-90);
}

void Canvas::line_to(float x, float y)
{
    context->line_to(transfer_y(y), transfer_x(x));
}

void Canvas::move_to(float x, float y)
{
    context->move_to(transfer_y(y), transfer_x(x));
}

void Canvas::begin_path()
{
    context->save();
};

void Canvas::end_path()
{
    context->stroke();
    context->restore();
};

float Canvas::transfer_x(float x)
{
    return 0.03 * x;
};

float Canvas::transfer_y(float y)
{
    return 0.03 * y;
};

// float Canvas::y(float c){
//     return 0.03 * c * scale_y;
// };

// float Canvas::x(float c){
//     return 0.03 * c * scale_x;
// }

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
// };

// void Canvas::update(){
//     Glib::RefPtr<Gdk::Window> win = get_window();
//     if (win)
//     {
//         Gdk::Rectangle r(0, 0, get_allocation().get_width(),
//                 get_allocation().get_height());
//         win->invalidate_rect(r, false);
//     }  
// };

#endif // _CANVAS_CPP_
