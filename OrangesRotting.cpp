// 994. 腐烂的橘子

#include <vector>
#include <utility>
#include <queue>
using namespace std;

class OrangesRotting
{
public:
    int cnt;
    int dist[10][10];
    int dir_x[4] = {0, 1, 0, -1};
    int dir_y[4] = {1, 0, -1, 0};

    int orangesRotting_1(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> Q;
        memset(dist, -1, sizeof(dist)); //标记为-1，认为不是腐烂的橘子（不存在或者新鲜）
        cnt = 0;

        int n = grid.size(), m = grid[0].size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    Q.emplace(i, j);
                    dist[i][j] = 0;
                }
                else if (grid[i][j] == 1)
                {
                    cnt++;
                }
            }
        } // 统计初始时刻所有的新鲜橘子，和最开始已经腐烂的橘子。

        while (!Q.empty())
        {
            auto [r, c] = Q.front();
            Q.pop();
            for (int i = 0; i < 4; i++)
            {
                int tx = r + dir_x[i];
                int ty = c + dir_y[i];
                if (tx < 0 || tx >= m || ty < 0 || ty >= m || dist[tx][ty] == -1 || !grid[tx][ty])
                    continue;

                dist[tx][ty] = dist[r][c] + 1;
                Q.emplace(tx, ty);
                //如果被传染腐蚀的是新鲜橘子，减少新鲜橘子的计数并更新腐蚀时长。
                if (grid[tx][ty] == 1)
                {
                    cnt--;
                    ans = dist[tx][ty];
                    if (!cnt)
                    {
                        break;
                    }
                }
            }
        }
        return cnt ? -1 : ans;
    }

    //层序遍历版本，层数即腐烂的轮数/分钟数
    int orangesRotting_2(vector<vector<int>> &grid){
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> Q;
        int fresh = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(grid[i][j] == 2)
                    Q.emplace(i, j);
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }
        
        int rounds = 0;
        while(fresh > 0 && !Q.empty()){
            int nums = Q.size();
            for(int k = 0; k < nums; k++){
                auto [r, c] = Q.front();
                Q.pop();
                for(int i = 0; i < 4; i++){
                    int tx = r + dir_x[i];
                    int ty = c + dir_y[i];
                    if(tx >= 0 && tx < m && ty >= 0 && ty < n && grid[tx][ty]== 1){
                        fresh--;
                        grid[tx][ty] = 2;
                        Q.emplace(tx, ty);
                    }
                }
            }
            rounds++;
        }
        return fresh == 0 ? rounds : -1;
    }
};