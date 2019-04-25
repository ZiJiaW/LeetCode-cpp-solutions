#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

/*
int main()
{
    int n, k, d;
    cin >> n;
    vector<ll> a(n, 0);
    for (auto i = a.begin(); i != a.end(); ++i)
    {
        cin >> *i;
    }
    cin >> k >> d;
    vector<vector<ll>> MAX(n, vector<ll>(k, 0));
    vector<vector<ll>> MIN(n, vector<ll>(k, 0));
    ll result = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i && j < k; ++j)
        {
            if (j == 0 || i == 0)
            {
                MAX[i][j] = a[i];
                MIN[i][j] = a[i];
            }
            else if (a[i] >= 0)
            {
                for (int k = 1; i - k >= j - 1 && k <= d; ++k)
                {
                    MAX[i][j] = max(MAX[i][j], MAX[i - k][j - 1] * a[i]);
                    MIN[i][j] = min(MIN[i][j], MIN[i - k][j - 1] * a[i]);
                }
            }
            else
            {
                for (int k = 1; i - k >= j - 1 && k <= d; ++k)
                {
                    MAX[i][j] = max(MAX[i][j], MIN[i - k][j - 1] * a[i]);
                    MIN[i][j] = min(MIN[i][j], MAX[i - k][j - 1] * a[i]);
                }
            }
        }
    }
    for (int i = k - 1; i < n; ++i)
        result = max(result, MAX[i][k - 1]);
    cout << result << endl;
    return 0;
}

*/