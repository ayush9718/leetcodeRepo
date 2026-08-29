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
    unordered_map<TreeNode*,TreeNode*> parent;
    void dfs(TreeNode* root, TreeNode* prnt){
        if(root == NULL){
            return ;
        }
        parent[root] = prnt;
        
        dfs(root->left,root);    
        dfs(root->right,root);
    }
    unordered_map<TreeNode*, bool> visited;
    vector<int> ans;

    void dfs2(TreeNode* root, int k){
        if(root == NULL || visited[root] == true){
            return ;
        }
        if(k == 0 && root!= NULL){
            ans.push_back(root->val);
            return ;
        }

        visited[root] = true;

       
        dfs2(root->left, k-1);
        dfs2(root->right,k-1);
        dfs2(parent[root],k-1);

        visited[root] = false;

        return ;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root,NULL);

        // now i have parent of every node
        // now apply dfs again and do something like burning tree
        dfs2(target,k);

        return ans;
    }
};