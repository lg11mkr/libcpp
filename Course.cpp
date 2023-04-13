#include "Course.h"
Course::Course()
{
    courseID="";
    courseName ="";
}
Course::Course(string _courseID, string _courseName)
{
    courseID=_courseID;
    courseName =_courseName;
}
void Course::clear(){
    courseID="";
    courseName ="";
    studentList.clear();
}
void Course::enroll()
{
    int n;
    cout<<"----------------------------------"<<endl;
    cout<<"Nhap so sinh vien muon enroll: ";
    cin>>n;
    cin.ignore();
    for(int i=0; i<n; i++)
    {
        Student temp;
        cout<<"Nhap sinh vien "<<i<<"(format: id,grade,Full name): "<<endl;
        cin>>temp;
        this->studentList.push_back(temp);
    }
    cout<<"----------------------------------"<<endl;
}
void Course::enroll(Student a)
{
    this->studentList.push_back(a);
}
void Course::enroll(vector<Student> a)
{
    for(int i=0; i<a.size(); i++)
    {
        Student temp = a[i];
        this->studentList.push_back(temp);
    }
}
void Course::unenroll()
{
    int n;
    cout<<"----------------------------------"<<endl;
    cout<<"Nhap so sinh vien can Huy mon: ";
    cin>>n;
    while (n > studentList.size()){
        cout<<"So luong vuot qua Hien tai! Nhap lai: ";
        cin>>n;
    }
    vector<string> listID;
    for(int i=0; i<n; i++)
    {
        string temp;
        cout<<"Nhap Ma sinh vien "<<i<<": ";
        cin>>temp;
        listID.push_back(temp);
    }
    cout<<"----------------------------------"<<endl;

    vector<int> listIndex;
    for(int i=0; i<studentList.size(); i++)
    {
        for (int j=0; j<listID.size(); j++)
        {
            if (studentList[i].getStudentId().compare(listID[j]) == 0 )
            {
                listIndex.push_back(i);
            }
        }
    }
    for(int i=listIndex.size()-1; i>=0; i--){
        studentList.erase(studentList.begin()+listIndex[i]);
    }
}
void Course::unenroll(string _studentID)
{
    for(int i=0; i<studentList.size(); i++)
    {
        if (studentList[i].getStudentId().compare(_studentID) == 0 )
        {
            studentList.erase(studentList.begin()+i);
        }
    }
}
void Course::unenroll(vector<string> _studentID)
{
    vector<int> listIndex;
    for(int i=0; i<studentList.size(); i++)
    {
        for (int j=0; j<_studentID.size(); j++)
        {
            if (studentList[i].getStudentId().compare(_studentID[j]) == 0 )
            {
                listIndex.push_back(i);
            }
        }
    }
    for(int i=listIndex.size()-1; i>=0; i--){
        studentList.erase(studentList.begin()+listIndex[i]);
    }
}
vector<Student> Course::SvXuatSac()
{
    vector<Student> ans;
    for(int i=0; i<studentList.size(); i++)
    {
        if (studentList[i].getGrade() >= 9.0)
        {
            Student temp=studentList[i];
            ans.push_back(temp);
        }
    }
    return ans;
}
vector<Student> Course::SvGioi()
{
    vector<Student> ans;
    for(int i=0; i<studentList.size(); i++)
    {
        if (studentList[i].getGrade() < 9.0 && studentList[i].getGrade() >= 8.0)
        {
            Student temp=studentList[i];
            ans.push_back(temp);
        }
    }
    return ans;
}
vector<Student> Course::SvKha()
{
    vector<Student> ans;
    for(int i=0; i<studentList.size(); i++)
    {
        if (studentList[i].getGrade() < 8.0 && studentList[i].getGrade() >= 6.5)
        {
            Student temp=studentList[i];
            ans.push_back(temp);
        }
    }
    return ans;
}
vector<Student> Course::SvTrungBinh()
{
    vector<Student> ans;
    for(int i=0; i<studentList.size(); i++)
    {
        if (studentList[i].getGrade() < 6.5 && studentList[i].getGrade() >= 5.0)
        {
            Student temp=studentList[i];
            ans.push_back(temp);
        }
    }
    return ans;
}
vector<Student> Course::SvDuoiTrungBinh()
{
    vector<Student> ans;
    for(int i=0; i<studentList.size(); i++)
    {
        if (studentList[i].getGrade() < 5.0)
        {
            Student temp=studentList[i];
            ans.push_back(temp);
        }
    }
    return ans;
}
int Course::soLuongQuaMon()
{
    int ans=0;
    for(int i=0; i<studentList.size(); i++)
    {
        if (studentList[i].getGrade() >= 5.0)
        {
            ans++;
        }
    }
    return ans;
}
int Course::soLuongKhongQuaMon()
{
    int ans=0;
    for(int i=0; i<studentList.size(); i++)
    {
        if (studentList[i].getGrade() < 5.0)
        {
            ans++;
        }
    }
    return ans;
}
void Course::sapXepTang()
{
    for(int i=0; i<studentList.size(); i++){
        for(int j=i+1; j<studentList.size(); j++){
            if (studentList[i].getGrade() > studentList[j].getGrade()){
                swap(studentList[i], studentList[j]);
            }
        }
    }
}
void Course::sapXepGiam()
{
    for(int i=0; i<studentList.size(); i++){
        for(int j=i+1; j<studentList.size(); j++){
            if (studentList[i].getGrade() < studentList[j].getGrade()){
                swap(studentList[i], studentList[j]);
            }
        }
    }
}
void Course::printCourse()
{
    cout<<"----------------------------------"<<endl;
    cout<<courseID<<"\t"<<courseName<<endl;
    cout<<"----------------------------------"<<endl;
    printStudent();
    cout<<"----------------------------------"<<endl;
}
void Course::printStudent()
{
    for (int i = 0; i < studentList.size(); i++){
        cout<<studentList[i]<<endl;
    }
}

void printStudentList(vector<Student> a)
{
    for (int i = 0; i < a.size();i++){
        cout<<a[i]<<endl;
    }
}
void Course::readFile(string filename)
{
    clear();
    ifstream infile(filename); 
    cout<<"----------------------------------"<<endl;
    cout << "Doc du lieu tu file: "<<filename << endl; 
    infile >>courseID; 
    infile.ignore();
    getline(infile,courseName);
    string temp;
    while(!infile.eof() && getline(infile, temp))
    {
        // ;
        if (temp.length()==0)
        {
            getline(infile, temp);
        } else {
            Student a(temp);
            studentList.push_back(a);
        }
    } 
    infile.close(); 
}
void Course::writeFile(string filename)
{
    ofstream outfile(filename); 
    cout<<"----------------------------------"<<endl;
    cout << "Ghi du lieu toi file: "<<filename << endl; 
    outfile <<courseID<< endl; 
    outfile <<courseName<< endl;
    for (int i=0; i<studentList.size(); i++)
    {
        outfile << studentList[i];
        if (i!=studentList.size()-1)
            outfile<<endl;
    } 
    outfile.close(); 
}
void Course::writeFile()
{
    writeFile("output.txt");
}