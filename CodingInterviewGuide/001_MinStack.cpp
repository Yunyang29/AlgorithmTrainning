// ✔️题目
// 给定一个栈，请设计一个支持push、pop、top操作，并能在O(1)检索到最小元素的栈
// ✔️思路
// 辅助站记录当前栈的最小值；
// 每次push时，如果当前元素小于等于辅助栈的栈顶元素，则将当前元素压入辅助栈；
// 出栈时，如果当前栈顶元素等于辅助栈的栈顶元素，则弹出辅助栈的栈顶元素；
// ✔️leetcode
// https://leetcode.cn/problems/min-stack/description/

#include <stack>
#include <stdexcept>
#include <iostream>

class _001 {
private:
	struct Node {
		int data;
		Node* under;
		Node(int val) : data(val), under(nullptr) {} // 构造函数
	};
	Node* topNode; // 栈顶指针
	int capacity;
	int count;

	std::stack<int> stackData; // 辅助栈

	void push(int x) {
		if (count == capacity)
		{
			return; // 栈满
		}
		count++;
		Node* newNode = new Node(x);
		newNode->under = topNode;
		topNode = newNode;

		// 只在辅助栈中存储当前栈的最小值
		if (stackData.empty() || x <= stackData.top())
		{
			stackData.push(x);
		}

		// 辅助stack中的元素个数等于主栈的元素个数
	/*	if (stackData.empty() || x <= stackData.top())
		{
			stackData.push(x);
		}
		else
		{
			stackData.push(stackData.top());
		}*/
	}

	void pop() {
		if (topNode == nullptr)
		{
			return; // 栈空
		}
		Node* temp = topNode;
		topNode = topNode->under;

		// 如果当前栈顶元素等于辅助栈的栈顶元素，则弹出辅助栈的栈顶元素
		if (temp != nullptr && temp->data == stackData.top())
		{
			stackData.pop();
		}
		//// 辅助stack中的元素个数等于主栈的元素个数
		//stackData.pop();

		delete temp;
		count--;
	}

	int top() {
		if (topNode == nullptr)
		{
			throw std::runtime_error("Stack is empty");
		}
		return topNode->data;
	}

	int getMin() {
		if (stackData.empty())
		{
			throw std::runtime_error("Stack is empty");
		}
		return stackData.top();
	}
public:
	_001() {
		topNode = nullptr;
		capacity = 1000;
		count = 0;
	}

	void test() {
		push(3);
		push(5);
		push(2);
		push(1);
		push(4);
		std::cout << "栈顶元素: " << top() << std::endl; // 4
		std::cout << "最小元素: " << getMin() << std::endl; // 1
		pop();
		std::cout << "栈顶元素: " << top() << std::endl; // 1
		std::cout << "最小元素: " << getMin() << std::endl; // 1
	}
};