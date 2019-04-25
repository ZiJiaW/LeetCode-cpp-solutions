#include "all.h"
using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bool bits[32];
        for (int i = 0; i < 32; ++i)
            bits[i] = 0;
        int index = 0;
        while (n)
        {
            bits[index++] = n % 2;
            n /= 2;
        }
        unsigned int r = 0;
        for (int i = 0; i < 32; ++i)
        {
            r = 2 * r + bits[i];
        }
        return r;
    }
};

//int main()
//{
//    cout << Solution().reverseBits(8);
//    return 0;
//}