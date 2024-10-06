/*
 * @lc app=leetcode id=1813 lang=cpp
 *
 * [1813] Sentence Similarity III
 */

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <sstream>

using namespace std;

/*
    Case 1: The shorter_string is at the beginning of the longer_str.
    Case 2: The shorter_string is at the end of the longer_str.
    Case 3: There is insertion in the middle of the shorter_string, which makes it become longer_string.

    138/138 cases passed (0 ms)
    runtime beats 100 % of cpp submissions
    memory usage beats 35.48 % of cpp submissions (8.7 MB)
 */

// @lc code=start
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // Check if the sentences are the same
        if (sentence1 == sentence2) return true;
        
        // Create string streams and vectors to store words
        vector<string> shorterSentence, longerSentence;
        stringstream ss1(sentence1), ss2(sentence2);

        // Extract words from the string streams
        string word;

        if (sentence1.size() < sentence2.size()) {
            while (ss1 >> word) {
                shorterSentence.push_back(word);
            }
            while (ss2 >> word) {
                longerSentence.push_back(word);
            }
        } else {
            while (ss2 >> word) {
                shorterSentence.push_back(word);
            }
            while (ss1 >> word) {
                longerSentence.push_back(word);
            }
        }

        // Test for case 1
        bool case1 = true;
        for (pair<vector<string>::iterator, vector<string>::iterator> it(shorterSentence.begin(), longerSentence.begin()); it.first != shorterSentence.end(); ++it.first, ++it.second) {
            if (*it.first != *it.second) {
                case1 = false;
                break;
            }
        }

        // If passed, then return true
        if (case1) return true;

        // Test for case 2
        bool case2 = true;
        for (pair<vector<string>::reverse_iterator, vector<string>::reverse_iterator> it(shorterSentence.rbegin(), longerSentence.rbegin()); it.first != shorterSentence.rend(); ++it.first, ++it.second) {
            if (*it.first != *it.second) {
                case2 = false;
                break;
            }
        }

        // If passed, then return true
        if (case2) return true;

        // Test for case 3
        bool case3 = true;
        for (pair<vector<string>::iterator, vector<string>::iterator> it(shorterSentence.begin(), longerSentence.begin()); it.first != shorterSentence.end(); ++it.first, ++it.second) {
            if (*it.first != *it.second) {
                --it.first;
                for (pair<vector<string>::iterator, vector<string>::iterator> rit(shorterSentence.end() - 1, longerSentence.end() - 1); rit.first >= shorterSentence.begin(); --rit.first, --rit.second) {
                    if (it.first == rit.first) {
                        break;
                    } else if (*rit.first != *rit.second) {
                        case3 = false;
                        break;
                    }
                }
                break;
            }
        }

        // If passed, then return true
        if (case3) return true;

        return false;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<tuple<string, string, bool>> test_cases = {
        {"Hello Jane", "Hello my name is Jane", true},
        {"Frog cool", "Frogs are cool", false},
        {"My name is Haley", "My Haley", true},
        {"of", "A lot of words", false},
        {"Eating right now", "Eating", true},
        {"A a a a A A A", "A A a a a", false},
        {"A B C D B B", "A B B", true},
        {"z z z z", "zz z", false},
        {"A a a", "Aa a", false},
        {"hello racecar", "hello racecar acecar", true},
        {"hello", "hr uyello", false},
        {"DN PD", "D", false},
        {"hello world python", "python", true},
        {"hello world python", "hello", true},
        {"hello world python", "hello python", true},
        {"hello world python", "world", false},
        {"A Fluffy", "A Really Super Fluffy Cat", false},
        {"A Fluffy", "A Fluffy Cat", true},
        {"Luky", "Luc ccky", false},
        {"hello world", "hello world", true},
        {"abc def", "def", true},
        {"abc def cdi", "def ghi", false},
        {"abc def cdi", "abc", true},
        {"CwFfRo regR", "CwFfRo H regR", true},
        {"Game is ON", "Game are ON", false},
    };

    for (const auto& [s1, s2, expected_result] : test_cases) {
        bool actual_result = s.areSentencesSimilar(s1, s2);

        if (actual_result != expected_result) {
            cout << "Input: sentence1 = \"" << s1 << "\", sentence2 = \"" << s2 << "\"" << endl <<
                "Output: " << (actual_result ? "true" : "false") << endl << 
                "Expected: " << (expected_result ? "true" : "false") << endl <<
                endl;
        }
    }
}