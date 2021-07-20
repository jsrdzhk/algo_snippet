/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-07-14 14:58:04
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-14 17:19:00
 */
#include "precompiled_headers.h"

class DoubleListNode {
   public:
    int k;
    int v;
    DoubleListNode* prev;
    DoubleListNode* next;
    DoubleListNode(int key, int val)
        : k(key), v(val), prev(nullptr), next(nullptr) {}
};

class DoubleList {
   private:
    DoubleListNode *_head, *_tail;
    std::size_t _size = 0;

   public:
    std::size_t size() { return _size; }
    void remove(DoubleListNode* node) {
        DoubleListNode* prev = node->prev;
        prev->next = node->next;
        node->next->prev = prev;
        delete node;
        node = nullptr;
        --_size;
    }

    int removeHead() {
        DoubleListNode* curHead = _head->next;
        DoubleListNode* newHead = curHead->next;
        _head->next = newHead;
        newHead->prev = _head;
        int key = curHead->k;
        delete curHead;
        curHead = nullptr;
        --_size;
        return key;
    }

    void add(DoubleListNode* node) {
        DoubleListNode* last = _tail->prev;
        last->next = node;
        _tail->prev = node;
        node->prev = last;
        node->next = _tail;
        ++_size;
    }

    void makeRecently(DoubleListNode* node) {
        // delete cur node
        DoubleListNode* prev = node->prev;
        prev->next = node->next;
        node->next->prev = prev;
        // make cur node last node
        DoubleListNode* curTail = _tail->prev;
        node->prev = curTail;
        curTail->next = node;
        _tail->prev = node;
        node->next = _tail;
    }

   public:
    DoubleList() {
        _head = new DoubleListNode(0, 0);
        _tail = new DoubleListNode(0, 0);
        _head->next = _tail;
        _tail->prev = _head;
    }

    ~DoubleList() {
        _tail->prev = nullptr;
        delete _tail;
        _tail = nullptr;
        _head->next = nullptr;
        delete _head;
        _head = nullptr;
    }
};

class LRUCache {
   private:
    DoubleList cache;
    std::unordered_map<int, DoubleListNode*> map;
    int cacheCapacity = 0;

   private:
    void add(int k, int v) {
        DoubleListNode* n = new DoubleListNode(k, v);
        cache.add(n);
        map[k] = n;
    }

    void makeRecently(int k) {
        if (map.count(k)) {
            cache.makeRecently(map[k]);
        }
    }

    void deleteLeastRecently() {
        int k = cache.removeHead();
        map.erase(k);
    }

    void deleteKey(int k) {
        DoubleListNode* n = map[k];
        cache.remove(n);
        map.erase(k);
    }

   public:
    LRUCache(int capacity) { cacheCapacity = capacity; }

    int get(int key) {
        if (map.count(key)) {
            makeRecently(key);
            return map[key]->v;
        }
        return -1;
    }

    void put(int key, int value) {
        if (map.count(key)) {
            deleteKey(key);
            add(key, value);
        } else {
            if (cache.size() >= cacheCapacity) {
                deleteLeastRecently();
            }
            add(key, value);
        }
    }
};
