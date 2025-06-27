// Date: 16/06/25
// Leetcode: https://leetcode.cn/problems/linked-list-cycle-ii/description/
// Keywords: Linked List Cycle, Cycle Detection, Floyd's Tortoise and Hare Algorithm
// Idea:
// - A fast pointer and a slow pointer are used to detect the cycle.
// - If they meet, it indicates a cycle.
// - To find the start of the cycle, a new pointer is set to the head and moved in tandem with the slow pointer until they meet again.
// - This point is the start of the cycle.

#include "General.h"
#include "Linkedlist.h"

using namespace LinkedList;

ListNode* _142_linked_list_cycle_ii::main(ListNode* head)
{
	ListNode* slow = head;
	ListNode* fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			break;
	}

	if (fast == NULL || fast->next == NULL)
	{
		return NULL; // No cycle detected
	}

	ListNode* node_1 = fast;
	ListNode* node_2 = head;


	while (node_1 != node_2)
	{
		node_1 = node_1->next;
		node_2 = node_2->next;
	}

	return node_1;
}