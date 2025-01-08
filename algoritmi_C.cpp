#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<int64_t> prefiksna(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    sort(a.begin(), a.end());

    prefiksna[0] = a[0];

    for (int i = 1; i < n; i++)
    {
        prefiksna[i] = a[i] + prefiksna[i - 1];
    }

    int q;
    std::cin >> q;

    for (int i = 0; i < q; i++)
    {
        int x;
        std::cin >> x;
        int j = std::upper_bound(a.begin(), a.end(), x) - a.begin() - 1;
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