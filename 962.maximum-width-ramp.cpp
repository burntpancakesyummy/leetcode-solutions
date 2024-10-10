/*
 * @lc app=leetcode id=962 lang=cpp
 *
 * [962] Maximum Width Ramp
 */

#include <iostream>
#include <vector>
#include <tuple>
#include <stack>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        // Initialize 'n' to the size of the 'nums' array and create an empty stack 'indicesStack'
        int n = nums.size();
        stack<int> indicesStack;

        // Iterate through the array from index 0 to 'n-1'
        for (int i = 0; i < n; ++i) {
            // If 'indicesStack' is empty or the value at the top index of the stack is greater than
            // the current value 'nums[i]', push 'i' onto the stack
            if (indicesStack.empty() || nums[indicesStack.top()] > nums[i]) {
                // This ensures the stack contains indices in increasing order of their corresponding
                // values in 'nums'
                indicesStack.push(i);
            }
        }

        // Initialize 'maxWidth' to 0
        int maxWidth = 0;

        // Iterate through the array from index 'n-1' down to 0
        for (int j = n - 1; j >= 0; --j) {
            // While the stack is not empty and the value at the index on the top of the stack is
            // less than or equal to nums[j]
            while (!indicesStack.empty() && nums[indicesStack.top()] <= nums[j]) {
                // Update 'maxWidth' to the maximum of its current value and the width calculated as
                // 'j - indicesStack.top()'
                maxWidth = max(maxWidth, j - indicesStack.top());

                // Pop the index from the stack, as it has already been processed
                indicesStack.pop();
            }
        }

        // Return 'maxWidth' as the result (the maximum width found)
        return maxWidth;
    }
};
// @lc code=end

// Helper function to join a vector of integers into a string
template <typename T>  // Template type parameter for the join function
string join(const vector<T>& nums, const string& delimiter) {
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
    // Test the solution with some static test cases
    Solution s;
    vector<tuple<vector<int>, int>> testCases = {
        {{6, 0, 8, 2, 1, 5}, 4},
        {{9, 8, 1, 0, 1, 9, 4, 0, 4, 1}, 7},
    };

    // Run through the test cases and print the results
    for (auto& [nums, expectedOutput] : testCases) {
        int actualOutput = s.maxWidthRamp(nums);

        // Print the results if the actual output does not match the expected output
        if (actualOutput != expectedOutput) {
            cout
                << "Input: nums = [" << join(nums, ",") << "]" << endl
                << "Output: " << actualOutput << endl
                << "Expected: " << expectedOutput << endl
                << endl;
        }
    }
}