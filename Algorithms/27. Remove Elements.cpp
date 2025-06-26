// Date: 15/05/25
// LeetCode: https://leetcode.cn/problems/remove-element/
// Keywords: Array, Two Pointers
// Idea:
// - Only move slow pointer when the current element is not equal to the value to be removed.


#include "Array.h"

int Array::_27_remove_element::main(vector<int>& nums, int val)
{
	int slow = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[slow] != val)
		{
			nums[slow++] = nums[i];
		}
	}

	return slow;
}