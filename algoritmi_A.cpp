#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;
    std::vector<int> x_osa(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> x_osa[i];
    }
    sort(x_osa.begin(), x_osa.end());
    int d;
    std::cin >> d;

    int ispis = 0;
    for (int i = 0, j = 0; j < n;)
    {
        if (x_osa[j] - x_osa[i] <= d)
        {
            if (x_osa[j] - x_osa[i] > ispis)
            {
                ispis = x_osa[j] - x_osa[i];
            }
            j++;
        }
        else
        {
            i++;
        }
    }
    std::cout << ispis;
    return 0;
}