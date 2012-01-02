#ifndef _COS_CPP_
#define _COS_CPP_

#include "cos.h"

Cos::Cos(float _from = -1, float _to = 1, float _step = 0.1):
    v_from(_from),
    v_to(_to),
    v_step(_step)
{
   
};

float Cos::from()
{
    return v_from;
};

float Cos::to()
{
    return v_to;
};

float Cos::step()
{
    return v_step;
};

float Cos::calculate(float x)
{
    return cos(x * M_PI);
};

#endif // _COS_CPP_
