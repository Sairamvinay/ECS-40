/*
NAME - SAIRAMVINAY VIJAYARAGHAVAN

*/
#include <iostream>
#ifndef FRACTION_H
 #define FRACTION_H
   int find_gcd(int n1,int n2);
   int find_lcm(int n1,int n2);
    
   class Fraction{
       
       private: 
          
           int num,denom;
       
       public:
           
           Fraction(void);
           Fraction(int a,int b);
           int getNum(void) const;
           int getDen(void) const;
           void setval(int n,int d);
           Fraction &operator=(const Fraction& rhs);
           void red_frac(int &numer,int &den);
           friend const Fraction operator+(const Fraction &frac1,const Fraction &frac2);
           friend const Fraction operator-(const Fraction &frac1, const Fraction &frac2);
           friend std::ostream& operator << (std::ostream& os, const Fraction& frac);
           friend std::istream& operator >> (std::istream& is, Fraction& frac);
          
            
  };

#endif
