#ifndef _APPLICATION_CPP_
#define _APPLICATION_CPP_

#include "application.h"
#include "my_drawing_area.h"

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

int Application::run()
{
    if(!builder)
    {
        return -1;
    }    
    
    Glib::RefPtr<Gtk::Adjustment> adj_x = Glib::RefPtr<Gtk::Adjustment>::cast_dynamic(builder->get_object("adjustment2"));
    MyDrawingArea *area = new MyDrawingArea(adj_x);

    Gtk::AspectFrame *frame = 0;
    builder->get_widget("aspectframe1", frame);
    frame->add(*area);
    area->show();

    builder->get_widget("window1", topLevel);
    main->run(*topLevel);
    return 0;
};


#endif // _APPLICATION_CPP_
