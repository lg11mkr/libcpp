#include "Fraction.h"
int Fraction::ucln(int a, int b)
{
    if (a % b == 0)
    {
        return b;
    }
    return ucln(b, a % b);
}
void Fraction::simplify()
{
    int a = ucln(tu, mau);
    this->tu /= a;
    this->mau /= a;
}
//----------------------------------------------------------------
Fraction::Fraction()
{
    this->tu = 0;
    this->mau = 1;
}
Fraction::Fraction(int tuSo, int mauSo)
{
    this->tu = tuSo;
    this->mau = mauSo;
    if (mauSo==0){
        return;
    }
    simplify();
}
Fraction::Fraction(const int& a)
{
    this->tu = a;
    this->mau = 1;
    simplify();
}
Fraction::Fraction(const Fraction &a)
{
    this->tu = a.tu;
    this->mau = a.mau;
}

void Fraction::nhap()
{
    int t, m;
    cout << "Nhap tu so: ";
    cin >> t;
    do
    {
        cout << "Nhap mau so( !=0): ";
        cin >> m;
    } while (m == 0);
    this->tu = t;
    this->mau = m;
    simplify();
} 
ostream& operator<<(ostream& os,const Fraction& a){
    if (a.tu%a.mau==0)
        os<<(int)a.tu/a.mau;
    else
        os<< a.tu << "/" << a.mau;
    return os;
}
Fraction &Fraction::operator=(const Fraction &a)
{
    if (a.mau == 0){
        return *this;
    }
    this->tu = a.tu;
    this->mau = a.mau;
    return *this;
}
Fraction &Fraction::operator=(const int &a)
{
    if (a == 0){
        return *this;
    }
    this->tu = a;
    this->mau = 1;
    return *this;
}

Fraction Fraction::operator+(const Fraction &other)
{
    int tuSo = tu * other.mau + other.tu * mau;
    int mauSo = mau * other.mau;
    return Fraction(tuSo, mauSo);
}

Fraction Fraction::operator-(const Fraction &other)
{
    int tuSo = tu * other.mau - other.tu * mau;
    int mauSo = mau * other.mau;
    return Fraction(tuSo, mauSo);
}

Fraction Fraction::operator*(const Fraction &other)
{
    int tuSo = tu * other.tu;
    int mauSo = mau * other.mau;
    return Fraction(tuSo, mauSo);
}

Fraction Fraction::operator/(const Fraction &other)
{
    if (other.tu ==0 || other.mau == 0)
    {
        cout << "Cannot divide by zero!"<<endl;
        return Fraction(0,0);
    }
    int tuSo = tu * other.mau;
    int mauSo = mau * other.tu;
    return Fraction(tuSo, mauSo);
}
// ---------------------
Fraction Fraction::operator+(const int &other)
{
    int tuSo = tu + other * mau;
    return Fraction(tuSo, mau);
}

Fraction Fraction::operator-(const int &other)
{
    int tuSo = tu - other * mau;
    return Fraction(tuSo, mau);
}

Fraction Fraction::operator*(const int &other)
{
    int tuSo = tu * other;
    return Fraction(tuSo, mau);
}

Fraction Fraction::operator/(const int &other)
{
    if (other == 0)
    {
        cout << "Cannot divide by zero!"<<endl;
        return Fraction(0,0);
    }
    int mauSo = mau * other;
    return Fraction(tu, mauSo);
}
//------------------------------------------
Fraction operator+(int a, const Fraction &other)
{
    int tuSo = a* other.mau + other.tu;
    return Fraction(tuSo, other.mau);
}

Fraction operator-(int a, const Fraction &other)
{
    int tuSo = a* other.mau - other.tu;
    return Fraction(tuSo, other.mau);
}

Fraction operator*(int a, const Fraction &other)
{
    int tuSo = a * other.tu;
    return Fraction(tuSo, other.mau);
}

Fraction operator/(int a, const Fraction &other)
{
    if (other.tu ==0 || other.mau == 0)
    {
        cout << "Cannot divide by zero!"<<endl;
        return Fraction(0,0);
    }
    int tuSo = a * other.mau;
    return Fraction(tuSo, other.mau);
}

// -------------------------------------
bool Fraction::operator==(const Fraction &other)
{
    return (tu * other.mau == other.tu * mau);
}
bool Fraction::operator!=(const Fraction &other)
{
    return (tu * other.mau != other.tu * mau);
}

bool Fraction::operator<(const Fraction &other)
{
    return (tu * other.mau < other.tu * mau);
}
bool Fraction::operator<=(const Fraction &other)
{
    return (tu * other.mau) <= (other.tu * mau);
}
bool Fraction::operator>(const Fraction &other)
{
    return (tu * other.mau > other.tu * mau);
}
bool Fraction::operator>=(const Fraction &other)
{
    return (tu * other.mau >= other.tu * mau);
}

Fraction &Fraction::operator+=(const Fraction &a)
{
	return *this = *this + a;	
}

Fraction &Fraction::operator-=(const Fraction &a)
{
	return *this = *this - a;	
}
Fraction &Fraction::operator*=(const Fraction &a)
{
	return *this = *this * a;	
}
Fraction &Fraction::operator/=(const Fraction &a)
{
	return *this = *this / a;	
}

Fraction &Fraction::operator++()
{
    return *this = *this +1;
}
Fraction Fraction::operator++(int a)
{
    Fraction t = *this;
    *this = *this +1;
    return t;
}
Fraction &Fraction::operator--()
{
    
    *this = *this - 1;
    return *this;
}
Fraction Fraction::operator--(int a)
{
    Fraction t(*this);
    *this = *this -1;
    return t;
}

Fraction::operator int(){
    return (int)tu/mau;
}
Fraction::operator float(){
    return (float)tu/mau;
}   