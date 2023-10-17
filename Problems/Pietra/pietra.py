import sys
import heapq

class Solution:
  def shortestDistance(self, maze: list[list[int]], start: list[int], dest: list[int]) -> int:
    n = len(maze)
    m = len(maze[0])

    dist = [[1e7] * n for _ in range(m)]
    dist[start[0]][start[1]] = 0

    priorityQueue = [(0, start[0], start[1])]
    visited = set()

    directions = [(0,1), (0,-1), (1,0), (-1,0)]

    while priorityQueue: # is not len == 0?
      currentDistance, x, y = heapq.heappop(priorityQueue)
      visited.add(x,y)

      for dir in directions:
        newX = x
        newY = y
        newDistance = 0

        while 0 <= newX + dir[0] < m and 0 <= newY + dir[1] < n and maze[newX + dir[0]][newY + dir[1]] == 0:
          newX += dir[0]
          newY += dir[1]
          newDistance += 1

        if (newX, newY) not in visited and currentDistance + newDistance < dist[newX][newY]:
          heapq.heappush(priorityQueue, (currentDistance + newDistance, newX, newY))
          dist[newX][newY] = currentDistance + newDistance

    return dist[dest[0]][dest[1]] if dist[dest[0]][dest[1]] < 1e7 else -1
