// 146. LRU缓存

#include <unordered_map>

#include "data_structure.h"

class LRUCache {
 private:
  unordered_map<int, DLinkedNode *> cached;
  DLinkedNode *head;
  DLinkedNode *tail;
  int size;
  int capacity;

 public:
  LRUCache(int capacity) : capacity(capacity), size(0) {
    head = new DLinkedNode();
    tail = new DLinkedNode();
    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    if (!cached.count(key)) return -1;

    DLinkedNode *node = cached[key];
    moveToHead(node);
    return node->value;
  }

  void put(int key, int value) {
    if (!cached.count(key)) {
      DLinkedNode *node = new DLinkedNode(key, value);
      cached[key] = node;
      addToHead(node);
      ++size;
      if (size > capacity) {
        DLinkedNode *removed = removeTail();
        cached.erase(removed->key);
        delete removed;
        --size;
      }
    } else {
      DLinkedNode *node = cached[key];
      node->value = value;
      moveToHead(node);
    }
  }

  void addToHead(DLinkedNode *node) {
    node->prev = head;
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
  }

  void removeNode(DLinkedNode *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void moveToHead(DLinkedNode *node) {
    removeNode(node);
    addToHead(node);
  }

  DLinkedNode *removeTail() {
    DLinkedNode *node = tail->prev;
    removeNode(node);
    return node;
  }
};