// #138 随机链表的复制

#include <unordered_map>

#include "data_structure.h"
using namespace std;

class RandomListNodeCopy {
 public:
  // 方法一：回溯+哈希表
  unordered_map<Node*, Node*> cachedNode;  // 记录目前节点是否有拷贝过
  Node* randomListNodeCopy_1(Node* head) {
    if (head == nullptr) return nullptr;

    if (!cachedNode.count(head)) {
      Node* headnew = new Node(head->val);
      cachedNode[head] = headnew;
      headnew->next = randomListNodeCopy_1(head->next);
      head->random = randomListNodeCopy_1(head->random);
    }
    return cachedNode[head];
  }

  // 方法二：迭代
  Node* randomListNodeCopy_2(Node* head) {
    if (head == nullptr) return nullptr;

    // 在源链表中插入拷贝的节点
    for (Node* node = head; node != nullptr; node = node->next->next) {
      Node* nodeNew = new Node(node->val);
      nodeNew->next = node->next;
      node->next = nodeNew;
    }

    // 根据原有节点的random指针，找到拷贝节点的random指向节点，在源节点的random指向的后一个节点。
    for (Node* node = head; node != nullptr; node = node->next->next) {
      Node* nodeNew = node->next;
      nodeNew->random = node->random != nullptr ? node->random->next : nullptr;
    }

    // 拆分链表，将拷贝节点和源节点分离
    Node* headNew = head->next;
    for (Node* node = head; node != nullptr; node = node->next) {
      Node* nodeNew = node->next;
      node->next = nodeNew->next;
      nodeNew->next =
          (nodeNew->next != nullptr) ? nodeNew->next->next : nullptr;
    }
    return headNew;
  }
};