// Date: 17/05/25
// Leetcode: https://leetcode.cn/problems/minimum-size-subarray-sum/
// Keywords: Minimum Size Subarray Sum, Sliding Window
// Idea:
// - A endIndex to move through the array.
// - While the current sum is greater than or equal to the target, try to shrink the window by moving the startIndex forward until the sum is less than the target.
// - Keep track of the minimum length of the subarray that meets the condition.
// - If no such subarray exists, return 0.

#include "..\Header\Array.h" 
#include <deque>

int Array::_209_minimum_size_subarray_sum::main(int s, vector<int>& nums)
{
	if (nums.size() <= 0)
		return 0;

	int curSum = 0;
	int res = INT_MAX;
	int startIndex = 0;
	for (int endIndex = 0; endIndex < nums.size(); endIndex++)
	{
		curSum += nums[endIndex];
		while (curSum >= s) // 需要while因为可能有多个连续的子数组满足条件
		{
			int newLen = endIndex - startIndex + 1;
			if (newLen < res)
			{
				res = newLen;
			}
			curSum -= nums[startIndex];
			startIndex++;
		}
	}
	return res == INT32_MAX ? 0 : res;
}