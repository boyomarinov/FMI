#include <iostream>
#include <cstring>
using namespace std;

class Car
{
public:
	Car(char* b = "", char* m = "", double p = 0)
	{
		CarBrand = new char[strlen(b)+1];
		strcpy(CarBrand, b);
		CarModel = new char[strlen(m)+1];
		strcpy(CarModel, m);
		price = p;
	}
	~Car()
	{
		delete[] CarBrand;
		delete[] CarModel;
	}
	Car(const Car&o)
	{
		cpy(CarBrand, o.CarBrand);
		cpy(CarModel, o.CarModel);
		price = o.price;
	}
	Car& operator=(const Car&o)
	{
		if(this != &o){
			delete[] CarModel;
			delete[] CarBrand;
			cpy(CarBrand, o.CarBrand);
			cpy(CarModel, o.CarModel);
			price = o.price;
		}
		return *this;
	}
	void cpy(char* &t, char* f)
	{
		t = new char[strlen(f)+1];
		strcpy(t, f);
	}
	char* GetBrand() const
	{
		return CarBrand;
	}
	char* GetModel() const
	{
		return CarModel;
	}
	double GetPrice() const
	{ return price;
	}
	void SetBrand(char* br)
	{
		delete[] CarBrand;
		CarBrand = new char[strlen(br)+1];
		strcpy(CarBrand, br);
	}
	void SetModel(char* mo)
	{
		delete[] CarModel;
		CarModel = new char[strlen(mo)+1];
		strcpy(CarModel, mo);
	}
	void SetPrice(double pr)
	{
		price = pr;
	}
	friend ostream& operator << (ostream& s, Car& c);
	friend istream& operator >> (istream& s, Car& c);

private:
	char* CarBrand;
	char* CarModel;
	double price;
};

ostream& operator<<(ostream& s, Car& c)
{
	s << c.CarBrand << c.CarModel << c.price << endl;
	return s;
}
istream& operator>>(istream& s, Car& c)
{
	char b[1024];
	s >> b;
	c.SetBrand(b);
	s >> b;
	c.SetModel(b);
	s >> b;
	s >> c.price;
	return s;
}

void main()
{

}
