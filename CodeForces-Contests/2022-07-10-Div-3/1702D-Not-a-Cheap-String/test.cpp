/*

 * https://codeforces.com/blog/entry/104763

  */





#include <iostream>


int main()
{

    int a[27];

    int t;
    std::cin >> t;

    while (t--)
    {
        std::fill((std::begin(a) + 1), std::end(a), 0);

        std::string w;
        std::cin >> w;

        int p;
        std::cin >> p;

        int sum = 0;

        for (auto c : w)
        {
            ++(a[c - 'a' + 1]);
            sum += (c - 'a' + 1);
        }

        for (int i = 26; i >= 1; --i)
        {
            while ((a[i]) && (sum > p))
            {
                --(a[i]);
                sum -= i;
            }
        }

        for (auto c : w)
        {
            if (a[c - 'a' + 1])
            {
                std::cout << c;
                --(a[c - 'a' + 1]);
            }
        }

        std::cout << '\n';
    }

    return 0;

}
