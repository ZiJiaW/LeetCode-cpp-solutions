#include "all.h"
using namespace std;
/*
https://leetcode.com/problems/sliding-window-maximum/
求长度为k的滑动窗口在nums数组中的不同位置的最大值;
Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
*/

class Solution {
public:
    vector<int> maxSlidingWindow_slow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i)
        {
            q.push(pair<int, int>(nums[i], i));
            while (!q.empty() && q.top().second <= i - k) q.pop();
            if (i >= k - 1) res.push_back(q.top().first);
        }
        return res;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        vector<int> res;
        for (int i = 0; i < n; ++i)
        {
            if (!q.empty() && q.front() == i - k) q.pop_front();
            while (!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
            q.push_back(i);
            if (i >= k - 1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};

//int main()
//{
//    auto r = Solution().maxSlidingWindow(vector<int>({ 1,3,-1,-3,5,3,6,7 }), 3);
//    copy(r.begin(), r.end(), ostream_iterator<int>(cout, " "));
//}