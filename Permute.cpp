// 46. 全排列（无重复元素）

#include <vector>
using namespace std;

class Permute
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        backtrack(res, nums, 0, nums.size());
        return res;
    }

    void backtrack(vector<vector<int>> &res, vector<int>& output, int first, int length ){
        if(first == length){
            res.emplace_back(output);
            return;
        }

        for (int i = first; i < length; i++)
        {
            swap(output[i], output[first]);
            backtrack(res, output, first + 1, length);
            swap(output[i], output[first]);
        }
        
    }
};