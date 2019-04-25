#include <iostream>
#include <vector>
#include <string>
using namespace std;
//79
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), len = word.length();
        int n = m == 0 ? 0 : board[0].size();
        if (m == 0 || n == 0) return word.empty();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dfs(board, visited, i, j, 0, word))
                    return true;
            }
        }
        return false;
    }
private:
    bool dfs(const vector<vector<char>>& board,
            vector<vector<bool>>& visited,
            int i, int j, int index, const string& word)
    {
        if (visited[i][j] || board[i][j] != word[index]) return false;
        if (index == word.length() - 1) return true;
        bool t = false;
        visited[i][j] = true;
        if (i > 0 && dfs(board, visited, i - 1, j, index + 1, word) ||
            j > 0 && dfs(board, visited, i, j - 1, index + 1, word) ||
            i < board.size() - 1 && dfs(board, visited, i + 1, j, index + 1, word) ||
            j < board[0].size() - 1 && dfs(board, visited, i, j + 1, index + 1, word))
            t = true;
        visited[i][j] = false;
        return t;
    }
};
/*
int main()
{
    vector<vector<char>> board({ {'A', 'B','C','E'},{'S','F','C','S'},{'A','D','E','E'} });
    cout << Solution().exist(board, "ABCCED");
    return 0;
}*/