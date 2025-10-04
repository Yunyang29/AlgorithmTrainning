// Date: 25/06/26
// Leetcode: https://leetcode.cn/problems/intersection-of-two-arrays/
// Keywords: Intersection of Two Arrays, Hash Table, Set
// Idea:
// - Use an unordered_set to store elements of the first array by time complexity O(n).
// - To do so, when iterate through the second array, the total time complexity is O(n + m), where n and m are the sizes of the two arrays.
// - Finally, convert the set to a vector and return it by time complexity O(k).
// Complexity:
// - Time: O(n + m + k) -> O(n + m)
// - Space: O(n), where n is the size of nums1.

#include "..\Header\HashTable.h" 
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