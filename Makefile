CC=/usr/bin/gcc
CPP=/usr/bin/g++ -std=c++0x
FLAGS=`pkg-config --cflags gtkmm-3.0`
LIBS=`pkg-config --libs gtkmm-3.0`

all: main
	$(CPP) main.o application.o canvas.o cartesian.o cos.o $(LIBS) -o main

main: application
	$(CPP) main.cpp $(FLAGS) -c -o main.o

application: cos canvas cartesian
	$(CPP) application.cpp $(FLAGS) -c -o application.o

cos: function
	$(CPP) cos.cpp -c -o cos.o

canvas: drawable
	$(CPP) canvas.cpp $(FLAGS) -c -o canvas.o

cartesian: coordinate_system
	$(CPP) cartesian.cpp -c -o cartesian.o

# INTERFACES

function:
	$(CPP) function.h -c -o function.o

drawable:
	$(CPP) drawable.h -c -o drawable.o

coordinate_system: function drawable
	$(CPP) coordinate_system.h -c -o coordinate_system.o

clean:
	rm -f *.o
	rm -f main
