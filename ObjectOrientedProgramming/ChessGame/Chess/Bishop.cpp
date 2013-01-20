/**
  Дефиниции на Bishop. 

  @file   Bishop.cpp
  @author V.Hadzhipopov
*/

#include "Bishop.hpp"
#include <iostream>
using namespace std;

Bishop::Bishop(ChessBoard* _board, color _player, int _x, int _y) 
: ChessFigure(_board, _player, BISHOP, _x, _y) {}

void Bishop::Draw() const
{
	if(player == White)
		cout << "wB";
	else
		cout << "bB";
}

bool Bishop::MoveTo(int _x, int _y)
{
	return isDiagMove(_x, _y);

}
ChessFigure* Bishop::Copy() const
{
	return NULL;
}
bool Bishop::isDiagMove(int to_x, int to_y)
{
	if(to_x > 8 || to_y > 8 || to_x < 0 || to_y < 0)
		return false;
	if(x == to_x && y == to_y)
		return true;
	return (isDiagMove(to_x+1, to_y+1) || isDiagMove(to_x-1, to_y-1) ||
			isDiagMove(to_x-1, to_y+1) || isDiagMove(to_x+1, to_y-1));
}