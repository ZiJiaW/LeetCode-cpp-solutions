#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//85
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int maxArea = 0, m = matrix.size(), n = matrix[0].size();
        vector<int> R(n, -1);
        vector<int> L(n, n);
        vector<int> H(n, 0);
        for (int i = 0; i < m; ++i)
        {
            int left = n, right = -1;
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    H[j] += 1;
                    left = min(j, left);
                    L[j] = H[j] == 1 || i == 0 ? left : max(L[j], left);
                }
                else
                {
                    H[j] = 0;
                    left = n;
                    L[j] = left;
                }
            }
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][n - j - 1] == '1')
                {
                    right = max(n - j - 1, right);
                    R[n - j - 1] = H[n - j - 1] == 1 || i == 0 ? right : min(R[n - j - 1], right);
                }
                else
                {
                    right = -1;
                    R[n - j - 1] = right;
                }
                maxArea = max(maxArea, (R[n - j - 1] - L[n - j - 1] + 1)*H[n - j - 1]);
            }
        }
        return maxArea;
    }
};
/*
int main()
{
    cout << Solution().maximalRectangle(vector<vector<char>>({ {'1','0','0'}}));
}*/