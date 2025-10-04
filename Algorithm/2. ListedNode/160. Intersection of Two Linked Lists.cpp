// Date: 11/06/25
// Leetcode: https://leetcode.cn/problems/intersection-of-two-linked-lists/description/
// Keywords: Intersection of Two Linked Lists, Linked List, Two Pointers
// Idea:
// - Get the lengths of both linked lists.
// - Align the starting points of both lists by skipping the extra nodes in the longer list.
// - Traverse both lists simultaneously until the intersection node is found or the end is reached.

#include "..\Header\General.h" 
#include <algorithm> // for std::swap
using namespace std;

class Solution
{
private:
	int getLen(ListNode* head) {
		int res = 0;
		while (head->next != NULL) {
			res++;
			head = head->next;
		}
		return res;
	}
public:
	ListNode* main(ListNode* headA, ListNode* headB) {
		ListNode* temp_A = headA;
		ListNode* temp_B = headB;
		int len_A = getLen(temp_A);
		int len_B = getLen(temp_B);
		if (len_B > len_A) {
			swap(len_A, len_B);
			swap(temp_A, temp_B);
		}

		while (len_A > len_B) {
			temp_A = temp_A->next;
			len_A--;
		}

		while (temp_A != NULL) {
			if (temp_A == temp_B) {
				return temp_A;
			}
			temp_A = temp_A->next;
			temp_B = temp_B->next;
		}

		return NULL;
	}
};