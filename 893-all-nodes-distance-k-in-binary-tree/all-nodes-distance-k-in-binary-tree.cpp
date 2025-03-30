/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //parent map
        //dist of node
        //visited
        queue<TreeNode*> q;
        map<TreeNode*,TreeNode*> parentNode;
        q.push(root);
        parentNode[root]=NULL;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left){
                q.push(curr->left);
                parentNode[curr->left]=curr;
            }
            if(curr->right){
                q.push(curr->right);
                parentNode[curr->right]=curr;
            }
        }
        queue<pair<TreeNode*,int>> node_hd;
        map<TreeNode*,bool> visited;
        vector<int> result;
        node_hd.push({target,0});
        visited[target]=true;
        while(!node_hd.empty()){
            TreeNode* curr=node_hd.front().first;
            int dist=node_hd.front().second;
            node_hd.pop();
            if(dist==k){
                result.push_back(curr->val);
            }
            if(dist>k){
                break;
            }
            if(curr->left && !visited[curr->left]){
                node_hd.push({curr->left,dist+1});
                visited[curr->left]=true;
            }
            if(curr->right && !visited[curr->right]){
                node_hd.push({curr->right,dist+1});
                visited[curr->right]=true;
            }
            if(parentNode[curr] && !visited[parentNode[curr]]){
                node_hd.push({parentNode[curr],dist+1});
                visited[parentNode[curr]]=true;
            }
        }
        return result;
    }
};