#include "Solution.h"
#include <iostream>
#include <string.h>
#include "ListNode.h"
#include "TreeNode.h"

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

	/*ListNode *head = nullptr;
	create_new_list(&head, 10);
	print_listnode(head);

	solution.printListFromTailToHead(head->next);
	solution.printListFromTailToHead_recursive(head->next);
	*/

	/*vector<int> pre{ 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> mid{ 4, 7 ,2, 1, 5, 3, 8, 6 };
	TreeNode* root = solution.reConstructBinaryTree(pre,mid);
	
	print_tree(root);
	*/
	
	/*solution.push(1);
	solution.push(2);
	solution.push(3);
	cout << solution.pop() << endl;
	cout << solution.pop() << endl;
	solution.push(4);
	cout << solution.pop() << endl;
	cout << solution.pop() << endl;
	*/
	vector<int> rot{ 3, 4, 5, 6, 7, 1, 2 };
	cout << solution.minNumberInRotateArray(rot) << endl;
	
	system("pause");
	
	return 0;
}