/**
  Header на Pawn. 

  @file   Pawn.hpp
  @author V.Hadzhipopov
*/

#include "ChessFigure.hpp"

class Pawn : public ChessFigure
{
public:
	Pawn(ChessBoard*, color); 
	void Draw() const;
	bool MoveTo(int, int);
	ChessFigure* Copy() const;
};