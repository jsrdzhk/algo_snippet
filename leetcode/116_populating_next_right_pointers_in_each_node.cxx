/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-07-10 17:36:20
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-11 08:28:11
 */

#include <queue>

class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root) {
    std::queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        auto len = q.size();
        for (auto i = 0; i < len; ++i) {
            Node* n = q.front();
            q.pop();
            if (!n) {
                continue;
            }
            if (i < len - 1) {
                n->next = q.front();
            }
            q.push(n->left);
            q.push(n->right);
        }
    }
    return root;
}

void recursiveConnectImpl(Node* n1, Node* n2) {
    if (!n1 || !n2) {
        return;
    }
    n1->next = n2;
    recursiveConnectImpl(n1->left, n1->right);
    recursiveConnectImpl(n1->right, n2->left);
    recursiveConnectImpl(n2->left, n2->right);
}

Node* recursiveConnect(Node* root) {
    if (root) {
        recursiveConnectImpl(root->left, root->right);
    }
    return root;
}