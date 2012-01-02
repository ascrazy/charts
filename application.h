#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <gtkmm.h>
#include <iostream>
#include "cos.h"
#include "canvas.h"
#include "cartesian.h"

class Application{
public:
    Application(int, char**);
    ~Application(){};
    int run();
    bool draw(const Cairo::RefPtr<Cairo::Context>& cr);
private:
    Gtk::Main *main;
    Gtk::Window *topLevel;
    Glib::RefPtr<Gtk::Builder> builder;
};

#endif // _APPLICATION_H_
