#include <iostream>
#include <deque>
#include <string>

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    std::deque<std::pair<char, bool>> d;

    for (int i = 0; i < s.length(); i++)
    {
        if (isupper(s[i]))
        {
            for (auto t : d)
            {
                std::cout << t.first;
            }
            std::cout << s[i] << '\n';
            while (!d.empty() && d.back().second)
            {
                d.pop_back();
            }
            if (!d.empty())
            {
                d.back().second = true;
            }
        }
        else
        {
            d.push_back(std::make_pair(s[i], false));
        }
    }

    return 0;
}
