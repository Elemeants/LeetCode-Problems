//
// 797. All Paths From Source to Target
//
#pragma once

#include <vector>
#include <deque>

using vector2D = std::vector<std::vector<int>>;

class Solution {
 public:
  vector2D allPathsSourceTarget(vector2D& graph) {
    vector2D result;
    std::vector<int> path;

    travelToChilds (graph, result, path, 0);

    return result;
  }

  void travelToChilds (
    vector2D& graph,
    vector2D& paths,
    std::vector<int> path,
    int node
  ) {
    path.push_back(node);
    if (node == ((int)graph.size() - 1)) {
      paths.push_back(path);
    } else {
      for (const auto& child : graph[node]) {
        travelToChilds(graph, paths, path, child);
      }
    }
    path.pop_back();
  }
};
