/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    vector<Node*> vis= std :: vector<Node*> (200);
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        Node* root= new Node(node->val);
        if(node->neighbors.empty()) return root;
        vis[node->val]=root;
        for(auto it: node->neighbors){
            if(vis[it->val]!=NULL) root->neighbors.push_back(vis[it->val]);
            else root->neighbors.push_back(cloneGraph(it));
        }
        return root;
    }
};