// leetcode 27

#include <iostream>
#include <vector>
class Solution {
public:
  int removeElement(std::vector<int> &nums, int val) {
    int leftPtr = 0;
    int rightPtr = nums.size() - 1;
    while (leftPtr <= rightPtr) {
      // two conditions cannot be swapped, otherwise it may cause overflow.
      while (leftPtr <= rightPtr && nums[leftPtr] != val)
        leftPtr++;
      while (leftPtr <= rightPtr && nums[rightPtr] == val)
        rightPtr--;
      if (leftPtr < rightPtr) {
        nums[leftPtr] = nums[rightPtr];
        leftPtr++;
        rightPtr--;
      }
    }
    return leftPtr;
  }
};

int main() {
  std::vector<int> nums = {1};
  Solution solve;
  int result = solve.removeElement(nums, 1);
  std::cout << result << std::endl;
  return 0;
}