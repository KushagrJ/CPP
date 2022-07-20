/*

 * Explain properly.

 */





#include <iostream>
#include <vector>
#include <algorithm>


void unite(int, int, std::vector<int>&, std::vector<int>&);


int main()
{

    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        std::vector<int> link(n+1);
        for (int i = 1; i <= n; ++i)
            link[i] = i;

        std::vector<int> size((n+1), 1);

        std::vector<int> count((n+1), 0);

        bool input_is_definitely_faulty = false;

        for (int i = 1; i <= n; ++i)
        {
            int a, b;
            std::cin >> a >> b;

            if (a == b)
                input_is_definitely_faulty = true;

            ++(count[a]);
            ++(count[b]);

            if ((count[a] > 2) || (count[b] > 2))
                input_is_definitely_faulty = true;

            unite(a, b, link, size);
        }

        if (input_is_definitely_faulty)
        {
            std::cout << "NO\n";
        }

        else
        {
            for (int i = 1; i <= n; ++i)
            {
                if (link[i] == i)
                {
                    if (size[i] & 1)
                    {
                        std::cout << "NO\n";
                        goto end;
                    }
                }
            }

            std::cout << "YES\n";

            end: ;
        }
    }

    return 0;

}


void unite(int a, int b, std::vector<int>& link, std::vector<int>& size)
{

    int x = link[a];
    while (x != link[x])
        x = link[x];

    int y = link[b];
    while (y != link[y])
        y = link[y];

    if (x != y)
    {
        if (size[x] > size[y])
            std::swap(x, y);

        size[y] += size[x];
        link[x] = y;
    }

}
