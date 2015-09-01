#ifndef __ZBLOCK_H__
#define __ZBLOCK_H__

#include "Blocks.h"


/*
	class name : ZBlock
	discription : handling class of "Z" shape block
*/
class ZBlock : public Blocks
{
public:
	ZBlock()
	{
		block[0][1] = 1;	block[1][1] = 1;
		block[1][0] = 1;	block[2][0] = 1;
	}
	virtual void Rotate();
	virtual bool CanMoveDown(int row, int col, int board[][10]) const;
	virtual bool CanMoveLeft(int row, int col, int board[][10]) const;
	virtual bool CanMoveRight(int row, int col, int board[][10]) const;
	virtual bool CanRotate(int row, int col, int board[][10]) const;
	virtual bool EndGame(int board[][10]) const;
};

#endif