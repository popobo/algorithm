#include "Solution.h"
#include <iostream>
#include <string.h>
#include "ListNode.h"

using namespace std;

int main()
{
	Solution solution;

	/*
	char *str = new char[100];
	strncpy_s(str, 100, "We are one", 100);
	solution.replaceSpace(str, strlen(str));
	cout << str << endl;
	if (str != nullptr)
	{
		delete str;
		str = nullptr;
	}
	*/

	ListNode *head = nullptr;
	create_new_list(&head, 10);
	print_listnode(head);

	solution.printListFromTailToHead(head->next);
	
	system("pause");
	
	return 0;
}