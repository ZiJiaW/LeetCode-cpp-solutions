#include "all.h"
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        if (nums.size() <= 1 || k == 0) return false;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (m.find(nums[i]) != m.end())
            {
                return true;
            }
            if (m.size() == k) m.erase(nums[i - k]);
            m[nums[i]] = 1;
        }
        return false;
    }
};
//
//int main()
//{
//    cout << Solution().containsNearbyDuplicate(vector<int>({1,2,3,1, 2 ,3}), 0);
//}