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
    // TreeNode* min = new TreeNode();
    // TreeNode* max = new TreeNode();
    TreeNode *x=NULL,*y=NULL,*prev=NULL;
    void inorder(TreeNode* root){
        if(!root) return;
        if(root->left) inorder(root->left);
        if(prev&&root->val<prev->val){
            y=root;
            if(!x) x=prev;
            else return;
        }
        prev=root;
        if(root->right) inorder(root->right);
        return;
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        int temp=x->val;
        x->val=y->val;
        y->val=temp;
        return;

    }
};