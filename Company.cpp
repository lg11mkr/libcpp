#include "Company.h"
Company::Company()
{
    name= "";
    establishedYear =1975;   
}
void Company::setInfor(){
    cout<<"Nhap ten cong ty: ";
    getline(cin,this->name);
    cout<<"Nhap nam thanh lap: ";
    cin>>this->establishedYear;
    char in;
    do{
        cout<<"Ban co muon nhap Nhan vien? (y/n):";
        cin>>in;
    } while (in!='y' && in!='n');

    if (in != 'n'){
        Officers.clear();
        Producers.clear();
        Managers.clear();
        addEmployee();
    }
}
void Company::addEmployee(){
    int n;
    cout<<"Nhap Nhan Vien Cong ty "<<name<<": "<<endl;
    cout<<"Nhap so Nhan vien Van Phong: ";
    cin>>n;
    cin.ignore();
    for(int i=0; i<n; i++){
        Officer a;
        cout<<"Nhap VP["<<i<<"] :"<<endl;
        cin>>a;
        Officers.push_back(a);
    }
    cout<<"Nhap so Nhan vien San Xuat: ";
    cin>>n;
    cin.ignore();
    for(int i=0; i<n; i++){
        Producer a;
        cout<<"Nhap SX["<<i<<"] :"<<endl;
        cin>>a;
        Producers.push_back(a);
    }
       cout<<"Nhap so Nhan vien Quan Ly: ";
    cin>>n;
    cin.ignore();
    for(int i=0; i<n; i++){
        Manager a;
        cout<<"Nhap SX["<<i<<"] :"<<endl;
        cin>>a;
        Managers.push_back(a);
    }
}
void Company::addEmployee(Officer a){
    Officers.push_back(a);
}
void Company::addEmployee(Producer a){
    Producers.push_back(a);
}
void Company::addEmployee(Manager a){
    Managers.push_back(a);
}
void Company::outputEmployee(){
    for(int i=0; i<Officers.size(); i++){
        cout<<"VP["<<i<<"] :"<<Officers[i]<<endl;
    }
    for(int i=0; i<Producers.size(); i++){
        cout<<"SX["<<i<<"] :"<<Producers[i]<<endl;
    }
    for(int i=0; i<Managers.size(); i++){
        cout<<"QL["<<i<<"] :"<<Managers[i]<<endl;
    }
}
double Company::sumOfSalaries(){
    double sum = 0;
    for(int i=0; i<Officers.size(); i++){
        sum+=Officers[i].getSalary();
    }
    for(int i=0; i<Producers.size(); i++){
        sum+=Producers[i].getSalary();
    }
    for(int i=0; i<Managers.size(); i++){
        sum+=Managers[i].getSalary();
    }
    return sum;
}
void Company::searchEmployee(){
    cout<<"Nhap ten Nhan Vien can tim: ";
    string sName;
    getline(cin, sName);
    searchEmployee(sName);
}
void Company::searchEmployee(string sName){
    for(int i=0; i<Officers.size(); i++){
        if (Officers[i].getName().compare(sName)==0 )
        {
            cout<<Officers[i]<<endl;
        }
    }
    for(int i=0; i<Producers.size(); i++){
        if (Producers[i].getName().compare(sName)==0 )
        {
            cout<<Producers[i]<<endl;
        }
    }
    for(int i=0; i<Managers.size(); i++){
        if (Managers[i].getName().compare(sName)==0 )
        {
            cout<<Managers[i]<<endl;
        }
    }
}