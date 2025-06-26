// Date: 13/05/25
// LetCode: https://leetcode.cn/problems/implement-queue-using-stacks/description/
// Keywords: Queue Stack,
// Idea:
// - The first stack (s) is used for the main operations, while the second stack (s_helper) is used to reverse the order of elements when needed.


#include "Queue&Stack.h"

using namespace Queue_Stack;

_232_implement_queue_using_stacks::_232_implement_queue_using_stacks()
{

}

void _232_implement_queue_using_stacks::push(int x) {
	while (!s_helper.empty())
	{
		s.push(s_helper.top());
		s_helper.pop();
	}

	s.push(x);
}

int _232_implement_queue_using_stacks::pop() {
	while (!s.empty())
	{
		s_helper.push(s.top());
		s.pop();
	}

	int val = s_helper.top();
	s_helper.pop();
	return val;
}

int _232_implement_queue_using_stacks::peek() {
	while (!s.empty())
	{
		s_helper.push(s.top());
		s.pop();
	}

	int val = s_helper.top();
	return val;
}

bool _232_implement_queue_using_stacks::empty() {
	return s.empty() && s_helper.empty();
}