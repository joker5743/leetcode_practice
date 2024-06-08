// 662. 二叉树最大宽度

#include<functional>
#include<vector>
#include<utility>
#include<unordered_map>
#include"data_structure.h"

class WidthOfBinaryTree{
public:
// 1.bfs
    int widthOfBinaryTree_bfs(TreeNode* root) {
        unsigned long long res = 1;
        vector<pair<TreeNode*, unsigned long long>> arr;
        arr.emplace_back(root, 1LL);
        while (!arr.empty())
        {
            vector<pair<TreeNode *, unsigned long long>> temp;
            for (auto &[node, index] : arr)
            {
                if(node->left)
                    temp.emplace_back(node->left, index * 2);
                if(node->right)
                    temp.emplace_back(node->right, index * 2 + 1);
            }
            res = max(res, arr.back().second - arr[0].second + 1);
            arr = std::move(temp);
        }
        return res;
    }

// 2.dfs
    using ULL = unsigned long long;
    int widthOfBinaryTree_dfs(TreeNode* root) {
        unordered_map<int, ULL> levelmin;
        function<ULL(TreeNode*, int, ULL)> dfs = [&](TreeNode* node, int depth, ULL index) -> ULL{
            if(node == nullptr)
                return 0;
            if(!levelmin.count(depth)){
                levelmin[depth] = index;
            }
            return max(static_cast<ULL>(index - levelmin[depth] + 1), max(dfs(node->left, depth + 1, index * 2), dfs(node->right, depth + 1, index * 2 + 1)));
        };
        return dfs(root, 1, 1);
    }
};