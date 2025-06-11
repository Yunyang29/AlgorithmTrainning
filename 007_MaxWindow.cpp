// ✔️题目
// 生成窗口最大值数组
// 有一个整型数组arr和一个大小为w的窗口从数组的最左边滑到最右边，窗口每次向右边滑一个位置
// 如果数组长度为n，窗口大小为w，则一共产生n-w+1个窗口的最大值。请实现一个函数
// ● 输入：整型数组arr，窗口大小为w
// ● 输出：一个长度为n-w+1的数组res，res[i]表示每一种窗口状态下的最大值
// ✔️思路
// 如果新进来的元素比前边的元素大，那么在滑动的过程中，前边的元素就不可能是最大值了
// ✔️leetcode
// https://leetcode.cn/problems/sliding-window-maximum/description/

#include "Tool.cpp"
#include <iostream>
#include <vector>

class _007 {
private:
	/// <summary>
	/// ​​O(n×w)​​
	/// </summary>
	/// <param name="arr"></param>
	/// <param name="w"></param>
	/// <returns></returns>
	std::vector <int> maxInWindows(const std::vector<int>& arr, int w) {
		if (arr.empty() || w <= 0 || w > arr.size()) {
			return {};
		}

		std::vector<int> res;
		int startIndex = 0;
		int curMax = arr[0];
		for (int endIndex = 0; endIndex < arr.size(); endIndex++) {
			// 更新当前窗口的最大值
			if (arr[endIndex] > curMax) {
				curMax = arr[endIndex];
			}

			// 当窗口大小达到 w 时，记录最大值并移动窗口
			if (endIndex - startIndex + 1 == w) {
				res.push_back(curMax);
				// 如果窗口左边界移出的是当前最大值，需要重新计算窗口内的最大值
				if (arr[startIndex] == curMax) {
					curMax = arr[startIndex + 1]; // 假设下一个元素是新的最大值
					for (int i = startIndex + 1; i <= endIndex; i++) {
						if (arr[i] > curMax) {
							curMax = arr[i];
						}
					}
				}
				startIndex++; // 移动窗口左边界
			}
		}

		return res;
	}

	/// <summary>
	/// 维护一个递减队列​​（存储的是数组元素的 ​​索引​​，而不是值）
	/// 滑动窗口时更新队列
	///		移除队头元素，因为它已经不在窗口内
	///		如果新进来的元素比队尾元素大，则弹出队尾元素（因为它们不可能成为后续窗口的最大值）
	///		加入新元素的索引
	/// 如果窗口形成时，记录最大值
	/// </summary>
	/// <param name="arr"></param>
	/// <param name="w"></param>
	/// <returns></returns>
	std::vector<int> maxInWindows_1(const std::vector<int>& arr, int w) {
		if (arr.empty() || w <= 0 || w > arr.size()) {
			return {};
		}

		std::vector<int> res;
		std::deque<int> dq; // 存储索引，维护递减队列

		for (int i = 0; i < arr.size(); i++) {
			// 移除不在当前窗口内的元素
			while (!dq.empty() && dq.front() <= i - w) {
				dq.pop_front();
			}

			// 维护递减队列，如果 arr[i] 比队尾元素大，则弹出队尾元素（因为它们不可能成为后续窗口的最大值）
			while (!dq.empty() && arr[dq.back()] <= arr[i]) {
				dq.pop_back();
			}

			dq.push_back(i);

			// 当窗口形成时，记录最大值
			if (i >= w - 1) { // i > w
				res.push_back(arr[dq.front()]);
			}
		}

		return res;
	}

	int max(int a, int b)
	{
		return a > b ? a : b;
	}


public:
	_007() {
	}
	void test() {
		std::vector<int> arr = { 4,3,5,4,3,3,6,7 };
		int w = 3;
		std::vector<int> result = maxInWindows(arr, w);
		std::cout << "Max in windows: ";
		for (int i : result) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
		std::cout << " " << std::endl;
		system("pause");
		return;
	}
};
