// Date: 13/05/25
// LeetCode: https://leetcode.cn/problems/min-stack/
// Keywords: Stack
// Idea:
// Use two stacks and an integer

#include "Queue&Stack.h"

Queue_Stack::_155_min_stack::_155_min_stack()
{
	curMin = INT_MIN; // 
}

void Queue_Stack::_155_min_stack::push(int val) {
	curMin = min(val, curMin);
	s_helper.push(curMin);
	s.push(val);
}

void Queue_Stack::_155_min_stack::pop() {
	s.pop();
	s_helper.pop();
	curMin = s_helper.empty() ? INT_MAX : s_helper.top();
}

int Queue_Stack::_155_min_stack::top() {
	return s.top();
}

int Queue_Stack::_155_min_stack::getMin() {
	return curMin;
}