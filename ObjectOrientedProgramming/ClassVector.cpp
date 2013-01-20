#include <iostream>
#include <cstring>
using namespace std;

struct Point{
	double x, y, z;
	Point(double _x = 0, double _z = 0, double _z = 0
	{
		x = _x; y = _y; z = _z;
};

Point Read(){
	Point r;
	cin >> r.x >> r.y >> r.z;
	return r;
}

istream& operator>> (istream& s, Point& p)
{
	s >> p.x >> p.y >> p.z;
	return s;
}

ostream& operator<< (ostream& s, const Point& p)
{
	return s << p.x << p.y << p.z;
}


class Vector{
private:
	Point a, b;
	char * name;
public:
	Vector(Point = Point(), Point = Point() , char * = "");
	~Vector();
	Vector& operator=(const Vector&);
	Vector(const Vector&);
	Point get_A() const;
	void Set_name(char *);
	bool operator==(const Vector&);
	bool operator!=(const Vector&);
	bool operator+=(const Vector&);
}

Vector::Vector(Point A, Point B, char* name){
	a = A;
	b = B;
	Name = copy(name);
}

Vector& Vector::operator= (const Vector& AB){
	if(this != &AB)
	{
		a = AB.a;
		b = AB.b;
		delete[] name;
		Name  = copy(AB.Name);
	}
	return *this;
}

Point Vector::get_A() const
{
	return a;
}

void Vector::Set_name(char * N)
{
	delete[] Name;
	Name = copy (N);
}

char* copy (const char* name)
{
	char* result = new char[strlen(name)+1];
	strcpy(result, name);
	return result;
}

bool Vector::operator==(const Vector& AB)
{
	return a == AB.a && b == AB.b && !strcmp(Name, AB.Name);
}

bool Vector::operator!= (const Vector& AB)
{
    //compare them by value, not by their pointers
	return !(*this == AB); 
}

Vector& Vector::operator+=(const Vector& AB)
{
	a.x += AB.a.x;
	a.y += AB.a.y;
	a.z += AB.a.y;
	char* helper = Name;
	delete[] Name;
	Name = concat (helper, "+", AB.Name);
	delete[] Name;
	return *this;
}

char* concat( char* F, char* sign, char * S)
{
	char* result = new char[strlen(F) + strlen(sign) + 1];
	strcpy(result, F);
	strcpy(result + strlen(F), sign);
	strcpy(result + strlen(F) + strlen(sign), S);
	return result;
}

Vector Vector::operator+(const Vector& AB)
{
	Vector result(*this);
	result+=AB;
	return result;
}

Vector& Vector::operator-()
{
	swap(a,b);
	reverse(Name, strlen(Name));
	return *this;
}

void reverse (char * s, int l){
	if(l >= 2){
		swap(*s, *(s + l - 1));
		return reverse( s+1, l-2);
	}
}

Vector& Vector::operator*=(double A)
{
	a.x* = A;
	a.y* = A;
	a.z* = A; /... sy6toto pravim za b
	return *this;
}

Vector operator*(double A, const Vector & AB)
{
	Vector result(AB);
	result *= A;
	return result;
}


double Vector::operator* (const Vector& AB)
{
	return  (b.x-a.x)*(AB.b.x - AB.a.x) + 
			(b.y-a.y)*(AB.b.y - AB.a.y) + 
			(b.z-a.z)*(AB.b.z - AB.a.z);

int main()
{
	//system("pause");
	return 0;
}
