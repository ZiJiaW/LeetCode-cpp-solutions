/*
Problem 32: 最长有效括号串的长度
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        int length = 0, max_length = 0, last = -1;
        stack<int> q;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                q.push(i);
            }
            else
            {
                if (q.empty())
                    last = i;
                else
                {
                    q.pop();
                    if (q.empty())
                    {
                        max_length = max_length < i - last ? i - last : max_length;
                    }
                    else
                        max_length = max_length < i - q.top() ? i - q.top() : max_length;
                }
            }
        }
        return max_length;
    }
};
/*
int main()
{
    string s;
    cin >> s;
    Solution ss;
    cout << ss.longestValidParentheses(s) << endl;
    return 0;
}*/