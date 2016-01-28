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

long long int data[362]; // 9! size
int num_data;
int dir[4][2] = {{0,-1},{1,0},{0,1},{-1,0}}; // up, right, down, left

long long int encode(int b[3][3], int d) // encode the board
{
	long long int result = 0;

	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			result = (result << 4) + b[i][j];
		}
	}

	result = (result << 4) + d;

	return result;
}

void get_board(long long int d, int result[3][3])
{
	d = d >> 4;

	for (int i=2; i>=0; i--)
	{
		for (int j=2; j>=0; j--)
		{
			result[i][j] = d % 16;
			d = d >> 4;
		}
	}
}

int get_depth(long long int d) // get depth of the board from data
{
	return d % 16;
}

void clone(int b[3][3], int result[3][3]) // clone the board
{
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			result[i][j] = b[i][j];
		}
	}
}

void make_move(int b[3][3], int x, int y, int d, int result[3][3]) // make move and return the result board
{
	int nextX = x + dir[d][0];
	int nextY = y + dir[d][1];

	clone(b, result);

	int temp = result[y][x];
	result[y][x] = result[nextY][nextX];
	result[nextY][nextX] = temp;
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
	long long int code = encode(b,0) >> 4;

	for (int i=0; i<num_data; i++)
	{
		long long int existed_code = data[i] >> 4;

		if (existed_code == code)
		{
			return true;
		}
	}

	return false;
}

int get_blank_x(int b[3][3])
{
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			if (b[i][j] == 0)
			{
				return j;
			}
		}
	}

	return -1;
}

int get_blank_y(int b[3][3])
{
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			if (b[i][j] == 0)
			{
				return i;
			}
		}
	}

	return -1;
}

int main()
{
	int board[3][3] = {{1,2,3},{8,0,4},{7,6,5}}; // initial the goal board
	int depth = 0;
	int visit_pos = 0;

	memset(data,-1,sizeof(data));
	data[0] = encode(board,depth);
	num_data = 1;

	while (visit_pos <= num_data-1) // has further move
	{
		get_board(data[visit_pos], board);
		depth = get_depth(data[visit_pos]);
		int x = get_blank_x(board);
		int y = get_blank_y(board);

		for (int i=0; i<4; i++) // consider 4 direction moves
		{
			if (is_legal_move(x,y,i))
			{
				int new_board[3][3];
				make_move(board,x,y,i,new_board);
				if (!has_existed(new_board))
				{
					data[num_data] = encode(new_board,depth+1);
					num_data++;
					cout << "num_data = " << num_data << endl;
				}
			}
		}

		visit_pos++; // visit next board
		cout << "visit_pos = " << visit_pos << endl;
	}

	cout << "num_data = " << num_data;

	return 0;
}
