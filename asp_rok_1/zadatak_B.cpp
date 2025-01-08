#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

typedef std::pair<int32_t, int32_t> par;

bool cmp1(par l, par r)
{
    return l.first < r.first;
}

bool cmp2(par l, par r)
{
    return l.second < r.second;
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int32_t n;
    std::cin >> n;
    std::vector<par> a(n);
    for (int32_t i = 0; i < n; i++)
    {
        std::cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end(), cmp1);
    for (int32_t i = 0; i < n;)
    {
        int32_t tmp = a[i].first;
        a[i].first = i;
        i++;
        while (i < n && a[i].first == tmp)
        {
            a[i].first = a[i - 1].first;
            i++;
        }
    }
    sort(a.begin(), a.end(), cmp2);
    for (int32_t i = 0; i < n; i++)
    {
        std::cout << a[i].first << ' ';
    }
    std::cout << '\n';

    return 0;
}
