// ✔️题目
// 如何仅用递归函数和栈操作逆序一个栈
// 一个栈依次压入1、2、3、4、5，那么从栈顶到栈底分别为5、4、3、2、1。将这个栈转置后，从栈顶到栈底为 1、2、3、4、5，也就是实现栈中元素的逆序，但是只能用递归函数来实现，不能用其他数据结构。
// ✔️思路
// 只在一个栈上操作，所以相当于把栈的元素都弹出，然后再压入，最终获取栈底元素。
// 理解为递归调用的栈帧确实是一个“栈”，每次调用都在放置一个“悬而未决”的元素（任务），递归返回时再处理它。
// ✔️leetcode


#include <stack>
#include <iostream>
class _003 {
private:
	/// <summary>
	/// 每次调用相当于要获取真正的栈底元素，而且会把原栈的所有元素都弹出再压入
	/// </summary>
	/// <param name="s"></param>
	/// <returns></returns>
	int getAndRemoveLastElement(std::stack<int>& s) {
		int res = s.top(); // 获取栈顶元素
		s.pop(); // 弹出栈顶元素
		if (s.empty())
		{
			return res; // 返回栈顶元素
		}
		else
		{
			int last = getAndRemoveLastElement(s); // 递归获取剩余栈的栈底元素
			s.push(res); // 恢复栈：将当前元素重新压入
			return last;  // 返回真正的栈底元素
		}
	}
	/// <summary>
	/// 递归入口
	/// </summary>
	/// <param name="s"></param>
	void reverse(std::stack<int>& s) {
		if (s.empty())
			return;
		int i = getAndRemoveLastElement(s);
		reverse(s);
		s.push(i);
	}

public:
	_003() {
	}
	void test() {
		std::stack<int> s;
		s.push(1);
		s.push(2);
		s.push(3);
		s.push(4);
		s.push(5);
		reverse(s);
		while (!s.empty())
		{
			std::cout << s.top() << " ";
			s.pop();
		}
		std::cout << std::endl;
	}
};