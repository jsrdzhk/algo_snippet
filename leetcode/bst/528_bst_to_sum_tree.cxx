/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-07-12 15:58:27
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-12 16:05:09
 */
#include "precompiled_headers.h"

void traverseBst(TreeNode* n, int& sum) {
    if (!n) {
        return;
    }
    traverseBst(n->right, sum);
    n->val = n->val += sum;
    sum = n->val;
    traverseBst(n->left, sum);
}

TreeNode* bstToGst(TreeNode* root) {
    int sum = 0;
    traverseBst(root, sum);
    return root;
}