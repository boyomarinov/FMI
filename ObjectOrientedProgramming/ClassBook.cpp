#include <iostream>
#include <cstring>
using namespace std;

class Book
{
public:
	Book();
	~Book();
	Book(const Book&);
	Book& operator=(const Book&);
	void setTitle(char *);
	void setAuthor(char *);
	void SetBooknum(int);
	void Print();
	int compare(const Book&) const;
private:
	char* title;
	char* author;
	int booknum;
};

Book::Book()
{
	title = NULL;
	author = NULL;
	booknum = 0;
}
Book::~Book()
{
	delete[] title;
	delete[] author;
}
Book::Book(const Book &m)
{
	setTitle(m.title);
	setAuthor(m.author);
	setBooknum(m.booknum);
}
Book& Book::operator=(const Book& m)
{
	if(this != &m)
	{
		delete[] title;
		delete[] author;
		setTitle(m.title);
		setAuthor(m.author);
		setBooknum(m.booknum);
	}
	return *this;
}

void Book::setTitle(char * _title)
{
	title = new char[strlen(_title)+1];
	strcpy(title, _title);
}
void Book::setAuthor(char * _author)
{
	author = new char[strlen(m_author)+1];
	strcpy(author, _author);
}
void Book::SetBooknum(int _booknum)
{
	booknum = _booknum;
}
void Book::Print()
{
	cout << "Number: " << booknum << endl;
	cout << "Title: " << title << endl;
	cout << "Author: " << author << endl;
}
Book::compare(const Book& m) const
{
	if(strcmp(title, m.title) == -1){
		return -1;
	}
		else if(strcmp(title, m.title) == 0){
		return 0;
		}
		else return 1;
}
