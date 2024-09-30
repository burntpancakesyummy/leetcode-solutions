/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        int prev1 = 0, prev2 = 1, curr;

        for (int i = 2; i <= n; i++) {
            curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }

        return prev2;
    }
};
// @lc code=end

int main() {
    Solution s;

    for (int n = 0; n <= 30; n++) {
        cout << "F(" << n << ") = " << s.fib(n) << endl;
    }

    return 0;
}