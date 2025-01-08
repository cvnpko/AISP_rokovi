#include <iostream>
#include <cstdint>
#include <string>

void generisi(std::string &s, size_t i_n)
{
    if (i_n > 0 && s[i_n] == s[i_n - 1] && s[i_n] == '1')
    {
        return;
    }
    if (i_n == s.length())
    {
        std::cout << s << '\n';
        return;
    }
    if (s[i_n] != '.')
    {
        generisi(s, i_n + 1);
        return;
    }
    s[i_n] = '0';
    generisi(s, i_n + 1);
    if (i_n == 0 || s[i_n - 1] != '1')
    {
        s[i_n] = '1';
        generisi(s, i_n + 1);
    }
    s[i_n] = '.';
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::string s;
    std::cin >> s;
    generisi(s, 0);

    return 0;
}