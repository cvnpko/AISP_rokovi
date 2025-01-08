#include <iostream>
#include <vector>

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    int t;
    std::cin >> t;

    int brojac = 0, tmp = 0;

    for (int i = 0, j = 0; j < n;)
    {
        brojac -= (j - i + 1) * (j - i) / 2;
        while (j < n && tmp + a[j] < t)
        {
            tmp += a[j];
            j++;
        }
        brojac += (j - i + 1) * (j - i) / 2;
        if (i != j)
        {
            do
            {
                tmp -= a[i];
                i++;
            } while (i < j && j < n && tmp - a[i] + a[j] >= t);
        }
        else
        {
            i++;
            j++;
        }
    }

    std::cout << brojac;

    return 0;
}