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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return{};
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>> ans;
        vector<int> sub;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(!curr){
                ans.push_back(sub);
                sub.clear();
                if(!q.empty()) q.push(NULL);
            }
            else{
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                sub.push_back(curr->val);
            }
        }

        return ans;
    }
};