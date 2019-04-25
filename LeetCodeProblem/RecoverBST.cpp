#include "all.h"
using namespace std;

//99

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *change1 = nullptr, *change2 = nullptr;
        inorderTraversal(root);
        if (pairs.size() == 1)
        {
            change1 = pairs[0].first;
            change2 = pairs[0].second;
        }
        else
        {
            change1 = pairs[0].first->val > pairs[1].first->val ? pairs[0].first : pairs[1].first;
            change2 = pairs[0].second->val < pairs[1].second->val ? pairs[0].second : pairs[1].second;
        }
        int tmp = change1->val;
        change1->val = change2->val;
        change2->val = tmp;
    }
private:
    typedef pair<TreeNode*, TreeNode*> Pair;
    vector<Pair> pairs;
    Pair inorderTraversal(TreeNode* p)
    {
        Pair left, right;
        if (!p) return Pair(nullptr, nullptr);
        left = inorderTraversal(p->left);
        if (left.second && left.second->val > p->val)
            pairs.emplace_back(left.second, p);
        right = inorderTraversal(p->right);
        if (right.first && p->val > right.first->val)
            pairs.emplace_back(p, right.first);
        return Pair(left.first ? left.first : p, right.second ? right.second : p);
    }
};
/*
int main()
{
    TreeNode a(1), b(2), c(3);
    a.left = &c;
    c.right = &b;
    Solution().recoverTree(&a);
    return 0;
}*/