#include "precompiled_headers.h"

class Solution
{
public:
    bool isMatch(std::string s, std::string p)
    {
        if (p.empty())
        {
            if (s.empty())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        std::size_t s_idx = 0;
        std::size_t s_len = s.size();
        std::size_t p_idx = 0;
        std::size_t p_len = p.size();
        while (p_idx<p_len)
        {
            char cur_regex_ch = p[p_idx];
            if (cur_regex_ch != '*')
            {
                if (s_idx < s_len && matches(s[s_idx], cur_regex_ch))
                {
                    ++s_idx;
                    ++p_idx;
                }else{

                }
            }
        }
    }

    bool matches(char src_char, char regex_char)
    {
        return src_char == regex_char || regex_char == '.';
    }
};