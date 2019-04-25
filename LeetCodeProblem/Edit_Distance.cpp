#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 72
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> count(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m + 1; ++i)
        {
            for (int j = 0; j < n + 1; ++j)
            {
                if (i == 0 || j == 0)
                    count[i][j] = i == 0 ? j : i;
                else if (word1[i - 1] == word2[j - 1])
                    count[i][j] = count[i - 1][j - 1];
                else
                    count[i][j] = min(count[i][j - 1], min(count[i - 1][j], count[i - 1][j - 1])) + 1;
            }
        }
        return count[m][n];
    }
};
/**
int main()
{
    cout << Solution().minDistance("intention", "itentio") << endl;
    return 0;
}*/