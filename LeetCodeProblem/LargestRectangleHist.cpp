#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
//84
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0);
        int result = 0;
        for (int i = 0; i < heights.size();)
        {
            if (s.empty() || heights[i] >= heights[s.top()])
                s.push(i++);
            else
            {
                int top = s.top();
                s.pop();
                result = max(result, heights[top] * (s.empty() ? i : i - s.top() - 1));
            }
        }
        return result;
    }
};
/*
int main()
{
    cout << Solution().largestRectangleArea(vector<int>({ 1,2,3,0,2,3 }));
    return 0;
}*/