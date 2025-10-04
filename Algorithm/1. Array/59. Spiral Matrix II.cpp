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
		int loop = n / 2;
		int starter = 0;
		int count = 1;
		while (loop--) {
			int row = starter;
			int col = starter;
			for (col; col < n - starter - 1; col++) {
				res[row][col] = count++;
			}

			for (row; row < n - starter - 1; row++) {
				res[row][col] = count++;
			}

			for (col; col > starter; col--) {
				res[row][col] = count++;
			}

			for (row; row > starter; row--) {
				res[row][col] = count++;
			}

			starter++;
		}

		if (n % 2 != 0) {
			int mid = n / 2;
			res[mid][mid] = n * n;
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
