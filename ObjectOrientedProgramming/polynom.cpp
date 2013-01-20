#include <iostream>
#include "polynom.hpp"
using namespace std;

Polynom::Polynom(){
	MonomialNode* node = new MonomialNode;
	node->data.coef = 0;
	node->data.power = 0;
	node->next = NULL;
	node->prev = NULL;
	first = node;
}

Polynom::~Polynom(){
	MonomialNode* walk1 = first;
	MonomialNode* walk2 = walk1->next;
	while(walk2->next != NULL){
		delete walk1;
		walk1 = walk2;
		walk2 = walk1->next;
	}
		delete walk2;

}

void Polynom::AddMonomial (double coef, int power){
	MonomialNode* temp = new MonomialNode;
	temp->data.coef = coef;
	temp->data.power = power;
	if(first == NULL){
		temp->next = NULL;
		temp->prev = NULL;
		temp = first;
		return;
	}
	MonomialNode* walk = first;
	while(walk->data.power >= power){
		walk = walk->next;
	}
	if(walk->data.power == power){
		delete temp;
		walk->data.coef += coef;
		return;
	}
	temp->prev = walk;
	temp->next = walk->next;
	walk->next = temp;
	if(temp->next != NULL){
		walk = temp->next;
		walk->prev = temp;
	}
}