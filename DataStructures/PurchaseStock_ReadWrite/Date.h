#include <iostream>
#include <fstream>
using namespace std;

class Date
{
	int day;
	int month;
	int year;
public:
	Date(int d = 1, int m = 1, int y = 1900)
	{
			day = d;
			month = m;
			year = y;
	}
	int GetDay() const
	{
		return day;
	}
	int GetMonth() const
	{
		return month;
	}
	int GetYear() const
	{
		return year;
	}
	Date GetDate() const
	{
		return day;
		return month;
		return year;
	}
	void SetDay(int d)
	{
		day = d;
	}
	void SetMonth(int m)
	{
		month = m;
	}
	void SetYear(int y)
	{
		year = y;
	}

friend istream& operator>>(istream&, Date&);
friend ostream& operator<<(ostream&, const Date&);
};

istream& operator>>(istream& inp, Date& d)
{
	inp >> d.day >> d.month >> d.year;
	return inp;
}
ostream& operator<<(ostream& out, const Date& d)
{
	out << d.day << " " << d.month << " " << d.year << endl;
	return out;
}
	//check for leap year
	bool LeapYear(int day, int month, int year)
	{
		return year % 4 == 0 && year%100 !=0 || year % 400 == 0;
	}
	//check data integrity
	bool CorrectDate(int day, int month, int year)
	{
		if(!(day || month || year))
		{
			return false;
		}
		if(month == 1 || month == 3 || month == 5 || 
		   month == 7 || month == 9 || month == 11)
		{
			if(!(day >= 1 && day <= 31))
			{
				return false;
			}
			return true;
		}
			if(month == 2)
			{
				if(LeapYear(day, month, year))
				{
					if(!(day>=1 && day<=29))
					{
						return false;
					}
					return true;
				}
				else if(day>=1 && day <=28)
				{
					return true;
				}
				return false;
			}
				if(month == 4 || month == 6 || month == 8 ||
					month == 10 || month == 12)
				{
					if(!(day >= 1 && day <= 30))
					{
						return false;
					}
					return true;
				}
	}
