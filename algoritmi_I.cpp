#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;
    std::vector<int> cene(1000001, 0);
    for (int i = 0; i < n; i++)
    {
        int tmp;
        std::cin >> tmp;
        cene[tmp]++;
    }
    for (int i = 1; i < 1000001; i++)
    {
        cene[i] += cene[i - 1];
    }
    int k;
    std::cin >> k;

    for (int i = 0; i < k; i++)
    {
        int a, b;
        std::cin >> a >> b;
        if (a > b)
        {
            std::swap(a, b);
        }
        std::cout << cene[b] - cene[std::max(a - 1, 0)] << '\n';
    }

    return 0;
}