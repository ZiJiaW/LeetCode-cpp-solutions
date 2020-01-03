#include "all.h"
using namespace std;


// https://leetcode.com/problems/queue-reconstruction-by-height/
// 12.31 2019
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        auto n = people.size();
        if (n == 0) return vector<vector<int>>();
        vector<vector<int>> res(n, vector<int>(2, -1));
        auto cmp = [](const vector<int> &a, const vector<int> &b) -> bool {
            return a[0] < b[0] ? true :
                a[0] == b[0] && a[1] > b[1] ? true : false;
        };
        sort(people.begin(), people.end(), cmp);
        int count, index;
        for (auto p : people) {
            index = -1;
            count = 0;
            while (count <= p[1]) {
                if (res[++index][0] == -1) {
                    count++;
                }
            }
            res[index] = p;
        }
        return res;
    }
};
//
//int main() {
//    auto res = Solution().reconstructQueue(vector<vector<int>>({ {7,0},{4,4},{7,1},{5,0},{6,1},{5,2} }));
//    for(auto p:res) {
//        cout << p[0] << ", " << p[1] << "; ";
//    }
//}