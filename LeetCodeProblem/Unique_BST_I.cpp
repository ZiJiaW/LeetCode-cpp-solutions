#include <iostream>
#include <vector>
using namespace std;
// 96
class Solution {
public:
    int numTrees(int n) {
        if (n <= 1) return 1;
        auto f = new int[n + 1]();
        f[0] = 1, f[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            for (int k = 0; k <= i - 1; ++k)
            {
                f[i] += f[k] * f[i - k - 1];
            }
        }
        return f[n];
    }
};
/*
int main()
{
    cout << Solution().numTrees(3);
    return 0;
}*/