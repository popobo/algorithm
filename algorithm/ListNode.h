#pragma once
#include <limits>

const int HEAD_VALUE = INT_MIN;

typedef struct ListNode 
{
	int val;
	struct ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}
}ListNode;

bool create_new_list(ListNode** head, int size);
void print_listnode(ListNode *head);