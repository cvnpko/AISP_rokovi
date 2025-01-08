#include <iostream>
#include <cstdint>
#include <string>

void generisi(std::string &s, int i_n, int i_d, int n, int d)
{
    if (i_n == n)
    {
        std::cout << s << '\n';
        return;
    }
    if (i_d < d && i_d + 2 + i_n <= n)
    {
        s += '(';
        generisi(s, i_n + 1, i_d + 1, n, d);
        s.pop_back();
    }
    if (i_d > 0)
    {
        s += ')';
        generisi(s, i_n + 1, i_d - 1, n, d);
        s.pop_back();
    }
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int32_t n, d;
    std::cin >> n >> d;
    std::string s = "";
    generisi(s, 0, 0, n, d);

    return 0;
}