#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 97
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length(), r = s3.length();
        if (m + n != r) return false;
        S1 = s1, S2 = s2, S3 = s3;
        f = vector<vector<int>>(m+1, vector<int>(n+1, -1));
        return bool(judge(m, n));
    }
private:
    string S1, S2, S3;
    vector<vector<int>> f;
    int judge(int m, int n)
    {
        if (f[m][n] != -1)
            return f[m][n];
        if (m == 0)
        {
            if (S2.substr(0, n) == S3.substr(0, n))
                return f[m][n] = 1;
            else
                return f[m][n] = 0;
        }
        if (n == 0)
        {
            if (S1.substr(0, m) == S3.substr(0, m))
                return f[m][n] = 1;
            else
                return f[m][n] = 0;
        }
        if (f[m - 1][n] == -1)
            f[m - 1][n] = S3[m + n - 1] == S1[m - 1] ? judge(m - 1, n) : 0;
        if (f[m][n - 1] == -1)
            f[m][n - 1] = S3[m + n - 1] == S2[n - 1] ? judge(m, n - 1) : 0;
        return f[m][n] = f[m - 1][n] | f[m][n - 1];
        
    }
};
/*
int main()
{
    cout << Solution().isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
    return 0;
}*/