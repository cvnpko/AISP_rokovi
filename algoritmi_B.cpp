#include <iostream>
#include <vector>
#include <algorithm>

bool cmp1(std::pair<int, int> l, std::pair<int, int> r)
{
    return l.first < r.first;
}

bool cmp2(std::pair<int, int> l, std::pair<int, int> r)
{
    return l.second < r.second;
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> a(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end(), cmp1);

    for (int i = 0; i < n;)
    {
        int tmp = a[i].first;
        a[i].first = i;
        i++;
        while (i < n && a[i].first == tmp)
        {
            a[i].first = a[i - 1].first;
            i++;
        }
    }
    sort(a.begin(), a.end(), cmp2);
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i].first << ' ';
    }

    return 0;
}
