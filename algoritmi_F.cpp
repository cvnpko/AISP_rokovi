#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int32_t n;
    std::cin >> n;
    std::vector<int32_t> a(n);
    for (int32_t i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    sort(a.begin(), a.end());
    int32_t d;
    std::cin >> d;
    d = d * 2 + 1;
    int32_t ispis = 0;
    for (int32_t i = 0, j = 0; j < n;)
    {
        if (a[j] - a[i] < d)
        {
            if (ispis < j - i + 1)
            {
                ispis = j - i + 1;
            }
            j++;
        }
        else
        {
            i++;
        }
    }
    std::cout << ispis << '\n';

    return 0;
}