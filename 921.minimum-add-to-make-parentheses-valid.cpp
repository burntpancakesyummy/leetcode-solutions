/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 */

#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

// @lc code=start
class Solution {
public:
    int minAddToMakeValid(string s) {
        // Initialize the count of opening parentheses
        int openBrackets = 0;
        int minAddsRequired = 0;

        // Iterate through the string to count the number of opening parentheses
        for (char c : s) {
            if (c == '(') {
                ++openBrackets;
            } else {
                openBrackets > 0 ? --openBrackets : ++minAddsRequired;
            }
        }

        // Return the minimum number of parentheses to add to make the string valid
        return minAddsRequired + openBrackets;
    }
};
// @lc code=end

int main() {
    // Test the solution
    Solution s;
    vector<tuple<string, int>> testCases = {
        {"())", 1},
        {"(((", 3},
        {"", 0},
        {"())((", 3},
        {"((", 2},
    };
}