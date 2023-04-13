#pragma once
#include <iostream>
#include <string>
using namespace std;
class Student
{
private:
    string studentId;
    double grade;
    string fullname;
public:
    Student();
    Student(const string _id,const double _grade,const string _fullname);
    Student(const Student& a);
    Student(const string a);
    Student operator=(const Student& a);
    friend ostream& operator<<(ostream& os,const Student& a);
    friend istream& operator>>(istream& os,Student& a);

    // Getters
    string getStudentId();
    double getGrade() ;
    string getFullname();
    // Setters
    void setStudentId(string id) ;
    void setGrade(double g);
    void setFullname(string name) ;
    
};