// leetcode 59

#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> generateMatrix(int n) {
    std::vector<std::vector<int>> result(n, std::vector<int>(n, 1));
    int row = 0, col = 0;
    int curNum = 1;
    for (int line = n - 1; line > 0; line -= 2) {
      for (int count = line; count != 0; count--)
        result[row][col++] = curNum++;
      for (int count = line; count != 0; count--)
        result[row++][col] = curNum++;
      for (int count = line; count != 0; count--)
        result[row][col--] = curNum++;
      for (int count = line; count != 0; count--)
        result[row--][col] = curNum++;
      // return to the origin
      row++;
      col++;
    }
    if (n % 2 == 1)
      result[n / 2][n / 2] = curNum;
    return result;
  }
};