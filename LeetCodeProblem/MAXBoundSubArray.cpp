#include "all.h"
using namespace std;//795
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int n = A.size();
        int sum = 0, left = -1, right = -1;
        for (int i = 0; i < n; ++i)
        {
            if (A[i] > R) left = i;
            if (A[i] >= L) right = i;
            sum += right - left;
        }
        return sum;
    }
};
/*
int main()
{
    cout << Solution().numSubarrayBoundedMax(vector<int>({ 73,55,36,5,55,14,9,7,72,52 }), 32, 69);
    return 0;
}*/