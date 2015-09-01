#ifndef __SBLOCK_H__
#define __SBLOCK_H__

#include "Blocks.h"

/*
	class name : SBlock
	discription : handling class of "S" shape block
*/
class SBlock : public Blocks
{
public:
	SBlock()
	{
		block[0][1] = 1;	block[1][1] = 1;
		block[1][2] = 1;	block[2][2] = 1;
	}
	virtual void Rotate();
	virtual bool CanMoveDown(int row, int col, int board[][10]) const;
	virtual bool CanMoveLeft(int row, int col, int board[][10]) const;
	virtual bool CanMoveRight(int row, int col, int board[][10]) const;
	virtual bool CanRotate(int row, int col, int board[][10]) const;
	virtual bool EndGame(int board[][10]) const;
};

#endif