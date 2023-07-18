// 870. 优势洗牌
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

class AdvantageCount{
public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2){
        int n = nums1.size();
        vector<int>idx1(n), idx2(n);
        iota(idx1.begin(), idx1.end(), 0);
        iota(idx2.begin(), idx2.end(), 0);
        sort(idx1.begin(), idx1.end(), [&](int i, int j) {return nums1[i] < nums1[j];});
        sort(idx2.begin(), idx2.end(), [&](int i, int j) {return nums2[i] < nums2[j];});

        vector<int> ans(n);
        int left = 0, right = n -1;
        for (int i = 0; i < n; i++)
        {
            // 选择比其大的最小数(升序排序实现)，若不存在这样的数字，则选择候选集合中的最小值（right指向最大的值与其配对）
            //田忌赛马
            if (nums1[idx1[i]] > nums2[idx2[left]])
            {
                ans[idx2[left]] = nums1[idx1[i]];       //己方能胜过对方的群体中，能力最弱的与对方配对
                left++;
            }
            else{
                ans[idx2[right]] = nums1[idx1[i]];      //己方最次与对方最优配对
                right--;
            }
        }
        return ans;
    }
};