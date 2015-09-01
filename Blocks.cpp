#include "Blocks.h"

Blocks::Blocks() : state(0)	// '0'은 최초 출력 상태
{
	for(int i=0; i<4; i++)
		memset(block[i], 0, sizeof(int) * 4);
}
int* Blocks::GetBlock() const
{
	int *arr = (int*)block;
	return arr;
}