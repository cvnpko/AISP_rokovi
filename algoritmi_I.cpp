#include <iostream>
#include <vector>

#define MAKS_CENA 1000001

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int32_t n;
    std::cin >> n;
    std::vector<int32_t> cene(MAKS_CENA, 0);
    for (int32_t i = 0; i < n; i++)
    {
        int32_t tmp;
        std::cin >> tmp;
        cene[tmp]++;
    }
    for (int32_t i = 1; i < MAKS_CENA; i++)
    {
        cene[i] += cene[i - 1];
    }
    int32_t k;
    std::cin >> k;
    for (int32_t i = 0; i < k; i++)
    {
        int32_t a, b;
        std::cin >> a >> b;
        if (a > b)
        {
            std::swap(a, b);
        }
        std::cout << cene[b] - cene[std::max(a - 1, 0)] << '\n';
    }

    return 0;
}