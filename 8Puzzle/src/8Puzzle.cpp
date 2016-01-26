//============================================================================
// Name        : 8Puzzle.cpp
// Author      : sjean
// Version     : 2016.1.15
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>

using namespace std;

int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}}; // up, right, down, left

long long int encode(int b[3][3], int d)
{
	long long result = 0;

	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			result = result << 4 + b[j][i];
		}
	}

	result += d;

	return result;
}

int** clone(int b[3][3])
{
	int result[3][3];

	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			result[i][j] = b[i][j];
		}
	}

	return result;
}

int** move(int b[3][3], int x, int y, int d)
{
	int result[3][3];
	int newX = x + dir[d][0];
	int newY = y + dir[d][1];

	result = clone(b);

	int temp = result[x][y];
	result[x][y] = result[newX][newY];
	result[newX][newY] = temp;

	return result;
}

bool can_move(int b[3][3], int x, int y, int d)
{
	int newX = x + dir[d][0];
	int newY = y + dir[d][1];

	if (newX >=0 && newX <=2 && newY >=0 && newY <=2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	long long int data[362880]; // 9! size
	int num_data = 0;
	int board[3][3] = {{1,2,3},{8,0,4},{7,6,5}}; // initial the goal board
	int depth = 0;
	bool can_move = true;

	memset(data,-1,sizeof(data));
	data[0] = encode(board,depth);
	num_data++;

	while (can_move)
	{
		can_move = false;


	}

	return 0;
}
