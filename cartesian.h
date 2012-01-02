#ifndef _CARTESIAN_H_
#define _CARTESIAN_H_

#include "coordinate_system.h"

class Cartesian : public CoordinateSystem
{
public:
	Cartesian(Drawable*);
	virtual ~Cartesian(){};
    void draw();
    void add(Function*);
private:
    void draw_axis();
    void draw_x(float, float);
    void draw_y(float, float);
    void draw_x_serif(float, float, float);
    void draw_y_serif(float, float, float);
    Drawable* drawable;
    Function* function;
};

#endif // _CARTESIAN_H_
