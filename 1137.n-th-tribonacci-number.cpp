/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        int prev1 = 0, prev2 = 1, prev3 = 1, curr;

        for (int i = 3; i <= n; i++) {
            curr = prev1 + prev2 + prev3;
            prev1 = prev2;
            prev2 = prev3;
            prev3 = curr;
        }

        return prev3;
    }
};
// @lc code=end

int main() {
    Solution s;

    for (int n = 0; n <= 37; n++) {
        cout << "T(" << n << ") = " << s.tribonacci(n) << endl;
    }

    return 0;
}