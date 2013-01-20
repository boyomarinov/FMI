
#include <iostream>
using namespace std;

class Point{
public:
	Point(int = 0, int = 0, int = 0); 
	Point(const Point&);	
	double getX() const;	//getters
	double getY() const;
	double getZ() const;
	void SetX(double);		//setters
	void SetY(double);
	void SetZ(double);
private:
	double x, y, z;
};

Point::Point(int _x, int _y, int _z){
	x = _x;
	y = _y;
	z = _z;
}

Point::Point(const Point &m){
	x = m.x;
	y = m.y;
	z = m.z;
}

double Point::getX() const{
	return x;
}

double Point::getY() const{
	return y;
}

double Point::getZ() const{
	return z;
}

void Point::SetX(double _x){
	x = _x;
}

void Point::SetY(double _y){
	y = _y;
}

void Point::SetZ(double _z){
	z = _z;
}


class Sphere{
public:
	Sphere(Point, double);
	Sphere(const Sphere&);
	Sphere& operator=(const Sphere&);
	void Set(Point, double);
	double Volume(double);
	bool Contain(Point);
private:
	Point center;
	double radius;
};

Sphere::Sphere(Point a, double r){
	radius = r;
	this->center.SetX(a.getX());
	this->center.SetY(a.getY());
	this->center.SetZ(a.getZ());
}

Sphere::Sphere(const Sphere &m){
	center.SetX(m.center.getX());
	center.SetY(m.center.getY());
	center.SetZ(m.center.getZ());
	radius = m.radius;
}

Sphere& Sphere::operator=(const Sphere &m){
	if(this != &m){
		center.SetX(m.center.getX());
		center.SetY(m.center.getY());
		center.SetZ(m.center.getZ());
		radius = m.radius;
	}
	return *this;
}

void Sphere::Set(Point a, double r){
	center.SetX(a.getX());
	center.SetY(a.getY());
	center.SetZ(a.getZ());
	radius = r;
}

double Sphere::Volume(double r){
	return 4/3*(3.14)*r*r*r;
}

bool Sphere::Contain(Point a){
	double s = Distance(center, a);
	if (s < radius){
		return true;
	}
	return false;
}
