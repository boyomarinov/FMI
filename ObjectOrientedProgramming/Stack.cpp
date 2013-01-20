class Stack
{
	int* data;
	int c;
	int cap;
	Stack();
	Stack(const Stack &other);
}
Stack::Stack()
{
	data = new int [20];
	cap = 20;
	c = 0;
}
Stack::Stack(const Stack &other)
{
	cap = other.cap;
	c = other.c;
	data  = new int [cap];
	for(int i = 0; i < c; i++)
	{
		data[i] = s.data[i];
	}
}
//cpy(const Stack& s)

Stack::~Stack()
{
	delete [] data;
}
	Stack& Stack::operator= (const Stack& other)
	{
	if(this == &other)
		return *this;
	if(other.c == this->cap)
	{
		delete [] this->data;
		this->data = new[other.cap];
		cap = other.cap;
	}
	c = other.c;
	for(int i = 0; i < c; i++)
	{
		*(data + i) = *(other.data + i);
	}
	return *this;
}

int Stack::Pop()
{
	return data[--c];
}

void Stack::Extend()
{
	int * old = data;
	data = new int[2*cap];
	for(int i = 0; i < c; i++)
	{
		data[i] = old[i];
	}
	cap *= 2;
	delete[] old;
}

void Stack::Push(const int& push)
{
	if(c == cap)
	{
		extend();
	}
	data[c++] = push;
}