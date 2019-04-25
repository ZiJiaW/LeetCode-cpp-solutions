/*31
* Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
* If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
* The replacement must be in-place, do not allocate extra memory.
* Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
* example: 123 --> 132; 321 --> 123; 4312 --> 4321
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1)
            return;
        auto partition = nums.end() - 2;
        while (*partition >= *(partition+1))
        {
            if (partition == nums.begin())
            {
                reverse(nums.begin(), nums.end());
                return;
            }
            partition--;
        }
        auto change = nums.end() - 1;
        while (change > partition && *change <= *partition)
        {
            change--;
        }
        swap(*partition, *change);
        reverse(partition + 1, nums.end());
    }
};
/*
int main()
{
    vector<int> nums({1,3,2});
    Solution s;
    s.nextPermutation(nums);
    for (auto p = nums.begin(); p != nums.end(); ++p)
    {
        cout << *p << ' ';
    }
    cout << endl;
    return 0;
}*/