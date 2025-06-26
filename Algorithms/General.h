#pragma once

struct LinkedNode {
	int val;
	LinkedNode* next;
	LinkedNode() : val(0), next(nullptr) {}
	LinkedNode(int x) : val(x), next(nullptr) {}
	LinkedNode(int x, LinkedNode* next) : val(x), next(next) {}
};