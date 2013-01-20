#include <iostream>
#include <fstream>
#include "Student.h"

using namespace std;

void Menu ()
{
	cout << "Menu: " << endl;
	cout << "1. Print All" << endl;
	cout << "2. Sort" << endl;
	cout << "3. Edit" << endl;
	cout << "4. Add" << endl;
	cout << "5. Delete" << endl;
	cout << "6. Sorted Add" << endl;
	cout << "7. Exit" << endl;
	cout << "Enter your choice: " << endl;
	int choice = 0;
	cin >> choice;
	while(true)
	{
		switch(choice)
		{
		case 1: 
			PrintAll(fstream&);
			break;
		case 2:
			Sort(fstream&);
			break;
		case 3:
			Edit(fstream&);
			break;
		case 4:
			Add();
			break;
		case 5:
			Delete();
			break;
		case 6:
			SortedAll();
			break;
		case 7:
			Exit();
			break;
		default:
			cout << "Invalid number. Please try again." << endl;
			break;
		}
	}
}


 void ReadStudent(ifstream& f, Student& s)
{
	Student S1;
	while(f.good()) // return true while we can read from the file
		//eof - returns true while we haven't reached the end of file
		//bad - return true when the file is corrupted
	{
		f.read(reinterpret_cast<char*>(&S1), sizeof(Student)); //(char*)(&S1)
		if(f.good())
		{
			S1.Add(f, S1);
		}
	}
}

 void PrintAll(ifstream& f, Student& s)
 {
	 int i = 0;
	 while(f.good())
	 {
		 cout << ReadStudent(f, s);
	 }
 }

 void main()
 {
	 fstream file1("test1", ios::in || ios::out || ios::binary);

 }
