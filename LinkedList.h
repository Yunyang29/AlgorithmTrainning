#pragma once

#include "General.h"
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

namespace LinkedList
{
	class _142_linked_list_cycle_ii {
	public:
		ListNode* main(ListNode* head);
	};

	class _203_remove_linked_list_elements {
	public:
		ListNode* main(ListNode* head, int val);
	};

	class _707_design_linked_list {
	private:
		int _size;
		ListNode* _dummyHead;
	public:
		_707_design_linked_list();
		int get(int index);
		void addAtHead(int val);
		void addAtTail(int val);
		void addAtIndex(int index, int val);
		void deleteAtIndex(int index);
	};
}
