#include "all.h"
using namespace std;
#define ll long long
class Solution {
public:
    int nthUglyNumber(int n)
    {
        if (n == 1) return 1;
        vector<int> s(n);
        s[0] = 1;
        int p1 = 0, p2 = 0, p3 = 0;
        for (int i = 1; i < n; ++i)
        {
            s[i] = min(2 * s[p1], min(3 * s[p2], 5 * s[p3]));
            if (s[i] == 2 * s[p1]) p1++;
            if (s[i] == 3 * s[p2]) p2++;
            if (s[i] == 5 * s[p3]) p3++;
            cout << p1 << endl;
        }
        return s[n - 1];
    }
};

//int main()
//{
//    cout << Solution().nthUglyNumber(10);
//}