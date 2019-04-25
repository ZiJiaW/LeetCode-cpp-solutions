#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
//324   3122--->2312  1112222   1 8 7 20 19 50
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        size_t n = nums.size();
        auto mid = nums.begin() + n / 2;
        nth_element(nums.begin(), mid, nums.end());
        int median = *mid;
        int li = 1;// first large index
        int si = n % 2 == 0 ? n - 2 : n - 1;// last small index
        for (auto k = 0; k < n; ++k)
        {
            if (nums[k] > median)
            {
                if (k <= li && k % 2 == 1) continue;
                swap(nums[k--], nums[li]);
                li += 2;
            }
            else if(nums[k] < median)
            {
                if (k >= si && k % 2 == 0) continue;
                swap(nums[k--], nums[si]);
                si -= 2;
            }
        }
    }
};
/*
int main()
{
    vector<int> nums({ 1,5,2,5,4 });
    Solution().wiggleSort(nums);
    copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
    return 0;
}*/