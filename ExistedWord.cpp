// 79. 单词搜索

#include <vector>
#include <string>
using namespace std;

class ExistedWord
{
public:
    bool exist_1(vector<vector<char>> &board, string word)
    {
        
    }

    bool exist_2(vector<vector<char>> &board, string word)
    {
        int row = board.size();
        int col = board[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if(backtrack_2(board, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }

    bool backtrack_2(vector<vector<char>> &board, string &word, int x, int y, int k)
    {
        if (k == word.size())
            return true;

        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] == '\0' || board[x][y] != word[k])
        {
            return false;
        }

        char temp = board[x][y];
        board[x][y] = '\0'; // 回溯中的覆盖当前元素操作
        if (backtrack_2(board, word, x + 1, y, k + 1) || backtrack_2(board, word, x - 1, y, k + 1) ||
            backtrack_2(board, word, x, y + 1, k + 1) || backtrack_2(board, word, x, y - 1, k + 1))
        {
            return true;
        }
        board[x][y] = temp;
        return false;
    }
};