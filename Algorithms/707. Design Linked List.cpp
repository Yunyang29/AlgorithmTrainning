#include "LinkedList.h"

LinkedList::_707_design_linked_list::_707_design_linked_list()
{
	_dummyHead = new LinkedNode(0);
	_size = 0;
}

int LinkedList::_707_design_linked_list::get(int index)
{
	if (index >= _size || index < 0) {
		return -1;
	}

	LinkedNode* current = _dummyHead->next;
	while (index--)
	{
		current = current->next;
	}
	return current->val;
}

void LinkedList::_707_design_linked_list::addAtHead(int val)
{
	LinkedNode* newNode = new LinkedNode(val, _dummyHead->next);
	_dummyHead->next = newNode;
	_size++;
}

void LinkedList::_707_design_linked_list::addAtTail(int val)
{
	LinkedNode* current = _dummyHead;
	while (current->next != nullptr) {
		current = current->next;
	}
	current->next = new LinkedNode(val);
	_size++;
}

void LinkedList::_707_design_linked_list::addAtIndex(int index, int val)
{
	if (index > _size)
		return;

	if (index < 0)
		index = 0;

	int count = 0;
	LinkedNode* current = _dummyHead;
	while (index--) {
		current = current->next;
		count++;
	}
	LinkedNode* newNode = new LinkedNode(val);
	newNode->next = current->next;
	current->next = newNode;
	_size++;
}

void LinkedList::_707_design_linked_list::deleteAtIndex(int index)
{
	if (index >= _size || index < 0) {
		return;
	}

	LinkedNode* current = _dummyHead;
	while (index--) {
		current = current->next;
	}

	LinkedNode* temp = current->next;
	current->next = temp->next;
	delete temp;
	temp = nullptr;
	_size--;
}