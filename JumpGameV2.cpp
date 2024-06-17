// 45. 跳跃游戏II

#include <vector>
using namespace std;

class JumpGameV2
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        int end = 0;
        int maxpos = 0;
        int steps = 0;

        for (int i = 0; i < n - 1; i++)
        {
            maxpos = max(maxpos, nums[i] + i);
            if (i == end)
            {
                end = maxpos;
                steps++;
            }
        }
        return steps;
    }
};