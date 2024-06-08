// 73. 矩阵置零

#include<vector>
using namespace std;

class SetZeroes{
    public:
        // 方法一：针对行列添加标记数组，记录原始数据中含有0的位置。
        void setZeroes_1(vector<vector<int>>& matrix){
            int m = matrix.size();
            int n = matrix[0].size();
            vector<bool> row(m, false);
            vector<bool> col(n, false);
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(matrix[i][j] == 0){
                        row[i] = true;
                        col[j] = true;
                    }
                }
            }
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(row[i] || col[j]){
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        // 方法二：用两个变量代替两个标记向量
        void setZeroes_2(vector<vector<int>>& matrix){
            int m = matrix.size();
            int n = matrix[0].size();
            bool flag_col0 = false, flag_row0 = false;
            for(int i = 0; i < m; i++){
                if(!matrix[i][0]){
                    flag_col0 = true;
                }
            }
            for (int i = 0; i < n; i++)
            {
                if(!matrix[0][i]){
                    flag_row0 = true;
                }
            }
            
            for(int i = 1; i < m; i++){
                for(int j =1; j< n; j++){
                    if(!matrix[i][j]){
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }

            for(int i = 1; i < m; i++){
                for(int j =1; j< n; j++){
                    if(!matrix[i][0] || !matrix[0][j]){
                        matrix[i][j] = 0;
                    }
                }
            }

            if(flag_col0){
                for (int i = 0; i < m; i++)
                {
                    matrix[i][0] = 0;
                }
            }
            if(flag_row0){
                for (int j = 0; j < n; j++)
                {
                    matrix[0][j] = 0;
                }
            }
        }

        // 方法三：基于二的更激进优化。
        void setZeroes_3(vector<vector<int>>& matrix){
            int m = matrix.size();
            int n = matrix[0].size();
        }
};