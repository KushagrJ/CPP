/*

 * https://codeforces.com/blog/entry/105164

 */





#include <iostream>
#include <vector>


int main()
{

    int t;
    std::cin >> t;

    while (t--)
    {
        std::vector<int> v(4);

        int n;
        std::cin >> n;

        for (int i = 1; i <= 3; ++i)
            std::cin >> v[i];

        int doors_opened = 0;

        while (n)
        {
            ++(doors_opened);
            n = v[n];
        }

        if (doors_opened == 3)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }

    return 0;

}
