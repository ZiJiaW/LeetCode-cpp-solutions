#include "all.h"
using namespace std;
//https://leetcode.com/problems/majority-element-ii/
// NO. 229
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int threshold = n / 3;
        int candidate[2], count[2];
        count[0] = 0; count[1] = 0;
        for (int i : nums)
        {
            if (count[0] == 0 && candidate[1] != i)
            {
                count[0] = 1;
                candidate[0] = i;
            }
            else if (count[1] == 0 && candidate[0] != i)
            {
                count[1] = 1;
                candidate[1] = i;
            }
            else if (candidate[0] == i)
            {
                count[0]++;
            }
            else if (candidate[1] == i)
            {
                count[1]++;
            }
            else
            {
                count[0]--;
                count[1]--;
            }
        }
        //cout << candidate[0] << ' ' << candidate[1] << endl;
        count[0] = 0; count[1] = 0;
        for (int i : nums)
        {
            if (i == candidate[0]) count[0]++;
            else if (i == candidate[1]) count[1]++;
        }
        vector<int> res;
        if (count[0] > threshold) res.push_back(candidate[0]);
        if (count[1] > threshold) res.push_back(candidate[1]);
        return res;
    }
};

int main()
{
    auto r = Solution().majorityElement(vector<int>({ 1 }));
    copy(r.begin(), r.end(), ostream_iterator<int>(cout, " "));
    return 0;
}