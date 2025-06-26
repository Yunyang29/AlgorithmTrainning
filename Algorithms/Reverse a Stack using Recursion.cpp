// Date: 15/05/25

#include "Queue&Stack.h"

using namespace Queue_Stack;

void reverse_a_stack_using_recursion::reverse(stack<int>& s)
{
	if (s.empty())
		return;

	int val = getBottom(s);
	reverse(s);
	s.push(val);
}

int reverse_a_stack_using_recursion::getBottom(stack<int>& s)
{
	int val = s.top();
	s.pop();
	if (s.empty())
	{
		return val;
	}
	else
	{
		int res = getBottom(s);
		s.push(val);
		return res;
	}
}