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
    long long totalsum=0;
    long long maxproduct=-1;
    int mod=1e9+7;
    long long total(TreeNode* root){
        if(!root) return 0;
        return root->val+total(root->left)+total(root->right);
    }
    long long dfs(TreeNode* root){
        if(!root) return 0;
        long long leftsum=dfs(root->left);
        long long rightsum=dfs(root->right);
        long long subtreesum=root->val+leftsum+rightsum;
        long long product=subtreesum*(totalsum-subtreesum);
        maxproduct=max(maxproduct,product);
        return subtreesum;
    }
    int maxProduct(TreeNode* root) {
        //calculate the sum of entire tree
        //then start from the end and keep both the sum and product
        totalsum=total(root);
        dfs(root);
        return maxproduct%mod;
    }
};