// Length of Last Word
/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.

If the last word does not exist, return 0.

Note: A word is defined as a maximal substring consisting of non-space characters only.

Example:

Input: "Hello World"
Output: 5
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0;
        int tail=s.length()-1;
        while(tail>=0 and s[tail]==' ')tail--;
        while(tail>=0 and s[tail]!=' '){
            len++;
            tail--;
        }
        return len;
    }
};