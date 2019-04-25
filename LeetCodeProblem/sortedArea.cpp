#include "all.h"
using namespace std;
/*
problem from topcoder grafix mask:
https://arena.topcoder.com/#/u/practiceCode/1416/2771/2998/1/1416
*/
class grafixMask {
public:
    vector<int> sortedAreas(vector<string> rectangles)
    {
        graph = vector<vector<int>>(400, vector<int>(600, 0));
        vector<int> res;
        for (auto s : rectangles)
        {
            auto v = split(s);
            for (int x = v[0]; x <= v[2]; ++x)
            {
                for (int y = v[1]; y <= v[3]; ++y)
                {
                    graph[x][y] = 1;
                }
            }
        }
        stack<pair<int, int>> s;
        while (hasNext())
        {
            s.push(next);
            int sum = 0;
            while (!s.empty())
            {
                int x = s.top().first, y = s.top().second;
                while (y >= 0 && graph[x][y] == 0) y--;
                s.pop();
                bool upAdd = true, downAdd = true;
                for (int col = y+1; col < 600 && graph[x][col] != 1; ++col)
                {
                    if (x != 0 && graph[x - 1][col] != 1 && upAdd)
                    {
                        s.push(pair<int, int>(x - 1, col));
                        upAdd = false;
                    }
                    if (!upAdd && x != 0 && graph[x - 1][col] == 1) upAdd = true;
                    if (x != 399 && graph[x + 1][col] != 1 && downAdd)
                    {
                        s.push(pair<int, int>(x + 1, col));
                        downAdd = false;
                    }
                    if (!downAdd && x != 399 && graph[x + 1][col] == 1) downAdd = true;
                    sum++;
                    graph[x][col] = 1;
                }
            }
            res.push_back(sum);
        }
        sort(res.begin(), res.end());
        return res;
    }
private:
    vector<vector<int>> graph;
    pair<int, int> next;
    vector<int> split(string s)
    {
        vector<int> r;
        string tmp;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] != ' ') tmp += s[i];
            if (s[i] == ' ' || i + 1 == s.length())
            {
                r.push_back(stoi(tmp));
                tmp.clear();
            }
        }
        return r;
    }
    bool hasNext()
    {
        for (int i = 0; i < 400; ++i)
        {
            for (int j = 0; j < 600; ++j)
            {
                if (graph[i][j] != 1) {
                    next = pair<int, int>(i, j);
                    return true;
                }
            }
        }
        return false;
    }
};
/*
int main()
{
    auto r = grafixMask().sortedAreas(vector<string>({ "0 20 399 20", "0 44 399 44", "0 68 399 68", "0 92 399 92", "0 116 399 116", "0 140 399 140", "0 164 399 164", "0 188 399 188", "0 212 399 212", "0 236 399 236", "0 260 399 260", "0 284 399 284", "0 308 399 308", "0 332 399 332", "0 356 399 356", "0 380 399 380", "0 404 399 404", "0 428 399 428", "0 452 399 452", "0 476 399 476", "0 500 399 500", "0 524 399 524", "0 548 399 548", "0 572 399 572", "0 596 399 596", "5 0 5 599", "21 0 21 599", "37 0 37 599", "53 0 53 599", "69 0 69 599", "85 0 85 599", "101 0 101 599", "117 0 117 599", "133 0 133 599", "149 0 149 599", "165 0 165 599", "181 0 181 599", "197 0 197 599", "213 0 213 599", "229 0 229 599", "245 0 245 599", "261 0 261 599", "277 0 277 599", "293 0 293 599", "309 0 309 599", "325 0 325 599", "341 0 341 599", "357 0 357 599", "373 0 373 599", "389 0 389 599" }));
    copy(r.begin(), r.end(), ostream_iterator<int>(cout, " "));
    return 0;
}*/