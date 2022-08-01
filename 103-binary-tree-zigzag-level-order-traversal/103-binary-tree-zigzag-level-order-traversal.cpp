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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return{};
        bool flag=0;
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()){
            int size=q.size();
            vector<int> sub;
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                sub.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(!flag) {
                ans.push_back(sub);
                flag=!flag;
            }
            else {
                reverse(sub.begin(),sub.end());
                ans.push_back(sub);
                flag=!flag;
            }
        }
        return ans;
    }
};