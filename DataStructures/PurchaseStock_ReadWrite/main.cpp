#include <iostream>
#include <fstream>
#include <string>
#include "Purchase.h"
using namespace std;

void main()
{
	//Input purchases from text file
	int count = 0;
	ifstream in("purchase.txt");
	in >> count;
	Purchase *P = new Purchase[count];
	for(int i=0; i<count; i++)
	{
		in >> P[i];
	}

	//Input stocks from text file
	int stockcount = 0;
	ifstream inp("stock.txt");
	inp >> stockcount;
	Stock *S = new Stock[stockcount];
	for(int i=0; i<stockcount; i++)
	{
		inp >> S[i];
	}

	//Check if all purchases contain only valid stocks
	for(int i=0; i<count; i++)
	{
		if(!(StockCheck(P[i], S, stockcount)))
		{
			cout << "There are some invalid stocks in purchase ¹" << i << ".";
		}
	}

	//Sort stocks by price
	SortByPrice(P, count);
	cout << "The 5 most expensive purchases sorted by stock with average price higher than 4 are: " << endl;

	if(count<5)
	{
		for(int i=0; i<count; i++)
		{
			if(HigherThanAverage(P[i], 4))
			{	
				cout << P[i];
			}
			cout << "There are only " << count << " purchases added. " << endl;
		}
	}
	else
	{
		for(int i=0; i<5; i++)
		{
			if(HigherThanAverage(P[i], 4))
			{	
				cout << P[i];
			}
		}
	}
	cout << endl;

	//sort purchases by date
	SortByDate(P, count);
	cout << "Last 5 purchases: " << endl;

	if(count < 5)
	{
		for(int i=0; i<count; i++)
		{
			cout << P[i];
		}
		cout << "There are only " << count << " purchases added. " << endl;
	}
	else
	{
		for(int i=0; i<5; i++)
		{
			cout << P[i];
		}
	}
}
