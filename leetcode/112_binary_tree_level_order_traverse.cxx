/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-07-10 18:23:16
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-12 09:30:26
 */
#include "precompiled_headers.h"

std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> res;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        auto len = q.size();
        std::vector<int> line;
        for (auto i = 0; i < len; ++i) {
            TreeNode* n = q.front();
            q.pop();
            if (!n) {
                continue;
            }
            line.push_back(n->val);
            if (n->left) {
                q.push(n->left);
            }
            if (n->right) {
                q.push(n->right);
            }
        }
        if (!line.empty()) {
            res.push_back(line);
        }
    }
    return res;
}