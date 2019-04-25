#include <iostream>
#include <vector>
using namespace std;
/*
�ǹ����⣬LeetCode Problem 135.
���������ɨ��������У�������ѭ����
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 0, n = ratings.size();
        if (n == 1) return 1;
        int *p = new int[n]();
        for (int i = 0; i < n-1; ++i)
        {
            if (p[i] == 0)
                p[i] = 1;
            if (ratings[i] < ratings[i + 1])
                p[i + 1] = p[i] + 1;
            else
                continue;
        }
        for (int i = n - 1; i > 0; --i)
        {
            if (p[i] == 0)
                p[i] = 1;
            sum += p[i];
            if (ratings[i] < ratings[i - 1] && p[i - 1] < p[i] + 1)
                p[i - 1] = p[i] + 1;
            else
                continue;
        }
        sum += p[0];
        return sum;
    }
};
/*
int main()
{
    int a[2] = { 2,1 };
    vector<int> rate(a, a + 2);
    Solution s;
    cout << s.candy(rate);
    cout << endl;
    return 0;
}
*/