// 200. 岛屿数量

#include <vector>
#include <queue>
#include <utility>
using namespace std;

class NumIslands
{
public:
    int numIslands_dfs(vector<vector<char>> &grid)
    {
        int nr = grid.size();
        if (!nr)
            return 0;
        int nc = grid[0].size();

        int num_islands = 0;
        for (int r = 0; r < nr; r++)
        {
            for (int c = 0; c < nc; c++)
            {
                if (grid[r][c] == '1')
                {
                    num_islands++;
                    dfs(grid, r, c);
                }
            }
        }
        return num_islands;
    }

    void dfs(vector<vector<char>> &grid, int r, int c)
    {
        int nr = grid.size();
        int nc = grid[0].size();

        grid[r][c] = '0'; // 标记为已访问，避免重复遍历无法停止。
        if (r - 1 >= 0 && grid[r - 1][c] == '1')
            dfs(grid, r - 1, c);
        if (r + 1 <= nr && grid[r + 1][c] == '1')
            dfs(grid, r + 1, c);
        if (c - 1 >= 0 && grid[r][c - 1] == '1')
            dfs(grid, r, c - 1);
        if (c + 1 <= nc && grid[r][c + 1] == '1')
            dfs(grid, r, c + 1);
    }

    int numIslands_bfs(vector<vector<char>> &grid)
    {
        int nr = grid.size();
        if (nr == 0)
            return 0;
        int nc = grid[0].size();

        int num_islands = 0;
        for (int r = 0; r < nr; r++)
        {
            for (int c = 0; c < nc; c++)
            {
                if (grid[r][c] == '1')
                {
                    ++num_islands;
                    grid[r][c] = '0'; // 标记为已访问
                    queue<pair<int, int>> neighbors;
                    neighbors.push({r, c});
                    while (!neighbors.empty())
                    {
                        auto rc = neighbors.front();
                        neighbors.pop();
                        int row = rc.first;
                        int col = rc.second;
                        if (row - 1 >= 0 && grid[row - 1][col] == '1')
                        {
                            neighbors.push({row - 1, col});
                            grid[row - 1][col] = '0';
                        }
                        if (row + 1 < nr && grid[row + 1][col] == '1')
                        {
                            neighbors.push({row + 1, col});
                            grid[row + 1][col] = '0';
                        }
                        if (col - 1 >= 0 && grid[row][col - 1] == '1')
                        {
                            neighbors.push({row, col - 1});
                            grid[row][col - 1] = '0';
                        }
                        if (col + 1 < nc && grid[row][col + 1] == '1')
                        {
                            neighbors.push({row, col + 1});
                            grid[row][col + 1] = '0';
                        }
                    }
                }
            }
        }
        return num_islands;
    }
};