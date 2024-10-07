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
 * 
 * Approach 3: In Place Modification (with indexes)
 * 1541/1541 cases passed (6 ms)
 * Your runtime beats 57.32 % of cpp submissions
 * Your memory usage beats 93.92 % of cpp submissions (10 MB)
 * 
 * Approach 3: In Place Modification (with iterators)
 * 1541/1541 cases passed (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 93.92 % of cpp submissions (10.1 MB)
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
        auto writePtr = s.begin();

        // Iterate over each character in the string
        for (auto readPtr = s.begin(); readPtr != s.end(); ++readPtr) {
            // Write the current character to the write position
            *writePtr = *readPtr;

            // Check if we have a valid pattern to remove
            if (
                writePtr > s.begin() &&
                ((*writePtr - 1) == 'A' || (*writePtr - 1) == 'C') &&
                *writePtr == *(writePtr - 1) + 1
            ) {
                --writePtr;
            } else {
                ++writePtr; // No match, so move the write pointer forward
            }
        }

        // Calculate the length of the remaining string
        return static_cast<int>(writePtr - s.begin());
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