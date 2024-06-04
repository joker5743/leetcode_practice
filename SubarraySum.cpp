// 560. 和为k的子数组

#include<vector>
#include<unordered_map>
using namespace std;

class SubarraySum{
    public:
        // 方法一：暴力枚举
        int subarraySum_1(vector<int>& nums, int k) {
            int res = 0;
            for(int i = 0; i < nums.size(); i++){
                int sum = 0;
                for(int j = i; j < nums.size(); j++){
                    sum += nums[j];
                    if(sum == k) res++;
                }
            }
            return res;
        }

        // 方法二：前缀和优化
        int subarraySum_2(vector<int>& nums, int k) {
            unordered_map<int, int> mp;
            mp[0] = 1;
            int count = 0, pre = 0;
            for (auto &x : nums)
            {
                pre += x;
                if(mp.find(pre - k) != mp.end()){
                    count += mp[pre - k];
                }
                mp[pre]++;
            }
            return count;
        }
};