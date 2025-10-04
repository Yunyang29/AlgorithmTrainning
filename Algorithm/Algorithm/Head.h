#pragma once
#include <vector>

using namespace std;

namespace Array
{
	class _15_3sum {
	public:
		vector<vector<int>> main(vector<int>& nums);
	};

	class _18_4sum {
	public:
		vector<vector<int>> main(vector<int>& nums, int target);
	};

	class _27_remove_element {
	public:
		int main(vector<int>& nums, int val);
	};

	class _209_minimum_size_subarray_sum {
	public:
		int main(int s, vector<int>& nums);
	};

	class _239_sliding_window_maximum {
	public:
		vector<int> main(vector<int>& nums, int k);
	};

	class _303_range_sum_query_immutable {
	private:
		vector<int> sums;
	public:
		_303_range_sum_query_immutable() = default;
		_303_range_sum_query_immutable(vector<int>& nums);
		int sumRange(int left, int right);
		void solution_2();
	};

	class _704_binary_search {
	public:
		int main(vector<int>& nums, int target);
	};

	class _997_squares_of_a_sorted_array {
	public:
		vector<int> main(vector<int>& nums);
	};

	class land_purchasing {
	public:
		void main();
	};
}