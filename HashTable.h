#pragma once

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

namespace HashTable
{
	class _1_two_sum {
	public:
		vector<int> main(vector<int>& nums, int target);
	};

	class _202_happy_number {
	public:
		bool main(int n);
	};

	class _242_valid_anagram {
	public:
		bool main(string s, string t);
	};

	class _349_intersection_of_two_arrays {
	public:
		vector<int> main(vector<int>& nums1, vector<int>& nums2);
	};

	class _454_4_sum_ii {
	public:
		int main(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4);
	};
}
