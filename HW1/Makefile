#NAME- SAIRAMVINAY VIJAYARAGHAVAN
#STUDENT ID - 913603345

all: useFraction calculator

useFraction: useFraction.o Fraction.o
	g++ -g -Wall -o useFraction useFraction.o Fraction.o

calculator: calculator.o Fraction.o
	g++ -g -Wall -o calculator calculator.o Fraction.o

useFraction.o: useFraction.cpp 
	g++ -g -Wall -c useFraction.cpp 

calculator.o: calculator.cpp 
	g++ -g -Wall -c calculator.cpp

Fraction.o: Fraction.cpp Fraction.h
	g++ -g -Wall -c Fraction.cpp
	
execs = calculator useFraction
clean:
	rm -f $(execs) *.o 

