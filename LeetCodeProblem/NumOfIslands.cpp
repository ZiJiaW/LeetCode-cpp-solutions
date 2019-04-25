#include "all.h"
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        height = grid.size();
        if (height == 0) return 0;
        width = grid[0].size();
        if (width == 0) return 0;
        while (hasNext(grid))
        {
            count++;
            stack<pair<int, int>> s;
            s.push(next);
            while (!s.empty())
            {
                int x = s.top().first, y = s.top().second;
                s.pop();
                while (y >= 1 && grid[x][y - 1] == '1') y--;
                bool up = true, down = true;
                for (int col = y; col < width && grid[x][col] == '1'; ++col)
                {
                    grid[x][col] = '0';
                    if (up && x != 0 && grid[x - 1][col] == '1')
                    {
                        s.push(pair<int, int>(x - 1, col));
                        up = false;
                    }
                    if (!up && x != 0 && grid[x - 1][col] == '0') up = true;
                    if (down && x != height - 1 && grid[x + 1][col] == '1')
                    {
                        s.push(pair<int, int>(x + 1, col));
                        down = false;
                    }
                    if (!down && x != height - 1 && grid[x + 1][col] == '0') down = true;
                }
            }
        }
        return count;
    }
private:
    int height, width;
    pair<int, int> next;
    bool hasNext(vector<vector<char>>& grid)
    {
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                if (grid[i][j] == '1')
                {
                    next = pair<int, int>(i, j);
                    return true;
                }
            }
        }
        return false;
    }
};

//int main()
//{
//    vector<vector<char>> grid({ vector<char>({'1','1','0','0','0'}),
//        vector<char>({'1','0','0','1','0'}) ,
//        vector<char>({'0','0','1','0','0'}) ,
//        vector<char>({'0','1','1','1','1'}) });
//    cout << Solution().numIslands(grid);
//}