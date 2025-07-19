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

typedef struct Node {
public:
  std::vector<struct Node*> children;
  std::string folder_name;
  bool saved;

  const std::vector<Node*>::iterator findChildNode(std::string folder_name) {
    const std::vector<Node*>::iterator it = std::find_if(this->children.begin(), this->children.end(), [&](const Node* node) -> bool {
      return std::equal(node->folder_name.begin(), node->folder_name.end(), folder_name.begin(), folder_name.end());
    });
    return it;
  }

  struct Node* upsertNode(std::string folder_name) {
    std::vector<Node*>::iterator children = findChildNode(folder_name);
    if (children == this->children.end()) {
      // If folder name found
      Node* new_node = new Node();
      new_node->folder_name = folder_name;
      this->children.push_back(new_node);
      return new_node;
    } else {
      return *children;
    }
  }
} Node;

class Solution {
  void sortByNestedLevels(std::vector<std::string>& folders) {
    std::sort(folders.begin(), folders.end(), [](const std::string& l, const std::string& r) -> int {
      std::pair<size_t, size_t> nested_level = std::make_pair(0, 0);

      for (size_t idx = 0; idx < std::max(l.size(), r.size()); idx ++) {
        const std::pair<char, char> ch = std::make_pair(l[std::min(idx, l.size())], r[std::min(idx, r.size())]);
        if (ch.first == '/') {
          nested_level.first ++;
        }
        if (ch.second == '/') {
          nested_level.second ++;
        }
      }

      return nested_level.first < nested_level.second;
    });
  }
 public:
  std::vector<std::string> removeSubfolders(std::vector<std::string>& folders) {
    sortByNestedLevels(folders);

    Node* base = new Node();
    std::vector<std::string> unique_folders;

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
        const std::string folder_name = folder.substr(ch_folder_name_st, ch_idx - ch_folder_name_st);
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

      const std::string folder_name = folder.substr(ch_folder_name_st, folder.size() - ch_folder_name_st);
      nav = nav->upsertNode(folder_name);
      nav->saved = true;
      unique_folders.push_back(folder);
    }

    return unique_folders;
  }
};
