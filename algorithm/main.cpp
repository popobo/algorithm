#include "Solution.h"
#include <iostream>
#include <string.h>
#include <string>
#include "ListNode.h"
#include "TreeNode.h"
#include <cmath>
#include <sstream>
#include <utility>

using namespace std;

#define INT_MIN (-2147483647 - 1)

int bubbleSort(int *arr, int len)
{
	if (nullptr == arr)
	{
		return -1;
	}

	int temp = 0;

	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	return 0;
}

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
	
	print_tree(root);*/
	
	
	/*solution.push(1);
	solution.push(2);
	solution.push(3);
	cout << solution.pop() << endl;
	cout << solution.pop() << endl;
	solution.push(4);
	cout << solution.pop() << endl;
	cout << solution.pop() << endl;
	*/

	/*vector<int> rot{ 3, 4, 5, 6, 7, 1, 2 };
	cout << solution.minNumberInRotateArray(rot) << endl;*/
	
	/*for (int i = 0; i < 10; i++)
	{
		cout << solution.Fibonacci(i) << endl;
	}*/

	/*int result = solution.android_unlock_modules(4, 4);*/

	/*int result = solution.jumpFloorII(5);*/

	/*int result = solution.rectCover(2);*/

	/*int input = 2147483648;

	int result = solution.NumberOf1(INT_MIN);

	cout << result << endl;*/

	/*cout << solution.Serialize(root) << endl;*/

	//¼ÇµÃÊÍ·Åroot

	/*ListNode *head = nullptr;
	create_new_list(&head, 10);
	print_listnode(head);
	solution.ReverseList(head->next);
	print_listnode(head);*/

	/*vector<int> result{ 1, 2, 3, 4, 5, 6, 7 };

	solution.reOrderArray(result);*/

	/*ListNode *head = nullptr;
	create_new_list(&head, 5);
	print_listnode(head);
	ListNode *temp = solution.FindKthToTail(head->next, 1);
	print_listnode(temp);


	vector<int> temp1;
	int iTemp = static_cast<int>(temp1.size());
	iTemp -= 10;
	cout << iTemp << endl;*/

	/*vector<int> temp{ 3, 4, 5, 6, 7, 1, 2 };
	//solution.quickSort(temp, 0, temp.size() - 1);
	vector<int> result = solution.smallestK(temp, 4);*/

	/*vector<int> temp{ 3,2,1,2,3,4,3,4,5,9,10,11 };
	solution.isPossibleDivide(temp, 3);*/

	/*vector<int> pre{ 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> mid{ 4, 7 ,2, 1, 5, 3, 8, 6 };
	TreeNode* root = solution.reConstructBinaryTree(pre,mid);
	print_tree(root);

	std::cout << solution.serialize(root) << std::endl;;
	solution.deserialize(solution.serialize(root));
	*/

	/*int arr[]{ 4, 7 ,2, 1, 5, 3, 8, 6 };
	bubbleSort(arr, sizeof(arr) / sizeof(arr[0]));*/
	
	// cout << solution.abbreviationEqual("international", "u11l");

//     ListNode *head = nullptr;
// 	int array[] = { 1, 0, 1 };
// 	createSpecifiedList(&head, array, sizeof(array) / sizeof(array[0]));
// 	int result = solution.getDecimalValue(head);
// 	result = solution.getDecimalValue2(head->next);

// 	std::vector<std::vector<int>> test = { {3,7,8}, {9,11, 13}, {15, 16, 17} };
// 	auto result = solution.luckyNumbers(test);
	
// 	std::vector<std::vector<int>> test = { {1,2,3}, {4, 5, 6}, {7, 8, 9} };
// 	int result = solution.diagonalSum(test);

// 	int array1[] = { 1, 0, 1 };
// 	int array2[] = { 1, 0, 1 };
	int array1[] = { 2, 4, 3 };
	int array2[] = { 5, 6, 4 };
	ListNode *head1 = nullptr;
	ListNode *head2 = nullptr;
	createSpecifiedList(&head1, array1, sizeof(array1) / sizeof(array1[0]));
	createSpecifiedList(&head2, array2, sizeof(array2) / sizeof(array2[0]));
	solution.addTwoNumbers(head1->next, head2->next);

	system("pause");

	return 0;
}