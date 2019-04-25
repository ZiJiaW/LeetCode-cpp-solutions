#include "all.h"
using namespace std;
//124

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        dfs(root);
        return maxSum;
    }
private:
    int maxSum;
    int dfs(TreeNode* root)
    {
        if (!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int thisSum = root->val;
        if (left > 0) thisSum += left;
        if (right > 0) thisSum += right;
        maxSum = max(maxSum, thisSum);
        return max(right, left) > 0 ? max(right, left) + root->val : root->val;
    }
};
/*
int main()
{
    TreeNode a(1), b(2), c(-3), d(4), e(5), f(6);
    a.left = &b;
    a.right = &c;
    c.right = &f;
    b.left = &d;
    b.right = &e;
    cout << Solution().maxPathSum(&a) << endl;
    return 0;
}*/