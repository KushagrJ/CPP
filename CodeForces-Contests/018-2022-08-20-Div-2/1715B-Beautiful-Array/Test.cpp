/*

 * Let n = 4, k = 6 and b = 3.

   Now, the minimum possible sum can be obtained in the following ways :-

   (1) floor(18 / 6) + floor(0 / 6) + floor(0 / 6) + floor(0 / 6) = 3 (i.e. b)
   (2) floor(12 / 6) + floor(6 / 6) + floor(0 / 6) + floor(0 / 6) = 3 (i.e. b)
   (3) floor(6 / 6) + floor(6 / 6) + floor(6 / 6) + floor(0 / 6) = 3 (i.e. b)
   ... and so on.

   Thus, no matter which integers we choose and in which order, the minimum sum
   that can be obtained is always equal to 18.
   In terms of k and b, the minimum sum is always equal to (k * b), irrespective
   of the value of n (as it is given that n is >= 1).

   Now, the maximum possible sum can be obtained in the following ways :-

   (1) floor(23 / 6) + floor(5 / 6) + floor(5 / 6) + floor(5 / 6) = 3 (i.e. b)
   (2) floor(17 / 6) + floor(11 / 6) + floor(5 / 6) + floor(5 / 6) = 3 (i.e. b)
   (3) floor(11 / 6) + floor(11 / 6) + floor(11 / 6) + floor(5 / 6) = 3 (i.e. b)
   ... and so on.

   Thus, no matter which integers we choose and in which order, the maximum sum
   that can be obtained is always equal to 38.
   In terms of n, k and b, the maximum sum is always equal to
     ((k * (b + 1)) - 1)   +   ((n - 1) * (k - 1))
     for the first integer     for the remaining (n - 1) integers
   = (k * b) + ((k - 1) * n).

   Thus, if the given value of s lies within the above range, then an answer is
   always possible.
   Otherwise, an answer is never possible.

   From the above example, it can be seen that if an answer is possible, then
   we can make the first integer equal to something which will satisfy the
   beauty of the array all by itself, and we can then make the other integers
   equal to something which contribute nothing to the beauty of the array.

   One way to do this is -

   ans[1] = min(((k * (b + 1)) - 1), s);
   s -= ans[1];

   for (int i = 2; i <= n; ++i)
   {
       ans[i] = min((k - 1), s);
       s -= ans[i];
   }

 */





#include <iostream>
#include <algorithm>


int main()
{

    int t;
    std::cin >> t;

    while (t--)
    {
        long long n, k, b, s;
        std::cin >> n >> k >> b >> s;

        if ((s < (k * b)) || (s > ((k * b) + ((k - 1) * n))))
        {
            std::cout << "-1\n";
            continue;
        }

        long long integer;

        integer = std::min(((k * (b + 1LL)) - 1LL), s);
        std::cout << integer << ' ';
        s -= integer;

        for (int i = 2; i <= n; ++i)
        {
            integer = std::min((k - 1), s);
            std::cout << integer << ' ';
            s -= integer;
        }

        std::cout << '\n';
    }

    return 0;

}
