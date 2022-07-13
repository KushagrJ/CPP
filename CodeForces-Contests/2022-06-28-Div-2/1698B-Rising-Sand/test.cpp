/*

 * If k = 1, then we can make every other pile too tall, excluding the ends of
   the array. For eg., if the array is [1, 2, 3, 4, 5, 6], then we can make
   piles 2 and 4 too tall by performing some large number of operations on them.
   Thus, the answer in this case is the floor of ((n - 1) / 2).

   Else, if k >= 2, then note that for any pile, if we perform an operation on
   it, then we perform on one of its neighbours as well.
   Therefore, if the pile is not too tall initially, then it will never become
   too tall as a result of these operations, since both a pile and at least one
   of its neighbours will gain sand.
   So in this case, doing operations never improves the answer, and so the
   answer is the number of too tall piles initially.

 */





#include <iostream>


int main()
{

    int t;
    std::cin >> t;

    while (t--)
    {
        int n, k;
        std::cin >> n >> k;

        int ans = 0;

        if (k == 1)
        {
            ans = ((n - 1) / 2);

            int a;
            while (n--)
                std::cin >> a;
        }

        else
        {
            int a, b, c;
            std::cin >> a >> b >> c;

            if (b > (a + c))
                ++(ans);

            n -= 3;

            while (n--)
            {
                a = b;
                b = c;
                std::cin >> c;

                if (b > (a + c))
                    ++(ans);
            }
        }

        std::cout << ans << '\n';
    }

    return 0;

}
