//
// 33. Search in Rotated Sorted Array
//
#pragma once

#include <vector>
#include <iostream>

class Solution
{
  template <typename Callback>
  int binarySearchFirstConditionByCallback(int left, int right, Callback callback)
  {
    while (left <= right)
    {
      const int mid = left + ((right - left) / 2);

      if (callback(mid))
      {
        right = mid - 1;
      }
      else
      {
        left = mid + 1;
      }
    }
    return right + 1;
  }

  int binarySearch(const std::vector<int> &nums, int target, int left, int right)
  {
    while (left + 1 < right)
    {
      const int mid = left + (right - left) / 2;
      // std::cout << " mid " << mid << " v " << nums[mid];
      if (nums[mid] == target)
      {
        // std::cout << " found " << std::endl;
        return mid;
      }
      else if (nums[mid] < target)
      {
        // std::cout << " left " << std::endl;
        left = mid;
      }
      else
      {
        // std::cout << " right " << std::endl;
        right = mid;
      }
    }

    if (nums[left] == target)
      return left;
    if (nums[right] == target)
      return right;
    return -1;
  }

public:
  int search(std::vector<int> &nums, int target)
  {
    const int nums_size = nums.size();
    if (nums_size == 1)
    {
      return nums[0] == target ? 0 : -1;
    }

    int pivotIndex = binarySearchFirstConditionByCallback(0, nums_size - 1, [&](int mid) -> bool
                                                          { return nums[mid] < nums[nums.size() - 1]; });

    // std::cout << " pivotIndex: " << pivotIndex << std::endl;

    int result = binarySearch(nums, target, 0, std::max(pivotIndex - 1, 0));
    // std::cout << " left search: " << result << std::endl;
    if (result == -1)
    {
      result = binarySearch(nums, target, std::min(pivotIndex, nums_size - 1), nums_size - 1);
      // std::cout << " right search: " << result << std::endl;
    }

    return result;
  }
};