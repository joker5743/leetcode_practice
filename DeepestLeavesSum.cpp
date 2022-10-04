// 1302. 层数最深叶子节点的和
#include"data_structure.cpp"
#include<queue>

class DeepestLeavesSum
{
private:
    int maxlevel = -1;
    int sum = 0;
public:
//1. 深度优先
    int deepestLeavesSum_dfs(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }

    void dfs(TreeNode *root, int level){
        if(root == nullptr)
            return;

        if(level > maxlevel){
            maxlevel = level;
            sum = root->val;
        }
        else if(level == maxlevel){
            sum += root->val;
        }
        else{

        }

        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }

    // 2.广度优先/层次遍历
    int deepestLeavesSum_bfs(TreeNode* root) {
        int sum = 0;
        std::queue<TreeNode *> qe;
        qe.emplace(root);

        while (!qe.empty())
        {
            sum = 0;
            int size = qe.size();
            for (size_t i = 0; i < size; i++)
            {
                TreeNode *node = qe.front();
                qe.pop();
                sum += node->val;
                if(node->left != nullptr)
                    qe.emplace(node->left);
                if (node->right != nullptr)
                    qe.emplace(node->right);
            }           
        }
        return sum;
    }
};


