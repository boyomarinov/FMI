/**
  Header на Bishop. 

  @file   Bishop.hpp
  @author V.Hadzhipopov
*/

#include "ChessFigure.hpp"

class Bishop : public ChessFigure
{
public:
	Bishop(ChessBoard* _board, color player, int _x, int _y); 
	void Draw() const;
	bool MoveTo(int _x, int _y);
	ChessFigure* Copy() const;
private:
	bool isDiagMove(int to_x, int to_y);
};