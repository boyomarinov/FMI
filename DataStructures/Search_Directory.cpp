//Pazim direktoriite s imena v dyrvo. Tyrsim failove v direktoriite
//We keep directories' names in a tree. We perform search over files in directories
//fil? -> fil(e), fil(a)
//fil* -> fil(whatever it is)

//1. string GetQuery(string source)			
//2. bool isRecursive(string source)			
//3. bool isMatch(string Query, string stringToMatch)	
//---------------------------------------------------------------------------------
//4.LList<Node<string>*> Find(Tree<string> tree, string query, bool isRecursive)
//5. main()

#include <iostream>
#include <string>
using namespace std;

bool IsRecursive(string source)
{
	if(source.length() >= 2)
	{
		return (source[source.length() - 2] == '/' &&
			source[source.length() - 1] == 's');
	}
	return false;
}
string GetQuery(string source)
{
	if(!IsRecursive(source))
	{
		return source;
	}
	return source.substr(0, source.length() - 3); 
}

bool IsMatch(string query, string stringToMatch)
{
	if(query.length() == 0)
	{
		return stringToMatch.length() == 0;
	}
	if(query[0] != '*')
	{
		return stringToMatch.length() >= 1 && (query[0] == '?' || query[0] == stringToMatch[0])
			&& IsMatch(query.substr(1, query.length() - 1), stringToMatch.substr(1, stringToMatch.length() - 1));
	}
	string t = query.substr(1, query.length() - 1);
	for(int i=0; i<stringToMatch.length(); i++)
	{
		if(IsMatch(t, stringToMatch.substr(i, stringToMatch.length() - i)))
		{
			return true;
		}
		return false;
	}
}

template <class T>
LList<Node<string>*> Find(Node<string>* r, string query, bool isRecursive)
{
	//Node<string>* r = tree.GetRootNode();
	LList<string> result;
	if(IsMatch(query, r->data))
	{
		result.ToEnd(r);
	}
	//result.Concat(Find(r->links, query));
	if(IsRecursive)
	{
		Elem<Node<string>*>* iter;
		r->links.IterStart();
		while(iter = r->links.Iter())
		{
			result.Concat(Find(Iter->data, query, IsRecursive));
		}
	}
	return result;
}

template <class T>
LList<Node<string>*>* Find(Tree<string> tree, string query, bool isRecursive)
{
	return Find(tree->GetRootNode(), query, isRecursive);
}

void main()
{
	
}
