/*

 * https://codeforces.com/blog/entry/104930

 */





#include <iostream>
#include <vector>


int main()
{

    int t;
    std::cin >> t;

    while (t--)
    {
        int n, l, r;
        std::cin >> n >> l >> r;

        std::vector<int> v((n+1), 0);

        bool ans = true;

        for (int i = 1; i <= n; ++i)
        {
            if ((l % i) == 0)
                v[i] = l;
            else if ((i * ((l / i) + 1)) <= r)
                v[i] = (i * ((l / i) + 1));
            else
                ans = false;
        }

        if (ans)
        {
            std::cout << "YES\n";
            for (int i = 1; i <= n; ++i)
                std::cout << v[i] << ' ';
            std::cout << '\n';
        }

        else
        {
            std::cout << "NO\n";
        }
    }

    return 0;

}
