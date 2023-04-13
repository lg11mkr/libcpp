#include "Point2d.h"
#include <iostream>
#include <math.h>
Point2d::Point2d(){
    this->x = 0;
    this->y = 0;
}
Point2d::Point2d(double x0, double y0){
    this->x = x0;
    this->y = y0;
}
Point2d::Point2d(const Point2d& a){
    this->x = a.x;
    this->y = a.y;
}
Point2d Point2d::operator=(const Point2d& a){
    this->x = a.x;
    this->y = a.y;
    return *this;
}
void Point2d::input(){
    std::cout<<"Nhap x0: ";
    std::cin>>this->x;
    std::cout<<"Nhap y0: ";
    std::cin>>this->y;
}
void Point2d::output(){
    std::cout<<"Toa do: ("<<this->x<<" ,"<<this->y<<" )"<<std::endl;
}
double Point2d::distance(Point2d b){
    return sqrt(double(x-b.x)*(x-b.x)+(y-b.y)*(y-b.y));
}
void Point2d::outDistance(Point2d b){
    double kq = sqrt(double(x-b.x)*(x-b.x)+(y-b.y)*(y-b.y));
    std::cout<<"Khoang Cach = "<<kq<<std::endl;
}
