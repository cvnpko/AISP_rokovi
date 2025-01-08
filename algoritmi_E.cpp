#include <iostream>
#include <vector>

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n, t;
    std::cin >> n >> t;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    int trenutni_zbir = 0, maks_zbir = 0;

    for (int i = 0, j = 0; j < n;)
    {
        while (j < n && trenutni_zbir + a[j] < t)
        {
            trenutni_zbir += a[j];
            j++;
        }
        if (trenutni_zbir > maks_zbir)
        {
            maks_zbir = trenutni_zbir;
        }
        if (i != j)
        {
            do
            {
                trenutni_zbir -= a[i];
                i++;
            } while (i < j && j < n && trenutni_zbir - a[i] + a[j] >= t);
        }
        else
        {
            i++;
            j++;
        }
    }
    std::cout << maks_zbir;

    return 0;
}