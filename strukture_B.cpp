#include <iostream>
#include <string>
#include <deque>

bool check(char a, char b)
{
    return a == 'U' && b == 'D' || a == 'D' && b == 'U' || a == 'L' && b == 'R' || a == 'R' && b == 'L';
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    std::string s;
    std::cin >> s;
    std::deque<char> d;
    for (int i = 0; i < s.length(); i++)
    {
        if (d.empty())
        {
            d.push_back(s[i]);
        }
        else if (check(d.back(), s[i]))
        {
            d.pop_back();
        }
        else
        {
            d.push_back(s[i]);
        }
    }

    while (!d.empty())
    {
        std::cout << d.front();
        d.pop_front();
    }

    return 0;
}
