//NAME- SAIRAMVINAY VIJAYARAGHAVAN
#ifndef SITENUMBER_H
#define SITENUMBER_H

class SiteNumber{
public:
	SiteNumber(std::string sitenumber): fsiteno(sitenumber)
	{;}

	bool operator()(Runway *r){
		return ((r->site_number()) == fsiteno);
	}



private:
	const std::string fsiteno;
};
#endif
