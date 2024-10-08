/*
 * @lc app=leetcode id=1963 lang=cpp
 *
 * [1963] Minimum Number of Swaps to Make the String Balanced
 */

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    int minSwaps(string s) {
        // Count the number of brackets
        int unbalanced = 0;

        // Count the number of brackets by iterating through the string
        for (char c : s) {
            // If the current character is an opening bracket, increment the count
            if (c == '[') {
                ++unbalanced;
            }
            // If the current character is a closing bracket and the count is greater than 0
            else if (unbalanced > 0) {
                --unbalanced;
            }
        }

        // Return the minimum number of swaps to make the string balanced
        return (unbalanced + 1) / 2;
    }
};
// @lc code=end

int main() {
    // Setup test cases
    Solution solution;
    vector<tuple<string, int>> testCases = {
        {"][][", 1},
        {"]]][[[", 2},
        {"[]", 0},
    };

    // Loop through test cases
    for (const auto& [s, expectedOutput] : testCases) {
        int actualOutput = solution.minSwaps(s);

        // Print the results if the actual output does not match the expected output
        if (actualOutput != expectedOutput) {
            cout 
                << "Input: \"" << s << "\"" << endl
                << "Output: " << actualOutput << endl
                << "Expected: " << expectedOutput << endl
                << endl;
        }
    }
}