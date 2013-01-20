#include <iostream>
#include <fstream>
#include "String.h"
using namespace std;

class Student
{
	String name;
	int fn;

public:
	Student() : name(""), fn(0) { }

	Student(String name, int fn): name(name), fn(fn) { }
	void Add(ifstream& f, Student& s)
	{
		f >> s.fn >> s.name >> endl;
	}
	String GetName() const
	{
		return name;
	}
	int GetFn() const
	{
		return fn;
	}
	void SetName(String _name)
	{
		name = _name;
	}
	friend istream& operator>>(istream&, Student&);
	friend ostream& operator<<(ostream&, const Student&);
};

istream& operator>>(istream& inp, Student& s)
{
	return inp>>s.fn>>s.name;
}

ostream& operator<<(ostream& out, const Student& s)
{
	return out<<s.fn<<" "<<s.name;
}
