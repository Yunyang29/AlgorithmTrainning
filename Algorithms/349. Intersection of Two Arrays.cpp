// Date: 25/06/26
// Leetcode: https://leetcode.cn/problems/intersection-of-two-arrays/
// Keywords: Intersection of Two Arrays, Hash Table, Set
// Idea:
// - Use a hash set to store the elements of the first array.
// - Iterate through the second array and check if each element exists in the hash set.

#include "HashTable.h"
#include <unordered_set>

vector<int> HashTable::_349_intersection_of_two_arrays::main(vector<int>& nums1, vector<int>& nums2) {
	unordered_set<int> result_set;
	unordered_set<int> nums1_set(nums1.begin(), nums1.end());
	for (int num : nums2) {
		if (nums1_set.find(num) != nums1_set.end()) { // 当find()返回的迭代器等于end()时，说明没有找到这个元素
			result_set.insert(num);
		}
	}
	return vector<int>(result_set.begin(), result_set.end()); // 将set转换为vector并返回
}