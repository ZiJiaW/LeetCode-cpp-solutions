#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
// 76
class Solution {
public:
    string minWindow(string s, string t) {
        string result;
        int start = 0, minWidth = INT32_MAX, total = 0, final_start = 0;
        int count[256], tmp_count[256];
        fill(count, count + 256, 0);
        fill(tmp_count, tmp_count + 256, 0);
        for (char c : t)
            count[c]++;
        for (int end = 0; end < s.length() + 1; ++end)
        {
            if (total == t.length())
            {
                for (; start < end; ++start)
                {
                    if (count[s[start]] > 0)
                    {
                        if (minWidth > end - start)
                        {
                            final_start = start;
                            minWidth = end - start;
                        }
                        if (tmp_count[s[start]] == count[s[start]])
                        {
                            total--;
                            tmp_count[s[start]]--;
                            start++;
                            break;
                        }
                        else
                        {
                            tmp_count[s[start]]--;
                            continue;
                        }
                    }
                }
            }
            if (end == s.length()) break;
            if (count[s[end]] > 0)
            {
                tmp_count[s[end]]++;
                if (tmp_count[s[end]] <= count[s[end]])
                    total++;
            }
        }
        return minWidth == INT32_MAX ? "" : s.substr(final_start, minWidth);
    }
};
/*
int main()
{
    cout << Solution().minWindow("bbvvacaaaccvba", "abc") << endl;
    return 0;
}*/