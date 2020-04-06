#include <iostream>
#include <string.h>
#include "Solution.h"

using namespace std;

void Solution::replaceSpace(char * str, int length)
{
	if (nullptr == str)
	{
		return;
	}
	int spaceNum = 0;
	for (int i = 0; i < length; i++)
	{
		if (' ' == str[i])
		{
			spaceNum++;
		}
	}
	int resultLength = length + spaceNum * 2;
	char *resultStr = new char[resultLength + 1];
	memset(resultStr, 0, resultLength + 1);
	int j = 0;
	for (int i = 0; i < length; i++)
	{
		if (' ' == str[i])
		{
			resultStr[j] = '%';
			j++;
			resultStr[j] = '2';
			j++;
			resultStr[j] = '0';
			j++;
		}
		else
		{
			resultStr[j] = str[i];
			j++;
		}

	}
	if (str != nullptr)
	{
		delete str;
		str = nullptr;
	}

	str = resultStr;
	cout << str << endl;
}


vector<int> Solution::printListFromTailToHead(ListNode * head)
{
	if (nullptr == head)
	{
		return vector<int>();
	}
	vector<int> tempVector;
	ListNode* node = head;
	while (node != nullptr)
	{
		tempVector.push_back(node->val);
		node = node->next;
	}
	vector<int> resultVector;
	for (int i = tempVector.size() - 1; i >= 0; --i)
	{
		resultVector.push_back(tempVector[i]);
	}

	for (auto result : resultVector)
	{
		cout << result << endl;
	}

	return resultVector;
}

vector<int> Solution::printListFromTailToHead_recursive(ListNode * head)
{
	ListNode* tempNode = head;
	if (tempNode != nullptr && tempNode->next != nullptr)
	{
		printListFromTailToHead_recursive(tempNode->next);
	}
	cout << tempNode->val << endl;
	printListFromTailToHead_recursive_result.push_back(tempNode->val);
	return printListFromTailToHead_recursive_result;
}


TreeNode * Solution::reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
	if (0 == pre.size())
	{
		return nullptr;
	}
	TreeNode* tempNode = new TreeNode(pre[0]);
	cout << tempNode->val;
	if (1 == pre.size())
	{
		return tempNode;
	}

	int indexVin = 0;
	for (int i = 0; i < vin.size(); i++) 
	{
		if (vin[i] == pre[0])
		{
			indexVin = i;
			break;
		}
	}
	
	int indexPre = 0;
	for (int i = 0; i < pre.size(); i++)
	{
		for (int j = 0; j <= indexVin; j++)
		{
			if (pre[i] == vin[j])
			{
				//下一代vin中有pre[i]
				break;
			}
			if (pre[i] != vin[j] && j == indexVin)
			{
				indexPre = i;
			}
		}
		if (indexPre != 0)
		{
			break;
		}
	}
	/*cout << "indexPre:" << indexPre << endl;
	for (auto ele : vector<int>(pre.begin() + indexPre, pre.end()))
	{
		cout << ele << ",";
	}
	cout << endl;
	cout << "indexVin:" << indexVin << endl;
	for (auto ele : vector<int>(vin.begin() + indexVin + 1, vin.end()))
	{
		cout << ele << ",";
	}
	cout << endl;*/

	cout << "indexVin" << indexVin << endl;
	
	if (indexVin == vin.size() - 1) //只有左子树
	{
		cout << "只有左子树" << endl;
		tempNode->left = reConstructBinaryTree(vector<int>(pre.begin() + 1, pre.end()), vector<int>(vin.begin(), vin.end() - 1));
	}
	else if (indexVin == 0) //只有右子树
	{
		cout << "只有右子树" << endl;
		tempNode->right = reConstructBinaryTree(vector<int>(pre.begin() + 1, pre.end()), vector<int>(vin.begin() + 1, vin.end()));
	}
	else //左右子树都有
	{
		cout << "存在左子树" << endl;
		tempNode->left = reConstructBinaryTree(vector<int>(pre.begin() + 1, pre.begin() + indexPre), vector<int>(vin.begin(), vin.begin() + indexVin));
		cout << "存在右子树" << endl;
		tempNode->right = reConstructBinaryTree(vector<int>(pre.begin() + indexPre, pre.end()), vector<int>(vin.begin() + indexVin + 1, vin.end()));
	}

	return tempNode;
}

void Solution::push(int node)
{
	stack1.push(node);
}

int Solution::pop()
{
	int val = 0;
	if (stack1.size() == 0 && stack2.size() == 0)
	{
		return 0;
	}
	if(stack1.size() == 1 && stack2.size() == 0)
	{
		//top（）是取出栈顶元素，不会删掉栈里边的元素
		//pop（）是删除栈顶元素
		val = stack1.top();
		stack1.pop();
		return val;
	}
	if (stack2.size() >= 1)
	{
		val = stack2.top();
		stack2.pop();
		return val;
	}
	if (stack1.size() > 1 && stack2.size() == 0)
	{
		while (!stack1.empty())
		{
			val = stack1.top();
			stack2.push(val);
			stack1.pop();
		}
		val = stack2.top();
		stack2.pop();
		return val;
	}
	return 0;
}

int Solution::minNumberInRotateArray(vector<int> rotateArray)
{
	if (rotateArray.size() == 0)
	{
		return 0;
	}
	int minNumIndex = 0;
	int minNum = rotateArray[0];

	for (int i = 0; i < rotateArray.size(); i++)
	{
		if (rotateArray[i] < minNum)
		{
			minNum = rotateArray[i];
			minNumIndex = i;
			break;
		}
	}

	return minNum;
}

