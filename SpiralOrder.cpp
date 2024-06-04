// 54. 螺旋矩阵

#include<vector>
using namespace std;

class SpiralOrder{
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix){
            vector<int> ans;
            if(matrix.empty())
                return ans;

            int u = 0;
            int d = matrix.size() - 1;
            int l = 0;
            int r = matrix[0].size() - 1;
            while (true)
            {
                // 向右遍历
                for(int i = l; i <= r; i++){
                    ans.emplace_back(matrix[u][i]);
                }
                // 调整上边界
                if(++u > d)
                    break;

                // 向下遍历
                for(int i = u; i <= d; i++){
                    ans.emplace_back(matrix[i][r]);
                }
                // 调整右边界
                if(--r < l)
                    break;

                // 向左遍历
                for(int i = r; i >= l; i--){
                    ans.emplace_back(matrix[d][i]);
                }
                // 调整下边界
                if(--d < u)
                    break;
                
                // 向上遍历
                for (int i = d; i >= u; i--)
                {
                    ans.emplace_back(matrix[i][l]);
                }
                // 调整左边界
                if(++l > r)
                    break;
            }
            return ans;
        }
};