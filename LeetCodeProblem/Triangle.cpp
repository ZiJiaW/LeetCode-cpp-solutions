#include "all.h"
using namespace std;
// 120
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0) return 0;
        f = vector<vector<int>>(triangle.size(), vector<int>(triangle.size(), INT32_MAX));
        return dfs(0, 0, triangle);
    }
private:
    vector<vector<int>> f;
    int dfs(int row, int index, vector<vector<int>>& triangle)
    {
        if (row == triangle.size() - 1) return f[row][index] = triangle[row][index];
        int left = f[row + 1][index] != INT32_MAX ? f[row + 1][index] : f[row + 1][index] = dfs(row + 1, index, triangle);
        int right = f[row + 1][index + 1] != INT32_MAX ? f[row + 1][index + 1] : f[row + 1][index + 1] = dfs(row + 1, index + 1, triangle);
        return min(right, left) + triangle[row][index];
    }
};

//int main()
//{
//    vector<vector<int>> t;
//    t.push_back(vector<int>({ 2 }));
//    t.push_back(vector<int>({ 3,4 }));
//    t.push_back(vector<int>({ 6,5,7 }));
//    t.push_back(vector<int>({ 4,1,8,3 }));
//    cout << Solution().minimumTotal(t) << endl;
//    return 0;
//}