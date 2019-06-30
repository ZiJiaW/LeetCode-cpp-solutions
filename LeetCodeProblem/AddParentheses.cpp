#include <iostream>
#include "all.h"

//https://leetcode.com/problems/different-ways-to-add-parentheses/
//Problem NO.241 计算表达式在不同括号添加策略下的结果集，运算符包括+-*

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        char c;
        bool op = false;
        for (int i = 0; i < input.length(); ++i)
        {
            c = input[i];
            if (c == '+' || c == '-' || c == '*')
            {
                op = true;
                auto left = diffWaysToCompute(input.substr(0, i));
                auto right = diffWaysToCompute(input.substr(i + 1));
                for (int i : left)
                {
                    for (int j : right)
                    {
                        switch (c)
                        {
                        case '+':
                        {
                            res.push_back(i + j);
                            break;
                        }
                        case '-':
                        {
                            res.push_back(i - j);
                            break;
                        }
                        default:
                        {
                            res.push_back(i * j);
                            break;
                        }
                        }
                    }
                }
            }
        }
        if (!op)
        {
            res.push_back(stoi(input));
        }
        return res;
    }
};

int main()
{
    auto res = Solution().diffWaysToCompute("2-1-10*13");
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
    return 0;
}