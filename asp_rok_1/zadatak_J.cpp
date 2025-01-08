#include <iostream>
#include <vector>
#include <cstdint>

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int32_t n, k;
    std::cin >> n >> k;
    std::vector<int32_t> a(n);
    for (int32_t i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    int32_t ispis = 0;
    for (int32_t i = 0, j = 0, tmp_k = 0; j < n; j++)
    {
        if (a[j] == 0)
        {
            if (tmp_k == k)
            {
                while (a[i] != 0)
                {
                    i++;
                }
                i++;
            }
            else
            {
                tmp_k++;
            }
        }
        ispis = std::max(j - i + 1, ispis);
    }
    std::cout << ispis << '\n';

    return 0;
}