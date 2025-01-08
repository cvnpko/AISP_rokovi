#include <iostream>
#include <vector>

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    int ispis = 0;

    for (int i = 0, j = 0, tmp_k = 0; j < n; j++)
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

    std::cout << ispis;

    return 0;
}