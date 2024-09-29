/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

#include <string>
#include <map>

using namespace std;

// @lc code=start
class Solution {
private:
    map<char, int> romanToDecimal{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

public:
    int romanToInt(string s) {
        int result = 0;
        char currChar, nextChar = '\0';

        for (int i = 0; i < s.size(); i++) {
            int value = 0;
            currChar = s[i];

            if (i + 1 < s.size()) {
                nextChar = s[i + 1];
                if (
                    (currChar == 'I' && (nextChar == 'V' || nextChar == 'X')) ||
                    (currChar == 'X' && (nextChar == 'L' || nextChar == 'C')) ||
                    (currChar == 'C' && (nextChar == 'D' || nextChar == 'M'))
                 ) {
                    value = romanToDecimal[nextChar] - romanToDecimal[currChar];
                    i++;  // Skip the next character since we've already accounted for it.
                } else {
                    value = romanToDecimal[currChar];
                }
            } else {
                value = romanToDecimal[currChar];
            }

            result += value;
        }

        return result;
    }
};
// @lc code=end