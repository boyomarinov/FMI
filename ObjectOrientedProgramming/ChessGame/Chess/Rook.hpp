/**
  Header на Rook. 

  @file   Rook.hpp
  @author V.Hadzhipopov
*/

#include "ChessFigure.hpp"

class Rook : public ChessFigure
{
public:
	Rook(ChessBoard*, color); 
	void Draw() const;
	bool MoveTo(int, int);
	ChessFigure* Copy() const;
};