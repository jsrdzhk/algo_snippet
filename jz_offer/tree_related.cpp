#include "precompiled_headers.h"

void recursivePreorderTraverseImpl(TreeNode *node, std::vector<int> &res) {
    if (!node) {
        return;
    }
    res.push_back(node->val);
    recursivePreorderTraverseImpl(node->left, res);
    recursivePreorderTraverseImpl(node->right, res);
}

std::vector<int> recursivePreorderTraverse(TreeNode *root) {
    std::vector<int> res;
    recursivePreorderTraverseImpl(root, res);
    return res;
}

std::vector<int> iterationPreorderTraverse(TreeNode *root) {
    std::vector<int> res;
    if (!root) {
        return res;
    }
    std::stack<TreeNode *> nodeStack;
    nodeStack.push(root);
    while (!nodeStack.empty()) {
        TreeNode *node = nodeStack.top();
        res.push_back(node->val);
        nodeStack.pop();
        if (node->right) {
            nodeStack.push(node->right);
        }
        if (node->left) {
            nodeStack.push(node->left);
        }
    }
    return res;
}

void recursiveInorderTraverseImpl(TreeNode *node, std::vector<int> &res) {
    if (!node) {
        return;
    }
    recursiveInorderTraverseImpl(node->left, res);
    res.push_back(node->val);
    recursiveInorderTraverseImpl(node->right, res);
}

std::vector<int> recursiveInorderTraverse(TreeNode *root) {
    std::vector<int> res;
    recursiveInorderTraverseImpl(root, res);
    return res;
}

std::vector<int> iterationInorderTraverse(TreeNode *root) {
    std::vector<int> res;
    std::stack<TreeNode *> nodeStack;
    while (root || !nodeStack.empty()) {
        while (root) {
            nodeStack.push(root);
            root = root->left;
        }
        root = nodeStack.top();
        nodeStack.pop();
        res.push_back(root->val);
        root = root->right;
    }
    return res;
}

void recursivePostorderTraverseImpl(TreeNode *node, std::vector<int> &res) {
    if (!node) {
        return;
    }
    recursivePostorderTraverseImpl(node->left, res);
    recursivePostorderTraverseImpl(node->right, res);
    res.push_back(node->val);
}

std::vector<int> recursivePostorderTraverse(TreeNode *root) {
    std::vector<int> res;
    recursivePostorderTraverseImpl(root, res);
    return res;
}

std::vector<int> iterationPostorderTraverse(TreeNode *root) {
    std::vector<int> res;
    if (!root) {
        return res;
    }
    std::stack<TreeNode *> nodeStack;
    nodeStack.push(root);
    while (!nodeStack.empty()) {
        TreeNode *node = nodeStack.top();
        nodeStack.pop();
        res.push_back(node->val);
        if (node->left) {
            nodeStack.push(node->left);
        }
        if (node->right) {
            nodeStack.push(node->right);
        }
    }
    std::reverse(res.begin(), res.end());
    return res;
}

std::vector<int> levelorderTraverse(TreeNode *root) {
    std::vector<int> res;
    if (!root) {
        return res;
    }
    std::queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *node = q.front();
        res.push_back(node->val);
        if (node->left) {
            q.push(node->left);
        }
        if (node->right) {
            q.push(node->right);
        }
        q.pop();
    }
    return res;
}

std::vector<std::vector<int>> levelorderTraverse2(TreeNode *root) {
    std::vector<std::vector<int>> res;
    if (!root) {
        return res;
    }
    std::queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        std::queue<TreeNode *> tmp;
        std::vector<int> line;
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            line.push_back(node->val);
            if (node->left) {
                tmp.push(node->left);
            }
            if (node->right) {
                tmp.push(node->right);
            }
        }
        res.push_back(line);
        q = tmp;
    }
    return res;
}

void recursiveNArrPreorderTraverseImpl(Node *node, std::vector<int> &res) {
    if (!node) {
        return;
    }
    res.push_back(node->val);
    for (auto c : node->children) {
        recursiveNArrPreorderTraverseImpl(c, res);
    }
}

std::vector<int> recursiveNArrPreorderTraverse(Node *root) {
    std::vector<int> res;
    recursiveNArrPreorderTraverseImpl(root, res);
    return res;
}

std::vector<int> iterationNArrPreorderTraverse(Node *root) {
    std::vector<int> res;
    if (!root) {
        return res;
    }
    std::stack<Node *> s;
    s.push(root);
    while (!s.empty()) {
        Node *node = s.top();
        s.pop();
        res.push_back(node->val);
        auto &c = node->children;
        for (auto rb = c.rbegin(); rb != c.rend(); ++rb) {
            if (*rb) {
                s.push(*rb);
            }
        }
    }
    return res;
}

void recursiveNArrPostorderTraverseImpl(Node *node, std::vector<int> &res) {
    if (!node) {
        return;
    }
    for (auto c : node->children) {
        recursiveNArrPostorderTraverseImpl(c, res);
    }
    res.push_back(node->val);
}

std::vector<int> recursiveNArrPostorderTraverse(Node *root) {
    std::vector<int> res;
    recursiveNArrPostorderTraverseImpl(root, res);
    return res;
}

std::vector<int> iterationNArrPostorderTraverse(Node *root) {
    std::vector<int> res;
    if (!root) {
        return res;
    }
    std::stack<Node *> s;
    s.push(root);
    while (!s.empty()) {
        Node *node = s.top();
        s.pop();
        res.push_back(node->val);
        auto &c = node->children;
        for (auto pc : c) {
            s.push(pc);
        }
    }
    std::reverse(res.begin(), res.end());
    return res;
}

std::vector<std::vector<int>> nArrLevelorderTraverse(Node *root) {
    std::vector<std::vector<int>> res;
    if (!root) {
        return res;
    }
    std::queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        std::vector<int> line;
        std::queue<Node *> tmp;
        while (!q.empty()) {
            Node *n = q.front();
            q.pop();
            line.push_back(n->val);
            auto &c = n->children;
            for (auto pc : c) {
                if (pc) {
                    tmp.push(pc);
                }
            }
        }
        res.push_back(line);
        q = tmp;
    }
    return res;
}