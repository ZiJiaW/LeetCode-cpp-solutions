//128
#include "all.h"
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> map;
        int maxLen = 0;
        for (int i : nums)
            map[i] = 1;
        for (int i : nums)
        {
            if (map[i] == 0) continue;
            int len = 1, left = i-1, right = i+1;
            while (map[left] == 1 || map[right] == 1)
            {
                if (map[left] == 1)
                {
                    map[left] = 0;
                    left--;
                    len++;
                }
                if (map[right] == 1)
                {
                    map[right] = 0;
                    right++;
                    len++;
                }
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};

//int main()
//{
//    cout << Solution().longestConsecutive(vector<int>({ 100,4,200,1,3,2 })) << endl;
//    return 0;
//}