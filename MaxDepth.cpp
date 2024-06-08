// 104 二叉树的最大深度

#include"data_structure.h"
#include<queue>

class MaxDepth{
    public:
        // 方法一：dfs，递归方式
        int maxDepth_1(TreeNode* root) {
            if(root == NULL) return 0;
            return max(maxDepth_1(root->left), maxDepth_1(root->right)) + 1;
        }

        // 方法二：bfs，迭代
        int maxDepth_2(TreeNode* root) {
            if(root == nullptr) return 0;

            int ans = 0;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                int sz = q.size();
                while(sz > 0){
                    TreeNode* node = q.front();
                    q.pop();
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                    sz--;
                }
                ans += 1;
            }
            return ans;
        }
};