#include <iostream>
#include <queue>

typedef std::pair<int, int> par;

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::priority_queue<par, std::vector<par>, std::greater<par>> pq;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        std::cin >> tmp;
        pq.push(std::make_pair(tmp, i));
    }

    int k;
    std::cin >> k;

    for (int i = 0; i < k; i++)
    {
        int tmp_int;
        std::cin >> tmp_int;
        par tmp_par = pq.top();
        pq.pop();
        tmp_par.first += tmp_int;
        pq.push(tmp_par);
    }

    std::vector<int> ispis(n);

    while (!pq.empty())
    {
        par tmp = pq.top();
        pq.pop();
        ispis[tmp.second] = tmp.first;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << ispis[i] << ' ';
    }

    return 0;
}
