/*

All Elements in Two Binary Search Trees

Given two binary search trees root1 and root2.

Return a list containing all the integers from both trees sorted in ascending order.


Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]

Example 2:

Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
Output: [-10,0,0,1,2,5,7,10]

Example 3:

Input: root1 = [], root2 = [5,1,7,0,2]
Output: [0,1,2,5,7]

Example 4:

Input: root1 = [0,-10,10], root2 = []
Output: [-10,0,10]

Example 5:
*/
class Solution {
public:
    vector<int>give(TreeNode* root){
        vector<int>res;
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty()){
            auto curr=s.top();
            s.pop();
            if(curr){
                res.push_back(curr->val);
                s.push(curr->left);
                s.push(curr->right);
            }
        }
        return res;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>res;
        vector<int>t1=give(root1);
        vector<int>t2=give(root2);
        sort(t1.begin(),t1.end());
        sort(t2.begin(),t2.end());
        move(t1.begin(), t1.end(), back_inserter(res));
	    move(t2.begin(), t2.end(), back_inserter(res));
        sort(res.begin(),res.end());
        return res;
    }
};