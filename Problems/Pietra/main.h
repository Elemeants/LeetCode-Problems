/**
 * There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, find the shortest distance for the ball to stop at the destination. The distance is defined by the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included). If the ball cannot stop at the destination, return -1.

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.

EXAMPLE 1:

Input 1: a maze represented by a 2D array

0 0 1 0 B
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 D

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (4, 4)

Output: 12
Explanation: One shortest way is : left -> down -> left -> down -> right -> down -> right.
             The total distance is 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12.



Notes:
1. You can assume that all borders that enclose the maze are 1s
2. The maze contains at least 2 empty spaces, and both the width and height of the maze will not exceed 100 * 100
 */
#pragma once

#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <array>

using matrix2D = std::vector<std::vector<int>>;

std::pair<int, int> move(const std::pair<int, int>& original, const std::pair<int, int>& movementVector) {
  return std::make_pair(original.first + movementVector.first, original.second + movementVector.second);
}

bool canMove(const matrix2D& matrix, const std::pair<int, int>& coord) {
  bool isOutOfBounds = (coord.first < 0) || (coord.first >= matrix.size()) || (coord.second < 0) || (coord.second >= matrix[0].size());
  if (isOutOfBounds) { return false; }

  bool isWall = matrix[coord.first][coord.second] == 1;
  if (isWall) { return false; }
  return true;
}

int foundMinimalDistance(
  const matrix2D& matrix,
  std::pair<int, int> initialCoord,
  std::pair<int, int> destinationCoord
) {
  const std::array<std::pair<int, int>, 4> movements = {
    std::make_pair(-1, 0),
    std::make_pair(1, 0),
    std::make_pair(0, -1),
    std::make_pair(0, 1)
  };
  std::priority_queue<
    std::pair<int, std::pair<int, int>>,
    std::vector<std::pair<int, std::pair<int, int>>>,
    std::greater<std::pair<int, std::pair<int, int>>>> queue;
  std::set<std::pair<int, int>> visited;
  matrix2D dist;

  for (int r = 0; r < matrix.size(); r++) {
    std::vector<int> row(matrix[0].size());
    for (int c = 0; c < matrix[0].size(); c++) {
      row[c] = INT32_MAX;
    }
    dist.push_back(row);
  }
  dist[initialCoord.first][initialCoord.second] = 0;
  queue.push(std::make_pair(0, initialCoord));

  while(!queue.empty()) {
    const std::pair<int, std::pair<int, int>> node = queue.top();
    queue.pop();
    visited.insert(node.second);

    if (node.second.first == destinationCoord.first && node.second.second == destinationCoord.second) {
      return node.first;
    }

    for (const std::pair<int, int>& movement : movements) {
      std::pair<int, int> coord = node.second;
      std::pair<int, int> prevCoord;
      int movements = -1;

      while (canMove(matrix, coord)) {
        prevCoord = coord;
        coord = move(coord, movement);
        movements++;
      }

      if (
        (prevCoord.first == node.second.first && prevCoord.second == node.second.second) ||
        (visited.count(prevCoord) > 0) ||
        (movements >= dist[prevCoord.first][prevCoord.second])
      ) {
        continue;
      }

#if false
      std::cout << node.second.first << " " << node.second.second << " -> " << prevCoord.first << " " << prevCoord.second << " : " << movements + node.first << std::endl;
#endif
      queue.push(std::make_pair(movements + node.first, prevCoord));
    }
  }

  return dist[destinationCoord.first][destinationCoord.second] == INT32_MAX ? -1 : dist[destinationCoord.first][destinationCoord.second];
}
