#include "Student.h"
int demPhay(string a){
	int sum = 0;
	for (int i = 0; i <a.length(); i++)
	{
		if (a[i] == ',') 
			sum++;
	}
	
	return sum;
}

bool isNum(string a){
	for (int i = 0; i <a.length(); i++)
	{
		if (a[i] <'0' || a[i] > '9' ) 
        {
            if ( a[i] == '.' ||a[i]==' '||a[i]=='\t')
                continue;
			return false;
        }
	}
	
	return true;
}
bool check(string a,string num){
    if (demPhay(a) !=2 )
        return false;
    return isNum(num);
}
Student::Student()
{
    studentId="";
    grade=0.0;
    fullname="";
}
Student::Student(const string _id,const double _grade,const string _fullname)
{
    studentId = _id;
    grade = _grade;
    fullname = _fullname;
}
Student::Student(const Student& a)
{
    studentId = a.studentId;
    grade = a.grade;
    fullname = a.fullname;
}

Student::Student(const string a)
{
    int pos = 0;
    int pos1 = a.find(',', pos);
    string Id = a.substr(pos, pos1 - pos);
    pos = pos1 + 1;
    pos1 = a.find(',', pos);
    string num=a.substr(pos, pos1 - pos);
    pos = pos1 + 1;

    if (!check(a, num))
    {
        cout<<"Nhap Khong dung cau truc hoac Loi! \n";
        return;
    }
    studentId =Id;
    grade = stod(num);
    fullname= a.substr(pos);
}
Student Student::operator=(const Student& a)
{
    if (this == &a)
        return *this;
    studentId = a.studentId;
    grade = a.grade;
    fullname = a.fullname;
    return *this;
}
ostream& operator<<(ostream& os,const Student& a){
    if(a.studentId == ""){
        cout<<"Have not initialized the variable!"<<endl;
        return os;
    }
    os<<a.studentId<<","<<a.grade<<","<<a.fullname;
    return os;
}
istream& operator>>(istream& is,Student& a)
{
    string str;
    getline(is,str);
    a = Student(str);
	return	is;
}
// Getters
string Student::getStudentId() { return studentId; }
double Student::getGrade() { return grade; }
string Student::getFullname() { return fullname; }

// Setters
void Student::setStudentId(string id) { studentId = id; }
void Student::setGrade(double g) { grade = g; }
void Student::setFullname(string name) { fullname = name; }

