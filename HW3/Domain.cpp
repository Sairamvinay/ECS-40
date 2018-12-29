//NAME -SAIRAMVINAY VIJAYARAGHAVAN
//S ID- 913603345
#include <iostream>
#include "Domain.h"
using namespace std;
Domain::Domain(int sx,int sy): size_x(sx), size_y(sy){;}

void Domain::addShape(char type,int x,int y){

	Shape *sp;
	sp = Shape::makeShape(type,x,y);
	if (fits(*sp)){

		for (unsigned int i = 0; i < sList.size(); ++i)
		
		{
			
			if (sp->overlap(*(sList[i]))){
				
				delete sp;
				return;
			}
			
		}
        
		sList.push_back(sp);
		return;
	}
	
	else{


	delete sp;
	return ;
    }
}


bool Domain::fits(const Shape &s) const{

	for (int i=0;i<s.size();i++){
		
		int sx = s.getX(i);
		int sy = s.getY(i);
		if ((sx<0) || (sx>=size_x) || 
		(sy<0) || (sy >= size_y)){

			return false;
		}
	}
	return true;		
}

bool Domain::full(void) const{

	int sum_size_shape=0;
	for (unsigned int i = 0; i < sList.size(); ++i)
	{

	   sum_size_shape= sum_size_shape + (sList[i])->size();
	}

	if (sum_size_shape == (size_y * size_x))
		return true;

	return false;
}


void Domain::draw(void) const{

	cout<< "<?xml version=\"1.0\" encoding=\"utf-8\"  standalone=\"no\"?>"<<endl;
	cout<< "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\""<< endl;
	cout<< "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">"<< endl;
	cout<< "<svg width=\"670\" height=\"670\" viewBox=\"0 0 650 650\""<< endl;
	cout<< "xmlns=\"http://www.w3.org/2000/svg\""<< endl;
	cout<< "xmlns:xlink=\"http://www.w3.org/1999/xlink\" >" << endl;
	cout<< "<g transform=\"matrix(1,0,0,-1,50,650)\">" << endl;

	cout<< "<rect fill=\"white\" stroke=\"black\" x=\"0\" y=\"0\"  width=\""
	<<40 * size_x<<"\" height=\""<< 40*size_y <<"\"/>" << endl;
	

	for (unsigned int i = 0; i < sList.size(); ++i){
		(sList[i])->draw();
	}
	cout<<"</g>"<<endl;	
	cout<< "</svg>" << endl;
}



