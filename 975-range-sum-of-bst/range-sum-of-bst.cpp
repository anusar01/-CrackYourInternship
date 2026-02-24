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
    int sum=0;
    void dfs(TreeNode* node,int low,int high){
        if(node){
            if(node->val<low){
                dfs(node->right,low,high);
            }else if(node->val>high){
                dfs(node->left,low,high);
            }else{
                sum+=node->val;
                dfs(node->right,low,high);
                dfs(node->left,low,high);
            }
            
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        dfs(root,low,high);
        return sum;
    }
};