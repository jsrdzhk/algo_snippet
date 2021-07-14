#include "precompiled_headers.h"

class Solution
{
public:
    bool isNumber(std::string s)
    {
        std::string trimmed_s = trim_leading_trailing_space(s);
        if (trimmed_s.empty() || trimmed_s.size() == s.size())
        {
            return false;
        }
        char leading = trimmed_s[0];
        if (!is_valid_leading(leading))
        {
            return false;
        }
        for (std::size_t i = 1; i < trimmed_s.size(); ++i)
        {
            char ch = trimmed_s[i];

            if (ch == '+' || ch == '-')
            {
                if (!is_e(trimmed_s[i - 1]))
                {
                    return false;
                }
                else
                {
                    std::string left = trimmed_s.substr(i);
                    return is_integer(left);
                }
            }

        }
    }

private:
    bool is_decimal(const std::string &s)
    {
    }

    bool is_integer(const std::string &s){

    }
    std::string trim_leading_trailing_space(const std::string &src)
    {
        std::string res = src;
        auto leading_non_whitespace_pos = src.find_first_not_of(' ');
        auto trailing_non_whitespace_pos = src.find_last_not_of(' ');
        if (leading_non_whitespace_pos != std::string::npos)
        {
            res = res.substr(leading_non_whitespace_pos);
        }
        if (trailing_non_whitespace_pos != std::string::npos)
        {
            res = res.substr(trailing_non_whitespace_pos);
        }
        return res;
    }

    bool is_num(char ch)
    {
        return ch >= '0' && ch <= '9';
    }

    bool is_valid(char ch)
    {
        return is_valid_leading(ch) || is_e(ch) || ch == '.';
    }

    bool is_valid_leading(char ch)
    {
        return ch == '+' || ch == '-' || is_num(ch);
    }

    bool is_e(char ch)
    {
        return ch == 'e' || ch == 'E';
    }
};