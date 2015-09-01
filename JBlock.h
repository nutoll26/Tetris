#ifndef __JBLOCK_H__
#define __JBLOCK_H__

#include "Blocks.h"

/*
	class name : JBlock
	discription : handling class of "J" shape block
*/
class JBlock : public Blocks
{
public:
	JBlock()
	{
		block[0][1] = 1;	block[1][1] = 1;
		block[2][1] = 1;	block[2][0] = 1;
	}
	virtual void Rotate();
	virtual bool CanMoveDown(int row, int col, int board[][10]) const;
	virtual bool CanMoveLeft(int row, int col, int board[][10]) const;
	virtual bool CanMoveRight(int row, int col, int board[][10]) const;
	virtual bool CanRotate(int row, int col, int board[][10]) const;
	virtual bool EndGame(int board[][10]) const;
};

#endif