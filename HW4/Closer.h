//NAME - SAIRAMVINAY VIJAYARAGHAVAN

#ifndef CLOSER_H
#define CLOSER_H
class Closer{
public:

	Closer(const double current_latitude,const double current_longitude): current_lat(current_latitude),current_lon(current_longitude)
	{
		;
	}


	bool operator()(Facility *f1,Facility *f2){

		return ((f1->distance(current_lat,current_lon)) < (f2->distance(current_lat,current_lon)));
	}
    private:
	   const double current_lat;
	   const double current_lon;
};

#endif
