#ifndef __IBLOCK_H__
#define __IBLOCK_H__

#include "Blocks.h"

/*
	class name : IBlock
	discription : handling class of "I" shape block
*/
class IBlock : public Blocks
{
public:
	IBlock()
	{
		block[0][1] = 1;	block[1][1] = 1;
		block[2][1] = 1;	block[3][1] = 1;
	}
	virtual void Rotate();
	virtual bool CanMoveDown(int row, int col, int board[][10]) const;
	virtual bool CanMoveLeft(int row, int col, int board[][10]) const;
	virtual bool CanMoveRight(int row, int col, int board[][10]) const;
	virtual bool CanRotate(int row, int col, int board[][10]) const;
	virtual bool EndGame(int board[][10]) const;
};

#endif