/*

 * https://codeforces.com/blog/entry/105549

 */





#include <iostream>
#include <vector>


int main()
{

    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        bool div_5_exists = false;

        std::vector<int> v(n);

        for (int i = 0; i < n; ++i)
        {
            std::cin >> v[i];

            if (v[i] % 5 == 0)
                div_5_exists = true;
        }

        if (div_5_exists)
        {
            bool ans = true;

            int x = (v[0] + (v[0] % 10));

            for (int i = 1; i < n; ++i)
            {
                if ((v[i] + (v[i] % 10)) != x)
                {
                    ans = false;
                    break;
                }
            }

            std::cout << (ans ? "Yes\n" : "No\n");
        }

        else
        {
            bool ans = true;

            while (v[0] % 10 != 2)
                v[0] += (v[0] % 10);

            int x = (v[0] % 20);

            for (int i = 1; i < n; ++i)
            {
                while (v[i] % 10 != 2)
                    v[i] += (v[i] % 10);

                if ((v[i] % 20) != x)
                {
                    ans = false;
                    break;
                }
            }

            std::cout << (ans ? "Yes\n" : "No\n");
        }
    }

    return 0;

}
