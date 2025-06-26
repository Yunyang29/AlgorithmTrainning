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
		int border = 1;
		int start = 0;
		int val = 1;
		int x, y = start;
		while (loop--) {
			x = start;
			y = start;
			for (x; x < n - border; x++) {
				res[y][x] = val++;
			}

			for (y; y < n - border; y++) {
				res[y][x] = val++;
			}

			for (x; x > start; x--) {
				res[y][x] = val++;
			}

			for (y; y > start; y--) {
				res[y][x] = val++;
			}

			start++;
			border++;
		}

		if (n % 2 > 0) { // count != n * n
			int mid = n / 2;
			res[mid][mid] = val;
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