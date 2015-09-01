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
	WINDOW *win1, *win2, *win3; // 터미널윈도우, 스코어윈도우, 네임윈도우
	int row, col;				// 게임화면 내 좌표
	int gameWidth, gameHeight;	// 게임 창 크기
	int board[18][10];			// 터미널의 상태를 저장할 행렬
	int score;					// 점수
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