//============================================================================
// Name        : 8Puzzle.cpp
// Author      : sjean
// Version     : 2016.1.27
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>

using namespace std;

long long int data[362880]; // 9! size
int num_data;
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}}; // up, right, down, left

long long int encode(int b[3][3], int d) // encode the board
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

int** get_board(long long int d)
{
	int result[3][3];

	d = d >> 4;

	for (int i=2; i>=0; i--)
	{
		for (int j=2; j>=0; j--)
		{
			result[i][j] = d % 16;
			d = d >> 4;
		}
	}

	return result;
}

int get_depth(long long int d) // get depth of the board from data
{
	return d % 16;
}

int** clone(int b[3][3]) // clone the board
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

int** move(int b[3][3], int x, int y, int d) // make move and return the result board
{
	int result[3][3];
	int nextX = x + dir[d][0];
	int nextY = y + dir[d][1];

	result = clone(b);

	int temp = result[x][y];
	result[x][y] = result[nextX][nextY];
	result[nextX][nextY] = temp;

	return result;
}

bool is_legal_move(int x, int y, int d) // check whether the move on the direction is legal  or not
{
	int nextX = x + dir[d][0];
	int nextY = y + dir[d][1];

	if (nextX >=0 && nextX <=2 && nextY >=0 && nextY <=2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool has_existed(int b[3][3])
{
	long long int code = encode(b,0) / 16;

	for (int i=0; i<num_data; i++)
	{
		long long int existed_code = data[i] / 16;

		if (existed_code == code)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	int board[3][3] = {{1,2,3},{8,0,4},{7,6,5}}; // initial the goal board
	int depth = 0;
	int visit_pos = 0;
	bool can_move = true;

	memset(data,-1,sizeof(data));
	data[0] = encode(board,depth);
	num_data = 1;

	while (can_move)
	{
		can_move = false;
		board = get_board(data[visit_pos]);
		depth = get_depth(data[visit_pos]);

		for (int i=0; i<4; i++)
		{

		}
	}

	return 0;
}
