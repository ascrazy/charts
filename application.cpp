#ifndef _APPLICATION_CPP_
#define _APPLICATION_CPP_

#include "application.h"

Application::Application(int argc, char **argv) :
    main(new Gtk::Main(argc, argv)),
    builder(Gtk::Builder::create()),
    topLevel(0)
    {};

int Application::run(){
    try {
        builder->add_from_file("resources/mainwindow.glade");
    } catch(const Glib::FileError& ex) {
        std::cerr << "FileError: " << ex.what() << std::endl;
        return -1;
    } catch(const Gtk::BuilderError& ex) {
        std::cerr << "BuilderError: " << ex.what() << std::endl;
        return -1;
    } 
    
    Gtk::AspectFrame *frame = 0;
    builder->get_widget("aspectframe1", frame);

    // Glib::RefPtr<Gtk::Adjustment> adj_y = Glib::RefPtr<Gtk::Adjustment>::cast_dynamic(builder->get_object("adjustment1"));
    // Glib::RefPtr<Gtk::Adjustment> adj_x = Glib::RefPtr<Gtk::Adjustment>::cast_dynamic(builder->get_object("adjustment2"));
    // Gtk::ColorButton *color = 0;
    // builder->get_widget("colorbutton1", color);

    Gtk::DrawingArea *area = new Gtk::DrawingArea(adj_y, adj_x, color);
    frame->add(*area);
    area->show();

    Cairo::RefPtr<Cairo::Context> context = area.get_window()->create_cairo_context();
    Drawable *c = new Canvas(context);
    CoordiateSystem *s = new Cartesian(c);
    Function *f = new Cos();
    c.add(f);
    c.draw();
    

    builder->get_widget("window1", topLevel);    
    main->run(*topLevel);

    return 0;
};


#endif // _APPLICATION_CPP_
