// Maximum XOR of Two Numbers in an Array
/*
Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 ≤ i ≤ j < n.

Follow up: Could you do this in O(n) runtime?

 

Example 1:

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.

Example 2:

Input: nums = [0]
Output: 0

Example 3:

Input: nums = [2,4]
Output: 6

Example 4:

Input: nums = [8,10,2]
Output: 10

Example 5:

Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127

 

Constraints:

    1 <= nums.length <= 2 * 104
    0 <= nums[i] <= 231 - 1


*/
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 0 || n == 1)
            return 0;
        if (n == 2)
            return nums.at(0) ^ nums.at(1);
        
        list<int> set0;
        list<int> set1;
        int i;
        int j;
        int maxValue;
        
        for (i = 30; i >= 0; i--) {
            for (j = 0; j < n; j++) {
                if ((nums.at(j) & (1<<i)) == 0)
                    set0.push_back(nums.at(j));
                else
                    set1.push_back(nums.at(j));
            }
            
            if (set0.size() != 0 && set1.size() != 0) {
                maxValue = pow(2, i);
                break;
            }
            else {
                set0.clear();
                set1.clear();
            }
        }
        
        if (i == -1)
            return 0;
        
        maxValue += getMaxXor(set0, set1, i-1);
        
        return maxValue;
    }
    int getMaxXor(list<int>& set0, list<int>& set1, int pos) {
        int maxValue;
        list<int> set0list0;
        list<int> set0list1;
        list<int> set1list0;
        list<int> set1list1;
        int i;
        list<int>::iterator it;
        
        if (set0.size() == 0 || set1.size() == 0 || pos < 0)
            return 0;
        
        for (it = set0.begin(); it != set0.end(); it++) {
            int value = *it;
            if ((value & (1<<pos)) == 0)
                set0list0.push_back(value);
            else
                set0list1.push_back(value);
        }
        
        for (it = set1.begin(); it != set1.end(); it++) {
            int value = *it;
            if ((value & (1<<pos)) == 0)
                set1list0.push_back(value);
            else
                set1list1.push_back(value);
        }
        
        if (set0list0.size() == 0 && set1list0.size() == 0)
            maxValue = getMaxXor(set0, set1, pos-1);
        else if (set0list1.size() == 0 && set1list1.size() == 0)
            maxValue = getMaxXor(set0, set1, pos-1);
        else {
            int maxValue1 = getMaxXor(set0list0, set1list1, pos-1);
            int maxValue2 = getMaxXor(set0list1, set1list0, pos-1);
            maxValue = pow(2, pos) + (maxValue1 > maxValue2 ? maxValue1 : maxValue2);
        }
        
        return maxValue;
 }
};