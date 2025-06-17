// ¡Ì Leetcode 142 https://leetcode.cn/problems/linked-list-cycle-ii/description/
//
// ¡Ì Keywords: Linked List Cycle, Cycle Detection, Floyd's Tortoise and Hare Algorithm
//
// ¡Ì Idea:	
// - A fast pointer and a slow pointer are used to detect the cycle.
// - If they meet, it indicates a cycle.
// - To find the start of the cycle, a new pointer is set to the head and moved in tandem with the slow pointer until they meet again.
// - This point is the start of the cycle.

#include "General.h"

class Solution
{
public:
	ListNode* main(ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast != nullptr && fast->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
			{
				ListNode* index1 = fast;
				ListNode* index2 = head;
				while (index1 != index2)
				{
					index1 = index1->next;
					index2 = index2->next;
				}
				return index2;
			}
		}
		return nullptr;
	}
};