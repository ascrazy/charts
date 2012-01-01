
#ifndef _CANVAS_CPP_
#define _CANVAS_CPP_

#include "canvas.h"

float Canvas::y(float c){
    return 0.03 * c * scale_y;
};

float Canvas::x(float c){
    return 0.03 * c * scale_x;
}

Canvas::Canvas(
        Glib::RefPtr<Gtk::Adjustment> adj_y, 
        Glib::RefPtr<Gtk::Adjustment> adj_x,
        Gtk::ColorButton *color_btn) : 
    adjustment_y(adj_y), 
    adjustment_x(adj_x),
    scale_y(1),
    scale_x(1),
    color_button(color_btn),
    color(new Gdk::Color())
    {
    color->set_rgb_p(0.999, 0.0, 0.0);
    signal_draw().connect(sigc::mem_fun(*this, &Canvas::on_draw), false);
    adjustment_y->set_value(scale_y);
    adjustment_x->set_value(scale_x);
    adjustment_y->signal_value_changed().connect(sigc::mem_fun(*this, &Canvas::update_scale_y), false);
    adjustment_x->signal_value_changed().connect(sigc::mem_fun(*this, &Canvas::update_scale_x), false);
    color_button->set_color(*color);
    color_button->signal_color_set().connect(sigc::mem_fun(*this, &Canvas::update_color), false);
};

bool Canvas::on_draw(const Cairo::RefPtr<Cairo::Context>& context){
    set_up_axis(context);
    draw_serif(context);
    context->save();
    context->set_line_width(0.005);
    context->set_source_rgba(color->get_red_p(), color->get_green_p(), color->get_blue_p(), 1);
    context->move_to(y(F(-10)), x(-10));
    for(float i = -10; i <= 10; i += 0.01){
         context->line_to(y(F(i * PI)), x(i * PI));
    }
    context->stroke();
    context->restore();
    return 0;
};

void Canvas::set_up_axis(Cairo::RefPtr<Cairo::Context> context){
    Gtk::Allocation allocation = get_allocation();
    const int width = allocation.get_width();
    const int height = allocation.get_height();
    context->scale(width, height);
    context->translate(0.5, 0.5);
    context->rotate_degrees(-90);
    context->save();
    context->set_line_width(0.001);
    context->set_source_rgba(0, 0, 0, 1);
    context->move_to(0, -0.5);
    context->line_to(0, 0.5);
    // x-arrow
    context->line_to(0.01, 0.49);
    context->move_to(0, 0.5);
    context->line_to(-0.01, 0.49);
    // 
    context->move_to(-0.5, 0);
    context->line_to(0.5, 0);
    // y-arrow
    context->line_to(0.49, -0.01);
    context->move_to(0.5, 0);
    context->line_to(0.49, 0.01);
    //
    context->move_to(0, 0);
    context->stroke();
    context->restore();
};

void Canvas::draw_serif(Cairo::RefPtr<Cairo::Context> context){
    context->save();
    context->set_line_width(0.001);
    context->set_source_rgba(0, 0, 0, 1);
    // x-serif
    for(float i = -20; i <= 20; i += 0.5){
        context->move_to(-0.01, x(i  * M_PI));
        context->line_to(0.01, x(i * M_PI));
    }
    // y-serif
    for(float i = -20; i <= 20; i += 1){
        context->move_to(y(i), -0.01);
        context->line_to(y(i), 0.01);
    }

    context->move_to(0, 0);
    context->stroke();
    context->restore();
};

void Canvas::update(){
    Glib::RefPtr<Gdk::Window> win = get_window();
    if (win)
    {
        Gdk::Rectangle r(0, 0, get_allocation().get_width(),
                get_allocation().get_height());
        win->invalidate_rect(r, false);
    }  
};

float Canvas::get_scale_y(){
    return scale_y;
};

float Canvas::set_scale_y(float y){
    scale_y = y;
    return scale_y;
};

void Canvas::update_scale_y(){
    set_scale_y(adjustment_y->get_value());
    update();
};


float Canvas::get_scale_x(){
    return scale_x;
};

float Canvas::set_scale_x(float x){
    scale_x = x;
    return scale_x;
};

void Canvas::update_scale_x(){
    set_scale_x(adjustment_x->get_value());
    update();
};

// Gdk::Color* Canvas::get_color(){
//     return color;
// };

// Gdk::Color* Canvas::set_color(Gdk::Color _color){
//     color = &_color;
//     return color;
// }

void Canvas::update_color(){
    *color = color_button->get_color();
    update();
}

#endif // _CANVAS_CPP_
