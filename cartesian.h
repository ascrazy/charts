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
private:
    void draw_axis(Drawable*);
    void draw_x(Drawable*, float, float);
    void draw_y(Drawable*, float, float);
    void draw_x_serif(Drawable*, float, float, float);
    void draw_y_serif(Drawable*, float, float, float);
    Function* function;
};

#endif // _CARTESIAN_H_
