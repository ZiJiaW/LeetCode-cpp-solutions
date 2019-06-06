#include "all.h"
using namespace std;
//NO.236 https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        search(root, p, q);
        return LCA;
    }
    /*更优的简化
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        else
        {
            if (p == root || q == root) return root;
            TreeNode* left = lowestCommonAncestor(root->left, p, q);
            TreeNode* right = lowestCommonAncestor(root->right, p, q);
            if (left && right) return root;
            return left ? left : right;
        }
    }*/
private:
    TreeNode* LCA = nullptr;
    pair<bool, bool> search(TreeNode* t, TreeNode* p, TreeNode* q)
    {
        pair<bool, bool> res(false, false);
        if (!t) return res;
        if (t == p) res.first = true;
        if (t == q) res.second = true;
        auto lf = search(t->left, p, q);
        auto rg = search(t->right, p, q);
        res.first |= lf.first | rg.first;
        res.second |= lf.second | rg.second;
        if (LCA == nullptr&&res.second&&res.first) LCA = t;
        return res;
    }
};
