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
    bool helper(TreeNode* root,long long max,long long min){
        if(!root) return true;
        if(root->val>=max||root->val<=min) return false;
        return helper(root->left,root->val,min)&&helper(root->right,max,root->val);
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return helper(root->left,root->val,(long long)INT_MIN-1)&&helper(root->right,(long long)INT_MAX+1,root->val);
    }
};