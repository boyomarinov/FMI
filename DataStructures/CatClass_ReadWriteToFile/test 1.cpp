#include <iostream>
#include <cstring>
#include <fstream>
#include <time.h>
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
	bool operator<(const Car&o) const
	{
		return price < o.price;
	}
	bool operator<(double p) const
	{
		return price < p;
	}

private:
	char* CarBrand;
	char* CarModel;
	double price;
};

	bool operator<(double p, const Car&o)
	{
		return p < o.GetPrice();
	}

	void Sort(Car A[], int n)
	{
		for(int i = n-2; i >= 0; i--)
		{
			for(int j = 0; j <= i; j++)
			{
			if(A[j]<A[j+1])
			{
				swap(A[j], A[j+1]);
			}
			}
		}
	}

ostream& operator<<(ostream& s, Car& c)
{
	s.width(12);
	s << c.CarBrand;
	s.width(12);
	s << c.CarModel;
	s.width(12);
	s << c.price << endl;
	return s;
}
istream& operator>>(istream& s, Car& c)
{
	char b[1024];
	s >> b;
	c.SetBrand(b);
	s >> b;
	c.SetModel(b);
	s >> c.price;
	return s;
}


void main()
{
	Car* A = new Car[5];
	//for(int i=0;i<5;i++)
	//{
	//	cout << "Type brand, model and price: ";
	//	cin >> A[i];
	//}

	//Sort(A, 5);


	//ofstream File("CarCollection.txt");
	//for(int i=0;i<5;i++)
	//{
	//	File << A[i];
	//}

		ifstream File1("CarCollection.txt");
	
		for(int i=0;i<5;i++)
		{
			File1 >> A[i];
		}

		ofstream File2("Car2ndEdition.txt");
		for(int i=0;i<5;i++)
		{
			if(A[i].GetPrice()>30000)
			{
				File2 << A[i];
			}
		}

}
