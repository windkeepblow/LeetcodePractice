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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        if (root->left == NULL && root->right != NULL) return false;
        if (root->left != NULL && root->right == NULL) return false;
        
        vector<int> res_1 = left_traverse(root->left);
        vector<int> res_2 = right_traverse(root->right);
        if (res_1.size() != res_2.size()) return false;
        for (int i = 0; i < res_1.size(); i++) {
            if (res_1[i] != res_2[i]) return false;
        }
        
        return true;
    }
     
    vector<int> left_traverse(TreeNode* root) {
        vector<int> res;
        left_helper(res, root);
        return res;
    }

    void left_helper(vector<int>& res, TreeNode* node) {
        if (node == NULL) {
            res.push_back(-1);
            return;
        }
        left_helper(res, node->left);
        left_helper(res, node->right);
        res.push_back(node->val);
    }

    vector<int> right_traverse(TreeNode* root) {
        vector<int> res;
        right_helper(res, root);
        return res;
    }

    void right_helper(vector<int>& res, TreeNode* node) {
        if (node == NULL) {
            res.push_back(-1);
            return;
        }
        right_helper(res, node->right);
        right_helper(res, node->left);
        res.push_back(node->val);
    }

};