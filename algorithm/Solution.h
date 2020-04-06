#pragma once
#include "ListNode.h"
#include "TreeNode.h"
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	void replaceSpace(char *str, int length);
	vector<int> printListFromTailToHead(ListNode* head);

	vector<int> printListFromTailToHead_recursive_result;
	vector<int> printListFromTailToHead_recursive(ListNode* head);

	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin);
	
	//用两个栈实现队列
	void push(int node);
	int pop();
	
	//旋转数组的最小数字
	int minNumberInRotateArray(vector<int> rotateArray);

private:
	stack<int> stack1;
	stack<int> stack2;
};