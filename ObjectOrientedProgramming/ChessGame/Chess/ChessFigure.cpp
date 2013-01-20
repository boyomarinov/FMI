/**
  Конструктора на ChessFigure, когото всички фигури трябва да ползват.

  @file   ChessFigure.cpp
  @author V.Hadzhipopov
*/

#include "ChessFigure.hpp"

ChessFigure::ChessFigure(ChessBoard* _board, color _player,
						 figure _type, int _x, int _y)
{
	board = _board;
	player = _player;
	type = _type;
	x = _x;
	y = _y;
}