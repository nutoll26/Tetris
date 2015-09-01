#include "Tetris.h"
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>

/*
	Function name : Tetris
	Discription : create tetris window
*/
Tetris::Tetris() : gameWidth(50), gameHeight(25), score(0)
{
	char name[20];
	std::cout << std::endl << std::setw(29) << "Welcome! Start tetris game!" << std::endl;
	std::cout << std::setw(24) << "Enter user name : "; std::cin >> name;

	pBlock = NULL;
	initscr();
	for(int i=0; i<18; i++)
	{
		memset(board[i], 0 , sizeof(int) * 10);
	}

	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_RED, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	init_pair(8, COLOR_BLUE, COLOR_BLACK);

	init_pair(9, COLOR_YELLOW, COLOR_BLACK);
	init_pair(10, COLOR_GREEN, COLOR_BLACK);

	resize_term(gameHeight, gameWidth);
	border('|', '|', '-', '-', '+', '+', '+', '+');
	wattron(stdscr, COLOR_PAIR(5));
	mvprintw(1, 2, "Welcome to Tetris world!!");
	wattroff(stdscr, COLOR_PAIR(5));
	refresh();

	keypad(stdscr, TRUE);
	nodelay(stdscr,TRUE);
	noecho();              
	cbreak();
	curs_set(0);

	win1 = newwin(20, 22, 2, 2);
	wborder(win1, '|', '|', '-', '-', '+', '+', '+', '+');
	
	wattron(win1, COLOR_PAIR(10));
	for(int i=1; i<19; i++){
		for(int j=1; j<20; j+=2){
			mvwprintw(win1, i, j, "□");
		}
	}
	wattroff(win1, COLOR_PAIR(10));
	wrefresh(win1);

	win2 = newwin(4, 10, 4, 30);
	wborder(win2, '|', '|', '-', '-', '+', '+', '+', '+');
	wattron(win2, COLOR_PAIR(9));
	mvwprintw(win2, 1, 1, "score:");
	printScore();
	wattroff(win2, COLOR_PAIR(9));
	wrefresh(win2);

	win3 = newwin(4, 10, 10, 30);
	wborder(win3, '|', '|', '-', '-', '+', '+', '+', '+');
	wattron(win3, COLOR_PAIR(9));
	mvwprintw(win3, 1, 1, "name:");
	mvwprintw(win3, 2, 1, "%s", name);
	wattroff(win3, COLOR_PAIR(9));
	wrefresh(win3);
}

/*
	Function name : ~Tetris
	Discription : delete tetris window
*/
Tetris::~Tetris()
{
	delwin(win1);
	delwin(win2);
	delwin(win3);
	endwin();
}

/*
	Function name : PlayGame
	Discription : create blocks & play tetris game
*/
bool Tetris::playGame()
{
	srand((unsigned)time(NULL));
	Blocks *bk = NULL;
	seed = rand()%7+1;

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

	pBlock = (int(*)[4][4])bk->GetBlock();

	/* 초기 블록 출력 */
	row=1; col=5; // 보드배열에 저장의 편의을 위해
	printBoard();

	if(endGame(bk))	return false;

	int ch;	ch = getch();
	while(1)
	{
		if(!bk->CanMoveDown(row, col, board)) return true;

		if(ch == 'q'){
			nodelay(stdscr, FALSE);
			printResult();
			getch();
			return false;
		}

		moveBlock(ch, bk);

		/* 블록의 떨어질 곳이 없어서 보드배열에 현재 상태 저장 */
		if(!bk->CanMoveDown(row, col, board)) storeBoard();

		clearLine();
		printScore();
		printBoard();

		ch = getch();
	}
}

/*
	Function name : storeBoard
	Discription : store block at tetris board
*/
void Tetris::storeBoard()
{
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			if((*pBlock)[i][j] != 0)
			{
				if(i == 0){
					if(j == 0){
						board[row-1][col-1] = seed;
					}
					else if(j == 1){
						board[row-1][col] = seed;
					}
					else{
						board[row-1][col+j-1] = seed;
					}
				}
				else if(i == 1){
					if(j == 0){
						board[row][col-1] = seed;
					}
					else if(j == 1){
						board[row][col] = seed;
					}
					else{
						board[row][col+j-1] = seed;
					}
				}
				else{
					if(j == 0){
						board[row+i-1][col-1] = seed;
					}
					else if(j == 1){
						board[row+i-1][col] = seed;
					}
					else{
						board[row+i-1][col+j-1] = seed;
					}
				}
			}
		}
	}
}

/*
	Function name : moveBlcok
	Discription : move & turn block
*/
void Tetris::moveBlock(int ch, Blocks *(&bk))
{
	register const int KEY_SPACE = 32;

	switch(ch)
	{
	case KEY_UP:
		if(bk->CanRotate(row, col, board))
		{
			bk->Rotate();
			pBlock = (int(*)[4][4])bk->GetBlock();
		}
		break;
	case KEY_DOWN:
		row++;
		break;
	case KEY_LEFT:
		if(bk->CanMoveLeft(row, col, board))
			col--;
		break;
	case KEY_RIGHT:
		if(bk->CanMoveRight(row, col, board))
			col++;
		break;
	case KEY_SPACE:
		while(bk->CanMoveDown(row, col, board))
			row++;
		break;
	}
}

/*
	Function name : printBorad
	Discription : Show tetris board, stored block
*/
void Tetris::printBoard() const
{
	/* 기존 보드배열에 저장된 그림 출력 */
	for(int i=0; i<18; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(board[i][j] == 0)
			{
				wattron(win1, COLOR_PAIR(10));
				mvwprintw(win1, i+1, j*2+1, "□");
				wattroff(win1, COLOR_PAIR(10));
			}
			else
			{
				wattron(win1, COLOR_PAIR(board[i][j]));
				mvwprintw(win1, i+1, j*2+1, "■");
				wattroff(win1, COLOR_PAIR(board[i][j]));
			}
		}
	}
	/* 블록이 한번 움직임에 따른 출력 */
	for (int i=0; i<4; i++)
	{
		for (int j=0; j<4; j++)
		{
			if((*pBlock)[i][j] != 0)
			{
				wattron(win1, COLOR_PAIR(seed));
				mvwprintw(win1, i+row, j*2+col*2-1, "■");
				wattroff(win1, COLOR_PAIR(seed));
			}
		}
	}
	wrefresh(win1);
}

/*
	Function name : clearLine
	Discription : delete full row line
*/
void Tetris::clearLine()
{
	int i, j, k;
	int flag;

	i = 17;
	while(i >= 0)
	{
		flag = 1;

		for(j = 0; j<10; j++)
		{
			if(board[i][j] == 0)
			{
				flag = 0;
				break;
			}
		}

		if(flag == 1)
		{
			score += 1;
			for(k=i-1; k>=0; k--)
			{
				for (j = 0; j<10; j++)
				{
					board[k + 1][j] = board[k][j];
				}
			}
			for(j = 0; j<10; j++)
			{
				board[0][j] = 0;
			}
			continue;
		}
		i--;
	}
}

/*
	Function name : printScore
	Discription : Show score
*/
void Tetris::printScore() const
{
	wattron(win2, COLOR_PAIR(9));
	mvwprintw(win2, 2, 1, "%d", score);
	wattroff(win2, COLOR_PAIR(9));

	wrefresh(win2);
}

/*
	Function name : printResult
	Discription : Show game result
*/
void Tetris::printResult() const
{
	mvprintw(22, 10, "score is %d", score);
	mvprintw(23, 10, "Press any key to exit Tetris");
}

/*
	Function name : endGame
	Discription : Test end of game
*/
bool Tetris::endGame(Blocks *(&bk))
{
	for(int j=0; j<10; j++)
	{
		printBoard();
		if(board[0][j] != 0)
		{
			nodelay(stdscr, FALSE);
			printResult();
			getch();
			return true;
		}
	}

	printBoard();
	if(bk->EndGame(board)){
		nodelay(stdscr, FALSE);
		printResult();
		getch();
		return true;
	}
	return false;
}