/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-07-11 08:37:19
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-11 09:54:02
 */
#include "precompiled_headers.h"

void traverseTree(TreeNode* node, std::vector<TreeNode*>& res) {
    if (!node) {
        return;
    }
    res.push_back(node);
    traverseTree(node->left, res);
    traverseTree(node->right, res);
}

void flatten(TreeNode* root) {
    std::vector<TreeNode*> res;
    traverseTree(root, res);
    if (res.empty()) {
        return;
    }
    int len = res.size();
    for (auto i = 0; i < len - 1; ++i) {
        res[i]->right = res[i + 1];
        res[i]->left = nullptr;
    }
}

void flatten2(TreeNode* root) {
    if (!root) {
        return;
    }
    flatten2(root->left);
    flatten2(root->right);
    TreeNode* right = root->right;
    TreeNode* left = root->left;
    root->left = nullptr;
    root->right = left;
    TreeNode* p = root;
    while (p->right) {
        p = p->right;
    }
    p->right = right;
}