#ifndef _CANVAS_H_
#define _CANVAS_H_

#include <cairomm/context.h>
#include "drawable.h"
#include "accessors.h"

class Canvas : public Drawable
{
public:
    Canvas();
    virtual ~Canvas(){};
    void begin_path();
    void end_path();
    void line_to(float x, float y);
    void move_to(float x, float y);
    void set_context(Cairo::RefPtr<Cairo::Context>);
    ACCESSOR(float, x_ratio)
private:
    Cairo::RefPtr<Cairo::Context> context;
    float transfer_x(float);
    float transfer_y(float);
    float x_ratio;
};

#endif // _CANVAS_H_
