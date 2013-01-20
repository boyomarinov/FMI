/**
  Header на ChessBoard, който ще съдържа моментното състояние на дъката, 
  ръководи ходовете и определя край на играта. 

  @file   ChessBoard.hpp
  @author V.Hadzhipopov
*/

#include "Bishop.hpp"
#include "King.hpp"
#include "Knight.hpp"
#include "Pawn.hpp"
#include "Queen.hpp"
#include "Rook.hpp"

class ChessBoard
{
public:
	ChessBoard();
	ChessBoard(const ChessBoard& other);
	~ChessBoard();
	ChessBoard& operator =(const ChessBoard& other);
	ChessFigure* Get(int x, int y);
	bool Move(int from_x, int from_y, int x, int y);
	void GameOver();
	void Remove(int x, int y);
private:
	ChessFigure* board[8][8];
};
