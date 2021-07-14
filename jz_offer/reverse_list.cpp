#include "precompiled_headers.h"

class Solution {
   private:
    void reverseList(ListNode* head, std::vector<int>& res) {
        if (head == nullptr) {
            return;
        }
        reverseList(head->next, res);
        res.push_back(head->val);
    }

   public:
    std::vector<int> reversePrint(ListNode* head) {
        std::vector<int> res;
        reverseList(head, res);
        return res;
    }
};