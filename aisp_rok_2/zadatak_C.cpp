#include <iostream>
#include <queue>
#include <cstdint>

typedef std::pair<int32_t, int32_t> par;

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int32_t n;
    std::cin >> n;
    std::priority_queue<par, std::vector<par>, std::greater<par>> pq;
    for (int32_t i = 0; i < n; i++)
    {
        int32_t tmp;
        std::cin >> tmp;
        pq.push(std::make_pair(tmp, i));
    }
    int32_t k;
    std::cin >> k;
    for (int32_t i = 0; i < k; i++)
    {
        int32_t tmp_int;
        std::cin >> tmp_int;
        par tmp_par = pq.top();
        pq.pop();
        tmp_par.first += tmp_int;
        pq.push(tmp_par);
    }
    std::vector<int32_t> ispis(n);
    while (!pq.empty())
    {
        par tmp = pq.top();
        pq.pop();
        ispis[tmp.second] = tmp.first;
    }
    for (int32_t i = 0; i < n; i++)
    {
        std::cout << ispis[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}
