#ifndef _APPLICATION_CPP_
#define _APPLICATION_CPP_

#include "application.h"

Application::Application(int argc, char **argv) :
    main(new Gtk::Main(argc, argv)),
    topLevel(0),
    builder(Gtk::Builder::create())
{
    try
    {
        builder->add_from_file("resources/mainwindow.glade");
    } 
    catch(const Glib::FileError& ex)
    {
        std::cerr << "FileError: " << ex.what() << std::endl;
    } 
    catch(const Gtk::BuilderError& ex)
    {
        std::cerr << "BuilderError: " << ex.what() << std::endl;        
    } 
};

bool Application::draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
    cr->scale(600, 600);
    cr->set_line_width(0.001);
    cr->set_source_rgba(0.999, 0.0, 0.0, 1.0);
    Drawable *c = new Canvas(cr);
    CoordinateSystem *s = new Cartesian(c);
    Function *f = new Cos(-5, 5, 0.1);
    s->add(f);
    s->draw();
}

int Application::run()
{
    if(!builder)
    {
        return -1;
    }
    
    Gtk::DrawingArea *area = 0;
    builder->get_widget("drawingarea1", area);
    area->signal_draw().connect(sigc::mem_fun(*this, &Application::draw), false);
    area->show();

    builder->get_widget("window1", topLevel);
    topLevel->add(*area);

    main->run(*topLevel);
    return 0;
};


#endif // _APPLICATION_CPP_
