#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct studentData
{
	int facultyNum;
	char name[128];
};

void Add(studentData other)
{
	ofstream file("Student.bin",ios::binary | ios::app);
	file.write((char*)& other,sizeof(studentData));	
}

void Print()
{
	ifstream file("Student.bin",ios::binary);
	studentData temp;
	while(file.read((char*)&temp,sizeof(studentData))>0)
	{
		cout<<temp.facultyNum<<" "<<temp.name<<endl;
	}
}

void Sort()
{
	studentData temp;
	temp.facultyNum =0;
	int Min;
	studentData buff;
	ifstream file("Student.bin",ios::binary);
	ofstream file1("StudentSorted.bin",ios::binary);

	while(temp.facultyNum != -1)
	{
		file.read((char*)&temp,sizeof(studentData));
		file.seekg(ios::cur);
		file.read((char*)&buff,sizeof(studentData));
	}
}

bool Edit(int facultyNum)
{
	int check = 0;
	int counter = 0;
	char tempName[256];
	fstream file("Student.bin",ios::binary | ios::in | ios::out);
	studentData temp;

	while(file.read((char*)&temp,sizeof(studentData))>0)
	{
		if(temp.facultyNum == facultyNum)
		{
			cout<<"Enter 1 to change the FN or 2 to change the Name: ";
			cin>>check;
			switch(check)
			{
			case 1: 
				{
					cout<<"Enter FN: ";
					cin>> check;
					temp.facultyNum = check;
					file.seekp(counter*sizeof(studentData));
					file.write((char*)&temp,sizeof(studentData));
					return true;
				}break;
			case 2:
				{
					cout<<"Enter Name: ";
					cin>>tempName;
					strcpy(temp.name,tempName);
					file.seekp(counter*sizeof(studentData));
					file.write((char*)&temp,sizeof(studentData));
					return true;
				}break;
			default:{
				cout<<"WrongInputData!";
				return false;
					}break;
			}
			
		}
		counter++;
	}
	return false;
}

bool Delete(int facultyNum)
{
	ifstream read("Student.bin",ios::binary);
	ofstream write("NewStudent.bin",ios::binary | ios::app);
	studentData buff;
	bool check = false;
	while(read.read((char*)&buff,sizeof(studentData))>0)
	{
		if(buff.facultyNum != facultyNum)
		{
			write.write((char*)&buff,sizeof(studentData));
			check = true;
		}
	}
	read.close();
	write.close();
	remove("Student.bin");
	rename("NewStudent.bin","Student.bin");
	return check;
}

void SortedAdd(studentData other)
{
}

void main()
{
	studentData first;
	first.facultyNum = 12345;
	strcpy(first.name,"George Georgiev");
	studentData second;
	second.facultyNum = 54321;
	strcpy(second.name,"Pesho Petrov");
	Add(first);
	Add(second);
	Sort();
	Print();
}
