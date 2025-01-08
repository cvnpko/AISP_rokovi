#include <iostream>
#include <queue>
#include <cstdint>

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int32_t k, n;
    std::cin >> k >> n;
    std::priority_queue<int32_t> pq;
    std::vector<int32_t> izlaz(n, 0);
    for (int32_t i = 0; i < k && i < n; i++)
    {
        int32_t tmp;
        std::cin >> tmp;
        pq.push(tmp);
        std::cout << "0 ";
    }
    for (int32_t i = k; i < n; i++)
    {
        int32_t tmp;
        std::cin >> tmp;
        if (tmp > pq.top())
        {
            std::cout << "1 ";
        }
        else
        {
            pq.pop();
            pq.push(tmp);
            std::cout << "0 ";
        }
    }
    std::cout << '\n';

    return 0;
}
