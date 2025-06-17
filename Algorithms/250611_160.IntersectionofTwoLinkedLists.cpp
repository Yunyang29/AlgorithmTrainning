// ¡Ì Leetcode 160 https://leetcode.cn/problems/intersection-of-two-linked-lists/description/
//
// ¡Ì Keywords: Intersection of Two Linked Lists, Linked List, Two Pointers
//
// ¡Ì Idea:
// - Get the lengths of both linked lists.
// - Align the starting points of both lists by skipping the extra nodes in the longer list.
// - Traverse both lists simultaneously until the intersection node is found or the end is reached.

#include "General.h"
#include <algorithm> // for std::swap
using namespace std;

class Solution
{
private:
	void getListLength(ListNode* head, int& len) {
		while (head) {
			len++;
			head = head->next;
		}
	}
public:
	ListNode* main(ListNode* headA, ListNode* headB) {
		ListNode* pA = headA;
		ListNode* pB = headB;
		int lenA = 0, lenB = 0;

		getListLength(pA, lenA);
		getListLength(pB, lenB);

		pA = headA;
		pB = headB;

		if (lenB > lenA)
		{
			swap(pA, pB);
			swap(lenA, lenB);
		}

		while (lenA > lenB)
		{
			pA = pA->next;
			lenA--;
		}

		while (pA != NULL)
		{
			if (pA == pB)
				return pA;
			pA = pA->next;
			pB = pB->next;
		}

		return NULL;
	}
};