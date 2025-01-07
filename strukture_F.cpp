#include <iostream>
#include <vector>
#include <algorithm>

bool cmp(std::pair<int, int> l, std::pair<int, int> r)
{
    return l.first < r.first;
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> a(n), m(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> m[i].first;
        m[i].second = i;
    }

    sort(a.begin(), a.end(), cmp);
    sort(m.begin(), m.end(), cmp);

    std::vector<int> pravilo(n);
    for (int i = 0; i < n; i++)
    {
        pravilo[m[i].second] = a[i].second;
    }

    std::vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> b[i];
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << b[pravilo[i]] << ' ';
    }

    return 0;
}
