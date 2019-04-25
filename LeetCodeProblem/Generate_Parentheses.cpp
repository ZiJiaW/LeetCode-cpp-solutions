#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
/* LeetCode Problem 22 ************
生成n个括号的所有有效不重复排列，例如：
n=2, [(()), ()()]
**********************************/
struct block {
    string s;
    int sum;
    int count;
    block(string s = "", int sum = 0, int count = 0) : s(s), sum(sum), count(count) {};
};
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n == 0) return result;
        queue<block> q;
        q.push(block("(", 1, 1));
        while (!q.empty())
        {
            block curs = q.front();
            q.pop();
            if (curs.sum > 0)
            {
                q.push(block(curs.s + ")", curs.sum - 1, curs.count));
                if (curs.count < n)
                    q.push(block(curs.s + "(", curs.sum + 1, curs.count + 1));
            }
            else if (curs.s.length() == 2 * n)
            {
                result.push_back(curs.s);
            }
            else
            {
                q.push(block(curs.s + "(", curs.sum + 1, curs.count + 1));
            }
        }
        return result;
    }
};
/*
int main()
{
    Solution s;
    int n;
    cin >> n;
    vector<string> r = s.generateParenthesis(n);
    for (auto c : r)
    {
        cout << c << endl;
    }
    return 0;
}*/