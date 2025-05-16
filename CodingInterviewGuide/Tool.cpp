#include <stack>
#include <iostream>

class Tool {
public:
	static void printStack(std::stack<int> s)
	{
		std::cout << "Stack: ";
		while (!s.empty())
		{
			std::cout << s.top() << " ";
			s.pop();
		}
		std::cout << std::endl;
	}
};