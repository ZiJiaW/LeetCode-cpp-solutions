#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        int newStart = newInterval.start;
        bool added = false, hasStart = false;
        if (intervals.empty())
        {
            result.push_back(newInterval);
            return result;
        }
        for (auto i = intervals.begin(); i != intervals.end(); ++i)
        {
            if (newInterval.start <= i->end && !hasStart)
            {
                newStart = i->start <= newInterval.start ? i->start : newInterval.start;
                hasStart = true;
            }
            if (newInterval.end <= i->end && !added)
            {
                if (newInterval.end >= i->start)
                    result.push_back(Interval(newStart, i->end));
                else
                {
                    result.push_back(Interval(newStart, newInterval.end));
                    result.push_back(*i);
                }
                added = true;
                hasStart = false;
                continue;
            }
            if (added || !hasStart)
                result.push_back(*i);
        }
        if (!added)
        {
            result.push_back(Interval(newStart, newInterval.end));
        }
        return result;
    }
};
/*
int main()
{
    Solution s;
    Interval a(1, 2), b(3,5), c(6,7),d(8,10),e(12,16),f(17,20);
    vector<Interval> is({ a,b,c,d,e });
    auto iss = s.insert(is, f);
    for (auto i : iss)
    {
        cout << i.start << ' ' << i.end << endl;
    }
    return 0;
}*/