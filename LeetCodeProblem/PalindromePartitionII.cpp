#include "all.h"
using namespace std;
//132
class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> f(n + 1, INT_MAX);
        f[n] = -1;
        vector<vector<bool>> p(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i; j < n; ++j)
            {
                if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1]))
                {
                    p[i][j] = true;
                    f[i] = min(f[i], f[j + 1] + 1);
                }
            }
        }
        return f[0];
    }
};

//int main()
//{
//    cout << Solution().minCut("ssas") << endl;
//    return 0;
//}