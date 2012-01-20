#ifndef _COORDINATESYSTEM_H_
#define _COORDINATESYSTEM_H_

#include "function.h"
#include "drawable.h"

class CoordinateSystem
{
public:
    virtual void draw_to(Drawable*)=0;
    virtual void add_function(Function*)=0;
    virtual void set_x_ratio(float)=0;
    virtual void set_y_ratio(float)=0;
};

#endif // _COORDINATESYSTEM_H_
