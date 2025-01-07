#include <iostream>
#include <set>

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n, k;
    std::cin >> n >> k;

    std::set<int> s;
    s.insert(n);
    int i = 0;
    for (auto it = s.begin(); i < k; i++, it++)
    {
        std::cout << *it << ' ';
        s.insert(*it * 2);
        s.insert(*it * 4 - 3);
    }

    return 0;
}
