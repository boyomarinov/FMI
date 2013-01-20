//Student, read by file, printed on the screen, sorted ascending and descending

#include <iostream>
class Student
{
	int fn;
	char* name;
public:
	Student();
	Student(int fac, char* n)
	{
		name = new char[strlen(n)+1];
		strcpy(name, n);
		fn = fac;
	}
	~Student()
	{
		delete[] name;
	}
	Student(const Student& m)
	{
		name = new char[strlen(m.name) + 1];
		strcpy(name, m.name);
		fn = m.fn;
	}
	Student& operator=(const Student& m)
	{
		if(this != &m)
		{
			delete[] name;
			name = new char[strlen(m.name) + 1];
			strcpy(name, m.name);
			fn = m.fn;
		}
		return *this;
	}
	int getFN() const
	{
		return fn;
	}
	char* getName() const
	{
		return name;
	}

};

class Courses
{
	int id;
	char* name;
public:
	Courses();
	Courses(int _id, char* _name)
	{
		id = _id;
		name = new char[strlen(_name)+1];
		strcpy(name, _name);
	}
	~Courses()
	{
		delete[] name;
	}
	Courses(const Courses& m)
	{
		name = new char[strlen(m.name) + 1];
		strcpy(name, m.name);
		id = m.id;
	}
	Courses& operator=(const Courses& m)
	{
		if(this != &m)
		{
			delete[] name;
			name = new char[strlen(m.name) + 1];
			strcpy(name, m.name);
			id = m.id;
		}
		return *this;
	}
	char* getName() const
	{
		return name;
	}

};

class Grades
{
	int fn;
	int id;
	int grade;
public:
	Grades(int _fn, int _id, int _grade)
	{
		fn = _fn;
		id = _id;
		grade = _grade;
	}
	int getFN() const
	{
		return fn;
	}
	int getID() const
	{
		return id;
	}
	int getGrade() const
	{
		return grade;
	}

};

template <class T>
class ArrayList
{
	T* dataList;
	int capacity;
	int length;
public:
	ArrayList(int c = 1)
	{
		length = 0;
		capacity = c;
		dataList = new T[capacity];
	}
	~ArrayList()
	{
		delete[] dataList;
	}
	ArrayList(const ArrayList <T>&o)
	{
		capacity = o.capacity;
		length = o.length;
		dataList = new T[capacity];
		for (int i=0; i<length; i++)
		{
			dataList[i] = o.dataList[i];
		}
	}
	ArrayList<T>& operator=(const ArrayList& o)
	{
		if(this != &o)
		{
			delete [] dataList;
			capacity = o.capacity;
			length = o.length;
			dataList = new T[capacity];
			for (int i=0; i<length; i++)
			{
				dataList[i] = o.dataList[i];
			}

		}
		return *this;
	}
	T& operator[](int index) const
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
			T* newArr = new E[l];
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
template <class T>
ostream& operator<<(ostream& o, const ArrayList<T>& e)
{
	o << e() << endl;
	for(int i=0;i<e();i++)
	{
		o << setw(4) << e[i];
	}
	return o;
}
template <class T>
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

struct CourseWithGrades
{
	Courses course;
	double grade;
};

struct StudentWithCourses
{
	Student s;
	ArrayList<CourseWithGrades> cources;
};

ArrayList<Grades> FilterFN(ArrayList<Grades> grades, int fn)
{

}
template <class T>
ArrayList<StudentWithCourses> GetAllData(ArrayList<Student> students, ArrayList<Courses> courses, ArrayList<Grades> grades)
{
	ArrayList<StudentWithCourses> result(Student());
	for(int i=0; i < Students(); i++)
	{
		StudentWithCourses st;
		st.Student = st[i];
		st.cources.grade = GetAllGrades(students[i].getFN());
		result.ToEnd(student);
	}
	return result;
}
ArrayList<CourseWithGrades> GetAllGrades(int fn,
										ArrayList<Courses> courses,
										ArrayList<Grades> grades)
{
	ArrayList<CourseWithGrades> result(Courses());
	grades = FilterFn(grades, fn);
	for(int i=0; i<Cources(); i++)
	{
		for(int j=0; j<grades(); j++)
		{
			if(courses[i].getID() == grades[j].getID())
			{
				CourseWithGrades c;
				c.course = courses[i];
				c.grade = grades[j].getGrade();
				result.ToEnd(c);
			}
		}
	}
	return result;
}
	template <class T>
	ArrayList<T> Sort() const
	{
		ArrayList<T> temp(cap);
		for(int i=0; i<lenght; i++)
		{
			temp.ToEnd(Min());
		}
		return temp;
	}
	template <class T>
	ArrayList<T> Filter (bool (*Pred(T a))) const		//bool Pred(T a, const T& a)
	{
		ArrayList<T> temp(len);
		for(int i=0; i<;em; i++)
		{
			if(Pred(*this[i]))
			{
				temp.ToEnd(*this[i]);
			}
		}
	}
bool gt40000(Student s)
{
	return s.getFN()>40000;
}


template <class T>
class Comparison
{
public:
	virtual int Compare(T a, T b) const = 0;
	int operator() (T a, T b) const
	{
		return Compare(a, b); 
	}
};
template <class T>
ArrayList<T> Sort (ArrayList<T> l, const Comparison<T>& comp)
//& - because class Comparison is abstract, meaning there are no objects 
//derived by it and we cannot copy them
{
	for(int i=0; i < l()-1; i++)
	{
		for(int j = i+1; j < l; j++)
		{
			if(comp(l[i], l[j]) > 0)
			{
				swap(l[i], l[j]);
			}
		}
	}
	return l;
}

template <class T>
class ReverseComparison: public Comparison<T>
{
private:
	Comparison<T>* comp;
public:
	int Compare(T a, T b) const
	{
		return -(*comp)(a, b);
	}
	ReverseComparison(Comparison<T>& comparison)
	{
		comp = &comparison;
	}
};
class CompByFn : public Comparison<Student>
{
public:
	int Compare(Student a, Student b)
	{
		return (a.getFN() == b.getFN()) ? 0 :  a.getFN() < b.getFN() ? -1 : 1;
		//return a.getFN() - b.getFN(); 
	}
};
template <class T>
class CompareByFunc: public Comparison<T>
{
private:
	int (*func)(T a, T b);
public:
	CompareByFunc(int (*f)(T, T))
	{
		func = f;
	}
	int Compare(T a, T b) const
	{
		return func(a, b);
	}
	int CompareByFN(Student a, Student b)
	{
		return a.getFN() - b.getFN();
	}
};

void main()
{

	//ifstream inp("test.txt");
	//ArrayList<Student> students;
	//inp >> Students;
	//inp.close();
	//CompareByFunc comp(CompByFN);
	//ReverseComparison<Student> rev(comp);
	//cout << Sort(Students, comp);
	//cout << Sort(students, rev);
}
