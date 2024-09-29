/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string str = to_string(x);
        return str == string(str.rbegin(), str.rend());
    }
};
// @lc code=end