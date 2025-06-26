// Date: 18/05/25
// Leetcode: https://leetcode.cn/problems/sliding-window-maximum/
// Keywords: Sliding Window Maximum, Deque, Monotonic Queue
// Idea:
// - Use a deque to maintain the indices of the maximum elements in the current sliding window.
// - As we slide the window, we remove indices that are out of the current window and maintain the order of maximum elements in the deque.
// - When the window is valid (i.e., when the current index is greater than or equal to k - 1), we add the maximum element (the front of the deque) to the result vector.

#include "Array.h"
#include <deque>

/// <summary>
///
/// </summary>
/// <param name="nums">array</param>
/// <param name="k">window size</param>
/// <returns></returns>
vector<int> Array::_239_sliding_window_maximum::main(vector<int>& nums, int k)
{
	if (nums.empty() || k <= 0 || k > nums.size()) {
		return {};
	}

	vector<int> res;
	deque<int> dq;

	for (int i = 0; i < nums.size(); i++) {
		while (!dq.empty() && nums[dq.back()] < nums[i]) {
			dq.pop_back();
		}
		dq.push_back(i);

		while (!dq.empty() && dq.front() <= i - k) {
			dq.pop_front();
		}

		if (i >= k - 1) { // i > k
			res.push_back(nums[dq.front()]);
		}
	}

	return res;
}