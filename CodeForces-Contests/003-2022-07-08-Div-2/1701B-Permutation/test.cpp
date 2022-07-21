/*

 * https://codeforces.com/blog/entry/104671

 */





#include <iostream>


int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        bool printed[200001] = {false};

        int n;
        std::cin >> n;

        std::cout << "2\n";

        for (int i = 1; i <= n; ++i)
        {
            if (!(printed[i]))
            {
                for (int j = i; j <= n; j *= 2)
                {
                    std::cout << j << " ";
                    printed[j] = true;
                }
            }
        }

        std::cout << '\n';
    }

    return 0;
}
