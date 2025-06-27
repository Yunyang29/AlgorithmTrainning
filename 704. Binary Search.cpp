// Date: 14/05/25
// Leetcode: https://leetcode.com/problems/binary-search/
// Keywords: Binary Search, Array
// Idea:
// - Binary search is a classic algorithm for finding an element in a sorted array.


#include "Array.h"

using namespace Array;

int _704_binary_search::main(vector<int>& nums, int target)
{
	int left = 0, right = nums.size() - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2; // ±ÜÃâleft+rightÒç³ö
		if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else if (nums[mid] > target)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}

	return -1;
}