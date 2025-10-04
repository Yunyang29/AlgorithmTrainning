// Date: 26/06/25
// Leetcode: https://leetcode.cn/problems/4sum-ii/description/
// Keywords: 4Sum II, Hash Table, Unordered Map
// Idea:
// - Use an unordered_map to store the sums of pairs from the first two arrays.
// - For each pair from the last two arrays, check if the negative sum exists in the map and count occurrences.
// Complexity:
// - Time: O(n^2), where n is the length of each array.
// - Space: O(n^2) for storing sums in the map.


#include "..\Header\HashTable.h" 
int HashTable::_454_4sum_ii::main(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
{
	unordered_map<int, int> umap; // ��Ϊֻ��Ҫͳ�ƺͳ��ֵĴ�����������unordered_map���洢�ͼ�����ִ���

	// ������A�ʹ�B���飬ͳ����������Ԫ��֮�ͣ��ͳ��ֵĴ������ŵ�map��
	for (int a : nums1) {
		for (int b : nums2) {
			umap[a + b]++;
		}
	}

	int count = 0; // ͳ��a+b+c+d = 0 ���ֵĴ���
	// �ٱ�����C�ʹ�D���飬�ҵ���� 0-(c+d) ��map�г��ֹ��Ļ����Ͱ�map��key��Ӧ��valueҲ���ǳ��ִ���ͳ�Ƴ�����
	for (int c : nums3) {
		for (int d : nums4) {
			if (umap.find(0 - (c + d)) != umap.end()) {
				count += umap[0 - (c + d)];
			}
		}
	}
	return count;
}