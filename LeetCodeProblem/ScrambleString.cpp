#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        if (m != n) return false;
        if (m == 0) return true;
        vector<vector<vector<bool>>> f(vector<vector<vector<bool>>>(m, vector<vector<bool>>(m, vector<bool>(m, false))));
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                for (int k = 0; k < n && j + k < n && i + k < n; ++k)
                {
                    if (k == 0)
                        f[i][j][k] = s1[i] == s2[j];
                    else
                    {
                        for (int d = 0; d < k; ++d)
                        {
                            bool tmp =  f[i][j][d] & f[i + d + 1][j + d + 1][k - d - 1] | f[i][j + k - d][d] & f[i + d + 1][j][k - d - 1];
                            f[i][j][k] = f[i][j][k] | tmp;
                            if (tmp) break;
                        }
                    }
                }
            }
        }
        return f[0][0][n - 1];
    }

    bool isScrambleII(string s1, string s2)
    {
        int m = s1.length(), n = s2.length();
        if (m != n) return false;
        if (m == 0) return true;
        if (m == 1) return s1[0] == s2[0];
        vector<int> count(26, 0);
        for (int i = 0; i < n; ++i)
        {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (auto i : count)
        {
            if (i != 0) return false;
        }
        for (int i = 1; i<s1.size(); ++i) {
            if (isScrambleII(s1.substr(0, i), s2.substr(0, i)) &&
                isScrambleII(s1.substr(i), s2.substr(i)))
                return true;
            if (isScrambleII(s1.substr(0, i), s2.substr(s1.size() - i)) &&
                isScrambleII(s1.substr(i), s2.substr(0, s1.size() - i)))
                return true;
        }
        return false;
    }
};
/*
int main()
{
    cout << Solution().isScrambleII("abcde", "bacde") << endl;
    return 0;
}*/