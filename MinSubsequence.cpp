// 1403. 非递增顺序的最小子序列

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

class MinSubsequence{
public:
    std::vector<int> minSubsequence(std::vector<int> nums){
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end());
        int cur = 0;
        std::vector<int> ans;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            cur += nums[i];
            ans.emplace_back(nums[i]);
            if(sum - cur < cur)
                break;
        }
        return ans;
    }
};