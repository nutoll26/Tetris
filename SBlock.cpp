#include "SBlock.h"

/*
	에스블록
*/
/*
	Function name : Rotate
	Discription : turn S block
*/
void SBlock::Rotate()
{
	for(int i=0; i<4; i++)
		memset(block[i], 0, sizeof(int) * 4);

	switch(state)
	{
	case 0: case 2:
		block[0][1]= 4;	block[0][2] =4; block[1][0] =4; block[1][1]=4;
		state++;
		break;
	case 1: case 3:
		block[0][1]= 4;	block[1][1] =4; block[1][2] =4; block[2][2]=4;
		if(state ==1) state++;
		else if(state == 3) state =0;
		break;
	}
}

/*
	Function name : CanMoveDown
	Discription : test move down S block
*/
bool SBlock::CanMoveDown(int row, int col, int board[][10]) const
{
	switch(state)
	{
	case 0: case 2:
		if(row+1 != 17 && board[row+1][col] == 0 && board[row+2][col+1] == 0)
			return true;
		else
			return false;
	case 1: case 3:
		if(row != 17 && board[row+1][col-1] == 0 && board[row+1][col] == 0 && board[row][col+1] == 0)
			return true;
		else
			return false;
	}
	return false;
}
/*
	Function name : CanMoveLeft
	Discription : test move left S block
*/
bool SBlock::CanMoveLeft(int row, int col, int board[][10]) const
{
	switch(state)
	{
	case 0: case 2:
		if(col != 0 && board[row-1][col-1] == 0 && board[row][col-1] == 0 && board[row+1][col] == 0)
			return true;
		else
			return false;
	case 1: case 3:
		if(col-1 != 0 && board[row][col-2] == 0 && board[row-1][col-1] == 0)
			return true;
		else
			return false;
	}
	return false;
}
/*
	Function name : CanMoveRight
	Discription : test move right S block
*/
bool SBlock::CanMoveRight(int row, int col, int board[][10]) const
{
	switch(state)
	{
	case 0: case 2:
		if(col+1 != 9 && board[row-1][col+1] == 0 && board[row][col+2] == 0 && board[row+1][col+2] == 0)
			return true;
		else
			return false;
	case 1: case 3:
		if(col+1 != 9 && board[row-1][col+2] == 0 && board[row][col+1] == 0)
			return true;
		else
			return false;
	}
	return false;
}
/*
	Function name : CanRotate
	Discription : test rotate S block
*/
bool SBlock::CanRotate(int row, int col, int board[][10]) const
{
	switch(state)
	{
	case 0: case 2:
		if(col != 0 && board[row][col-1] == 0)
			return true;
		else
			return false;
	case 1: case 3:
		if(row != 17 && board[row][col+1] == 0 && board[row+1][col+1] == 0)
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
bool SBlock::EndGame(int board[][10]) const
{
	if(board[2][4] != 0 || board[3][5] != 0) return true;
	else return false;
}