#ifndef __TETRIS_H__
#define __TETRIS_H__

#include "curses.h"

#include "IBlock.h"
#include "JBlock.h"
#include "LBlock.h"
#include "OBlock.h"
#include "SBlock.h"
#include "TBlock.h"
#include "ZBlock.h"
#include "DiaBlock.h"

class Tetris
{
private:
	WINDOW *win1, *win2, *win3; // �͹̳�������, ���ھ�������, ����������
	int row, col;				// ����ȭ�� �� ��ǥ
	int gameWidth, gameHeight;	// ���� â ũ��
	int board[18][10];			// �͹̳��� ���¸� ������ ���
	int score;					// ����
	int (*pBlock)[4][4];		// receive block board
	int seed;
public:
	Tetris(); // Create game window
	~Tetris(); // Delete game window

	bool playGame(); // start game
	void moveBlock(int ch, Blocks *(&bk)); // move block

	void printBoard() const;
	void storeBoard();
	void clearLine();
	void printScore() const;
	void printResult() const;
	bool endGame(Blocks *(&bk));
};

#endif