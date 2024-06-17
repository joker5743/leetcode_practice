// 48. 旋转图像

#include <vector>
using namespace std;

class RotateImage {
 public:
  // 方法一：利用额外数组，空间复杂度为O（N^2）
  void rotate_1(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> res(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        res[j][n - i - 1] = matrix[i][j];
      }
    }
    matrix = res;
  }

  // 方法二：旋转位置推导得出，四个位置变换是一次循环
  void rotate_2(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n / 2; i++) {
      for (int j = 0; j < (n + 1) / 2; j++) {
        int temp = matrix[i][j];
        matrix[i][j] = matrix[n - j - 1][i];
        matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
        matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
        matrix[j][n - i - 1] = temp;
      }
    }
  }

  // 方法三：通过水平翻转和主对角线翻转，实现方法一二中的逻辑推导关系。
  void rotate_3(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // 水平翻转
    for (int i = 0; i < n / 2; i++) {
      for (int j = 0; j < n; j++) {
        swap(matrix[i][j], matrix[n - i - 1][j]);
      }
    }
    // 主对角线翻转
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
  }
};