#pragma once
#include <iostream>
using namespace std;
class Employee
{
protected:
    string fullName;
    short joiningYear;
    double baseSalary;
public:
    Employee();
    Employee( string _fname);
    Employee( string _fname, short _jYear);
    Employee( short _jYear, double _bSal);
    Employee( string _fname, short _jYear, double _bSal);
    virtual double getSalary();
    virtual string getName();
    friend istream& operator >> (istream& is, Employee& A);
    friend ostream& operator << (ostream& os, Employee& A);
};

class Manager:public Employee{
protected:
    float positionFactor;
    double bonus;
public:
    Manager();
    Manager(string _fname);
    Manager(string _fname, short _jYear);
    Manager(string _fname, short _jYear, double _bSal, double _posFac);
    Manager(string _fname, short _jYear, double _bSal, double _posFac, int _bon);
    virtual double getSalary();
    friend istream& operator >> (istream& is, Manager& A);
    friend ostream& operator << (ostream& os, Manager& A);
};

class Producer:public Employee{
protected:
    int products;
public:
    Producer();
    Producer( string _fname);
    Producer( string _fname, short _jYear);
    Producer( string _fname, short _jYear, double _bSal);
    Producer(string _fname, short _jYear, double _bSal, int _pro);
    virtual double getSalary();
    friend istream& operator >> (istream& is, Producer& A);
    friend ostream& operator << (ostream& os, Producer& A);
};
class Officer:public Employee{
protected:
    int workedDays;
    double subsidize;
public:
    Officer();
    Officer( string _fname);
    Officer( string _fname, short _jYear);
    Officer( string _fname, short _jYear, double _bSal);
    Officer(string _fname, short _jYear, double _bSal, int _wrkDay);
    Officer(string _fname, short _jYear, double _bSal, int _wrkDay, int _sub);
    virtual double getSalary();
    friend istream& operator >> (istream& is, Officer& A);
    friend ostream& operator << (ostream& os, Officer& A);
};