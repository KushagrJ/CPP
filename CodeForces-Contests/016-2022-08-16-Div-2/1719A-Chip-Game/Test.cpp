/*

 * https://codeforces.com/blog/entry/106049

 */





#include <iostream>


int main()
{

    int t;
    std::cin >> t;

    while (t--)
    {
        int n, m;
        std::cin >> n >> m;

        if ((n + m) & 1)
            std::cout << "Burenka" << '\n';
        else
            std::cout << "Tonya" << '\n';
    }

    return 0;

}
