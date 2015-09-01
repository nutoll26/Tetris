#ifndef __LBLOCK_H__
#define __LBLOCK_H__

#include "Blocks.h"


/*
	class name : LBlock
	discription : handling class of "L" shape block
*/
class LBlock : public Blocks
{
public:
	LBlock()  // initialize shape
	{
		block[0][1] = 2;	block[1][1] = 2;
		block[2][1] = 2;	block[2][2] = 2;
	}
	virtual void Rotate(); // turn block
	virtual bool CanMoveDown(int row, int col, int board[][10]) const; // Can block move down
	virtual bool CanMoveLeft(int row, int col, int board[][10]) const; // Can block move left
	virtual bool CanMoveRight(int row, int col, int board[][10]) const; // Can block right
	virtual bool CanRotate(int row, int col, int board[][10]) const; // Can block trun
	virtual bool EndGame(int board[][10]) const; // testing continue game
};

#endif