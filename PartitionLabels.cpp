// 763. 划分字母区间

#include <vector>
using namespace std;

class PartitionLabels
{
public:
    // 贪心算法，记录每个字母最后出现的位置，决定划分的位置。
    vector<int> partitionLabels(string s)
    {
        int last[26];
        int length = s.size();
        for (size_t i = 0; i < length; i++)
        {
            last[s[i] - 'a'] = i;
        }

        vector<int> res;
        int start = 0, end = 0;
        for (size_t i = 0; i < length; i++)
        {
            end = max(end, last[s[i] - 'a']);
            if (i == end)
            {
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};