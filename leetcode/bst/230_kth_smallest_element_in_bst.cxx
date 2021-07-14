/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-07-12 15:25:46
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-12 15:55:20
 */
#include "precompiled_headers.h"

void traverse(TreeNode* n, int k, int& c, int& res) {
    if (!n) {
        return;
    }
    traverse(n->left, k, c, res);
    ++c;
    if (c == k) {
        res = n->val;
        return;
    } else if (c > k) {
        return;
    } else {
        traverse(n->right, k, c, res);
    }
}

int kthSmallest(TreeNode* root, int k) {
    int res = 0, c = 0;
    traverse(root, k, c, res);
    return res;
}