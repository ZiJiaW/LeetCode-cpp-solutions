#include <iostream>
#include <vector>
#include <string>
using namespace std;
/**
Gas Station (Problem 134.)
转化为求数列的最大连续子序列问题，O(n)解法
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int sum = 0;
        int pos = 0;
        for (int i = 0; i < gas.size(); ++i)
        {
            total += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if (sum < 0)
            {
                pos = i + 1;
                sum = 0;
            }
        }
        return total < 0 ? -1 : pos;
    }
};