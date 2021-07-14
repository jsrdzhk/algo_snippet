/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-07-12 10:47:43
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-12 11:05:00
 */
#include "precompiled_headers.h"

std::size_t getInorderRootPos(int rootNodeVal, const std::vector<int>& inorder,
                              std::size_t inorderStart,
                              std::size_t inorderEnd) {
    for (auto i = inorderStart; i <= inorderEnd; ++i) {
        if (inorder[i] == rootNodeVal) {
            return i;
        }
    }
    return 0;
}

TreeNode* constructBinaryTree(const std::vector<int>& postorer,
                              const std::vector<int>& inorder,
                              std::size_t postorerStart,
                              std::size_t postorerEnd, std::size_t inorderStart,
                              std::size_t inorderEnd) {
    auto rootNodeVal = postorer[postorerEnd];
    TreeNode* n = new TreeNode(rootNodeVal);
    auto inorderRootPos =
        getInorderRootPos(rootNodeVal, inorder, inorderStart, inorderEnd);
    auto leftSubTreeLen = inorderRootPos - inorderStart;
    if (leftSubTreeLen > 0) {
        n->left = constructBinaryTree(postorer, inorder, postorerStart,
                                      postorerStart + leftSubTreeLen - 1,
                                      inorderStart, inorderRootPos - 1);
    }
    auto rightSubTreeLen = inorderEnd - inorderRootPos;
    if (rightSubTreeLen > 0) {
        n->right = constructBinaryTree(
            postorer, inorder, postorerStart + leftSubTreeLen, postorerEnd - 1,
            inorderRootPos + 1, inorderEnd);
    }
    return n;
}

TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
    if (postorder.empty()) {
        return nullptr;
    }
    return constructBinaryTree(postorder, inorder, 0, postorder.size() - 1, 0,
                               inorder.size() - 1);
}