#include "all.h"
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return vector<int>({ 1 });
        if (rowIndex == 1) return vector<int>({ 1,1 });
        vector<int> r({1});
        auto t = getRow(rowIndex - 1);
        for (auto i = t.begin(); i + 1 != t.end(); ++i) {
            r.push_back(*i + *(i + 1));
        }
        r.push_back(1);
        return r;
    }
};
//int main() {
//    auto r = Solution().getRow(9);
//    copy(r.begin(), r.end(), ostream_iterator<int>(cout, " "));
//    return 0;
//}