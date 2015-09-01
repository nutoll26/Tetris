#ifndef __OBLOCK_H__
#define __OBLOCK_H__

#include "Blocks.h"

/*
	class name : OBlock
	discription : handling class of "O" shape block
*/
class OBlock : public Blocks
{
public:
	OBlock() // initialize shape
	{
		block[0][0] = 1;	block[0][1] = 1;
		block[1][0] = 1;	block[1][1] = 1;
	}
	virtual void Rotate(); // turn block
	virtual bool CanMoveDown(int row, int col, int board[][10]) const; // Can block move down
	virtual bool CanMoveLeft(int row, int col, int board[][10]) const; // Can blcok move left
	virtual bool CanMoveRight(int row, int col, int board[][10]) const; // Can block move right
	virtual bool CanRotate(int row, int col, int board[][10]) const; // Can block trun
	virtual bool EndGame(int board[][10]) const; // testing continue game
};

#endif