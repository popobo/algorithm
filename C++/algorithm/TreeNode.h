#pragma once
#include <vector>

const int LINE_LENGTH = 128;

using namespace std;

typedef struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {};
}TreeNode;

void print_tree(TreeNode* root);

void in_order(TreeNode* root, vector<int>& inVector);