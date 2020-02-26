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
