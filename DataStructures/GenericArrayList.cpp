//random number of elements
//indexator
//change of values
//element count
//change of specific elements
//add element in the end
//input from and ouput to a file
//!encapsulatoin

//template <class T>
//class Test
//{
//	T f1(T [a]);
//};
//template <class T>;
//T Test<T>::f1(T [a]);
//(int Test<int>::f1(int a[]))

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

template <class E>
class ArrayList
{
	E* dataList;
	int capacity;
	int length;
public:
	ArrayList(int c = 1)
	{
		length = 0;
		capacity = c;
		dataList = new E[capacity];
	}
	~ArrayList()
	{
		delete[] dataList;
	}
	ArrayList(const ArrayList <E>&o)
	{
		capacity = o.capacity;
		length = o.length;
		dataList = new E[capacity];
		for (int i=0; i<length; i++)
		{
			dataList[i] = o.dataList[i];
		}
	}
	ArrayList<E>& operator=(const ArrayList& o)
	{
		if(this != &o)
		{
			delete [] dataList;
			capacity = o.capacity;
			length = o.length;
			dataList = new E[capacity];
			for (int i=0; i<length; i++)
			{
				dataList[i] = o.dataList[i];
			}

		}
		return *this;
	}
	E& operator[](int index) const
	{
		return (index < length && index > 0) ? dataList[index]:dataList[0];
	}
	int operator()() const
	{
		return length;
	}
	void setLength(int l)
	{
		if(l > capacity)
		{
			E* newArr = new E[l];
			capacity = l;
			for(int i=0; i<length; i++)
			{
				newArr[i] = dataList[i];
			}
			delete[] dataList;
			dataList = newArr;
			length = l;
		}

	}
};
template <class E>
ostream& operator<<(ostream& o, const ArrayList<E>& e)
{
	o << e() << endl;
	for(int i=0;i<e();i++)
	{
		o << setw(4) << e[i];
	}
	return o;
}
template <class E>
istream& operator>>(istream& inp, ArrayList<E>& e)
{
	int temp = 0;
	inp >> temp;
	e.setLength(temp);
	for(int i=0; i<e(); i++)
	{
		inp >> e[i];
	}
	return inp;
}


void main()
{

	ArrayList<int> A;
	A.setLength(3);
	//for(int i=0; i<A(); i++)
	//{
	//	cout << "Element: ";
	//	cin >> A[i];
	//}

	//ofstream file("test.txt");
	//for(int i=0; i<A(); i++)
	//{
	//	file << A[i];
	//}
	//file.close();

	ifstream file1("test2.txt");
	//for(int i=0; i<A();i++)
	//{
	//	file1 >> A[i];
	//}
	//for(int i=0; i<A(); i++)
	//{
	//	cout << A[i];
	//}
	file1 >> A;
	cout << A;
	cout << endl;
	file1.close();
}
