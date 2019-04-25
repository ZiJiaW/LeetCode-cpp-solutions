#include "all.h"
using namespace std;

// 102
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        int thisLeverCount = 1, nextLeverCount = 0;
        while (!q.empty())
        {
            vector<int> tmp;
            while (thisLeverCount != 0)
            {
                auto cur = q.front();
                q.pop();
                if (cur->left)
                {
                    q.push(cur->left);
                    nextLeverCount++;
                }
                if (cur->right)
                {
                    q.push(cur->right);
                    nextLeverCount++;
                }
                thisLeverCount--;
                tmp.push_back(cur->val);
            }
            swap(thisLeverCount, nextLeverCount);
            result.push_back(tmp);
        }
        return result;
    }
};
/*
int main()
{
    TreeNode a(1), b(2), c(3), d(4), e(5), f(6);
    a.left = &b;
    b.left = &f;
    a.right = &c;
    c.left = &d;
    c.right = &e;
    auto r = Solution().levelOrder(&a);
    for (auto x : r)
    {
        copy(x.begin(), x.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
    return 0;
}*/