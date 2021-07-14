/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-07-12 17:00:43
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-12 17:45:35
 */
#include "precompiled_headers.h"

std::vector<TreeNode*> constructBst(int s, int e) {
    std::vector<TreeNode*> res;
    if (s > e) {
        res.push_back(nullptr);
        return res;
    }
    for (auto i = s; i <= e; ++i) {
        auto leftRes = constructBst(s, i - 1);
        auto rightRes = constructBst(i + 1, e);
        for (auto l : leftRes) {
            for (auto r : rightRes) {
                TreeNode* node = new TreeNode(i);
                node->left = l;
                node->right = r;
                res.push_back(node);
            }
        }
    }
    return res;
}

std::vector<TreeNode*> generateTrees(int n) {
    return constructBst(1, n);
}