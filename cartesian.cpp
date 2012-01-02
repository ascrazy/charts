#ifndef _CARTESIAN_CPP_
#define _CARTESIAN_CPP_

#include "cartesian.h"

Cartesian::Cartesian() :
    function(0)
{

};

void Cartesian::draw_to(Drawable* drawable)
{
    if(drawable)
    {
        draw_axis(drawable);
        if(function)
        {
            float from = function->from(), to = function->to(), step = function->step();
            drawable->begin_path();
            drawable->move_to(from, function->calculate(from));
            for(float i = from; i <= to; i += step)
            {
                drawable->line_to(i, function->calculate(i));
            }
            drawable->end_path();
        }
    }
};

void Cartesian::add_function(Function* _function)
{
    function = _function;
};

void Cartesian::draw_axis(Drawable* drawable)
{
    draw_x(drawable, -15, 15);
    draw_y(drawable, -15, 15);
    draw_x_serif(drawable, -15, 15, 1);
    draw_y_serif(drawable, -15, 15, 1);
};

void Cartesian::draw_x(Drawable* drawable, float from, float to)
{
    drawable->begin_path();
    drawable->move_to(from, 0);
    drawable->line_to(to, 0);
//    // x-arrow
//    drawable->line_to(0.01, 0.49);
//    drawable->move_to(0, 0.5);
//    drawable->line_to(-0.01, 0.49);
    drawable->move_to(0, 0);
    drawable->end_path();   
};

void Cartesian::draw_y(Drawable* drawable, float from, float to)
{
    drawable->begin_path();
    drawable->move_to(0, from);
    drawable->line_to(0, to);
//    // y-arrow
//    drawable->line_to(0.49, -0.01);
//    drawable->move_to(0.5, 0);
//    drawable->line_to(0.49, 0.01);
    drawable->move_to(0, 0);
    drawable->end_path();
};

void Cartesian::draw_x_serif(Drawable* drawable, float from, float to, float step)
{
    drawable->begin_path();
    for(float i = from; i <= to; i += step)
    {
        drawable->move_to(i, -0.1);
        drawable->line_to(i, 0.1);
    }
    drawable->move_to(0, 0);
    drawable->end_path();
};

void Cartesian::draw_y_serif(Drawable* drawable, float from, float to, float step)
{
    drawable->begin_path();
    for(float i = from; i <= to; i += step)
    {
        drawable->move_to(-0.1, i);
        drawable->line_to(0.1, i);
    }
    drawable->move_to(0, 0);
    drawable->end_path();
};

#endif // _CARTESIAN_CPP_
