/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-07-12 10:15:29
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-12 10:43:15
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

TreeNode* constructBinaryTree(const std::vector<int>& preorder,
                              const std::vector<int>& inorder,
                              std::size_t preorderStart,
                              std::size_t preorderEnd, std::size_t inorderStart,
                              std::size_t inorderEnd) {
    auto rootNodeVal = preorder[preorderStart];
    TreeNode* n = new TreeNode(rootNodeVal);
    auto inorderRootPos =
        getInorderRootPos(rootNodeVal, inorder, inorderStart, inorderEnd);
    auto leftSubTreeLen = inorderRootPos - inorderStart;
    if (leftSubTreeLen > 0) {
        n->left = constructBinaryTree(preorder, inorder, preorderStart + 1,
                                      preorderStart + leftSubTreeLen,
                                      inorderStart, inorderRootPos - 1);
    }
    auto rightSubTreeLen = inorderEnd - inorderRootPos;
    if (rightSubTreeLen > 0) {
        n->right = constructBinaryTree(
            preorder, inorder, preorderStart + leftSubTreeLen + 1, preorderEnd,
            inorderRootPos + 1, inorderEnd);
    }
    return n;
}

TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    if (preorder.empty()) {
        return nullptr;
    }
    return constructBinaryTree(preorder, inorder, 0, preorder.size() - 1, 0,
                               inorder.size() - 1);
}