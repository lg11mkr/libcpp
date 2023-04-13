#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Student.h"
class Course
{
private:
    string courseID;
    string courseName;
    vector<Student> studentList;

public:
    Course();
    Course(string _courseID, string _courseName);
    void clear();
    void enroll();
    void enroll(Student a);
    void enroll(vector<Student> a);
    void unenroll();
    void unenroll(string _studentID);
    void unenroll(vector<string> _studentID);
    vector<Student> SvXuatSac();
    vector<Student> SvGioi();
    vector<Student> SvKha();
    vector<Student> SvTrungBinh();
    vector<Student> SvDuoiTrungBinh();
    int soLuongQuaMon();
    int soLuongKhongQuaMon();
    void sapXepTang();
    void sapXepGiam();
    void printCourse();
    void printStudent();
    void readFile(string filename);
    void writeFile(string filename);
    void writeFile();
    
};
void printStudentList(vector<Student> a);

