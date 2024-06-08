// 230. 二叉搜索树第k小的元素

#include"data_structure.h"
#include<stack>

class KthSmallest{
    public:
        int kthSmallest(TreeNode* root, int k) {
            stack<TreeNode*> s;
            TreeNode* cur = root;
            while(cur || s.size() > 0){
                while(cur){
                    s.push(cur);
                    cur = cur->left;
                }
                cur = s.top();
                s.pop();
                --k;
                if(k == 0)
                    break;
                cur = cur->right;
            }
            return cur->val;
        }
};