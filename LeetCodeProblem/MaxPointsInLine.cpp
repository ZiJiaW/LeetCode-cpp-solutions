#include "all.h"
using namespace std;
//149
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() < 3) return points.size();
        unordered_map<double, int> count;
        int maxCount = 0;
        for (int i = 0; i < points.size() - 1; ++i) {
            count.clear();
            int sameAsI = 0;
            int thisCount = 1;
            for (int j = i + 1; j < points.size(); ++j) {
                double slope = 0;
                if (points[i].x == points[j].x) {
                    if (points[i].y == points[j].y) {
                        sameAsI++;
                        continue;
                    }
                    slope = numeric_limits<double>::infinity();
                }
                else {
                    slope = 1.0 * (points[j].y - points[i].y) / (points[j].x - points[i].x);
                }
                if (count.find(slope) != count.end()) {
                    count[slope]++;
                }
                else {
                    count[slope] = 2;
                }
                thisCount = max(thisCount, count[slope]);
            }
            maxCount = max(maxCount, thisCount + sameAsI);
        }
        return maxCount;
    }
};
/*
int main() {
    cout << Solution().maxPoints(vector<Point>({ Point(1,1),Point(94911151,94911152),Point(94911150,94911151)})) << endl;
}*/