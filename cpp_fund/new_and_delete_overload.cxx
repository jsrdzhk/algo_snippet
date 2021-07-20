/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-07-15 15:49:26
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-16 09:02:05
 */
#include "precompiled_headers.h"
class TestOverloadOp {
   private:
    std::ostream& os;
    std::string delim;

   private:
    void* operator new(std::size_t s) { return ::operator new(s); }

    void operator delete(void* s) { ::operator delete(s); }

   public:
    TestOverloadOp() = delete;
    TestOverloadOp(std::ostream& os, std::string&& delim)
        : os(os), delim(std::move(delim)) {}
    TestOverloadOp& operator()(const std::string& data) {
        os << data << delim;
        return *this;
    }
    ~TestOverloadOp() = default;
};

int main() {
    TestOverloadOp testOverloadOp(std::cout, "/");
    testOverloadOp("asas");
    testOverloadOp("lk");
    return 0;
}