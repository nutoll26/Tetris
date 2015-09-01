#include "ZBlock.h"

/*
	제트블록
*/

/*
	Function name : Rotate
	Discription : turn Z block
*/
void ZBlock::Rotate()
{
	for(int i=0; i<4; i++)
		memset(block[i], 0, sizeof(int) * 4);

	switch(state)
	{
	case 0: case 2:
		block[0][0]= 5;	block[0][1] =5; block[1][1] =5; block[1][2]=5;
		state++;
		break;
	case 1: case 3:
		block[0][1]= 5;	block[1][0] =5; block[1][1] =5; block[2][0]=5;
		if(state ==1) state++;
		else if(state ==3) state=0;
		break;
	}
}

/*
	Function name : CanMoveDown
	Discription : test move down Z block
*/
bool ZBlock::CanMoveDown(int row, int col, int board[][10]) const
{
	switch(state)
	{
	case 0: case 2:
		if(row+1 != 17 && board[row+2][col-1] == 0 && board[row+1][col] == 0)
			return true;
		else
			return false;
	case 1: case 3:
		if(row != 17 && board[row][col-1] == 0 && board[row+1][col] == 0 && board[row+1][col+1] == 0)
			return true;
		else
			return false;
	}
	return false;
}

/*
	Function name : CanMoveleft
	Discription : test move left Z block
*/
bool ZBlock::CanMoveLeft(int row, int col, int board[][10]) const
{
	switch(state)
	{
	case 0: case 2:
		if(col-1 != 0 && board[row-1][col-1] == 0 && board[row][col-2] == 0 && board[row+1][col-2] == 0)
			return true;
		else
			return false;
	case 1: case 3:
		if(col-1 != 0 && board[row-1][col-2] == 0 && board[row][col-1] == 0)
			return true;
		else
			return false;
	}
	return false;
}

/*
	Function name : CanMoveRight
	Discription : test move right Z block
*/
bool ZBlock::CanMoveRight(int row, int col, int board[][10]) const
{
	switch(state)
	{
	case 0: case 2:
		if(col != 9 && board[row-1][col+1] == 0 && board[row][col+1] == 0 && board[row+1][col] == 0)
			return true;
		else
			return false;
	case 1: case 3:
		if(col+1 != 9 && board[row-1][col+1] == 0 && board[row][col+2] == 0)
			return true;
		else
			return false;
	}
	return false;
}

/*
	Function name : CanRotate
	Discription : test rotate Z block
*/
bool ZBlock::CanRotate(int row, int col, int board[][10]) const
{
	switch(state)
	{
	case 0: case 2:
		if(col != 9 && board[row-1][col-1] == 0 && board[row][col+1] == 0)
			return true;
		else
			return false;
	case 1: case 3:
		if(row != 17 && col != 0 && board[row][col-1] == 0 && board[row+1][col-1] == 0)
			return true;
		else
			return false;
	}
	return false;
}
bool ZBlock::EndGame(int board[][10]) const
{
	if(board[2][5] != 0 || board[3][4] != 0) return true;
	else return false;
}