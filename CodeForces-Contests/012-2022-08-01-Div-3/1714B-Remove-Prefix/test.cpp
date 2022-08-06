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

        std::vector<int> v1(n+1);

        for (int i = 1; i <= n; ++i)
            std::cin >> v1[i];

        std::vector<int> v2((n+1), 0);

        int i;
        for (i = n; i >= 1; --i)
        {
            if (v2[v1[i]] == 0)
                ++(v2[v1[i]]);
            else
                break;
        }

        std::cout << i << '\n';
    }

    return 0;

}
