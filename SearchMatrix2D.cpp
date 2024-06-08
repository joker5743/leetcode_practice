// 240. 搜索二维矩阵

#include<vector>
#include<algorithm>
using namespace std;

class SearchMatrix2D
{
    public:
        // 方法一：逐个遍历
        bool searchMatrix_1(vector<vector<int>>& matrix, int target) {
            for (const auto row : matrix)
            {
                for(const auto elem: row){
                    if (elem == target)
                        return true;
                }
            }
            return false;
        }

        // 方法二：每一行使用二分搜索
        bool searchMatrix_2(vector<vector<int>>& matrix, int target) {
            for(const auto row : matrix){
                auto it = lower_bound(row.begin(), row.end(), target);
                if(it != row.end() && *it == target){
                    return true;
                }
            }
            return false;
        }

        // 方法三：选择右上角作为起始查询点，根据单调性不断收缩左右边界，类似于二叉搜索树
        bool searchMatrix_3(vector<vector<int>>& matrix, int target) {
            int m = matrix.size(), n = matrix[0].size();
            int x = 0, y = n - 1;
            while(x < m && y >= 0){
                if(matrix[x][y] == target)
                    return true;
                
                if(matrix[x][y] > target){
                    --y;
                }
                else{
                    ++x;
                }
            }
            return false;
        }
};
