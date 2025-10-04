// Date: 13/05/25
// LeetCode: https://leetcode.cn/problems/min-stack/
// Keywords: Stack
// Idea:
// Use two stacks and an integer

#include "..\Header\Queue&Stack.h" 

using namespace Queue_Stack;

_155_min_stack::_155_min_stack()
{
	curMin = INT_MIN; // 
}

void _155_min_stack::push(int val) {
	curMin = min(val, curMin);
	s_helper.push(curMin);
	s.push(val);
}

void _155_min_stack::pop() {
	s.pop();
	s_helper.pop();
	curMin = s_helper.empty() ? INT_MAX : s_helper.top();
}

int _155_min_stack::top() {
	return s.top();
}

int _155_min_stack::getMin() {
	return curMin;
}