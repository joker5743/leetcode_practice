// 常用数据结构定义
#ifndef DATA_STRUCTURE
#define DATA_STRUCTURE

// 二叉树
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0),left(nullptr),right(nullptr){}
    TreeNode(int x): val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x),left(left),right(right){}
};

// 单链表
struct ListNode{
    int value;
    ListNode *next;
    ListNode(): value(0), next(nullptr){}
    ListNode(int x): value(x), next(nullptr){}
    ListNode(int x, ListNode *next): value(x), next(next){}
};

// 双向链表
struct ListNode_Doubleforward{
    int value;
    ListNode_Doubleforward *next;
    ListNode_Doubleforward *prev;
};

#endif