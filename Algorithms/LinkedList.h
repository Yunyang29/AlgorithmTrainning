#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include "General.h"

using namespace std;

namespace LinkedList
{
	class _707_design_linked_list {
	private:
		int _size;
		LinkedNode* _dummyHead;
	public:
		_707_design_linked_list();
		int get(int index);
		void addAtHead(int val);
		void addAtTail(int val);
		void addAtIndex(int index, int val);
		void deleteAtIndex(int index);
	};
}
#pragma once
