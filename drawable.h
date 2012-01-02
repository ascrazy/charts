#ifndef _DRAWABLE_H_
#define _DRAWABLE_H_

class Drawable
{
public:
    virtual void begin_path()=0;
    virtual void end_path()=0;
    virtual void line_to(float x, float y)=0;
    virtual void move_to(float x, float y)=0;
};

#endif // _DRAWABLE_H_
