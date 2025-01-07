#include <iostream>
#include <queue>

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int k, n;
    std::cin >> k >> n;
    std::priority_queue<int> pq;
    std::vector<int> izlaz(n, 0);
    for (int i = 0; i < k && i < n; i++)
    {
        int tmp;
        std::cin >> tmp;
        pq.push(tmp);
        std::cout << "0 ";
    }
    for (int i = k; i < n; i++)
    {
        int tmp;
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

    return 0;
}
