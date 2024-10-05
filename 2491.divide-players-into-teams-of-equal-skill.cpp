/*
 * @lc app=leetcode id=2491 lang=cpp
 *
 * [2491] Divide Players Into Teams of Equal Skill
 */

#include <iostream>
#include <vector>
#include <numeric>  // For accumulate()
#include <algorithm>  // For sort()
#include <cmath>  // For sqrt()

using namespace std;

// @lc code=start
class Solution {

public:
    long long dividePlayers(vector<int>& skill) {
        // Sort the skill vector
        sort(skill.begin(), skill.end());

        // Keep track of chemistry for each team
        long long chemistry = 0;

        // Calculate the team skill from the first and last players
        long long team_skill = skill[0] + skill[skill.size() - 1];

        // Make an iterator loop and erase if a team is found that matches the team skill
        for (int i = 0; i < skill.size() / 2; ++i) {
            long long current_skill = skill[i] + skill[skill.size() - 1 - i];

            // If the current skill point does not equals the team skill
            if (current_skill != team_skill) {
                return -1;  // If a team cannot be formed, return -1
            }

            // Calculate the chemistry for the current team
            chemistry += (long long)skill[i] * (long long)skill[skill.size() - 1 - i];
        }

        return chemistry;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<vector<int>> skills = {
        {3,2,5,1,3,4},
        {3,4},
        {1,1,2,3},
        {2,1,5,2}
    };
    for (auto& skill : skills) {
        cout << solution.dividePlayers(skill) << endl;
    }
    return 0;
}