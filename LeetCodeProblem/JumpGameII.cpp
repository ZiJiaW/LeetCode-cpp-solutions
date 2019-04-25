#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    // DP Ì«Âý n^3
    int jumpx(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> record(len, vector<int>(len, 0));
        if (len == 2) return 1;
        for (int step = 1; step < len; ++step)
        {
            for (int start = 0; start < len - step; ++start)
            {// now compute record[start, start+step]
                if (step == 1 && nums[start] == 0)
                    record[start][start + step] = len;//len represents infinity here
                else if (nums[start] >= step)
                    record[start][start + step] = 1;
                else
                {
                    int tmpMin = len;
                    for (int mid = start + 1; mid < start + step; ++mid)
                        tmpMin = min(record[start][mid] + record[mid][start + step], tmpMin);
                    record[start][start + step] = tmpMin;
                }
            }
        }
        return record[0][len - 1];
    }
    // Ì°ÐÄ
    int jump(vector<int> &nums) {
        int right = 0, left = 0, step = 0;
        while (right < nums.size() - 1)
        {
            step++;
            int old_right = right;
            for (int i = left; i <= old_right; ++i)
            {
                right = max(right, nums[i] + i);
            }
            left = old_right + 1;
        }
        return step;
    }
};
/*
int main()
{
    int a[] = {9,7,9,1,7,3,7,0,5,0,0,5,6,7,5,6,0,5,4,7,3,9,0,2,0,5,9,2,3,6,0,4,3,1,6,
        3,4,3,3,1,3,3,8,1,2,3,0,3,1,4,2,6,5,4,0,6,9,0,8,4,6,0,9,2,1,7,5};
    int b[] = { 2,3,1,1,4 };
    vector<int> nums(begin(b),end(b));
    Solution s;
    cout << s.jump(nums) << endl;
    return 0;
}*/