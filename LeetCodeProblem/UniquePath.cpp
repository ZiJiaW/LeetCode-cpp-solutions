#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        height = obstacleGrid.size(), width = obstacleGrid.begin()->size();
        record = vector<vector<int>>(height, vector<int>(width, -1));
        return findPaths(0, 0, obstacleGrid);
    }
    int SolutionOfDP(vector<vector<int>>& obstacleGrid)
    {
        int height = obstacleGrid.size(), width = obstacleGrid.begin()->size();
        vector<int> f(width, -1);
        f[0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                f[j] = obstacleGrid[i][j] == 1 ? 0 :
                                     j == 0 ? f[j] :
                                 i == 0 ? f[j - 1] :
                                    f[j] + f[j - 1];
            }
        }
        return f[width - 1];
    }
private:
    vector<vector<int>> record;
    int height, width;
    int findPaths(int h, int w, vector<vector<int>>& obstacleGrid)
    {
        if (obstacleGrid[h][w] == 1) return 0;
        if (h == height - 1 && w == width - 1) return 1;
        if (record[h][w] != -1) return record[h][w];
        if (h != height - 1)
            record[h + 1][w] = findPaths(h + 1, w, obstacleGrid);
        if (w != width - 1)
            record[h][w + 1] = findPaths(h, w + 1, obstacleGrid);
        return h == height - 1 ? record[h][w + 1] :
            w == width - 1 ? record[h + 1][w] : record[h][w + 1] + record[h + 1][w];
    }
};
/*
int main()
{
    Solution s;
    vector<vector<int>> og({ {0,1,0}, {0,1,0}, {0,0,0} });
    cout << s.SolutionOfDP(og);
    return 0;
}*/