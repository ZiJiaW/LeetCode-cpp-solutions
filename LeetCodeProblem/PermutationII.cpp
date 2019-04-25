#include <iostream>
#include <vector>
#include <iterator>
#include <map>
using namespace std;
/*
生成不重复的排列。47
*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int, int> count;
        vector<vector<int>> result;
        vector<int> tmp;
        int size = nums.size();
        for (auto num : nums)
        {
            if (count.find(num) != count.end())
                count[num]++;
            else
                count[num] = 1;
        }
        genPermutation(count, result, tmp, size);
        return result;
    }
private:
    void genPermutation(map<int, int> &count, vector<vector<int>> &result, vector<int> tmp, int size)
    {
        if (tmp.size() == size)
        {
            result.push_back(tmp);
            return;
        }
        for (auto i = count.begin(); i != count.end(); ++i)
        {
            if (i->second > 0)
            {
                tmp.push_back(i->first);
                i->second--;
                genPermutation(count, result, tmp, size);
                tmp.pop_back();
                i->second++;
            }
        }
    }
};
/*
int main()
{
    vector<int> nums({ 1,2,1});
    Solution s;
    auto ret = s.permuteUnique(nums);
    for (auto perm : ret)
    {
        copy(perm.begin(), perm.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
    return 0;
}*/