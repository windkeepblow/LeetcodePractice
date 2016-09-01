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
//fast
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return isSymmetricHelper(root->left, root->right);
    }

    bool isSymmetricHelper(TreeNode* left, TreeNode* right) {
        if (left == NULL || right == NULL) return left == right;
        if (left->val != right->val) return false;
        return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
    }
};

class Solution {
//slow
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
        if (root == NULL) return res;
        stack<TreeNode*> buf;
        TreeNode* node = root;
        buf.push(node);
        while (buf.size() > 0) {
            node = buf.top();
            if (node != NULL) {
               res.push_back(node->val);
            } else {
               res.push_back(-1);
            }
            buf.pop();
            
            if (node != NULL) {
                buf.push(node->left);
                buf.push(node->right);
            }
        }
        return res;
    }

    vector<int> right_traverse(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        stack<TreeNode*> buf;
        TreeNode* node = root;
        buf.push(node);
        while (buf.size() > 0) {
            node = buf.top();
            if (node != NULL) {
               res.push_back(node->val);
            } else {
               res.push_back(-1);
            }
            buf.pop();
            
            if (node != NULL) {
                buf.push(node->right);
                buf.push(node->left);
            }
        }
        return res;
    }
};