CC=/usr/bin/gcc
CPP=/usr/bin/g++ -std=c++0x
FLAGS=`pkg-config --cflags gtkmm-3.0`
LIBS=`pkg-config --libs gtkmm-3.0`

all: canvas application main
	$(CPP) main.o application.o canvas.o $(LIBS) -o main

main: 
	$(CPP) main.cpp $(FLAGS) -c -o main.o

application:
	$(CPP) application.cpp $(FLAGS) -c -o application.o

canvas:
	$(CPP) canvas.cpp $(FLAGS) -c -o canvas.o

clean:
	rm -f *.o
	rm -f main
