// 658. 找到 K 个最接近的元素

#include<vector>
#include<algorithm>
using namespace std;

class FindClosestElements
{
public:
// 1.直接排序
    vector<int> findClosestElements_1(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [x](int a, int b) -> bool{
            return abs(a-x) < abs(b-x) || abs(a-x) == abs(b-x) && a < b;
        });

        sort(arr.begin(), arr.begin() + k);
        return vector<int>(arr.begin(), arr.begin() + k);
    }

// 2.二分查找 + 双指针
    vector<int> findClosestElements_1(vector<int>& arr, int k, int x) {
        int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = right - 1;
        while (k--)
        {
            if(left < 0)
                right++;
            else if(right >= arr.size())
                left--;
            else if(x - arr[left] <= arr[right] - x)
                left--;
            else
                right--;
        }
        return vector<int>(arr.begin() + left + 1, arr.begin() + right);
    }
};