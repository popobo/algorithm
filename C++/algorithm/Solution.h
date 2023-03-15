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
	string Serialize(TreeNode *root);
	TreeNode* Deserialize(char *str);

	//��ת����
	ListNode* ReverseList(ListNode* pHead);

	//����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η�
	double Power(double base, int exponent);

	//��������˳��ʹ����λ��ż��ǰ��
	void reOrderArray(vector<int> &array);

	//����һ����������������е�����k�����
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k);

	//��һ�����������а����������ҳ�������Ļ�����ڽ�㣬�������null
	ListNode* EntryNodeOfLoop(ListNode* pHead);

	//������ʹ��һ��ľ�彨����ˮ�塣���������͵�ľ�壬���г��Ƚ϶̵�ľ�峤��Ϊshorter�����Ƚϳ���ľ�峤��Ϊlonger�����������ʹ��k��ľ�塣��дһ��������������ˮ�����п��ܵĳ���
	vector<int> divingBoard(int shorter, int longer, int k);

	//��һ�� n * m �Ķ�ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ���������ж��������Ƿ��и�����
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target);

	//��ջ������������
	vector<string> buildArray(vector<int>& target, int n);

	//���һ���㷨���ҳ���������С��k������������˳�򷵻���k��������
	vector<int> smallestK(vector<int>& arr, int k);

	//��������
	void quickSort(vector<int> & arr, int left, int right);
	
	//��������Ϊ�������ֵļ���
	bool isPossibleDivide(vector<int>& nums, int k);

	//int exchangeBits(int num)
	int exchangeBits(int num);

	//leetcode�����������л��뷴���л�
	string serialize(TreeNode* root);
	TreeNode* deserialize(string data);

	//ð������
	
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