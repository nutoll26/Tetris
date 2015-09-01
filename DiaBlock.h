#ifndef __DIABLOCK_H__
#define __DIABLOCK_H__

#include "Blocks.h"

/*
	class name : DiaBlock
	discription : handling class of "Dia" shape block
*/
class DiaBlock : public Blocks
{
public:
	DiaBlock()
	{
		block[0][1] = 1;	block[1][0] = 1;
		block[1][2] = 1;	block[2][1] = 1;
	}
	virtual void Rotate();
	virtual bool CanMoveDown(int row, int col, int board[][10]) const;
	virtual bool CanMoveLeft(int row, int col, int board[][10]) const;
	virtual bool CanMoveRight(int row, int col, int board[][10]) const;
	virtual bool CanRotate(int row, int col, int board[][10]) const;
	virtual bool EndGame(int board[][10]) const;
};

#endif