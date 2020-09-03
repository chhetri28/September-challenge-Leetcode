// Repeated Substring Pattern
/*
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

 

Example 1:

Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.

Example 2:

Input: "aba"
Output: False

Example 3:

Input: "abcabcabcabc"
Output: True
Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)


Solution explained

s = "abab"
s+s = "abababab"

On removing the first and the last characters, we get:
(s+s).substr(1, 2*s.size()-2) = "bababa"

This new string, "bababa" still contains the original string, "abab".
Thus there exists some repeated pattern in the original string itself.

s = "aba"
s+s = "abaaba"

On removing the first and the last characters, we get:
(s+s).substr(1, 2*s.size()-2) = "baab"

This new string, "baab" does not contain the original string, "aba".
This implies that there does not exist any pattern in the original string itself.

https://leetcode.com/problems/repeated-substring-pattern/discuss/826135/C%2B%2B-O(N)-time-or-One-liner-without-KMP-Explained-or-Beats-99

*/
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).substr(1, 2*s.size()-2).find(s) != -1;
    }
};