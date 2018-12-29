//NAME- SAIRAMVINAY VIJAYARAGHAVAN
//SID- 913603345
#include "Facility.h"
#include "gcdistance.h"
#include <sstream>
using namespace std;


Facility::Facility(string s): site_number_(s.substr(0,10)),
type_(s.substr(11,13)), code_(s.substr(24,4)), name_(s.substr(130,50))
, latitude_(convert_latitude(s)), longitude_(convert_longitude(s))
{
	;
}

string Facility::site_number(void) const{

	return site_number_;
}

string Facility::type(void) const{
	return type_;
}

string Facility::code(void) const{
	return code_;
}

string Facility::name(void) const{
	return name_;
}

double Facility::latitude(void) const{
	return latitude_;
}

double Facility::longitude(void) const{
	return longitude_;
}

double Facility::distance(double lat, double lon) const{
	return gcdistance(latitude_,longitude_,lat,lon);
}

double Facility::convert_latitude(string s) const{

	
	string substr = s.substr(535,12);
	string substr1;
	double val;
	if (substr.at(11) == 'N'){
		substr1 = s.substr(535,11);
		istringstream is(substr1);
		is>>val;
		val=val/3600.0;
	}
	else {
		substr1 = s.substr(535,11);
		istringstream is(substr1);
		is>>val;
		val = -1 * (val/3600.0) ;
	}
	
	return val;
}

double Facility::convert_longitude(string s) const{

	
	string substr1;
	string substr = s.substr(562,12);
	double val;
	if (substr.at(11) == 'E'){
		string substr1 = s.substr(562,11);
		istringstream is(substr1);
		is>>val;
		val = val/3600.0;
	}
	else {
		substr1 = s.substr(562,11);
		istringstream is(substr1);
		is>>val;
	    val = -1 * (val/3600.0) ;
	}

	return val;
}