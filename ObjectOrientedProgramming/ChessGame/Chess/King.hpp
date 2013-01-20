/**
  Header на King. 

  @file   King.hpp
  @author V.Hadzhipopov
*/

#include "ChessFigure.hpp"

class King : public ChessFigure
{
public:
	King(ChessBoard*, color); 
	void Draw() const;
	bool MoveTo(int, int);
	ChessFigure* Copy() const;
};