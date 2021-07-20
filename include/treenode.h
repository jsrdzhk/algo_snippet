/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-06-12 15:01:07
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-15 09:31:48
 */
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Node {
   public:
    int val;
    std::vector<Node *> children;
    Node() {}
    Node(int _val) { val = _val; }
    Node(int _val, std::vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};