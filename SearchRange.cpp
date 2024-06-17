// 34. 在排序数组中找到元素第一位和最后一位的位置

#include<vector>
#include<iostream>
using namespace std;

class SearchRange{
    public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIndex = findIndex(nums, target, false);
        int rightIndex = findIndex(nums, target, true) - 1;
        cout << "the left index is " << leftIndex << endl;
        cout << "the right index is " << rightIndex << endl;
        if(rightIndex < nums.size() && leftIndex <= rightIndex && nums[leftIndex] == target && nums[rightIndex] == target){
            return vector<int>{leftIndex, rightIndex};
        }
        else{
            return vector<int>{-1, -1};
        }
    }

    // 二分查找变种，关于左右边界查询，参考https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/
    int findIndex(vector<int>& nums, int target, bool right){
        int l = 0, r = nums.size();
        int ans = 0;
        while(l < r){
            int mid = l + (r - l) / 2;
            cout << "the mid is " << mid << endl;
            if(nums[mid] < target || (right && nums[mid] <=target)){
                l = mid + 1;
                ans = l;
            }
            else{
                r = mid;
            }
        }
        return ans;   
    }
};