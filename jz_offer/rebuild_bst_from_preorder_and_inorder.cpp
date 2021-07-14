#include "precompiled_headers.h"

class Solution {
   public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        if (preorder.size() == 0) {
            return nullptr;
        }
        init_num_pos(inorder);
        return buildTreeImpl(preorder, 0, preorder.size() - 1, inorder, 0,
                             inorder.size() - 1);
    }

   private:
    std::unordered_map<int, std::size_t> inorder_num_pos;
    void init_num_pos(const std::vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_num_pos[inorder[i]] = i;
        }
    }

    TreeNode* buildTreeImpl(const std::vector<int>& preorder,
                            std::size_t pre_left_bound,
                            std::size_t pre_right_bound,
                            const std::vector<int>& inorder,
                            std::size_t in_left_bound,
                            std::size_t in_right_bound) {
        if (pre_left_bound > pre_right_bound) {
            return nullptr;
        }
        int root_node_num = preorder[pre_left_bound];
        int inorder_pos = inorder_num_pos[root_node_num];
        int left_subtree_len = inorder_pos - in_left_bound;

        TreeNode* root = new TreeNode(root_node_num);
        root->left = buildTreeImpl(preorder, pre_left_bound + 1,
                                   pre_left_bound + left_subtree_len, inorder,
                                   in_left_bound, inorder_pos - 1);
        root->right = buildTreeImpl(
            preorder, pre_left_bound + left_subtree_len + 1, pre_right_bound,
            inorder, inorder_pos + 1, in_right_bound);
        return root;
    }
};