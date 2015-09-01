#ifndef __TBLOCK_H__
#define __TBLOCK_H__

#include "Blocks.h"

/*
	class name : TBlock
	discription : handling class of "T" shape block
*/
class TBlock : public Blocks
{
public:
	TBlock()
	{
		block[0][1] = 1;	block[1][0] = 1;
		block[1][2] = 1;	block[1][1] = 1;
	}
	virtual void Rotate();
	virtual bool CanMoveDown(int row, int col, int board[][10]) const;
	virtual bool CanMoveLeft(int row, int col, int board[][10]) const;
	virtual bool CanMoveRight(int row, int col, int board[][10]) const;
	virtual bool CanRotate(int row, int col, int board[][10]) const;
	virtual bool EndGame(int board[][10]) const;
};

#endif