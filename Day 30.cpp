// First Missing Positive
/*
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3

Example 2:

Input: [3,4,-1,1]
Output: 2

Example 3:

Input: [7,8,9,11,12]
Output: 1

Follow up:

Your algorithm should run in O(n) time and uses constant extra space.

*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int res=0;
        int n=nums.size();
        set<int>st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(int i=1;i<=n+1;i++){
            if(st.find(i)==st.end()){
                res=i;
                break;
            }
        }
        return res;
    }
};