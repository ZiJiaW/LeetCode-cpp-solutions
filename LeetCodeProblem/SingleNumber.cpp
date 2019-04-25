#include "all.h"
using namespace std;
// 137
/*
idea: using two ints to count the corresponding bits, find the single one by moding 3.
two  one  in  ntwo none
0    0    0    0    0
0    1    0    0    1
1    0    0    1    0
0    0    1    0    1
0    1    1    1    0
0    1    1    1    0
1    0    1    0    0
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;
        for (int i : nums) {
            int tone = (~i & one & ~two) | (~two & ~one & i);
            two = (~i & two & ~one) | (~two & one & i);
            one = tone;
        }
        return one;
    }
};

//int main() {
//    cout << Solution().singleNumber(vector<int>({ 1,3,1,1 })) << endl;
//    return 0;
//}