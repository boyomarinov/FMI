#include <iostream>
#include "ArrayList.h"

using namespace std;

class String : public ArrayList<char>
{
public:
	String(char* string = "") : ArrayList<char>(strlen(string) + 1)
	{
		SetLength(strlen(string) + 1);
		size_t i = 0;
		while (*string)
			(*this)[i++] = *(string++);
		(*this)[i] = 0;
	}
};

istream& operator>>(istream& inp, String& str)
{
	char buf[1024];
	inp>>buf;
	str = String(buf);
	return inp;
}

ostream& operator<<(ostream& out, const String& str)
{
	for (size_t i = 0; i < str(); i++)
	{
		out<<str[i];
	}

	return out;
}