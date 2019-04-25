#include "all.h"
using namespace std;
//105

class Solution {
public:
    TreeNode *buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.empty()) return nullptr;
        for (int i = 0; i < inorder.size(); ++i)
            map[inorder[i]] = i;
        return build(0, preorder.size(), 0, inorder.size(), preorder, inorder);
    }
private:
    unordered_map<int, int> map;
    TreeNode* build(int ps, int pe, int is, int ie, vector<int> &pre, vector<int> &in)
    {
        if (ps == pe) return nullptr;
        TreeNode* root = new TreeNode(pre[ps]);
        int rootPos = map[root->val];
        root->left = build(ps + 1, ps + 1 + rootPos - is, is, rootPos, pre, in);
        root->right = build(ps + 1 + rootPos - is, pe, rootPos + 1, ie, pre, in);
        return root;
    }
};
/*
int main()
{
    vector<int> p({ 3,9,20,15,7 });
    vector<int> i({ 9,3,15,20,7 });
    Solution().buildTree(p, i);
    return 0;
}*/