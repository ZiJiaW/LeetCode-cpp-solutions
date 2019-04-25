#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1[0] == '0' || num2[0] == '0')
            return "0";
        int size = num1.length() + num2.length() - 1;
        int* r = new int[size]();
        string result;
        for (int i = 0; i < num1.length(); ++i)
        {
            for (int j = 0; j < num2.length(); ++j)
            {
                r[i + j] += (num1[i] - '0')*(num2[j] - '0');
            }
        }
        int carry = 0;
        for (int i = size - 1; i >= 0; --i)
        {
            result += char((r[i] + carry) % 10 + '0');
            carry = (r[i] + carry) / 10;
        }
        if(carry != 0)
            result += char((carry) % 10 + '0');
        reverse(result.begin(), result.end());
        return result;
    }
};
/*
int main()
{
    string num1, num2;
    cin >> num1 >> num2;
    Solution s;
    cout << s.multiply(num1, num2);
    return 0;
}*/