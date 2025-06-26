#include <vector>
#include "Array.h"
using namespace std;

vector<int> Array::_997_squares_of_a_sorted_array::main(vector<int>& nums)
{
	if (nums.empty())
		return vector<int>();
	vector<int> res(nums.size(), 0);
	int k = nums.size() - 1;
	for (int i = 0, j = nums.size() - 1; i <= j;) {
		if (nums[i] * nums[i] < nums[j] * nums[j]) {
			res[k--] = nums[j] * nums[j];
			j--;
		}
		else {
			res[k--] = nums[i] * nums[i];
			i++;
		}
	}
	return res;
}