#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

typedef std::pair<int32_t, int32_t> par;

bool cmp(par l, par r)
{
    return l.first < r.first;
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int32_t n;
    std::cin >> n;
    std::vector<par> a(n), m(n);
    for (int32_t i = 0; i < n; i++)
    {
        std::cin >> a[i].first;
        a[i].second = i;
    }
    for (int32_t i = 0; i < n; i++)
    {
        std::cin >> m[i].first;
        m[i].second = i;
    }
    sort(a.begin(), a.end(), cmp);
    sort(m.begin(), m.end(), cmp);
    std::vector<int32_t> pravilo(n);
    for (int32_t i = 0; i < n; i++)
    {
        pravilo[m[i].second] = a[i].second;
    }
    std::vector<int32_t> b(n);
    for (int32_t i = 0; i < n; i++)
    {
        std::cin >> b[i];
    }
    for (int32_t i = 0; i < n; i++)
    {
        std::cout << b[pravilo[i]] << ' ';
    }
    std::cout << '\n';

    return 0;
}
