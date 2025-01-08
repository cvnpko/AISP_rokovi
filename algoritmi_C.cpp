#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int32_t n;
    std::cin >> n;
    std::vector<int32_t> a(n);
    std::vector<int64_t> prefiksna(n);
    for (int32_t i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    sort(a.begin(), a.end());
    prefiksna[0] = a[0];
    for (int32_t i = 1; i < n; i++)
    {
        prefiksna[i] = a[i] + prefiksna[i - 1];
    }
    int32_t q;
    std::cin >> q;
    for (int32_t i = 0; i < q; i++)
    {
        int32_t x;
        std::cin >> x;
        int32_t j = std::upper_bound(a.begin(), a.end(), x) - a.begin() - 1;
        if (j == -1)
        {
            std::cout << 0 << '\n';
        }
        else
        {
            std::cout << prefiksna[j] << '\n';
        }
    }

    return 0;
}