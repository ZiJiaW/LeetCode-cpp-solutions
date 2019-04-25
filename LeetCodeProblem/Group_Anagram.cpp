#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, int> index_map;
        for (string s : strs)
        {
            int count[26] = { 0 };
            string key;
            for (char c : s)
                count[c - 'a']++;
            for (int i = 0; i < 26; ++i)
                if (count[i] != 0)
                    key.append(string(1, char(i + 'a')) + char(count[i] - '0'));
            if (index_map.find(key) == index_map.end())
            {
                result.push_back(vector<string>(1, s));
                index_map[key] = result.size() - 1;
            }
            else
            {
                result[index_map[key]].push_back(s);
            }
        }
        return result;
    }
};
/*
int main()
{
    vector<string> strs({ "eat", "tea", "tan", "ate", "nat", "bat", "aasd", "saad", "aaabb" });
    Solution s;
    vector<vector<string>> r = s.groupAnagrams(strs);
    for (auto i : r)
    {
        copy(i.begin(), i.end(), ostream_iterator<string>(cout, " "));
        cout << endl;
    }
    return 0;
}*/