#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ListNode.h"

using namespace std;

bool create_new_list(ListNode ** headOut, int size)
{
	ListNode* head = new ListNode(HEAD_VALUE);
	if (nullptr == head)
	{
		return false;
	}
	ListNode* pre = head;
	ListNode* born = nullptr;
	
	unsigned int seed = time(0);
	srand(seed);

	for (int i = 0; i < size; ++i)
	{
		born = new ListNode(rand());
		if (nullptr == born)
		{
			return false;
		}
		pre->next = born;
		pre = born;
	}
	
	*headOut = head;

	return true;
}

void print_listnode(ListNode *head) 
{
	if (nullptr == head)
	{
		return;
	}
	ListNode *node = head->next;
	while (node != nullptr)
	{
		cout << node->val << ", ";
		node = node->next;
	}
	cout << endl;
}

