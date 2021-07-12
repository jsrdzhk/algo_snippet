/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-06-20 13:19:40
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-06-20 14:11:31
 */
class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val)
    {
        val = _val;
        left = nullptr;
        right = nullptr;
    }

    Node(int _val, Node *_left, Node *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution
{
private:
    Node *pre, *head = nullptr;

public:
    Node *treeToDoublyList(Node *root)
    {
        if (!root)
        {
            return root;
        }
        treeToDoublyListImpl(root);
        head->left = pre;
        pre->right = head;
        return head;
    }

    void treeToDoublyListImpl(Node *node)
    {
        if (!node)
        {
            return;
        }
        treeToDoublyListImpl(node->left);
        if (pre == nullptr)
        {
            head = node;
        }
        else
        {
            pre->right = node;
        }
        node->left = pre;
        pre = node;
        treeToDoublyListImpl(node->right);
    }
};