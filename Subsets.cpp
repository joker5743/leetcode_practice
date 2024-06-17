// 78. 子集

#include <vector>
using namespace std;

class Subsets
{
public:
    vector<int> t;
    vector<vector<int>> ans;

    vector<vector<int>> subsets(vector<int> &nums)
    {
        dfs(0, nums);
        return ans;
    }

    void dfs(int cur, vector<int> &nums)
    {
        if (cur == nums.size())
        {
            ans.push_back(t);
            return;
        }

        // 选中当前元素
        t.push_back(nums[cur]);
        dfs(cur + 1, nums);
        // 跳过当前元素
        t.pop_back();
        dfs(cur + 1, nums);
    }
};