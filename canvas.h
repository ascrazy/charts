#ifndef _CANVAS_H_
#define _CANVAS_H_

#include <gtkmm.h>
#include "drawable.h"

class Canvas : public Drawable
{
public:
    Canvas(Cairo::RefPtr<Cairo::Context>);
    virtual ~Canvas(){};
    void begin_path();
    void end_path();
    void line_to(float x, float y);
    void move_to(float x, float y);
private:
    Cairo::RefPtr<Cairo::Context> context;
    float transfer_x(float);
    float transfer_y(float);
};

#endif // _CANVAS_H_
