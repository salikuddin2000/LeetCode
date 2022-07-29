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
    TreeNode* helper(TreeNode* root){
        if(root->left==nullptr&&root->right==nullptr){ 
            return root;
        }
        if(root->left==nullptr){
            return helper(root->right);
        }
        if(root->right==nullptr){
            root->right=root->left;
            root->left=nullptr;
            return helper(root->right);
        }
        TreeNode* left = helper(root->left);
        TreeNode* right = helper(root->right);
        left->right=root->right;
        root->right=root->left;
        root->left=nullptr;
        return right;
    }
    void flatten(TreeNode* root) {
        if(root==nullptr) return;
        else helper(root);
        return;

    }
};