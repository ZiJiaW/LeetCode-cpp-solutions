#include "all.h"
using namespace std;
// 140
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<bool>> exist(s.size(), vector<bool>(s.size(), false));
        vector<bool> f(s.size(), false);
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                exist[j][i] = find(wordDict.begin(), wordDict.end(), s.substr(j, i - j + 1)) != wordDict.end();
                f[i] = f[i] | (j >= 1 ? (f[j - 1] && exist[j][i]) : exist[0][i]);
            }
        }
        vector<string> result;
        if (!f[s.size() - 1]) return result;
        getResult(exist, result, 0, "", s);
        return result;
    }
private:
    void getResult(vector<vector<bool>>& exist, vector<string>& result, int cur, string tmp, string s) {
        if (cur == s.size()) {
            tmp.erase(tmp.begin());
            result.push_back(tmp);
            return;
        }
        for (int i = cur; i < s.size(); ++i) {
            if (exist[cur][i]) {
                getResult(exist, result, i + 1, tmp + " " + s.substr(cur, i - cur + 1), s);
            }
        }
    }
};

//int main()
//{
//    vector<string> br = Solution().wordBreak("catsanddo", vector<string>({ "cat", "cats", "and", "sand", "dog", "catsanddog" }));
//    copy(br.begin(), br.end(), ostream_iterator<string>(cout,"\n"));
//    return 0;
//}