// Sum of Root To Leaf Binary Numbers
/*
Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

Return the sum of these numbers.

Input: [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
*/
class Solution {
public:
    int sum;
    int sumRootToLeaf(TreeNode* root) {
        sum=0;
        helper(root,0);
        return sum;
    }
    void helper(TreeNode* root,int bin){
        if(!root)return;
        bin=bin<<1;
        if(root->val==1){
            bin++;
        }
        if(root->left==NULL and root->right==NULL){
            sum+=bin;
            return;
        }
        helper(root->left,bin);
        helper(root->right,bin);
    }
};
// another approach
 int sumRootToLeaf(TreeNode* root, int val = 0) {
        if (!root) return 0;
        val = (val * 2 + root->val);
        return root->left == root->right ? val : sumRootToLeaf(root->left, val) + sumRootToLeaf(root->right, val));
    }