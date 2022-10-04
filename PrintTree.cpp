// 655. 输出二叉树
#include<string>
#include<vector>
#include<queue>
#include<tuple>
#include"data_structure.cpp"
using namespace std;

class PrintTree
{
public:
// 1.dfs
    vector<vector<string>> printTree_dfs(TreeNode* root) {
        int height = calDepth_dfs(root);
        int m = height + 1;
        int n = (1 << (height + 1)) - 1;
        vector<vector<string>> res(m, vector<string>(n,""));
        dfs(res, root, 0, (n-1)/2, height);
        return res;
    }

    int calDepth_dfs(TreeNode *root){
        int h = 0;
        if(root->left)
            h = max(h,calDepth_dfs(root->left) + 1);
        if(root->right)
            h = max(h, calDepth_dfs(root->right) + 1);
        return h;
    }

    void dfs(vector<vector<string>> &res, TreeNode *root, int r, int c, const int &height){
        res[r][c] = to_string(root->val);
        if(root->left)
            dfs(res, root->left, r+1, c - (1 << (height - r - 1)), height);
        if(root->right)
            dfs(res, root->right, r+1, c + (1 << (height - r - 1)), height);
    }

// 2.bfs
    vector<vector<string>> printTree_bfs(TreeNode* root) {
        int height = calDepth_bfs(root);
        int m = height + 1;
        int n = (1 << (height + 1)) - 1;
        vector<vector<string>> res(m, vector<string>(n,""));
        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, 0, (n - 1) / 2});

        while (!q.empty())
        {
            auto t = q.front();
            q.pop();
            int r = get<1>(t), c = get<2>(t);
            res[r][c] = to_string(get<0>(t)->val);
            if(get<0>(t)->left)
                q.push({get<0>(t)->left, r+1, c - (1 << (height - r - 1))});
            if(get<0>(t)->right)
                q.push({get<0>(t)->right, r+1, c + (1 << (height - r - 1))});
        }
        return res;
    }

    int calDepth_bfs(TreeNode *root){
        int res = -1;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int len = q.size();
            res++;
            while (len)
            {
                len--;
                auto t = q.front();
                q.pop();
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            
        }
        return res;
    }
};