#include "precompiled_headers.h"

class CQueue {
   public:
    CQueue() {}

    void appendTail(int value) { value_stack.push(value); }

    int deleteHead() {
        if (delete_stack.empty()) {
            while (!value_stack.empty()) {
                delete_stack.push(value_stack.top());
                value_stack.pop();
            }
        }
        if (delete_stack.empty()) {
            return -1;
        } else {
            int deleted = delete_stack.top();
            delete_stack.pop();
            return deleted;
        }
    }

   private:
    std::stack<int> value_stack;
    std::stack<int> delete_stack;
};