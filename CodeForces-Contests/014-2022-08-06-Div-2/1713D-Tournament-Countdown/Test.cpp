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

        std::vector<int> v((1 << n) + 1);
        for (int i = 1; i < v.size(); ++i)
            v[i] = i;

        while ((n-2) >= 0)
        {
            int x = 1;

            int i = 1;

            while (i <= (1 << n))
            {
                std::cout << "? " << v[i] << ' ' << v[(i+2)] << '\n';
                std::cout.flush();

                int r;
                std::cin >> r;

                if (r == 0)
                {
                    std::cout << "? " << v[(i+1)] << ' ' << v[(i+3)] << '\n';
                    std::cout.flush();

                    int r1;
                    std::cin >> r1;

                    if (r1 == 1)
                        v[x++] = v[(i+1)];
                    else
                        v[x++] = v[(i+3)];
                }

                else if (r == 1)
                {
                    std::cout << "? " << v[i] << ' ' << v[(i+3)] << '\n';
                    std::cout.flush();

                    int r1;
                    std::cin >> r1;

                    if (r1 == 1)
                        v[x++] = v[i];
                    else
                        v[x++] = v[(i+3)];
                }

                else
                {
                    std::cout << "? " << v[(i+1)] << ' ' << v[(i+2)] << '\n';
                    std::cout.flush();

                    int r1;
                    std::cin >> r1;

                    if (r1 == 1)
                        v[x++] = v[(i+1)];
                    else
                        v[x++] = v[(i+2)];
                }

                i += 4;
            }

            n -= 2;
        }

        if (n == 1)
        {
            std::cout << "? " << v[1] << ' ' << v[2] << '\n';
            std::cout.flush();

            int r1;
            std::cin >> r1;

            if (r1 == 1)
                std::cout << "! " << v[1] << '\n';
            else
                std::cout << "! " << v[2] << '\n';
        }

        else
        {
            std::cout << "! " << v[1] << '\n';
        }
    }

    return 0;

}
