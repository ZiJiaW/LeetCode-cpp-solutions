#include "all.h"
using namespace std;

//129
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        result = 0;
        dfs(root, 0);
        return result;
    }
private:
    int result;
    void dfs(TreeNode* root, int sum)
    {
        if (!root) return;
        sum = 10 * sum + root->val;
        if (!root->left && !root->right) result += sum;
        else
        {
            dfs(root->left, sum);
            dfs(root->right, sum);
        }
    }
};
/*
int main()
{
    TreeNode a(1), b(2), c(0), d(4), e(5), f(6);
    a.left = &b;
    a.right = &c;
    c.right = &f;
    b.left = &d;
    b.right = &e;
    cout << Solution().sumNumbers(&a) << endl;
    return 0;
}*/