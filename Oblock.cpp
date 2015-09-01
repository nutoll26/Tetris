#include "OBlock.h"

/*
	¿À ºí·Ï
*/
/*
	Function name : Rotate
	Discription : turn O block
*/
void OBlock::Rotate()
{
	return;
}
/*
	Function name : CanMoveDown
	Discription : test move down O block
*/
bool OBlock::CanMoveDown(int row, int col, int board[][10]) const
{
	if(row != 17 && board[row+1][col] == 0 && board[row+1][col-1] == 0)
		return true;
	else
		return false;
}

/*
	Function name : CanMoveLeft
	Discription : test move left O block
*/
bool OBlock::CanMoveLeft(int row, int col, int board[][10]) const
{
	if(col-1 != 0 && board[row][col-2] == 0 && board[row-1][col-2] == 0)
		return true;
	else
		return false;
}

/*
	Function name : CanMoveRight
	Discription : test move right O block
*/
bool OBlock::CanMoveRight(int row, int col, int board[][10]) const
{
	if(col != 9 && board[row][col+1] == 0 && board[row-1][col+1] == 0)
		return true;
	else
		return false;
}
/*
	Function name : CanRotate
	Discription : test rotate O block
*/
bool OBlock::CanRotate(int row, int col, int board[][10]) const
{
	return true;
}
/*
	Function name : EndGame
	Discription : test end of game
*/
bool OBlock::EndGame(int board[][10]) const
{
	if(board[2][4] != 0 || board[2][5] != 0) return true;
	else return false;
}