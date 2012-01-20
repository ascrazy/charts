#ifndef _CARTESIAN_CPP_
#define _CARTESIAN_CPP_

#include "cartesian.h"

Cartesian::Cartesian() :
    function(0),
    x_ratio(1),
    y_ratio(1)
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
            drawable->move_to(transfer_x(from), transfer_y(function->calculate(from)));
            for(float i = from; i <= to; i += step)
            {
                drawable->line_to(transfer_x(i), transfer_y(function->calculate(i)));
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
        drawable->move_to(transfer_x(i), -0.1);
        drawable->line_to(transfer_x(i), 0.1);
    }
    drawable->move_to(0, 0);
    drawable->end_path();
};

void Cartesian::draw_y_serif(Drawable* drawable, float from, float to, float step)
{
    drawable->begin_path();
    for(float i = from; i <= to; i += step)
    {
        drawable->move_to(-0.1, transfer_y(i));
        drawable->line_to(0.1, transfer_y(i));
    }
    drawable->move_to(0, 0);
    drawable->end_path();
};

#include <stdio.h>

void Cartesian::set_x_ratio(float _x)
{
    printf("x==%f\n", _x);
    this->x_ratio = _x;
};

void Cartesian::set_y_ratio(float _y)
{
    printf("y==%f\n", _y);
    this->y_ratio = _y;
};

float Cartesian::transfer_x(float _x)
{
    return _x * this->x_ratio;
};

float Cartesian::transfer_y(float _y)
{
    return _y * this->y_ratio;
};


#endif // _CARTESIAN_CPP_
