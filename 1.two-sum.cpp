/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    for (size_t iNum1 = 0; iNum1 < nums.size(); iNum1++) {
      for (size_t iNum2 = 0; iNum2 < nums.size(); iNum2++) {
        iNum2 = iNum1 == iNum2 ? iNum2 + 1 : iNum2;  // Skip duplicate numbers.

        if (nums[iNum1] + nums[iNum2] == target) {
          return {static_cast<int>(iNum1), static_cast<int>(iNum2)};
        }
      }
    }

    return {};  // If no pair found, return an empty vector.
  }
};
// @lc code=end

int main() {
  Solution solution;
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
}