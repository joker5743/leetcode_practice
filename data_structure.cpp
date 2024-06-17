#include "data_structure.h"
// 常用数据结构定义

// 二叉树
TreeNode::TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right)
    : val(x), left(left), right(right) {}

// 单链表
ListNode::ListNode() : val(0), next(nullptr) {}
ListNode::ListNode(int x) : val(x), next(nullptr) {}
ListNode::ListNode(int x, ListNode *next) : val(x), next(next) {}

// 带有随机指针的链表
Node::Node(int _val) {
  val = _val;
  next = nullptr;
  random = nullptr;
}

DLinkedNode::DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
DLinkedNode::DLinkedNode(int _key, int _value)
    : key(_key), value(_value), prev(nullptr), next(nullptr) {}