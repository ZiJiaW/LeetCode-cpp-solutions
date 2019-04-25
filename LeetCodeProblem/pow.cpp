#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (abs(n) == 1)
            return n > 0 ? x : double(1) / x;
        else if (n == 0)
            return 1;
        else
        {
            double a = myPow(x, n / 2);
            if (n % 2 == 0) return a * a;
            else return a * a * myPow(x, abs(n)/n);
        }
    }
};
/*
int main()
{
    cout << Solution().myPow(0.1, -3) << endl;
    return 0;
}*/