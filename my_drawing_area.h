#ifndef _MYDRAWINGAREA_H_
#define _MYDRAWINGAREA_H_

#include <gtkmm.h>
#include "canvas.h"
#include "cartesian.h"
#include "cos.h"

class MyDrawingArea : public Gtk::DrawingArea{
public:
    MyDrawingArea(Glib::RefPtr<Gtk::Adjustment>);
    virtual ~MyDrawingArea(){};
protected:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);
    void update_view();
private:
    Canvas* drawable;
    CoordinateSystem* pane;
    Function* f;
    Glib::RefPtr<Gtk::Adjustment> adj_x;
};

#endif // _MYDRAWINGAREA_H_
