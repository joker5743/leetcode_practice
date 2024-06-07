// 94 二叉树中序遍历

#include"data_structure.h"
#include<stack>

class InorderTraversal{
    public:
        // 方法一：递归
        vector<int> inorderTraversal_1(TreeNode* root) {
            vector<int> ans;
            inorderTraversal_recursive(root, ans);
            return ans;
        }

        void inorderTraversal_recursive(TreeNode* root, vector<int> &ans){
            if(!root)
                return;

            inorderTraversal_recursive(root->left, ans);
            ans.push_back(root->val);
            inorderTraversal_recursive(root->right, ans);
        }

        // 方法二：迭代
        vector<int> inorderTraversal_2(TreeNode* root) {
            vector<int> res;
            stack<TreeNode*> s;
            while(root != nullptr || !s.empty()){
                while(root != nullptr){
                    s.push(root);
                    root = root->left;
                }
                root = s.top();
                s.pop();
                res.push_back(root->val);
                root = root->right;
            }
            return res;
        }
};