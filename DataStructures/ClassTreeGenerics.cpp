#include <iostream>
using namespace std;

template <class T>
struct Node
{
	T data;
	LList<Node<T>*> links; //linked list
}
template <class T>
class Tree
{
	Node<T>* root;
public:
	Tree()
	{
		root = NULL;
	}
	~Tree()
	{
		if(root != NULL)
		{
			DeleteTree(root);
		}
	}
	static void DeleteTree(Node<T>* r)
	{
		Elem<Node<T>*>* tmp = new Elem<Node<T>*>*;
		r->links.IterStart();
		while(tmp = r->links.Iter())
		{
			DeleteTree(tmp->data);
		}
		delete r;
	}

	Tree<T> operator=(Tree<T> & other)
	{
		if(this != &other)
		{
			if(root != NULL)
			{
				DeleteTree(root);
			}
			root = CopyTree(other.root);
		}
		return *this;
	}
	Node<T>* CopyTree(Node<T>* root)
	{
		if(root != NULL)
		{
			Elem<Node<T>*>* tmp;
			Node<T>* t = new Node<T>;
			t->data = root->data;
			root->links.IterStart();
			while(tmp = root->links.Iter())
			{
				t->links.ToEnd(CopyTree(tmp->data));
			}
			return r;
		}
		return NULL;
	}
	Tree(const Tree<T> &other)
	{
		root = CopyTree(other.root);
	}
	Node<T>* Find(T data)
	{
		Node<T>* temp = this->root;
		Stack<Node<T>*>* s;
		s.push(temp);
		while(!s.IsEmpty())
		{
			temp = s.pop();
		}
		if(temp.data == data)
		{
			return temp;
		}
		temp->links.IterStart();
		Elem<Node<T>*>* iterator;

		while(iterator = temp->links.Iter())
		{
			s.push(iterator->data);
		}
		return NULL;
	}
	void Insert(T after, T data)
	{
		Node<T>* temp = Find(after);
		if(temp != NULL)
		{
			Node<T>* add  = new Node<T>*;
			add->data = data;
			temp->links.ToEnd(add);
		}
	}
	void Delete(T data)
	{
		if(root.data == data)
		{
			DeleteTree(root);
		}
		else
		{
			Node<T>* node = Find(data);
			Node<T>* father = FindFather(data, root);
			if(father != NULL)
			{
				Elem<Node<T>*>* iter;
				node->links.IterStart();
				while(iter = node->links.Iter())
				{
					father->links.ToEnd(iter->data);
				}
				father->links.Remove(node);
				delete node;
			}
		}
	}
	template <class T>
	bool Contains(T data, LList<Node<T>*>* List)
	{
		elem<Node<T>*>* iter;
		List.IterStart();
		while(iter = List.Iter())
		{
			if(iter->data->data == data)
			{
				return true;
			}
		}
		return false;
	}
	Node<T>* FindFather(T data, Node<T>* StartRoot)
	{
		if(Contains(StartRoot->links, data))
		{
			return StartRoot;
		}
		Elem<Node<T>*>* iterator;
		StartRoot->links.IterStart();
		while(iterator = StartRoot->links.Iter())
		{
			Node<T>* t = FindFather(data, iterator->data);
			if(t != NULL)
			{
				return t;
			}
		}
		return NULL;
	}
	friend ostream operator<<(ostream&, const Tree<T>&)
	template <class T>
	friend istream operator>>(istream&, Tree<T>&)

};

	template <class T>
	ostream operator<<(ostream& out, Tree<T>& tr)
	{
		Print(out, tr->root);
	}
	template <class T>
	void Print(ostream&out, TreeNode<T>* r)
	{
		if(r != NULL)
		{
			out << r->data;
			out << r->links.Lenght();
			r->links.IterStart();
			Elem<Node<T>*>* temp;
			while(temp = r->links.Iter())
			{
				Print(out, temp->data);
			}
		}
	}
	template <class T>
	istream operator>>(istream& in, Tree<T>& tr)
	{
		if(tr.root != NULL)
		{
			Tree<T>::DeleteTree(tr.root);
		}
		tr.root = Read<T>(in);
		return in;
	}
	template <class T>
	Node<T>* Read (istream& in)
	{
		Node<T>* temp = new Node<T>;
		in >> temp->data;
		int count;
		in >> count;
		for(int i=0; i<count; i++)
		{
			Node<T>* t;
			t = Read(in);
			temp->links.ToEnd(t);
		}
		return temp;
	}



void main()
{

}
