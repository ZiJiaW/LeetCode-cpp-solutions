#include "all.h"
using namespace std;

class TrieNode {
public:
    string word;
    TrieNode() {
        for (int i = 0; i < 26; ++i)
        {
            kids[i] = nullptr;
        }
        word = "";
    }

    bool containsKey(char ch)
    {
        return kids[ch - 'a'] != nullptr;
    }

    void put(char ch, TrieNode* node)
    {
        kids[ch - 'a'] = node;
    }

    TrieNode* get(char ch)
    {
        return kids[ch - 'a'];
    }
private:
    TrieNode* kids[26];
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        delete root;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for (auto ch : word)
        {
            if (!node->containsKey(ch))
            {
                node->put(ch, new TrieNode());
            }
            node = node->get(ch);
        }
        node->word = word;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto node = searchPrefix(word);
        return node != nullptr&&node->word != "";
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto node = searchPrefix(prefix);
        return node != nullptr;
    }

    /** Returns the node at the end of the prefix. */
    TrieNode* searchPrefix(string word)
    {
        TrieNode* node = root;
        for (auto ch : word)
        {
            if (node->containsKey(ch))
                node = node->get(ch);
            else
                return nullptr;
        }
        return node;
    }

    TrieNode* getRoot()
    {
        return root;
    }

private:
    TrieNode *root;
};

class Solution {
public:
    TrieNode* search(string word, TrieNode* node)
    {
        for (auto ch : word)
        {
            if (node->containsKey(ch))
                node = node->get(ch);
            else
                return nullptr;
        }
        return node;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> results;
        if (board.empty() || board[0].empty()) return results;
        int m = board.size(), n = board.begin()->size();
        Trie tree = Trie();
        for (string word : words)
            tree.insert(word);
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                dfs(tree.getRoot(), board, i, j, results);
            }
        }
        return results;
    }
private:
    void dfs(TrieNode* node, vector<vector<char>>& board, int i, int j, vector<string>& results)
    {
        if (board[i][j] == '#') return;
        char c = board[i][j];
        if (!node->containsKey(c)) return;
        auto next = node->get(c);
        if (next->word != "")
        {
            results.push_back(next->word);
            next->word = "";
        }

        board[i][j] = '#';
        if (i > 0)
            dfs(next, board, i - 1, j, results);
        if (j > 0)
            dfs(next, board, i, j - 1, results);
        if (i < board.size() - 1)
            dfs(next, board, i + 1, j, results);
        if (j < board.begin()->size() - 1)
            dfs(next, board, i, j + 1, results);
        board[i][j] = c;
    }
};
//
//int main()
//{
//    auto r = Solution().findWords(vector<vector<char>>({
//        vector<char>({'o','a','a','n'}),
//        vector<char>({'e','t','a','e'}),
//        vector<char>({'i','h','k','r'}),
//        vector<char>({'i','f','l','v'}),
//        }), vector<string>({ "oath","pea","eat","rain", "aaaa" }));
//
//    for (auto s : r)
//    {
//        cout << s << ' ';
//    }
//    return 0;
//}