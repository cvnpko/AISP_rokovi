#include <iostream>
#include <vector>
#include <set>

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int32_t n;
    std::cin >> n;
    std::vector<u_int32_t> a(n);
    for (int32_t i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    u_int32_t t;
    std::cin >> t;
    std::set<int32_t> s;
    int32_t ispis = 0;
    for (int32_t i = 0; i < n; i++)
    {
        if (s.find(t ^ a[i]) != s.end())
        {
            ispis++;
            s.erase(t ^ a[i]);
        }
        else
        {
            s.insert(a[i]);
        }
    }
    std::cout << ispis << '\n';

    return 0;
}