/*

 * https://codeforces.com/blog/entry/104881

 */





#include <iostream>


int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        bool non_zero_integer_encountered = false;

        long long ans = 0;

        while (--n)
        {
            int a;
            std::cin >> a;

            if (a > 0)
            {
                non_zero_integer_encountered = true;
                ans += a;
            }

            else
            {
                if (non_zero_integer_encountered)
                    ++(ans);
            }
        }

        int temp;
        std::cin >> temp;

        std::cout << ans << '\n';
    }

    return 0;
}
