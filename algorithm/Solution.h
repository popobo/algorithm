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
	
	//用两个栈实现队列
	void push(int node);
	int pop();
	
	//旋转数组的最小数字
	int minNumberInRotateArray(vector<int> rotateArray);

	//斐波那契数列
	int Fibonacci(int n);

	int android_unlock_modules(int m, int n);

	//剑指offer, 青蛙跳台阶
	int jumpFloor(int number);

	//剑指offer, 青蛙跳台阶2
	int jumpFloorII(int number);

	//剑指offer， 矩形覆盖
	int rectCover(int number);
	
	//剑指offer, 整数二进制中1的个数
	int  NumberOf1(long n);

	//序列化与反序列化二叉树
	char* Serialize(TreeNode *root);
	TreeNode* Deserialize(char *str);
private:
	stack<int> stack1;
	stack<int> stack2;
};