#ifndef _COS_H_
#define _COS_H_

#include <math.h>
#include "accessors.h"
#include "function.h"

class Cos : public Function
{
public:
    Cos(float, float, float);
	virtual ~Cos()=0;
    virtual float from();
    virtual float to();
    virtual float step();
    virtual float calculate(float);
    ACCESSOR(float, v_from)
    ACCESSOR(float, v_to)
    ACCESSOR(float, v_step)
private:
    float v_from;
    float v_to;
    float v_step;
};

#endif // _COS_H_
