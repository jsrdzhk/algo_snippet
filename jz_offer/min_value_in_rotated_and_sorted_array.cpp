#include "precompiled_headers.h"

class Solution {
   public:
    int minArray(std::vector<int>& numbers) {
        std::size_t num_size = numbers.size();
        if (num_size == 1) {
            return numbers[0];
        }
        int last = numbers[num_size - 1];
        int first = numbers[0];
        // not rotate
        if (last > first) {
            return first;
        } else {
            return get_min(numbers, 0, num_size - 1);
        }
    }

   private:
    int get_min(const std::vector<int>& numbers, std::size_t s, std::size_t e) {
        if (s == e) {
            return numbers[s];
        }
        std::size_t middle_idx = (e + s) / 2;
        int middle = numbers[middle_idx];
        int last = numbers[e];
        if (middle > last) {
            return get_min(numbers, middle_idx + 1, e);
        } else if (middle == last) {
            return std::min(get_min(numbers, middle_idx + 1, e),
                            get_min(numbers, s, middle_idx));
        } else {
            return get_min(numbers, s, middle_idx);
        }
    }
};