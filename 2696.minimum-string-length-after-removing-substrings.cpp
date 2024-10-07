/*
 * @lc app=leetcode id=2696 lang=cpp
 *
 * [2696] Minimum String Length After Removing Substrings
 * 
 * 1541/1541 cases passed (12 ms)
 * Your runtime beats 15.77 % of cpp submissions
 * Your memory usage beats 99.28 % of cpp submissions (9.8 MB)
 */

#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

// @lc code=start
class Solution {
public:
    int minLength(string s) {
        // Create some variables to store the indices of "AB" and "CD"
        size_t ab, cd = string::npos;
        
        // Remove "AB" and "CD" from the string in a loop until no more occurrences are found
        do {
            // Find and remove "AB"
            ab = s.find("AB");
            if (ab != string::npos) s.erase(ab, 2);
            
            // Find and remove "CD"
            cd = s.find("CD");
            if (cd != string::npos) s.erase(cd, 2);
        } while (ab != string::npos || cd != string::npos);

        // Return the length of the remaining string
        return s.length();
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