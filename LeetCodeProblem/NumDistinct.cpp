#include "all.h"
using namespace std;
//115
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        if (m == 0 || n == 0) return 0;
        vector<vector<int>> f(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i < j)
                    f[i][j] = 0;
                else if (i == 0)
                    f[i][j] = s[i] == t[j] ? 1 : 0;
                else if (s[i] != t[j])
                    f[i][j] = f[i - 1][j];
                else
                {
                    if (j != 0)
                        f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
                    else
                        f[i][j] = 1 + f[i - 1][j];
                }
            }
        }
        return f[m - 1][n - 1];
    }
};
/*
int main()
{
    cout << Solution().numDistinct("babgbag", "bag") << endl;
    return 0;
}*/