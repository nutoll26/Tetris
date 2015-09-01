#include "DiaBlock.h"

/*
	다이아 블록
*/
void DiaBlock::Rotate()
{
	return;
}
bool DiaBlock::CanMoveDown(int row, int col, int board[][10]) const
{
	switch(state)
	{
	case 0: case 1: case 2: case 3:
		if(row+1 != 17 && board[row+1][col-1] == 0 && board[row+2][col] ==0 && board[row+1][col+1] == 0)
			return true;
		else
			return false;
	}
	return false;
}
bool DiaBlock::CanMoveLeft(int row, int col, int board[][10]) const
{
	switch(state)
	{
	case 0: case 2: case 1: case 3:
		if(col-1 != 0 && board[row-1][col-1] == 0 && board[row][col-2] == 0 && board[row+1][col-1] == 0 && board[row+2][col-1] == 0)
			return true;
		else
			return false;
	}
	return false;
}
bool DiaBlock::CanMoveRight(int row, int col, int board[][10]) const
{
	switch(state)
	{
	case 0: case 2: case 1: case 3:
		if(col+1 != 9 && board[row-1][col+1] == 0 && board[row][col+2] == 0 && board[row+1][col+1] == 0 && board[row+2][col+1] == 0)
			return true;
		else
			return false;
	}
	return false;
}
bool DiaBlock::CanRotate(int row, int col, int board[][10]) const
{
	return true;
}
bool DiaBlock::EndGame(int board[][10]) const
{
	if(board[2][4] != 0 || board[3][5] != 0 || board[2][6] != 0) return true;
	else return false;
}