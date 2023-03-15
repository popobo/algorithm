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
	string Serialize(TreeNode *root);
	TreeNode* Deserialize(char *str);

	//反转链表
	ListNode* ReverseList(ListNode* pHead);

	//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方
	double Power(double base, int exponent);

	//调整数组顺序使奇数位于偶数前面
	void reOrderArray(vector<int> &array);

	//输入一个链表，输出该链表中倒数第k个结点
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k);

	//给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null
	ListNode* EntryNodeOfLoop(ListNode* pHead);

	//你正在使用一堆木板建造跳水板。有两种类型的木板，其中长度较短的木板长度为shorter，长度较长的木板长度为longer。你必须正好使用k块木板。编写一个方法，生成跳水板所有可能的长度
	vector<int> divingBoard(int shorter, int longer, int k);

	//在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target);

	//用栈操作构建数组
	vector<string> buildArray(vector<int>& target, int n);

	//设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可
	vector<int> smallestK(vector<int>& arr, int k);

	//快速排序
	void quickSort(vector<int> & arr, int left, int right);
	
	//划分数组为连续数字的集合
	bool isPossibleDivide(vector<int>& nums, int k);

	//int exchangeBits(int num)
	int exchangeBits(int num);

	//leetcode二叉树的序列化与反序列化
	string serialize(TreeNode* root);
	TreeNode* deserialize(string data);

	//冒泡排序
	
	//internationalization
	//i18n
	//
	//ringcentral
	//r3c5l
	bool abbreviationEqual(std::string strSource, std::string strAbbrevi);

	int getDecimalValue(ListNode * head);

	int getDecimalValue2(ListNode * head);

	vector<int> luckyNumbers(vector<vector<int>>& matrix);

	int diagonalSum(vector<vector<int>>& mat);

	string replaceDigits(string s);

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

	vector<int> twoSum(vector<int>& nums, int target);

	vector<int> twoSumBest(vector<int>& nums, int target);

private:
	stack<int> stack1;
	stack<int> stack2;
};