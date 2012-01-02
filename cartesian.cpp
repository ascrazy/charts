#ifndef _CARTESIAN_CPP_
#define _CARTESIAN_CPP_

#include "cartesian.h"

Cartesian::Cartesian(Drawable* _function) :
    drawable(_drawable),
    function(0)
{

};

void Cartesian::draw()
{
    if(function && drawable)
    {
        float from = function->from(), to = function->to(), step = function->step();
        drawable->begin_path();
        drawable->move_to(from, function->calculate(from))
        for(float i = from; i <= to; i += step)
        {
            drawable->line_to(i, function->calculate(i));
        }
        drawable->end_path();
    }
};
void Cartesian::clear()
{
    
};
void Cartesian::add(Function* _function)
{
    function = _function;
};

#endif // _CARTESIAN_CPP_
