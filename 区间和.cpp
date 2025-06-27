// Date: 20/05/25
// Leetcode: https://leetcode.cn/problems/range-sum-query-immutable/description/
// Keywords: Prefix Sum, Range Sum Query, Array
// Idea:
// - Use a prefix sum array to efficiently calculate the sum of elements in a given range.

#include "Array.h"
#include <iostream>
#include <vector>
using namespace std;
using namespace Array;

_303_range_sum_query_immutable::_303_range_sum_query_immutable(vector<int>& nums) {
	int n = nums.size();
	sums.resize(n + 1);
	for (int i = 0; i < n; i++) {
		sums[i + 1] = sums[i] + nums[i];
	}
}

int _303_range_sum_query_immutable::sumRange(int left, int right) {
	return sums[right + 1] - sums[left];
}

void _303_range_sum_query_immutable::solution_2()
{
	int n;
	cin >> n;

	int sum = 0;
	vector<int> nums(n, 0);
	vector<int> sums(n, 0);
	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;
		nums[i] = val;

		sum += val;
		sums[i] = sum;
	}


	int a, b = 0;

	while (cin >> a >> b) {
		if (a == 0)
			cout << sums[b];
		else
			cout << sums[b] - sums[a - 1];
	}
}