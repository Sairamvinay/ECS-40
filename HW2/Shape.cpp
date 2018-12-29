//NAME -SAIRAMVINAY VIJAYARAGHAVAN
//S ID- 913603345
#include <iostream>
#include <stdexcept>
#include "Shape.h"
using namespace std;

Shape::~Shape(void){
    delete x;
	delete y;
}

void Shape::print(void) const{
    char type = name();
    int len = size();
    cout<<type<<" at";
    for (int i=0;i<len;i++){
    	cout<<" ("<<x[i]<<","<<y[i]<<")";
    }
    cout<<endl;
} 

void Shape::move(int dx, int dy){
	int len = size();
	for (int i=0;i<len;i++){
		x[i]=x[i]+dx;
		y[i]=y[i]+dy;
	}
}

bool Shape::overlap(const Shape &s) const{

	int size1 = size();
	int size2 = s.size();
	for (int i=0;i<size1;i++){
		for (int j=0;j<size2;j++){
			if ((x[i]==(s.x)[j]) && (y[i] == (s.y)[j]))
				return true;
		}
	}
	return false;
}

Shape* Shape::makeShape(char ch, int posx, int posy){



	if (ch=='O') return new O(posx,posy);
	else if (ch=='I') return new I(posx,posy);
	else if (ch=='L') return new L(posx,posy);
	else if (ch=='S') return new S(posx,posy);
	else if (ch=='X') return new X(posx,posy);
	else if (ch=='U') return new U(posx,posy);
	

	else {

		throw invalid_argument("invalid type");
	}

	return 0;
}

O::O(int posx, int posy){
	x = new int[1];
	y = new int[1];
	*x = posx;
	*y = posy;
}

char O::name(void) const{
	return 'O';
}

int O::size(void) const{
	return 1;
}

I::I(int posx, int posy){
	x = new int[2];
	y = new int[2];
	x[0] = posx;
	y[0] = posy;
	x[1] = posx;
	y[1] = posy + 1;
}

char I::name(void) const{
	return 'I';
}

int I::size(void) const{
	return 2; 
}

L::L(int posx,int posy){
	x = new int[3];
	y = new int[3];
	x[0] = posx;
	y[0] = posy;
	x[1] = posx + 1;
	y[1] = posy;
	x[2] = posx;
	y[2] = posy + 1;
}

char L::name(void) const{
	return 'L';
}

int L::size(void) const{
	return 3;
}

S::S(int posx,int posy){
	x = new int[4];
	y = new int[4];
	x[0] = posx;
	y[0] = posy;
	x[1] = posx + 1;
	y[1] = posy;
	x[2] = posx + 1;
	y[2] = posy + 1;
	x[3] = posx + 2;
	y[3] = posy + 1; 
}

char S::name(void) const{
	return 'S';
}

int S::size(void) const{
	return 4;
}

X::X(int posx, int posy){
	x = new int[5];
	y = new int[5];
	x[0] = posx;
	y[0] = posy;
	x[1] = posx - 1;
	y[1] = posy + 1;
	x[2] = posx ;
	y[2] = posy + 1;
	x[3] = posx + 1;
	y[3] = posy + 1;
	x[4] = posx ;
	y[4] = posy + 2; 
}

char X::name(void) const{
	return 'X';
}

int X::size(void) const{
	return 5;
}

U::U(int posx, int posy){
	x = new int[7];
	y = new int[7];
	x[0] = posx;
	y[0] = posy;
	x[1] = posx + 1;
	y[1] = posy;
	x[2] = posx + 2;
	y[2] = posy;
	x[3] = posx;
	y[3] = posy + 1;
	x[4] = posx + 2;
	y[4] = posy + 1;
	x[5] = posx;
	y[5] = posy + 2;
	x[6] = posx + 2;
	y[6] = posy + 2; 
}

char U::name(void) const{
	return 'U';
}

int U::size(void) const{
	return 7;
}