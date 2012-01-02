#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <gtkmm.h>
#include <iostream>

class Application{
public:
    Application(int, char**);
    ~Application(){};
    int run();
private:
    Gtk::Main *main;
    Gtk::Window *topLevel;
    Glib::RefPtr<Gtk::Builder> builder;
};

#endif // _APPLICATION_H_
