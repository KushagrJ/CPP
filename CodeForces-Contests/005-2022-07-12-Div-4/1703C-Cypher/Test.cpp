#include <iostream>


int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        int a[100];
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];

        for (int i = 0; i < n; ++i)
        {
            int b;
            std::cin >> b;

            std::string s;
            std::cin >> s;

            for (auto j : s)
            {
                // In C/C++, (((n % M) + M) % M) gives the same result as
                // (n % m) in Python

                if (j == 'D')
                    a[i] = ((((a[i] + 1) % 10) + 10) % 10);
                else
                    a[i] = ((((a[i] - 1) % 10) + 10) % 10);
            }
        }

        for (int i = 0; i < n; ++i)
            std::cout << a[i] << ' ';
        std::cout << '\n';
    }

    return 0;
}
