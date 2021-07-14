/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-07-10 10:55:37
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-10 11:18:49
 */
#include "precompiled_headers.h"

void invertTreeImpl(TreeNode* node) {
    if (!node) {
        return;
    }
    std::swap(node->left, node->right);
    invertTreeImpl(node->left);
    invertTreeImpl(node->right);
}

void invertTreeInorderImpl(TreeNode* node) {
    if (!node) {
        return;
    }
    invertTreeInorderImpl(node->left);
    std::swap(node->left, node->right);
    invertTreeInorderImpl(node->left);
}

TreeNode* invertTree(TreeNode* root) {
    if (!root) {
        return nullptr;
    }
    invertTreeImpl(root);
    return root;
}

TreeNode* iterationInvertTree(TreeNode* root) {
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* n = q.front();
        q.pop();
        if (!n) {
            continue;
        }
        std::swap(n->left, n->right);
        q.push(n->left);
        q.push(n->right);
    }
    return root;
}