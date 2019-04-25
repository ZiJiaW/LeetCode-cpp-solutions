#include "all.h"
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        n = s.length();
        p = vector<vector<bool>>(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i; j < n; ++j)
                if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1]))
                    p[i][j] = true;
        }
        vector<vector<string>> result;
        cut(vector<string>(), 0, result, s);
        return result;
    }
private:
    vector<vector<bool>> p;
    size_t n;
    void cut(vector<string> tmp, int start, vector<vector<string>>& result, const string &s)
    {
        if (start == n) result.push_back(tmp);
        else
        {
            for (int j = start; j < n; ++j)
            {
                if (p[start][j])
                {
                    tmp.push_back(s.substr(start, j + 1 - start));
                    cut(tmp, j + 1, result, s);
                    tmp.pop_back();
                }
            }
        }
    }
};

//int main()
//{
//    auto ret = Solution().partition("abacd");
//    for (auto v : ret)
//    {
//        copy(v.begin(), v.end(), ostream_iterator<string>(cout, " "));
//        cout << endl;
//    }
//    return 0;
//}