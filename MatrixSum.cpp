// 2679. 矩阵中的和

#include<queue>
#include<vector>
#include<algorithm>
using namespace std;


class MatrixSum{
public:
  // 1. 模拟 + 优先队列抉择最大值
  int matrixSumWithPriorityQueue(vector<vector<int>>& nums){
    int res = 0;
    int m = nums.size();
    int n = nums[0].size();
    vector<priority_queue<int>> pq(m);

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        pq[i].emplace(nums[i][j]);
      }
    }

    for (int j = 0; j < n; j++)
    {
      int maxVal = 0;
      for (int i = 0; i < m; i++)
      {
        maxVal = max(maxVal, pq[i].top());
        pq[i].pop();
      }
      res += maxVal;
    }
    return res;
  }

  // 2. 排序
  int matrixSumWithSort(vector<vector<int>>& nums){
    int res = 0;
    int m = nums.size();
    int n = nums[0].size();

    for (int i = 0; i < m; i++)
    {
      sort(nums[i].begin(), nums[i].end());
    }

    for (int j = 0; j < n; j++)
    {
      int maxVal = 0;
      for (int i = 0; i < m; i++)
      {
        maxVal = max(maxVal, nums[i][j]);
      }
      res += maxVal;
    }
    return res;
  }
};