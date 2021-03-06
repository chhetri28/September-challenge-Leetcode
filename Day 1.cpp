//Largest Time for Given Digits
/*
Given an array of 4 digits, return the largest 24 hour time that can be made.

The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.

Return the answer as a string of length 5.  If no valid time can be made, return an empty string.

 

Example 1:

Input: [1,2,3,4]
Output: "23:41"

Example 2:

Input: [5,5,5,5]
Output: ""


*/
class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        string ans = "";
		sort(A.begin(),A.end());
		do
		{
			if((A[0]==2 && A[1]<=3 || A[0]<2) && A[2]<=5)
			{
				string temp = to_string(A[0])+to_string(A[1])+":"
					+to_string(A[2])+to_string(A[3]);
				if(temp > ans) ans = temp;
			}       
		}while(next_permutation(A.begin(),A.end()));
		return ans;
    }
};