// Date: 26/06/25
// Leetcode: https://leetcode.cn/problems/two-sum/description/
// Keywords: Two Sum, Hash Table, Unordered Map
// Idea:
// - Use an unordered_map to store the numbers and their indices.

#include "HashTable.h"

vector<int> HashTable::_1_two_sum::main(vector<int>& nums, int target)
{
	unordered_map<int, int> map; // 存储数字和其索引
	for (size_t i = 0; i < nums.size(); i++)
	{
		auto iter = map.find(target - nums[i]);
		if (iter != map.end())
		{
			return vector<int>{iter->second, static_cast<int>(i)};
		}
		map.insert(pair<int, int>(nums[i], i));
	}
	return {};
}