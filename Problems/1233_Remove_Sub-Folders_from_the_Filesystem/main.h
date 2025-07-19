//
// 1233. Remove Sub-Folders from the Filesystem
//
#pragma once

//
// So a quick brute force solution I think of is to.
// Iterate over the vector and for the root folders.
// check if it starts with some value on the valid folders.
// Well this is tricky because I should also check if some of the previous values
// are now sub-folder from the file system.
//
// So maybe I could order them by the number of `/`, so I can order by nested level.
//
// This would be an entry in our look-up tree.
//
//   /a -> /b -> /c
//
// then if we find /a/b/ca, then we should look like
//   /a -> /b -> /ca
//
// And since no leaf was found, we registry that in our tree. that now looks like
//
//   /a -> /b -> /c (saved)
//            -> /ca (saved)
//
// Now we found /a/b/c/a, now we should:
//   /a -> /b -> /c (saved) (If found a saved node then break and ignore that entry)
//
//
// So basically the algorithm would be like
// 1. Iterate over the folders.
//    1.1 For each folder do: /<entry>/<leaf>
//    1.2 And save it in the trie tree
//    1.3 during the trie navigation we found a saved node, then we can determine
//        that it is a sub-folder.
// 2. Retrieve all the saved nodes in the tree.
// 3. Return them.
//
// I do belive that since we are ordering them fist we should not find
// a case where we found a sub-folder of a saved node, because that could complicate the 
// solution, so I'll consider that it should work.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <map>

typedef struct Node {
public:
  std::map<std::string, struct Node*> children;
  std::string folder_name;
  bool saved;

  struct Node* upsertNode(std::string folder_name) {
    if (this->children.count(folder_name) == 0) {
      // If folder name found
      Node* new_node = new Node();
      new_node->folder_name = folder_name;
      this->children[folder_name] = new_node;
      return new_node;
    } else {
      return this->children.at(folder_name);
    }
  }
} Node;

class Solution {
 public:
  std::vector<std::string> removeSubfolders(std::vector<std::string>& folders) {
    Node* base = new Node();

    for (size_t idx = 0; idx < folders.size(); idx ++) {
      const std::string folder = folders[idx];
      size_t ch_folder_name_st = 1;
      Node* nav = base;
      bool found_sub_folder = false;

      for (size_t ch_idx = 2; ch_idx < folder.size(); ch_idx ++) {
        const char ch = folder[ch_idx];
        if (ch != '/') {
          continue;
        }

        // folder name is the string in between ch_folder_name_st and ch_idx
        const std::string folder_name = folder.substr(0, ch_idx);
        nav = nav->upsertNode(folder_name);
        if (nav->saved) {
          found_sub_folder = true;
          break;
        }

        ch_folder_name_st = ch_idx + 1;
      }

      if (found_sub_folder) {
        continue;
      }

      const std::string folder_name = folder.substr(0, folder.size());
      nav = nav->upsertNode(folder_name);
      nav->saved = true;
    }

    std::vector<std::string> unique_folders;
    std::queue<Node*> queue;
    queue.push(base);
    while(!queue.empty()) {
      Node* node = queue.front(); queue.pop();
      
      if (node->saved) {
        unique_folders.push_back(node->folder_name);
        continue;
      }

      for (auto it = node->children.begin(); it != node->children.end(); ++it) {
        queue.push(it->second);
      }
    }
    return unique_folders;
  }
};
