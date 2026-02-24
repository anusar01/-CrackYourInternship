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
    void rRl(TreeNode* root){
        if(root){
            rRl(root->right);
            sum+=root->val;
            root->val=sum;
            rRl(root->left);
        }
    }
    //all node in sorted order
    //right root left

    TreeNode* bstToGst(TreeNode* root) {
        //for every node find put thr sum of its parent and parents rightand itself
        rRl(root);
        return root;
    }
};