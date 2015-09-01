#include "JBlock.h"

/*
	제이블록
*/
/*
	Function name : Rotate
	Discription : turn Z block
*/
void JBlock::Rotate()
{
	for(int i=0; i<4; i++)
		memset(block[i], 0, sizeof(int) * 4);

	switch(state)
	{
	case 0:
		block[1][0]= 3;	block[1][1] =3; block[1][2] =3; block[2][2]=3;
		state++;
		break;
	case 1:
		block[0][1]= 3;	block[0][2] =3; block[1][1] =3; block[2][1]=3;
		state++;
		break;
	case 2:
		block[0][0]= 3;	block[1][0] =3; block[1][1] =3; block[1][2]=3;
		state++;
		break;
	case 3:
		block[0][1] =3; block[1][1] = 3; block[2][1] =3; block[2][0]=3;
		state = 0;
		break;
	}
}
/*
	Function name : CanMoveDown
	Discription : test move down J block
*/
bool JBlock::CanMoveDown(int row, int col, int board[][10]) const
{
	switch(state)
	{
	case 0:
		if(row+1 != 17 && board[row+2][col-1] == 0 && board[row+2][col] == 0)
			return true;
		else
			return false;
	case 1:
		if(row+1 != 17 && board[row+1][col-1] == 0 && board[row+1][col] == 0 && board[row+2][col+1] == 0)
			return true;
		else
			return false;
	case 2:
		if(row+1 != 17 && board[row+2][col] == 0 && board[row][col+1] == 0)
			return true;
		else
			return false;
	case 3:
		if(row != 17 && board[row+1][col-1] == 0 && board[row+1][col] == 0 && board[row+1][col+1] == 0)
			return true;
		else
			return false;
	}
	return false;
}
/*
	Function name : CanMoveLeft
	Discription : test move left J block
*/
bool JBlock::CanMoveLeft(int row, int col, int board[][10]) const
{
	switch(state)
	{
	case 0:
		if(col-1 != 0 && board[row-1][col-1] == 0 && board[row][col-1] == 0 && board[row+1][col-2] == 0)
			return true;
		else
			return false;
	case 1:
		if(col-1 != 0 && board[row][col-2] == 0 && board[row-1][col] == 0)
			return true;
		else
			return false;
	case 2:
		if(col != 0 && board[row-1][col-1] == 0 && board[row][col-1] == 0 && board[row+1][col-1] == 0)
			return true;
		else
			return false;
	case 3:
		if(col-1 != 0 && board[row-1][col-2] == 0 && board[row][col-2] == 0)
			return true;
		else
			return false;
	}
	return false;
}
/*
	Function name : CanMoveRight
	Discription : test move right J block
*/
bool JBlock::CanMoveRight(int row, int col, int board[][10]) const
{
	switch(state)
	{
	case 0:
		if(col != 9 && board[row-1][col+1] == 0 && board[row][col+1] == 0 && board[row+1][col+1] == 0)
			return true;
		else
			return false;
	case 1:
		if(col+1 != 9 && board[row][col+2] == 0 && board[row+1][col+2] == 0)
			return true;
		else
			return false;
	case 2:
		if(col+1 != 9 && board[row-1][col+2] == 0 && board[row][col+1] == 0 && board[row+1][col+1] == 0)
			return true;
		else
			return false;
	case 3:
		if(col+1 != 9 && board[row-1][col] == 0 && board[row][col+2] == 0)
			return true;
		else
			return false;
	}
	return false;
}
/*
	Function name : CanRotate
	Discription : test rotate J block
*/
bool JBlock::CanRotate(int row, int col, int board[][10]) const
{
	switch(state)
	{
	case 0:
		if(col !=9 && board[row][col+1] == 0 && board[row+1][col+1] == 0)
			return true;
		else
			return false;
	case 1:
		if(row+1 != 17 && board[row+1][col] == 0)
			return true;
		else
			return false;
	case 2:
		if(col != 0 && board[row][col-1] == 0 && board[row][col+1] == 0)
			return true;
		else
			return false;
	case 3:
		if(row != 17 && board[row+1][col-1] == 0 && board[row+1][col] == 0)
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
bool JBlock::EndGame(int board[][10]) const
{
	if(board[3][5] != 0 || board[3][4] != 0) return true;
	else return false;
}