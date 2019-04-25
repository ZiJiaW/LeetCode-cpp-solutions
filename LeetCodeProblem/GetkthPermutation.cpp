#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
LeetCode 60
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        vector<int> candidate;
        for (int i = 1; i <= 9; ++i)
            candidate.push_back(i);
        int mod = k - 1;
        for (int i = 1; i <= n; ++i)
        {
            int div = fact(n - i);
            int less_count = mod / div;
            result += char('0' + candidate[less_count]);
            candidate.erase(candidate.begin() + less_count);
            mod %= div;
        }
        return result;
    }
    int fact(int n)
    {
        int ret = 1;
        for (int i = 1; i <= n; ++i)
        {
            ret *= i;
        }
        return ret;
    }
};
/*
int main()
{
    Solution s;
    cout << s.getPermutation(3, 4);
    return 0;
}*/