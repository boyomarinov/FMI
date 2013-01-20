/*
This is The chess game screen class which will display the game actions on the screen.

@file Screen.hpp
@author Gandi Pirkov
*/
#include <iostream>
#include <cstdlib>
#include "ChessBoard.hpp"
using namespace std;

class Screen : public ChessBoard
{
public:
	Screen(int a);

	//Will maintain the game console.
	void printScreen();

private:
	int GameBeginer;
};