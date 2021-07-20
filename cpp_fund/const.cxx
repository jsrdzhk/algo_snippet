/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-07-15 09:10:44
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-15 10:56:09
 */

#include "precompiled_headers.h"

class TestConst {
   private:
    int a;
    int b;

   public:
    TestConst(int a1) : a(a1) {}
    int getA() { return a; }
    int getConstB() const { return b; }

    int getB() { return b; }
    void setB(int v) { b = v; }
    void setA(int v) { a = v; }
};

int main() {
    auto testConst = TestConst(1);
    auto other = TestConst(2);
    auto other2 = TestConst(3);
    std::cout << testConst.getA() << std::endl;
    // const TestConst* p=&testConst;
    TestConst *const p = &testConst;
    p->setA(1);
    // p=&other;
    const TestConst *otherP = &testConst;
    otherP->getConstB();
    const auto other3=TestConst(4);
    auto& x=other;
    x=other2;
    x.setA(100);
    std::cout<<other2.getA()<<std::endl;
    // otherP->setA(2);
    otherP = p;
    otherP = &other2;
    return 0;
}