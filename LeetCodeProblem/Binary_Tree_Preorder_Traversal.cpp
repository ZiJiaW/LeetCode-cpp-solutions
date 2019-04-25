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
			if (p->right != nullptr)//ע��˳��
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
		/* pΪ��ǰ���ڴ���Ľ�㣬qΪǰһ������Ľ��*/
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
				if (p->right == q)//�����ǰ�ڵ���ҽڵ�Ϊ�ջ��ѱ����ʣ�����ʵ�ǰ�ڵ�
				{
					result.push_back(p->val);
					q = p;
				}
				else//���ҽڵ�δ�����ʣ���ǰ�ڵ�������ջ�������õ�ǰ�ڵ�Ϊ���ҽڵ㣬�˳�ѭ�����ȴ���������
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