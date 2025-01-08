#include <iostream>
#include <cstdint>
#include <string>

void generisi(std::string &s, size_t i_n, int32_t i_k)
{
    if (i_k < 0)
    {
        return;
    }
    if (i_n == s.length())
    {
        if (i_k == 0)
        {
            std::cout << s << '\n';
        }
        return;
    }
    if (s[i_n] != '.')
    {
        generisi(s, i_n + 1, i_k);
        return;
    }
    if (i_k != 0)
    {
        s[i_n] = '1';
        generisi(s, i_n + 1, i_k - 1);
    }
    s[i_n] = '2';
    generisi(s, i_n + 1, i_k);
    s[i_n] = '3';
    generisi(s, i_n + 1, i_k);
    s[i_n] = '.';
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int32_t k;
    std::string s;
    std::cin >> k >> s;
    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
        {
            k--;
        }
    }
    generisi(s, 0, k);

    return 0;
}