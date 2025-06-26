// Date: 19/05/25
// Leetcode: https://leetcode.cn/problems/spiral-matrix-ii/description/
// Keywords: Spiral Matrix, 2D Array, Matrix Filling
// Idea:
// - Use a 2D vector to represent the matrix.
// - Process n/2 layers of the matrix, filling in numbers in a clockwise spiral order. If n is odd, handle the center element separately in the end.
// - Each processing requires tracking the starting position and an offset.
// - The starting position is the top-left corner of the current layer, and the offset increases by 1 after each layer is processed.

#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> main(int n)
	{
		vector<vector<int>> res(n, vector<int>(n, 0));
		int startX, startY = 0;
		int loop = n / 2;
		int offset = 1;
		int count = 1;
		int i, j;

		while (loop--)
		{
			i = startX;
			j = startY;

			for (j; j < n - offset; j++)
			{
				res[i][j] = count++;
			}

			for (i; i < n - offset; i++)
			{
				res[i][j] = count++;
			}

			for (j; j > startY; j--)
			{
				res[i][j] = count++;
			}

			for (i; i > startX; i--)
			{
				res[i][j] = count++;
			}

			startX++;
			startY++;
			offset += 1;
		}

		if (n % 2 == 1) {
			int mid = n / 2;
			res[mid][mid] = count;
		}
		return res;
	}

	void test()
	{
		int n = 3; // Example size of the matrix
		vector<vector<int>> res = main(n);
		for (const auto& row : res) {
			for (int val : row) {
				printf("%d ", val);
			}
			printf("\n");
		}
	}
};