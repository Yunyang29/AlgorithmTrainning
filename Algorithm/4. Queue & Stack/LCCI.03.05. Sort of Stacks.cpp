// Date: 16/05/25
// LeetCode: https://leetcode.cn/problems/sort-of-stacks-lcci/description/
// Keywords: Sort of Stacks, Stack, Helper Stack
// Idea:
// - Use two stacks: one for the main stack and another helper stack to maintain order.
// - The main stack (s) will maintain the order such that the top is the smallest element.
// - The helper stack (s_helper) will be used to temporarily hold elements while maintaining the order.

#include "..\Header\Queue&Stack.h" 

using namespace Queue_Stack;

LCCI0305_sort_of_stacks::LCCI0305_sort_of_stacks()
{
}

void LCCI0305_sort_of_stacks::push(int val)
{
	// 1. ȷ�� s_helper ��ջ��Ԫ�� �� val��s_helper �Ƿǵݼ��ģ�
	while (!s_helper.empty() && s_helper.top() > val) {
		s.push(s_helper.top());
		s_helper.pop();
	}

	// 2. ȷ�� s ��ջ��Ԫ�� �� val��s �Ƿǵ����ģ�
	while (!s.empty() && s.top() < val) {
		s_helper.push(s.top());
		s.pop();
	}

	// 3. ���� val����ʱ s ��Ȼ����ջ����С��ջ�����
	s.push(val);
}

void LCCI0305_sort_of_stacks::pop()
{
	while (!s_helper.empty()) {
		s.push(s_helper.top());
		s_helper.pop();
	}
	if (!s.empty()) {
		s.pop();
	}
}

int LCCI0305_sort_of_stacks::peek()
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

bool LCCI0305_sort_of_stacks::isEmpty()
{
	return s.empty() && s_helper.empty();
}