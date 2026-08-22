/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

   string serialize(TreeNode* root) {
        if(root == NULL) {
            return "#";
        }


        string left = serialize(root->left);
        string right = serialize(root->right);

        string ans = to_string(root->val) + " " + left + " " + right;
        return ans;
    }


    TreeNode* deserializeHelper(string& data, int& index) {

    while(index< data.size()&& data[index] == ' '){
        index++;
    }

    string val;

    while(index< data.size() && data[index] != ' ') {
        val += data[index];
        index++;
    }

    if (val == "#") {
        return NULL;
    }

    TreeNode* node = new TreeNode(stoi(val));

    node->left = deserializeHelper(data, index);
    node->right = deserializeHelper(data, index);

    return node;
}

TreeNode* deserialize(string data) {
    int index = 0;
    return deserializeHelper(data, index);
}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));