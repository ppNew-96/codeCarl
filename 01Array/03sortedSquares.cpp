// leetcode 977
#include <vector>

class Solution {
public:
  std::vector<int> sortedSquares(std::vector<int> &nums) {
    int left = 0, right = nums.size() - 1;
    std::vector<int> result(right + 1, 0);
    int cur = right;
    while (cur != -1) {
      if (-nums[left] > nums[right]) {
        result[cur] = nums[left] * nums[left];
        left++;
      } else {
        result[cur] = nums[right] * nums[right];
        right--;
      }
      cur--;
    }
    return result;
  }
};