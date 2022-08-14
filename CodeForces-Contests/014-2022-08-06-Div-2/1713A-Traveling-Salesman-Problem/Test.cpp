/*

 * https://codeforces.com/blog/entry/105419

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

        int pos_x = 0, pos_y = 0, neg_x = 0, neg_y = 0;

        while (n--)
        {
            int x, y;
            std::cin >> x >> y;

            if (x > 0)
            {
                if (x > pos_x)
                    pos_x = x;
            }

            else if (y > 0)
            {
                if (y > pos_y)
                    pos_y = y;
            }

            else if (x < 0)
            {
                if ((-x) > neg_x)
                    neg_x = (-x);
            }

            else if (y < 0)
            {
                if ((-y) > neg_y)
                    neg_y = (-y);
            }
        }

        std::cout << ((pos_x * 2) + (pos_y * 2) + (neg_x * 2) + (neg_y * 2))
                  << '\n';
    }

    return 0;

}
