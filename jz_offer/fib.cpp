#include "precompiled_headers.h"

class Solution {
   public:
    int fib(int n) {
        init_fib_cache();
        // return fibImpl(n);
        if (fib_cache.count(n)) {
            return fib_cache[n];
        }
        int res = 1;
        for (int i = 2; i < n; ++i) {
            int cur = fib_cache[i - 1] + fib_cache[i - 2];
            fib_cache[i] = cur;
            res += cur;
        }
        return res;
    }

   private:
    std::unordered_map<int, int> fib_cache;
    void init_fib_cache() {
        fib_cache[0] = 0;
        fib_cache[1] = 1;
    }
    int fibImpl(int n) {
        if (fib_cache.count(n)) {
            return fib_cache[n];
        }
        return fibImpl(n - 1) + fibImpl(n - 2);
    }
};