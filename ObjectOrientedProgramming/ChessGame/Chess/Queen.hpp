/**
  Header на Queen. 

  @file   Queen.hpp
  @author V.Hadzhipopov
*/

#include "ChessFigure.hpp"

class Queen : public ChessFigure
{
public:
	Queen(ChessBoard*, color); 
	void Draw() const;
	bool MoveTo(int, int);
	ChessFigure* Copy() const;
};