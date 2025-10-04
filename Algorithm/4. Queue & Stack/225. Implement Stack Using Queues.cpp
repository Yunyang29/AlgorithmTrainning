#include "..\Header\Queue&Stack.h" 


Queue_Stack::_225_implement_stack_using_queues::_225_implement_stack_using_queues()
{

}

void Queue_Stack::_225_implement_stack_using_queues::push(int val) {
	q.push(val);
}

int Queue_Stack::_225_implement_stack_using_queues::pop() {
	int curSize = q.size();
	curSize--;
	while (curSize--)
	{
		int val = q.front();
		q.pop();
		q.push(val);
	}
	int res = q.front();
	q.pop();
	return res;
}

int Queue_Stack::_225_implement_stack_using_queues::top() {
	int res = 0;
	int curSize = q.size();
	while (curSize--)
	{
		res = q.front();
		q.pop();
		q.push(res);
	}
	return res;
}

bool Queue_Stack::_225_implement_stack_using_queues::empty() {
	return q.empty();
}