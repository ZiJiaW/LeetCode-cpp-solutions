/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
For example,Given input array nums = [1,1,2],Your function should return length = 2, 
with the first two elements of nums being 1 and 2 respectively. 
It doesn't matter what you leave beyond the new length.
LeetCode 26.
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1 || nums.size() == 0)
            return nums.size();
        vector<int> temp;
        for (auto p = nums.begin(); p != nums.end(); ++p)
        {
            temp.push_back(*p);
            while (p + 1 != nums.end() ? *p == *(p + 1) : 0)
            {
                ++p;
            }
        }
        nums = temp;
        return nums.size();
    }
};
/*
int main()
{
    vector<int> a;
    a.push_back(1); a.push_back(1); a.push_back(2); a.push_back(3); a.push_back(3); a.push_back(4); a.push_back(5);
    Solution s;
    cout << s.removeDuplicates(a) << endl;
    for (auto p : a)
    {
        cout << p << ' ';
    }
    return 0;
}
*/