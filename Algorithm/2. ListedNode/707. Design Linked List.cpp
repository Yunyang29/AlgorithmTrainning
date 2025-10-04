// Date: 27/05/25
// LeetCode: https://leetcode.com/problems/design-linked-list/
// Keywords: Linked List, Design
// Idea:
// - Use a dummy head node to simplify the implementation.

#include "..\Header\LinkedList.h" 

LinkedList::_707_design_linked_list::_707_design_linked_list()
{
	_dummyHead = new ListNode(0);
	_size = 0;
}

int LinkedList::_707_design_linked_list::get(int index)
{
	if (index < 0 || index >= _size)
	{
		return -1;
	}

	ListNode *current = _dummyHead->next;
	while (index--)
	{
		current = current->next;
	}

	return current->val;
}

void LinkedList::_707_design_linked_list::addAtHead(int val)
{
	ListNode *newNode = new ListNode(val, _dummyHead->next);
	_dummyHead->next = newNode;
	_size++;
}

void LinkedList::_707_design_linked_list::addAtTail(int val)
{
	ListNode *newNode = new ListNode(val);
	ListNode *current = _dummyHead;

	while (current->next != nullptr)
	{
		current = current->next;
	}

	current->next = newNode;
	_size++;
}

void LinkedList::_707_design_linked_list::addAtIndex(int index, int val)
{
	if (index < 0 || index > _size)
	{
		return;
	}

	ListNode *newNode = new ListNode(val);
	ListNode *current = _dummyHead;

	while (index--)
	{
		current = current->next;
	}

	newNode->next = current->next;
	current->next = newNode;
	_size++;
}

void LinkedList::_707_design_linked_list::deleteAtIndex(int index)
{
	if (index < 0 || index >= _size)
	{
		return;
	}

	ListNode *current = _dummyHead;

	while (index--)
	{
		current = current->next;
	}

	ListNode *toDelete = current->next;
	current->next = toDelete->next;
	delete toDelete;
	_size--;
}