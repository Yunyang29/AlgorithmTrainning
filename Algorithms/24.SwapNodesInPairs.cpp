// ¡Ì Date: 25/06/10
// ¡Ì Leetcode 24 https://leetcode.cn/problems/spiral-matrix-ii/description/
//
// ¡Ì Keywords: Swap Nodes, Linked List, Pairwise Swap
//
// ¡Ì Idea:
// - The most confused part is finding the right nodes while swaping.
// - Draw a sketch and set a dummy node to simplify the process.
// - Iterate through the list, swapping pairs of nodes until the end is reached.

#include "General.h"
#include <stdio.h>

class Solution
{
public:
	ListNode* main(ListNode* head)
	{
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* cur = dummy;
		while (cur->next != nullptr && cur->next->next != nullptr)
		{
			ListNode* a = cur->next;
			ListNode* c = cur->next->next->next;

			cur->next = cur->next->next;
			cur->next->next = a;
			cur->next->next->next = c;

			cur = cur->next->next;
		}

		ListNode* result = dummy->next;
		delete dummy;
		return result;
	}

	void test()
	{
		ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
		ListNode* result = main(head);
		while (result != nullptr)
		{
			printf("%d ", result->val);
			result = result->next;
		}
		printf("\n");
		delete head; // Clean up the original list
	}
};