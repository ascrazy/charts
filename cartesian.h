#ifndef _CARTESIAN_H_
#define _CARTESIAN_H_

#include "coordinate_system.h"

class Cartesian : public CoordinateSystem
{
public:
	Cartesian();
	virtual ~Cartesian(){};
    void draw_to(Drawable*);
    void add_function(Function*);
    void set_x_ratio(float);
    void set_y_ratio(float);
private:
    void draw_axis(Drawable*);
    void draw_x(Drawable*, float, float);
    void draw_y(Drawable*, float, float);
    void draw_x_serif(Drawable*, float, float, float);
    void draw_y_serif(Drawable*, float, float, float);
    float transfer_x(float);
    float transfer_y(float);
    Function* function;
    float x_ratio;
    float y_ratio;
};

#endif // _CARTESIAN_H_
