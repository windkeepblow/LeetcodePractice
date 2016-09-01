#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preorder_traverse(TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    preorder_traverse(root->left);
    preorder_traverse(root->right);
}

void preorder_traverse_loop(TreeNode* root) {
    if (root == NULL) return;
    stack<TreeNode*> stk;
    stk.push(root);
    while (stk.size() > 0) {
        TreeNode* node = stk.top();
        printf("%d ", node->val);
        stk.pop();
        if (node->right != NULL) stk.push(node->right);
        if (node->left != NULL) stk.push(node->left);
    } 
}

void inorder_traverse(TreeNode* root) {
    if (root == NULL) return;
    inorder_traverse(root->left);
    printf("%d ", root->val);
    inorder_traverse(root->right);
}

void inorder_traverse_loop(TreeNode* root) {
    if (root == NULL) return;
    stack<TreeNode*> stk;
    TreeNode* node = root;
    
    while (node != NULL || stk.size() > 0) {
        while (node != NULL) {
            stk.push(node);
            node = node->left;
        }
        node = stk.top();
        printf("%d ", node->val);
        stk.pop();
        node = node->right;
    }
}

void postorder_traverse(TreeNode* root) {
    if (root == NULL) return;
    postorder_traverse(root->left);
    postorder_traverse(root->right);
    printf("%d ", root->val);
}

void postorder_traverse_loop(TreeNode* root) {
    stack<int> res;
    stack<TreeNode*> buf;
    TreeNode* node = root;
    buf.push(node);
    while (buf.size() > 0) {
        node = buf.top();
        res.push(node->val);
        buf.pop();
        if (node->left != NULL) buf.push(node->left);
        if (node->right != NULL) buf.push(node->right);
    }
    while (res.size() > 0) {
        printf("%d ", res.top());
        res.pop();
    }
}

void breadth_traverse_topdown(TreeNode* root) {
    if (root == NULL) return;
    queue<TreeNode*> buf;
    TreeNode* node = root;
    buf.push(node);
    while (buf.size() > 0) {
        node = buf.front();
        printf("%d ", node->val);
        buf.pop();
        if (node->left != NULL) buf.push(node->left);
        if (node->right != NULL) buf.push(node->right);
    }
}

void breadth_traverse_downtop(TreeNode* root) {
    if (root == NULL) return;
    stack<int> res;
    queue<TreeNode*> buf;
    TreeNode* node = root;
    buf.push(node);
    while (buf.size() > 0) {
        node = buf.front();
        res.push(node->val);
        buf.pop();
        if (node->right != NULL) buf.push(node->right);
        if (node->left != NULL) buf.push(node->left);
    }
    while (res.size() > 0) {
        printf("%d ", res.top());
        res.pop();
    }
}

int main() {
    //init
    TreeNode* tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);
    tree->left->left = new TreeNode(4);
    tree->left->right = new TreeNode(5);
    tree->right->left = new TreeNode(6);
    tree->right->right = new TreeNode(7);
    printf(
"Tree:\n"
"            1\n"
"           / \\\n"
"          2   3\n"
"         /\\   /\\\n"
"        4  5 6  7\n");
    //...
    printf("preorder:\t");
    preorder_traverse(tree);
    printf("\n");
    printf("preorder loop:\t");
    preorder_traverse_loop(tree);
    printf("\n");
    printf("inorder:\t");
    inorder_traverse(tree);
    printf("\n");
    printf("inorder loop:\t");
    inorder_traverse_loop(tree);
    printf("\n");
    printf("postorder:\t");
    postorder_traverse(tree);
    printf("\n");
    printf("postorder loop:\t");
    postorder_traverse_loop(tree);
    printf("\n");
    printf("breadth topdown:\t");
    breadth_traverse_topdown(tree);
    printf("\n");
    printf("breadth downtop:\t");
    breadth_traverse_downtop(tree);
    printf("\n");
}
