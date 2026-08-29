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
    int cameras = 0;
    int solve(TreeNode* root) {

        // null nodes are covered
        if(root == NULL){
            return 1;
        }

        int left = solve(root->left);
        int right = solve(root->right);

        // if any child is not covered.. we must put a camera here.
        if(left == 0 || right == 0){
            cameras++;
            return 2;
        }

        // If any child has a camera.. this node is covered.
        if(left == 2 || right == 2){
            return 1;
        }

        return 0;
    }

    int minCameraCover(TreeNode* root) {
        cameras = 0;

        // If root itself is not covered.. we need one camera at root.
        if(solve(root) == 0){
            cameras++;
        }
        
        return cameras;
    }
};