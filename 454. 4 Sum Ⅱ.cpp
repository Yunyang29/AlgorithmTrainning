// Date: 26/06/25
// Leetcode: https://leetcode.cn/problems/4sum-ii/description/
// Keywords: 4Sum II, Hash Table, Unordered Map
// Idea:
// - Use an unordered_map to store the sums of pairs from the first two arrays.
// - For each pair from the last two arrays, check if the negative sum exists in the map and count occurrences.


#include "HashTable.h"
int HashTable::_454_4_sum_Ⅱ::main(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
{
	unordered_map<int, int> umap; // 因为只需要统计和出现的次数，所以用unordered_map来存储和及其出现次数

	// 遍历大A和大B数组，统计两个数组元素之和，和出现的次数，放到map中
	for (int a : nums1) {
		for (int b : nums2) {
			umap[a + b]++;
		}
	}

	int count = 0; // 统计a+b+c+d = 0 出现的次数
	// 再遍历大C和大D数组，找到如果 0-(c+d) 在map中出现过的话，就把map中key对应的value也就是出现次数统计出来。
	for (int c : nums3) {
		for (int d : nums4) {
			if (umap.find(0 - (c + d)) != umap.end()) {
				count += umap[0 - (c + d)];
			}
		}
	}
	return count;
}