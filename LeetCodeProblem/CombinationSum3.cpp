#include "all.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if (k == 0 || n == 0 || k >= 10 || n > 45) return res;
        auto cur = vector<int>();
        cur.reserve(9);
        dfs(res, cur, 0, 1, k, n);
        return res;
    }

    void dfs(vector<vector<int>> &res, vector<int> &cur, int sum, int min, int k, int n)
    {
        if (cur.size() == k)
        {
            if (sum == n) res.push_back(cur);
            return;
        }
        if (sum > n || min > 9) return;
        for (int i = min; i <= 9; ++i)
        {
            cur.push_back(i);
            dfs(res, cur, sum + i, i + 1, k, n);
            cur.pop_back();
        }
    }
};

//int main()
//{
//    auto r = Solution().combinationSum3(1, 7);
//    for (auto v : r)
//    {
//        for (auto i : v)
//        {
//            cout << i << ' ';
//        }
//        cout << endl;
//    }
//    return 0;
//}