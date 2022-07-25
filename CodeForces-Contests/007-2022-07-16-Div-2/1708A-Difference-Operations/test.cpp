/*

 * https://codeforces.com/blog/entry/104930

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
        --n;

        int a;
        std::cin >> a;

        bool ans = true;

        while (n--)
        {
            int b;
            std::cin >> b;

            if ((b % a) != 0)
                ans = false;
        }

        if (ans)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }

    return 0;

}
