// Date: 27/05/25
// LeetCode: https://leetcode.cn/problems/remove-linked-list-elements/
// Keywords: Linked List
// Idea:
// - Use a dummy head node to simplify the implementation.

#include "General.h"
#include "LinkedList.h"

ListNode* LinkedList::_203_remove_linked_list_elements::main(ListNode* head, int val)
{
	ListNode* dummyHead = new ListNode(0);
	dummyHead->next = head;
	ListNode* current = dummyHead;
	while (current->next != nullptr) {
		if (current->next->val == val) {
			ListNode* toDelete = current->next;
			current->next = toDelete->next;
			delete toDelete;
		}
		else {
			current = current->next;
		}
	}
	ListNode* result = dummyHead->next;
	delete dummyHead; // Clean up the dummy head
	return result;
}