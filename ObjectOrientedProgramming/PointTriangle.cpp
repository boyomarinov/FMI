#include<iostream>
using namespace std;

struct Point
{
	double x, y;
	void Print() {
		cout<<"("<<x<<", "<<y<<")";
	}
};


class Triangle
{
public:
	Triangle();									
	void SetPoints ( Point a, Point b, Point c); 
	void Print() {
		a.Print(); b.Print(); c.Print();
		cout<<endl;
	}

private:
	Point a, b, c;
};

Triangle::Triangle(){
	a.x = a.y = 0;
	b.x = b.y = 0;
	c.x = c.y = 0;
}

void Triangle::SetPoints ( Point a, Point b, Point c) 
{
	this->a = a;
	this->b = b;
	this->c = c;
}

//------------------------------------------------------------------------------------
//Element of linked list
struct TriangleNode
{
    //the data
	Triangle triangle; 
    //pointer to next member of the linked list
	TriangleNode* next;
};

//starts an empty linkes list
TriangleNode* first = NULL;			

//Adds element in the end of a linked list
void add_element(Triangle tr)
{
	TriangleNode* to_add = new TriangleNode;
	//make changes by VALUE
	to_add->triangle = tr;					
	to_add->next = NULL;					

	if(first==NULL){
		first = to_add;
		return;
	}

	first = to_add;
	//find current end of the list and add element there
	TriangleNode* walk = first;
	while (walk->next != NULL){
		walk = walk->next;
	}
	//modify last element to point to the newly added one
	walk->next = to_add;
}

voidPrintTriangleList()
{
	TriangleNode* walk= first;
	while (walk != NULL){
		walk->triangle.Print();
		walk = walk->next;
	}
}

//------------------------------------------------------------------------------------

void main()
{
Triangle triangle;						
			
Point a = {1,1};
Point b = {2,2};
Point c;
c.x = 1.5; c.y = 1.5;

triangle.SetPoints (a, b, c);

add_element( triangle );
add_element( triangle );

//system("pause");
}
