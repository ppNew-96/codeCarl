// leetcode 209
#include <vector>

class Solution {
public:
  int minSubArrayLen(int target, std::vector<int> &nums) {
    int minSubLen = INT32_MAX;
    int numsLen = nums.size();
    int slowPtr = 0, fastPtr = 0;
    int subSum = 0;
    for (; fastPtr != numsLen; fastPtr++) {
      subSum += nums[fastPtr];
      while (subSum >= target) {
        // Closed interval on both ends here.
        minSubLen = minSubLen < fastPtr - slowPtr + 1 ? minSubLen
                                                      : fastPtr - slowPtr + 1;
        subSum -= nums[slowPtr];
        slowPtr++;
      }
    }
    return minSubLen == INT32_MAX ? 0 : minSubLen;
  }
};