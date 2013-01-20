#include <iostream>
#include <string>
using namespace std;

struct Stock
{
	string name;
	int catalogueNum;
	double price;

public:
	Stock(string _name = "", int num = 1, double p = 0)
	{
		name = _name;
		catalogueNum = num;
		price = p;
	}

	string GetName() const
	{
		return name;
	}
	int GetCatalogueNum() const
	{
		return catalogueNum;
	}
	double GetPrice() const
	{
		return price;
	}
};
	

istream& operator>>(istream& inp,  Stock& o)
{
	inp >> o.catalogueNum >> o.name >> o.price;
	return inp;
}
ostream& operator<<(ostream& out, const Stock& o)
{
	out << o.catalogueNum << " " << o.name << " " << o.price;
	return out;
}