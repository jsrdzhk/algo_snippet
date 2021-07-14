#include "precompiled_headers.h"

class Solution {
   public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (; n; n /= 2) {
            if (n % 2 == 1) {
                ++count;
            }
        }
        return count;
    }
};