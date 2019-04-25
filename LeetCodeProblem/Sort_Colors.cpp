#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
// 75
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int index_0 = 0, index_2 = nums.size() - 1;
        for (int i = 0; i <= index_2; ++i)
        {
            if (nums[i] == 0)
                swap(nums[index_0++], nums[i]);
            else if (nums[i] == 2)
                swap(nums[index_2--], nums[i--]);
        }
    }
};
/*
int main()
{
    vector<int> nums({ 2,1,0,0 });
    Solution().sortColors(nums);
    copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
    return 0;

}*/