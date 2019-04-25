/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
Given a binary tree, return the preorder/postorder traversal of its nodes' values.
Problem 144 145
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode *> s;
		if (root != nullptr) s.push(root);
		while (!s.empty())
		{
			TreeNode *p = s.top();
			s.pop();
			result.push_back(p->val);
			if (p->right != nullptr)//注意顺序
				s.push(p->right);
			if (p->left != nullptr)
				s.push(p->left);
		}
		return result;
	}
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<const TreeNode *> s;
		const TreeNode *p = root, *q = nullptr;
		/* p为当前正在处理的结点，q为前一个处理的结点*/
		do {
			while (p != nullptr)
			{
				s.push(p);
				p = p->left;
			}
			q = nullptr;
			while (!s.empty())
			{
				p = s.top();
				s.pop();
				if (p->right == q)//如果当前节点的右节点为空或已被访问，则访问当前节点
				{
					result.push_back(p->val);
					q = p;
				}
				else//若右节点未被访问，当前节点重新入栈，并设置当前节点为其右节点，退出循环，先处理右子树
				{
					s.push(p);
					p = p->right;
					break;
				}
			}
		} while (!s.empty());
		return result;
	}
};