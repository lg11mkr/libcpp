#include "Employee.h"

Employee::Employee()
{
    this->fullName = "";
    this->baseSalary=0;
    this->joiningYear=1945;
}
Employee::Employee(string _fname):Employee()
{
    this->fullName = _fname;
}
Employee::Employee(string _fname, short _jYear):Employee()
{
    this->fullName = _fname;
    this->joiningYear = _jYear;
}
Employee::Employee(short _jYear, double _bSal):Employee()
{
    this->joiningYear = _jYear;
    this->baseSalary = _bSal;
}
Employee::Employee(string _fname, short _jYear, double _bSal)
{
    this->fullName = _fname;
    this->joiningYear = _jYear;
    this->baseSalary = _bSal;
}
double Employee::getSalary()
{
    return (double)baseSalary;
}
string Employee::getName()
{
    return fullName;
}

istream &operator>>(istream &is, Employee &A)
{
    A.fullName = "";
    A.baseSalary=0;
    A.joiningYear=1945;
    cout << "Enter the full name of the employee: ";
    getline(is, A.fullName);
    cout << "Enter the joinning year: ";
    is >> A.joiningYear;
    cout << "Enter the base salary: ";
    is >> A.baseSalary;
    cin.ignore();
    return is;
}

ostream &operator<<(ostream &os, Employee &A)
{
    os << "Name: " << A.fullName << " ,JnYear: " << A.joiningYear << " ,BaseSal: " << A.baseSalary;
    return os;
}
//------------------------------------------------------------
Manager::Manager():Employee()
{
    this->positionFactor = 1;
    this->bonus = 0;
}
Manager::Manager(string _fname):Manager()
{
    this->fullName = _fname;
}
Manager::Manager(string _fname, short _jYear):Manager()
{
    this->fullName = _fname;
    this->joiningYear = _jYear;
}
Manager::Manager(string _fname, short _jYear, double _bSal, double _posFac):Manager()
{
    this->positionFactor = _posFac;
    this->fullName = _fname;
    this->joiningYear = _jYear;
    this->baseSalary = _bSal;
}
Manager::Manager(string _fname, short _jYear, double _bSal, double _posFac, int _bon)
{
    this->positionFactor = _posFac;
    this->bonus = _bon;
    this->fullName = _fname;
    this->joiningYear = _jYear;
    this->baseSalary = _bSal;
}
double Manager::getSalary()
{
    return (double)baseSalary * positionFactor + bonus;
}
istream &operator>>(istream &is, Manager &A)
{
    A.fullName = "";
    A.baseSalary=0;
    A.joiningYear=1945;
    A.positionFactor=1;
    A.bonus=0;
    cout << "Enter the full name of the Manager: ";
    getline(is, A.fullName);
    cout << "Enter the joinning year: ";
    is >> A.joiningYear;
    cout << "Enter the base salary: ";
    is >> A.baseSalary;
    cout << "Enter the position Factor: ";
    is >> A.positionFactor;
    cout << "Enter the Bonus: ";
    is >> A.bonus;
    cin.ignore();
    return is;
}

ostream &operator<<(ostream &os, Manager &A)
{
    os << *(Employee *)&A;
    os << " ,PosFac: " << A.positionFactor << " ,Bonus: " << A.bonus;
    return os;
}
//------------------------------------------------------------
Producer::Producer():Employee()
{
    this->products =0;
}
Producer::Producer(string _fname):Producer()
{
    this->fullName = _fname;
}
Producer::Producer(string _fname, short _jYear):Producer()
{
    this->fullName = _fname;
    this->joiningYear = _jYear;
}
Producer::Producer(string _fname, short _jYear, double _bSal):Producer()
{
    this->fullName = _fname;
    this->joiningYear = _jYear;
    this->baseSalary = _bSal;
}
Producer::Producer(string _fname, short _jYear, double _bSal, int _pro)
{
    this->products = _pro;
    this->fullName = _fname;
    this->joiningYear = _jYear;
    this->baseSalary = _bSal;
}
double Producer::getSalary()
{
    return (double)baseSalary + products * 2000;
}
istream &operator>>(istream &is, Producer &A)
{
    A.fullName = "";
    A.baseSalary=0;
    A.joiningYear=1945;
    A.products=0;
    cout << "Enter the full name of the Producer: ";
    getline(is, A.fullName);
    cout << "Enter the joinning year: ";
    is >> A.joiningYear;
    cout << "Enter the base salary: ";
    is >> A.baseSalary;
    cout << "Enter the Number of products: ";
    is >> A.products;
    cin.ignore();
    return is;
}

ostream &operator<<(ostream &os, Producer &A)
{
    os << *(Employee *)&A;
    os << " ,Products: " << A.products;
    return os;
}
//------------------------------------------------------------
Officer::Officer():Employee()
{
    this->subsidize = 0;
    this->workedDays = 0;
}
Officer::Officer(string _fname):Officer()
{
    this->fullName = _fname;
}
Officer::Officer(string _fname, short _jYear):Officer()
{
    this->fullName = _fname;
    this->joiningYear = _jYear;
}
Officer::Officer(string _fname, short _jYear, double _bSal):Officer()
{
    this->fullName = _fname;
    this->joiningYear = _jYear;
    this->baseSalary = _bSal;
}
Officer::Officer(string _fname, short _jYear, double _bSal, int _wrkDay):Officer()
{
    this->workedDays = _wrkDay;
    this->fullName = _fname;
    this->joiningYear = _jYear;
    this->baseSalary = _bSal;
}
Officer::Officer(string _fname, short _jYear, double _bSal, int _wrkDay, int _sub)
{
    this->workedDays = _wrkDay;
    this->subsidize = _sub;
    this->fullName = _fname;
    this->joiningYear = _jYear;
    this->baseSalary = _bSal;
}
double Officer::getSalary()
{
    return (double)baseSalary + workedDays * 100000 + subsidize;
}
istream &operator>>(istream &is, Officer &A)
{
    A.fullName = "";
    A.baseSalary=0;
    A.joiningYear=1945;
    A.workedDays=0;
    A.subsidize=0;
    cout << "Enter the full name of the Officer: ";
    getline(is, A.fullName);
    cout << "Enter the joinning year: ";
    is >> A.joiningYear;
    cout << "Enter the base salary: ";
    is >> A.baseSalary;
    cout << "Enter the days of work: ";
    is >> A.workedDays;
    cout << "Enter the Subsidize: ";
    is >> A.subsidize;
    cin.ignore();
    return is;
}

ostream &operator<<(ostream &os, Officer &A)
{
    os << *(Employee *)&A;
    os << " ,DaysWork: " << A.workedDays << " ,Subsidize: " << A.subsidize;
    return os;
}
//------------------------------------------------------------