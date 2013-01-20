#include <iostream>
using namespace std;

template <class T>
struct BinNode
{
	T data;
	BinNode<T>* left, right;
}

template <class T>
class BinTree
{
public:
	BinTree();
	BinTree(BinTree<T>& left, const T& root, const BinTree<T>& right)
	{
		root = new BinNode<T>;
		root->data = r;
		root->left = Copy(left.root);
		root->right = Copy(right.root);
	}
	~BinTree();
	BinTree(const BinTree<T>&);
	BinTree<T>& operator=(const BinTree<T>&);
	T GetRootValue() const
	{
		return root->data;
	}
	bool IsEmpty() const
	{
		return root == NULL;
	}
	BinTree<T> Left() const
	{
		BinNode<T>* copy = Copy(root->left);
		return BinTree<T>(root->left);
	}
	BinTree<T> Right() const
	{
		BinNode<T>* copy = Copy(root->right);
		return BinTree<T>(root->right);
	}
	BinTree<T> Copy(BinTree<T>& o)
	{

	}
	BinTree<T> Read(istream& in)
	{
		T root;
		in >> root;
		int hasLeft, hasRight;
		in >> hasLeft >> hasRight;
		BinTree<T> left = hasLeft ? Read(in) : BinTree<T>();
		BinTree<T> right;
		if(hasRight)
		{
			right = Read(in);	
		}
		return BinTree<T> (left, root, right);
	}
	BinTree<T> Insert(const T& node, const T& newV)
	{
		if(node == t.GetRootValue())
		{
			BinTree<T> left = t.Left(), right = t.Right();
		}
		BinTree<T> newTree(BinTree<T>(), nweV, BinTree<T>());
		if(left.IsEmpty())
		{
			return BinTree<T>(newTree, t.GetRootValue(), right);
		}
		else if(right.IsEmpty())
		{
			return BinTree<T>(left, t.GetRootValue(), newTree);
		}
		else
		{
			return t;
		}
		return BinTree<T>(Insert(node, newV, t.Left()), t.GetRootValue(), Insert(node, newV, t.Right()));
	}

	//Add an ordered tree
	BinTree<T> InsertOrd(const BinTree<T>& t, const T& value)
	{
		if(t.IsEmpty)
		{
			return BinTree<T>(BinTree<T>(), value, BinTree<T>());
		}
		T rootValue = t.GetRootValue();
		BinTree<T> left = t.Left(), right = t.Right();
		if(value < rootValue)
		{
			left = InsertOrd(left, value);
		}
		else
		{
			right = InsertOrd(right, value);
		}
		return BinTree<T>(left, rootValue, right);
	}
	T Min(const BinTree<T> & t)
	{
		BinTree<T> left = t.Left();
		if(!left.IsEmpty())
		{
			return Min(left);
		}
		return t.GetRootValue();
	}
	BinTree<T> DelMin(const BinTree<T>& t)
	{
		T root = t.GetRootVelu();
		BinTree<T> left = t.Left(), right = t.Right();
		if(!left.IsEmpty())
		{
			return BinTree<T>(DelMin(left, root, right);)
		}
		return right;
	}
	BinTree<T> DeleteOrd(const BinTree<T>& t, const T value)
	{
		if(t.IsEmpty())
		{
			return t;
		}
		T root = t.GetRootValue();
		BinTree<T> left = t.Left(), right = t.Right();
		if(root == value)
		{
			if(left.IsEmpty())
			{
				return right;
			}
			else if(right.IsEmpty())
			{
				return left;
			}
			else
			{
				return BinTree<T>(left, Min(right), DelMin(right));
			}
		}
		else if(value < root)
		{
			return BinTree<T>(DeleteOrd(left, value), root, right);
		}
		else
		{
			return BinTree<T>(left, root, DeleteOrd(right, value));
		}
	}

	friend ostream& operator<<(ostream&, const BinTree<T>&)

	friend istream& operator>>(istream&, BinTree<T>&)


private:
	BinNode<T>* root;

	template <class T>
	BinTree(BinNode<T>* t)
	{
		root = Copy(t);
	}

};

template <class T>
void Print(ostream & out, const BinTree<T>& t)
{
	if(!(t.IsEmpty()))
	{
		out << t.GetRootValue() << !left.IsEmpty() << !right.IsEmpty() << endl;
		o << left << right;
	}
	else
	{

	}
}

template <class T>
ostream& operator<<(ostream& out, const BinTree<T>& t)
{
	Print(out, t);
	//we give the whole tree, because we're allowed to use only the public
	//interface and cannot access the root of the tree
	return out;
}

template <class T>
istream& operator>>(istream& in, BinTree<T>& t)
{
	t = Read(in);
	return in;
}
