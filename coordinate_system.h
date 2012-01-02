#ifndef _COORDINATESYSTEM_H_
#define _COORDINATESYSTEM_H_

#include "function.h"
#include "drawable.h"

class CoordinateSystem{
public:
    virtual void draw()=0;
    virtual void clear()=0;
    virtual void add(Function*)=0;
};

#endif // _COORDINATESYSTEM_H_
