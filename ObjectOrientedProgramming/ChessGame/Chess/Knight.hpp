/**
  Header на Knight. 

  @file   Knight.hpp
  @author V.Hadzhipopov
*/

#include "ChessFigure.hpp"

class Knight : public ChessFigure
{
public:
	Knight(ChessBoard*, color); 
	void Draw() const;
	bool MoveTo(int, int);
	ChessFigure* Copy() const;
};