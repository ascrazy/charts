#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <gtkmm.h>
#include <iostream>
#include "canvas.h"

class Application{
public:
    Application(int, char**);
    virtual ~Application(){};
    int run();
private:
    Gtk::Main *main;
    Glib::RefPtr<Gtk::Builder> builder;
    Gtk::Window *topLevel;
};

#endif // _APPLICATION_H_
