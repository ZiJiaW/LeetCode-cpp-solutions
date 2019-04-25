#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 95
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        return genSubtree(1, n);
    }
    vector<TreeNode*> genSubtree(int s, int t)
    {
        vector<TreeNode*> trees;
        if (s > t)
        {
            trees.push_back(NULL);
            return trees;
        }
        else if (s == t)
        {
            TreeNode* tmp = new TreeNode(s);
            trees.push_back(tmp);
            return trees;
        }
        else
        {
            for (int i = s; i <= t; ++i)
            {
                auto left = genSubtree(s, i - 1);
                auto right = genSubtree(i + 1, t);
                for (auto l : left)
                {
                    for (auto r : right)
                    {
                        auto root = new TreeNode(i);
                        root->left = l;
                        root->right = r;
                        trees.push_back(root);
                    }
                }
            }
            return trees;
        }
    }
};