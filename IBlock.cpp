#include "IBlock.h"

/*
	아이블록
*/
/*
	Function name : Rotate
	Discription : turn I block
*/
void IBlock::Rotate()
{
	for(int i=0; i<4; i++)
		memset(block[i], 0, sizeof(int) * 4);

	switch(state)
	{
	case 0: case 2:
		block[1][0]= 7;	block[1][1] =7; block[1][2] =7; block[1][3]=7;
		state++;
		break;
	case 1: case 3:
		block[0][1]= 7;	block[1][1] =7; block[2][1] =7; block[3][1]=7;
		if(state==1) state++;
		else if(state==3) state=0;
		break;
	}
	return;
}
/*
	Function name : CanMoveDown
	Discription : test move down I block
*/
bool IBlock::CanMoveDown(int row, int col, int board[][10]) const
{
	switch(state)
	{
	case 0: case 2:
		if(row+2 != 17 && board[row+3][col] == 0)
			return true;
		else
			return false;
	case 1: case 3:
		if(row != 17 && board[row+1][col-1] == 0 && board[row+1][col] == 0 && board[row+1][col+1] == 0 && board[row+1][col+2] == 0)
			return true;
		else
			return false;
	}
	return false;
}
/*
	Function name : CanMoveleft
	Discription : test move left I block
*/
bool IBlock::CanMoveLeft(int row, int col, int board[][10]) const
{
	switch(state)
	{
	case 0: case 2:
		if(col != 0 && board[row-1][col-1] == 0 && board[row][col-1] == 0 && board[row+1][col-1] == 0 && board[row+2][col-1] == 0)
			return true;
		else
			return false;
	case 1: case 3:
		if(col-1 != 0 && board[row][col-2] == 0)
			return true;
		else
			return false;
	}
	return false;
}
/*
	Function name : CanMoveRight
	Discription : test move right I block
*/
bool IBlock::CanMoveRight(int row, int col, int board[][10]) const
{
	switch(state)
	{
	case 0: case 2:
		if(col != 9 && board[row-1][col+1] == 0 && board[row][col+1] == 0 && board[row+1][col+1] == 0 && board[row+2][col+1] == 0)
			return true;
		else
			return false;
	case 1: case 3:
		if(col+2 != 9 && board[row][col+3] == 0)
			return true;
		else
			return false;
	}
	return false;
}
/*
	Function name : CanMoveRotate
	Discription : test move rotate I block
*/
bool IBlock::CanRotate(int row, int col, int board[][10]) const
{
	switch(state)
	{
	case 0: case 2:
		if(col != 0 && col < 8 && board[row][col-1] == 0 && board[row][col+1] == 0 && board[row][col+2] == 0)
			return true;
		else
			return false;
	case 1: case 3:
		if(row < 16 && board[row-1][col] == 0 && board[row+1][col] ==0 && board[row+2][col] == 0)
			return true;
		else
			return false;
	}
	return false;
}
/*
	Function name : EndGame
	Discription : test end of game
*/
bool IBlock::EndGame(int board[][10]) const
{
	if(board[4][5] != 0) return true;
	else return false;
}