#include "all.h"
using namespace std;

/*
https://leetcode.com/problems/expression-add-operators/
Input: num = "123", target = 6
Output: ["1+2+3", "1*2*3"]
+-*
*/
#define ll long long

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        tar = target;
        if (num.empty()) return res;
        dfs(num, vector<ll>(), "", 0, "");
        return res;
    }

private:
    vector<string> res;
    int tar;
    void dfs(string cur, vector<ll> nums, string ops, int index, string remain)
    {
        if (index != cur.size() - 1 && cur[index] != '0')
            dfs(cur, nums, ops, index + 1, remain + cur[index]);// nothing
        // +-*
        auto s = remain + cur[index];
        auto pre = string(10 - s.length(), '0');
        if (pre + s > "2147483647") return;
        int num2 = stoi(s);
        if (!ops.empty() && ops.back() == '*')
        {
            ops.pop_back();
            auto num1 = nums.back();
            nums.pop_back();
            nums.push_back(num1*num2);
        }
        else nums.push_back(num2);
        if (index == cur.size() - 1)
        {
            int i = 0;
            auto r = nums[i++];
            for (auto op : ops)
            {
                if (op == '+') r += nums[i++];
                else r -= nums[i++];
            }
            //cout << cur << " = " << r << endl;
            if (r == tar) res.push_back(cur);
            return;
        }
        cur.insert(index + 1, "+");
        ops.append("+");
        dfs(cur, nums, ops, index + 2, "");
        *ops.rbegin() = '-';
        cur[index + 1] = '-';
        dfs(cur, nums, ops, index + 2, "");
        *ops.rbegin() = '*';
        cur[index + 1] = '*';
        dfs(cur, nums, ops, index + 2, "");
    }
};

//int main()
//{
//    //cout << (string("909191") > string("092345"));
//    auto r = Solution().addOperators("123456789", 6);
//    cout << "-------------------------\n";
//    copy(r.begin(), r.end(), ostream_iterator<string>(cout, "\n"));
//}