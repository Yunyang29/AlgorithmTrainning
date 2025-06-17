#pragma once

#include <vector>
#include <stack>
#include <string>
#include <queue>

using namespace std;

namespace Queue_Stack
{
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

	class ReverseStack {
	public:
		void reverse(stack<int>& stack);
		int getBottom(stack<int>& stack);
	};
}
