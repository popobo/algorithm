#include <iostream>
#include <queue>
#include <string>
#include "TreeNode.h"

using namespace std;

void print_tree(TreeNode* root) {
	queue<TreeNode*> tempQueue;
	tempQueue.push(root);
	vector<int> inOrderVector;
	in_order(root, inOrderVector);
	while (!tempQueue.empty())
	{
		vector<TreeNode*> cache;
		//取出队列中位于同一行的结点 放到cache中 
		while (!tempQueue.empty())
		{
			cache.push_back(tempQueue.front());
			tempQueue.pop();
		}
		string line(LINE_LENGTH , ' ');
		for (auto tempNode : cache)
		{
			if (tempNode)
			{
				//找当前节点中序遍历位置
				int i = 0;
				for (i = 0; i < inOrderVector.size(); i++)
				{
					if (inOrderVector[i] == tempNode->val)
					{
						break;
					}
				}

				line[i] = inOrderVector[i] + '0';
				//孩子节点入队
				if (tempNode->left)
				{
					tempQueue.push(tempNode->left);
				}
				if (tempNode->right)
				{
					tempQueue.push(tempNode->right);
				}
			}
		}
		cout << line << endl;
	}
}

void in_order(TreeNode* root, vector<int>& inVector)
{
	if (root)
	{
		in_order(root->left, inVector);
		inVector.push_back(root->val);
		in_order(root->right, inVector);
	}
}