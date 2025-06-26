// Date: 10/06/25
// Leetcode: https://leetcode.cn/problems/spiral-matrix-ii/description/
// Keywords: Swap Nodes, Linked List, Pairwise Swap
// Idea:
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
		ListNode* dummyHead = new ListNode(0, head);
		ListNode* cur = dummyHead;
		while (cur->next != nullptr && cur->next->next != nullptr) {
			ListNode* A = cur->next;
			ListNode* B = cur->next->next;

			A->next = B->next;
			cur->next = B;
			B->next = A;

			cur = cur->next->next;
		}
		head = dummyHead->next;
		delete dummyHead;
		return head;
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