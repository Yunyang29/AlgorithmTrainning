#include "..\Header\Array.h" 
#include <algorithm>

vector<vector<int>> Array::_18_4sum::main(vector<int>& nums, int target)
{
	vector<vector<int>> res;
	sort(nums.begin(), nums.end()); // O(nlogn)
	for (int i = 0; i < nums.size() - 3; i++)
	{
		if (i > 0 && nums[i] == nums[i - 1])
			continue;
		for (int j = i + 1; j < nums.size() - 2; j++)
		{
			if (j > i + 1 && nums[j] == nums[j - 1])
				continue;
			int left = j + 1, right = nums.size() - 1;
			while (left < right)
			{
				if (nums[i] + nums[j] + nums[left] + nums[right] == target)
				{
					res.push_back({ nums[i],nums[j],nums[left],nums[right] });
					left++;
					right--;
					while (left < right && nums[left] == nums[left - 1])
						left++;
					while (left < right && nums[right] == nums[right + 1])
						right--;
				}
				else if (nums[i] + nums[j] + nums[left] + nums[right] < target)
				{
					left++;
				}
				else if (nums[i] + nums[j] + nums[left] + nums[right] > target)
				{
					right--;
				}
			}
		}
	}

	return res;
}