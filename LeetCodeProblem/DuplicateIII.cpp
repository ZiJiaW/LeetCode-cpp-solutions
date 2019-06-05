#include "all.h"
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() <= 1 || k == 0 || t < 0) return false;
        set<int> s;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (!s.empty())
            {
                int high = nums[i] < INT_MAX - t ? nums[i] + t : INT_MAX;
                int low = nums[i] > INT_MIN + t ? nums[i] - t : INT_MIN;
                if (s.lower_bound(low) != s.end() && *s.lower_bound(low) <= high)
                {
                    return true;
                }
            }
            s.insert(nums[i]);
            if (s.size() == k + 1) s.erase(nums[i - k]);
        }
        return false;
    }
};



