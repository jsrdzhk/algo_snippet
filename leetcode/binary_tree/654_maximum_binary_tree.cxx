/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-07-12 09:42:07
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-12 10:04:20
 */
#include "precompiled_headers.h"

std::pair<int, int> getMax(const std::vector<int>& nums, int s, int e) {
    int max = 0, maxPos = 0;
    for (auto i = s; i <= e; ++i) {
        if (nums[i] >= max) {
            max = nums[i];
            maxPos = i;
        }
    }
    return std::make_pair(max, maxPos);
}

TreeNode* constructImpl(const std::vector<int>& nums, int s, int e) {
    auto maxPair = getMax(nums, s, e);
    auto maxNum = maxPair.first;
    auto maxPos = maxPair.second;
    TreeNode* newNode = new TreeNode(maxNum);
    if (maxPos > s) {
        newNode->left = constructImpl(nums, s, maxPos - 1);
    }
    if (maxPos < e) {
        newNode->right = constructImpl(nums, maxPos + 1, e);
    }
    return newNode;
}

TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) {
    if (nums.empty()) {
        return nullptr;
    }
    return constructImpl(nums, 0, nums.size() - 1);
}