#pragma once
#include "ListNode.h"
#include "TreeNode.h"
#include <vector>
#include <stack>
#include <cmath>
#include <windows.h>

using namespace std;

class Solution {
public:
	void replaceSpace(char *str, int length);
	vector<int> printListFromTailToHead(ListNode* head);

	vector<int> printListFromTailToHead_recursive_result;
	vector<int> printListFromTailToHead_recursive(ListNode* head);

	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin);
	
	//������ջʵ�ֶ���
	void push(int node);
	int pop();
	
	//��ת�������С����
	int minNumberInRotateArray(vector<int> rotateArray);

	//쳲���������
	int Fibonacci(int n);

	int android_unlock_modules(int m, int n);

	//��ָoffer, ������̨��
	int jumpFloor(int number);

	//��ָoffer, ������̨��2
	int jumpFloorII(int number);

	//��ָoffer�� ���θ���
	int rectCover(int number);
	
	//��ָoffer, ������������1�ĸ���
	int  NumberOf1(long n);

	//���л��뷴���л�������
	char* Serialize(TreeNode *root);
	TreeNode* Deserialize(char *str);
private:
	stack<int> stack1;
	stack<int> stack2;
};