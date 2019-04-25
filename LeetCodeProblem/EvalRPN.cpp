#include "all.h"
using namespace std;
//150
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int b = 0, a = 0;
        for (string token : tokens) {
            if (token.size() == 1 && !isdigit(token[0])) {
                b = s.top(); s.pop();
                a = s.top(); s.pop();
                switch (token[0]) {
                case '+':
                    s.push(a + b);
                    break;
                case '-':
                    s.push(a - b);
                    break;
                case '*':
                    s.push(a * b);
                    break;
                case '/':
                    s.push(a / b);
                    break;
                }
            }
            else {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};
//int main() {
//    cout << Solution().evalRPN(vector<string>({ "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" })) << endl;
//    return 0;
//}