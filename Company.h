#pragma once
#include <vector>
#include "Employee.h"
#include <iostream>
using namespace std;

class Company
{
private:
    string name;
    int establishedYear;
    vector<Officer> Officers;
    vector<Producer> Producers;
    vector<Manager> Managers;
public:
    Company();
    void setInfor();
    void addEmployee();//10
    void addEmployee(Officer a);//10
    void addEmployee(Producer a);//10
    void addEmployee(Manager a);//10
    void outputEmployee();//11
    double sumOfSalaries();//12
    void searchEmployee();//13
    void searchEmployee(string sName);
};

