/*
 * @lc app=leetcode id=1590 lang=cpp
 *
 * [1590] Make Sum Divisible by P
 */

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        // Calculate the sum of all elements in the array
        int totalSum = 0;
        for (int num : nums) {
            totalSum = (totalSum + num) % p;
        }

        // Store the target sum that needs to be added to make the sum divisible by p
        int target = totalSum % p;

        // Check if the total sum is already divisible by p
        if (target == 0) {
            return 0;
        }

        // Initialize a prefix modulus map
        unordered_map<int, int> prefixModulusMap;
        prefixModulusMap[0] = -1;

        // Initialize the current sum and the minimum length
        int currentSum = 0, minLength = nums.size();

        // Iterate over the array and update the current sum and the prefix modulus map
        for (int i = 0; i < nums.size(); ++i) {
            // Update the current sum with the current element and modulus p
            currentSum = (currentSum + nums[i]) % p;

            // Calculate the difference between the current sum and the target sum
            int needed = (currentSum - target + p) % p;

            // If the difference is found in the prefix modulus map, update the minimum length
            if (prefixModulusMap.find(needed) != prefixModulusMap.end()) {
                // Calculate the length of the subarray
                minLength = min(minLength, i - prefixModulusMap[needed]);
            }

            // Store the current remainder and its index in the prefix modulus map
            prefixModulusMap[currentSum] = i;
        }

        // Return -1 if no subarray is found that satisfies the condition
        if (minLength == nums.size()) {
            return -1;
        }
        // Otherwise, return the minimum length
        return minLength;
    }
};
// @lc code=end

// Helper function to join a vector of integers into a string
string join(const vector<int>& nums, const string& delimiter) {
    string result;

    // Join the elements of the vector into a string with the specified delimiter
    for (size_t i = 0; i < nums.size(); ++i) {
        result += to_string(nums[i]);

        // Add the delimiter between elements except for the last one
        if (i < nums.size() - 1) {
            result += delimiter;
        }
    }
    return result;
}

int main() {
    // Setup test cases
    Solution solution;
    vector<tuple<vector<int>, int, int>> testCases = {
        {{3, 1, 4, 2}, 6, 1},
        {{6, 3, 5, 2}, 9, 2},
        {{1, 2, 3}, 3, 0},
    };

    // Run the solution with the test cases and print the results
    for (auto& [nums, p, expectedOutput] : testCases) {
        int actualOutput = solution.minSubarray(nums, p);

        // Print the results if the actual output does not match the expected output
        if (actualOutput != expectedOutput) {
            cout
                << "Input: nums = [" << join(nums, ", ") << "], p = " << p << endl
                << "Output: " << actualOutput << endl
                << "Expected: " << expectedOutput << endl
                << endl;
        }
    }
}