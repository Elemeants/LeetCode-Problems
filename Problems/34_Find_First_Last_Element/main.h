//
// 34. Find First and Last Position of Element in Sorted Array
//
#pragma once

#include <vector>
#include <iostream>

class Solution
{
  template <typename Callback>
  int binarySearch(int left, int right, Callback callback)
  {
    while (left <= right)
    {
      int mid = ((right - left) / 2) + left;

      if (callback(mid))
      {
        right = mid - 1;
      }
      else
      {
        left = mid + 1;
      }
    }
    return right;
  }

  template <typename Callback>
  int binarySearch(int left, int right, Callback callback)
  {
    while (left <= right)
    {
      int mid = ((right - left) / 2) + left;

      if (callback(mid))
      {
        right = mid - 1;
      }
      else
      {
        left = mid + 1;
      }
    }
    return right;
  }

  int midSearch(std::vector<int> &nums, int target, int left, int right)
  {
    while (left <= right)
    {
      int mid = ((right - left) / 2) + left;

      if (nums[mid] == target)
      {
        return mid;
      }
      else if (nums[mid] > target)
      {
        right = mid - 1;
      }
      else if (nums[mid] < target)
      {
        left = mid + 1;
      }
    }
    return -1;
  }

public:
  std::vector<int> searchRange(std::vector<int> &nums, int target)
  {
    std::vector<int> result = {-1, -1};
    const int nums_size = nums.size();
    if (nums_size == 0)
    {
      return result;
    }

    int mid = midSearch(nums, target, 0, nums_size - 1);

    if (mid == -1)
    {
      return result;
    }

    int left = binarySearch(0, mid, [&](int mid) -> bool
                            { return nums[mid] == target; }) + 1;


    int right = binarySearch(mid, nums_size - 1, [&](int mid) -> bool
                             { return nums[mid] != target; });

    result[0] = left;
    result[1] = right;

    return result;
  }
};