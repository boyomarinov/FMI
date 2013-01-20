/**
  Header на ChessFigure, когото всички фигури тр€бва да наслед€ват.

  @file   ChessFigure.hpp
  @author V.Hadzhipopov
*/

#ifndef CHESS_FIG
#define CHESS_FIG

enum color 
{
	Black, White
};

enum figure 
{
	KING, QUEEN, ROOK, KNIGHT, BISHOP, PAWN
};


class ChessBoard;
class ChessFigure
{
public:
	virtual void Draw() const =0;
    virtual bool MoveTo(int x, int y) =0;
    virtual ChessFigure* Copy() const =0;
protected:
	ChessFigure(ChessBoard*, color, figure, int, int);
	int x, y;
	ChessBoard *board;
	color player;
	figure type;
};

#endif