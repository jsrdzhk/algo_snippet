/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-06-20 12:50:28
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-15 09:29:42
 */
class RandomNode {
public:
    int val;
    RandomNode* next;
    RandomNode* random;

    RandomNode(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};