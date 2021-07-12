/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-06-20 12:50:28
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-06-20 12:50:37
 */
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};