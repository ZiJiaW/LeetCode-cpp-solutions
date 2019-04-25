#include <iostream>
#include <vector>
#include <bitset>
#include <iterator>
#include <algorithm>
//89
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1, 0);
        if (n == 0) return result;
        bitset<32> tmp;
        while (!tmp.test(n - 1) || tmp.count() != 1)
        {
            if (tmp.count() % 2 == 0)
                tmp.flip(0);
            else
            {
                int i = 0;
                while (!tmp.test(i++));
                tmp.flip(i);
            }
            result.push_back(tmp.to_ulong());
        }
        return result;
    }
};
/**
int main()
{
    auto r = Solution().grayCode(0);
    copy(r.begin(), r.end(), ostream_iterator<int>(cout, " "));
    return 0;
}*/