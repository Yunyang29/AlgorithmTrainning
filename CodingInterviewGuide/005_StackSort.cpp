// ✔️题目
// 一个栈中元素的类型为整型，现在想将该栈从顶到底按从大到小的顺序排序，只许申请一个栈。除此之外，可以申请新的变量，但不能申请额外的数据结构
// ✔️思路
// ✔️leetcode

#include <stack>
#include <iostream>
#include "Tool.cpp"

class _005 {
private:
	std::stack<int> stackAssit;
	int count = 0;

	/// <summary>
	/// 自己想的
	/// 每次递归调用处理一个最小值
	/// 时间复杂度 O(n^2)
	/// </summary>
	/// <param name="s"></param>
	void Sort(std::stack<int>& s)
	{
		if (count == s.size())
			return;

		int min = s.top();
		while (s.size() > count)
		{
			int temp = s.top();
			s.pop();
			if (temp < min)
			{
				min = temp;
			}
			stackAssit.push(temp);
		}

		s.push(min);
		bool found = false;
		while (!stackAssit.empty())
		{
			int temp = stackAssit.top();
			stackAssit.pop();
			if (temp == min && !found)
			{
				found = true;
				continue;
			}

			s.push(temp);
		}
		count++;
		Sort(s);
	}

	/// <summary>
	/// 书上的算法
	/// 从a依次弹到b
	/// 每次弹出时，判断当前弹出的数cur是否比b的元素大
	/// （注意如果要a从栈顶到底按照从大到小，则b中从栈顶到底按照从小到大）
	/// 如果是，则依次将b的栈顶元素弹回到a，直到cur比要弹出的元素小
	/// 把cur压入b，直至a中弹完
	/// 把b中的元素依次弹回到a
	/// 时间复杂度 O(n^2)
	/// </summary>
	void Sort_2(std::stack<int>& s)
	{
		std::stack<int> help;
		while (!s.empty())
		{
			int curTop = s.top();
			s.pop();
			while (!help.empty())
			{
				if (help.top() >= curTop)
				{
					break;
				}
				s.push(help.top());
				help.pop();
			}
			help.push(curTop);
		}
		while (!help.empty())
		{
			s.push(help.top());
			help.pop();
		}
	}

public:
	_005() {
	}
	void test() {
		std::stack<int> s;
		s.push(1);
		s.push(2);
		s.push(4);
		s.push(2);
		s.push(1);
		Tool::printStack(s);
		Sort(s);
		Tool::printStack(s);
	}
};