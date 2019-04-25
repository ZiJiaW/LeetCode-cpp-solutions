#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//64
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.begin()->size();
        if (n == 0 || m == 0) return 0;
        int *row_min = new int[n]();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == 0)
                    row_min[j] = j == 0 ? grid[i][j] : row_min[j - 1] + grid[i][j];
                else
                    row_min[j] = j == 0 ? row_min[j] + grid[i][j] : min(row_min[j] + grid[i][j], row_min[j - 1] + grid[i][j]);
            }
        }
        return row_min[n - 1];
    }
};
/*
int main()
{
    vector<vector<int>> grid({ {1,3,1},{1,5,1},{4,2,1} });
    cout << Solution().minPathSum(grid);
    return 0;
}*/