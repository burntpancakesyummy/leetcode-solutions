/*
 * @lc app=leetcode id=2696 lang=cpp
 *
 * [2696] Minimum String Length After Removing Substrings
 * 
 * Approach 1: String Replace
 * 1541/1541 cases passed (12 ms)
 * Your runtime beats 15.77 % of cpp submissions
 * Your memory usage beats 99.28 % of cpp submissions (9.8 MB)
 * 
 * Approach 2: Stack
 * 1541/1541 cases passed (5 ms)
 * Your runtime beats 59.38 % of cpp submissions
 * Your memory usage beats 61.24 % of cpp submissions (11.6 MB)
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
    int minLength(string s) {
        stack<char> stack;

        // Iterate over each character in the input string
        for (int i = 0; i < s.size(); i++) {
            char currentChar = s[i];

            // If the stack is empty, simply push the current character
            if (stack.empty()) {
                stack.push(currentChar);
                continue;
            }

            // Check for "AB" pattern, remove the pair by popping from the stack
            if (currentChar == 'B' && stack.top() == 'A') {
                stack.pop();
            }
            // Check for "CD" pattern, remove the pair by popping from the stack
            else if (currentChar == 'D' && stack.top() == 'C') {
                stack.pop();
            }
            // Otherwise, push the current character to the stack
            else {
                stack.push(currentChar);
            }
        }

        return stack.size();
    }
};
// @lc code=end

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Setup some test cases
    vector<tuple<string, int>> test_cases = {
        {"ABFCACDB", 2},
        {"ACBBD", 5},
        {"CCADDADDDBBCDDBABACADABAABADCABDCCBDACBDBAADDABCABBCABBDDAABCBCBBCCCDBCDDDADAACBCACDDBBA", 62},
        {"DCDCBCBDACBBABDABABCCCBABCCCCCCCBDDBCDACDADABADDCDBBC", 35},
        {"BBBDCADCDACACDBBCACDACDABCBCDDADCDCACCDDBCACCDDDCCBCDBDCBDDCBCBBCCBBBAACBBB", 47},
        {"BCDDBCCCCBACCADDCBDADDCCABCCCBACAADDADCDAACABDDDDABBACBABCABCCDCABBA", 48},
        {"RZAAAACCCCCAABBDDDDDBBBBYAAAAAAACAACAACACCAAAACCACCDDBDDBBBBDDBDBBDBBDBBBBBBBMBSCACCACDBDDBDACCDDBCD", 6},
        {"DCAACCCCCCACCCAACAABBDBBDDDBDDDDDDBBDPCAACAAACAAAAAACDBBBBBBDBBBDBBDACCCAAABBBDDDAACACDBDBBCAACDBBDP", 4},
        {"AXFCCCCCACCACCCAACAACACACAACCAAABBBDDBBDBDBDBBDBBDDDBDDBDDDDDCCACDBDDCABD", 3},
        {"ACACACACACACACACACACACACACACACACACACACACACACACACACDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDB", 0},
        {"BJKDKABJ", 6},
        {"NXWEXUXLSAAACACAAAAAACDBBBBBBDBDBBBBCABLABRR", 14},
    };

    // Run the solution with the test cases and print the results
    for (const auto& [s, expected_length] : test_cases) {
        int actual_length = solution.minLength(s);

        // Only print the results if the actual length does not match the expected length
        if (actual_length != expected_length) {
            cout
                << "Input: s = \"" << s << "\"" << endl
                << "Output: " << actual_length << endl
                << "Expected: " << expected_length << endl;
        }
    }
}