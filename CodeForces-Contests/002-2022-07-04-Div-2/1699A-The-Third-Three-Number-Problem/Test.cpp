/*

 * For every integer, if its least significant (i.e. the rightmost) bit is 0,
   then it is even, and if it is 1, then it is odd.

   The possible combinations for the rightmost bits of a, b & c are
   0 0 0, 0 0 1, 0 1 0, 0 1 1, 1 0 0, 1 0 1, 1 1 0 and 1 1 1.

   The rightmost bit of (a XOR b) + (b XOR c) + (c XOR a) depends only on the
   rightmost bits of a, b & c, and in every combination given above, the
   rightmost bit of the result always comes out to be 0, making the result even.

   Thus, an answer exists if and only if n is even.

   One possible answer when n is even is a = 0, b = 0 and c = (n / 2).

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

        if (n & 1)
        {
            std::cout << "-1\n";
        }

        else
        {
            std::cout << "0 0 " << (n / 2) << '\n';
        }
    }

    return 0;

}
