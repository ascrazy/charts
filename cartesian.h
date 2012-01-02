#ifndef _CARTESIAN_H_
#define _CARTESIAN_H_

#include "coordinate_system"

class Cartesian : public CoordinateSystem
{
public:
	Cartesian(Drawable*);
	virtual ~Cartesian()=0;
    virtual void draw()=0;
    virtual void clear()=0;
    virtual void add(Function*)=0;
private:
    Drawable* drawable
    Function* function;
};

#endif // _CARTESIAN_H_
