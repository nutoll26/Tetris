#include "TBlock.h"

/*
	Æ¼ºí·Ï
*/
/*
	Function name : Rotate
	Discription : turn T block
*/
void TBlock::Rotate()
{
	for(int i=0; i<4; i++)
		memset(block[i], 0, sizeof(int) * 4);

	switch(state)
	{
	case 0:
		block[0][1]= 6;	block[1][0] =6; block[1][1] =6; block[2][1]=6;
		state++;
		break;
	case 1:
		block[1][0]= 6;	block[1][1] =6; block[1][2] =6; block[2][1]=6;
		state++;
		break;
	case 2:
		block[0][1]= 6;	block[1][1] =6; block[1][2] =6; block[2][1]=6;
		state++;
		break;
	case 3:
		block[0][1]= 6;	block[1][0] =6; block[1][1] =6; block[1][2]=6;
		state = 0;
		break;
	}
}

/*
	Function name : CanMoveDown
	Discription : test move down T block
*/
bool TBlock::CanMoveDown(int row, int col, int board[][10]) const
{
	switch(state)
	{
	case 0:
		if(row != 17 && board[row+1][col-1] == 0 && board[row+1][col] == 0 && board[row+1][col+1] == 0)
			return true;
		else
			return false;
	case 1:
		if(row +1 != 17 && board[row+1][col-1] == 0 && board[row+2][col] == 0)
			return true;
		else
			return false;
	case 2:
		if(row+1 != 17 && board[row+1][col-1] == 0 && board[row+2][col] == 0 && board[row+1][col+1] == 0)
			return true;
		else
			return false;
	case 3:
		if(row+1 != 17 && board[row+2][col] == 0 && board[row+1][col+1] == 0)
			return true;
		else
			return false;
	}
	return false;
}

/*
	Function name : CanMoveLeft
	Discription : test move left T block
*/
bool TBlock::CanMoveLeft(int row, int col, int board[][10]) const
{
	switch(state)
	{
	case 0:
		if(col-1 != 0 && board[row-1][col-1] == 0 && board[row][col-2] == 0)
			return true;
		else
			return false;
	case 1:
		if(col-1 != 0 && board[row-1][col-1] == 0 && board[row][col-2] == 0 && board[row+1][col-1] == 0)
			return true;
		else
			return false;
	case 2:
		if(col-1 != 0 && board[row][col-2] == 0 && board[row+1][col-1] == 0)
			return true;
		else
			return false;
	case 3:
		if(col != 0 && board[row-1][col-1] == 0 && board[row][col-1] == 0 && board[row+1][col-1] == 0)
			return true;
		else
			return false;
	}
	return false;
}
/*
	Function name : CanMoveright
	Discription : test move right T block
*/
bool TBlock::CanMoveRight(int row, int col, int board[][10]) const
{
	switch(state)
	{
	case 0:
		if(col+1 != 9 && board[row-1][col+1] == 0 && board[row][col+2] == 0)
			return true;
		else
			return false;
	case 1:
		if(col != 9 && board[row-1][col+1] == 0 && board[row][col+1] == 0 && board[row+1][col+1] == 0)
			return true;
		else
			return false;
	case 2:
		if(col+1 != 9 && board[row][col+2] == 0 && board[row+1][col+1] == 0)
			return true;
		else
			return false;
	case 3:
		if(col+1 != 9 && board[row-1][col+1] == 0 && board[row][col+2] == 0 && board[row+1][col+1] == 0)
			return true;
		else
			return false;
	}
	return false;
}

/*
	Function name : CanRotate
	Discription : test rotate T block
*/
bool TBlock::CanRotate(int row, int col, int board[][10]) const
{
	switch(state)
	{
	case 0:
		if(row != 17 && board[row+1][col] == 0)
			return true;
		else
			return false;
	case 1:
		if(col != 9 && board[row][col+1] == 0)
			return true;
		else
			return false;
	case 2:
			return true;
	case 3:
		if(col != 0 && board[row][col-1] == 0)
			return true;
		else
			return false;
	}
	return false;
}
bool TBlock::EndGame(int board[][10]) const
{
	if(board[2][4] != 0 || board[2][5] != 0 || board[2][6] != 0) return true;
	else return false;
}