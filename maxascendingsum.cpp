// 1800. 最大升序子数组和
#include<vector>
using namespace std;

class MaxAscendingSum{
public:
    int maxAscendingSum(vector<int> &nums){
        int res = 0;
        int l = 0;
        while (l < nums.size())
        {
            int curSum = nums[l++];
            while (l < nums.size() && nums[l] > nums[l-1])
            {
                curSum += nums[l++];
            }
            res = max(res, curSum);
        }
        return res;
    }
};