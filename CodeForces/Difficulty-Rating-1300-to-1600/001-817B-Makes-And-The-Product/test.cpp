/*

 * Let min_1[i] be the minimum product using 1 integer in the range
   a[0] to a[i] (both inclusive), and let count_1[i] be the number of distinct
   ways in which this minimum product can be achieved using 1 integer in the
   above range.
   Since the product of 1 integer is that integer itself, therefore
   min_1[0] = a[0], and for all i > 0, min_1[i] = min(min_1[i-1], a[i]).
   Consequently, count_1[0] = 1, and for all i > 0,
   (1) if a[i] == min_1[i-1], then count_1[i] = count_1[i-1] + 1,
   (2) if a[i] < min_1[i-1], then count_1[i] = 1, and
   (3) if a[i] > min_1[i-1], then count_1[i] = count_1[i-1].

   Similarly, let min_2[i] be the minimum product using 2 distinct integers in
   the range a[0] to a[i] (both inclusive), and let count_2[i] be the number of
   distinct ways in which this minimum product can be achieved using 2 distinct
   integers in the above range.
   Now, min_2[0] = NIL, min_2[1] = a[0] * a[1], and for all i > 1,
   min_2[i] = min(min_2[i-1], min_1[i-1] * a[i]) (this is because only the
   minimum integer in the range a[0] to a[i-1] can be multiplied with a[i] to
   achieve the minimum product).
   Consequently, count_2[0] = NIL, count_2[1] = 1, and for all i > 1,
   (1) if min_1[i-1] * a[i] == min_2[i-1], then
   count_2[i] = count_1[i-1] + count_2[i-1] (this is because min_1[i-1] * a[i]
   represents the minimum possible product when a[i] is the right-hand operand
   of the product, and if this product is the same as the previously stored
   minimum product, then the total number of distinct ways in which this
   product can be achieved becomes equal to count_1[i-1] + count_2[i-1], as
   count_1[i-1] is the number of times min_1[i-1] appears in the range
   a[0] to a[i-1], and a[i] can be multiplied with each of those occurrences of
   min_1[i-1] to achieve the same minimum product, and count_2[i-1] is the
   number of times this product can be achieved in the range a[0] to a[i-1]),
   (2) if min_1[i-1] * a[i] < min_2[i-1], then count_2[i] = count_1[i-1] (this
   is because if min_1[i-1] * a[i] is smaller than the previously stored
   minimum product, then this becomes the new minimum product, and this new
   minimum product can be achieved in count_1[i-1] distinct ways, by the logic
   described above), and
   (3) if min_1[i-1] * a[i] > min_2[i-1], then count_2[i] = count_2[i-1].

   Similar logic applies to min_3[] and count_3[].

 */





#include <iostream>


int main()
{

    unsigned long long n;
    std::cin >> n;
    n -= 2;

    unsigned long long x, y;
    std::cin >> x >> y;

    unsigned long long min_1 = ((x < y) ? x : y);
    unsigned long long count_1 = ((x == y) ? 2 : 1);

    unsigned long long min_2 = (x * y);
    unsigned long long count_2 = 1;

    __uint128_t min_3 = static_cast<__uint128_t>(-1);
    unsigned long long count_3 = 1;

    while (n--)
    {
        unsigned long long a;
        std::cin >> a;

        unsigned long long b = (min_1 * a);

        __uint128_t c = (static_cast<__uint128_t>(min_2) * a);

        if (c == min_3)
            count_3 = (count_2 + count_3);
        else if (c < min_3)
            (min_3 = c), (count_3 = count_2);

        if (b == min_2)
            count_2 = (count_1 + count_2);
        else if (b < min_2)
            (min_2 = b), (count_2 = count_1);

        if (a == min_1)
            ++(count_1);
        else if (a < min_1)
            (min_1 = a), (count_1 = 1);
    }

    std::cout << count_3 << '\n';

    return 0;

}
