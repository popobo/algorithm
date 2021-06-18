#include <iostream>
#include <string.h>
#include <string>
#include <sstream>
#include <queue>
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

int Solution::Fibonacci(int n)
{	
	int num1 = 0;
	int num2 = 1;
	int temp = 0;
	if (0 == n)
	{
		return num1;
	}
	if (1 == n)
	{
		return num2;
	}
	for (int i = 0; i < n - 1; i++)
	{
		temp = num1 + num2;
		num1 = num2;
		num2 = temp;
	}
	return num2;
}


int directions[24][2] = { {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1},
						  {2, 0}, {2, -2}, {0, -2}, {-2, -2}, {-2, 0}, {-2, 2}, {0, 2}, {2, 2},
						  {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2} };


int isVisit[3][3] = { 0 };

bool canVisit(int x, int y, int xMove, int yMove)
{
	//坐标超出范围非法
	if (x + xMove > 2 || x + xMove < 0 || y + yMove > 2 || y + yMove < 0)
	{
		return false;
	}

	//如果在模式中连接两个连续键的行通过任何其他键，则其他键必须在模式中选择，不允许跳过非选择键
	if ((xMove * xMove + yMove * yMove) == 4 || (xMove * xMove + yMove * yMove) == 8)
	{
		if (0 == isVisit[(xMove + x) / 2][(yMove + y) / 2])
		{
			return false;
		}
	}
	
	if ((xMove * xMove + yMove * yMove) == 5)
	{
		return true;
	}

	if (1 == isVisit[x + xMove][y + yMove])
	{
		return false;
	}

	return true;
}

int result = 0;

//x, y当前坐标，xMove, yMove移动目标方向
void dfs(int x, int y, int xMove, int yMove, int pointsLeft)
{	
	//cout << "x:" << x << " y:" << y << " xMove:" << xMove << " yMove:" << yMove << endl;
	if (!canVisit(x, y, xMove, yMove)) 
	{
		return;
	}

	if (1 == pointsLeft)
	{
		//cout << "successful way x:" << x << " y:" << y << " xMove:" << xMove << " yMove:" << yMove << endl;
		//isVisit[x][y] = 0;
		result++;
		return;
	}

	isVisit[x + xMove][y + yMove] = 1;
	for (int i = 0; i < 24; i++)
	{
		dfs(x + xMove, y + yMove, directions[i][0], directions[i][1], pointsLeft - 1);
	}
	isVisit[x][y] = 0;
	return;
}

void initIsVisit()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			isVisit[i][j] = 0;
		}
	}
}

int Solution::android_unlock_modules(int m, int n)
{	
	int isVisit[3][3] = { 0 };
	for (int u = m; u < n + 1; u++)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (u == 1)
				{
					result += 1;
					continue;
				}
				isVisit[i][j] = 1;
				for (int k = 0; k < 24; k++)
				{
					dfs(i, j, directions[k][0], directions[k][1], u - 1);
					initIsVisit();
				}
			}
		}
	}
	
	return result;
}

int Solution::jumpFloor(int number)
{
	int sN_2 = 1;
	int sN_1 = 2;
	int sN = 0;
	
	if (1 == number)
	{
		return sN_1;
	}

	if (2 == number)
	{
		return sN_2;
	}

	for (int i = 0; i < number - 2; i++)
	{
		sN = sN_1 + sN_2;
		sN_2 = sN_1;
		sN_1 = sN;
	}

	return sN;
}



int Solution::jumpFloorII(int number)
{
	int	iResult = 0;
	if (number == 0)
	{
		return 0;
	}

	for (int i = 1; i < number; i++)
	{
		iResult += jumpFloorII(number - i);
	}

	iResult++;

	return iResult;
}

int Solution::rectCover(int number)
{
	int num1 = 1;
	int num2 = 2;
	int temp = 0;
	if (0 == number)
	{
		return 0;
	}
	if (1 == number)
	{
		return 1;
	}
	if (2 == number)
	{
		return 2;
	}
	for (int i = 0; i < number - 2; i++)
	{
		temp = num1 + num2;
		num1 = num2;
		num2 = temp;
	}
	return num2;
}

int Solution::NumberOf1(long n)
{
	long num = abs(n);
	cout << n << endl;

	if (0 == num)
	{
		return 0;
	}

	int oneCount = 0;
	int totalCount = 0;

	while (true)
	{
		totalCount++;
		if (num % 2 == 1)
		{
			oneCount++;
		}
		num = num / 2;
		cout << num << endl;
		if (1 == num)
		{
			oneCount++;
			break;
		}
		Sleep(100);
	}
	if (n < 0)
	{
		oneCount = totalCount - oneCount;
	}

	return oneCount;
}

static string resultString;

//中序序列化
string Solution::Serialize(TreeNode * root)
{
	cout << "Serialize" << endl;
	if (nullptr == root->left && nullptr == root->right)
	{
		resultString.append(to_string(root->val)).append("!");
		return string();
	}
	if (root->left)
	{
		Serialize(root->left);
	}
	else
	{
		resultString.append("#");
	}
	resultString.append(to_string(root->val)).append("!");
	if (root->right)
	{
		Serialize(root->right);
	}
	else
	{
		resultString.append("#");
	}
	return resultString;
}

TreeNode * Solution::Deserialize(char * str)
{
	int strLen = strlen(str);
	

	return nullptr;
}

ListNode * Solution::ReverseList(ListNode * pHead)
{
	ListNode* temp = pHead;
		
	stack<int> stack;
	while (temp != nullptr)
	{
		stack.push(temp->val);
		temp = temp->next;
	}
	
	temp = pHead;
	while (!stack.empty())
	{
		temp->val = stack.top();
		stack.pop();
		temp = temp->next;
	}

	return pHead;
}

double Solution::Power(double base, int exponent)
{
	double result = base;
	int temp = exponent;

	if (abs(base) < 1e-6)
	{
		return 0.0;
	}

	if (exponent == 0)
	{
		return 1;
	}

	if (exponent < 0)
	{
		exponent = -exponent;
	}
	
	while (exponent > 0)
	{
		if (exponent & 1 == 1)
		{
			//奇数
			result *= base;
		}
		exponent >>= 1;
		result *= result;
	}

	return temp > 0 ? result : (1 / result);
}

void Solution::reOrderArray(vector<int>& array)
{
	vector<int> odd;
	vector<int> event;
	for (auto& a : array)
	{
		if (a % 2 != 0)
		{
			odd.push_back(a);
		}
		else
		{
			event.push_back(a);
		}
	}
	
	int i = 0;
	for (auto& o : odd)
	{
		array[i++] = o;
	}
	for (auto& e : event)
	{
		array[i++] = e;
	}
}

ListNode * Solution::FindKthToTail(ListNode * pListHead, unsigned int k)
{
	vector<ListNode*> temp;
	if (!pListHead)
	{
		return nullptr;
	}
	while (pListHead != nullptr)
	{
		temp.push_back(pListHead);
		pListHead = pListHead->next;
	}
	int iTemp = static_cast<int>(temp.size());
	if (iTemp - k - 1 < 0)
	{
		return nullptr;
	}
	if (temp.size() - k - 1 >= temp.size())
	{
		return nullptr;
	}
	return temp.at(temp.size() - k - 1);
}

ListNode * Solution::EntryNodeOfLoop(ListNode * pHead)
{
	if (nullptr == pHead)
	{
		return nullptr;
	}
	bool bLoop = false;
	ListNode * slow = pHead;
	ListNode * fast = pHead;
	
	while (slow != nullptr && fast != nullptr && fast->next != nullptr)
	{
		
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			//走到了相同的节点代表有环
			bLoop = true;
			break;
		}
	}
	if (!bLoop)
	{
		return nullptr;
	}

	ListNode * temp = pHead;
	while (temp != slow)
	{
		temp = temp->next;
		slow = slow->next;
	}

	return temp;
}


vector<int> Solution::divingBoard(int shorter, int longer, int k)
{
	vector<int> divingBoardResult;
	if (0 == k)
	{
		return divingBoardResult;
	}

	for (int i = 0; i <= k; i++)
	{
		if (shorter == longer)
		{
			divingBoardResult.push_back(k * shorter);
			break;
		}
		else
		{
			divingBoardResult.push_back(i * longer + (k - i) * shorter);
		}
	}

	return divingBoardResult;
}

bool Solution::findNumberIn2DArray(vector<vector<int>>& matrix, int target)
{

	for (auto ritOutside = matrix.rbegin(); ritOutside != matrix.rend();)
	{
		for (auto ritInside = ritOutside->rbegin(); ritInside != ritOutside->rend();)
		{
			if (target == *ritInside)
			{
				return true;
			}
			if (target > *ritInside)
			{
				break;
			}
			else
			{
				ritInside++;
			}
		}
		ritOutside++;
	}

	return false;
}

vector<string> Solution::buildArray(vector<int>& target, int n)
{
	vector<string> buildArrayResult;
	int maxTargetValue = target[target.size() - 1];
	for (int i = 1, j = 0; i <= maxTargetValue && j < target.size(); i++)
	{
		if (i != target[j])
		{
			buildArrayResult.push_back("Push");
			buildArrayResult.push_back("PoP");
		}
		else
		{
			buildArrayResult.push_back("Push");
			j++;
		}
	}

	return buildArrayResult;
}

static int smallestKK = 0;

void Solution::quickSort(vector<int> & arr, int left, int right)
{
	if (right == smallestKK - 1 || left == smallestKK)
	{
		return;
	}
	if (left >= right)
	{
		return;
	}
	//挖出一个坑
	int benchmark = arr[left];
	int tempLeft = left;
	int tempRight = right;
	while (left != right)
	{
		while (benchmark <= arr[right] && left != right)
		{
			right--;
		}
		if (left < right)
		{
			//把坑填上， 并挖一个新坑
			arr[left] = arr[right];
		}
		while (benchmark >= arr[left] && left != right)
		{
			left++;
		}
		if (left < right)
		{
			//把坑填上， 并挖一个新坑
			arr[right] = arr[left];
		}
	}
	//填上最后一个坑
	arr[left] = benchmark;
	quickSort(arr, tempLeft, left);
	quickSort(arr, left + 1, tempRight);
}

bool Solution::isPossibleDivide(vector<int>& nums, int k)
{
	int flag = 0;
	bool isIncrease = true;

	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = i; j < k + i - 1 && j < nums.size() - 1; j++)
		{
			if (j == i)
			{
				if (nums[j] - nums[j + 1] == 1)
				{
					isIncrease = false;
				}
				else if (nums[j] - nums[j + 1] == -1)
				{
					isIncrease = true;
				}
				else
				{
					break;
				}
			}
			else
			{
				if (isIncrease == false && nums[j] - nums[j + 1] != 1)
				{
					break;
				}

				if (isIncrease == true && nums[j] - nums[j + 1] != -1)
				{
					break;
				}

				if (j == k + i - 2)
				{
					flag++;
				}
			}
		}
	}

	return flag > 1;
}

int Solution::exchangeBits(int num)
{
	int odd = num & 0xaaaaaaaa;
	int even = num & 0x55555555;
	
	odd = odd >> 1;
	even = even << 1;

	return odd | even;
}

string Solution::serialize(TreeNode * root)
{
	std::queue<TreeNode *> tempQueue;
	TreeNode *front;
	std::string serializeString;

	do 
	{
		if (nullptr == root)
		{
			break;
		}
		
		tempQueue.push(root);
		
		while (!tempQueue.empty())
		{
			front = tempQueue.front();
			if (front)
			{
				serializeString.append(",").append(std::to_string(front->val));
			}
			else
			{
				serializeString.append(",null");
			}
			tempQueue.pop();
			
			if (front)
			{
				if (front->left)
				{
					tempQueue.push(front->left);
				}
				else
				{
					tempQueue.push(nullptr);
				}

				if (front->right)
				{
					tempQueue.push(front->right);
				}
				else
				{
					tempQueue.push(nullptr);
				}
			}
		}

	} while (false);
	
	serializeString.at(0) = '[';
	serializeString.append("]");
	return serializeString;
}

TreeNode * Solution::deserialize(string data)
{
	string temp = data.substr(1, data.size()-2);
	/*int width = 1;
	int totalWidth = 0;
	while (totalWidth < )

	{
	}*/

	return nullptr;
}

bool Solution::abbreviationEqual(std::string strSource, std::string strAbbrevi)
{
	if (strSource.size() == 0 || strAbbrevi.size() == 0)
	{
		return false;
	}

	char tempIntStr[1024] = { 0 };
	int tempInt = 0;

	int str1Index = 0;
	//i18n
	//r3c5l
	//ri2c5l
	for (int i = 0; i < strAbbrevi.size();)
	{
		if ((strAbbrevi[i] >= 'a' && strAbbrevi[i] <= 'z') && (strAbbrevi[i + 1] >= '0' &&  strAbbrevi[i + 1] <= '9'))
		{
			int k = 0;
			for (int j = i + 1; j < strAbbrevi.size(); j++)
			{
				if (strAbbrevi[j] >= '0' &&  strAbbrevi[j] <= '9')
				{
					tempIntStr[k] = strAbbrevi[j];
					k++;
				}
				else
				{
					tempInt = atoi(tempIntStr);
					break;
				}
			}
			if (strSource[str1Index] == strAbbrevi[i])
			{
				str1Index += tempInt + 1;
				i += k + 1;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (strSource[str1Index] == strAbbrevi[i])
			{
				i++;
				str1Index++;
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}

int Solution::getDecimalValue(ListNode * head)
{
	if (head == nullptr) {
		return -1;
	}

	ListNode * node = head->next;
	int lengthOfList = 0;
	while (node != nullptr) {
		lengthOfList++;
		if (node->val != 0 && node->val != 1) {
			return -1;
		}
		node = node->next;
	}

	node = head->next;
	int result = 0;
	for (int i = 0; i < lengthOfList; ++i) {
		result = (node->val << (lengthOfList - 1 - i)) + result;
		node = node->next;
	}

	return result;
}

int Solution::getDecimalValue2(ListNode * head)
{
	ListNode * prev = nullptr;
	ListNode * current = nullptr;
	int result = 0;
	int count = 0;
	// reverse list
	while (head != nullptr) {
		current = head->next;
		head->next = prev;
		prev = head;
		head = current;
	}
	
	while (prev != nullptr) {
		int temp = prev->val << count;
		result = result | temp;
		count++;
		prev = prev->next;
	}

	return result;
}

vector<int> Solution::smallestK(vector<int>& arr, int k)
{
	vector<int> smallestKResult;
	smallestKK = k;
	quickSort(arr, 0, arr.size() - 1);

	for (int i = 0; i < k; i++)
	{
		smallestKResult.push_back(arr[i]);
	}

	return smallestKResult;
}