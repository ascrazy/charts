#ifndef _CANVAS_H_
#define _CANVAS_H_

#include <gtkmm.h>
#include "drawable.h"

class Canvas : public Drawable
{
public:
    Canvas(Cairo::RefPtr<Cairo::Context>);
    virtual ~Canvas()=0;
    virtual void begin_path()=0;
    virtual void end_path()=0;
    virtual void line_to(float x, float y);
    virtual void move_to(float x, float y);
private:
    Cairo::RefPtr<Cairo::Context> context;
};

#endif // _CANVAS_H_
