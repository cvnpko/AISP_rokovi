#include <iostream>
#include <cstdint>
#include <vector>

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int32_t n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    size_t ind;
    for (ind = a.size() - 1; ind > 0; ind--)
    {
        if ((a[ind] + 1) - a[ind - 1] < 2)
        {
            break;
        }
    }
    if (ind == 0)
    {
        std::cout << -1;
    }
    else
    {
        a[ind]++;
        ind++;
        while (ind < a.size())
        {
            a[ind] = a[ind - 1] - 1;
            ind++;
        }
        for (int i = 0; i < n; i++)
        {
            std::cout << a[i] << ' ';
        }
    }
    std::cout << '\n';

    return 0;
}