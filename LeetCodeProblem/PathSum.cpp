#include "all.h"
using namespace std;
//113

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        if (!root) return result;
        vector<int> tmp;
        dfs(root, sum, tmp, result);
        return result;
    }
private:
    void dfs(TreeNode* t, int sum, vector<int> &record, vector<vector<int>>& result)
    {
        sum -= t->val;
        record.push_back(t->val);
        if (!t->left && !t->right && sum == 0)
            result.push_back(record);
        if (t->left)
            dfs(t->left, sum, record, result);
        if (t->right)
            dfs(t->right, sum, record, result);
        record.pop_back();
    }
};