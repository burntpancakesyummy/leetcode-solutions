/*
 * @lc app=leetcode id=1133 lang=cpp
 *
 * [1133] Largest Unique Number
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// @lc code=start
class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        // If there is only one number, return it
        if (nums.size() == 1) {
            return nums[0];
        }

        // Create a map to store the count of each number
        map<int, int> countMap;
        
        // Iterate over the numbers and update the count map
        for (const auto& num : nums) {
            // Count the occurrences of each number
            countMap[num]++;
        }

        // Iterate over the count map to find the largest unique number
        int largestUniqueNumber = -1;
        for (const auto& [num, count] : countMap) {
            if (count == 1 && num > largestUniqueNumber) {
                largestUniqueNumber = num;
            }
        }

        // There is no number that appears more than once, so return -1
        return largestUniqueNumber;
    }
};
// @lc code=end

int main() {
    // Setup test cases
    Solution solution;
    vector<vector<int>> numsVec = {
        {5, 7, 3, 9, 4, 9, 8, 3, 1},
        {9, 9, 8, 8}
    };

    // Run the solution with the test cases and print the results
    for (auto& nums : numsVec) {
        cout << solution.largestUniqueNumber(nums) << endl;
    }
}