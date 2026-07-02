/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum=INT_MIN;
    int Solve(TreeNode* root){
        if(root==NULL) return 0;
        int left=max(0,Solve(root->left));
        int right=max(0,Solve(root->right));
        maxSum=max(maxSum,left+right+root->val);
        return root->val+max(left,right); 
    }
    int maxPathSum(TreeNode* root) {
        Solve(root);
        return maxSum;
    }
};