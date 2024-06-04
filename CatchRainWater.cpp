// 42. 接雨水

#include<vector>
#include<stack>
using namespace std;

class CatchRainWater{
    public:
        // 方法一：动态规划，扫描每一个位置左右两侧的最大高度。
        int trap_1(vector<int>& height) {
            int n = height.size();
            if(n == 0) return 0;

            vector<int> leftMax(n);
            leftMax[0] = height[0];
            for (int i = 1; i < n; i++)
            {
                leftMax[i] = max(leftMax[i - 1], height[i]);
            }
            
            vector<int> rightMax(n);
            rightMax[n - 1] = height[n - 1];
            for (int i = n - 2; i >= 0; i--){
                rightMax[i] = max(rightMax[i + 1], height[i]);
            }

            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                ans += min(leftMax[i], rightMax[i]) - height[i];
            }
            return ans;
        }

        // 方法二：单调栈。从左往右遍历并存入栈中，针对两侧高中间低的区间进行计算雨水量。
        int trap_2(vector<int>& height) {
            int ans = 0;
            stack<int> stk;
            int n = height.size();
            for(int i = 0; i < n; i++){
                while (!stk.empty() && height[i] > height[stk.top()])
                {
                    // i指向的是容纳雨水的右边柱子，此时栈顶指向的是容纳雨水的凹陷位置
                    int top = stk.top();
                    stk.pop();
                    if(stk.empty()) break;
                    // 此时栈顶指向的是容纳雨水的左边柱子
                    int left = stk.top();
                    int distance = i - left - 1;
                    int bounded_height = min(height[i], height[left]) - height[top];
                    ans += distance * bounded_height;
                }
                stk.push(i);
            }
            return ans;
        }

        // 方法三：双指针。本质上是对方法一的动态规划的进一步优化，减少了空间复杂度
        /**
        可算看懂了，原来双指针同时开两个柱子接水。大家题解没说清楚，害得我也没看懂。 对于每一个柱子接的水，那么它能接的水=min(左右两边最高柱子）-当前柱子高度，这个公式没有问题。同样的，两根柱子要一起求接水，同样要知道它们左右两边最大值的较小值。
        问题就在这，假设两柱子分别为 i，j。那么就有 iLeftMax,iRightMax,jLeftMx,jRightMax 这个变量。由于 j>i ，故 jLeftMax>=iLeftMax，iRigthMax>=jRightMax.
        那么，如果 iLeftMax>jRightMax，则必有 jLeftMax >= jRightMax，所有我们能接 j 点的水。
        如果 jRightMax>iLeftMax，则必有 iRightMax >= iLeftMax，所以我们能接 i 点的水。
        而上面我们实际上只用到了 iLeftMax，jRightMax 两个变量，故我们维护这两个即可。
        */
        int trap_3(vector<int>& height) {
            int ans = 0;
            int left = 0, right = height.size() - 1;
            int leftMax = 0, rightMax = 0;
            while (left < right)
            {
                leftMax = max(leftMax, height[left]);
                rightMax = max(rightMax, height[right]);
                if(height[left] < height[right]){
                    ans += leftMax - height[left];
                    left++;
                }
                else{
                    ans += rightMax - height[right];
                    right--;
                }
            }
            return ans;
        }
};