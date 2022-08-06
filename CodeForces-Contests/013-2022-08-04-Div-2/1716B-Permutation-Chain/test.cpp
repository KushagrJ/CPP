/*

 * https://codeforces.com/blog/entry/105653

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
        std::cout << n << '\n';

        std::vector<int> v(n+1);
        for (int i = 1; i <= n; ++i)
        {
            v[i] = i;
            std::cout << i << ' ';
        }
        std::cout << '\n';

        for (int i = 1; i < n; ++i)
        {
            int temp = v[i];
            v[i] = v[i+1];
            v[i+1] = temp;

            for (int j = 1; j <= n; ++j)
                std::cout << v[j] << ' ';
            std::cout << '\n';
        }
    }

    return 0;

}
