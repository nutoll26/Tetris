#ifndef __BLOCK_H__
#define __BLOCK_H__

#include <cstring>
#include <iostream>

/*
	class name : Blocks
	discript : base class of block's shape
*/
class Blocks
{
protected:
	int state; // 블록의 회전 상태
	int block[4][4]; // block board
public:
	Blocks();	// '0'은 최초 출력 상태
	int* GetBlock() const; // return block
	virtual void Rotate() = 0; // turn block
	virtual bool CanMoveDown(int row, int col, int board[][10]) const = 0;
	virtual bool CanMoveLeft(int row, int col, int board[][10]) const = 0;
	virtual bool CanMoveRight(int row, int col, int board[][10]) const = 0;
	virtual bool CanRotate(int row, int col, int board[][10]) const = 0;
	virtual bool EndGame(int board[][10]) const = 0;
};

#endif