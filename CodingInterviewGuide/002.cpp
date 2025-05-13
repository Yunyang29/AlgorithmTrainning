// ✔️题目
// 编写一个类，用两个栈实现队列，支持队列的基本操作（add、poll、peek）​
// ✔️思路
// 当元素发生变动时，两个栈之间进行元素的转移
// ✔️leetcode
// https://leetcode.cn/problems/implement-queue-using-stacks/description/

#include <stack>
#include <stdexcept>
class MyQueue {
private:
	std::stack<int> stack_main;
	std::stack<int> stack_aid;

	void toss(std::stack<int>& src, std::stack<int>& dst) {
		while (!src.empty()) {
			dst.push(src.top());
			src.pop();
		}
	}
public:
	MyQueue() {
	}

	void push(int x) {
		if (stack_main.empty())
		{
			toss(stack_aid, stack_main);
		}
		stack_main.push(x);
	}

	int pop() {
		if (empty()) {
			throw std::runtime_error("Queue is empty");
		}
		if (stack_aid.empty())
		{
			toss(stack_main, stack_aid);
		}

		// remind that we need to pop the top element of stack_aid
		int val = stack_aid.top();
		stack_aid.pop();
		return val;
	}

	int peek() {
		if (empty()) {
			throw std::runtime_error("Queue is empty");
		}
		if (stack_aid.empty()) {
			toss(stack_main, stack_aid);
		}
		return stack_aid.top();
	}

	bool empty() {
		return stack_main.empty() && stack_aid.empty();
	}
};
