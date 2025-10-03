#pragma once

#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

namespace Queue_Stack
{

	class _155_min_stack
	{
	private:
		stack<int> s;
		stack<int> s_helper;
		int curMin;
	public:
		_155_min_stack();
		void push(int val);
		void pop();
		int top();
		int getMin();
	};

	class _225_implement_stack_using_queues
	{
	private:
		queue<int> q;
	public:
		_225_implement_stack_using_queues();
		void push(int x);
		int pop();
		int top();
		bool empty();
	};

	class _232_implement_queue_using_stacks
	{
	private:
		stack<int> s;
		stack<int> s_helper;
	public:
		_232_implement_queue_using_stacks();
		void push(int x);
		int pop();
		int peek();
		bool empty();
	};

	class LCCI0305_sort_of_stacks {
	private:
		stack<int> s;
		stack<int> s_helper;
	public:
		LCCI0305_sort_of_stacks();
		void push(int val);
		void pop();
		int peek();
		bool isEmpty();
	};

	class CatAndDogQueue {
	public:
		struct Animal
		{
			string type; // "dog" or "cat"
			int order; // the order of arrival
		};

		queue<Animal*> dogQueue; // Queue for dogs
		queue<Animal*> catQueue; // Queue for cats
		int orderCounter = 0; // To maintain the order of arrival

		void add(string type);
		Animal* pollAll();
		Animal* pollDog();
		Animal* pollCat();
		bool isEmpty();
		bool isDogEmpty();
		bool isCatEmpty();
	};

	class reverse_a_stack_using_recursion {
	public:
		void reverse(stack<int>& s);
		int getBottom(stack<int>& s);
	};
}
