/*

 * Since the XOR operation is commutative & associative, and it is given that
   some value of x exists, therefore every element of the array is a possible
   answer.

   For eg., let the array be [4, 3, 2, 5].

   From the given example, we know that 3 is an answer, i.e. 4 XOR 2 XOR 5 = 3.

   We know that A XOR B = 0 if and only if A = B.

   Therefore, (4 XOR 2 XOR 5) XOR 3 = 0,
   i.e. 4 XOR 2 XOR 5 XOR 3 = 0,
   i.e. 4 XOR 2 XOR 3 XOR 5 = 0,
   i.e. (4 XOR 2 XOR 3) XOR 5 = 0,
   i.e. 4 XOR 2 XOR 3 = 5.

   Thus, 5 is also a possible answer, and a similar reasoning applies to every
   other element in the array.

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

        int a;
        while (n--)
            std::cin >> a;

        std::cout << a << '\n';
    }

    return 0;

}
