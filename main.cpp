#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <vector>

using namespace std;

int board[10][10];

void initialize_board(int array1[10][10])
{
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			array1[x][y] = occupied;
		}
	}
}
int main()
{
	initialize_board(board);
	print_board(board);

	return 0;
}