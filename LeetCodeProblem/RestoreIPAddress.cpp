#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;//93
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        if (s.length() > 12) return result;
        dfs(result, "", 0, s, 0);
        return result;
    }
private:
    void dfs(vector<string>& result, string tmp, int index, const string& s, int count)
    {
        if (count == 3 && check(s.substr(index)))
            result.push_back(tmp + s.substr(index));
        else if (count <= 2)
        {
            for (int i = 1; i <= 3; ++i)
            {
                if (s.length() - index - i > 3 * (4 - count - 1) || s.length() - index - i < 3 - count || !check(s.substr(index, i)))
                    continue;
                dfs(result, tmp + s.substr(index, i) + '.', index + i, s, count + 1);
            }
        }
    }
    bool check(const string &s)
    {
        if (s.length() >= 2 && s[0] == '0') return false;
        else return stoi(s) <= 255;
    }
};
/*
int main()
{
    auto s = Solution().restoreIpAddresses("010010");
    copy(s.begin(), s.end(), ostream_iterator<string>(cout, "\n"));
    return 0;
}*/