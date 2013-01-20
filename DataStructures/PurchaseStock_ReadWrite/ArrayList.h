#include <iostream>
#include <fstream>


template <class T>
class ArrayList
{
	T* data;
	size_t capacity;
	size_t count;
	T* copy() const
	{
		T* result = new T[capacity];
		copy(result, data, count);
		return result;
	}
	static void copy(T* dest, const T* source, size_t count)
	{
		for (size_t i = 0; i < count; i++)
		{
			dest[i] = source[i];
		}
	}
	void SetCapacity(size_t newCapacity)
	{		
		if (newCapacity != capacity)
		{
			T* newArray = new T[newCapacity];
			copy(newArray, data, count);
			delete[] data;
			data = newArray;
			capacity = newCapacity;
		}
	}
	static size_t max(size_t const & a, size_t const & b)
	{ 
		return (a>b)?a:b;
	}
	static size_t min(size_t const & a, size_t const & b)
	{ 
		return (a<b)?a:b;
	}

public:
	ArrayList(size_t expectedLength = 1)
	{
		capacity = expectedLength;
		count = 0;
		data = new T[expectedLength];
	}
	ArrayList(const ArrayList<T>& other)
	{
		capacity = other.capacity;
		count = other.count;
		data = other.copy();
	}

protected:
	ArrayList(const T* array, size_t len)
	{
		count = capacity = len;
		data = new T[len];
		copy(data,array,len);
	}

public:
	~ArrayList()
	{
		delete[] data;
	}
	ArrayList<T>& operator=(const ArrayList<T>& other)
	{
		if (this != &other)
		{
			delete[] data;
			capacity = other.capacity;
			count = other.count;
			data = other.copy();
		}
		return *this;
	}
	void Add(const T& newElement)
	{
		if (count == capacity)
		{
			SetCapacity(count*2);
		}
		data[count++] = newElement;
	}
	void SetLength(size_t length)
	{
		if (length > capacity)
			SetCapacity(max(length, capacity*2));
		count = length;
	}
	void Trim()
	{
		SetCapacity(count);
	}
	// In case of const instance
	T& operator[](size_t index) const
	{
		return data[min(max(0, index), count - 1)];
	}
	size_t operator()() const
	{
		return count;
	}
	size_t Length() const
	{
		return count;
	}
	T* GetData() const
	{
		return data;
	}
	size_t GetCount() const
	{
		return count;
	}
};

template <class T>
std::istream& operator>>(std::istream& inp, ArrayList<T>& t)
{
	size_t count;
	inp>>count;
	if (count < 0)
		count = 0;
	t.SetLength(count);
	for (size_t i = 0; i < count; i++)
	{
		inp>>t[i];
	}
	return inp;
}

template <class T>
std::ostream& operator<<(std::ostream& out, const ArrayList<T>& t)
{
	out << t() << std::endl;
	if(t()>0)
	{
		for (size_t i = 0 ;i < t(); i++)
		{
			out<<t[i]<<std::endl;
		}
	}
	return out;
}