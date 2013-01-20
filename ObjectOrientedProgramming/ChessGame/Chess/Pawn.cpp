/**
  Дефиниции на Pawn. 

  @file   Pawn.cpp
  @author V.Hadzhipopov
*/

#include "Pawn.hpp"
#include <iostream>
using namespace std;

Pawn::Pawn(ChessBoard *, color, int _x, int _y)
: ChessFigure(ChessBoard* _board, color _player, figure _type, int _x, int _y) {}

void Pawn::Draw() const
{
	if(player == White)
		cout << "wP";
	else
		cout << "bP";
}

Pawn::MoveTo(int, int)
{


}

bool Forward(int to_x, int to_y)
{
	if(to_x < 0 || to_y < 0 || to_x > 8 || to_y > 8 || to_x + 1 = ){
		return false;
	}

}
