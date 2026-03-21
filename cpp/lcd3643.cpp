// https://leetcode.com/problems/flip-square-submatrix-vertically
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k)
  {
		for(int w=0; w<k; w++)
		{
			int c=y+w;
			for(int d=0; d<k/2; d++)
			{
				int r1=x+d;
				int r2=x+k-1-d;
				int tmp = grid[r1][c];
				grid[r1][c] = grid[r2][c];
				grid[r2][c] = tmp;
			}
		}
		return grid;
	}
};