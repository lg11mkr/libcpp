#pragma once
#include <iostream>
using namespace std;

class Fraction
{
    int tu;
    int mau;
    // Simplify fractions
    int ucln(int a,int b);
    void simplify();
public:
    Fraction();
    Fraction(const Fraction& a);
    Fraction(const int& a);
    Fraction(int tuSo, int mauSo);
    void nhap();

    friend ostream& operator<<(ostream& os,const Fraction& a);
    Fraction& operator=(const Fraction& a);
    Fraction& operator=(const int& a);
    
    
    Fraction operator+(const Fraction& other) ;
    Fraction operator-(const Fraction& other) ;
    Fraction operator*(const Fraction& other) ;
    Fraction operator/(const Fraction& other) ;
    
    Fraction operator+(const int& other) ;
    Fraction operator-(const int& other) ;
    Fraction operator*(const int& other) ;
    Fraction operator/(const int& other) ;

    friend Fraction operator+(int a, const Fraction& other);
    friend Fraction operator-(int a, const Fraction& other);
    friend Fraction operator*(int a, const Fraction& other);
    friend Fraction operator/(int a, const Fraction& other);
    

    bool operator==(const Fraction& other);
    bool operator!=(const Fraction& other);
    bool operator<(const Fraction& other) ;
    bool operator<=(const Fraction& other) ;
    bool operator>(const Fraction& other) ;
    bool operator>=(const Fraction& other) ;
    Fraction& operator+=(const Fraction& a);
    Fraction& operator-=(const Fraction& a);
    Fraction& operator*=(const Fraction& a);
    Fraction& operator/=(const Fraction& a);

    Fraction& operator++();
    Fraction operator++(int a);
    Fraction& operator--();
    Fraction operator--(int a);

    operator int();
    operator float();
};
