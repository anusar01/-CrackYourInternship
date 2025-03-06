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
    bool hasPathSum(TreeNode* node, int targetSum) {
        //root to leaf saare calculate kr
        if(node==nullptr){
            return false;
        }
        if(node->left==nullptr && node->right==nullptr && targetSum-node->val==0){
            return true;
        }
        targetSum-=node->val;
        return hasPathSum(node->left,targetSum)||hasPathSum(node->right,targetSum);
    }
};