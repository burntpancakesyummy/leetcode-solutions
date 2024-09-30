/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;

        int prev = 1, curr = 1, temp;

        for (int i = 2; i <= n; i++) {
            temp = curr;
            curr = prev + curr;
            prev = temp;
        }

        return curr;
    }
};
// @lc code=end

int main() {
    Solution s;

    for (int n = 1; n <= 45; n++) {
        cout << "There are " << s.climbStairs(n) << " ways to climb " << n << " stairs." << endl; // Output: 3
    }

    return 0;
}