#include "precompiled_headers.h"

class Solution {
   public:
    std::string replaceSpace(std::string s) {
        std::string replacement = "%20";
        std::ostringstream oss(std::ios_base::ate);
        for (const auto& c : s) {
            if (std::isspace(c)) {
                oss << replacement;
            } else {
                oss << c;
            }
        }
        return oss.str();
    }
};