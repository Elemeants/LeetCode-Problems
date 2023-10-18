//
// 146. LRU Cache
//
#pragma once

#include <map>
#include <queue>

template <typename T>
class _LRUCache {
 private:
  std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache;
  std::list<int> deque;
  const int capacity;

 public:
  _LRUCache(int capacity): capacity(capacity) { }

  T get(int key) {
    if (cache.count(key) == 0) {
      return -1;
    }
    auto& node = cache[key];
    deque.erase(node.second);
    deque.push_front(key);
    node.second = deque.begin();
    return node.first;
  }

  void put(int key, T value) {
    if (cache.size() >= capacity && cache.count(key) == 0) {
      int e = deque.back();
      deque.pop_back();
      cache.erase(e);
    }
    if (cache.count(key) > 0) {
      deque.erase(cache[key].second);
    }
    deque.push_front(key);
    cache[key] = std::make_pair(value, deque.begin());
  }

  void printQueue() {
    for (const int i : deque) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
};

using LRUCache = _LRUCache<int>;
