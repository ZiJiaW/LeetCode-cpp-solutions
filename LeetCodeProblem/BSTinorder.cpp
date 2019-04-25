#include <vector>
#include <iostream>
#include <stack>
#include <iterator>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        stack<TreeNode*> s;
        s.push(root);
        auto cur = root;
        while (!s.empty() && cur)
        {
            while (cur->left)
            {
                s.push(cur->left);
                cur = cur->left;
            }
            result.push_back(cur->val);
            s.pop();
            while (!cur->right && !s.empty())
            {
                cur = s.top();
                result.push_back(cur->val);
                s.pop();
            }
            s.push(cur->right);
            cur = cur->right;
        }
        return result;
    }
};
/*
int main()
{
    TreeNode a(1), b(2), c(3), d(4);
    a.left = &d;
    a.right = &c;
    d.right = &b;
    auto s = Solution().inorderTraversal(&a);
    copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
    return 0;
}*/