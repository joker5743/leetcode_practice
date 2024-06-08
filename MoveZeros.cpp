// 283. 移动零

#include<vector>
using namespace std;

class MoveZeros{
    public:
        void movezeros(vector<int> &nums){
            int n = nums.size();
            int l = 0, r = 0;
            while (r < n)
            {
                if(nums[r]){
                    swap(nums[l], nums[r]);
                    l++;
                }
                r++;
            }
        }
};