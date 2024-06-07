// 114. 二叉树展开为链表

#include"data_structure.h"
#include<stack>

class Flatten{
    public:
        // 方法一：前序遍历+顺序模拟
        void flatten_1(TreeNode* root) {
            vector<TreeNode*> l;
            preorderTraversal(root, l);
            int n = l.size();
            for (int i = 1; i < n; i++)
            {
                TreeNode *prev = l[i-1], *cur = l[i];
                prev->left = nullptr;
                prev->right = cur;
            }
        }

        void preorderTraversal(TreeNode* root, vector<TreeNode*> &l) {
            if(root != nullptr){
                l.push_back(root);
                preorderTraversal(root->left, l);
                preorderTraversal(root->right, l);
            }
        }

        // 方法二：迭代+展开同步进行
        void flatten_2(TreeNode* root) {
            if(root == nullptr)
                return;

            stack<TreeNode*> stk;
            stk.push(root);
            TreeNode *prev = nullptr;
            while (!stk.empty())
            {
                TreeNode *cur = stk.top();
                stk.pop();
                if(prev){
                    prev->left = nullptr;
                    prev->right = cur;
                }
                TreeNode *left = cur->left;
                TreeNode *right = cur->right;
                if(right){
                    stk.push(right);
                }
                if (left)
                {
                    stk.push(left);
                }
                prev = cur;
            }
            
        }

        // 方法三：迭代+前驱节点
        void flatten_3(TreeNode* root) {
            TreeNode *cur = root;
            while (cur)
            {
                if(cur->left){
                    TreeNode *next = cur->left;
                    TreeNode *predecessor = next;
                    while(predecessor->right){
                        predecessor = predecessor->right;
                    }
                    predecessor->right = cur->right;
                    cur->left = nullptr;
                    cur->right = next;
                }
                cur = cur->right;
            }
            
        }
};