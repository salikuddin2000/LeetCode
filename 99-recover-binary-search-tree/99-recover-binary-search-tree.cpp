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
    vector<TreeNode*> v;
    void inorder(TreeNode* root){
        if(!root) return;
        if(root->left) inorder(root->left);
        v.push_back(root);
        if(root->right) inorder(root->right);
        return;
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        int n=v.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(v[i]->val>=v[j]->val){
                int temp=v[i]->val;
                v[i]->val=v[j]->val;
                v[j]->val=temp;
                }
            }
        }
    }
};