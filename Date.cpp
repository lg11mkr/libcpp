#include "Date.h"
#include <iostream>
using namespace std;

int Date::maxDay(){
    int max;
    switch (mm)
    {
        case 4:
        case 6:
        case 9:
        case 11:
            max = 30;
            break;
        case 2:
            if (yy%4==0){
                max = 29;
            } else
                max =28;
            if (yy%100 ==0 && yy%400 !=0)
                max =28;
            break;    
        default:
            max = 31;
            break;
    }
    return max;
}

void Date::inDate(){
    cout<<"Nhap nam :";
    cin>>this->yy;
    do {
        cout<<"Nhap thang :";
        cin>>this->mm;
    } while(mm >12 || mm < 1);
  
    do {
        cout<<"Nhap ngay :";
        cin>>this->dd;
    } while(dd  > maxDay() || dd < 1);
}
void Date::outDate (){
    cout<<"Ngay hien tai: "<<dd<<"/"<<mm<<"/"<<yy<<endl;
}
void Date::increase1day(){
    int max = maxDay();
    dd++;
    if (dd > max){
        dd =1;
        mm++;
    }
    if (mm > 12){
        mm =1;
        yy++;
    }
}
void Date::increaseNDay(int n){
    for (int i = 0; i < n; i++)
        increase1day();
}
void Date::decrease1day(){
    int max = maxDay();
    dd--;
    if (dd < 1){
        dd =max;
        mm--;
    }
    if (mm < 1){
        mm =12;
        yy--;
    }
}

void Date::decreaseNDay(int n){
    for (int i = 0; i < n; i++)
        decrease1day();
}
int Date::compare(Date khac){
    if (yy> khac.yy) {
        return 1;
    } else if (yy== khac.yy)
    {
        if (mm> khac.mm) {
            return 1;
        } else if (mm== khac.mm){
             if (dd> khac.dd) {
                return 1;
            } else if (dd== khac.dd)
                return 0;
        }

    }
    return -1;       
}