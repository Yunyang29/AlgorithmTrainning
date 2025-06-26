// Date: 25/05/15

#include <iostream>
#include <stack>
#include "Queue&Stack.h"

using namespace std;
using namespace Queue_Stack;

void ReverseStack::reverse(stack<int>& s)
{
	if (s.empty())
	{
		return;
	}

	int bottom = getBottom(s);
	reverse(s);
	s.push(bottom);
}

int ReverseStack::getBottom(stack<int>& s)
{
	int val = s.top();
	s.pop();
	if (s.empty())
	{
		return val;
	}
	else
	{
		int bottom = getBottom(s);
		s.push(val);
		return bottom;
	}
}