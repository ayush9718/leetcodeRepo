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
    int ans;
    int sum(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftans = sum(root->left);
        int rightans = sum(root->right);

        int both = leftans + rightans + root->val;
        int only_one = max(leftans,rightans) + root->val;
        int no_one = root->val;

        ans = max({ans,both,only_one,no_one});
        
        return max(only_one,no_one);
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        sum(root);
        return ans;
    }
};