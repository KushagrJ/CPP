/*

 * // Assuming 1-based indexing.

   In order to reverse the segment of the string starting at index a and ending
   at index (|s| - a + 1), both inclusive, the following loop can be used -
   for (int i = a, j = (s.size() - a + 1); i < j; ++i, --j)
       std::swap(s[i], s[j]);

   Now, since for all possible i, s[i] can only be swapped with s[|s| - i + 1],
   therefore the order in which the segments are reversed is irrelevant.
   Also, swapping s[i] an odd number of times is the same as swapping s[i]
   once, and swapping s[i] an even number of times is the same as not swapping
   s[i] at all.

   Let swap_count[i] (for all i such that 1 <= i <= (|s| / 2)) be the
   number of times s[i] needs to be swapped.
   Then, swap_count[1] is equal to the number of times 1 occurs in the input,
   swap_count[2] is equal to the number of times 1 occurs in the input plus the
   number of times 2 occurs in the input, and so on, because getting i in the
   input increases each of swap_count[i], swap_count[i+1], swap_count[i+2], ...
   by 1.

   Now, instead of incrementing the values after every input, the following
   method can be used -

   while (m--)
   {
       int a;
       std::cin >> a;

       ++(swap_count[a]);
   }

   for (int i = 2; i <= (s.size() / 2); ++i)
       swap_count[i] += swap_count[i-1];

 */





#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


int main()
{

    // Since the string is stored using 0-based indexing, therefore 1 will have
    // to be subtracted when subscripting.
    std::string s;
    std::cin >> s;

    // The 0-th element of this vector is unused, making the indexing 1-based.
    std::vector<int> swap_count(((s.size() / 2) + 1), 0);

    int m;
    std::cin >> m;

    while (m--)
    {
        int a;
        std::cin >> a;

        ++(swap_count[a]);
    }

    for (int i = 2; i <= (s.size() / 2); ++i)
        swap_count[i] += swap_count[i-1];

    for (int i = 1, j = s.size(); i < j; ++i, --j)
        if (swap_count[i] & 1)
            std::swap(s[i-1], s[j-1]);

    std::cout << s << '\n';

    return 0;

}
