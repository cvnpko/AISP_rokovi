#include <iostream>
#include <cstdint>
#include <string>

void generisi(std::string &s, size_t i_n, int32_t i_l)
{
    if (i_l < 0)
    {
        return;
    }
    if (i_n == s.length())
    {
        if (i_l == 0)
        {
            std::cout << s << '\n';
        }
        return;
    }
    if (s[i_n] != '.')
    {
        if (s[i_n] == '(')
        {
            generisi(s, i_n + 1, i_l + 1);
        }
        else
        {
            generisi(s, i_n + 1, i_l - 1);
        }
        return;
    }
    s[i_n] = '(';
    generisi(s, i_n + 1, i_l + 1);
    s[i_n] = ')';
    generisi(s, i_n + 1, i_l - 1);
    s[i_n] = '.';
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::string s;
    std::cin >> s;
    generisi(s, 0, 0);

    return 0;
}