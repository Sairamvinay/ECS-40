#NAME -SAIRAMVINAY VIJAYARAGHAVAN


all: fill

fill: fill.o Shape.o Domain.o
	g++ -g -Wall -o fill fill.o Shape.o Domain.o

fill.o: fill.cpp Shape.h Domain.h
	g++ -g -Wall -c fill.cpp

Shape.o: Shape.cpp Shape.h 
	g++ -g -Wall -c Shape.cpp

Domain.o: Domain.cpp Domain.h Shape.h
	g++ -g -Wall -c Domain.cpp


clean:
	rm -f fill *.o
