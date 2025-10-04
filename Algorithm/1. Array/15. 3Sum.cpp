#include "..\Header\Array.h" 
#include <algorithm>

vector<vector<int>> Array::_15_3sum::main(vector<int>& nums)
{
	vector<vector<int>> res;
	sort(nums.begin(), nums.end()); // O(nlogn)

	for (int i = 0; i < nums.size() - 2; i++)
	{
		if (nums[i] > 0)
			break;
		if (i > 0 && nums[i] == nums[i - 1])
			continue;

		int left = i + 1, right = nums.size() - 1;
		while (left < right)
		{
			if (nums[i] + nums[left] + nums[right] == 0)
			{
				res.push_back({ nums[i],nums[left],nums[right] });

				left++;
				right--;

				while (left < right && nums[left] == nums[left - 1])
					left++;

				while (left < right && nums[right] == nums[right + 1])
					right--;
			}
			else if (nums[i] + nums[left] + nums[right] < 0)
			{
				left++;
			}
			else if (nums[i] + nums[left] + nums[right] > 0)
			{
				right--;
			}
		}
	}

	return res;
}