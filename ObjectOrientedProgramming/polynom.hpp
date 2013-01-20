#ifndef POLYNOM
#define POLYNOM

struct Monomial {
	double coef;
	int power;
};

struct MonomialNode {
	Monomial data;
	MonomialNode* next;
	MonomialNode* prev;
};

class Polynom
{
public:
	Polynom();
	void AddMonomial (double coef, int power);
	~Polynom();
	void Print();
private:
	MonomialNode* first;
};

#endif
