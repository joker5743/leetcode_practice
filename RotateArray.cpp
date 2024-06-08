// 189. 轮转数组


#include<vector>
#include<numeric>
using namespace std;

class RotateArray {
public:
    // 方法一：使用额外空间，直接放置
    void rotate_1(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> newArray(n);
        for (int i = 0; i < n; i++)
        {
            newArray[(i + k) % n] = nums[i];
        }
        nums.assign(newArray.begin(), newArray.end());
    }

    // 方法二：环装替换
    void rotate_2(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int count = gcd(n, k);
        for (int start = 0; start < count; start++)
        {
            int current = start;
            int prev = nums[start];
            do{
                int next = (current + k) % n;
                swap(nums[next], prev);
                current = next;
            }while(start != current);
        }
    }

    // 方法三：多次（1次整体+2次局部）翻转数组
    void rotate_3(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }

    void reverse(vector<int>& nums, int start, int end) {
        while(start < end){
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
};