/*

 * https://codeforces.com/blog/entry/105008

 */





#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


int main()
{

    int t;
    std::cin >> t;

    while (t--)
    {
        int n, m;
        std::cin >> n >> m;

        std::vector<int> v(n+1);
        for (int i = 1; i <= n; ++i)
            std::cin >> v[i];

        std::string s((m+1), 'B');

        for (int i = 1; i <= n; ++i)
        {
            if (s[std::min(v[i], (m + 1 - v[i]))] == 'B')
                s[std::min(v[i], (m + 1 - v[i]))] = 'A';
            else
                s[std::max(v[i], (m + 1 - v[i]))] = 'A';
        }

        for (int i = 1; i <= m; ++i)
            std::cout << s[i];
        std::cout << '\n';
    }

    return 0;

}
