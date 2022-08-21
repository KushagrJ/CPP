/*

 * https://codeforces.com/blog/entry/104261

 */





#include <iostream>
#include <algorithm>


int main()
{

    int t;
    std::cin >> t;

    while (t--)
    {
        long long n, m;
        std::cin >> n >> m;

        if ((n == 1) && (m == 1))
            std::cout << "0\n";
        else
            std::cout << (std::min(n, m) + (n - 1 + m - 1)) << '\n';
    }

    return 0;

}
