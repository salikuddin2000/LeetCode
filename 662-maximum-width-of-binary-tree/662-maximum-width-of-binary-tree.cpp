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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            long long currMin=q.front().second;
            int leftMost,rightMost;
            for(int i=0;i<size;i++){
                long long currId=q.front().second-currMin;
                TreeNode* temp=q.front().first;
                q.pop();
                if(i==0) leftMost=currId;
                if(i==size-1) rightMost=currId; 
                if(temp->left) q.push({temp->left,currId*2+1});
                if(temp->right) q.push({temp->right,currId*2+2});
            }
            ans=max(ans,rightMost-leftMost+1);            
        }
        return ans;
    }
};