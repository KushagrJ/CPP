/*

 * https://codeforces.com/blog/entry/105549

 */





#include <iostream>
#include <limits>
#include <algorithm>


int main()
{

    int t;
    std::cin >> t;

    while (t--)
    {
        int n, h, m;
        std::cin >> n >> h >> m;

        m = ((h * 60) + m);

        int minutes_sleep = std::numeric_limits<int>::max();

        while (n--)
        {
            int h_i, m_i;
            std::cin >> h_i >> m_i;

            m_i = ((h_i * 60) + m_i);

            if (m <= m_i)
                minutes_sleep = std::min(minutes_sleep, (m_i - m));
            else
                minutes_sleep = std::min(minutes_sleep, ((m_i + 1440 - m)));
        }

        h = (minutes_sleep / 60);
        m = (minutes_sleep % 60);

        std::cout << h << ' ' << m << '\n';
    }

    return 0;

}
