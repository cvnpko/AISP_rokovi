#include <iostream>
#include <vector>

struct struktura
{
public:
    long long l, r, d;
};

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    long long t, n;
    std::cin >> t >> n;

    long long m_min = 0, m_max = 0;
    std::vector<struktura> a(n);
    for (long long i = 0; i < n; i++)
    {
        std::cin >> a[i].l >> a[i].r >> a[i].d;
        m_min = std::min(m_min, a[i].l);
        m_max = std::max(m_max, a[i].r);
    }
    long long ispis = 0;

    while (m_min <= m_max)
    {
        long long m_s = m_max - (m_max - m_min) / 2;
        long long r = 0;
        for (long long i = 0; i < n; i++)
        {
            if (m_s < a[i].r)
            {
                r += ((a[i].r - std::max(m_s, a[i].l)) * a[i].d);
            }
        }
        if (r <= t)
        {
            ispis = r;
            m_max = m_s - 1;
        }
        else
        {
            m_min = m_s + 1;
        }
    }
    std::cout << m_min << ' ' << ispis;

    return 0;
}