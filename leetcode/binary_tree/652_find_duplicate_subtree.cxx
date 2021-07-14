/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-07-12 11:17:06
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-12 12:07:45
 */
#include "precompiled_headers.h"

bool subTreeEqual(TreeNode* src, TreeNode* dst) {
    if (!src && !dst) {
        return true;
    }
    if (!src || !dst) {
        return false;
    }
    return src->val == dst->val && subTreeEqual(src->left, dst->left) &&
           subTreeEqual(src->right, dst->right);
}

bool findInSub(TreeNode* target, std::vector<TreeNode*>& vec) {
    for (auto p = vec.begin(); p != vec.end(); ++p) {
        if (subTreeEqual(*p, target)) {
            vec.erase(p);
            return true;
        }
    }
    vec.push_back(target);
    return false;
}

bool findInRes(TreeNode* target, std::vector<TreeNode*>& vec) {
    for (auto p = vec.begin(); p != vec.end(); ++p) {
        if (subTreeEqual(*p, target)) {
            return true;
        }
    }
    return false;
}

void traverse(TreeNode* node, std::vector<TreeNode*>& res,
              std::vector<TreeNode*>& sub) {
    if (!node) {
        return;
    }
    traverse(node->left, res, sub);
    if (!findInRes(node, res)) {
        if (findInSub(node, sub)) {
            res.push_back(node);
        }
    }
    traverse(node->right, res, sub);
}

std::vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    std::vector<TreeNode*> res, sub;
    traverse(root, res, sub);
    return res;
}

std::string getSubTreeSeq(TreeNode* n,
                          std::unordered_map<std::string, int>& counter,
                          std::vector<TreeNode*>& res) {
    if (!n) {
        return "$";
    }
    std::ostringstream oss;
    oss << n->val << ',' << getSubTreeSeq(n->left, counter, res) << ','
        << getSubTreeSeq(n->right, counter, res);
    std::string seq = oss.str();
    ++counter[seq];
    if (counter[seq] == 2) {
        res.push_back(n);
    }
    return seq;
}

std::vector<TreeNode*> findDuplicateSubtrees2(TreeNode* root) {
    std::unordered_map<std::string, int> counter;
    std::vector<TreeNode*> res;
    getSubTreeSeq(root, counter, res);
    return res;
}
