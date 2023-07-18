// 654. 最大二叉树
#include"data_structure.cpp"
#include<vector>
using namespace std;

class ConstructMaximumBinaryTree
{
public:
// 1.递归解法
    TreeNode* constructMaximumBinaryTree_Recursion(vector<int>& nums) {
        return construction_Recursion(nums, 0, nums.size()-1);
    }

    TreeNode *construction_Recursion(const vector<int>& nums, int left, int right){
        if(left > right)
            return nullptr;

        int best = left;
        for (int i = left + 1; i <= right; i++)
        {
            if(nums[i] > nums[best])
                best = i;
        }

        TreeNode *node = new TreeNode(nums[best]);
        node->left = construction_Recursion(nums, left, best - 1);
        node->right = construction_Recursion(nums, best + 1, right);
        return node;
    }

    // 2.单调栈
    // 2.1 完整写法
    TreeNode* constructMaximumBinaryTree_Stack1(vector<int>& nums) {
        int n = nums.size();
        vector<int> stk;
        vector<int> left(n,-1), right(n,-1);
        vector<TreeNode *> tree(n);

        for (int i = 0; i < n; i++)
        {
            tree[i] = new TreeNode(nums[i]);
            while (!stk.empty() && nums[i] > nums[stk.back()])
            {
                right[stk.back()] = i;
                stk.pop_back();
            }
            if(!stk.empty()){
                left[i] = stk.back();
            }
            stk.push_back(i);
        }

        TreeNode* root = nullptr;
        for (int i = 0; i < n; i++)
        {
            if(left[i] == -1 && right[i] == -1)
                root = tree[i];
            else if(right[i] == -1 || (left[i] == -1 && nums[left[i]] < nums[right[i]]))
                tree[left[i]]->right = tree[i];
            else
                tree[right[i]]->left = tree[i];
        }
        return root;
    }

    // 2.2 构造树过程置入单调栈中
    TreeNode* constructMaximumBinaryTree_Stack2(vector<int>& nums) {
        int n = nums.size();
        vector<int> stk;
        vector<TreeNode *> tree(n);
        for (int i = 0; i < n; i++)
        {
            tree[i] = new TreeNode(nums[i]);
            while (!stk.empty() && nums[i] > nums[stk.back()])
            {
                tree[i]->left = tree[stk.back()];
                stk.pop_back();
            }
            if(!stk.empty())
                tree[stk.back()]->right = tree[i];
            stk.push_back(i);
        }
        return tree[stk[0]];
    }
};