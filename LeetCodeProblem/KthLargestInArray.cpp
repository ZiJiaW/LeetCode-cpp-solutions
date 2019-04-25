#include "all.h"
using namespace std;
//215
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() <= 3)
        {
            for (int i = 0; i < nums.size() - 1; ++i)
            {
                int j = i + 1;
                while (nums[j] > nums[j - 1] && j > 0)
                    swap(nums[j], nums[j - 1]);
            }
            return nums[k - 1];
        }
        return partition(nums, 0, nums.size() - 1, k - 1);
    }
private:
    int partition(vector<int> &nums, int p, int q, int k)
    {
        if (p == q) return nums[p];
        srand((unsigned)time(0));
        int pivot = p + rand() % (q - p + 1);
        swap(nums[pivot], nums[q]);
        int i = p;
        for (int j = p; j < q; ++j)
        {
            if (nums[j] >= nums[q])
                swap(nums[i++], nums[j]);
        }
        swap(nums[i], nums[q]);
        if (i - p == k) return nums[i];
        else if (i - p < k) return partition(nums, i + 1, q, k - i + p - 1);
        else return partition(nums, p, i - 1, k);
    }
};
/*
int main()
{
    cout << Solution().findKthLargest(vector<int>({4,-3,2,1}), 2);
    return 0;
}*/