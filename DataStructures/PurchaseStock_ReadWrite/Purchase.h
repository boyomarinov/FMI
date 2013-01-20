#include <iostream>
#include "ArrayList.h"
#include "Stock.h"
#include "Date.h"
using namespace std;

struct Purchase
{
	ArrayList<Stock> StockList;
	Date date;

public:
	Purchase(size_t len = 1, int d = 1, int m = 1, int y = 1900)
	{
		if(!(CorrectDate(d, m, y)))
		{
			cout << "Invalid date input!";
		}
		else
		{
			date.SetDay(d);
			date.SetMonth(m);
			date.SetYear(y);
		}
	}

};

istream& operator>>(istream& inp, Purchase& o)
{
	inp >> o.date >> o.StockList;
	return inp;
}
ostream& operator<<(ostream& out, const Purchase& o)
{
	out << o.date << o.StockList << endl;
	return out;
}

	double CalcPurchasePrice(Purchase A)
	{
		double sum = 0;
		for(int i=0; i<A.StockList.GetCount(); i++)
		{
			sum += A.StockList[i].GetPrice();
		}
		return sum;
	}
	void SortByPrice(Purchase A[], int count)
	{
		Purchase temp;
		for(int i=0; i<count; i++)
		{
			for(int j=i+1; j<count; j++)
			{
				if(CalcPurchasePrice(A[i]) < CalcPurchasePrice(A[j]))
				{
					temp = A[i];
					A[i] = A[j];
					A[j] = temp;
				}
			}
		}
	}
	int CompareDate(Date check1, Date check2)
	{
		if(check1.GetYear() == check2.GetYear())
		{
			if(check1.GetMonth() == check2.GetMonth())
			{
				if(check1.GetDay() == check2.GetDay()) return 0;
				if(check1.GetDay() > check2.GetDay()) return -1;
				if(check1.GetDay() < check2.GetDay()) return 1;
			}
			if(check1.GetMonth() > check2.GetMonth()) return -1;
			if(check1.GetMonth() < check2.GetMonth()) return 1;
		}
		if(check1.GetYear() > check2.GetYear()) return -1;
		if(check1.GetYear() < check2.GetYear()) return 1;
	}
	void SortByDate(Purchase A[], int count)
	{
		Purchase temp;
		for(int i=0; i<count; i++)
		{
				for(int j=i+1; j<count; j++)
			{
				if((CompareDate(A[i].date, A[j].date) == 1))
				{
					temp = A[i];
					A[i] = A[j];
					A[j] = temp;
				}
			}
		}
	}

	double AveragePrice(Purchase A)
	{
		int count = A.StockList.GetCount();
		return CalcPurchasePrice(A)/count;
	}

	bool HigherThanAverage(Purchase A, double price)
	{
		return AveragePrice(A) > price;
	}
	//checks(by catalogue number) if stocks from given purchase
	//correspond to stock from the list of valid stocks
	bool StockCheck(Purchase A, Stock *S, int stockcount)
	{
		for(int i=0; i<stockcount; i++)
		{
			for(int j=0; j<A.StockList.GetCount(); j++)
			{
				if(S[i].GetCatalogueNum() == A.StockList[j].GetCatalogueNum())
				{
					return true;
				}
			}
		}
		return false;
	}
