/*
NAME - SAIRAMVINAY VIJAYARAGHAVAN
STUDENT ID - 913603345
*/

#include "Fraction.h"
#include <stdlib.h>
#include <stdexcept>

using namespace std;

/*
THIS METHOD OF FRACTION CLASS IS THE DEFAULT CONSTRUCTOR
*/
Fraction::Fraction(void){
    num = 1;
    denom =1;
}

/*
THIS METHOD OF FRACTION CLASS IS THE PARAMETERIZED CONSTRUCTOR 
*/    
Fraction::Fraction(int a, int b){
  
    int sign_factor;
    
    
    /* Adjusts sign (at most, numerator should be negative)	*/
    
    if (a * b >= 0)
       sign_factor = 1;
    else
       sign_factor = -1;

    
    a = sign_factor * abs(a);
    b = abs(b);
    red_frac(a,b);
    num=a;
    denom=b;
}

//THIS METHOD OF FRACTION CLASS REDUCES THE FRACTION
void Fraction::red_frac(int &numer, int &den){
    
    int gcd = find_gcd(numer,den);
    if(gcd == 1){
    ;
    }
      
    else{
        
        numer = numer / gcd;
        den = den / gcd;
    }
    
    int sign;
    if (numer * den>=0)
        sign =1;
    else 
        sign = -1;
    
    numer = sign * abs(numer);
    den = abs(den);
}



//THIS FUNCTION COMPUTES THE GCD OF TWO NUMBERS N1 AND N2
int find_gcd(int n1,int n2){
    int gcd, remainder;

    /* Euclid's algorithm */
    remainder = n1 % n2; 
    while ( remainder != 0 )
    {
       n1 = n2;
       n2 = remainder; 
       remainder = n1 % n2; 
    } 
    gcd = n2; 

    return (gcd);
}


//THIS FUNCTION COMPUTES THE LCM OF TWO NUMBERS N1 AND N2
int find_lcm(int n1,int n2){
    
    int lcm,gcd;
    gcd = find_gcd(n1,n2);
    lcm = (n1 * n2)/gcd;
    return lcm;
}


//THIS METHOD OF FRACTION CLASS IS A GET FUNCTION FOR THE NUMERATOR ATTRIBUTE
int Fraction::getNum(void) const{
    return num;    
}


//THIS METHOD OF FRACTION CLASS IS A GET FUNCTION FOR THE DENOMINATOR ATTRIBUTE
int Fraction::getDen(void) const{
    return denom;
}

//THIS METHOD OF CLASS FRACTION IS A SET FUNCTION FOR BOTH THE ATTRIBUTES: NUMERATOR AND DENOMINATOR 
void Fraction::setval(int n,int d){
    num=n;
    denom=d;
    red_frac(num,denom);
}


//THIS OPERATOR IS A FRIEND OVERLOADED OPERATOR - FOR THE FRACTION CLASS
Fraction& Fraction::operator=(const Fraction& rhs){
    
    if(&rhs == this) 
        return *this;
    
    num=rhs.num;
    denom=rhs.denom;
    return *this;
}


//THIS OPERATOR IS A FRIEND OVERLOADED OPERATOR + FOR THE FRACTION CLASS
const Fraction operator+(const Fraction &frac1,const Fraction &frac2){
               
               
    int lcm = find_lcm(frac1.getDen(),frac2.getDen());
    int new_num = (frac1.getNum() * lcm / frac1.getDen()) + (frac2.getNum() * lcm / frac2.getDen()) ;
    return Fraction(new_num,lcm);
}


//THIS OPERATOR IS A FRIEND OVERLOADED OPERATOR - FOR THE FRACTION CLASS
const Fraction operator-(const Fraction &frac1,const Fraction &frac2){
               
    int lcm = find_lcm(frac1.getDen(),frac2.getDen());
    int new_num = (frac1.getNum() * lcm / frac1.getDen()) - (frac2.getNum() * lcm / frac2.getDen()) ;
    return Fraction(new_num,lcm);
}
           

//THIS OPERATOR IS A FRIEND OVERLOADED OPERATOR << FOR THE FRACTION CLASS
ostream& operator << (ostream& os, const Fraction& frac){
      
    if (frac.getNum() % frac.getDen() == 0){
        os<<(frac.getNum()/frac.getDen());
        return os;
    }
    
    

    os << frac.getNum() <<"/"<<frac.getDen();
    return os;
}
           

//THIS OPERATOR IS A FRIEND OVERLOADED OPERATOR >> FOR THE FRACTION CLASS
istream& operator >> (istream& is, Fraction& frac){
    
    int numer,den;
    char slash = '/';
    is >> numer >> slash >> den;
    if (den==0){
        
        throw invalid_argument("denominator is zero");
    }
    frac.setval(numer,den);
    return is;
}
