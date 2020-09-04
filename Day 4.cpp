/*
Partition Labels

A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

 

Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.

*/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>res;
        //1. Take an array for last index of every char in string
        int last_indices[26];
        for(int i=0;s[i];i++){
            last_indices[s[i]-'a']=i;
        }
        //2. take start and end for the end of the first char in string
        int start=0;
        int end=0;
        for(int i=0;s[i];i++){
            end=max(end,last_indices[s[i]-'a']);
            if(i==end){
                //3. push end-start+1 in res 
                res.push_back(end-start+1);
                start=end+1;
            }
        }
        return res;
    }   
};