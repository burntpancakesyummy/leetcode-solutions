/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Check if the length of the first string is greater than the second string
        if (s1.size() > s2.size()) {
            return false;
        }

        // Create an array to store the count of each character in the first string
        vector<int> s1CharCount(26, 0);

        // Iterate over the first string and update the count array
        for (char c : s1) {
            s1CharCount[c - 'a']++;
        }

        // Iterate over the second string
        for (int i = 0; i <= s2.size() - s1.size(); ++i) {
            // Create an array to store the count of each character in the second string
            vector<int> s2CharCount(26, 0);
            
            // Count the characters in the second string
            for (int j = 0; j < s1.size(); ++j) {
                s2CharCount[s2[i + j] - 'a']++;
            }

            // If the counts are equal, return true
            if (s1CharCount == s2CharCount) {
                return true;
            }
        }

        // If no permutation found, return false
        return false;
    }
};
// @lc code=end

int main() {
    Solution s;

    vector<pair<string, string>> test_cases = {
        {"ab", "eidbaooo"},
        {"ab", "eidboaoo"},
        {"a", "ab"},
        {"abcdxabcde", "abcdeabcdx"},
        {"prosperity", "properties"}
    };

    for (auto& [s1, s2] : test_cases) {
        cout << s.checkInclusion(s1, s2) << endl;
    }

    return 0;
}