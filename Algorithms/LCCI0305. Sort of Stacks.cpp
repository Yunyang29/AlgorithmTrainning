// Date: 16/05/25
// LeetCode: https://leetcode.cn/problems/sort-of-stacks-lcci/description/
// Keywords: Sort of Stacks, Stack, Helper Stack
// Idea:
// - Use two stacks: one for the main stack and another helper stack to maintain order.
// - The main stack (s) will maintain the order such that the top is the smallest element.
// - The helper stack (s_helper) will be used to temporarily hold elements while maintaining the order.

#include "Queue&Stack.h"

Queue_Stack::LCCI0305_sort_of_stacks::LCCI0305_sort_of_stacks()
{
}

void Queue_Stack::LCCI0305_sort_of_stacks::push(int val)
{
	// 1. 确保 s_helper 的栈顶元素 ≤ val（s_helper 是非递减的）
	while (!s_helper.empty() && s_helper.top() > val) {
		s.push(s_helper.top());
		s_helper.pop();
	}

	// 2. 确保 s 的栈顶元素 ≥ val（s 是非递增的）
	while (!s.empty() && s.top() < val) {
		s_helper.push(s.top());
		s.pop();
	}

	// 3. 插入 val，此时 s 仍然保持栈顶最小、栈底最大
	s.push(val);
}


void Queue_Stack::LCCI0305_sort_of_stacks::pop()
{
	while (!s_helper.empty()) {
		s.push(s_helper.top());
		s_helper.pop();
	}
	if (!s.empty()) {
		s.pop();
	}
}

int Queue_Stack::LCCI0305_sort_of_stacks::peek()
{
	while (!s_helper.empty()) {
		s.push(s_helper.top());
		s_helper.pop();
	}
	if (!s.empty())
	{
		return s.top();
	}
	return -1;
}

bool Queue_Stack::LCCI0305_sort_of_stacks::isEmpty()
{
	return s.empty() && s_helper.empty();
}