
#ifndef _CANVAS_CPP_
#define _CANVAS_CPP_

#include "canvas.h"

Canvas::Canvas() :
    x_ratio(1)
{

};

void Canvas::line_to(float x, float y)
{
    if(context)
    {
        context->line_to(transfer_y(y), transfer_x(x));
    }
};

void Canvas::move_to(float x, float y)
{
    if(context)
    {
        context->move_to(transfer_y(y), transfer_x(x));
    }
};

void Canvas::begin_path()
{
    if(context)
    {
        context->save();
    }
};

void Canvas::end_path()
{
    if(context)
    {
        context->stroke();
        context->restore();
    }
};

void Canvas::set_context(Cairo::RefPtr<Cairo::Context> _context)
{
    context = _context;
    context->set_line_width(0.001);
    context->set_source_rgba(0.999, 0.0, 0.0, 1.0);
    context->translate(0.5, 0.5);
    context->rotate_degrees(-90);
};

float Canvas::transfer_x(float x)
{
    return 0.03 * x * x_ratio;
};

float Canvas::transfer_y(float y)
{
    return 0.03 * y;
};

#endif // _CANVAS_CPP_
