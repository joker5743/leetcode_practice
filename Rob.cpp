// 198. 打家劫舍

#include<vector>
using namespace std;

class Rob
{
public:
    // 传统动态规划，带规划记录表
    int rob_1(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        int size = nums.size();
        if(size == 1)
            return nums[1];

        vector<int> dp(size, 0);
        dp[0] = 0;
        dp[1] = max(nums[0], nums[1]);
        for (size_t i = 2; i < size; i++)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[size - 1];
    }

    // 优化版本，常数级变量代替规划记录
    int rob_2(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        int size = nums.size();
        if(size == 1)
            return nums[0];

        int first = nums[0], second = max(nums[0], nums[1]);
        for (size_t i = 2; i < size; i++)
        {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }
};