#include <iostream>
#include <vector>

struct struktura
{
public:
    int32_t l, r, d;
};

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int64_t t;
    int32_t n;
    std::cin >> t >> n;
    int32_t m_min = 0, m_max = 0;
    std::vector<struktura> a(n);
    for (int64_t i = 0; i < n; i++)
    {
        std::cin >> a[i].l >> a[i].r >> a[i].d;
        m_min = std::min(m_min, a[i].l);
        m_max = std::max(m_max, a[i].r);
    }
    int64_t ispis = 0;
    while (m_min <= m_max)
    {
        int32_t m_s = m_max - (m_max - m_min) / 2;
        int64_t r = 0;
        for (int64_t i = 0; i < n; i++)
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
    std::cout << m_min << ' ' << ispis << '\n';

    return 0;
}