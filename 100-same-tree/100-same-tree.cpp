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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q) return true;
        else if(!p||!q) return false;
        queue<TreeNode*> v;
        v.push(p);
        v.push(q);
        while(!v.empty()){
            TreeNode* temp1=v.front();
            v.pop();
            TreeNode* temp2=v.front();
            v.pop();
            // if(!temp1&&temp2||temp1&&!temp2) return false;
            if(temp1->val!=temp2->val)return false;
            cout<<temp1->val<<","<<temp2->val<<" ";
            if(temp1->left&&temp2->left){ 
                v.push(temp1->left);
                v.push(temp2->left);
            }
            else if(!temp1->left&&!temp2->left);
            else return false;
            if(temp1->right&&temp2->right){ 
                v.push(temp1->right);
                v.push(temp2->right);
            }
            else if(!temp1->right&&!temp2->right);
            else return false;
        }
        return true;
    }
};