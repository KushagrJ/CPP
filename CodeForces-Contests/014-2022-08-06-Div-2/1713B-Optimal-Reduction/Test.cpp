/*

 * https://codeforces.com/blog/entry/105419

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

        std::vector<int> v(n);
        for (int i = 0; i < n; ++i)
            std::cin >> v[i];

        bool increasing = true;
        bool ans = true;

        for (int i = 1; i < n; ++i)
        {
            if (increasing)
            {
                if (v[i-1] > v[i])
                    increasing = false;
            }

            else
            {
                if (v[i-1] < v[i])
                {
                    ans = false;
                    break;
                }
            }
        }

        std::cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;

}
