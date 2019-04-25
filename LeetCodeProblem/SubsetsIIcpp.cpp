#include <iostream>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <algorithm>
using namespace std;
// 90

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> count;
        vector<vector<int>> result;
        for (int x : nums)
        {
            if (count.find(x) == count.end())
                count[x] = 1;
            else
                count[x]++;
        }
        genSubsets(vector<int>(), result, count.begin(), count.end());
        return result;
    }
    typedef unordered_map<int, int>::iterator Iter;
    void genSubsets(vector<int> tmp, vector<vector<int>>& result, Iter curPos, Iter endPos)
    {
        if (curPos == endPos)
            result.push_back(tmp);
        else
        {
            for (int i = 0; i <= curPos->second; ++i)
            {
                auto s = curPos;
                if (i > 0)
                    tmp.push_back(curPos++->first);
                else
                    curPos++;
                genSubsets(tmp, result, curPos, endPos);
                curPos = s;
            }
        }
    }
};
/*
int main()
{
    vector<vector<int>> r = Solution().subsetsWithDup(vector<int>({1,2,2}));
    for (auto row : r)
    {
        copy(row.begin(), row.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
    return 0;
}*/