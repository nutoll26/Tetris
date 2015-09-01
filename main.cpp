/*
	국민대학교 컴퓨터 공학부
	20113291 신우철
	테트리스 #03
*/
#include "Tetris.h"
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
	Tetris game;

	/* 실행 파일이 없을 경우 */
	if(argc<2)
	{
		while(1)
		{
			if(game.playGame())	continue;
			else	break;
		}
	}

	/* 실행 파일이 있는 경우 */
	else
	{
		int KEY_SPACE = 32;

		ifstream inStream;
		inStream.open(argv[1]); // open file

		Blocks *bk = NULL;

		int ch; char name[10]; int seed;
		inStream >> name >> seed;

		seed %= 7;
		switch(seed)
		{
		case 1:	bk = new OBlock; break;
		case 2:	bk = new LBlock; break;
		case 3:	bk = new JBlock; break;
		case 4:	bk = new SBlock; break;
		case 5:	bk = new ZBlock; break;
		case 6:	bk = new TBlock; break;
		case 7:	bk = new IBlock; break;
		case 8: bk = new DiaBlock; break;
		}
		
		while(inStream.eof())
		{
			inStream >> ch;
			if(ch == 'q')	break;

			/* 게임 결과 실행 */
			switch(ch)
			{
			case 't':
				game.moveBlock(KEY_UP, bk);
				break;
			case 'g':
				game.moveBlock(KEY_DOWN, bk);
				break;
			case 'l':
				game.moveBlock(KEY_LEFT, bk);
				break;
			case 'r':
				game.moveBlock(KEY_RIGHT, bk);
				break;
			case 'd':
				game.moveBlock(KEY_SPACE, bk);
				break;
			}
			if(ch == 'd')
			{
				seed %= 7;
				switch(seed)
				{
				case 1:	bk = new OBlock; break;
				case 2:	bk = new LBlock; break;
				case 3:	bk = new JBlock; break;
				case 4:	bk = new SBlock; break;
				case 5:	bk = new ZBlock; break;
				case 6:	bk = new TBlock; break;
				case 7:	bk = new IBlock; break;
				case 8: bk = new DiaBlock; break;
				}
			}
		}
	}
	/* 결과 출력*/
	game.printBoard();
	game.printResult();

	return 0;
}