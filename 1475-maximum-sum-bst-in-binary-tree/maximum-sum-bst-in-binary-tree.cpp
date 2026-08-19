class Solution {
public:

    struct Info {
        bool isBST;
        int minVal;
        int maxVal;
        int sum;
    };

    int ans = 0;

    Info solve(TreeNode* root) {

        if (root == NULL) {
            return {true,INT_MAX,INT_MIN,0};
        }

        Info left = solve(root->left);
        Info right = solve(root->right);

        if (left.isBST && right.isBST &&
            left.maxVal < root->val && root->val < right.minVal){

            int sum = left.sum + right.sum + root->val;
            ans = max(ans, sum);

            return { true, min(left.minVal, root->val), max(right.maxVal, root->val), sum };
        }

        return { false, INT_MIN, INT_MAX, 0 };
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};